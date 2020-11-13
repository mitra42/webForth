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
 */

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
// #define WRITEROM 1 // Define if want to write to "rom" area

//L.1794
#define EM 0x2000 * CELLL

#define LITTLEENDIAN true // Arduino is little endian


// ==== In order, there is a gap (mLissing code) before each Line marker ==== 
//L.112
#define COMP 0x40 // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
#define IMED 0x80 // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
#define bitsSPARE 0x20 // Unused spare bit in names
#define BYTEMASK 0xFF - COMP - IMED - bitsSPARE // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
// Using const for forthtrue as we care about its size
const CELLTYPE forthTrue = -1; // Not quite correct, should be masked BUT when pushed that it is done underneath
#define nameMaxLength 31
#define BL 32

//L.125-
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

//L.17
//L.1778
#define CELLbits CELLL * 8 // Number of bits in a cell - used for loops and shifts
// mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
// TODO-CELLL assumes CELLL = 2
const CELLTYPE CELLMASK = forthTrue ^ ((0xFF ^ BYTEMASK) << (CELLbits - 8)); // TODO-11-CELLL will be endian dependent

//L.1797
// EM is top of RAM
#define US (40 << CELLSHIFT)  // user area size in cells i.e. 64 variables - standard usage below is using about 37
#define UPP (EM - US) // start of user area // TODO-28-MULTI UP should be a variable, and used in most places UPP is
#define RP0 (UPP - (8 << CELLSHIFT))  // top of return stack RP0 - there is an 8 cell buffer which is probably just for safety.
#define RTS (0x80 << CELLSHIFT) // return stack/TIB size // eFORTH-DIFF was 64 which is tiny for any kind of string handling
#define TIB0 (RP0 - RTS) // Terminal input buffer - shares space with Return stack //TODO-28-MULTITASK will move
#define SPP (TIB0 - (8 << CELLSHIFT)) // 8 cell gap between TIB0 and SPP
#define SPS (0x80 << CELLSHIFT) // Size of data stack 256 128 bytes for now
#define NAMEE (TIB0 - SPS) // name dictionary
#define RAM0 NAMEE
#define RAMSIZE (EM - RAM0) // TODO-RAM maybe want to build up from e.g. 0x8000 instead of down from EM

#define RAMADDR(x) ((x - RAM0) >> CELLSHIFT)
#define ROMADDR(x) (x >> CELLSHIFT)

// Now some cell based pointers into RAM
#define ramSPP RAMADDR(SPP) // start of data stack - grows down, points at top of stack - 8 word buffer for safety
#define RAMCELLS (RAMSIZE >> CELLSHIFT) // Approx 624 bytes  TODO-RAM
#define ROMCELLS (NAMEE >> CELLSHIFT)
#define ramRP0 RAMADDR(RP0)
#define ramUP0 RAMADDR(UPP)


// Define the Rom area we will build the dictionary in
extern const CELLTYPE rom[ROMCELLS]; // Forward reference
extern const void (*f[30])(CELLTYPE); // Forward reference 

// And then building from the bottom up. The gap in middle is code directory
// cold start vector - its unclear if these bottom 0x100 are useful outside of the DOS context and for DOS it would need code at this address I think?
// const COLDD = 0x100;
#define UZERO 0
// Above UZERO is a store of initial values for User variables
#define CODEE (UZERO + US) // code dictionary grows up from here towards NAME dictionary.
// PAD is 80 bytes above the current top of the Code directory, and HLD (where numbers are build for output) is a few bytes growing down from PAD.

//L.1852
static CELLTYPE ram[RAMCELLS]; // Equivalent of Mem16_16 in webForth
//L.1853 - jsFunctions[] is now fp[] and has to be after definition of functions in it. 

// Key pointers used - would ideally be registers in a register based system
static CELLTYPE romIP = 0;    // Interpreter Pointer (this is a cell pointer into ram i.e. IP >> CELLSHIFT
static CELLTYPE ramSP = ramSPP;  // Data Stack Pointer (cant call SP as that is reserved) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramRP = ramRP0;  // Return Stack Pointer (aka BP in 8086) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramUP = ramUP0;  // User Area Pointer // TODO-28-MULTI will move this around

//L.2049-
// TODO if only used here then might merge into Mfetch and Mstore
CELLTYPE cellRomFetch(CELLTYPE cellAddr) { return rom[cellAddr]; };
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

void ALIGNED(CELLTYPE unused) { SPpush(align(SPpop())); }
CELLTYPE SPfetch() { return ram[ramSP]; }
CELLTYPE SPpop() { return ram[ramSP++]; }
void SPpush(CELLTYPE v) { ram[--ramSP] = v; }
CELLTYPE RPfetch() { return ram[ramRP]; }
CELLTYPE RPpop() { return ram[ramRP++]; }
void RPpush(CELLTYPE v) { ram[--ramRP] = v; }
CELLTYPE IPnext() { return rom[romIP++]; }
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

//L.2177-
// Traverse dictionary to convert xt back to a na (for decompiler or debugging)
CELLTYPE xt2na(CELLTYPE xt) {
  CELLTYPE p = currentFetch(); // vocabulary
  while (p = Mfetch(p)) {
    //console.log('_find: comparing:', this.countedToJS(p)) // comment out except when debugging find
    if (na2xt(p) == xt) {
      return p;
    }
    p -= CELLL; // point at link address and loop for next word
  }
  // Drop through not found
  return 0;
}
// TODO-ported above L.2177-

