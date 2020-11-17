/*
 * NOTES
 * See https://www.arduino.cc/reference/en/language/variables/utilities/progmem/ for reading program memory (where dictionary will be)
 */



//TODO-ARDUINO OPTIMIZATION - check for constant parameters to functions nad mark constant in definition

//TODO-ARDUINO - can only define remainder below when know how dictionary is buid as its the XT 
#define js2xtdCOMPILE -1 // used directly in C function
#define js2xtdINTERPRET -1 // used directly in C function
#define js2xtdoLIT -1 // used directly in C function
#define js2xtEXIT -1 // used directly in C function
#define js2xtWARM -1 // called via a lookup
#define js2xtquit1 -1 // called via a lookup
#define js2xtQRX -1 // used to initialize a user variable
#define js2xtTXbang -1 // used to initialize a user variable
#define js2xtNUMBERQ -1 // used to initialize a user variable

//L.1777
#define CELLL 2  // 2 or 4. Needs to be big enough for an address
#if CELLL == 2
#define CELLTYPE int
#define CELLSHIFT 1
#endif
#if CELLL == 4
#define CELLTYPE long
#define CELLSHIFT 2
#endif
//#define WRITEROM 1 // Define if want to write to "rom" area

//L.1794
//#define EM 0x2000 * CELLL
#define ROMSIZE 0x2000
// RAMSIZE is defined by the size of the parts that go there

#define LITTLEENDIAN true // Arduino is little endian


// ==== In order, there is a gap (mLissing code) before each Line marker ==== 
//L.113-
#define COMP 0x40 // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
#define IMED 0x80 // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
#define bitsSPARE 0x20 // Unused spare bit in names
#define BYTEMASK 0xFF - COMP - IMED - bitsSPARE // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
// Using const for forthtrue as we care about its size
const CELLTYPE forthTrue = -1; // Not quite correct, should be masked BUT when pushed that it is done underneath
#define nameMaxLength 31
#define BL 32

// User offsets - TODO should be defined by dictionary creation - note these are in CELLS not in Bytes as in webForth
#define SP0offset 4
#define RP0offset 5
#define PROMPToffset 11
#define BASEoffset 12
#define INoffset 15
#define nTIBoffset 16
#define TIBoffset 17
#define EVALoffset 19
#define NUMBERoffset 20
#define CONTEXToffset 23
#define CURRENToffset 32 
#define CPoffset 34
#define NPoffset 35
#define LASToffset 36
#define VPoffset 37
#define _USER 38

//L.1823
#define CELLbits CELLL * 8 // Number of bits in a cell - used for loops and shifts
// mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
// TODO-CELLL assumes CELLL = 2
const CELLTYPE CELLMASK = forthTrue ^ ((0xFF ^ BYTEMASK) << (CELLbits - 8)); // TODO-11-CELLL will be endian dependent

//L.1831
static byte testing = 0;

//L.1840
#define RAM0 0x8000 // Arbitrary address to use for RAM
#define SPS (0x40 << CELLSHIFT) // Size of data stack 64 Cells (128 bytes) for now
#define SPP (RAM0 + SPS) // Top of stack
// 8 cell buffer between Stack and TIB
#define TIB0 (SPP + (8 << CELLSHIFT)) // Terminal input buffer - shares space with Return stack //TODO-28-MULTITASK will move
#define RTS (0x40 << CELLSHIFT) // return stack/TIB size // eFORTH-DIFF was 64 which is tiny for any kind of string handling
#define RP0 (TIB0 + RTS)  // top of return stack RP0 - there is an 8 cell buffer which is probably just for safety.
// 8 cell buffer between RP0 and UPP 
#define UPP (RP0 + (8 << CELLSHIFT)) // start of user area // TODO-28-MULTI UP should be a variable, and used in most places UPP is
#define US (40 << CELLSHIFT)  // user area size in cells i.e. 64 variables - standard usage below is using about 37
#define EM (UPP + US)
#define RAMSIZE (EM - RAM0) // Size of RAM used 


#define RAMADDR(x) ((x - RAM0) >> CELLSHIFT)
#define ROMADDR(x) (x >> CELLSHIFT)
#define FROMRAMADDR(x) ((x << CELLSHIFT) + RAM0)
#define FROMROMADDR(x) (x << CELLSHIFT)

// Now some cell based pointers into RAM
#define ramSPP RAMADDR(SPP) // start of data stack - grows down, points at top of stack - 8 word buffer for safety
#define RAMCELLS (RAMSIZE >> CELLSHIFT) // Approx 624 bytes  TODO-RAM
#define ROMCELLS (ROMSIZE >> CELLSHIFT)
#define ramRP0 RAMADDR(RP0)
#define ramUP0 RAMADDR(UPP)


// Define the Rom area we will build the dictionary in
#ifdef WRITEROM
extern CELLTYPE rom[ROMCELLS]; // Forward reference
#else
extern const CELLTYPE rom[ROMCELLS]; // Forward reference
#endif
extern const void (*f[60])(CELLTYPE); // Forward reference 

// And then building from the bottom up. The gap in middle is code directory
// cold start vector - its unclear if these bottom 0x100 are useful outside of the DOS context and for DOS it would need code at this address I think?
// const COLDD = 0x100;
#define UZERO 0
// Above UZERO is a store of initial values for User variables
#define CODEE (UZERO + US) // code dictionary grows up from here towards NAME dictionary.
// PAD is 80 bytes above the current top of the Code directory, and HLD (where numbers are build for output) is a few bytes growing down from PAD.
#define NAMEE ROMSIZE

//L.1852
static CELLTYPE ram[RAMCELLS]; // Equivalent of Mem16_16 in webForth
//L.1853 - jsFunctions[] is now fp[] and has to be after definition of functions in it. 

// Key pointers used - would ideally be registers in a register based system
static CELLTYPE romIP = 0;    // Interpreter Pointer (this is a cell pointer into ram i.e. IP >> CELLSHIFT
static CELLTYPE ramSP = ramSPP;  // Data Stack Pointer (cant call SP as that is reserved) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramRP = ramRP0;  // Return Stack Pointer (aka BP in 8086) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramUP = ramUP0;  // User Area Pointer // TODO-28-MULTI will move this around

//L.2023
void debugNA() { Serial.print(F("NAME=")); printCounted(SPfetch()); } // Print the NA on console
// Put testing3 in a definition to start outputing stack trace on console.
void testing3() { testing |= 3; };

// Put break in a definition.
void Fbreak() {
  Serial.println(F("\nbreak in a FORTH word")); 
} // Put a breakpoint in your IDE at this line

// debugPrintTIB will print the current TIB.
void debugPrintTIB() {
  Serial.print(F("TIB: ")); TXbangS(Ufetch(TIBoffset) + Ufetch(INoffset), Ufetch(nTIBoffset) - Ufetch(INoffset));
}

// TEST will (destructively) check the stack matches expected result, used for testing the compiler.
// e.g. this.interpret(`10 DUP 10 10 2 TEST`); // Confirm stack finishes with 2 items (10 10)
void TEST() { //  a1 a2 a3 b1 b2 b3 n -- ; Check n parameters on stack
  const byte stackDepth = SPpop();
  if ((ramSPP - ramSP) != (stackDepth << 1)) {
    Serial.println(F("Stack depth wrong"));
  } else {
    for (byte i = 0; i < stackDepth; i++) {
      const CELLTYPE onStack = cellRamFetch(ramSP + i);
      const CELLTYPE expected = SPpop(); // What we expect to see 
      if (onStack != expected) { 
        Serial.print(F("Expected")); 
        Serial.print(expected); 
        Serial.print(F("got")); 
        Serial.println(onStack); 
      }
    }
    ramSP = ramSPP; // Clear stack
  }
  //this.debugClear(); // Reset Debug Stack as can be mucked up by THROW and CATCH
}

// TODO if only used here then might merge into Mfetch and Mstore
#ifdef WRITEROM
#define ROM(cellAddr) rom[cellAddr]
#else
#define ROM(cellAddr) pgm_read_word_near(rom + cellAddr)
#endif 
CELLTYPE cellRomFetch(CELLTYPE cellAddr) { return ROM(cellAddr); }; 
CELLTYPE cellRamFetch(CELLTYPE cellAddr) { return ram[cellAddr]; };
CELLTYPE cellRamStore(CELLTYPE cellAddr, CELLTYPE v) { ram[cellAddr] = v; };
#ifdef WRITEROM
CELLTYPE cellRomStore(CELLTYPE cellAddr, CELLTYPE v) { rom[cellAddr] = v; };
#endif
CELLTYPE Mfetch(CELLTYPE byteAddr) { return (byteAddr > RAM0) ? cellRamFetch(RAMADDR(byteAddr)) : cellRomFetch(ROMADDR(byteAddr)) ; }
#ifdef WRITEROM
CELLTYPE Mstore(CELLTYPE byteAddr, CELLTYPE v) { return (byteAddr > RAM0) ? cellRamStore(RAMADDR(byteAddr), v) : cellRomStore(ROMADDR(byteAddr), v) ; }
#else
CELLTYPE Mstore(CELLTYPE byteAddr, CELLTYPE v) { cellRamStore(RAMADDR(byteAddr), v); }
#endif
// 8 bit equivalents
byte Mfetch8(CELLTYPE byteAddr) { 
  const bool offset = byteAddr & 0x01;
  const CELLTYPE cell = Mfetch(byteAddr); // Does not have to be aligned
#ifdef LITTLEENDIAN
  return offset ? (cell >> 8) : (cell & 0xFF) ;
#else
  return offset ? (cell & 0xFF) : (cell >> 8);
#endif
}; // Returns byte at a 

void Mstore8(CELLTYPE byteAddr, byte v) { 
  const bool offset = byteAddr & 0x01;
  const CELLTYPE cell = Mfetch(byteAddr);
#ifdef LITTLEENDIAN
    if (offset) {
      Mstore(byteAddr, (cell & 0x00FF) | (v << 8));
    } else {
      Mstore(byteAddr, (cell & 0xFF00) | v);
    }  
#else
    if (offset) {
      Mstore(cellAddr, (cell & 0xFF00) | v);
    } else {
      Mstore(cellAddr, (cell & 0x00FF) | (v << 8));
    }  
#endif
}

// TODO-MEM this is really dependent on MEM not CELLL 
CELLTYPE align(CELLTYPE byteAddr) { return (((byteAddr - 1) >> CELLSHIFT) + 1) << CELLSHIFT; }
// Only used in token - which is bytes and never aligned
void copyWithin(CELLTYPE byteDestn, CELLTYPE byteSource, CELLTYPE byteEnd) {
  while(byteSource < byteEnd) {
    Mstore8(byteDestn++, Mfetch8(byteSource++));
  }
}

void ALIGNED(CELLTYPE unused) { SPpush(align(SPpop())); }
CELLTYPE SPfetch() { return ram[ramSP]; }
CELLTYPE SPpop() { return ram[ramSP++]; }
void SPpush(CELLTYPE v) { ram[--ramSP] = v; }
CELLTYPE RPfetch() { return ram[ramRP]; }
CELLTYPE RPpop() { return ram[ramRP++]; }
void RPpush(CELLTYPE v) { ram[--ramRP] = v; }
CELLTYPE IPnext() { return ROM(romIP++); }
CELLTYPE Ufetch(byte userindex) { return ram[ramUP + userindex]; } // userindex is a cell index, not a byte index
void Ustore(byte userindex, CELLTYPE w) { ram[ramUP + userindex] = w; } // userindex is a cell index not a byte index
// === Access to the USER variables before they are defined
CELLTYPE currentFetch() { return Ufetch(CURRENToffset); }
CELLTYPE cpFetch() { return Ufetch(CPoffset); }
CELLTYPE vpFetch() { return Ufetch(VPoffset) || Ufetch(CPoffset); }
CELLTYPE cpAlign() { Ustore(CPoffset, align(cpFetch())); }
CELLTYPE vpAlign() { Ustore(VPoffset, align(vpFetch())); }
CELLTYPE npFetch() { return Ufetch(NPoffset); }
CELLTYPE lastFetch() { return Ufetch(LASToffset); }
CELLTYPE padPtr() { return vpFetch() + 80; } // Sometimes JS needs the pad pointer

// === Functions related to building 'find'  and its wrappers ====

// Convert a string made up of a count and that many bytes to a Javascript string.
// it assumes a maximum of nameMaxLength (31) characters.
// Mostly used for debugging but also in number conversion.
// TODO-ARDUINO use TXbangS(b, u) or printCounted instead
void printCounted(CELLTYPE a) { const byte c = Mfetch8(a++); TXbangS(a, c); }  // TODO-backport maybe use this in TYPE
//countedToJS(a) {
//  return this.m.decodeString(a + 1, a + (this.Mfetch8(a) & l['=BYTEMASK']) + 1);
//}

//L.2096-
// Convert a name address to the code dictionary definition.
CELLTYPE na2xt(CELLTYPE na) {
    return Mfetch(na - (2 << CELLSHIFT));
}

// Inner function of find, traverses a linked list Name dictionary.
// name   javascript string looking for
// va     pointer holding address of first element in the list.
// cell1  if present, gives it a quick first-cell test to apply.
// xt     if present we are looking for name pointing at this executable (for decompiler)
// returns 0 or na
// TODO-11-CELLL optimize to cells
bool _sameq(CELLTYPE na1, CELLTYPE na2, byte cells) {
  // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
  // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
  for (byte i = 0; i < cells; i++) {
      if ( Mfetch(na1 + (i<<CELLSHIFT)) != Mfetch(na2 + (i<<CELLSHIFT))) {
        return false;
      }
    }
    return true;
}
CELLTYPE _find(CELLTYPE va, CELLTYPE na) { // return na that matches or 0
  const byte cellCount = (Mfetch8(na) & BYTEMASK)  >> CELLSHIFT; // Count of cells after first one (formula is not as obvious as you think)
  const CELLTYPE cell1 = Mfetch(na);  // Could be little or big-endian
  CELLTYPE p = va;
  while (p = Mfetch(p)) {
    const CELLTYPE c1 = Mfetch(p) & CELLMASK; // count
    if (cell1 == c1) { // first cell matches (if cell1 not passed then does slow compare
      if (_sameq(p + CELLL, na + CELLL, cellCount)) {
        return p;
      }
    }
    p -= CELLL; // point at link address and loop for next word
  }
  // Drop through not found
  return 0;
}

