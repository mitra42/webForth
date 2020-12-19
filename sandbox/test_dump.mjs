import { Forth, ForthNodeExtensions, jsUsers, RP0offset, jsFunctionAttributes } from '../index.js';

/*
 * This is a first cut at a dictionary dumper aka cross-compiler for Arduino
 * Its written in Javascript - it could be written in Forth, but there is some significant string handling going on.
 *
 * To use this, see README.md and search for "Arduino support"
 */

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32 - Arduino is 2:16 and memClass = ROmable16_16
const CELLL = 4; // Must use 2 for Arduino On ESP8266 better to use 4
const MEM = 32; // Must use 16 for Arduino On ESP8266 better to use 4
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x1000 * CELLL; // Set to 0x2000 should cover the standard dict plus a few extensions.
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x2800 * CELLL; // 200x2 is about the maximum Ram you can use currently on e.g. an Arduino Uno; ESP8266 seems to be ok (untested) at 0x2800 x 4
const extensions = ForthNodeExtensions;
const memClass = undefined; // Flash16_16; // Can override default memory class for esoteric or experimental requirements
const xcRevDefines = {}; // Extra defines to check for values in
//TODO-DUMP should refuse to dump any code fields to non existent routines
class ForthDumper extends Forth {
  xcLine(s) { this.TXbangS(s); }
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
  xcFuncIdentifier(func, token) {
    return `F_${this.xcNameEncode(func.name)}`;
  }
  xcXTIdentifier(name) {
    return `XT_${this.xcNameEncode(name)}`;
  }
  xcNum(v) {
    return v < 10 ? v.toString(10) : `0x${v.toString(16)}`;
  }
  xcConstants() {
    console.assert(this.UZERO === this.ROM0, "UZERO=ROM0 assumed by userAreaInit in .ino");
    ['RAM0', 'ROM0', 'CELLL', 'TIB0', 'UPP', 'UZERO'].forEach((k) => {
      const val = this[k];
      xcRevDefines[val] = k;
      this.xcLine(`\n#define ${k} ${this.xcNum(val)}`);
    });
    this.xcLine(`\n#define CELLTYPE ${this.CELLL === 2 ? 'uint16_t' : 'uint32_t'}`);
    this.xcLine(`\n#define SIGNEDCELLTYPE ${this.CELLL === 2 ? 'int16_t' : 'int32_t'}`);
    this.xcLine(`\n#define DOUBLECELLTYPE ${this.CELLL === 2 ? 'uint32_t' : 'uint64_t'}`); // TODO-ARDUINO-32
    this.xcLine(`\n#define CELLSHIFT ${this.CELLL === 2 ? 1 : 2}`);
    this.xcLine(`\n#define CELLOFFSETMASK ${this.CELLL === 2 ? 0x01 : 0x03}`);
    this.xcLine('\n#define LITTLEENDIAN true');
    this.xcLine(`\n#define ROMCELLS ${this.xcNum(ROMSIZE / this.CELLL)}`);
    this.xcLine(`\n#define RAMCELLS ${this.xcNum(RAMSIZE / this.CELLL)}`);
    this.xcLine(`\n#define SPP ${this.xcNum(this.SPP)}`);
    this.xcLine(`\n#define RP0 ${this.xcNum(this.Ufetch(RP0offset))}`);
    this.xcLine(`\n#define RAMNAMEE ${this.xcNum(this.RAMNAMEE)}`);
    this.xcLine(`\n#define RAMCODEE ${this.xcNum(this.RAMCODEE)}`);
    // #if CELLL == 4
    this.xcLine(`\n#define ROM(cellAddr) pgm_read_${CELLL === 2 ? 'word' : 'dword'}_near(&rom[cellAddr])`);
  }
  xcNames() {
    this.xcLine('\n/* === Dumping Arduino source from names === */');
    // Traverse dictionary to report each name
    //TODO-XC handle multiple dictionaries TODO-VOCABULARY
    let p = this.currentFetch(); // vocabulary
    while (p = this.Mfetch(p)) {
      const name = this.countedToJS(p);
      const xt = this.na2xt(p);
      const funcNumber = this.Mfetch(xt); // Typically 3 for colon words
      if (!jsFunctionAttributes[funcNumber].replaced) {
        this.xcLine(`\n#define ${this.xcXTIdentifier(name)} ${this.xcNum(xt)} /* ${name.replace('*/', '* /')}*/`);
      }
      p -= this.CELLL; // point at link address and loop for next word
    }
  }
  xcTokens() {
    this.xcLine('\n/* === Function tokens === */');
    this.jsFunctions.forEach((func, token) => {
      if (func)
      //if (func && !jsFunctionAttributes[token].replaced) // TODO only output non-replaced tokens, but then have to catch in CODE DICT and callers of those
        this.xcLine(`\n#define ${this.xcFuncIdentifier(func, token)} ${token}`);
    });
  }
  xcFunctions() {
    this.xcLine('\n/* === Function table - maps tokens to functions === */');
    this.jsFunctions.forEach((func, token) => {
      if (func && !jsFunctionAttributes[token].replaced) {
        const arduinoFuncName = this.xcNameEncode(func.name);
        this.xcLine(`\nextern void ${arduinoFuncName}();`);
      }
    });
    // This is the actual array of functions - will have 0 for replaced ones
    // On Arduino uno `const void (*f[62])() = {` worked, but ESP8266 rquired `void (* const f[])() PROGMEM = {`
    this.xcLine(`\n#define FUNCTIONSLENGTH ${this.jsFunctions.length + 1}`);
    this.xcLine(`\nvoid (* const f[FUNCTIONSLENGTH])() PROGMEM = {`);
    const itemsPerLine = 4;
    let itemsToGoOnLine = 0;
    this.jsFunctions.forEach((func, token) => {
      if (!itemsToGoOnLine--) { itemsToGoOnLine = itemsPerLine-1; this.xcLine('\n'); }
      if (!func || jsFunctionAttributes[token].replaced) {
        this.xcLine('0, ');
      } else {
        const arduinoFuncName = this.xcNameEncode(func.name);
        const forthName = jsFunctionAttributes[token].n;
        if (forthName && (forthName !== arduinoFuncName)) {
          this.xcLine(`/* ${forthName.replace('*/','* /')} */ `);
        }
        this.xcLine(`${arduinoFuncName}, `);
      }
    });
    this.xcLine(' 0 };');
  }
  xcCode() {
    this.xcLine('\nconst CELLTYPE rom[ROMCELLS] PROGMEM = {');
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

    while(CP < romTop ) { // Only need to go to ROMNAMEE - above is in Ram
      const val = this.Mfetch(CP);
      const na = this.xt2na(val);
      const value = na
        ? this.xcXTIdentifier(this.countedToJS(na))
        : (definitionName && (definitionXT < val) && (val < (definitionXT + longestDef)))
          ? `${this.xcXTIdentifier(definitionName)} + ${this.xcNum(val-definitionXT)}`
          : (xcRevDefines[val] && (val > 0x10)) // Arbitrary distinction that small numbers probably coincidental
            ? xcRevDefines[val]
            : this.xcNum(val);

      if (CP in boundaries) {
        this.xcLine(`\n/* ==== ${boundaries[CP]} ==== */`);
      }
      if (CP < this.ROMCODEE) { // User save area
        //TODO-XC maybe reverse User offset into name and comment listings
        this.xcLine(`\n/* ${this.xcNum(CP)} ${jsUsers[(CP-this.ROM0)/this.CELLL] ? jsUsers[(CP-this.ROM0)/this.CELLL][0] : "unused"} */ ${value},`);
      // Code definitions area
      } else if (CP < this.romCodeTop) {
        const defNa = this.xt2na(CP);
        if (defNa) {
          definitionXT = CP;
          definitionName = this.countedToJS(defNa);
          this.xcLine(`\n/* ${this.xcNum(CP)}: ${definitionName.replace('*/','* /')} */ `);
          this.xcLine(`${this.xcFuncIdentifier(this.jsFunctions[val], val)}, `);
        } else {
          this.xcLine(`${value}, `);
        }
      // Space between Code and Names
      } else if (CP < this.romNameBottom) {
        if (itemsAlreadyOnLine++ === 0) {
          this.xcLine(`\n/* ${this.xcNum(CP)}: */ `);
        }
        this.xcLine(`${value}, `);
        if (itemsAlreadyOnLine >= itemsPerLine) itemsAlreadyOnLine = 0;
      // Name area
      } else if (CP < this.ROMNAMEE) {
        if (CP === definitionNA) {
          definitionNA = this.Mfetch(CP + this.CELLL) - 2 * this.CELLL;
          definitionName = this.countedToJS(CP + 2 * this.CELLL);
          this.xcLine(`\n/* ${this.xcNum(CP)} ${definitionName.replace('*/','* /')} */ ${value},`);
        } else {
          this.xcLine(` ${value},`);
        }
      }
      CP += this.CELLL;
    }
    this.xcLine(`\n};`);
  }
  xcDictionary() {
    this.xcLine('\n// === Dumping Arduino source from dictionary === ');
    this.xcConstants();
    this.xcNames();
    this.xcTokens();
    this.xcFunctions();
    this.xcCode();
    this.xcLine('\n// === End of Arduino source from dictionary === \n');
  }
}
const forth = new ForthDumper({CELLL, ROMSIZE, RAMSIZE, MEM, memClass, extensions});
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => forth.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => forth.interpret("COLD"))
  //.then(() => forth.console()) // Interactive console
  .then(() => forth.xcDictionary()) // Interactive console
  .then(() => console.log('\n// arduino dump complete'));
