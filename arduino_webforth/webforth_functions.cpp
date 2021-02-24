#include "webforth_functions.h"

// Forward definitions
extern void debugStack();
extern void debugNA();
extern void debugPrintTIB();
extern void printCounted(CELLTYPE a);

/*
 * NOTES
 * See https://www.arduino.cc/reference/en/language/variables/utilities/progmem/ for reading program memory (where dictionary will be)
 * Board: Arduino Uno:
 * Board: Wemos D1 R2 & Mini; Upload: 921600; CPU 80MHz; Flash 4M/3M SPIFFS; cu.usbserial-1420
 */


//TODO-ARDUINO OPTIMIZATION - check for constant parameters to functions nad mark constant in definition

//#define WRITEROM 1 // Define if want to write to "rom" area

// ==== In order, there is a gap (missing code) before each Line marker ====
//L.115
#define COMP 0x40 // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
#define IMED 0x80 // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
#define bitsSPARE 0x20 // Unused spare bit in names
#define BYTEMASK 0xFF - COMP - IMED - bitsSPARE // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
// Using const for TRUE as we care about its size
const CELLTYPE TRUE = -1;
const CELLTYPE FALSE = 0;
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
#define STATEoffset 19
#define NUMBERoffset 20
#define CONTEXToffset 23
#define CURRENToffset 32
#define CPoffset 34
#define NPoffset 35
#define LASToffset 36
#define VPoffset 37
#define SOURCEIDoffset 38
#define _USER 39

//L.1823
#define CELLbits CELLL * 8 // Number of bits in a cell - used for loops and shifts
// mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
// Note - this will fail if master that dumped dictionary above is the opposite Endian. (Currently only Flash8_xx is little-endian; and Arduino is using Flash16_16).
#ifdef LITTLEENDIAN
const CELLTYPE CELLMASK = TRUE ^ (0xFF ^ BYTEMASK);
#else
const CELLTYPE CELLMASK = TRUE ^ ((0xFF ^ BYTEMASK) << (CELLbits - 8));
#endif

//L.1831
static uint8_t testing = 0;

//L.1840
// === Memory layout
// Memory may be aligned to a boundary depending on underlying mem store (which may or may not match CELLL), this assumption should be confined to ALIGNED
// Now the memory map itself, starting at the top of memory.

#define RAMADDR(x) (x >> CELLSHIFT)
#define ROMADDR(x) ((x ^ ROM0) >> CELLSHIFT)
#define FROMRAMADDR(x) CELLTYPE(x << CELLSHIFT)
#define FROMROMADDR(x) (CELLTYPE(x << CELLSHIFT) | ROM0)
#if CELLL == 4
#define ROM(cellAddr) pgm_read_dword_near(&rom[cellAddr])
#else // Assume 2
#define ROM(cellAddr) pgm_read_word_near(&rom[cellAddr])
#endif

// Now some cell based pointers into RAM
#define ramSPP RAMADDR(SPP) // start of data stack - grows down, points at top of stack - 8 word buffer for safety
#define ramRP0 RAMADDR(RP0)
#define ramUP0 RAMADDR(UPP)

//L.1852
static CELLTYPE ram[RAMCELLS]; // Equivalent of Flash16_16 in webForth
//L.1853 - jsFunctions[] is now fp[] and has to be after definition of functions in it.

// Key pointers used - would ideally be registers in a register based system
CELLTYPE IP = 0;    // Interpreter Pointer (this is a byte pointer - cannot use CellPointer as could be into Rom or Ram)
CELLTYPE PAYLOAD = 0;    // XT pointer - its either put this here OR make every function take a XT parameter - unlike JS C wont allow un-passed parameters
CELLTYPE ramSP = ramSPP;  // Data Stack Pointer (cant call SP as that is reserved) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
CELLTYPE ramRP = ramRP0;  // Return Stack Pointer (aka BP in 8086) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
CELLTYPE ramUP = ramUP0;  // User Area Pointer // TODO-28-MULTI will move this around

//L.2023
// Put testing3 in a definition to start outputing stack trace on console.
void testing3() { testing |= 3; };