// Search a single vocabulary for a string
// This has same footprint as eForth's 'find' but we do not replace it since this is approx 8x faster
void find() { // a va -- ca na | a 0
  const CELLTYPE va = SPpop();
  const CELLTYPE a = SPpop();
  const CELLTYPE na = _find(va, a);  // return matching na or 0
  if (na) {
    SPpush(na2xt(na));
    SPpush(na);
  } else {
    SPpush(a);
    SPpush(0);
  }
}
// Traverse dictionary to convert xt back to a na (for decompiler or debugging)
CELLTYPE xt2na(CELLTYPE xt) {
  CELLTYPE p = currentFetch(); // vocabulary
  while (p = Mfetch(p)) {
    //console.log('_find: comparing:', countedToJS(p)) // comment out except when debugging find
    if (na2xt(p) == xt) {
      return p;
    }
    p -= CELLL; // point at link address and loop for next word
  }
  // Drop through not found
  return 0;
}

//L.2180-
void ToNAME() { SPpush(xt2na(SPpop())); }  // Fast version of >NAME see Forth definition below

// TODO-29-VOCABULARY This just looks up a in the Context vocabulary, it makes no attempt to use multiple vocabularies
// If required then fixing this to iterate over the context array should not break anything (this is what NAME? does)
void findName() { // a -- xt na | a F
  SPpush(Ufetch(CONTEXToffset));  // a va
  find();                           // xt na | a F
}

//L.2214-
// === JS Functions to be able to define words ==== in Zen pg30 these are Macros.

// Compile one or more words into the next consecutive code cells.
void DW(CELLTYPE word) {
  CELLTYPE cp = cpFetch();
  Mstore(cp, word);
  cp += CELLL;
  Ustore(CPoffset, cp);
}

// a -- a; Check if a definition of the word at 'a' would be unique and display warning (but continue) if it would not be.
// Same profile as ?UNIQUE but not turned into a code word as not used prior to
void qUnique() {
  SPpush(SPfetch());      // DUP
  SPpush(currentFetch()); // a a va; dictionary to search
  find();                 // a xt na | a a F
  if (SPpop()) {
    const CELLTYPE xt = SPpop();              // Discard xt
    Serial.println(F("Duplicate definition of")); // Catch duplicates - report, but allow
    /*TODO-ARDUINO
      const char* name = countedToJS(SPfetch());
      if (!['foo', 'bar'].includes(name)) {
        Serial.println(F("Duplicate definition of"), name); // Catch duplicates - report, but allow
        //Serial.println(jsFunctionAttributes[Mfetch(xt)].replaced ? 'Expected' : '', 'Duplicate definition of', countedToJS(SPfetch())); // Catch duplicates - report, but allow
      }
    */
  } else {
    SPpop(); // DROP a
  }
}


// na -- ; Builds bytes around a newly entered name. Same function as $,n on Zen pg94 used by all defining words (CODE ':')
// expects in Name dictionary: <count><string><opt padding>
// prepends:   <aligned address of next cell of code><address of na of last definition in vocabulary>...
// Side effects are important: specifically.
// LAST <= na
void dollarCommaN() {
  if (Mfetch8(SPfetch())) {         // DUP C@ IF  ; test for no word
    qUnique();
    CELLTYPE a = SPpop();
    Ustore(LASToffset, a);    // DUP LAST ! ; a=na  ; LAST=na
    // Link address points to previous NA (prev value of LAST)
    // Note that first time this is run, it gets a 0 (CURRENT is 0, @0 is 0) if that changes will need to test Current here.
    a -= CELLL; // CURRENT @ @ OVER ! ; a = la = top of current dic
    Mstore(a, Mfetch(currentFetch())); // CURRENT @ @ OVER ! ; a = la = top of current dic
    // Push CP (code field to where will build in dictionary) into ca, below a and store that ca into NP
    a -= CELLL;
    Mstore(a, cpFetch()); // ca=CP ;
    Ustore(NPoffset, a); // ca=CP ;
  } else {                    // THEN $" name" THROW ;
    Serial.println(F("name error")); // This is an error - in FORTH equivalent its a THROW
  }
}


// Make the most recent definition available in the directory. This is part of closing every 'defining word'
// See also forth version
void OVERT() {
  Mstore(currentFetch(), lastFetch()); // LAST @ CURRENT @ !
}

//L.2278-
void tokenVocabulary(CELLTYPE romAddr) {
  Ustore(CONTEXToffset, FROMROMADDR(romAddr));
};
// Put the contents of the payload (1 word) onto Stack, used for CONSTANT
void tokenNextVal(CELLTYPE romAddr) {  // TODO check if could pass romAddr instead of byteAddr
  SPpush(cellRomFetch(romAddr));

};

// This is the most important token function - used for a Colon word to iterate over the list.
void tokenDoList(CELLTYPE romAddr) {
  RPpush(romIP);
  romIP = romAddr; // Point at first word in the definition
}
// Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
void tokenUser(CELLTYPE romAddr) { SPpush(FROMRAMADDR(rom[romAddr] + ramUP)); }

// Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
//TODO-15-EPROM should allocate in a space that might be elsewhere.
void _tokenDoes(CELLTYPE romAddr) {
  const CELLTYPE does = cellRomFetch(romAddr);
  if (does) {
    //debugPush();
    RPpush(romIP);
    romIP = does;
  }
}

// Put next address on the stack  -- byteAddr
void tokenCreate(CELLTYPE romAddr) {
  SPpush(FROMROMADDR(romAddr+1));
  _tokenDoes(romAddr);
}

void tokenVar(CELLTYPE romAddr) {
  SPpush(cellRomFetch(romAddr+1));
  _tokenDoes(romAddr);
}

// === INNER INTERPRETER YES THIS IS IT ! ==================== eForthAndZen#36
// This is quite different from eForth as its token-threaded rather than direct threaded

void threadtoken(CELLTYPE xt) {
  // console.assert(xt >= CODEE && xt < NAMEE); // Uncomment to catch bizarre xt values earlier
  // This next section is only done while testing, and outputs a trace, so set it on (with testing3) immediately before a likely error.
  //debugThread(xt);
  const CELLTYPE tok = Mfetch(xt);
  xt += CELLL;
  // console.assert(tok < jsFunctions.length); // commented out for efficiency, a fail will just break in the next line anyway.
  f[tok](xt); // Run the token function - like tokenDoList or tokenVar - doesnt return - (JS returns null or a Promise)
}

// This is not re-entrant, normally its threadtoken you want ....
// In particular you cannot use this to nest forth in code in forth
// If that becomes necessary, it MIGHT work to save IP (where?) and restore after while loop
// Cant use R or S for it as words use that across calls to the 'EVAL
void runXT(CELLTYPE xt) {
  //let waitFrequency = 0;
  //console.assert(this.IP === 0); // Cant nest run()
  threadtoken(xt);
  // If this returns without changing program Counter, it will exit
  while (romIP) {
    // console.assert(this.IP >= CODEE && this.IP <= NAMEE); // uncomment if tracking down jumping into odd places
    xt = IPnext();
    // Comment this out except when needed for debugging, they are slow
    // debugTIB =  this.m.decodeString(this.Ufetch(TIBoffset) + this.Ufetch(INoffset), this.Ufetch(TIBoffset) + this.Ufetch(nTIBoffset));
    // 'await this.threadtoken(xt)' would be legit, but creates a stack frame in critical inner loop, when usually not reqd.
    threadtoken(xt);
  }
}


void MS() { delay(SPpop()); } // ms --; delay for a period of time.
void BYE() {  romIP = 0; } // Should exit all the way out

// Unwind the effect of tokenDoList restoring IP to the next definition out.
// TODO-ARDUINO The XT of this is stored in js2xtEXIT
void EXIT() { romIP = RPpop(); }

// EXECUTE runs the word on the stack,
// and because there is nothing after the return from threadtoken which would get executed out of order
// Note that it has a return which could be a promise, which the 'run' will await on.
// This pattern may or may not work in other situations.
void EXECUTE() { threadtoken(SPpop()); }

// === Basic low level key I/O and links to OS - Zen pg 35
// This section will need editing for other systems.
/*
 * Input call chain is
 * ?RX  read one char if present
 * ?KEY via '?KEY to ?RX
 * KEY loop till ?KEY
 * accept read a line via KEY, processing control chars via 'TAP  to kTAP
 * QUERY read a line via 'EXPECT to accept into TIB and reset >IN
 * que read an evaluate a line
 * QUIT loop over que, handling errors
 *
 * See https://github.com/mitra42/webForth/issues/17 for strategy for async version
 */

// Call chain is ?RX < '?KEY  < ?KEY < KEY < accept < 'EXPECT < QUERY < que < QUIT
// -- char T | F
void QRX() { // ?RX
  if (Serial.available() > 0) {
    SPpush(Serial.read());
    SPpush(forthTrue);
  } else {
    SPpush(0);
  }
}
// Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.

void TXbang() { Serial.write(SPpop()); } // TX!
void bangIO() { Serial.begin(57600); } // !IO: Initialize IO port
void TXbangS(CELLTYPE byteaddr, byte len) { for (byte i=len; i > 0; i--) Serial.write(byteaddr++); }

// === Literals and Branches - using next value in dictionary === eForthAndZen#37

// push the value in the next code word
// The XT of this is stored in doLIT
void doLIT() { SPpush(IPnext()); }

// See DOES> and CREATE, this patches the field after the token compiled by the create to point to the code following the DOES>
// : DOES> R> LAST @ 2 CELLS - @ CELLL + ! ; // Untested Forth version, note side effect of the R> of doing an exit.
void DOES() {
  Mstore(
    Mfetch(Ufetch(LASToffset) - (2 << CELLSHIFT) ) + CELLL, // field after tokenVar compile by CREATE
    FROMROMADDR(romIP) // The address after the doDOES
  );
  EXIT(); // Exit the CREATE part
}

// Address Literals (aka branches and jumps) eForthAndZen#38

// decrement count on Return stack, and branch if not decremented past zero (FOR..NEXT)
// noinspection JSUnusedGlobalSymbols
void next() {
  CELLTYPE x = RPpop();
  const CELLTYPE destn = IPnext(); // Increments over it
  if (--x >= 0) {
    RPpush(x);
    romIP = ROMADDR(destn); // Jump back
  }
}

// Jump if flag on stack is zero to destn in dictionary
void qBranch() {
  const CELLTYPE destn = IPnext();
  if (!SPpop()) {
    romIP = ROMADDR(destn);
  }
}

// Unconditional jump to destn in dictionary
void branch() { romIP = ROMADDR(IPnext()); }

// Memory access eForthAndZen#39
void store() { Mstore(SPpop(), SPpop()); } //!  w a -- , Store
void fetch() { SPpush(Mfetch(SPpop())); } //@ a -- w, fetch
void cStore() { Mstore8(SPpop(), SPpop()); } //C! c a -- , Store character
void cFetch() { SPpush(Mfetch8(SPpop())); } //C@ a -- c, Fetch character


  // Return stack words eForthAndZen#40
void RPat() { SPpush(FROMRAMADDR(ramRP)); } //RP@
void RPbang() { ramRP = RAMADDR(SPpop()); } // RP! must be aligned
void Rfrom() { SPpush(RPpop()); } // R>
void Rat() { SPpush(RPfetch()); } // R@
void toR() { RPpush(SPpop()); } // >R

  // Data stack initialization eForthAndZen#41
void SPat() { SPpush(FROMRAMADDR(ramSP)); } //SP@
void SPbang() { ramSP = RAMADDR(SPpop()); } //SP! must be aligned

// Classic Data stack words eForthAndZen#42
void DROP() { ramSP++; };
void DUP() { SPpush(SPfetch()); };
void SWAP() {
  const CELLTYPE x = SPpop();
  const CELLTYPE y = SPpop();
  SPpush(x);
  SPpush(y);
};
void OVER() {
  const CELLTYPE x = SPpop();
  const CELLTYPE y = SPfetch();
  SPpush(x);
  SPpush(y);
}; // TODO optimize

  // Logical Words eForthAndZen43
  // noinspection JSBitwiseOperatorUsage
void less0() { SPpush((SPpop() & (1 << (CELLbits - 1))) ? -1 : 0); } //0<  e.g. 0x8000 for CELLL=2
void AND() { SPpush(SPpop() & SPpop()); }
void OR() { SPpush(SPpop() | SPpop()); }
void XOR() { SPpush(SPpop() ^ SPpop()); }

  // Primitive Arithmetic Word eForthAndZen44
void UMplus() {
  const CELLTYPE a = SPpop();
  const CELLTYPE b = SPpop();
  /*
  if (CELLL === 4) {
    // JS truncates to 32 bits before shift, so use it here rather than getting bitten below
    const x = (a >>> 0) + (b >>> 0);
    SPpush(x >>> 0);
    SPpush(x >= 0x100000000 ? 1 : 0);
  } else {
  */
    // Note there is what I believe is a JS bug where x >> 32 is a noop so do th double shift
    const CELLTYPE x = a + b;
    SPpush(x); // This should only push the bottom cell.
    SPpush(x >> CELLbits);
  //}
}
  // === Define and initialize User variables Zen pg33 see Zen pg46
  // See Zen pg31 for tokenUser etc and $USER and Zen pg33 for USER initialization values

  // TODO-28-MULTITASK will need to think carefully about how to move all, or part of the USER space to task-specific space.
  // TODO-28-MULTITASK this is non-trivial since somethings are clearly across all tasks (e.g. CP and NP)
