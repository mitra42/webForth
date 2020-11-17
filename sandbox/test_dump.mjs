import { Forth, ForthNodeExtensions} from '../index.js';

/*
 * This is a first cut at a dictionary dumper for Arduino
 * Not currently working
 * Its written in Javascript - it could be written in Forth, but there is some significant string handling going on.
 */

const CELLL = 2; // Must use 2 for Arduino
const MEM = 16; // Must use 16 for Arduino
const ROMSIZE = 0x2000; // TODO-ARDUINO will need to be actual size used, or change to use bottom up ram/rom like in Arduino
const extensions = ForthNodeExtensions;

class ForthDumper extends Forth {
  xcLine(s) { this.TXbangS(s); }
  xcNameEncode(s) { return escape(s) // C identifiers are alphanumeric and _
    .replace(/\*/g,'%2A')
    .replace(/\+/g, '%2B')
    .replace(/-/g,'%2D')
    .replace(/\./g, '%2E')
    .replace(/\//g,'%2F')
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
  xcNames() {
    this.xcLine('\n/* === Dumping Arduino source from names === */');
    // Traverse dictionary to report each name
    //TODO-XC handle multiple dictionaries TODO-VOCABULARY
    let p = this.currentFetch(); // vocabulary
    while (p = this.Mfetch(p)) {
      //TODO-XC make sure names valid as arduino defines
      const name = this.countedToJS(p);
      this.xcLine(`\n#define ${this.xcXTIdentifier(name)} 0x${this.na2xt(p).toString(16)} /* ${name.replace('*/','* /')}*/`);
      p -= this.CELLL; // point at link address and loop for next word
    }
  }
  xcTokens() {
    this.xcLine('/* === Function tokens === */\n')
    this.jsFunctions.forEach((func, token) => {
      if (!func) { return; } // 0
      this.xcLine(`#define ${this.xcFuncIdentifier(func, token)} ${token}\n`);
    });
  }
  xcCode() {
    const boundaries = {};
    const itemsPerLine = 16;
    let itemsAlreadyOnLine = 0;
    boundaries[0] = "USER VARIABLE SAVE AREA";
    boundaries[this.CODEE] = "CODE DICTIONARY";
    boundaries[this.cpFetch()] = "CURRENT TOP OF CODE DICTIONARY";
    boundaries[this.npFetch()] = "CURRENT BOTTOM OF NAME DICTIONARY";
    boundaries[this.NAMEE] = "TOP OF NAME DICTIONARY";
    let CP = 0; // Start at bottom of m
    const romTop = this.NAMEE;
    //const romTop = 100;
    let definitionXT = this.CODEE;
    let definitionName = '';
    let definitionNA = this.npFetch();
    const longestDef = 256; // Arbitrary guess at how long a definition might be for forward jumps
    while(CP < romTop ) { // Only need to go to NAMEE - above is in Ram TODO-XC
      //TODO-XC convert numbers
      const val = this.Mfetch(CP);
      const na = this.xt2na(val);
      const value = na
        ? this.xcXTIdentifier(this.countedToJS(na))
        : (definitionName && (definitionXT < val) && (val < (definitionXT + longestDef)))
          ? `${this.xcXTIdentifier(definitionName)} + 0x${(val-definitionXT).toString(16)}`
          : (val < 10)
          ? val.toString(10)
          : `0x${val.toString(16)}`;

      if (CP in boundaries) {
        this.xcLine(`\n/* ==== ${boundaries[CP]} ==== */`);
      }
      if (CP < this.CODEE) { // User save area
        //TODO-XC maybe reverse User offset into name and comment listings
        this.xcLine(`\n/* 0x${CP.toString(16)} */ ${value},`);
      // Code definitions area
      } else if (CP < this.cpFetch()) {
        const defNa = this.xt2na(CP);
        if (defNa) {
          definitionXT = CP;
          definitionName = this.countedToJS(defNa);
          this.xcLine(`\n/* 0x${CP.toString(16)}: ${definitionName.replace('*/','* /')} */ `);
          this.xcLine(`${this.xcFuncIdentifier(this.jsFunctions[val], val)}, `);
        } else {
          this.xcLine(`${value}, `);
        }
      // Space between Code and Names
      } else if (CP < this.npFetch()) {
        if (itemsAlreadyOnLine++ === 0) {
          this.xcLine(`\n/* 0x${CP.toString(16)}: */ `);
        }
        this.xcLine(`${value}, `);
        if (itemsAlreadyOnLine >= itemsPerLine) itemsAlreadyOnLine = 0;
      // Name area
      } else if (CP < this.NAMEE) {
        if (CP === definitionNA) {
          definitionNA = this.Mfetch(CP + this.CELLL) - 2 * this.CELLL;
          definitionName = this.countedToJS(CP + 2 * this.CELLL);
          this.xcLine(`\n/* 0x${CP.toString(16)} ${definitionName.replace('*/','* /')} */ ${value},`);
        } else {
          this.xcLine(` ${value},`);
        }
      }
      //TODO-XC other sections to go here - see issue #57
      CP += this.CELLL;
    }
  }
  xcDictionary() {
    this.xcLine('\n/* === Dumping Arduino source from dictionary === */');
    this.xcNames();
    this.xcTokens();
    this.xcCode();
    this.xcLine('\n// === End of Arduino source from dictionary === \n');
  }
}
const forth = new ForthDumper({CELLL, ROMSIZE, MEM, extensions});
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => forth.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => forth.interpret("WARM"));
  //.then(() => forth.console()) // Interactive console
  .then(() => forth.xcDictionary()) // Interactive console
  .then(() => console.log('\n// arduino dump complete'));