// Put break in a definition.
void Fbreak() {
  debugStack();
  //Serial.println(F("\nbreak in a FORTH word"));
} // Put a breakpoint in your IDE at this line



// TODO if only used here then might merge into Mfetch and Mstore
#ifdef WRITEROM
#define ROM(cellAddr) rom[cellAddr]
#endif
CELLTYPE cellRomFetch(const CELLTYPE cellAddr) {
  if (cellAddr >= ROMCELLS) { Serial.print(F("Attempt to read above top of Rom at ")); Serial.println(cellAddr); debugStack(); delay(10000); } // TODO-OPTIMIZE comment out

  return ROM(cellAddr);
  };
CELLTYPE cellRamFetch(const CELLTYPE cellAddr) {
  if (cellAddr >= RAMCELLS) { Serial.print(F("Attempt to read above top of Ram at ")); Serial.println(cellAddr); debugStack(); delay(10000); } // TODO-OPTIMIZE comment out
  return ram[cellAddr]; };
void cellRamStore(const CELLTYPE cellAddr, const CELLTYPE v) {
  if (cellAddr >= RAMCELLS) { Serial.print(F("Attempt to write above top of Ram at ")); Serial.println(cellAddr); debugStack(); delay(10000); } // TODO-OPTIMIZE comment out
  ram[cellAddr] = v; };
#ifdef WRITEROM
void cellRomStore(cont CELLTYPE cellAddr, constCELLTYPE v) { rom[cellAddr] = v; };
#endif
CELLTYPE Mfetch(const CELLTYPE byteAddr) { return (byteAddr >= ROM0) ? cellRomFetch(ROMADDR(byteAddr)) : cellRamFetch(RAMADDR(byteAddr)) ; }
#ifdef WRITEROM
void Mstore(const CELLTYPE byteAddr, const CELLTYPE v) {  if (byteAddr >= ROM0) { cellRomStore(ROMADDR(byteAddr), v) } else { cellRamStore(RAMADDR(byteAddr), v) } }
#else
void Mstore(const CELLTYPE byteAddr, const CELLTYPE v) {
  if (byteAddr >= ROM0) { Serial.print(F("Attempt to write to Rom at ")); Serial.print(byteAddr); Serial.print(F(" v=")); Serial.println(v); debugStack(); delay(10000); } // TODO-OPTIMIZE comment out
  cellRamStore(RAMADDR(byteAddr), v); }
#endif
// 8 bit equivalents
uint8_t Mfetch8(const CELLTYPE byteAddr) {
  const uint8_t offset = byteAddr & CELLOFFSETMASK;
#ifdef LITTLEENDIAN
  const uint8_t shiftbits = offset << 3;
#else
  const uint8_t shiftbits = (CELLOFFSETMASK - offset) << 3;
#endif
  const CELLTYPE cell = Mfetch(byteAddr); // Does not have to be aligned
  return (cell >> shiftbits) & 0xff; // Can prob remove '&0xff'
}; // Returns byte at a

void Mstore8(const CELLTYPE byteAddr, uint8_t v) {
  //Serial.print("Mstore8 a="); Serial.print(byteAddr); Serial.print(" v="); Serial.println(v);
    const uint8_t offset = byteAddr & CELLOFFSETMASK;
#ifdef LITTLEENDIAN
    const uint8_t shiftbits = 8 * offset ;
#else
    const uint8_t shiftbits = 8 * (CELLOFFSETMASK - offset);
#endif
    const CELLTYPE cell = Mfetch(byteAddr);
    Mstore(byteAddr, (cell & (-1 ^ (0xFF << shiftbits))) | (v << shiftbits));
}

// TODO-MEM this is really dependent on MEM not CELLL
CELLTYPE align(const CELLTYPE byteAddr) { return (((byteAddr - 1) >> CELLSHIFT) + 1) << CELLSHIFT; }
// Only used in token - which is bytes and never aligned
void copyWithin(CELLTYPE byteDestn, CELLTYPE byteSource, const CELLTYPE byteEnd) {
  while(byteSource < byteEnd) {
    Mstore8(byteDestn++, Mfetch8(byteSource++));
  }
}