void userAreaInit() {
  for (byte a = 0; a < _USER; a++) {
    Ustore(a, cellRomFetch(UZERO + a));
  }
}

  // The opposite of userAreaInit - save values for restoration at COLD
  // Note it saves the value of LAST which is also in "FORTH", the "OVERT" in COLD restores that
void userAreaSave() {
  #ifdef WRITEROM
    for (byte a = 0; a < _USER; a++) {
      cellRomStore(UZERO + a, Ufetch(a));
    }
  #else
    Serial.println(F("Cannot write to Rom area"));
  #endif
}

  // === Forth words written in JS as needed for the interpreter

void PARSE() { // returns b (address) and u (length)
  const byte delimiter = SPpop(); // delimiter
  const CELLTYPE tib = Ufetch(TIBoffset);
  const byte ntib = Ufetch(nTIBoffset);
  byte inoffset = Ufetch(INoffset);
  if (delimiter == BL) {
    while ((inoffset < ntib) && (Mfetch8(tib + inoffset) <= BL)) {
      inoffset++;
    }  // If blank then skip over leading BL /control chars
  }
  // inoffset now points at first non-delimiter or #TIB
  const CELLTYPE b = tib + inoffset; // Save start of string
  while ((inoffset < ntib) && ((delimiter == BL) ? (delimiter < Mfetch8(tib + inoffset)) : (delimiter != Mfetch8(tib + inoffset)))) {
    inoffset++;
  } // Exit with inoffset at #TIB or after delimiter
  SPpush(b);
  SPpush(tib + inoffset - b); // Store length not including trailing delimiter
  Ustore(INoffset, inoffset < ntib ? ++inoffset : inoffset); // Skip over delimiter - TODO its not clear this is what FORTH wants. eForth doc is almost certainly wrong
}

// JS version of TOKEN - same signature
//TODO-ARDUINO optimize TOKEN to use cell pointers
void TOKEN() { // -- a; <string>; copy blank delimited string to name buffer, immediately below name dictionary (location is important as ':' take a shortcut in eForth.
  SPpush(BL);
  PARSE();   // b u (counted string, adjusts >IN)
  const byte u = min(SPpop(), nameMaxLength); // length of string
  const CELLTYPE b = SPpop(); // start of string
  const CELLTYPE np = align(npFetch() - u - CELLL); // Enough space in Name Directory to copy string optionally with one zero after
  // Careful if edit next formula, align doesnt change if mem=8, AND in this case np may not be on a cell boundary
  Mstore(np + ((u / CELLL)>>0) * CELLL, 0); // Write a zero in the last cell where the last letter of word will be written
  copyWithin(np + 1, b, b + u);
  Mstore8(np, u);  // 1 byte count
  SPpush(np); // Note that NP is not updated, the same buffer will be used for each word until hit ':'
}

// Same footprint as NUMBER?, this will be stored vectored from 'NUMBER and then replaced by FORTH version. 
void NUMBERQ() { 
  CELLTYPE a = SPpop();
  const CELLTYPE aa = a;
  const byte radix = Ufetch(BASEoffset); //TODO-ANDROID handle base other than 10 BUT maybe not needed as switch to Forth version before ever use non-decimal
  bool neg = false;
  CELLTYPE acc = 0;
  for (byte i = Mfetch8(a++); i > 0; i--) {
    byte c = Mfetch8(a++); 
    if (c == '-') {
       neg = true;
    } else if ((c > '9') || (c < '0')) {
        SPpush(aa);
        SPpush(0);
        return;
    } else {
      c = c - '0';
      acc = (acc * radix) + acc;
    }
  }
  if (neg) { acc = -acc; }
  SPpush(acc);
  SPpush(forthTrue);
}
/* Not needed on Arduino
  // If we are going to compile it, then check its not compiling into the dict, code we plan on replacing. (See same code on "'")
  checkNotCompilingReplaceable(xt, na) {
    if (jsFunctionAttributes[Mfetch(xt)].replaced) {
      const inDefOf = countedToJS(lastFetch());
      if (!['[COMPILE]', '(', 'create', 'CREATE', 'vCREATE'].includes(inDefOf)) { // Intentionally redefine ( so ok with redefinition
        console.log('Compiling', countedToJS(na), 'in', inDefOf, 'when code will be deleted');
        console.assert(false); // Break here, shouldn't be happening.
      }
    }
  }
*/

void dCOMPILE() { // a -- ...; same signature as to $COMPILE at Zen pg96
    findName(); // xt na | a F
    const CELLTYPE na = SPpop();
    if (na) { // ca
      const CELLTYPE xt = SPpop();
      const byte ch = Mfetch8(na);
      // noinspection JSBitwiseOperatorUsage
      if (ch & IMED) {
        runXT(xt);
      } else {
        //TODO-ARDUINO dont think needed: checkNotCompilingReplaceable(xt, na);
        //if (testing & 0x02) console.log('COMPILING:', countedToJS(na));
        DW(xt);
      }
    } else { // a
      runXT(Ufetch(NUMBERoffset)); // n T | a F // Works as long as NUMBER is code, OR this is called from code.
      if (SPpop()) {
        DW(js2xtdoLIT);
        DW(SPpop());
      } else {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        Serial.print(F("Cannot find or convert to number")); printCounted(SPpop());
      }
    }
  }

void dINTERPRET() { // a -- ...; Based on signature of $INTERPRET at Zen pg83
  findName(); // xt na | a F
  const CELLTYPE na = SPpop();
  if (na) { // ca
    const CELLTYPE xt = SPpop();
    runXT(xt); //TODO-ASYNC maybe should be threadToken - but that won't work if this isn't running inside run already
  } else {
    runXT(Ufetch(NUMBERoffset)); // n T | a F
    if (!SPpop()) {
      // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
      Serial.print(F("Cannot find or convert to number")); printCounted(SPpop());
    }
  }
}

/*
void EVAL() { // Same signature as Forth EVAL, reads tokens from TIB and interprets
  while (Ufetch(INoffset) < Ufetch(nTIBoffset)) {
    TOKEN(); // a ; pointing to word in Name Buffer (NB)
    // There may be case where TOKEN returns empty string at end of line or similar
    if (Mfetch8(SPfetch()) == 0) { // Skip zero length string
      SPpop();
    } else {
      // This is currently OK since its calling JS routines that may call Forth, there is no Forth-in-Forth
      runXT(Ufetch(EVALoffset));
    }
    // TODO-28-MULTITASK RP0 will move
    //console.assert(cellSP <= cellSPP && (cellRP * CELLL) <= Ufetch(RP0offset)); // Side effect of making SP and SPP available to debugger.
  }
  const CELLTYPE prompt = Ufetch(PROMPToffset);
  if (prompt) {
    runXT(prompt);
  }
}
*/
// ==== FORTH Interpreter - words that have no Forth equivalent ====
/*
void JStoTIB(s) {
  const TIBoff = Ufetch(TIBoffset);
  console.assert((TIBoff + s.length) < (Ufetch(RP0offset) - 10)); // Check for overlong lines
  Ustore(INoffset, 0); // Start at beginning of TIB
  Ustore(nTIBoffset,  m.encodeString(TIBoff, s)); // copy string to TIB, and store length in #TIB
}
*/
/*
// Take a multiline string, and pass line by line to EVAL
interpret(inp) {
  const inputs = inp.split('\n');
  // eslint-disable-next-line no-restricted-syntax,guard-for-in
  for (const i in inputs) {
    // noinspection JSUnfilteredForInLoop
    const inputline = inputs[i];
    if (testing & 0x01) {
      console.log(debugCells(cellSP, cellSPP), ' >>', inputline);
    }
    JStoTIB(inputline);
    await EVAL();
  }
}
*/
/*
async interpret1(inp) {
  JStoTIB(inp);
  await runXT(JStoXT('quit1', true));
}
// === A group of words required for the JS interpreter redefined later
*/

// : [  doLIT $INTERPRET 'EVAL ! ; IMMEDIATE
//Zen pg84 and Zen pg88  redefined below to use FORTH $INTERPRET
void openBracket() {
  Ustore(EVALoffset, js2xtdINTERPRET); // uses JS $INTERPRET
}

// : ] doLIT $COMPILE 'EVAL ! ;
//Zen pg84 and Zen pg95  redefined below to use FORTH $COMPILE
void closeBracket() {
  Ustore(EVALoffset, js2xtdCOMPILE);
}

// : : TOKEN $,n [ ' doLIST ] LITERAL ] ; see Zen pg96
void colon() {
  TOKEN();  // a; (counted string in named space)
  cpAlign(); // Before dollarCommaN so code field in Name dictionary correct
  dollarCommaN();
  DW(tokenDoList); // Must be after creating the name and links etc TODO-ARDUINO tokenDoList is token and function
  closeBracket();
}

// : ; doLIT EXIT , OVERT [ ; IMMEDIATE
void semicolon() { // Zen pg95
  DW(js2xtEXIT);
  OVERT();
  openBracket();
}

// : ' ( -- xt ) TOKEN NAME? IF EXIT THEN THROW ; // Zen pg89 needs TOKEN NAME? THROW all of which are advanced
void tick() { // -- xt; Search for next word in input stream
  TOKEN(); // -- a; String with count in first byte
  //const a = SPfetch(); // used for debugging
  findName(); // xt na | a 0
  const CELLTYPE na = SPpop();
  if (!na) {
    printCounted(SPpop()); Serial.println(F("not found during"));
  } else {
    // For debugging need to make sure we are not including code that will replaced by Forth versions.
    // checkNotCompilingReplaceable(SPfetch(), na);
  }
}

void console() {
  runXT(js2xtWARM);
}




// ==== NEXT GROUP - HAVE TO BE MOVED DOWN BECAUSE OF USE === 
// L.1853 jsFunctions[]=
const void (*f[60])(CELLTYPE) = { 
  tokenVocabulary, tokenNextVal, tokenDoList, tokenUser, tokenVar, 
  ALIGNED, find, OVERT, dollarCommaN /* $,n */, ToNAME /* >NAME */, MS, BYE, EXIT, EXECUTE, 
  QRX /* ?RX */, TXbang /* TX! */, bangIO /*bangIO */, 
  doLIT, DOES /* DOES> */, next, qBranch /* ?branch */, branch,
  store /* ! */, fetch /* @ */, cFetch /* C@ */, cStore /* C! */,
  RPat /* RP@*/, RPbang /* RP! */, Rfrom /* R> */, Rat /* R@ */, toR /* >R */,
  SPat /* SP@ */, SPbang /* SP! */,
  DROP, DUP, SWAP, OVER,
  less0 /* 0< */, AND, OR, XOR, UMplus /* UM+ */,
  userAreaInit, userAreaSave,
  PARSE, TOKEN, NUMBERQ /* NUMBER? */, dCOMPILE /* $COMPILE */, dINTERPRET /* $INTERPRET */,
  openBracket /* [ */, closeBracket /* ] */, colon /* : */, semicolon /* ; */, tick /* ' */, 
  debugNA, testing3, Fbreak /* break */, debugPrintTIB, TEST,
  0 };

