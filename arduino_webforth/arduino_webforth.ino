/*
 * Status and next steps
 * Rework SP to use ramSP
 * move to git
 * Rework RAM to go up, not down from 0x8000 
 * Rework mem access to use a mask of mem rather than (a - RAM0)
 * Rework tokenvar from EPROM branch - check branch for other changes - then merge back ramSP etc as nenSP
 * Build mem access functions to test top bit 
 * Builddictionary() -> Arduino
 * cross comp 
 * Backport - use of ramSP ramRP
 * 
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
#define ROMSIZE 0x2000 * CELLL
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
#define romUZERO 0
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
const CELLTYPE rom[ROMCELLS] PROGMEM = { 1, 2, 3 }; 
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