CELLTYPE SPfetch() { return ram[ramSP]; }
CELLTYPE SPpop() { return ram[ramSP++]; }
void SPpush(const CELLTYPE v) { ram[--ramSP] = v; }
CELLTYPE RPfetch() { return ram[ramRP]; }
CELLTYPE RPpop() { return ram[ramRP++]; }
void RPpush(const CELLTYPE v) { ram[--ramRP] = v; }
CELLTYPE IPnext() {
  const CELLTYPE v = Mfetch(IP);
  IP += CELLL;
  return v; }
CELLTYPE Ufetch(const uint8_t userindex) { return ram[ramUP + userindex]; } // userindex is a cell index, not a byte index
void Ustore(const uint8_t userindex, const CELLTYPE w) { ram[ramUP + userindex] = w; } // userindex is a cell index not a byte index
// === Access to the USER variables before they are defined
CELLTYPE currentFetch() { return Ufetch(CURRENToffset); }
CELLTYPE cpFetch() { return Ufetch(CPoffset); }
CELLTYPE vpFetch() { return Ufetch(VPoffset) || Ufetch(CPoffset); }
CELLTYPE cpAlign() { Ustore(CPoffset, align(cpFetch())); }
CELLTYPE vpAlign() { Ustore(VPoffset, align(vpFetch())); }
CELLTYPE npFetch() { return Ufetch(NPoffset); }
CELLTYPE lastFetch() { return Ufetch(LASToffset); }
CELLTYPE padPtr() { return vpFetch() + 80; } // Sometimes JS needs the pad pointer
void ALIGNED() { SPpush(align(SPpop())); }

// === Functions related to building 'find'  and its wrappers ====


//L.2096-
// Convert a name address to the code dictionary definition.
CELLTYPE na2xt(const CELLTYPE na) {
    return Mfetch(na - uint8_t(2 << CELLSHIFT));
}