#ifdef WRITEROM
CELLTYPE rom[ROMCELLS] = { 1, 2, 3 };
#else
/* === Dumping Arduino source from dictionary === */
/* === Dumping Arduino source from names === */
#define XT_WARM 0x11cc /* WARM*/
#define XT_COLD 0x11aa /* COLD*/
#define XT__27BOOT 0x11a4 /* 'BOOT*/
#define XT_EMPTY 0x1194 /* EMPTY*/
#define XT_hi 0x118c /* hi*/
#define XT_version 0x1158 /* version*/
#define XT_VER 0x1154 /* VER*/
#define XT_SEE 0x10ce /* SEE*/
#define XT_FORTH_3ENAME 0x1090 /* FORTH>NAME*/
#define XT_WORDS 0x106e /* WORDS*/
#define XT__2EID 0x104e /* .ID*/
#define XT__3FCSP 0x1034 /* ?CSP*/
#define XT__21CSP 0x102a /* !CSP*/
#define XT__2EFREE 0x101e /* .FREE*/
#define XT__2EBASE 0x100c /* .BASE*/
#define XT__2ES 0xfec /* .S*/
#define XT_DUMP 0xfa8 /* DUMP*/
#define XT_dm_2B 0xf80 /* dm+*/
#define XT__5FTYPE 0xf62 /* _TYPE*/
#define XT_CONSTANT 0xf52 /* CONSTANT*/
#define XT_VARIABLE 0xf46 /* VARIABLE*/
#define XT_vCREATE 0xf2a /* vCREATE*/
#define XT_CREATE 0xf22 /* CREATE*/
#define XT_create 0xf10 /* create*/
#define XT_USER 0xf02 /* USER*/
#define XT__3A 0xef4 /* :*/
#define XT__5D 0xee8 /* ]*/
#define XT__3B 0xedc /* ;*/
#define XT_OVERT 0xece /* OVERT*/
#define XT__24COMPILE 0xea0 /* $COMPILE*/
#define XT__24_2Cn 0xe64 /* $,n*/
#define XT__3FUNIQUE 0xe48 /* ?UNIQUE*/
#define XT__24_22 0xe3e /* $"*/
#define XT_RECURSE 0xe32 /* RECURSE*/
#define XT__5BCOMPILE_5D 0xe2a /* [COMPILE]*/
#define XT_vALLOT 0xe14 /* vALLOT*/
#define XT_ALLOT 0xe0c /* ALLOT*/
#define XT__27 0xdfc /* '*/
#define XT_quit1 0xde8 /* quit1*/
#define XT_QUIT 0xdc8 /* QUIT*/
#define XT_quitError 0xd98 /* quitError*/
#define XT_que 0xd90 /* que*/
#define XT_CONSOLE 0xd82 /* CONSOLE*/
#define XT_I_2FO 0xd7a /* I/O*/
#define XT_HAND 0xd68 /* HAND*/
#define XT_FILE 0xd56 /* FILE*/
#define XT_XIO 0xd3e /* XIO*/
#define XT_PRESET 0xd2c /* PRESET*/
#define XT__5B 0xd20 /* [*/
#define XT_EVAL 0xd02 /* EVAL*/
#define XT__3FSTACK 0xcee /* ?STACK*/
#define XT__2EOK 0xcd4 /* .OK*/
#define XT__24INTERPRET 0xca0 /* $INTERPRET*/
#define XT__2E_22 0xc96 /* ."*/
#define XT_ABORT_22 0xc8c /* ABORT"*/
#define XT__24_2C_22 0xc78 /* $,"*/
#define XT_abort_22 0xc68 /* abort"*/
#define XT_ABORT 0xc60 /* ABORT*/
#define XT_NULL_24 0xc5a /* NULL$*/
#define XT_THROW 0xc3e /* THROW*/
#define XT_CATCH 0xc1a /* CATCH*/
#define XT_QUERY 0xbfe /* QUERY*/
#define XT_EXPECT 0xbf0 /* EXPECT*/
#define XT_accept 0xbb8 /* accept*/
#define XT_kTAP 0xb76 /* kTAP*/
#define XT_TAP 0xb62 /* TAP*/
#define XT__5EH 0xb36 /* ^H*/
#define XT_NAME_3F 0xafc /* NAME?*/
#define XT_FORTHfind 0xa8a /* FORTHfind*/
#define XT_SAME_3F 0xa56 /* SAME?*/
#define XT_NAME_3E 0xa48 /* NAME>*/
#define XT_WORD 0xa3e /* WORD*/
#define XT_TOKEN 0xa24 /* TOKEN*/
#define XT__2E_28 0xa18 /* .(*/
#define XT_CTRL 0xa0c /* CTRL*/
#define XT_CHAR 0xa00 /* CHAR*/
#define XT_PARSE 0x9e0 /* PARSE*/
#define XT_parse 0x93e /* parse*/
#define XT__2E_22_7C 0x936 /* ."|*/
#define XT__24_22_7C 0x930 /* $"|*/
#define XT_do_24 0x91a /* do$*/
#define XT_CR 0x90a /* CR*/
#define XT_PACE 0x900 /* PACE*/
#define XT_NUF_3F 0x8ea /* NUF?*/
#define XT_KEY 0x8d4 /* KEY*/
#define XT__3FKEY 0x8cc /* ?KEY*/
#define XT_NUMBER_3F 0x826 /* NUMBER?*/
#define XT_DIGIT_3F 0x7f8 /* DIGIT?*/
#define XT__3F 0x7f0 /* ?*/
#define XT__2E 0x7d4 /* .*/
#define XT_U_2E 0x7c6 /* U.*/
#define XT_U_2ER 0x7b0 /* U.R*/
#define XT__2ER 0x79e /* .R*/
#define XT_DECIMAL 0x792 /* DECIMAL*/
#define XT_HEX 0x786 /* HEX*/
#define XT_str 0x772 /* str*/
#define XT__2E_24 0x76a /* .$*/
#define XT_TYPE 0x74e /* TYPE*/
#define XT_SPACES 0x746 /* SPACES*/
#define XT_CHARS 0x72a /* CHARS*/
#define XT_SPACE 0x722 /* SPACE*/
#define XT_EMIT 0x71a /* EMIT*/
#define XT__23_3E 0x70a /* #>*/
#define XT_SIGN 0x6fa /* SIGN*/
#define XT__23S 0x6ea /* #S*/
#define XT__23 0x6de /* #*/
#define XT_HOLD 0x6c8 /* HOLD*/
#define XT__3C_23 0x6be /* <#*/
#define XT_EXTRACT 0x6ae /* EXTRACT*/
#define XT_DIGIT 0x694 /* DIGIT*/
#define XT_PACK_24 0x65a /* PACK$*/
#define XT__2DTRAILING 0x62e /* -TRAILING*/
#define XT_FILL 0x610 /* FILL*/
#define XT_CMOVE 0x5e8 /* CMOVE*/
#define XT_COUNT 0x5d8 /* COUNT*/
#define XT__40EXECUTE 0x5c4 /* @EXECUTE*/
#define XT_TIB 0x5ba /* TIB*/
#define XT_PAD 0x5ae /* PAD*/
#define XT_vCREATE 0x592 /* vCREATE*/
#define XT_v_2C 0x572 /* v,*/
#define XT_vHERE 0x560 /* vHERE*/
#define XT_2_40 0x552 /* 2@*/
#define XT_2_21 0x544 /* 2!*/
#define XT__2B_21 0x534 /* +!*/
#define XT_PICK 0x522 /* PICK*/
#define XT_DEPTH 0x510 /* DEPTH*/
#define XT__3ECHAR 0x4f2 /* >CHAR*/
#define XT_CELLS 0x4ea /* CELLS*/
#define XT_CELL_2D 0x4e2 /* CELL-*/
#define XT__2A_2F 0x4da /* * /*/
#define XT__2A_2FMOD 0x4ce /* * /MOD*/
#define XT_M_2A 0x4b2 /* M**/
#define XT__2A 0x4aa /* **/
#define XT_UM_2A 0x470 /* UM**/
#define XT__2F 0x468 /* /*/
#define XT_MOD 0x460 /* MOD*/
#define XT__2FMOD 0x454 /* /MOD*/
#define XT_M_2FMOD 0x41e /* M/MOD*/
#define XT_UM_2FMOD 0x3ba /* UM/MOD*/
#define XT_WITHIN 0x3aa /* WITHIN*/
#define XT_MIN 0x398 /* MIN*/
#define XT_MAX 0x388 /* MAX*/
#define XT__3C 0x370 /* <*/
#define XT_U_3C 0x358 /* U<*/
#define XT__3D 0x344 /* =*/
#define XT_0_3D 0x330 /* 0=*/
#define XT_ABS 0x322 /* ABS*/
#define XT__2D 0x31a /* -*/
#define XT_DNEGATE 0x306 /* DNEGATE*/
#define XT_NEGATE 0x2fa /* NEGATE*/
#define XT_INVERT 0x2f0 /* INVERT*/
#define XT_D_2B 0x2dc /* D+*/
#define XT__2B 0x2d4 /* +*/
#define XT_2DUP 0x2cc /* 2DUP*/
#define XT__2DROT 0x2c0 /* -ROT*/
#define XT_ROT 0x2b4 /* ROT*/
#define XT__3FDUP 0x2a8 /* ?DUP*/
#define XT_WHILE 0x2a0 /* WHILE*/
#define XT_WHEN 0x298 /* WHEN*/
#define XT_ELSE 0x28e /* ELSE*/
#define XT_AFT 0x282 /* AFT*/
#define XT_THEN 0x27c /* THEN*/
#define XT_REPEAT 0x274 /* REPEAT*/
#define XT_AHEAD 0x26a /* AHEAD*/
#define XT_IF 0x260 /* IF*/
#define XT_AGAIN 0x256 /* AGAIN*/
#define XT_UNTIL 0x24c /* UNTIL*/
#define XT_NEXT 0x242 /* NEXT*/
#define XT_BEGIN 0x23c /* BEGIN*/
#define XT_FOR 0x232 /* FOR*/
#define XT__3ERESOLVE 0x228 /* >RESOLVE*/
#define XT__3EMARK 0x21c /* >MARK*/
#define XT__3CRESOLVE 0x216 /* <RESOLVE*/
#define XT__3CMARK 0x210 /* <MARK*/
#define XT_CREATE 0x208 /* CREATE*/
#define XT_create 0x1f6 /* create*/
#define XT_LITERAL 0x1ec /* LITERAL*/
#define XT_COMPILE 0x1dc /* COMPILE*/
#define XT__5BCOMPILE_5D 0x1d4 /* [COMPILE]*/
#define XT__2C 0x1c2 /* ,*/
#define XT_CELL_2B 0x1b8 /* CELL+*/
#define XT_HERE 0x1b0 /* HERE*/
#define XT_NIP 0x1a8 /* NIP*/
#define XT__5CT 0x19c /* \T*/
#define XT__5C 0x190 /* \*/
#define XT__28 0x184 /* (*/
#define XT_IMMEDIATE 0x17c /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x174 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x162 /* setHeaderBits*/
#define XT_2DROP 0x15a /* 2DROP*/
#define XT_VP 0x156 /* VP*/
#define XT_LAST 0x152 /* LAST*/
#define XT_NP 0x14e /* NP*/
#define XT_CP 0x14a /* CP*/
#define XT_CURRENT 0x146 /* CURRENT*/
#define XT_CONTEXT 0x142 /* CONTEXT*/
#define XT_HANDLER 0x13e /* HANDLER*/
#define XT_HLD 0x13a /* HLD*/
#define XT__27NUMBER 0x136 /* 'NUMBER*/
#define XT__27EVAL 0x132 /* 'EVAL*/
#define XT_CSP 0x12e /* CSP*/
#define XT__23TIB 0x12a /* #TIB*/
#define XT__3EIN 0x126 /* >IN*/
#define XT_SPAN 0x122 /* SPAN*/
#define XT_temp 0x11e /* temp*/
#define XT_BASE 0x11a /* BASE*/
#define XT__27PROMPT 0x116 /* 'PROMPT*/
#define XT__27ECHO 0x112 /* 'ECHO*/
#define XT__27TAP 0x10e /* 'TAP*/
#define XT__27EXPECT 0x10a /* 'EXPECT*/
#define XT__27EMIT 0x106 /* 'EMIT*/
#define XT__27_3FKEY 0x102 /* '?KEY*/
#define XT_RP0 0xfe /* RP0*/
#define XT_SP0 0xfa /* SP0*/
#define XT_TEST 0xf8 /* TEST*/
#define XT_debugPrintTIB 0xf6 /* debugPrintTIB*/
#define XT_break 0xf4 /* break*/
#define XT_testing3 0xf2 /* testing3*/
#define XT_debugNA 0xf0 /* debugNA*/
#define XT__27 0xee /* '*/
#define XT__3B 0xec /* ;*/
#define XT__3A 0xea /* :*/
#define XT__5D 0xe8 /* ]*/
#define XT__5B 0xe6 /* [*/
#define XT__24INTERPRET 0xe4 /* $INTERPRET*/
#define XT__24COMPILE 0xe2 /* $COMPILE*/
#define XT_NUMBER_3F 0xe0 /* NUMBER?*/
#define XT_TOKEN 0xde /* TOKEN*/
#define XT_PARSE 0xdc /* PARSE*/
#define XT_userAreaSave 0xda /* userAreaSave*/
#define XT_userAreaInit 0xd8 /* userAreaInit*/
#define XT_UM_2B 0xd6 /* UM+*/
#define XT_XOR 0xd4 /* XOR*/
#define XT_OR 0xd2 /* OR*/
#define XT_AND 0xd0 /* AND*/
#define XT_0_3C 0xce /* 0<*/
#define XT_OVER 0xcc /* OVER*/
#define XT_SWAP 0xca /* SWAP*/
#define XT_DUP 0xc8 /* DUP*/
#define XT_DROP 0xc6 /* DROP*/
#define XT_SP_21 0xc4 /* SP!*/
#define XT_SP_40 0xc2 /* SP@*/
#define XT__3ER 0xc0 /* >R*/
#define XT_R_40 0xbe /* R@*/
#define XT_R_3E 0xbc /* R>*/
#define XT_RP_21 0xba /* RP!*/
#define XT_RP_40 0xb8 /* RP@*/
#define XT_C_21 0xb6 /* C!*/
#define XT_C_40 0xb4 /* C@*/
#define XT__40 0xb2 /* @*/
#define XT__21 0xb0 /* !*/
#define XT_branch 0xae /* branch*/
#define XT__3Fbranch 0xac /* ?branch*/
#define XT_next 0xaa /* next*/
#define XT_DOES_3E 0xa8 /* DOES>*/
#define XT_doLIT 0xa6 /* doLIT*/
#define XT__21IO 0xa4 /* !IO*/
#define XT_TX_21 0xa2 /* TX!*/
#define XT__3FRX 0xa0 /* ?RX*/
#define XT_EXECUTE 0x9e /* EXECUTE*/
#define XT_EXIT 0x9c /* EXIT*/
#define XT_BYE 0x9a /* BYE*/
#define XT_MS 0x98 /* MS*/
#define XT__3ENAME 0x96 /* >NAME*/
#define XT__24_2Cn 0x94 /* $,n*/
#define XT_OVERT 0x92 /* OVERT*/
#define XT_find 0x90 /* find*/
#define XT_ALIGNED 0x8e /* ALIGNED*/
#define XT_tokenCreate 0x8a /* tokenCreate*/
#define XT_tokenVar 0x86 /* tokenVar*/
#define XT_tokenUser 0x82 /* tokenUser*/
#define XT_tokenDoList 0x7e /* tokenDoList*/
#define XT_tokenNextVal 0x7a /* tokenNextVal*/
#define XT_tokenVocabulary 0x76 /* tokenVocabulary*/
#define XT_BL 0x72 /* BL*/
#define XT__3DBYTEMASK 0x6e /* =BYTEMASK*/
#define XT__3DIMED 0x6a /* =IMED*/
#define XT__3DCOMP 0x66 /* =COMP*/
#define XT_TIB0 0x62 /* TIB0*/
#define XT_CELLMASK 0x5e /* CELLMASK*/
#define XT_CELLbits 0x5a /* CELLbits*/
#define XT_CELLL 0x56 /* CELLL*/
#define XT_FORTH 0x50 /* FORTH*//* === Function tokens === */
#define F_tokenVocabulary 1
#define F_tokenNextVal 2
#define F_tokenDoList 3
#define F_tokenUser 4
#define F_tokenVar 5
#define F_tokenCreate 6
#define F_ALIGNED 7
#define F_find 8
#define F_OVERT 9
#define F_dollarCommaN 10
#define F_ToNAME 11
#define F_MS 12
#define F_BYE 13
#define F_EXIT 14
#define F_EXECUTE 15
#define F_QRX 16
#define F_TXbang 17
#define F_bangIO 18
#define F_doLIT 19
#define F_DOES 20
#define F_next 21
#define F_qBranch 22
#define F_branch 23
#define F_store 24
#define F_fetch 25
#define F_cFetch 26
#define F_cStore 27
#define F_RPat 28
#define F_RPbang 29
#define F_Rfrom 30
#define F_Rat 31
#define F_toR 32
#define F_SPat 33
#define F_SPbang 34
#define F_DROP 35
#define F_DUP 36
#define F_SWAP 37
#define F_OVER 38
#define F_less0 39
#define F_AND 40
#define F_OR 41
#define F_XOR 42
#define F_UMplus 43
#define F_userAreaInit 44
#define F_userAreaSave 45
#define F_PARSE 46
#define F_TOKEN 47
#define F_NUMBERQ 48
#define F__24COMPILE 49
#define F__24INTERPRET 50
#define F_openBracket 51
#define F_closeBracket 52
#define F_colon 53
#define F_semicolon 54
#define F_tick 55
#define F_debugNA 56
#define F_testing3 57
#define F_break 58
#define F_debugPrintTIB 59
#define F_TEST 60

