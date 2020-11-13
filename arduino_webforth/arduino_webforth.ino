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



// ==== In order, there is a gap (missing code) before each Line marker ==== 
//L.112
#define COMP 0x40 // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
#define IMED 0x80 // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
#define bitsSPARE 0x20 // Unused spare bit in names
#define BYTEMASK 0xFF - COMP - IMED - bitsSPARE // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
// Using const for forthtrue as we care about its size
const CELLTYPE forthTrue = -1; // Not quite correct, should be masked BUT when pushed that it is done underneath
#define nameMaxLength 31
#define BL 32

//L.152
// User offsets - TODO should be defined by dictionary creation - note these are in CELLS not in Bytes as in webForth
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

// Now some cell based pointers into RAM
#define ramSPP ((SPP - RAM0) >> CELLSHIFT) // start of data stack - grows down, points at top of stack - 8 word buffer for safety
#define RAMCELLS (RAMSIZE >> CELLSHIFT) // Approx 624 bytes  TODO-RAM
#define ROMCELLS (NAMEE >> CELLSHIFT)
#define ramRP0 ((RP0 - RAM0) >> CELLSHIFT)
#define ramUP0 ((UPP - RAM0) >> CELLSHIFT)

// Define the Rom area we will build the dictionary in
extern const CELLTYPE rom[ROMCELLS]; // Forward reference

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
CELLTYPE Mfetch(CELLTYPE byteAddr) { return (byteAddr > RAM0) ? cellRamFetch((byteAddr - RAM0) >> CELLSHIFT) : cellRamFetch(byteAddr >> CELLSHIFT) ; }
#ifdef WRITEROM
CELLTYPE Mstore(CELLTYPE byteAddr, CELLTYPE v) { return (byteAddr > RAM0) ? cellRamStore(byteAddr - RAM0) >> CELLSHIFT, v) : cellRomStore(byteAddr >> CELLSHIFT, v) ; }
#else
CELLTYPE Mstore(CELLTYPE byteAddr, CELLTYPE v) { cellRamStore((byteAddr - RAM0) >> CELLSHIFT, v); }
#endif

//L.2061-
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

//L.2098
// Inner function of find, traverses a linked list Name dictionary.
// name   javascript string looking for
// va     pointer holding address of first element in the list.
// cell1  if present, gives it a quick first-cell test to apply.
// xt     if present we are looking for name pointing at this executable (for decompiler)
// returns 0 or na
// TODO-11-CELLL optimize to cells
bool _sameq(na1, na2, cells) {
  // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
  for (let i = 0; i < chars; i++) {
    if (this.Mfetch8(na1 + i) !== this.Mfetch8(na2 + i)) {
      return false;
    }
  }
  return true;
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

CELLTYPE align(CELLTYPE byteAddr) {
  // TODO-MEM this is really dependent on MEM not CELLL 
  return (((byteAddr - 1) >> CELLSHIFT) + 1) << CELLSHIFT; 
}

// ==== NEXT GROUP - HAVE TO BE MOVED DOWN BECAUSE OF USE === 
// L.1853 jsFunctions[]=
const void (*f[20])(CELLTYPE) = { tokenVocabulary, tokenNextVal, tokenDoList, tokenUser, tokenVar, ALIGNED };

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
  /*
   *   { n: 'find' }, // Fast version of find - see Forth definition later
  { n: 'OVERT', replaced: true },
  // { n: '?UNIQUE', f: 'qUnique' }, // Not used yet
  { n: '$,n', f: 'dollarCommaN', replaced: true },
  { n: '>NAME', f: 'ToNAME' }, // Fast version of >NAME - see Forth definition later
  'debugNA', 'testing3', 'break', 'debugPrintTIB', 'TEST',
   */
}

void loop() {
  // put your main code here, to run repeatedly:

}