// Inner function of find, traverses a linked list Name dictionary.
// name   javascript string looking for
// va     pointer holding address of first element in the list.
// cell1  if present, gives it a quick first-cell test to apply.
// xt     if present we are looking for name pointing at this executable (for decompiler)
// returns 0 or na
bool _sameq(const CELLTYPE na1, const CELLTYPE na2, const uint8_t cells) {
  // Note this is similar to SAME? except via parameters and return rather than stack
  for (uint8_t i = 0; i < cells; i++) {
      if ( Mfetch(na1 + (i<<CELLSHIFT)) != Mfetch(na2 + (i<<CELLSHIFT))) {
        return false;
      }
    }
    return true;
}
CELLTYPE _find(const CELLTYPE va, const CELLTYPE na) { // return na that matches or 0
  //Serial.print(F("XXX _find looking for:")); printCounted(na);
  const uint8_t cellCount = (Mfetch8(na) & BYTEMASK)  >> CELLSHIFT; // Count of cells after first one (formula is not as obvious as you think)
  const CELLTYPE cell1 = Mfetch(na);  // Could be little or big-endian
  CELLTYPE p = va;
  while (p = Mfetch(p)) {
    //Serial.print(F(" - ")); printCounted(p);
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
void jsFind() { // a va -- ca na | a 0
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
CELLTYPE _toName(const CELLTYPE xt) {
  CELLTYPE p = currentFetch(); // vocabulary
  if (!Mfetch(p)) { p = lastFetch() - CELLL; } // Note this is not quite correct, it will miss the first definition (WARM)
  //Serial.print("_toName: p="); Serial.println(p);
  while (p = Mfetch(p)) {
    //Serial.print("_toName comparing"); Serial.print(na2xt(p)),Serial.print(" "); Serial.println(xt);
    if (na2xt(p) == xt) {
      //Serial.println("_toName: Got it");
      return p;
    }
    p -= CELLL; // point at link address and loop for next word
  }
  //Serial.println("_toName: Drop through");
  // Drop through not found
  return 0;
}

//L.2180-
void toNAME() { SPpush(_toName(SPpop())); }  // Fast version of >NAME see Forth definition below

// TODO-29-VOCABULARY This just looks up a in the Context vocabulary, it makes no attempt to use multiple vocabularies
// If required then fixing this to iterate over the context array should not break anything (this is what NAME? does)
void findName() { // a -- xt na | a F
  SPpush(Ufetch(CONTEXToffset));  // a va
  jsFind();                           // xt na | a F
}

//L.2214-
// === JS Functions to be able to define words ==== in Zen pg30 these are Macros.

// Compile one or more words into the next consecutive code cells.
void DW(const CELLTYPE word) {
  CELLTYPE cp = cpFetch();
  Mstore(cp, word);
  cp += CELLL;
  Ustore(CPoffset, cp);
}

//L.2278-
void tokenVocabulary() {
  Ustore(CONTEXToffset, Mfetch(PAYLOAD));
};
// Put the contents of the payload (1 word) onto Stack, used for CONSTANT
void tokenNextVal() {
  SPpush(Mfetch(PAYLOAD));

};

// This is the most important token function - used for a Colon word to iterate over the list.
void tokenDoList() {
  if (testing) {
      Serial.println(F(":"));
  }
  RPpush(IP);
  IP = PAYLOAD; // Point at first word in the definition
}
// Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
void tokenUser() {
  //Serial.print("tokenUser payload="); Serial.print(PAYLOAD); Serial.print(" @payload="); Serial.print(Mfetch(PAYLOAD));
  SPpush(FROMRAMADDR((Mfetch(PAYLOAD) + ramUP)));
  //Serial.print(" result="); Serial.print(SPfetch()); Serial.print(" @="); Serial.println(Mfetch(SPfetch()));
}
// Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
void _tokenDoes() {
  const CELLTYPE does = Mfetch(PAYLOAD);
  if (does) {
    //debugPush();
    RPpush(IP);
    IP = does;
  }
}

// Put next address on the stack  -- byteAddr
void tokenCreate() {
  SPpush(PAYLOAD+CELLL);
  _tokenDoes();
}

void tokenVar() {
  SPpush(Mfetch(PAYLOAD+CELLL));
  _tokenDoes();
}

// === INNER INTERPRETER YES THIS IS IT ! ==================== eForthAndZen#36
// This is quite different from eForth as its token-threaded rather than direct threaded

void debugThreadToken(const CELLTYPE tok) {
  const CELLTYPE xt = PAYLOAD-CELLL;
  Serial.print(IP-CELLL); Serial.print(F(":"));
  //if (CELLTYPE p = _toName(xt)) {
  //  printCounted(p);
  //} else {
    Serial.print(xt);
  //}
  Serial.print(F(":")); Serial.print(tok); Serial.print(F("  "));
}

void threadtoken(const CELLTYPE xt) {
  // console.assert(xt >= CODEE && xt < NAMEE); // Uncomment to catch bizarre xt values earlier
  // This next section is only done while testing, and outputs a trace, so set it on (with testing3) immediately before a likely error.
  //debugThread(xt);
  //Serial.print("Threading token at XT="); Serial.println(xt); delay(1000);
  const CELLTYPE tok = Mfetch(xt);
  //Serial.print("XXX tok="); Serial.println(tok); delay(1000);
  PAYLOAD = xt + CELLL;
  // console.assert(tok < jsFunctions.length); // commented out for efficiency, a fail will just break in the next line anyway.
  if ((tok < FUNCTIONSLENGTH) && f[tok]) {
    if (testing) { debugThreadToken(tok); }
    f[tok](); // Run the token function - like tokenDoList or tokenVar - doesnt return - (JS returns null or a Promise)
  } else {
    Serial.print(F("Bad token:")); debugThreadToken(tok); delay(10000);
  }
}

// This is not re-entrant, normally its threadtoken you want ....
// In particular you cannot use this to nest forth in code in forth
// If that becomes necessary, it MIGHT work to save IP (where?) and restore after while loop
// Cant use R or S for it as words use that across calls to the 'EVAL
/* ARDUINO REPLACED BY LOOP
void runXT(CELLTYPE xt) {
  //let waitFrequency = 0;
  //console.assert(this.IP === 0); // Cant nest run()
  threadtoken(xt);
  // If this returns without changing program Counter, it will exit
  while (IP) {
    // console.assert(this.IP >= CODEE && this.IP <= NAMEE); // uncomment if tracking down jumping into odd places
    xt = IPnext();
    // Comment this out except when needed for debugging, they are slow
    // debugTIB =  this.m.decodeString(Ufetch(TIBoffset) + Ufetch(INoffset), Ufetch(TIBoffset) + Ufetch(nTIBoffset));
    // 'await this.threadtoken(xt)' would be legit, but creates a stack frame in critical inner loop, when usually not reqd.
    threadtoken(xt);
  }
}
*/

void MS() { delay(SPpop()); } // ms --; delay for a period of time.
void BYE() {  IP = 0; } // Should exit all the way out

// Unwind the effect of tokenDoList restoring IP to the next definition out.
void EXIT() {
  if (testing) Serial.println(F(";"));
  IP = RPpop(); }

// EXECUTE runs the word on the stack,
// and because there is nothing after the return from threadtoken which would get executed out of order
// Note that it has a return which could be a promise, which the 'run' will await on.
// This pattern may or may not work in other situations.
//TODO ARDUINO try and figure out how to do this in the loop() then move threadtoken into the loop
void EXECUTE() { threadtoken(SPpop()); }

// === Basic low level key I/O and links to OS - Zen pg 35
// This section will need editing for other systems.
/*
 * Input call chain is
 * ?RX  read one char if present
 * ?KEY via '?KEY to ?RX
 * KEY loop till ?KEY
 * ACCEPT read a line via KEY, processing control chars via 'TAP  to kTAP
 * REFILL reads a line, where depends on SOURCE-ID/SOURCE
 * QUERY read a line via ACCEPT into TIB and reset >IN
 * que read an evaluate a line
 * QUIT loop over que, handling errors
 *
 * See https://github.com/mitra42/webForth/issues/17 for strategy for async version
 */

// Call chain is ?RX < '?KEY  < ?KEY < KEY < ACCEPT < 'EXPECT < QUERY < que < QUIT
// -- char T | F
void QRX() { // ?RX
   if (Serial.available() > 0) {
    SPpush(Serial.read());
    SPpush(TRUE);
  } else {
    SPpush(0);
  }
}
// Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.

void TXbang() {
  Serial.write(SPpop());
} // TX!
void bangIO() {
//Serial.begin(57600); // DONE IN SETUP
} // !IO: Initialize IO port
void TXbangS(CELLTYPE byteaddr, const uint8_t len) {
  for (uint8_t i=len; i > 0; i--) {
  Serial.write(Mfetch8(byteaddr++));
  }
 }
// Convert a string made up of a count and that many bytes to a Javascript string.
// it assumes a maximum of nameMaxLength (31) characters.
// Mostly used for debugging but also in number conversion.
void printCounted(CELLTYPE a) { const char c = Mfetch8(a++) & BYTEMASK; TXbangS(a, c); }  // TODO-backport maybe use this in TYPE
void TYPE() { const char c = SPpop(); const CELLTYPE a = SPpop(); TXbangS(a, c); }

// === Literals and Branches - using next value in dictionary === eForthAndZen#37

// push the value in the next code word
// The XT of this is stored in doLIT
void doLIT() { SPpush(IPnext()); }

// See DOES> and CREATE, this patches the field after the token compiled by the create to point to the code following the DOES>
// : DOES> R> LAST @ 2 CELLS - @ CELLL + ! ; // Untested Forth version, note side effect of the R> of doing an exit.
void DOES() {
  Mstore(
    Mfetch(Ufetch(LASToffset) - uint8_t(2 << CELLSHIFT) ) + CELLL, // field after tokenVar compile by CREATE
    IP // The address after the doDOES
  );
  EXIT(); // Exit the CREATE part
}

// Address Literals (aka branches and jumps) eForthAndZen#38

// decrement count on Return stack, and branch if not decremented past zero (FOR..NEXT)
// noinspection JSUnusedGlobalSymbols
void next() {
  SIGNEDCELLTYPE x = RPpop();
  const CELLTYPE destn = IPnext(); // Increments over it
  if (--x >= 0) {
    RPpush(x);
    IP = destn; // Jump back
  }
}

// Jump if flag on stack is zero to destn in dictionary
void qBranch() {
  const CELLTYPE destn = IPnext();
  if (!SPpop()) {
    IP = destn;
  }
}

// Unconditional jump to destn in dictionary
void branch() { IP = IPnext(); }

// Memory access eForthAndZen#39
void store() { const CELLTYPE a = SPpop(); const CELLTYPE v = SPpop(); Mstore(a, v); } //!  w a -- , Store
void fetch() { SPpush(Mfetch(SPpop())); } //@ a -- w, fetch
void cStore() { const CELLTYPE a = SPpop(); const uint8_t v = SPpop(); Mstore8(a, v); } //C! c a -- , Store character
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
void less0() { SPpush((SPpop() & (1 << (CELLbits - 1))) ? TRUE : FALSE); } //0<  e.g. 0x8000 for CELLL=2
void AND() { SPpush(SPpop() & SPpop()); }
void OR() { SPpush(SPpop() | SPpop()); }
void XOR() { SPpush(SPpop() ^ SPpop()); }

  // Primitive Arithmetic Word eForthAndZen44
void UMplus() { /* UM+ */
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
    const DOUBLECELLTYPE x = (DOUBLECELLTYPE)a + (DOUBLECELLTYPE)b;
    //Serial.print(F("UMplus: a=")); Serial.print(a); Serial.print(F(" b=")); Serial.print(b); Serial.print(F(" x=")); Serial.print(x); Serial.print(F(" x>>=")); Serial.println(x >> CELLbits);
    SPpush(x); // This should only push the bottom cell.
    SPpush(x >> CELLbits);
  //}
}
  // === Define and initialize User variables Zen pg33 see Zen pg46
  // See Zen pg31 for tokenUser etc and $USER and Zen pg33 for USER initialization values

  // TODO-28-MULTITASK will need to think carefully about how to move all, or part of the USER space to task-specific space.
  // TODO-28-MULTITASK this is non-trivial since somethings are clearly across all tasks (e.g. CP and NP)
void userAreaInit() {
  for (uint8_t a = 0; a < _USER; a++) {
    Ustore(a, cellRomFetch(a)); // Actually `UZERO/CELLL + a` but UZERO==ROM0 (checked in xc)
  }
  //testing3();
}

void userAreaSave() {
  #ifdef WRITEROM
    for (uint8_t a = 0; a < _USER; a++) {
      cellRomStore(a, Ufetch(a)); // Actually `UZERO/CELLL + a` but UZERO==ROM0 (checked in xc)
    }
  #else
    //TODO-ARDUINO - how to use Serial
    //Serial.println(F("Cannot write to Rom area"));
  #endif
}

void debugStack() {  // TODO - can comment out and remove from Fbreak when .S working, useful for debugging early
  Serial.print(F(" S:"));
  for (CELLTYPE i = ramSP; i < ramSPP; i++) {
    Serial.print(cellRamFetch(i));
    Serial.print(F(" "));
  }
  Serial.print(F(" R:"));
  for (CELLTYPE i = ramRP; i < ramRP0; i++) {
    Serial.print(cellRamFetch(i));
    Serial.print(F(" "));
  }
  Serial.print(F(" IP-:"));
  Serial.print(IP-CELLL);
  Serial.print(F(" XT:"));
  Serial.print(PAYLOAD-CELLL);
  Serial.println();
}
void debugNA() { Serial.print(F("NAME=")); printCounted(SPfetch()); } // Print the NA on console

// debugPrintTIB will print the current TIB.
void debugPrintTIB() {
  Serial.print(F("TIB: ")); TXbangS(Ufetch(TIBoffset) + Ufetch(INoffset), Ufetch(nTIBoffset) - Ufetch(INoffset));
}
// TEST will (destructively) check the stack matches expected result, used for testing the compiler.
// e.g. this.interpret(`10 DUP 10 10 2 TEST`); // Confirm stack finishes with 2 items (10 10)
void TEST() { //  a1 a2 a3 b1 b2 b3 n -- ; Check n parameters on stack
  const uint8_t stackDepth = SPpop();
  if ((ramSPP - ramSP) != uint8_t(stackDepth << 1)) {
    Serial.println(F("Stack depth wrong"));
  } else {
    for (uint8_t i = 0; i < stackDepth; i++) {
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

// ==== FORTH Interpreter - words that have no Forth equivalent ====

