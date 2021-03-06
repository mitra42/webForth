import { promises as fs, constants as fs_constants } from 'fs';

// eslint-disable-next-line import/extensions
import { Forth, ForthNodeExtensions, jsUsers, RP0offset, jsFunctionAttributes } from './index.js';

const extensions = ForthNodeExtensions;

/*
 * This is a first cut at a dictionary dumper aka cross-compiler for Arduino
 * Its written in Javascript - it could be written in Forth, but there is some significant string handling going on.
 *
 * To use this, see README.md and search for "Arduino support"
 */

const xcRevDefines = {}; // Extra defines to check for values in
const numTokens = 8; // Should match value of highest token - currently tokenValue

//TODO-DUMP should refuse to dump any code fields to non existent routines
// noinspection JSCheckFunctionSignatures,JSBitwiseOperatorUsage
class ForthXC extends Forth {
  xcLine(s, fd) { // asynchronous if passed fd
    if (fd) {
      return fd.write(s); // Current position, utf8, return a promise { bytesWritten, buffer }
    } else {
      // noinspection JSUnresolvedFunction
      this.TXstoreS(s);
    }
  }
  xcNameEncode(s) { return escape(s) // C identifiers are alphanumeric and _
    .replace(/\*/g, '%2A')
    .replace(/\+/g, '%2B')
    .replace(/-/g, '%2D')
    .replace(/\./g, '%2E')
    .replace(/\//g, '%2F')
    .replace(/@/g, '%40')
    .replace(/_/g, '%5F')
    .replace(/%/g, '_');
  }
  xcFuncIdentifier(func, unusedToken) {
    return `F_${this.xcNameEncode(func.name)}`;
  }
  xcXTIdentifier(name) {
    return `XT_${this.xcNameEncode(name)}`;
  }
  xcNum(v) {
    return v < 10 ? v.toString(10) : `0x${v.toString(16)}`;
  }
  async xcXTdef(name, xt, fd) {
    await this.xcLine(`\n#define ${this.xcXTIdentifier(name)} ${this.xcNum(xt)} /* ${name.replace('*/', '* /')}*/`, fd);
  }
  async xcConstants(fd = undefined) {
    console.assert(this.UZERO === this.ROM0, 'UZERO=ROM0 assumed by userAreaInit in .ino');

    const keys = ['RAM0', 'ROM0', 'CELLL', 'TIB0', 'UPP', 'UZERO'];
    for (let i = 0; i < keys.length; i++) {
      const k = keys[i];
      const val = this[k];
      xcRevDefines[val] = k;
      await this.xcLine(`\n#define ${k} ${this.xcNum(val)}`, fd);
    }
    await this.xcLine(`\n#define CELLTYPE ${this.CELLL === 2 ? 'uint16_t' : 'uint32_t'}`, fd);
    await this.xcLine(`\n#define SIGNEDCELLTYPE ${this.CELLL === 2 ? 'int16_t' : 'int32_t'}`, fd);
    await this.xcLine(`\n#define DOUBLECELLTYPE ${this.CELLL === 2 ? 'uint32_t' : 'uint64_t'}`, fd); // TODO-ARDUINO-32
    await this.xcLine(`\n#define CELLSHIFT ${this.CELLL === 2 ? 1 : 2}`, fd);
    await this.xcLine(`\n#define CELLOFFSETMASK ${this.CELLL === 2 ? 0x01 : 0x03}`, fd);
    await this.xcLine('\n#define LITTLEENDIAN true', fd);
    await this.xcLine(`\n#define ROMCELLS ${this.xcNum(this.ROMSIZE / this.CELLL)}`, fd);
    await this.xcLine(`\n#define RAMCELLS ${this.xcNum(this.RAMSIZE / this.CELLL)}`, fd);
    await this.xcLine(`\n#define SPP ${this.xcNum(this.SPP)}`, fd);
    await this.xcLine(`\n#define RP0 ${this.xcNum(this.Ufetch(RP0offset))}`, fd);
    await this.xcLine(`\n#define RAMNAMEE ${this.xcNum(this.RAMNAMEE)}`, fd);
    await this.xcLine(`\n#define RAMCODEE ${this.xcNum(this.RAMCODEE)}`, fd);
    await this.xcLine(`\n#define ROM(cellAddr) pgm_read_${this.CELLL === 4 ? 'dword' : 'word'}_near(&rom[cellAddr])`, fd);
    await this.xcLine(`\n#define FUNCTIONSLENGTH ${this.jsFunctions.length + 1}`, fd);
    await this.xcXTdef('COLD', this.JStoXT('COLD'), fd);
  }
  async xcNames(fd) {
    await this.xcLine('\n/* === Dumping Arduino source from names === */', fd);
    // Traverse dictionary to report each name
    //TODO-XC handle multiple dictionaries TODO-VOCABULARY
    let p = this.currentFetch(); // vocabulary
    while (p = this.Mfetch(p)) {
      const name = this.countedToJS(p);
      const xt = this.na2xt(p);
      const funcNumber = this.Mfetch(xt); // Typically 3 for colon words
      if (name && !jsFunctionAttributes[funcNumber].defer) { await this.xcXTdef(name, xt, fd); }
      p -= this.CELLL; // point at link address and loop for next word
    }
  }
  async xcTokens(top = this.jsFunctions.length, fd) {
    await this.xcLine('\n/* === Function tokens === */', fd);
    for (let token = 0; token < top; token++) {
      const func = this.jsFunctions[token];
      if (func) {
        await this.xcLine(`\n#define ${this.xcFuncIdentifier(func, token)} ${token}`, fd);
      }
    }
  }
  async xcFunctions({ processor }, fd) {
    await this.xcLine('\n/* === Function table - maps tokens to functions === */', fd);
    for (let token = 0; token < this.jsFunctions.length; token++) {
      const func = this.jsFunctions[token];
      if (func && !jsFunctionAttributes[token].defer) {
        const arduinoFuncName = this.xcNameEncode(func.name);
        await this.xcLine(`\nextern void ${arduinoFuncName}();`, fd);
      }
    }
    // This is the actual array of functions - will have 0 for deferred ones
    // On Arduino uno `const void (*f[62])() = {` worked, but ESP8266 required `void (* const f[])() PROGMEM = {`
    await this.xcLine(`\nvoid (* const f[FUNCTIONSLENGTH])()${processor === 'esp8266' ? ' PROGMEM' : ''} = {`, fd);
    const itemsPerLine = 4;
    let itemsToGoOnLine = 0;
    for (let token = 0; token < this.jsFunctions.length; token++) {
      const func = this.jsFunctions[token];
      if (!itemsToGoOnLine--) { itemsToGoOnLine = itemsPerLine - 1; await this.xcLine(`\n /* ${token} */`, fd); }
      if (!func || jsFunctionAttributes[token].defer) {
        await this.xcLine('0, ', fd);
      } else {
        const arduinoFuncName = this.xcNameEncode(func.name);
        const forthName = jsFunctionAttributes[token].n;
        if (forthName && (forthName !== arduinoFuncName)) {
          await this.xcLine(`/* ${forthName.replace('*/', '* /')} */ `, fd);
        }
        await this.xcLine(`${arduinoFuncName}, `, fd);
      }
    }
    await this.xcLine(' 0 };', fd);
  }
  async xcCode(fd) {
    await this.xcLine('\nconst CELLTYPE rom[ROMCELLS] PROGMEM = {', fd);
    const boundaries = {};
    const itemsPerLine = 16;
    let itemsAlreadyOnLine = 0;
    boundaries[this.UZERO] = 'USER VARIABLE SAVE AREA';
    boundaries[this.ROMCODEE] = 'CODE DICTIONARY';
    boundaries[this.romCodeTop] = 'CURRENT TOP OF CODE DICTIONARY';
    boundaries[this.romNameBottom] = 'CURRENT BOTTOM OF NAME DICTIONARY';
    boundaries[this.ROMNAMEE] = 'TOP OF NAME DICTIONARY';
    let CP = this.ROM0; // Start at bottom of m
    const romTop = this.ROMNAMEE;
    //const romTop = 100;
    let definitionXT = this.ROMCODEE;
    let definitionName = '';
    let definitionNA = this.romNameBottom;
    const longestDef = 256; // Arbitrary guess at how long a definition might be for forward jumps
    // Link from name directory into Rom dictionary

    while (CP < romTop) { // Only need to go to ROMNAMEE - above is in Ram
      const val = this.Mfetch(CP);
      const na = this._toName(val);
      const value = (na && (this.Mfetch8(na) & 31))
        ? this.xcXTIdentifier(this.countedToJS(na))
        : (definitionName && (definitionXT < val) && (val < (definitionXT + longestDef)))
          ? `${this.xcXTIdentifier(definitionName)} + ${this.xcNum(val - definitionXT)}`
          : (xcRevDefines[val] && (val > 0x10)) // Arbitrary distinction that small numbers probably coincidental
            ? xcRevDefines[val]
            : this.xcNum(val);

      if (CP in boundaries) {
        await this.xcLine(`\n/* ==== ${boundaries[CP]} ==== */`, fd);
      }
      if (CP < this.ROMCODEE) { // User save area
        //TODO-XC maybe reverse User offset into name and comment listings
        await this.xcLine(`\n/* ${this.xcNum(CP)} ${jsUsers[(CP - this.ROM0) / this.CELLL] ? jsUsers[(CP - this.ROM0) / this.CELLL][0] : 'unused'} */ ${value},`, fd);
      // Code definitions area
      } else if (CP < this.romCodeTop) {
        const defNa = this._toName(CP);
        if (defNa) {
          definitionXT = CP;
          definitionName = this.countedToJS(defNa);
          await this.xcLine(`\n/* ${this.xcNum(CP)}: ${definitionName.replace('*/', '* /')} */ `, fd);
          await this.xcLine(`${this.xcFuncIdentifier(this.jsFunctions[val], val)}, `, fd);
        } else {
          await this.xcLine(`${value}, `, fd);
        }
      // Space between Code and Names
      } else if (CP < this.romNameBottom) {
        if (itemsAlreadyOnLine++ === 0) {
          await this.xcLine(`\n/* ${this.xcNum(CP)}: */ `, fd);
        }
        await this.xcLine(`${value}, `, fd);
        if (itemsAlreadyOnLine >= itemsPerLine) itemsAlreadyOnLine = 0;
      // Name area
      } else if (CP < this.ROMNAMEE) {
        if (CP === definitionNA) {
          definitionNA = this.Mfetch(CP + this.CELLL) - 2 * this.CELLL;
          definitionName = this.countedToJS(CP + 2 * this.CELLL);
          await this.xcLine(`\n/* ${this.xcNum(CP)} ${definitionName.replace('*/', '* /')} */ ${value},`, fd);
        } else {
          await this.xcLine(` ${value},`, fd);
        }
      }
      CP += this.CELLL;
    }
    await this.xcLine('\n};', fd);
  }
  async xcDictionary({ processor, folder }) {
    await this.xcHeaderFile({ processor, folder });
    await this.xcDictionaryFile({ processor, folder });
  }
  async xcDictionaryFile({ processor, folder }) {
    const fd = await fs.open(`${folder}/webforth_dictionary.cpp`, fs_constants.O_WRONLY | fs_constants.O_CREAT | fs_constants.O_TRUNC);
    await this.xcLine('#include "webforth_functions.h"', fd);
    await this.xcLine('\n// === Arduino source built directly from dictionary - edit at your own risk ! === ', fd);
    await this.xcNames(fd);
    await this.xcTokens(undefined, fd);
    await this.xcFunctions({ processor }, fd);
    await this.xcCode(fd);
    await this.xcLine('\n// === End of Arduino source from dictionary === \n', fd);
    await fd.close();
  }
  async xcHeaderFile({ processor, folder }) {
    const fd = await fs.open(`${folder}/webforth_functions.h`, fs_constants.O_WRONLY | fs_constants.O_CREAT | fs_constants.O_TRUNC);
    await this.xcLine('#ifndef ARDUINO_WEBFORTH_H_\n#define ARDUINO_WEBFORTH_H_\n#include <Arduino.h>', fd);
    await this.xcConstants(fd);
    await this.xcLine(`
// Data defined currently in arduino_webforth.ino but used in webforth_functions.cpp
extern const CELLTYPE rom[ROMCELLS] PROGMEM;
extern void (* const f[FUNCTIONSLENGTH])()${processor === 'esp8266' ? ' PROGMEM' : ''};
// Needed by setup or loop defined in webforth_functions.cpp
extern CELLTYPE IP;
extern CELLTYPE IPnext();
extern void threadtoken(const CELLTYPE xt);
`, fd);
    await this.xcLine('\n// Tokens are needed by webforth_functions.cpp which does not include webforth_dictionary.cpp', fd);
    await this.xcTokens(numTokens + 1, fd);
    await this.xcLine('\n#endif', fd);
    await fd.close();
  }
}
export { ForthXC, extensions };