const CELLTYPE rom[ROMCELLS] PROGMEM = {

/* ==== USER VARIABLE SAVE AREA ==== */
/* 0x0 */ 0,
/* 0x2 */ 0,
/* 0x4 */ 0,
/* 0x6 */ 0,
/* 0x8 */ 0x8080,
/* 0xa */ 0x8190,
/* 0xc */ XT__3FRX,
/* 0xe */ XT_TX_21,
/* 0x10 */ XT_accept,
/* 0x12 */ 0,
/* 0x14 */ XT_TX_21,
/* 0x16 */ 0,
/* 0x18 */ 0xa,
/* 0x1a */ 0x20,
/* 0x1c */ 0,
/* 0x1e */ 0xd,
/* 0x20 */ 0x3a,
/* 0x22 */ 0x8090,
/* 0x24 */ 0,
/* 0x26 */ XT__24INTERPRET,
/* 0x28 */ XT_NUMBER_3F,
/* 0x2a */ 0,
/* 0x2c */ 0,
/* 0x2e */ 0x52,
/* 0x30 */ 0,
/* 0x32 */ 0,
/* 0x34 */ 0,
/* 0x36 */ 0,
/* 0x38 */ 0,
/* 0x3a */ 0,
/* 0x3c */ 0,
/* 0x3e */ 0,
/* 0x40 */ 0x52,
/* 0x42 */ 0x52,
/* 0x44 */ 0x11d8,
/* 0x46 */ 0x1500,
/* 0x48 */ 0x1504,
/* 0x4a */ 0,
/* 0x4c */ 0,
/* 0x4e */ 0,
/* ==== CODE DICTIONARY ==== */
/* 0x50: FORTH */ F_tokenVocabulary, 0x1504, 0, 
/* 0x56: CELLL */ F_tokenNextVal, 2, 
/* 0x5a: CELLbits */ F_tokenNextVal, 0x10, 
/* 0x5e: CELLMASK */ F_tokenNextVal, 0xff1f, 
/* 0x62: TIB0 */ F_tokenNextVal, 0x8090, 
/* 0x66: =COMP */ F_tokenNextVal, 0x40, 
/* 0x6a: =IMED */ F_tokenNextVal, XT__3DIMED + 0x16, 
/* 0x6e: =BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x72: BL */ F_tokenNextVal, 0x20, 
/* 0x76: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x7a: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x7e: tokenDoList */ F_tokenNextVal, 3, 
/* 0x82: tokenUser */ F_tokenNextVal, 4, 
/* 0x86: tokenVar */ F_tokenNextVal, 5, 
/* 0x8a: tokenCreate */ F_tokenNextVal, 6, 
/* 0x8e: ALIGNED */ F_ALIGNED, 
/* 0x90: find */ F_find, 
/* 0x92: OVERT */ F_OVERT, 
/* 0x94: $,n */ F_dollarCommaN, 
/* 0x96: >NAME */ F_ToNAME, 
/* 0x98: MS */ F_MS, 
/* 0x9a: BYE */ F_BYE, 
/* 0x9c: EXIT */ F_EXIT, 
/* 0x9e: EXECUTE */ F_EXECUTE, 
/* 0xa0: ?RX */ F_QRX, 
/* 0xa2: TX! */ F_TXbang, 
/* 0xa4: !IO */ F_bangIO, 
/* 0xa6: doLIT */ F_doLIT, 
/* 0xa8: DOES> */ F_DOES, 
/* 0xaa: next */ F_next, 
/* 0xac: ?branch */ F_qBranch, 
/* 0xae: branch */ F_branch, 
/* 0xb0: ! */ F_store, 
/* 0xb2: @ */ F_fetch, 
/* 0xb4: C@ */ F_cFetch, 
/* 0xb6: C! */ F_cStore, 
/* 0xb8: RP@ */ F_RPat, 
/* 0xba: RP! */ F_RPbang, 
/* 0xbc: R> */ F_Rfrom, 
/* 0xbe: R@ */ F_Rat, 
/* 0xc0: >R */ F_toR, 
/* 0xc2: SP@ */ F_SPat, 
/* 0xc4: SP! */ F_SPbang, 
/* 0xc6: DROP */ F_DROP, 
/* 0xc8: DUP */ F_DUP, 
/* 0xca: SWAP */ F_SWAP, 
/* 0xcc: OVER */ F_OVER, 
/* 0xce: 0< */ F_less0, 
/* 0xd0: AND */ F_AND, 
/* 0xd2: OR */ F_OR, 
/* 0xd4: XOR */ F_XOR, 
/* 0xd6: UM+ */ F_UMplus, 
/* 0xd8: userAreaInit */ F_userAreaInit, 
/* 0xda: userAreaSave */ F_userAreaSave, 
/* 0xdc: PARSE */ F_PARSE, 
/* 0xde: TOKEN */ F_TOKEN, 
/* 0xe0: NUMBER? */ F_NUMBERQ, 
/* 0xe2: $COMPILE */ F__24COMPILE, 
/* 0xe4: $INTERPRET */ F__24INTERPRET, 
/* 0xe6: [ */ F_openBracket, 
/* 0xe8: ] */ F_closeBracket, 
/* 0xea: : */ F_colon, 
/* 0xec: ; */ F_semicolon, 
/* 0xee: ' */ F_tick, 
/* 0xf0: debugNA */ F_debugNA, 
/* 0xf2: testing3 */ F_testing3, 
/* 0xf4: break */ F_break, 
/* 0xf6: debugPrintTIB */ F_debugPrintTIB, 
/* 0xf8: TEST */ F_TEST, 
/* 0xfa: SP0 */ F_tokenUser, 8, 
/* 0xfe: RP0 */ F_tokenUser, 0xa, 
/* 0x102: '?KEY */ F_tokenUser, 0xc, 
/* 0x106: 'EMIT */ F_tokenUser, 0xe, 
/* 0x10a: 'EXPECT */ F_tokenUser, 0x10, 
/* 0x10e: 'TAP */ F_tokenUser, 0x12, 
/* 0x112: 'ECHO */ F_tokenUser, 0x14, 
/* 0x116: 'PROMPT */ F_tokenUser, 0x16, 
/* 0x11a: BASE */ F_tokenUser, 0x18, 
/* 0x11e: temp */ F_tokenUser, 0x1a, 
/* 0x122: SPAN */ F_tokenUser, 0x1c, 
/* 0x126: >IN */ F_tokenUser, 0x1e, 
/* 0x12a: #TIB */ F_tokenUser, 0x20, 
/* 0x12e: CSP */ F_tokenUser, 0x24, 
/* 0x132: 'EVAL */ F_tokenUser, 0x26, 
/* 0x136: 'NUMBER */ F_tokenUser, 0x28, 
/* 0x13a: HLD */ F_tokenUser, 0x2a, 
/* 0x13e: HANDLER */ F_tokenUser, 0x2c, 
/* 0x142: CONTEXT */ F_tokenUser, 0x2e, 
/* 0x146: CURRENT */ F_tokenUser, 0x40, 
/* 0x14a: CP */ F_tokenUser, 0x44, 
/* 0x14e: NP */ F_tokenUser, 0x46, 
/* 0x152: LAST */ F_tokenUser, 0x48, 
/* 0x156: VP */ F_tokenUser, 0x4a, 
/* 0x15a: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x162: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x174: COMPILE-ONLY */ F_tokenDoList, XT__3DCOMP, XT_setHeaderBits, XT_EXIT, 
/* 0x17c: IMMEDIATE */ F_tokenDoList, XT__3DIMED, XT_setHeaderBits, XT_EXIT, 
/* 0x184: ( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_2DROP, XT_EXIT, 
/* 0x190: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x19c: \T */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x1a8: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x1b0: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x1b8: CELL+ */ F_tokenDoList, XT_CELLL, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x1c2: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x1d4: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x1dc: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x1ec: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLIT, XT__2C, XT_EXIT, 
/* 0x1f6: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x208: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x210: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x216: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x21c: >MARK */ F_tokenDoList, XT_HERE, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x228: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x232: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x23c: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x242: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x24c: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x256: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x260: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x26a: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x274: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x27c: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x282: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x28e: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x298: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x2a0: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x2a8: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x2b4: ROT */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x2c0: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x2cc: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x2d4: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x2dc: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x2f0: INVERT */ F_tokenDoList, XT_doLIT, 0xffff, XT_XOR, XT_EXIT, 
/* 0x2fa: NEGATE */ F_tokenDoList, XT_INVERT, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x306: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLIT, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x31a: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x322: ABS */ F_tokenDoList, XT_DUP, XT_0_3C, XT__3Fbranch, XT_ABS + 0xc, XT_NEGATE, XT_EXIT, 
/* 0x330: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xe, XT_doLIT, 0, XT_branch, XT_0_3D + 0x12, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x344: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xe, XT_doLIT, 0, XT_EXIT, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x358: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x370: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x388: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x398: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x3aa: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x3ba: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x58, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4e, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DROP, XT_doLIT, 1, XT__2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x4c, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLIT, 0xffff, XT_DUP, XT_EXIT, 
/* 0x41e: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x454: /MOD */ F_tokenDoList, XT_OVER, XT_0_3C, XT_SWAP, XT_M_2FMOD, XT_EXIT, 
/* 0x460: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x468: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x470: UM* */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x4aa: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x4b2: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x4ce: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x4da: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x4e2: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x4ea: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x4f2: >CHAR */ F_tokenDoList, XT_doLIT, 0x7f, XT_AND, XT_DUP, XT_doLIT, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLIT, 0x5f, XT_EXIT, 
/* 0x510: DEPTH */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x522: PICK */ F_tokenDoList, XT_doLIT, 1, XT__2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x534: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x544: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x552: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x560: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x572: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x592: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x14, XT_CREATE, XT_branch, XT_vCREATE + 0x1a, XT_tokenVar, XT_create, XT__2C, XT_EXIT, 
/* 0x5ae: PAD */ F_tokenDoList, XT_vHERE, XT_doLIT, XT_FORTH, XT__2B, XT_EXIT, 
/* 0x5ba: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x5c4: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x10, XT_EXECUTE, XT_branch, XT__40EXECUTE + 0x12, XT_break, XT_EXIT, 
/* 0x5d8: COUNT */ F_tokenDoList, XT_DUP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x5e8: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x20, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_doLIT, 1, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_CMOVE + 0x8, XT_2DROP, XT_EXIT, 
/* 0x610: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x16, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x62e: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x22, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x22, XT_R_3E, XT_doLIT, 1, XT__2B, XT_EXIT, XT_next, XT__2DTRAILING + 0x8, XT_doLIT, 0, XT_EXIT, 
/* 0x65a: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLIT, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLIT, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, XT_EXIT, XT_EXIT, 
/* 0x694: DIGIT */ F_tokenDoList, XT_doLIT, 9, XT_OVER, XT__3C, XT_doLIT, 7, XT_AND, XT__2B, XT_doLIT, 0x30, XT__2B, XT_EXIT, 
/* 0x6ae: EXTRACT */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_UM_2FMOD, XT_SWAP, XT_DIGIT, XT_EXIT, 
/* 0x6be: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x6c8: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_doLIT, 1, XT__2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x6de: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x6ea: #S */ F_tokenDoList, XT__23, XT_DUP, XT__3Fbranch, XT__23S + 0xe, XT_branch, XT__23S + 0x2, XT_EXIT, 
/* 0x6fa: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLIT, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x70a: #> */ F_tokenDoList, XT_DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x71a: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x722: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x72a: CHARS */ F_tokenDoList, XT_SWAP, XT_doLIT, 0, XT_MAX, XT__3ER, XT_branch, XT_CHARS + 0x14, XT_DUP, XT_EMIT, XT_next, XT_CHARS + 0x10, XT_DROP, XT_EXIT, 
/* 0x746: SPACES */ F_tokenDoList, XT_BL, XT_CHARS, XT_EXIT, 
/* 0x74e: TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT_TYPE + 0x14, XT_DUP, XT_C_40, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT_TYPE + 0x8, XT_DROP, XT_EXIT, 
/* 0x76a: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x772: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x786: HEX */ F_tokenDoList, XT_doLIT, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x792: DECIMAL */ F_tokenDoList, XT_doLIT, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x79e: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x7b0: U.R */ F_tokenDoList, XT__3ER, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x7c6: U. */ F_tokenDoList, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x7d4: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLIT, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x7f0: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x7f8: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLIT, 0x30, XT__2D, XT_doLIT, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x26, XT_doLIT, 7, XT__2D, XT_DUP, XT_doLIT, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x826: NUMBER? */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_doLIT, 0, XT_OVER, XT_COUNT, XT_OVER, XT_C_40, XT_doLIT, 0x24, XT__3D, XT__3Fbranch, XT_NUMBER_3F + 0x30, XT_HEX, XT_SWAP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_doLIT, 1, XT__2D, XT_OVER, XT_C_40, XT_doLIT, 0x2d, XT__3D, XT__3ER, XT_SWAP, XT_R_40, XT__2D, XT_SWAP, XT_R_40, XT__2B, XT__3FDUP, XT__3Fbranch, XT_NUMBER_3F + 0x9a, XT_doLIT, 1, XT__2D, XT__3ER, XT_DUP, XT__3ER, XT_C_40, XT_BASE, XT__40, XT_DIGIT_3F, XT__3Fbranch, XT_NUMBER_3F + 0x8c, XT_SWAP, XT_BASE, XT__40, XT__2A, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_NUMBER_3F + 0x56, XT_DROP, XT_R_40, XT__3Fbranch, XT_NUMBER_3F + 0x86, XT_NEGATE, XT_SWAP, XT_branch, XT_NUMBER_3F + 0x98, XT_R_3E, XT_R_3E, XT_2DROP, XT_2DROP, XT_doLIT, 0, XT_DUP, XT_R_3E, XT_2DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x8cc: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x8d4: KEY */ F_tokenDoList, XT_doLIT, 0, XT_MS, XT_doLIT, XT_DUP, XT__3FKEY, XT__3Fbranch, XT_KEY + 0x6, XT_NIP, XT_EXIT, 
/* 0x8ea: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLIT, 0xd, XT__3D, XT_EXIT, 
/* 0x900: PACE */ F_tokenDoList, XT_doLIT, 0xb, XT_EMIT, XT_EXIT, 
/* 0x90a: CR */ F_tokenDoList, XT_doLIT, 0xd, XT_EMIT, XT_doLIT, 0xa, XT_EMIT, XT_EXIT, 
/* 0x91a: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x930: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x936: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x93e: parse */ F_tokenDoList, XT_temp, XT__21, XT_OVER, XT__3ER, XT_DUP, XT__3Fbranch, XT_parse + 0x9a, XT_doLIT, 1, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x4c, XT__3ER, XT_BL, XT_OVER, XT_C_40, XT__2D, XT_0_3C, XT_INVERT, XT__3Fbranch, XT_parse + 0x4a, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x24, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_DUP, XT_EXIT, XT_R_3E, XT_OVER, XT_SWAP, XT__3ER, XT_temp, XT__40, XT_OVER, XT_C_40, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x6a, XT_0_3C, XT__3Fbranch, XT_parse + 0x80, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x52, XT_DUP, XT__3ER, XT_branch, XT_parse + 0x8e, XT_R_3E, XT_DROP, XT_DUP, XT_doLIT, 1, XT__2B, XT__3ER, XT_OVER, XT__2D, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, XT_OVER, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x9e0: PARSE */ F_tokenDoList, XT__3ER, XT_TIB, XT__3EIN, XT__40, XT__2B, XT__23TIB, XT__40, XT__3EIN, XT__40, XT__2D, XT_R_3E, XT_parse, XT__3EIN, XT__2B_21, XT_EXIT, 
/* 0xa00: CHAR */ F_tokenDoList, XT_BL, XT_PARSE, XT_DROP, XT_C_40, XT_EXIT, 
/* 0xa0c: CTRL */ F_tokenDoList, XT_CHAR, XT_doLIT, 0x1f, XT_AND, XT_EXIT, 
/* 0xa18: .( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0xa24: TOKEN */ F_tokenDoList, XT_BL, XT_PARSE, XT__3DBYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0xa3e: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0xa48: NAME> */ F_tokenDoList, XT_doLIT, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0xa56: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 0x8, XT_doLIT, 0, XT_EXIT, 
/* 0xa8a: FORTHfind */ F_tokenDoList, XT_SWAP, XT_DUP, XT_C_40, XT_CELLL, XT__2F, XT_temp, XT__21, XT_DUP, XT__40, XT__3ER, XT_CELL_2B, XT_SWAP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTHfind + 0x4a, XT_DUP, XT__40, XT_doLIT, 0xff1f, XT_AND, XT_R_40, XT_XOR, XT__3Fbranch, XT_FORTHfind + 0x3e, XT_CELL_2B, XT_doLIT, 0xffff, XT_branch, XT_FORTHfind + 0x46, XT_CELL_2B, XT_temp, XT__40, XT_SAME_3F, XT_branch, XT_FORTHfind + 0x56, XT_R_3E, XT_DROP, XT_SWAP, XT_CELL_2D, XT_SWAP, XT_EXIT, XT__3Fbranch, XT_FORTHfind + 0x62, XT_CELL_2D, XT_CELL_2D, XT_branch, XT_FORTHfind + 0x1a, XT_R_3E, XT_DROP, XT_NIP, XT_CELL_2D, XT_DUP, XT_NAME_3E, XT_SWAP, XT_EXIT, 
/* 0xafc: NAME? */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_NAME_3F + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT_DUP, XT__3ER, XT__40, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x30, XT_find, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x12, XT_R_3E, XT_DROP, XT_EXIT, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0xb36: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0xb62: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0xb76: kTAP */ F_tokenDoList, XT_DUP, XT_doLIT, 0xd, XT__3D, XT_OVER, XT_doLIT, 0xa, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x3a, XT_doLIT, 8, XT__3D, XT_OVER, XT_doLIT, 0x7f, XT__3D, XT_OR, XT__3Fbranch, XT_kTAP + 0x36, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x38, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0xbb8: accept */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_accept + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLIT, 0x5f, XT_U_3C, XT__3Fbranch, XT_accept + 0x28, XT_TAP, XT_branch, XT_accept + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_accept + 0x8, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0xbf0: EXPECT */ F_tokenDoList, XT__27EXPECT, XT__40EXECUTE, XT_SPAN, XT__21, XT_DROP, XT_EXIT, 
/* 0xbfe: QUERY */ F_tokenDoList, XT_TIB, XT_doLIT, XT_FORTH, XT__27EXPECT, XT__40EXECUTE, XT__23TIB, XT__21, XT_DROP, XT_doLIT, 0, XT__3EIN, XT__21, XT_EXIT, 
/* 0xc1a: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0xc3e: THROW */ F_tokenDoList, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0xc5a: NULL$ */ F_tokenCreate, 0, 0, 
/* 0xc60: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0xc68: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0xc78: $," */ F_tokenDoList, XT_doLIT, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0xc8c: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0xc96: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0xca0: $INTERPRET */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24INTERPRET + 0x26, XT_C_40, XT_doLIT, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24INTERPRET + 0x30, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0xcd4: .OK */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__40, XT__3D, XT__3Fbranch, XT__2EOK + 0x16, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0xcee: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0xd02: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x16, XT__27EVAL, XT__40EXECUTE, XT__3FSTACK, XT_branch, XT_EVAL + 0x2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0xd20: [ */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__21, XT_EXIT, 
/* 0xd2c: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_TIB0, XT__23TIB, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0xd3e: XIO */ F_tokenDoList, XT_doLIT, XT_accept, XT__27EXPECT, XT__21, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0xd56: FILE */ F_tokenDoList, XT_doLIT, XT_PACE, XT_doLIT, XT_DROP, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0xd68: HAND */ F_tokenDoList, XT_doLIT, XT__2EOK, XT_doLIT, XT_EMIT, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0xd7a: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0xd82: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0xd90: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0xd98: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLIT, XT_CELLMASK, XT_CHARS, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0xdc8: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLIT, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT_CONSOLE, XT_quitError, XT_branch, XT_QUIT + 0x8, XT_EXIT, 
/* 0xde8: quit1 */ F_tokenDoList, XT_doLIT, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0xdfc: ' */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, XT__27 + 0xc, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0xe0c: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0xe14: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0xe2a: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0xe32: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3E, XT__2C, XT_EXIT, 
/* 0xe3e: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0xe48: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0xe64: $,n */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, XT__24_2Cn + 0x30, XT__3FUNIQUE, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0xea0: $COMPILE */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24COMPILE + 0x1e, XT_C_40, XT__3DIMED, XT_AND, XT__3Fbranch, XT__24COMPILE + 0x1a, XT_EXECUTE, XT_branch, XT__24COMPILE + 0x1c, XT__2C, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24COMPILE + 0x2a, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0xece: OVERT */ F_tokenDoList, XT_LAST, XT__40, XT_CURRENT, XT__40, XT__21, XT_EXIT, 
/* 0xedc: ; */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 
/* 0xee8: ] */ F_tokenDoList, XT_doLIT, XT__24COMPILE, XT__27EVAL, XT__21, XT_EXIT, 
/* 0xef4: : */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0xf02: USER */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenUser, XT__2C, XT_EXIT, 
/* 0xf10: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0xf22: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0xf2a: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x14, XT_CREATE, XT_branch, XT_vCREATE + 0x1a, XT_tokenVar, XT_create, XT__2C, XT_EXIT, 
/* 0xf46: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLIT, 0, XT_v_2C, XT_EXIT, 
/* 0xf52: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0xf62: _TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT__5FTYPE + 0x16, XT_DUP, XT_C_40, XT__3ECHAR, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT__5FTYPE + 0x8, XT_DROP, XT_EXIT, 
/* 0xf80: dm+ */ F_tokenDoList, XT_OVER, XT_doLIT, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x22, XT_DUP, XT_C_40, XT_doLIT, 3, XT_U_2ER, XT_doLIT, 1, XT__2B, XT_next, XT_dm_2B + 0x12, XT_EXIT, 
/* 0xfa8: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLIT, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLIT, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLIT, 2, XT_SPACES, XT__5FTYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0xfec: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2004, 0x733c, 0x70, XT_EXIT, 
/* 0x100c: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x101e: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x102a: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x1034: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x104e: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT__3DBYTEMASK, XT_AND, XT__5FTYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x106e: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 0x8, XT_DROP, XT_EXIT, 
/* 0x1090: FORTH>NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_2DUP, XT_NAME_3E, XT_XOR, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_CELL_2D, XT_branch, XT_FORTH_3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x10ce: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLIT, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLIT, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, XT__3DBYTEMASK, XT_DROP, XT_EXIT, 
/* 0x1154: VER */ F_tokenNextVal, 0xa, 
/* 0x1158: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, XT_CELLL, XT_VER, XT__3C_23, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_CR, XT_EXIT, 
/* 0x118c: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x1194: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x11a4: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x11aa: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 0x2, XT_EXIT, 
/* 0x11cc: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x11d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x11f8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1238: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1278: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x12b8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x12d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x12f8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1338: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1378: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x13b8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x13d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x13f8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1438: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1478: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x1498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x14b8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x14d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172, 
/* 0x14f8: */ 0x6572, 0x5361, 0x7661, 0x2801, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x1500 WARM */ XT_WARM, 0x150e, 0x5704, 0x5241, 0x4d,
/* 0x150a COLD */ XT_COLD, 0x1518, 0x4304, 0x4c4f, 0x44,
/* 0x1514 'BOOT */ XT__27BOOT, 0x1522, 0x2705, 0x4f42, 0x544f,
/* 0x151e EMPTY */ XT_EMPTY, 0x152c, 0x4505, 0x504d, 0x5954,
/* 0x1528 hi */ XT_hi, 0x1534, 0x6842, 0x69,
/* 0x1530 version */ XT_version, 0x1540, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0x153c VER */ XT_VER, 0x1548, 0x5603, 0x5245,
/* 0x1544 SEE */ XT_SEE, 0x1550, 0x5303, 0x4545,
/* 0x154c FORTH>NAME */ XT_FORTH_3ENAME, 0x1560, 0x460a, 0x524f, 0x4854, 0x4e3e, 0x4d41, 0x45,
/* 0x155c WORDS */ XT_WORDS, 0x156a, 0x5705, 0x524f, 0x5344,
/* 0x1566 .ID */ XT__2EID, 0x1572, 0x2e03, 0x4449,
/* 0x156e ?CSP */ XT__3FCSP, 0x157c, 0x3f04, 0x5343, XT_FORTH,
/* 0x1578 !CSP */ XT__21CSP, 0x1586, 0x2104, 0x5343, XT_FORTH,
/* 0x1582 .FREE */ XT__2EFREE, 0x1590, 0x2e05, 0x5246, 0x4545,
/* 0x158c .BASE */ XT__2EBASE, 0x159a, 0x2e05, 0x4142, 0x4553,
/* 0x1596 .S */ XT__2ES, 0x15a2, 0x2e02, 0x53,
/* 0x159e DUMP */ XT_DUMP, 0x15ac, 0x4404, 0x4d55, XT_FORTH,
/* 0x15a8 dm+ */ XT_dm_2B, 0x15b4, 0x6403, 0x2b6d,
/* 0x15b0 _TYPE */ XT__5FTYPE, 0x15be, 0x5f05, 0x5954, 0x4550,
/* 0x15ba CONSTANT */ XT_CONSTANT, 0x15cc, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0x15c8 VARIABLE */ XT_VARIABLE, 0x15da, 0x5608, 0x5241, 0x4149, 0x4c42, 0x45,
/* 0x15d6 vCREATE */ XT_vCREATE, 0x15e6, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x15e2 CREATE */ XT_CREATE, 0x15f2, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x15ee create */ XT_create, 0x15fe, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x15fa USER */ XT_USER, 0x1608, 0x5504, 0x4553, 0x52,
/* 0x1604 : */ XT__3A, 0x160e, 0x3a01,
/* 0x160a ] */ XT__5D, 0x1614, 0x5d01,
/* 0x1610 ; */ XT__3B, 0x161a, 0x3bc1,
/* 0x1616 OVERT */ XT_OVERT, 0x1624, 0x4f05, 0x4556, 0x5452,
/* 0x1620 $COMPILE */ XT__24COMPILE, 0x1632, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x162e $,n */ XT__24_2Cn, 0x163a, 0x2403, 0x6e2c,
/* 0x1636 ?UNIQUE */ XT__3FUNIQUE, 0x1646, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0x1642 $" */ XT__24_22, 0x164e, 0x2482, 0x22,
/* 0x164a RECURSE */ XT_RECURSE, 0x165a, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0x1656 [COMPILE] */ XT__5BCOMPILE_5D, 0x1668, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x1664 vALLOT */ XT_vALLOT, 0x1674, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0x1670 ALLOT */ XT_ALLOT, 0x167e, 0x4105, 0x4c4c, 0x544f,
/* 0x167a ' */ XT__27, 0x1684, 0x2701,
/* 0x1680 quit1 */ XT_quit1, 0x168e, 0x7105, 0x6975, 0x3174,
/* 0x168a QUIT */ XT_QUIT, 0x1698, 0x5104, 0x4955, 0x54,
/* 0x1694 quitError */ XT_quitError, 0x16a6, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0x16a2 que */ XT_que, 0x16ae, 0x7103, 0x6575,
/* 0x16aa CONSOLE */ XT_CONSOLE, 0x16ba, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0x16b6 I/O */ XT_I_2FO, 0x16c2, 0x4903, 0x4f2f,
/* 0x16be HAND */ XT_HAND, 0x16cc, 0x4804, 0x4e41, 0x44,
/* 0x16c8 FILE */ XT_FILE, 0x16d6, 0x4604, 0x4c49, 0x45,
/* 0x16d2 XIO */ XT_XIO, 0x16de, 0x5803, 0x4f49,
/* 0x16da PRESET */ XT_PRESET, 0x16ea, 0x5006, 0x4552, 0x4553, 0x54,
/* 0x16e6 [ */ XT__5B, 0x16f0, 0x5b81,
/* 0x16ec EVAL */ XT_EVAL, 0x16fa, 0x4504, 0x4156, 0x4c,
/* 0x16f6 ?STACK */ XT__3FSTACK, 0x1706, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0x1702 .OK */ XT__2EOK, 0x170e, 0x2e03, 0x4b4f,
/* 0x170a $INTERPRET */ XT__24INTERPRET, 0x171e, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x171a ." */ XT__2E_22, 0x1726, 0x2e82, 0x22,
/* 0x1722 ABORT" */ XT_ABORT_22, 0x1732, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0x172e $," */ XT__24_2C_22, 0x173a, 0x2403, 0x222c,
/* 0x1736 abort" */ XT_abort_22, 0x1746, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0x1742 ABORT */ XT_ABORT, 0x1750, 0x4105, 0x4f42, 0x5452,
/* 0x174c NULL$ */ XT_NULL_24, 0x175a, 0x4e05, 0x4c55, 0x244c,
/* 0x1756 THROW */ XT_THROW, 0x1764, 0x5405, 0x5248, 0x574f,
/* 0x1760 CATCH */ XT_CATCH, 0x176e, 0x4305, 0x5441, 0x4843,
/* 0x176a QUERY */ XT_QUERY, 0x1778, 0x5105, 0x4555, 0x5952,
/* 0x1774 EXPECT */ XT_EXPECT, 0x1784, 0x4506, 0x5058, 0x4345, 0x54,
/* 0x1780 accept */ XT_accept, 0x1790, 0x6106, 0x6363, 0x7065, 0x74,
/* 0x178c kTAP */ XT_kTAP, 0x179a, 0x6b04, 0x4154, XT_FORTH,
/* 0x1796 TAP */ XT_TAP, 0x17a2, 0x5403, 0x5041,
/* 0x179e ^H */ XT__5EH, 0x17aa, 0x5e02, 0x48,
/* 0x17a6 NAME? */ XT_NAME_3F, 0x17b4, 0x4e05, 0x4d41, 0x3f45,
/* 0x17b0 FORTHfind */ XT_FORTHfind, 0x17c2, 0x4609, 0x524f, 0x4854, 0x6966, 0x646e,
/* 0x17be SAME? */ XT_SAME_3F, 0x17cc, 0x5305, 0x4d41, 0x3f45,
/* 0x17c8 NAME> */ XT_NAME_3E, 0x17d6, 0x4e05, 0x4d41, 0x3e45,
/* 0x17d2 WORD */ XT_WORD, 0x17e0, 0x5704, 0x524f, 0x44,
/* 0x17dc TOKEN */ XT_TOKEN, 0x17ea, 0x5405, 0x4b4f, 0x4e45,
/* 0x17e6 .( */ XT__2E_28, 0x17f2, 0x2e82, 0x28,
/* 0x17ee CTRL */ XT_CTRL, 0x17fc, 0x4304, 0x5254, 0x4c,
/* 0x17f8 CHAR */ XT_CHAR, 0x1806, 0x4304, 0x4148, 0x52,
/* 0x1802 PARSE */ XT_PARSE, 0x1810, 0x5005, 0x5241, 0x4553,
/* 0x180c parse */ XT_parse, 0x181a, 0x7005, 0x7261, 0x6573,
/* 0x1816 ."| */ XT__2E_22_7C, 0x1822, 0x2e03, 0x7c22,
/* 0x181e $"| */ XT__24_22_7C, 0x182a, 0x2403, 0x7c22,
/* 0x1826 do$ */ XT_do_24, 0x1832, 0x6403, 0x246f,
/* 0x182e CR */ XT_CR, 0x183a, 0x4302, 0x52,
/* 0x1836 PACE */ XT_PACE, 0x1844, 0x5004, 0x4341, 0x45,
/* 0x1840 NUF? */ XT_NUF_3F, 0x184e, 0x4e04, 0x4655, 0x3f,
/* 0x184a KEY */ XT_KEY, 0x1856, 0x4b03, 0x5945,
/* 0x1852 ?KEY */ XT__3FKEY, 0x1860, 0x3f04, 0x454b, 0x59,
/* 0x185c NUMBER? */ XT_NUMBER_3F, 0x186c, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x1868 DIGIT? */ XT_DIGIT_3F, 0x1878, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0x1874 ? */ XT__3F, 0x187e, 0x3f01,
/* 0x187a . */ XT__2E, 0x1884, 0x2e01,
/* 0x1880 U. */ XT_U_2E, 0x188c, 0x5502, 0x2e,
/* 0x1888 U.R */ XT_U_2ER, 0x1894, 0x5503, 0x522e,
/* 0x1890 .R */ XT__2ER, 0x189c, 0x2e02, 0x52,
/* 0x1898 DECIMAL */ XT_DECIMAL, 0x18a8, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0x18a4 HEX */ XT_HEX, 0x18b0, 0x4803, 0x5845,
/* 0x18ac str */ XT_str, 0x18b8, 0x7303, 0x7274,
/* 0x18b4 .$ */ XT__2E_24, 0x18c0, 0x2e02, 0x24,
/* 0x18bc TYPE */ XT_TYPE, 0x18ca, 0x5404, 0x5059, 0x45,
/* 0x18c6 SPACES */ XT_SPACES, 0x18d6, 0x5306, 0x4150, 0x4543, 0x53,
/* 0x18d2 CHARS */ XT_CHARS, 0x18e0, 0x4305, 0x4148, 0x5352,
/* 0x18dc SPACE */ XT_SPACE, 0x18ea, 0x5305, 0x4150, 0x4543,
/* 0x18e6 EMIT */ XT_EMIT, 0x18f4, 0x4504, 0x494d, 0x54,
/* 0x18f0 #> */ XT__23_3E, 0x18fc, 0x2302, 0x3e,
/* 0x18f8 SIGN */ XT_SIGN, 0x1906, 0x5304, 0x4749, 0x4e,
/* 0x1902 #S */ XT__23S, 0x190e, 0x2302, 0x53,
/* 0x190a # */ XT__23, 0x1914, 0x2301,
/* 0x1910 HOLD */ XT_HOLD, 0x191e, 0x4804, 0x4c4f, 0x44,
/* 0x191a <# */ XT__3C_23, 0x1926, 0x3c02, 0x23,
/* 0x1922 EXTRACT */ XT_EXTRACT, 0x1932, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0x192e DIGIT */ XT_DIGIT, 0x193c, 0x4405, 0x4749, 0x5449,
/* 0x1938 PACK$ */ XT_PACK_24, 0x1946, 0x5005, 0x4341, 0x244b,
/* 0x1942 -TRAILING */ XT__2DTRAILING, 0x1954, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0x1950 FILL */ XT_FILL, 0x195e, 0x4604, 0x4c49, 0x4c,
/* 0x195a CMOVE */ XT_CMOVE, 0x1968, 0x4305, 0x4f4d, 0x4556,
/* 0x1964 COUNT */ XT_COUNT, 0x1972, 0x4305, 0x554f, 0x544e,
/* 0x196e @EXECUTE */ XT__40EXECUTE, 0x1980, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0x197c TIB */ XT_TIB, 0x1988, 0x5403, 0x4249,
/* 0x1984 PAD */ XT_PAD, 0x1990, 0x5003, 0x4441,
/* 0x198c vCREATE */ XT_vCREATE, 0x199c, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x1998 v, */ XT_v_2C, 0x19a4, 0x7602, 0x2c,
/* 0x19a0 vHERE */ XT_vHERE, 0x19ae, 0x7605, 0x4548, 0x4552,
/* 0x19aa 2@ */ XT_2_40, 0x19b6, 0x3202, 0x40,
/* 0x19b2 2! */ XT_2_21, 0x19be, 0x3202, 0x21,
/* 0x19ba +! */ XT__2B_21, 0x19c6, 0x2b02, 0x21,
/* 0x19c2 PICK */ XT_PICK, 0x19d0, 0x5004, 0x4349, 0x4b,
/* 0x19cc DEPTH */ XT_DEPTH, 0x19da, 0x4405, 0x5045, 0x4854,
/* 0x19d6 >CHAR */ XT__3ECHAR, 0x19e4, 0x3e05, 0x4843, 0x5241,
/* 0x19e0 CELLS */ XT_CELLS, 0x19ee, 0x4305, 0x4c45, 0x534c,
/* 0x19ea CELL- */ XT_CELL_2D, 0x19f8, 0x4305, 0x4c45, 0x2d4c,
/* 0x19f4 * / */ XT__2A_2F, 0x1a00, 0x2a02, 0x2f,
/* 0x19fc * /MOD */ XT__2A_2FMOD, 0x1a0a, 0x2a05, 0x4d2f, 0x444f,
/* 0x1a06 M* */ XT_M_2A, 0x1a12, 0x4d02, 0x2a,
/* 0x1a0e * */ XT__2A, 0x1a18, 0x2a01,
/* 0x1a14 UM* */ XT_UM_2A, 0x1a20, 0x5503, 0x2a4d,
/* 0x1a1c / */ XT__2F, 0x1a26, 0x2f01,
/* 0x1a22 MOD */ XT_MOD, 0x1a2e, 0x4d03, 0x444f,
/* 0x1a2a /MOD */ XT__2FMOD, 0x1a38, 0x2f04, 0x4f4d, 0x44,
/* 0x1a34 M/MOD */ XT_M_2FMOD, 0x1a42, 0x4d05, 0x4d2f, 0x444f,
/* 0x1a3e UM/MOD */ XT_UM_2FMOD, 0x1a4e, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0x1a4a WITHIN */ XT_WITHIN, 0x1a5a, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0x1a56 MIN */ XT_MIN, 0x1a62, 0x4d03, 0x4e49,
/* 0x1a5e MAX */ XT_MAX, 0x1a6a, 0x4d03, 0x5841,
/* 0x1a66 < */ XT__3C, 0x1a70, 0x3c01,
/* 0x1a6c U< */ XT_U_3C, 0x1a78, 0x5502, 0x3c,
/* 0x1a74 = */ XT__3D, 0x1a7e, 0x3d01,
/* 0x1a7a 0= */ XT_0_3D, 0x1a86, 0x3002, 0x3d,
/* 0x1a82 ABS */ XT_ABS, 0x1a8e, 0x4103, 0x5342,
/* 0x1a8a - */ XT__2D, 0x1a94, 0x2d01,
/* 0x1a90 DNEGATE */ XT_DNEGATE, 0x1aa0, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0x1a9c NEGATE */ XT_NEGATE, 0x1aac, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0x1aa8 INVERT */ XT_INVERT, 0x1ab8, 0x4906, 0x564e, 0x5245, 0x54,
/* 0x1ab4 D+ */ XT_D_2B, 0x1ac0, 0x4402, 0x2b,
/* 0x1abc + */ XT__2B, 0x1ac6, 0x2b01,
/* 0x1ac2 2DUP */ XT_2DUP, 0x1ad0, 0x3204, 0x5544, XT_FORTH,
/* 0x1acc -ROT */ XT__2DROT, 0x1ada, 0x2d04, 0x4f52, 0x54,
/* 0x1ad6 ROT */ XT_ROT, 0x1ae2, 0x5203, 0x544f,
/* 0x1ade ?DUP */ XT__3FDUP, 0x1aec, 0x3f04, 0x5544, XT_FORTH,
/* 0x1ae8 WHILE */ XT_WHILE, 0x1af6, 0x5785, 0x4948, 0x454c,
/* 0x1af2 WHEN */ XT_WHEN, 0x1b00, 0x5784, 0x4548, 0x4e,
/* 0x1afc ELSE */ XT_ELSE, 0x1b0a, 0x4584, 0x534c, 0x45,
/* 0x1b06 AFT */ XT_AFT, 0x1b12, 0x4183, 0x5446,
/* 0x1b0e THEN */ XT_THEN, 0x1b1c, 0x5484, 0x4548, 0x4e,
/* 0x1b18 REPEAT */ XT_REPEAT, 0x1b28, 0x5286, 0x5045, 0x4145, 0x54,
/* 0x1b24 AHEAD */ XT_AHEAD, 0x1b32, 0x4185, 0x4548, 0x4441,
/* 0x1b2e IF */ XT_IF, 0x1b3a, 0x4982, 0x46,
/* 0x1b36 AGAIN */ XT_AGAIN, 0x1b44, 0x4185, 0x4147, 0x4e49,
/* 0x1b40 UNTIL */ XT_UNTIL, 0x1b4e, 0x5585, 0x544e, 0x4c49,
/* 0x1b4a NEXT */ XT_NEXT, 0x1b58, 0x4e84, 0x5845, 0x54,
/* 0x1b54 BEGIN */ XT_BEGIN, 0x1b62, 0x4285, 0x4745, 0x4e49,
/* 0x1b5e FOR */ XT_FOR, 0x1b6a, 0x4683, 0x524f,
/* 0x1b66 >RESOLVE */ XT__3ERESOLVE, 0x1b78, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x1b74 >MARK */ XT__3EMARK, 0x1b82, 0x3e05, 0x414d, 0x4b52,
/* 0x1b7e <RESOLVE */ XT__3CRESOLVE, 0x1b90, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x1b8c <MARK */ XT__3CMARK, 0x1b9a, 0x3c05, 0x414d, 0x4b52,
/* 0x1b96 CREATE */ XT_CREATE, 0x1ba6, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x1ba2 create */ XT_create, 0x1bb2, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x1bae LITERAL */ XT_LITERAL, 0x1bbe, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0x1bba COMPILE */ XT_COMPILE, 0x1bca, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0x1bc6 [COMPILE] */ XT__5BCOMPILE_5D, 0x1bd8, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x1bd4 , */ XT__2C, 0x1bde, 0x2c01,
/* 0x1bda CELL+ */ XT_CELL_2B, 0x1be8, 0x4305, 0x4c45, 0x2b4c,
/* 0x1be4 HERE */ XT_HERE, 0x1bf2, 0x4804, 0x5245, 0x45,
/* 0x1bee NIP */ XT_NIP, 0x1bfa, 0x4e03, 0x5049,
/* 0x1bf6 \T */ XT__5CT, 0x1c02, 0x5c02, 0x54,
/* 0x1bfe \ */ XT__5C, 0x1c08, 0x5c81,
/* 0x1c04 ( */ XT__28, 0x1c0e, 0x2881,
/* 0x1c0a IMMEDIATE */ XT_IMMEDIATE, 0x1c1c, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0x1c18 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x1c2e, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0x1c2a setHeaderBits */ XT_setHeaderBits, 0x1c40, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0x1c3c 2DROP */ XT_2DROP, 0x1c4a, 0x3205, 0x5244, 0x504f,
/* 0x1c46 VP */ XT_VP, 0x1c52, 0x5602, XT_FORTH,
/* 0x1c4e LAST */ XT_LAST, 0x1c5c, 0x4c04, 0x5341, 0x54,
/* 0x1c58 NP */ XT_NP, 0x1c64, 0x4e02, XT_FORTH,
/* 0x1c60 CP */ XT_CP, 0x1c6c, 0x4302, XT_FORTH,
/* 0x1c68 CURRENT */ XT_CURRENT, 0x1c78, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0x1c74 CONTEXT */ XT_CONTEXT, 0x1c84, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0x1c80 HANDLER */ XT_HANDLER, 0x1c90, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0x1c8c HLD */ XT_HLD, 0x1c98, 0x4803, 0x444c,
/* 0x1c94 'NUMBER */ XT__27NUMBER, 0x1ca4, 0x2707, 0x554e, 0x424d, 0x5245,
/* 0x1ca0 'EVAL */ XT__27EVAL, 0x1cae, 0x2705, 0x5645, 0x4c41,
/* 0x1caa CSP */ XT_CSP, 0x1cb6, 0x4303, 0x5053,
/* 0x1cb2 #TIB */ XT__23TIB, 0x1cc0, 0x2304, 0x4954, 0x42,
/* 0x1cbc >IN */ XT__3EIN, 0x1cc8, 0x3e03, 0x4e49,
/* 0x1cc4 SPAN */ XT_SPAN, 0x1cd2, 0x5304, 0x4150, 0x4e,
/* 0x1cce temp */ XT_temp, 0x1cdc, 0x7404, 0x6d65, 0x70,
/* 0x1cd8 BASE */ XT_BASE, 0x1ce6, 0x4204, 0x5341, 0x45,
/* 0x1ce2 'PROMPT */ XT__27PROMPT, 0x1cf2, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0x1cee 'ECHO */ XT__27ECHO, 0x1cfc, 0x2705, 0x4345, 0x4f48,
/* 0x1cf8 'TAP */ XT__27TAP, 0x1d06, 0x2704, 0x4154, XT_FORTH,
/* 0x1d02 'EXPECT */ XT__27EXPECT, 0x1d12, 0x2707, 0x5845, 0x4550, 0x5443,
/* 0x1d0e 'EMIT */ XT__27EMIT, 0x1d1c, 0x2705, 0x4d45, 0x5449,
/* 0x1d18 '?KEY */ XT__27_3FKEY, 0x1d26, 0x2705, 0x4b3f, 0x5945,
/* 0x1d22 RP0 */ XT_RP0, 0x1d2e, 0x5203, 0x3050,
/* 0x1d2a SP0 */ XT_SP0, 0x1d36, 0x5303, 0x3050,
/* 0x1d32 TEST */ XT_TEST, 0x1d40, 0x5404, 0x5345, 0x54,
/* 0x1d3c debugPrintTIB */ XT_debugPrintTIB, 0x1d52, 0x640d, 0x6265, 0x6775, 0x7250, 0x6e69, 0x5474, 0x4249,
/* 0x1d4e break */ XT_break, 0x1d5c, 0x6205, 0x6572, 0x6b61,
/* 0x1d58 testing3 */ XT_testing3, 0x1d6a, 0x7408, 0x7365, 0x6974, 0x676e, 0x33,
/* 0x1d66 debugNA */ XT_debugNA, 0x1d76, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0x1d72 ' */ XT__27, 0x1d7c, 0x2701,
/* 0x1d78 ; */ XT__3B, 0x1d82, 0x3b81,
/* 0x1d7e : */ XT__3A, 0x1d88, 0x3a01,
/* 0x1d84 ] */ XT__5D, 0x1d8e, 0x5d01,
/* 0x1d8a [ */ XT__5B, 0x1d94, 0x5b81,
/* 0x1d90 $INTERPRET */ XT__24INTERPRET, 0x1da4, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x1da0 $COMPILE */ XT__24COMPILE, 0x1db2, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x1dae NUMBER? */ XT_NUMBER_3F, 0x1dbe, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x1dba TOKEN */ XT_TOKEN, 0x1dc8, 0x5405, 0x4b4f, 0x4e45,
/* 0x1dc4 PARSE */ XT_PARSE, 0x1dd2, 0x5005, 0x5241, 0x4553,
/* 0x1dce userAreaSave */ XT_userAreaSave, 0x1de4, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0x1de0 userAreaInit */ XT_userAreaInit, 0x1df6, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0x1df2 UM+ */ XT_UM_2B, 0x1dfe, 0x5503, 0x2b4d,
/* 0x1dfa XOR */ XT_XOR, 0x1e06, 0x5803, 0x524f,
/* 0x1e02 OR */ XT_OR, 0x1e0e, 0x4f02, 0x52,
/* 0x1e0a AND */ XT_AND, 0x1e16, 0x4103, 0x444e,
/* 0x1e12 0< */ XT_0_3C, 0x1e1e, 0x3002, 0x3c,
/* 0x1e1a OVER */ XT_OVER, 0x1e28, 0x4f04, 0x4556, 0x52,
/* 0x1e24 SWAP */ XT_SWAP, 0x1e32, 0x5304, 0x4157, XT_FORTH,
/* 0x1e2e DUP */ XT_DUP, 0x1e3a, 0x4403, 0x5055,
/* 0x1e36 DROP */ XT_DROP, 0x1e44, 0x4404, 0x4f52, XT_FORTH,
/* 0x1e40 SP! */ XT_SP_21, 0x1e4c, 0x5303, 0x2150,
/* 0x1e48 SP@ */ XT_SP_40, 0x1e54, 0x5303, 0x4050,
/* 0x1e50 >R */ XT__3ER, 0x1e5c, 0x3e02, 0x52,
/* 0x1e58 R@ */ XT_R_40, 0x1e64, 0x5202, 0x40,
/* 0x1e60 R> */ XT_R_3E, 0x1e6c, 0x5202, 0x3e,
/* 0x1e68 RP! */ XT_RP_21, 0x1e74, 0x5203, 0x2150,
/* 0x1e70 RP@ */ XT_RP_40, 0x1e7c, 0x5203, 0x4050,
/* 0x1e78 C! */ XT_C_21, 0x1e84, 0x4302, 0x21,
/* 0x1e80 C@ */ XT_C_40, 0x1e8c, 0x4302, 0x40,
/* 0x1e88 @ */ XT__40, 0x1e92, 0x4001,
/* 0x1e8e ! */ XT__21, 0x1e98, 0x2101,
/* 0x1e94 branch */ XT_branch, 0x1ea4, 0x6206, 0x6172, 0x636e, 0x68,
/* 0x1ea0 ?branch */ XT__3Fbranch, 0x1eb0, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0x1eac next */ XT_next, 0x1eba, 0x6e04, 0x7865, 0x74,
/* 0x1eb6 DOES> */ XT_DOES_3E, 0x1ec4, 0x4405, 0x454f, 0x3e53,
/* 0x1ec0 doLIT */ XT_doLIT, 0x1ece, 0x6405, 0x4c6f, 0x5449,
/* 0x1eca !IO */ XT__21IO, 0x1ed6, 0x2103, 0x4f49,
/* 0x1ed2 TX! */ XT_TX_21, 0x1ede, 0x5403, 0x2158,
/* 0x1eda ?RX */ XT__3FRX, 0x1ee6, 0x3f03, 0x5852,
/* 0x1ee2 EXECUTE */ XT_EXECUTE, 0x1ef2, 0x4507, 0x4558, 0x5543, 0x4554,
/* 0x1eee EXIT */ XT_EXIT, 0x1efc, 0x4504, 0x4958, 0x54,
/* 0x1ef8 BYE */ XT_BYE, 0x1f04, 0x4203, 0x4559,
/* 0x1f00 MS */ XT_MS, 0x1f0c, 0x4d02, 0x53,
/* 0x1f08 >NAME */ XT__3ENAME, 0x1f16, 0x3e05, 0x414e, 0x454d,
/* 0x1f12 $,n */ XT__24_2Cn, 0x1f1e, 0x2403, 0x6e2c,
/* 0x1f1a OVERT */ XT_OVERT, 0x1f28, 0x4f05, 0x4556, 0x5452,
/* 0x1f24 find */ XT_find, 0x1f32, 0x6604, 0x6e69, 0x64,
/* 0x1f2e ALIGNED */ XT_ALIGNED, 0x1f3e, 0x4107, 0x494c, 0x4e47, 0x4445,
/* 0x1f3a tokenCreate */ XT_tokenCreate, 0x1f4e, 0x740b, 0x6b6f, 0x6e65, 0x7243, 0x6165, 0x6574,
/* 0x1f4a tokenVar */ XT_tokenVar, 0x1f5c, 0x7408, 0x6b6f, 0x6e65, 0x6156, XT_BL,
/* 0x1f58 tokenUser */ XT_tokenUser, 0x1f6a, 0x7409, 0x6b6f, 0x6e65, 0x7355, 0x7265,
/* 0x1f66 tokenDoList */ XT_tokenDoList, 0x1f7a, 0x740b, 0x6b6f, 0x6e65, 0x6f44, 0x694c, 0x7473,
/* 0x1f76 tokenNextVal */ XT_tokenNextVal, 0x1f8c, 0x740c, 0x6b6f, 0x6e65, 0x654e, 0x7478, 0x6156, 0x6c,
/* 0x1f88 tokenVocabulary */ XT_tokenVocabulary, 0x1fa0, 0x740f, 0x6b6f, 0x6e65, 0x6f56, 0x6163, 0x7562, 0x616c, 0x7972,
/* 0x1f9c BL */ XT_BL, 0x1fa8, 0x4202, 0x4c,
/* 0x1fa4 =BYTEMASK */ XT__3DBYTEMASK, 0x1fb6, 0x3d09, 0x5942, 0x4554, 0x414d, 0x4b53,
/* 0x1fb2 =IMED */ XT__3DIMED, 0x1fc0, 0x3d05, 0x4d49, 0x4445,
/* 0x1fbc =COMP */ XT__3DCOMP, 0x1fca, 0x3d05, 0x4f43, 0x504d,
/* 0x1fc6 TIB0 */ XT_TIB0, 0x1fd4, 0x5404, 0x4249, 0x30,
/* 0x1fd0 CELLMASK */ XT_CELLMASK, 0x1fe2, 0x4308, 0x4c45, 0x4d4c, 0x5341, 0x4b,
/* 0x1fde CELLbits */ XT_CELLbits, 0x1ff0, 0x4308, 0x4c45, 0x624c, 0x7469, 0x73,
/* 0x1fec CELLL */ XT_CELLL, 0x1ffa, 0x4305, 0x4c45, 0x4c4c,
/* 0x1ff6 FORTH */ XT_FORTH, 0, 0x4605, 0x524f, 0x4854
// === End of Arduino source from dictionary === 
};


#endif
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); // Initialize IO port TODO move to somewhere Forth wants it
  Serial.println(F("Starting"));
  // TODO: Serial.println('Space for', NAMEE - CODEE, 'bytes for code and names');
  (*f[0])(0); // TEST function pointer 
  //L.1864
  Ustore(CPoffset, CODEE);
  Ustore(NPoffset, NAMEE); // Pointer to where writing name stack
  Ustore(RP0offset, RP0);
  // builddictionary()
  //TODO------------> working from here  from start of builddictionary
}

void loop() {
  // put your main code here, to run repeatedly:

}