//L.2177-
void ToNAME() { SPpush(xt2na(SPpop())); }  // Fast version of >NAME see Forth definition below


//L.2221-
// a -- a; Check if a definition of the word at 'a' would be unique and display warning (but continue) if it would not be.
// Same profile as ?UNIQUE but not turned into a code word as not used prior to
void qUnique() {
  SPpush(SPfetch());      // DUP
  SPpush(currentFetch()); // a a va; dictionary to search
  find();                 // a xt na | a a F
  if (SPpop()) {
    const CELLTYPE xt = SPpop();              // Discard xt
    Serial.println('Duplicate definition of'); // Catch duplicates - report, but allow
    /*TODO-ARDUINO
      const char* name = countedToJS(SPfetch());
      if (!['foo', 'bar'].includes(name)) {
        Serial.println('Duplicate definition of', name); // Catch duplicates - report, but allow
        //Serial.println(jsFunctionAttributes[Mfetch(xt)].replaced ? 'Expected' : '', 'Duplicate definition of', countedToJS(this.SPfetch())); // Catch duplicates - report, but allow
      }
    */
  } else {
    SPpop(); // DROP a
  }
}


// na -- ; Builds bytes around a newly entered name. Same function as $,n on Zen pg94 used by all defining words (this.CODE ':')
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
    Serial.println('name error'); // This is an error - in FORTH equivalent its a THROW
  }
}


// Make the most recent definition available in the directory. This is part of closing every 'defining word'
// See also forth version
void OVERT() {
  Mstore(currentFetch(), lastFetch()); // LAST @ CURRENT @ !
}

//L.2278-
void tokenVocabulary(CELLTYPE romAddr) {
  Ustore(CONTEXToffset, romAddr << CELLSHIFT);
};
// Put the contents of the payload (1 word) onto Stack, used for CONSTANT
void tokenNextVal(CELLTYPE romAddr) {  // TODO check if could pass romAddr instead of byteAddr
  SPpush(rom[romAddr]);
};

// This is the most important token function - used for a Colon word to iterate over the list.
void tokenDoList(CELLTYPE romAddr) {
  RPpush(romIP);
  romIP = romAddr; // Point at first word in the definition
}
// Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
void tokenUser(CELLTYPE romAddr) { SPpush((rom[romAddr] + ramUP) << CELLSHIFT); }

// Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
//TODO-15-EPROM should allocate in a space that might be elsewhere.
void _tokenDoes(CELLTYPE romAddr) {
  const CELLTYPE does = rom[romAddr];
  if (does) {
    //this.debugPush();
    RPpush(romIP);
    romIP = does;
  }
}

// Put next address on the stack  -- byteAddr
void tokenCreate(CELLTYPE romAddr) {
  SPpush((romAddr+1) << CELLSHIFT);
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
  //this.debugThread(xt);
  const CELLTYPE tok = Mfetch(xt);
  xt += CELLL;
  // console.assert(tok < this.jsFunctions.length); // commented out for efficiency, a fail will just break in the next line anyway.
  f[tok](xt); // Run the token function - like tokenDoList or tokenVar - doesnt return - (JS returns null or a Promise)
}


// ported below L.2382-
void MS() { delay(SPpop()); } // ms --; delay for a period of time.
void BYE() {  romIP = 0; } // Should exit all the way out

// Unwind the effect of tokenDoList restoring IP to the next definition out.
// The XT of this is stored in this.js2xt.EXIT
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
void QRX() {
  if (Serial.available() > 0) {
    SPpush(Serial.read());
    SPpush(forthTrue);
  } else {
    SPpush(0);
  }
}
// Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.

void TXbang() { Serial.write(SPpop()); }
void bangIO() { Serial.begin(57600); } // Initialize IO port

// === Literals and Branches - using next value in dictionary === eForthAndZen#37

// push the value in the next code word
// The XT of this is stored in this.doLIT
void doLIT() { SPpush(IPnext()); }

// See DOES> and CREATE, this patches the field after the token compiled by the create to point to the code following the DOES>
// : DOES> R> LAST @ 2 CELLS - @ CELLL + ! ; // Untested Forth version, note side effect of the R> of doing an exit.
void DOES() {
  Mstore(
    Mfetch(Ufetch(LASToffset) - (2 << CELLSHIFT) ) + CELLL, // field after tokenVar compile by CREATE
    romIP << CELLSHIFT // The address after the doDOES
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


// TODO-ported above L.2382-



// ==== NEXT GROUP - HAVE TO BE MOVED DOWN BECAUSE OF USE === 
// L.1853 jsFunctions[]=
const void (*f[30])(CELLTYPE) = { tokenVocabulary, tokenNextVal, tokenDoList, tokenUser, tokenVar, ALIGNED, find, OVERT, dollarCommaN /* $,n */, ToNAME /* >NAME */, MS,
  BYE, EXIT, EXECUTE, QRX /* ?RX */, TXbang /* TX! */, bangIO /*bangIO */, doLIT, DOES /* DOES> */, next, qBranch /* ?branch */, branch  };
//TODO-ARDUINO 

const CELLTYPE rom[ROMCELLS] = { 1, 2, 3 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); // Initialize IO port TODO move to somewhere Forth wants it
  Serial.println('Starting');
  // TODO: Serial.println('Space for', NAMEE - CODEE, 'bytes for code and names');
  //(*f[0])(); // TEST function pointer 
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
