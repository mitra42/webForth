/*
 * References see FORTH.md
*/

/* Naming conventions and abbreviations
 * xt: execution token, points at the token field of a definition
 * na: Name Address, points to the name, (first byte count+flags, then that number of characters, max 31)
 * ca: Codefield Address, field that holds the xt
 * la: Linkfield Address, field holding the na of the previously defined word in this vocabulary
 * u: unsigned 16 bit
 * c: character
 * w: word - 16 bit signed
 * n: word - 16 bit signed
 */

let testing = 0x0; // 0x01 display words passed to interpreters; 0x02 each word in tokenthread
let testingDepth = 4;
let padTestLength = 0; // Display pad length
// == Some debugging routines, can all be commented out (as long as their calls are)
let debugName; // Set in run()
let debugTIB;
let debugStack = [];
function debugPush() { debugStack.push(debugName); } // in tokenDoList
function debugPop() { debugStack.pop(); } // in EXIT

// EFORTH-DIFF difference to eForth in using indirect threaded code as makes more sense in JS

// TODO review eForth Word Set at eForthAndZen pg 25 and check all implemented

// eForthAndZen pg 26

// === Memory Map - pg26
// TODO-VM TODO-MEM rework this into separate slots and then check if really need ! and @ into some parts of mem
// EFORTH-ERRATA doesnt define CELLL (and presumes is 2 in multiple places)
// EFORTH-ERRATA the definitions on pg 26 dont come close to matching the addresses given as the example below. In particular UPP and RPP overlap !
const CELLL = 2;  // Using Buffers, but needs to be 2 as needs to be big enough for an address (offset into buffer) if change see CELL+ CELL- CELLS ALIGNED $USER
const US = 64 * CELLL;  // user area size in cells i.e. 64 variables - standard beow is using about 37
const RTS = 0x80 * CELLL; // return stack/TIB size // eFORTH-DIFF was 64 which is tiny for any kind of string handling TODO review this
const SPS = 0x80 * CELLL; // Size of data stack 256 bytes for now
// From top down
const EM = 0x4000; // top of memory
const UPP = EM - US; // start of user area
const RPP = UPP - (8 * CELLL); // top of return stack RP0 TODO figure out if this 8 celll buffer is used - something about a word buffer
const TIBB = RPP - RTS; // Terminal input buffer
const SPP = TIBB - (8 * CELLL); // start of data stack - bottom down, points at top of stack TODO figure out if this 8 celll buffer is used - something about a word buffer
const NAMEE = SPP - SPS; // name dictionary
// And bottom up - gap in middle is code directory
const COLDD = 0x100; // cold start vector
const CODEE = COLDD + US; // code dictionary
const bitsCOMP = 0x40; // bit in first char of name field to indicate 'compile-only'
const bitsIMED = 0x80; // bit in first char of name field to indicate 'immediate'
const bitsMASK = 0x1FFF; // bits to mask out of a call with count and first char

// TODO-VM make this something passed to each function.
// Standard pointers used (ref eForthAndZen pg22
let IP = 0;  // Interpreter Pointer
let SP = SPP;  // Data Stack Pointer
let RP = RPP;  // Return Stack Pointer (aka BP in 8086)
//let WP = 0;  // Word or Work Pointer
//let UP = 0;  // User Area Pointer


const m = Buffer.alloc(EM); // Allocate as one big buffer for now. TODO-MEM redo as a struct of some sort or poss u16 array

// Javascript structures
const codeSpace = []; // Maps tokens to executable functions
const userInit = [0, 0, 0, 0]; // Used for initialization of user variables - for now not in m as would be in ROM normally

// These aren't part of eForth, but are here to simplify storing 16 bit words into 8 bit bytes in the Buffer.
function SPfetch() { return (m[SP] << 8) | m[SP + 1]; }
function SPpop() { return (m[SP++] << 8) | m[SP++]; }
function SPpush(u16) { m[--SP] = u16 & 0xFF; m[--SP] = (u16 >> 8); }
function RPfetch() { return (m[RP] << 8) | m[RP + 1]; }
function RPpop() { return (m[RP++] << 8) | m[RP++]; }
function RPpush(u16) { m[--RP] = u16 & 0xFF; m[--RP] = (u16 >> 8); }
function IPnext() { return (m[IP++] << 8) | m[IP++]; }
function Mstore(a, v) { m[a++] = v >> 8; m[a] = v & 0xFF; }
function Mfetch(a) { return (m[a++] << 8) | m[a]; }
function Ufetch(userindex, offset = 0) { return Mfetch(UPP + userindex + offset); }
function Ustore(userindex, w, offset = 0) { return Mstore(UPP + userindex + offset, w); }

// Handle the Code and Namespace \pointer, which always points after last thing compiled into dictionary - in eForthAndZen this is '$'
const CURRENToffset = 64;
const CPoffset = 68; // This value is checked during the sequence of USER below
const NPoffset = 70;
const LASToffset = 72;
function currentFetch() { return Ufetch(CURRENToffset); }
function currentStore(w) { return Ustore(CURRENToffset, w); }
function cpFetch() { return Ufetch(CPoffset); }
function cpStore(w) { Ustore(CPoffset, w); }
function npFetch() { return Ufetch(NPoffset); }
function npStore(w) { Ustore(NPoffset, w); }
function lastStore(w) { Ustore(LASToffset, w); }
function lastFetch() { return Ufetch(LASToffset); }

const nameMaxLength = 31;
function countedToJS(a) {
  const c = m[a] & 0x1f;
  return m.slice(a + 1, a + c + 1).toString('utf8');
}
/* Not currently used
function SPpopWord() {  // b u -- ; return w the JS string
  const u = SPpop(); const b = SPpop(); return m.slice(b, b + u).toString('utf8');
}
*/
function na2xt(na) { return Mfetch(na - 2 * CELLL); }

function _find(va, name, cell1, xt) {
  let p = va;
  while (p = Mfetch(p)) {
    //console.log('_find: comparing:', countedToJS(p)) // comment out except when debugging find
    const c1 = Mfetch(p);
    if (xt && (na2xt(p) === xt)) {
      return p;
    }
    if (!cell1 || (cell1 === (c1 & bitsMASK))) { // first cell matches (if cell1 not passed then does slow compare
      if (countedToJS(p) === name) { // This is what SAME? does
        return p;
      }
    }
    p -= CELLL; // point at link address and loop for next word
  }
  // Drop through not found
  return 0;
}

function name2na(name) {
  return _find(currentFetch(), name);
}

function find() { // a va -- ca na | a 0
  const va = SPpop();
  const a = SPpop();
  const cell1 = Mfetch(a);
  const name = countedToJS(a);
  //console.log('find: Looking for', name) // comment out except when debugging find
  const na = _find(va, name, cell1);
  if (na) {
    SPpush(na2xt(na));
    SPpush(na);
  } else {
    SPpush(a);
    SPpush(0);
  }
}
function xt2na(xt) {
  return _find(currentFetch(), undefined, undefined, xt);
}

function xt2name(xt) {
  const na = xt2na(xt);
  return na ? countedToJS(na) : 'undefined';
}
function name2xt(name) { return na2xt(name2na(name)); }
function UfetchName(name, offset = 0) { return Ufetch(Mfetch(name2xt(name) + 2), offset); } // e.g. UfetchName('CURRENT',2)
function UstoreName(name, w, offset = 0) { return Ustore(Mfetch(name2xt(name) + 2), w, offset); } // e.g. UstoreName('BASE',10)

cpStore(CODEE); // Pointer to where compiling into dic TODO-MEM will be code.length
npStore(NAMEE); // Pointer to where writing name stack TODO-MEM will move

// === ASSEMBLY MACROS (or JS equivalent) pg 30
// TODO_VM will prob need to be inside 'vm'
//OBS uses NB user variable: let _NAME = NAMEE; // initialize name pointer
//OBS uses CP user variable let _CODE = CODEE; // initialize code pointer - points at start of last word defined (CP points to top of dict)
let _USER = 4 * CELLL; // first user variable offset, skips 4 variables used by multitasking

function $ALIGN() {} // Not applicable since using a byte Buffer

function $DW(...words) { // Forth presumes big-endian, high word stored at low memory address (which is above on stacks)
  words.forEach((word) => {
    let w;
    if (typeof word === 'string') {
      w = name2xt(word);
      if (!w) {
        console.error('Cant find', word);
      }
    } else {
      w = word;
    }
    let cp = cpFetch();
    m[cp++] = w >> 8;
    m[cp++] = w & 0xFF;
    cpStore(cp);
  });
}

console.assert(CELLL === 2); // Presuming its 2

function dollarCommaN() { // na -- ; Same function as $,n on pg94 common between $CODE and ':'
  let a = SPpop();            //            ; a = na
  if (m[a]) {                 // DUP C@ IF  ; test for no word
    SPpush(a);
    SPpush(currentFetch());
    find();                   // xt na | a F
    if (SPpop()) {
      console.log('Duplicate definition of', countedToJS(a)); // Catch duplicates - probably an error
    }
    SPpop();                  // remove xt of previous definition or a if not found.
    lastStore(a);             // DUP LAST ! ; a=na  ; LAST=na
    a -= CELLL;               // CELL-      ; a=la
    // Link address points to previous NA (prev value of LAST)
    // Note that first time this is run, it gets a 0 (CURRENT is 0, @0 is 0) if that changes will need to test Current here.
    Mstore(a, Mfetch(currentFetch())); // CURRENT @ @ OVER ! ; la = top of current dic
    a -= CELLL;               // CELL-      ; a=ca
    npStore(a);               // DUP NP !   ; NP=ca // adjust name pointer
    Mstore(a, cpFetch());     // ! EXIT     ; ca=CP ; code field to where will build in dictionary
  } else {                    // THEN $" name" THROW ;
    console.log('name error');
  }
}

function OVERT() {
  const last = lastFetch();
  Mstore(currentFetch(), last); // LAST @ CURRENT @ !
}

function $CODE(lex, name) { //TODO-CELLL check this carefully
  console.assert(name.length <= 31);
  // <NP-after>CPh CPl <_LINK> LINKh LINKl count name... <NP-BEFORE>
  $ALIGN();
  const np = npFetch();
  // Note this is going to give the name string an integral number of cells.
  const len = (((lex & 0x01F) / CELLL) + 1) * CELLL;
  let a = np - len;
  npStore(a);
  SPpush(a); // so dollarCommaN can find it
  m[a++] = lex;
  m.write(name, a, 'utf8');
  dollarCommaN(); // Build the headers that precede the name
}

// eForthAndZen 31
// tokenFunction defines a function, puts a pointer to it in codeSpace and returns the token that should be in the dict
function tokenFunction(func) {
  const x = codeSpace.length;
  codeSpace.push(func);
  return x;
}

const tokenDoList = tokenFunction((payload) => {
  debugPush(); // Pop is in EXIT
  RPpush(IP); IP = payload;
}); // Note same code on tokenDoes

/* no longer used, as define ':' before need this.
function $COLON(name) {
  const xt = cpFetch();
  $CODE(name.length, name);
  // Now writing in code dictionary
  $DW(tokenDoList);
  OVERT();
  return xt;
}
*/

const tokenUser = tokenFunction(payload => SPpush(Mfetch(payload) + UPP));

function $USER(name) { // Note unlike eForth we use Token threading see USER() which also initialized
  if (name) {
    $CODE(name.length, name);
    $DW(tokenUser, _USER);
    OVERT();
  }
  _USER += CELLL; // Need to skip to next _USER in either case
}
// tokenNextVal TODO define VARIABLE and CONSTANT to use this
const tokenNextVal = tokenFunction(payload => SPpush(Mfetch(payload)));
const tokenVar = tokenFunction(payload => SPpush(payload));

/* No longer used - not sure if it was ever used in eForth
function D$(funct, string) {
  $DW(funct, string.length);
  let cp = cpFetch();
  cp +=  m.write(string, cp, 'utf8');
  cpStore(cp);
  $ALIGN();
}
*/
/* No longer used - it was the end of $COLON in a direct threaded eForth
function $NEXT() {
  $DW(EXIT);
}
*/
function initRegisters() {
  SP = SPP;
  RP = RPP;
}
function doCOLDD() {
  initRegisters();
  COLD(); // TODO-EPRECORE should run the inner interpreter on COLD
}
function code(name, func) {
  const xt = cpFetch();
  $CODE(name.length, name);
  $DW(tokenFunction(func));
  OVERT();
  return xt;
}
function constant(name, val) {  // TODO merge this with CONSTANT once defined
  const xt = cpFetch();
  $CODE(name.length, name);
  $DW(tokenNextVal, val);
  OVERT();
  return xt;
}
//User variables initialization eForthAndZen pg33 see pg46


//TODO define VOCABULARY as CREATE DOES> word

const tokenVocabulary = tokenFunction((payload) => {
  // : doVOC R> CONTEXT ! ;
  UstoreName('CONTEXT', payload);
});
$CODE(5, 'FORTH');
$DW(tokenVocabulary);
currentStore(cpFetch()); // Initialize Current. Context & Current+2 initialized in USER process pg46
$DW(0, 0);
OVERT(); // Uses the initialization done by currentStore above.

// === Add some functions defined earlier prior to dictionary being available
code('find', find);
code('OVERT', OVERT);
code('$,n', dollarCommaN);

// == Debugging code words
code('debugNA', () => console.log('NAME=', countedToJS(SPfetch()))); // Print the NA on console
code('testing3', () => testing |= 3); // this word can be slotted in a definition to turn on debugging


// Basic key I/O eForthAndZen pg 35
code('BYE', 'TODO-bye');
code('?RX', () => console.error('TODO ?RX not defined')); //TODO-IO
code('TX!', () => console.error('TODO TX! not defined')); //TODO-IO
code('!IO', () => console.error('TODO !IO not defined')); //TODO-IO

/* TODO-IO FAILED attempt to get stdin/stdout IO then code see issue #14
var stream = require('stream');
var s = stream.Duplex()
function foo() {
  chunk = null;
  let i = 1000;
  while(!chunk) {
    //console.log('preread');
    chunk = s.read(1)
    if (chunk && chunk.length) { console.log('Saw chunk of len',chunk.length); }
    //console.log('Looping');
  }
  console.log('OutOLoop');
};
foo();
process.stdin.setEncoding('ascii');
process.stdin.pipe(s).pipe(process.stdout);
console.log('exited');
*/

/** ===================================================
 * INNER INTERPRET === YES THIS IS IT ! eForthAndZen#36
 * This is quite different from eForth as its threaded token
 */

// == INNER INTERPRETER - loops through nesting
function threadtoken(xt) {
  console.assert(xt >= CODEE && xt < NAMEE); // Catch bizarre xt values TODO-EFFICIENCY comment out
  if (testing & 0x02) {
    debugName = xt2name(xt); // Expensive so only done when testing
    if (testingDepth > debugStack.length) {
      console.log('R:', RPP === RP ? '' : m.slice(RP, RPP), debugStack, xt2name(xt), 'S:', SPP === SP ? '' : m.slice(SP, SPP),
        padTestLength ? ('pad: '+ (padTestLength > 0 ? m.slice(padPtr(), padPtr() + padTestLength) : m.slice(padPtr()+padTestLength, padPtr())).toString()) : '');
    }
  }
  //console.assert(SPP >= SP && RPP >= RP);
  const tok = ((m[xt++] << 8) + m[xt++]);
  console.assert(tok < codeSpace.length);
  codeSpace[tok](xt);
}
// This should only be called once, normally its threadtoken you want ....
function run(xt) {
  threadtoken(xt);
  // If this returns without changing program Counter, it will exit
  while (IP) {
    console.assert(IP >= CODEE && IP <= NAMEE); // TODO-EFFICIENCY comment out
    xt = IPnext(); // SEE-OTHER-ENDIAN
    //TODO-EFFICIENCY comment this out except when needed for debugging, they are slow
    // debugTIB =  m.slice(UfetchName('#TIB', 2) + UfetchName('>IN'), UfetchName('#TIB', 2) + UfetchName('#TIB')).toString('utf8');
    threadtoken(xt);
  }
}
const EXIT = code('EXIT', () => {
  debugPop(); // Pushed in tokenDoList
  IP = RPpop();
});
code('EXECUTE', () => threadtoken(SPpop()));

// === Literals eForthAndZen#37
// push the value in the next code word
code('doLIT', () => SPpush(IPnext()));

// Address Literals (aka branches and jumps) eForthAndZen#38

// decrement count and branch if not decremented past zero
code('next', () => {
  let x = RPpop();
  const destn = IPnext(); // Increments over it
  if (--x >= 0) {
    RPpush(x);
    IP = destn; // Jump back
  }
});
// Jump if flag is zero to destn in dictionary
code('?branch', () => {
  const destn = IPnext();
  if (!SPpop()) {
    IP = destn;
  }
});
// Jump to destn in dictionary
code('branch', () => IP = IPnext());

// Memory access eForthAndZen#39
code('!', () => Mstore(SPpop(), SPpop())); // w a -- , Store
code('@', () => SPpush(Mfetch(SPpop()))); // a -- w, fetch
code('C!', () => m[SPpop()] = SPpop()); // c a -- , Store character
code('C@', () => SPpush(m[SPpop()])); // a -- c, Fetch character

// Return stack words eForthAndZen#40
code('RP@', () => SPpush(RP));
code('RP!', () => RP = SPpop());
code('R>', () => SPpush(RPpop()));
code('R@', () => SPpush(RPfetch()));
code('>R', () => RPpush(SPpop()));

// Data stack initialization eForthAndZen#41
code('SP@', () => SPpush(SP));
code('SP!', () => SP = SPpop());

// Classic Data stack words eForthAndZen#42
code('DROP', () => SP += 2);
code('DUP', () => SPpush(SPfetch()));
code('SWAP', () => { const x = SPpop(); const y = SPpop(); SPpush(x); SPpush(y); });
code('OVER', () => { const x = SPpop(); const y = SPfetch(); SPpush(x); SPpush(y); }); // TODO optimize

// Logical Words eForthAndZen43
code('0<', () => SPpush((SPpop() & 0x8000) ? -1 : 0));
code('AND', () => SPpush(SPpop() & SPpop()));
code('OR', () => SPpush(SPpop() | SPpop()));
code('XOR', () => SPpush(SPpop() ^ SPpop()));

// Primitive Arithmetic Word eForthAndZen44
code('UM+', () => {
  const x = SPpop() + SPpop();
  SPpush(x & 0xFFFF);
  SPpush(x >> 16);
});

// === High Level Forth Words eForthAndZen pg46
// See pg31 for tokenUser etc and $USER nd pg33 for USER initialization values

//TODO-VAR put definition of tokenVariable or how to do it here ... (probably)
//TODO-EFORTH-5 define variable creation process use tokenNextVal
//TODO-VM Variables should not be in code space
//VARIABLE UP; //TODO-VAR figure out how to point VARIABLE UP at UP for high level forth (maybe not reqd) //TODO-MULTITASK think

function USER(name, init) {
  Mstore(UPP + _USER, init);
  $USER(name); // Put into dictionary
  userInit.push((typeof init === 'string') ?  name2xt(init) : init);
}

USER('SP0', SPP); // (--a) Pointer to bottom of the data stack.
USER('RP0', RPP); // (--a) Pointer to bottom of the return stack.
USER("'?KEY", '?RX'); // Execution vector of ?KEY. Default to ?rx.
USER("'EMIT", 'TX!');  // Execution vector of EMIT. Default to tx!
USER("'EXPECT", 'accept'); // Execution vector of EXPECT. Default to 'accept'.
USER("'TAP", undefined); // TODO KTAP Execution vector of TAP. Default the kTAP.
USER("'ECHO", 'TX!'); // Execution vector of ECHO. Default to tx!.
USER("'PROMPT", undefined); // TODO DOTOK Execution vector of PROMPT.  Default to '.ok'.
USER('BASE', 10);
USER('temp', 0); // A temporary storage location used in parse and find. EFORTH-ERRATA its uses as 'temp', listing says 'tmp'
USER('SPAN', 0); // Hold character count received by EXPECT.
USER('>IN', 0); // Hold the character pointer while parsing input stream.
USER('#TIB', 0); // Hold the current count and address of the terminal input buffer.
USER(undefined, TIBB); // Terminal Input Buffer used one cell after #TIB.
USER('CSP', 0); // Hold the stack pointer for error checking.
USER("'EVAL", undefined); // Initialized when have jsINTERPRET
USER("'NUMBER", undefined); // TODO NUMBQ Execution vector of number conversion. Default to NUMBER?.
USER('HLD', 0); // Hold a pointer in building a numeric output string.
USER('HANDLER', 0); // Hold the return stack pointer for error handling.
USER('CONTEXT', currentFetch()); // A area to specify vocabulary search order. Default to FORTH. Vocabulary stack, 8 cells following CONTEXT.
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0); // Always 0 to indicate no more valid Vocabularies
console.assert(_USER === CURRENToffset, 'CURRENT mismatch offset should be ', _USER); // This is checked because need to know this earlier
USER('CURRENT', currentFetch()); // Point to the vocabulary to be extended. Default to FORTH.
USER(undefined, currentFetch()); // Vocabulary link uses one cell after CURRENT (not clear how this is used)
console.assert(_USER === CPoffset, 'CP mismatch offset should be ', _USER); // This is checked because need to know this earlier
USER('CP', cpFetch()); // eForth initializes to CTOP but we have to use this during compilation
console.assert(_USER === NPoffset, 'NP mismatch offset should be ', _USER); // This is checked because need to know this earlier
USER('NP', npFetch()); // normally set on pg106 but we are using it live. Its the bottom of what compiled in name space.
console.assert(_USER === LASToffset, 'LAST mismatch offset should be ', _USER); // This is checked because need to know this earlier
USER('LAST', lastFetch()); // normally set on pg106 but using live

// === JS interpreter - will be discarded when done or built out
// IMMEDIATE sets a word to be interpreted, even when compiling - most useful for control loops but also pre-calculating a literal.
// It is moved early from pg96: : IMMEDIATE [ =IMED ] LITERAL LAST @ C@ OR LAST @ C! ; where IMED
// EFORTH-ERRATA IMMEDIATE COMPILE-ONLY =COMP =IMED is not defined , in EFORTHv5 its defined as 0x80
function setHeaderBits(b) {
  const lastNA = lastFetch(); // LAST points at the name field of the last defined word
  m[lastNA] |= b;
}
code('IMMEDIATE', () => setHeaderBits(bitsIMED));
code('COMPILE-ONLY', () => setHeaderBits(bitsCOMP));

function tibIn() { return UfetchName('#TIB', CELLL) + UfetchName('>IN'); }  // TIB >IN @ +
const BL = 32;
const forthTrue = 0xFFFF;

function fPARSE() { // returns b (address) and u (length)
  const c = SPpop();
  const tib = UfetchName('#TIB', CELLL);
  const ntib = UfetchName('#TIB');
  let inoffset = UfetchName('>IN');
  if (c === BL) {
    while ((inoffset < ntib) && (m[tib + inoffset] <= BL)) { inoffset++; }  // If blank then skip over leading BL /control chars
  }
  // inoffset now points at first non-delimiter or #tib
  const b = tib + inoffset;
  while ((inoffset < ntib) && ((c === BL) ? (c < m[tib + inoffset]) : (c !== m[tib + inoffset]))) { inoffset++; } // Exit with inoffset at #tib or after delimiter
  SPpush(b); SPpush(tib + inoffset - b); // Store length not including trailing delimiter
  UstoreName('>IN', inoffset < ntib ? ++inoffset : inoffset); // Skip over delimiter - TODO its not clear this is what FORTH wants. eForth doc is almost certainly wrong
}
code('PARSE', fPARSE);

function jsTOKEN() { // -- a; <string>; copy blank delimited string to name buffer, immediately below name dictionary (location is important as ':' take a shortcut in eForth.
  SPpush(BL);
  fPARSE();   // b u (counted string, adjusts >IN)
  const u = Math.min(SPpop(), nameMaxLength);
  const b = SPpop();
  const np = UfetchName('NP') - u - 2;
  m.copy(m, np + 1, b, b + u);
  m[np] = u;  // 1 byte count
  m[np + u + 1] = 0;  // eFORTH errata  pg62 - PACK$ does `0 !` which I think will overwrite bottom value of name dict as NP is last byte used
  SPpush(np); // Note that NP is not updated, the same buffer will be used for each word until hit ':'
}
code('TOKEN', jsTOKEN);

function findName() { // a -- xt na | a F
  SPpush(UfetchName('CONTEXT'));  // a va
  find();                           // xt na | a F
}

function NUMBER() { //TODO-INTERPRETER-5 make this work like things stored in 'NUMBER
  const a = SPpop();
  const w = countedToJS(a);
  const base = UfetchName('BASE');
  const n = parseInt(w, base); // TODO-NUM handle parsing errors // Needs forth to convert word
  if (isNaN(n)) {
    SPpush(a);
    SPpush(0);
  } else {
    SPpush(n);
    SPpush(forthTrue)
  }
}
// Define NUMBER and store its xt in 'NUMBER
UstoreName("'NUMBER", code('NUMBER', NUMBER));

const jsCOMPILE = code('jsCOMPILE', () => { // a -- ...; similar to $COMPILE at pg96
  findName(); // xt na | a F
  const na = SPpop();
  if (na) { // ca
    const xt = SPpop();
    const c = m[na];
    if (c & bitsIMED) {
      run(xt);
    } else {
      if (testing & 0x02) console.log('COMPILING:', countedToJS(na)); // TODO-EFFICIENCY comment out
      $DW(xt);
    }
  } else { // a
    threadtoken(UfetchName("'NUMBER")); // n T | a F
    if (SPpop()) {
      $DW('doLIT', SPpop());
    } else {
      console.log("Number conversion of",countedToJS(SPpop()),"failed"); // TODO handle error in Forth-ish way (via Throw)
    }
  }
});

const jsINTERPRET = code('jsINTERPRET', () => { // a -- ...; Based on signature of $INTERPRET at pg83
  findName(); // xt na | a F
  const na = SPpop();
  if (na) { // ca
    const xt = SPpop();
    run(xt);
  } else {
    threadtoken(UfetchName("'NUMBER")); // n T | a F
    if (!SPpop()) {
      console.log("Number conversion of",w,"failed"); // TODO handle error in Forth-ish way (via Throw)
    }
  }
});
UstoreName("'EVAL", jsINTERPRET); // Start off interpreting

function jsEVAL(inp) { // equivalent to Forth EVAL with few things wrapped around it - so not exact same TODO align it
  //OBS: input = inp; // Could point at TIB
  if (testing & 0x01) { console.log(m.slice(SP, SPP), ' >>', inp); }
  console.assert(inp.length < (RTS - 10));
  UstoreName('>IN', 0); // Start at beginning of TIB
  UstoreName('#TIB', m.write(inp, tibIn(), 'utf8')); // copy string to TIB, and store length in #TIB
  //OBS: while (input && input.length) {
  while (UfetchName('>IN') < UfetchName('#TIB')) {
    jsTOKEN(); // a ; pointing to word in Name Buffer (NB)
    // There may be case where jsTOKEN returns empty string at end of line or similar.
    if (m[SPfetch()] === 0) { // Skip zero length string
      SPpop();
    } else {
      //console.log('>', w); //TODO-EFFICIENCY comment out
      run(UfetchName("'EVAL"));
    }
    console.assert(SP <= SPP && RP <= RPP); // Side effect of making SP and SPP available to debugger.
  }
}
function interpret(inp) {
  inp.split('\n').forEach(i => jsEVAL(i));
}

function padPtr() { return UfetchName('CP') + 80; } // Sometimes JS needs the pad pointer
function test(inp, arr, { pad = undefined, hold = undefined } = {}) {
  console.assert((SPP === SP) && (RPP === RP) && (debugStack.length === 0));
  interpret(inp);
  const mm = m; // this is just to make sure m is in scope for debugging
  while (arr.length) {
    if (arr.pop() !== SPpop()) {
      console.log('Test of:', inp, 'did not leave expected result');
    }
  }
  if (pad) {
    console.assert(m.slice(padPtr(), padPtr() + pad.length).toString() === pad);
  }
  if (hold) {
    console.assert(m.slice(padPtr() - hold.length, padPtr()).toString() === hold);
  }
  console.assert((SPP === SP) && (RPP === RP));
}

// === A group of words defined relative to the JS interpreter but will be redefined to the Forth interpreter at pg TODO

// TODO could replace with : ':' TOKEN $,n [ ' doLIST ] LITERAL CALL, ] ; see pg96
code(':', () => {
  jsTOKEN();  // a; (counted string in named space)
  dollarCommaN();
  $DW(tokenDoList); // Must be after creating the name and links etc
  UstoreName("'EVAL", jsCOMPILE);
});


code(';', () => { $DW(EXIT); OVERT(); UstoreName("'EVAL", jsINTERPRET); }); // TODO-INTERPRETER replace with definition of ;
interpret('IMMEDIATE');
code('[', () => UstoreName("'EVAL", jsINTERPRET)); interpret('IMMEDIATE'); //pg84 and pg88
code(']', () => UstoreName("'EVAL", jsCOMPILE)); // pg88
// Create a new word that doesnt allocate any space, but will push address of that space. )
// : CREATE TOKEN $,n OVERT COMPILE tokenVar ; // except tokenVar isn't an accessible value
code('CREATE', () => { jsTOKEN(); dollarCommaN(); OVERT(); $DW(tokenVar); });

//EXIT & EXECUTE tested with '
// doLIT implicitly tested by all literals
// next, ?branch, branch implicitly tested by control structures
test('123 HLD ! HLD @', [123]); // Also tests user variables
test('111 HLD ! 222 HLD C! HLD C@ 0 HLD C! HLD @', [222, 111]);
// R> >R R@ SP@ SP! tested after arithmetic operators
test('1 2 DROP', [1]);
test('1 2 DUP', [1, 2, 2]);
test('1 2 SWAP', [2, 1]);
test('1 2 OVER', [1, 2, 1]);
test('123 0< -123 0<', [0, 0xFFFF]);
interpret('16 BASE !');
test('5050 6060 AND 5050 6060 OR 5050 6060 XOR', [0x4040, 0x7070, 0x3030]);
interpret('0A BASE !');
test('12 34 UM+ 60000 60000 UM+', [46, 0, 60000 + 60000 - (2 ** 16), 1]);
// IMMEDIATE implicitly tested
test('32 PARSE ABC SWAP DROP', [3]);

// === Vocabulary and Sort Order eForthAndZen pg47

// EFORTH-DIFF with direct threaded code makes sense to put function, prefer here to use a tokenized Does>
//TODO doesnt belong here as not used for FORTH - move to definition of CREATE DOES>
//tokenDoes = tokenFunction(payload => { RPpush(IP); IP = (m[payload++]<<8)+m[payload++]; SPpush(payload++); ); // Almost same as tokenDoList

// doVOC is not used; and 'FORTH' is moved earlier to be the first word defined

// === Words moved earlier ....
constant('BL', BL);
test('BL', [32]);

// Note this is the first colon definition so there is a lot that can go wrong with it.
interpret(': 2DROP DROP DROP ;'); // w1 w2 -- ; Drop two items pg 49)
test('1 2 2DROP', []);

// CHAR: Parse a word and return its first character
// CTRL: Parse a word, return first character as a control
interpret(`
: CHAR BL PARSE DROP C@ ;
: CTRL CHAR 31 AND ;
`);
test('CHAR )', [41]);
test('CTRL H', [08]);


// Comment character - from here on we can use ( xxx) in interpreted strings
interpret(': ( 41 PARSE 2DROP ; IMMEDIATE'); // pg74 : ( [ CHAR ) ] LITERAL PARSE 2DROP ; IMMEDIATE
test('1 2 ( 3 )', [1, 2]);

// Note failure on this line, can be for three reasons
// a: its the first execution of an immediate word inside a compilation
// b: its the first execution of a word defined with a colon
// c: its the first use of the comment
interpret(`: HERE ( -- a; return top of code dictionary; pg60)
  CP @ ;`);
// test is non-obvious

constant('CELLL', CELLL); // effectively '2 CONSTANT CELLL' but dont have CONSTANT at this point
test('CELLL', [2]); // Assuming small cell, otherwise it should be 2

// Note eForth has +, but that isn't defined till pa50
interpret(': CELL+ CELLL UM+ DROP ;');
test('1 CELL+', [3]);

// pg89 : ' ( -- ca ) TOKEN NAME? IF EXIT THEN THROW ;
code("'", () => { // -- xt; Search for next word in input stream // TODO-RECODE as WORD FIND NOT IF ERROR THEN needs WORD FIND ERROR reqs FIND
  jsTOKEN(); // -- a; String with count in first byte
  findName(); // xt na | a 0
  if (!SPpop()) {
    console.error(countedToJS(SPpop()), "not found during '");
  }
});
test(': FOO 1 EXIT 2 ; FOO', [1]);
test("' FOO EXECUTE 3", [1, 3]);


interpret(`
: , HERE ( w --; Compile an integer into the code dictionary. pg 90)
  DUP CELL+ CP ! ! ;

: [COMPILE] ( --; <string>; Compile next immediate word into code dictionary; pg90)
  ' , ; IMMEDIATE
`); interpret(`

: COMPILE ( --; Compile the next address in colon list to code dictionary. pg 90)
  R> DUP @ , CELL+ >R ;

: LITERAL ( w -- ) ( Compile tos to code dictionary as an integer literal.)
  COMPILE doLIT ( compile doLIT to head lit )
  , ; IMMEDIATE ( compile literal itself )
`);
// TODO-TEST test of above group non-obvious as writing to dictionary.

// === Control structures - were on pg91 but needed earlier pg 91-92 but moved early
interpret(`
: FOR ( -- a; Start a FOR-NEXT loop structure in a colon definition)
  COMPILE >R HERE ; IMMEDIATE

: BEGIN ( -- a ; Start an infinite or indefinite loop structure)
  HERE ; IMMEDIATE ( push HERE for later ref. )

: NEXT ( a --; Terminate a FOR-NEXT loop structure)
  COMPILE next , ; IMMEDIATE

: UNTIL ( a -- ; Terminate a BEGIN-UNTIL indefinite loop structure )
  COMPILE ?branch , ; IMMEDIATE

: AGAIN ( a -- ; Terminate a BEGIN-AGAIN infinite loop structure )
  COMPILE branch , ; IMMEDIATE
( TODO interpret 'COMPILE-ONLY' - how is COMPILE-ONLY used, where does it set flags?)

: IF ( -- A; begin conditional branch structure pg 92)
  COMPILE ?branch HERE 0 , ; IMMEDIATE

: AHEAD ( -- A; compile a forward branch instruction. pg  92)
  COMPILE branch HERE 0 , ; IMMEDIATE

: REPEAT ( A a -- ; Terminate BEGIN-WHILE-REPEAT loop )
  [COMPILE] AGAIN HERE SWAP ! ; IMMEDIATE

: THEN ( A --; terminate conditional branch structure pg 92)
  HERE SWAP ! ; IMMEDIATE

: AFT ( a -- a A ; Jump to THEN in a FOR-AFT-THEN-NEXT loop the first time through. pg92)
  DROP            ( discard address left by IF )
  [COMPILE] AHEAD ( compile unconditional jump )
  [COMPILE] BEGIN ( leave HERE on stack )
  SWAP ; IMMEDIATE         ( realign jump addresses )

: ELSE ( A -- A; False clause of IF ELSE THEN structure pg 92)
  [COMPILE] AHEAD SWAP [COMPILE] THEN ; IMMEDIATE

: WHILE ( a -- A a ; Conditional branch out of a BEGIN-WHILE-REPEAT loop.)
  [COMPILE] IF
  SWAP ; IMMEDIATE
`);
// test of above group non-obvious as writing to dictionary.
// IF-THEN tested in ?DUP;

// === Multitasking pg48 - not implemented in eForth TODO

// === More Stack Words pg49
interpret(`
: ?DUP DUP IF DUP THEN ; ( w--ww|0) ( Dup top of stack if its is not zero.)
: ROT >R SWAP R> SWAP ; ( w1, w2, w3 -- w2 w3 w1; Rotate third item to top)
: 2DUP OVER OVER ; ( w1 w2 -- w1 w2 w1 w2;)
( 2DROP moved earlier )
`);
test('1 ?DUP 0 ?DUP', [1, 1, 0]);
test('1 2 3 ROT', [2, 3, 1]);
test('1 2 2DUP', [1, 2, 1, 2]);
// === More Arithmetic operators pg50
interpret(`
: + UM+ DROP ; ( w1 w2 -- w1+w2)
: D+ >R SWAP >R UM+ R> R> + + ; ( d1 d2 -- d1+d2)
: INVERT -1 XOR ; ( w -- w; 1's compliment)
( NOT's meaning is deprecated use 0= or INVERT bitwise see http://lars.nocrew.org/forth2012/core/INVERT.html)
: NEGATE INVERT  1 + ; ( w -- w; 2's complement)
: DNEGATE INVERT >R INVERT  1 UM+ ;
: - NEGATE + ; ( n1 n2 -- n1-n2)
: ABS DUP 0< IF NEGATE THEN ; ( n -- n; Absolute value of w)
: 0= IF 0 ELSE -1 THEN ;
`);
test('1 2 +', [3]);
test('40000 1 40000 3 D+', [14464, 5]);
test('257 INVERT', [0xFEFE]); // 257 is 0x101
test('53 NEGATE 53 +',  [0]);
test('456 123 - 456 -123 -', [333, 579]);
test('-456 ABS 456 ABS -', [0]);
test('111 >R R@ RP@ R> SWAP RP@ SWAP -', [111, 111, 2]);
test('1 2 SP@ 2 + SP!', [1]);

// More comparison pg51-52
interpret(`
: = XOR IF 0 EXIT THEN -1 ; ( w w -- t)
: U< 2DUP XOR 0< IF SWAP DROP 0< EXIT THEN - 0< ;
: < 2DUP XOR 0< IF DROP 0< EXIT THEN - 0< ;
: MAX 2DUP < IF SWAP THEN DROP ;
: MIN 2DUP SWAP < IF SWAP THEN DROP ;
: WITHIN OVER - >R - R> U< ;
`);
test('123 123 = 123 124 =', [0xFFFF, 0]);
test('123 100 U< 100 123 U< 123 -100 U< -100 123 U<', [0, forthTrue, forthTrue, 0]);
test('123 100 < 100 123 < 123 -100 < -100 123 <', [0, forthTrue, 0, forthTrue]);
test('100 200 MAX 300 100 MAX', [200, 300]);
test('100 200 MIN 300 100 MIN', [100, 100]);
test('200 100 300 WITHIN 300 100 200 WITHIN 100 -100 200 WITHIN', [forthTrue, 0, forthTrue]);

// === More Math Words pg53-55 UM/MOD M/MOD /MOD MOD / UM+ * M*
interpret(`
: UM/MOD ( udl udh u -- ur uq ) ( needs FOR-NEXT from 91)
  ( Unsigned divide of a double by a single. Return mod and quotient)
  2DUP U<
  IF NEGATE         ( negate u for subtraction )
    15 FOR          ( repeat 16 times for 16 bits)
      >R            ( save -u)
      DUP UM+       ( left shift udh)
      >R >R DUP UM+ ( left shift udl)
      R> + DUP      ( add carry to udh)
      R> R@ SWAP    ( retrieve -u)
      >R UM+        ( subtract u from udh)
      R> OR         ( a borrow?)
      IF >R DROP    ( yes add a bit to quotient)
        1 + R>
      ELSE DROP     ( no borrow)
      THEN R>       ( retrieve -u)
    NEXT            ( repeat for 16 bits)
    DROP SWAP EXIT  ( return remainder and quotient)
  THEN DROP 2DROP   ( overflow, return -1's)
  -1 DUP
;
: M/MOD ( d n -- r q)
  ( Signed floored divide of double by single. Return mod and quotient.)
  DUP 0<          ( n negative)
  DUP >R          ( save a copy of flag)
  IF NEGATE >R    ( take abs of n)
    DNEGATE R>    ( negative d also)
  THEN >R
  DUP 0<          ( if d is negative)
  IF R@ + THEN    ( floor it)
  R> UM/MOD       ( now divide)
  R>              ( if n is negative)
  IF SWAP NEGATE SWAP THEN  ( negative remainder also )
;
: /MOD ( n1 n2 -- r q)
  ( Signed divide. Return mod and quotient)
  OVER 0<     ( sign extend n1)
  SWAP M/MOD  ( floored divide)
;
: MOD ( n n -- r)
  ( Signed divide. Return mod only)
  /MOD DROP ; ( discard quotient)

: / ( n n -- q)
  ( Signed divide. Return quotient only)
  /MOD SWAP DROP ; ( discard remainder)

: UM* ( u1 u2 -- ud)
  ( Unsigned multiply. Return double product.)
  0 SWAP          ( u1 sum u2)
  15 FOR          ( repeat for 16 bits)
    DUP UM+ >R >R ( left shift u2)
    DUP UM+       ( left shift sum)
    R> +          ( add carry to u2)
    R>            ( carry shifted out of u2?)
    IF >R OVER UM+  ( add u1 to sum)
      R> +        ( carry into u2)
    THEN
  NEXT            ( repeat 16 time to form ud)
  ROT DROP ;        ( discard u1)

: * ( n n -- n)
  ( Signed multiply. Return single product)
  UM* DROP ; ( retain only low part)

: M* ( n1 n2 -- d)
  ( Signed multiply. Return double product)
  2DUP XOR 0< >R    ( n2 n2 have same sign?)
  ABS SWAP ABS UM*  ( multiply absolutes)
  R> IF DNEGATE THEN ;  ( negate if signs are different)
`);
function forthNum(n) { return (n < 0) ? 0x10000 + n : n; } // to allow negative numbers in test
test('1 2 4 UM/MOD', [1, 2 ** 15]);
test('1 2 4 M/MOD', [1, 2 ** 15]);
test('9 4 /MOD', [1, 2]);
test('9 4 MOD', [1]);
test('9 4 /', [2]);
test('256 256 UM*', [0, 1]);
test('3 4 *', [12]);
test('256 256 M*', [0, 1]); // TODO add a negative test

// Scaling Words pg56 */MOD */
interpret(`
: */MOD ( n1 n2 n3 -- r q )
  ( Multiply n1 and n2, then divide by n3. Return mod and quotient)
  >R M*       ( n1*n2)
  R> M/MOD ;  ( n1*n2/n3 with remainder)

: */ ( n1 n2 n3 -- q )
  ( Multiple by n1 by n2, then divide by n3. Return quotient only)
  */MOD SWAP DROP ; ( n1*n2/n3 and discard remainder)
`);
test('5 7 2 */MOD', [1, 17]);
test('5 7 2 */', [17]);

// === Memory Alignment words pg57 CELL+ CELL- CELLS ALIGNED
/*
( CELL+ is moved earlier)
: CELL+ ( a -- a)
  ( Add cell size in byte from address )
  CELLL + DROP ;  ( eForth uses '2 +' which is wrong unless CELL is '2' )
*/
interpret(`
: CELL- ( a -- a)
  ( Subtract cell size in byte from address)
  CELLL - ;

: CELLS ( n - n )
  ( Multiply n by cell size in bytes)
  CELLL * ;
`);
test('123 CELL-', [121]);
test('123 CELLS', [246]);

/* EFORTH-ERRATA - pg57 presumes CELLL==2 and need to align, not case with JS and byte Buffer
: ALIGNED ( b -- a)
  ( Align address to the cell boundary)
  DUP 0 CELLL UM/MOD    ( divide b by 2)
  DROP DUP          ( save remainder)
  IF CELLL SWAP - THEN  ( add 1 if remainder is 1)
  + ;
*/
interpret(': ALIGNED ;');
test('101 ALIGNED', [101]);

// === Special Characters pg58 BL >CHAR
interpret(`
( BL moved earlier)

: >CHAR ( c -- c; filter non printing characters, replace by _)
  127 AND DUP   ( mask off the MSB bit)
  127 BL WITHIN ( if its a control character)
  IF DROP 95 THEN ; ( replace with an underscore)
`);
test('41 >CHAR 23 >CHAR BL >CHAR', [41, 95, 32]);

// === Managing Data Stack pg59 DEPTH PICK
interpret(`
: DEPTH ( -- n)
  ( Return the depth of the data stack)
  SP@           ( current stack pointer)
  SP0 @ SWAP -  ( distance from stack origin)
  CELLL / ;     ( divide by bytes/cell)

: PICK ( ... +n -- ... w)
  ( Copy the nth stack item to tos)
  1 + CELLS     ( bytes below tos)
  SP@ + @ ;     ( fetch directly from stack)
`);
test('1 2 3 DEPTH', [1, 2, 3, 3]);
test('11 22 33 1 PICK', [11, 22, 33, 22]);

// Memory Access pg60 +! 2! 2@ HERE PAD TIB @EXECUTE
// Note 2! 2@ presume big-endian which is a Forth assumption (high word at low address)
interpret(`
: +! ( n a -- ; Add n to the contents at address a)
  SWAP OVER @ + SWAP ! ;
: 2! ( d a -- ; Store double integer to address a, high part at low address)
  SWAP OVER ! CELL+ ! ;
: 2@ ( a -- d; Fetch double integer from address a, high part from low address)
  DUP CELL+ @ SWAP @ ;
( HERE is defined in moved forward words)
: PAD ( -- a; Return address of a temporary buffer above code dic)
  HERE 80 + ;
: TIB ( -- a; Return address of terminal input buffer)
  #TIB CELL+ @ ; ( 1 cell after #TIB)
: @EXECUTE ( a -- ; execute vector -if any- stored in address a)
  @ ?DUP IF EXECUTE THEN ;
`);
test('HLD @ 2 HLD +! HLD @ SWAP -', [2]);
test('1 2 3 SP@ 4 5 ROT 2!', [1, 4, 5]);
test('1 2 3 SP@ 2@', [1, 2, 3, 2, 3]);
test('TIB >R BL PARSE XXX SWAP R> -', [3, 16]);

// Memory Array and String pg61-62: COUNT CMOVE FILL -TRAILING PACK$
interpret(`
: COUNT ( b -- b+1 +n; return count byte of string and add 1 to byte address)
  DUP 1 + SWAP C@ ;

: CMOVE ( b1 b2 u -- ; Copy u bytes from b1 to b2)
  FOR             ( repeat u+1 times)
    AFT           ( skip to THEN first time)
      >R DUP C@   ( fetch from source )
      R@ C!       ( store to destination)
      1 +         ( increment source address)
      R> 1 +      ( increment destination address)
    THEN
  NEXT 2DROP ;    ( done discard addresses)
`); interpret(`
: FILL ( b u c --; Fill u bytes of character c to area beginning at b.)
  SWAP            ( b c u)
  FOR             ( loop u+1 times)
    SWAP          ( c b )
    AFT           ( skip to THEN)
      2DUP C!     ( c b; store c to b)
      1 +         ( c b+1; increment b)
    THEN
  NEXT 2DROP ;    ( done, discard c and b)

: -TRAILING ( b u -- b u ; Adjust the count to eliminate trailing white space.)
  FOR                 ( scan u+1 characters)
    AFT               ( skip the first loop)
      BL              ( blank for comparison)
      OVER R@ + C@ <  ( compare char at the end)
      IF R> 1 +       ( non-white space, exit loop)
        EXIT          ( with adjusted count)
      THEN
    THEN              ( else continue scanning)
  NEXT 0 ;            ( reach the beginning of b)

( Note there is code in jsTOKEN which does this )
( Note that PACK$ has very different definition in eForthOverviewv5 which I've used)
: PACK$ ( b u a -- a; Build a counted string with u characters from b. Null fill.)
  ALIGNED             ( noop on JS celll=2 where not requiring alignment)
  DUP >R OVER         ( b u a u ; save address of word buffer )
  DUP 0 CELLL UM/MOD DROP ( b y a u r; find remainder of chars if not exact number of cells)
  - OVER + 0 SWAP !   ( b y a ; Store 0 in last cell)
  2DUP C!             ( store the character count first )
  1 + SWAP CMOVE      ( ; store characters in cells - 0 padded to end of cell)
  R> ;        ( leave only word buffer address )
`);
test('NP @ 4 + COUNT SWAP DROP', [5]);
test('NP @ 4 + COUNT PAD SWAP CMOVE', [], { pad: 'PACK$' });
test('PAD 3 + 5 BL FILL', [], { pad: 'PAC     ' });
test('PAD 8 -TRAILING >R PAD - R>', [0, 3], { pad: 'PAC' });
test('NP @ 4 + COUNT PAD 1 - PACK$', [padPtr() - 1], { pad: 'PACK$' });
// === TEXT INTERPRETER ===  pg63

// === Numeric Output pg64 DIGIT EXTRACT
interpret(`
: DIGIT ( u -- c ; Convert digit u to a character.)
  9 OVER <    ( if u is greater than 9)
  7 AND +     ( add 7 to make it A-F)
  48 + ;      ( add ASCII 0 for offset)
: EXTRACT ( n base -- n/base c ; Extract the least significant digit from n.)
  0 SWAP UM/MOD   ( divide n by base)
  SWAP DIGIT ;    ( convert remainder to a digit)
`);
test('123 10 EXTRACT', [12, 51]);

// Number formatting pg65 <# HOLD #S SIGN #>
interpret(`
: <# ( -- ;  Initiate the numeric output process.)
  PAD HLD ! ; ( use PAD as the number buffer)

: HOLD ( c -- ; Insert a character into the numeric output string.)
     HLD @          ( get the digit pointer in HLD)
     1 - DUP HLD !  ( decrement HLD)
     C! ;           ( store c where HLD pointed to)

: # ( u -- u; Extract one digit from u and append the digit to output string.)
     BASE @         ( get current base)
     EXTRACT        ( extract one digit from u)
     HOLD ;         ( save digit to number buffer)

: #S ( u -- 0 ; Convert u until all digits are added to the output string.)
  BEGIN     ( begin converting all digits)
    # DUP   ( convert one digit)
  WHILE     ( repeat until u is divided to 0)
  REPEAT ;

: SIGN ( n-- ; Add a minus sign to the numeric output string.)
  0< ( if n is negative)
  IF 45 HOLD THEN ; ( add a - sign to number string)

: #> ( w -- b u ; Prepare the output string to be TYPEed.)
  DROP          ( discard w)
  HLD @         ( address of last digit)
  PAD OVER - ;  ( return address of 1st digit and length)
`);

test('123 <# DUP SIGN #S #>', [padPtr() - 3, 3], { hold: '123' });
test('-123 DUP ABS <# #S SWAP SIGN #>', [padPtr() - 4, 4], { hold: '-123'});

// === More definitions moved up
interpret(`
: EMIT ( c--;  Send a character to the output device. pg69)
  'EMIT @EXECUTE ;
: SPACE ( -- ; Send the blank character to the output device. pg70)
  BL EMIT ; ( send out blank character)
: SPACES ( n -- ; Send n spaces to the output device. pg70)
  SWAP 0 MAX FOR AFT SPACE THEN NEXT DROP ;
: TYPE ( b u -- ; Output u characters from b)
  FOR AFT DUP C@ EMIT 1 + THEN NEXT DROP ;
`);
// TODO-TEST TODO-OUTPUT EMIT, SPACE SPACES TYPE

// === Number output pg66 str HEX DECIMAL .R U.R U. . ?
interpret(`
: str ( n -- b u ; Convert a signed integer to a numeric string)
  DUP >R  ( save a copy for sign)
  ABS     ( use absolute of n)
  <# #S   ( convert all digits)
  R> SIGN ( add sign from n)
  #> ;    ( return number string addr and length)

( Set radix as base for numeric conversions)
: HEX ( --) 16 BASE ! ;
: DECIMAL ( --) 10 BASE ! ;

: .R ( n +n -- ; Display an integer in a field of n columns, right justified.)
  >R str            ( convert n to a number string)
  R> OVER - SPACES  ( print leading spaces)
  TYPE ;            ( print number in +n column format)

: U.R ( u+ n -- ; Display an unsigned integer in n column, right justified.)
  >R            ( save column number)
  <# #S #> R>   ( convert unsigned number)
  OVER - SPACES ( print leading spaces)
  TYPE ;        ( print number in +n columns)

: U. ( u -- ; Display an unsigned integer in free format.)
  <# #S #>  ( convert unsigned number)
  SPACE     ( print one leading space)
  TYPE ;    ( print number)

: . ( w--; Display an integer in free format, preceded by a space.)
  BASE @ 10 XOR     ( if not in decimal mode)
  IF U. EXIT THEN   ( print unsigned number)
  str SPACE TYPE ;  ( print signed number if decimal)

: ? ( a -- ; Display the contents in a memory cell.)
  @ . ; ( very simple but useful command)
`);
//TODO-TEST TODO-OUTPUT .R U.R U. . ?

// === Numeric input pg67-68 DIGIT? NUMBER?
// eFORTH-ERRATA NIP is not designed
interpret(`
: NIP ( x1 x2 -- x2 )
  SWAP DROP ;
: DIGIT? ( c base -- u t ; Convert a character to its numeric value. A flag indicates success.)
  >R                    ( save radix )
  48 -          ( character offset from digit 0 - would be better as '[ CHAR 0 ] LITERAL' but dont have '[')
  9 OVER <              ( is offset greater than 9? )
  IF 7 -                ( yes. offset it from digit A )
    DUP                 ( n n )
    10 <                ( if n<10, the flag will be -1, and )
    OR                  ( OR with n, result will be -1 )
  THEN                  ( if n>10, the flag will be 0 and )
  DUP                   ( OR result will still be n )
  R> U< ;               ( if n=/>radix, the digit is not valid )

( TODO evaluate control structures here)
( EFORTH-ERRATA it doesnt return 'n T' it returns 'n a' on success
: NUMBER? ( a -- n T, a F ; Convert a number string to integer. Push a flag on tos.)
  BASE @ >R         ( save the current radix in BASE )
  0 OVER COUNT      ( a 0 a+1 n --, get length of the string )
  OVER C@           ( get first digit )
  36                ( [ CHAR $ ] LITERAL )
  =                 ( is it a $ for hexadecimal base?)
  IF HEX            ( use hexadecimal base and adjust string )
    SWAP 1 +        ( a 0 n a+2 )
    SWAP 1 -        ( a 0 a+2 n-1 )
  THEN OVER C@      ( get the next digit )
  45                ( [ CHAR - ] LITERAL )
  =                 ( is it a - sign? )
  >R                ( a 0 b' n'; save the - flag )
  SWAP R@ -         ( adjust address b )
  SWAP R@ +         ( a 0 b" n") ( adjust count n)
  ?DUP              ( do we still have digits left? )
  IF                ( yes. do conversion )
    1 - ( a 0 b" n"-1) ( adjust loop count for FOR-NEXT loop )
    FOR DUP >R      ( save address b )
      C@            ( get one digit )
      BASE @ DIGIT? ( convert it according to current radix )
    WHILE SWAP      ( it is a valid digit )
      BASE @ * +    ( multiply it by radix and add to sum )
      R> 1 +        ( increment b, pointing to next digit )
    NEXT            ( loop back to convert the next digit )
      R@ ( ?sign)   ( completely convert the string.get sign )
      NIP ( a sum ) ( discard string address b )
      IF NEGATE THEN ( negate the sum if - flag is true )
      SWAP          ( sum a )
    ELSE            ( a non-digit was encountered )
      R> R>         ( a sum b" b index)
      2DROP         ( a sum b")
      2DROP 0       ( a 0 , conversion failed )
    THEN DUP        ( /sum a a/ if success; else /a 0/ 0 )
  THEN
  R> ( n ?sign)     ( retrieve the sign flag )
  2DROP             ( discard garbage )
  R> BASE ! ;       ( restore radix )

`);
test('1 2 NIP', [2]);
test('50 10 DIGIT?', [2, forthTrue]);
test('BL PARSE 1234 PAD PACK$ NUMBER? DROP', [1234]);
//TODO Note the errata in the docs v. code for NUMBER? means we drop testing the flag will reconsider when see how used

// === Serial I/O pg69 ?KEY KEY EMIT NUF?
interpret(`
: ?KEY ( -- c T | F) ( Return input character and true, or a false if no input.)
  '?KEY @EXECUTE ;
: KEY ( -- c ) ( Wait for and return an input character.)
  BEGIN ?KEY UNTIL ;
( EMIT moved up )
: NUF? ( -- t) ( Return false if no input, else pause and if CR return true)
  ?KEY DUP ( -- c T T | F F;  wait for a key-stroke)
  IF 2DROP KEY
    13 = ( return true if key is CR)
  THEN ;
`);
//TODO-TEST TODO-INPUT then test ?KEY KEY NUF?

// === Derived I/O pg70 PACE SPACE SPACES TYPE CR
interpret(`
: PACE ( --) ( Send a pace character for the file downloading process.)
  11 EMIT ; ( 11 is the pace character)
( SPACE and SPACES and TYPE moved earlier)
: CR ( --) ( Output carriage return line feed)
  15 EMIT 11 EMIT ;
`);
//TODO-TEST TODO-INPUT then test PACE, CR

// === String Literal pg71 do$ $"| ."|
interpret(`
: do$ ( --a) ( Return the address of a compiled string.)
  R>    ( this return address must be preserved)
  R@    ( get address of the compiled string)
  R>    ( get another copy)
  COUNT + ALIGNED >R  ( replace it with addr after string)
  SWAP  ( get saved address to top)
  >R ;  ( restore the saved return address)

: $"| ( -- a) ( Run time routine compiled by $". Return address of a compiled string.)
  do$ ; ( return string address only)
: ."| ( -- ) ( Run time routine of ." . Output a compiled string.)
  do$           ( get string address)
  COUNT TYPE ;  ( print the compiled string)
`);
//TODO-TEST check $"| tested by $" once that is defined
//TODO-TEST TODO-OUTPUT then check ."| tested by ."

// === Word Parser pg72-73 PARSE parse
/*
interpret(`
// EFORTH-ERRATA this doesnt set >IN past the string, but the callers clearly assume it does.
// the version in eForthAndZen pg72 is obviously broken as it doesn't even increment the pointer in the FOR loop.
// The version in eForthOverViewV5 matches the spec, but clearly not what is expected.
// For now keeping the javascript versions that work TODO come back and get this working

: parse ( b u c -- b u delta ; <string> ) ( TODO evaluate control structures here)
  ( Scan string delimited by c. Return found string and its offset. )
  ( eFORTH-ERRATA - delta appears to be to end of string, not start )
  temp !            ( save delimiter in temp )
  OVER >R DUP       ( b u u)
  IF                ( if string length u=0, nothing to parse )
    1 -             ( u>0, decrement it for FOR-NEXT loop )
    temp @ BL =     ( is delimiter a space? )
    IF              ( b u' --, skip over leading spaces )
      FOR BL        ( eFORTH-ERRATA says BLANK )
        OVER C@       ( get the next character )
        - 0<          ( is it a space? )
        INVERT
      WHILE
        1 +           ( eForth errata - correct in eForthOverviewv5.pdf )
      NEXT            ( b -- , if space, loop back and scan further)
        R> DROP       ( end of buffer, discard count )
        0 DUP EXIT    ( exit with -- b 0 0, end of line)
     THEN
     ( eFORTH errata - correct in eForthOverview5.pdf: 1 -              ( back up the parser pointer to non-space )
     R>               ( retrieve the length of remaining string )
    THEN
    OVER SWAP           ( b' b' u' -- , start parsing non-space chars )
    FOR
      temp @            ( get delimiter )
      OVER C@ -         ( get next character )
      temp @ BL =
      IF 0<
      ( EFORTH-ERRATA ELSE 1 + )
      THEN
    WHILE               ( if delimiter, exit the loop )
      1 +
    NEXT                ( not delimiter, keep on scanning )
      DUP >R            ( save a copy of b at the end of the loop)
    ELSE                ( early exit, discard the loop count )
      R> DROP           ( discard count )
      DUP 1 + >R        ( save a copy of b'+1)
    THEN
    OVER -              ( length of the parsed string )
    R> R> -             ( and its offset in the buffer )
    EXIT
  THEN ( b u)
  OVER                  ( buffer length is 0 )
  R> - ;                ( the offset is 0 also )

: PARSE ( c -- b u ; <string> ) ( Scan input stream and return counted string delimited by c.)
  >R              ( save the delimiting character )
  TIB >IN @ +     ( address in TIB to start parsing )
  #TIB @ >IN @ -  ( length of remaining string in TIB )
  R> parse        ( parse the desired string )
  >IN +! ;        ( move parser pointer to end of string )
`);
*/

// === Parsing Words pg74 .( ( \ CHAR TOKEN WORD
interpret(`
( CHAR is moved earlier )

: .(  ( -- ) ( Output following string up to next )
  [ CHAR ) ] LITERAL PARSE
   ( parse the string until next )
  TYPE ; IMMEDIATE         ( type the string to terminal )

: (
  [ CHAR ) ] LITERAL PARSE
  2DROP ; IMMEDIATE

: \\ ( -- ; Ignore following text till the end of line.)
   #TIB @ >IN ! ( store the length of TIB in >IN )
   ; IMMEDIATE ( in effect ignore the rest of a line )

( Note there is jsTOKEN which does same thing )
: TOKEN ( -- a ; <string> ; Parse a word from input stream and copy it to name dictionary.)
  BL PARSE            ( parse out next space delimited string )
  31 MIN              ( truncate it to 31 characters = nameMaxLength )
  NP @                ( word buffer below name dictionary )
  OVER - 2 - PACK$ ;  ( copy parsed string to word buffer )

: WORD ( c -- a ; <string> ) ( Parse a word from input stream and copy it to code dictionary.)
  PARSE         ( parse out a string delimited by c )
  HERE PACK$ ;  ( copy the string into the word buffer )
`);
//TODO-TEST TODO-OUTPUT test .(
test('1 2 ( 3 ) 4 \\ commenting', [1, 2, 4]);
test('TOKEN xxx C@', [3]);
test('BL WORD yyyy DUP C@ SWAP CP @ -', [4, 0]);

// === Dictionary Search pg75-77 NAME> SAME? find NAME?
constant('=COMP', bitsCOMP); // Compile only word - TODO figure out how used EFORTH-ERRATA used but not defined
constant('=IMED', bitsIMED); // Immediate word - interpreted during compilation EFORTH-ERRATA used but not defined
constant('=MASK', bitsMASK); // EFORTH-ERRATA used but not defined

interpret('BL WORD TOKEN CONTEXT @ find SWAP'); const testFind = [SPpop(), SPpop()]; // Get results from old find
interpret(`
: NAME> ( na -- ca )
  ( Return a code address given a name address.)
  2 CELLS - ( move to code pointer field ) 
  @ ; ( get code field address )

: SAME? ( a1 a2 u -- a1 a2 f \\ -0+ )
  ( Compare u cells in two strings. Return 0 if identical.)
  FOR               ( scan u+1 cells )
    AFT             ( skip the loop the first time )
      OVER          ( copy a1 )
      R@ CELLS + @  ( fetch one cell from a1)
      OVER          ( copy a2 )
      R@ CELLS + @  ( fetch one cell from a2)
      -             ( compare two cells )
      ?DUP
      IF            ( if they are not equal )
        R> DROP     ( drop loop count )
        EXIT        ( and exit with the difference as a flag )
      THEN
    THEN
  NEXT              ( loop u times if strings are the same )
  0 ;               ( then push the 0 flag on the stack )

: find ( a va -- ca na, a F )
  ( Search a vocabulary for a string. Return ca and na if succeeded.)
  SWAP                ( va a )
  DUP C@ CELLL / temp !   ( va a -- , get cell count ) ( EFORTH-ERRATA was '2 /'
  DUP @ >R            ( va a -- , save 1st cell of string )
  CELL+ SWAP          ( a' va -- , compare string with names )
  BEGIN               ( fast test, compare only 1st cells )
    @ DUP             ( a' na na -- )
    ( debugNA )       ( uncomment for debugging find - will report each name as checked)
    IF                ( na=0 at the end of a vocabulary )
      DUP @           ( not end of vocabulary, test 1st cell )
      [ =MASK ] LITERAL AND ( mask off lexicon bits )
      R@ XOR          ( compare with 1st cell in string )
      IF              ( 1st cells do not match )
        CELL+ -1      ( try the next name in the vocabulary )
      ELSE CELL+      ( get address of the 2nd cell )
        temp @        ( get the length of string )
        SAME?         ( string=name? )
      THEN
    ELSE              ( end of vocabulary )
      R> DROP         ( discard the 1st cell )
      SWAP CELL- SWAP ( restore the string address )
      EXIT            ( exit with ca na, na=0 is false flag )
    THEN
  WHILE               ( if the name does not match the string )
    CELL- CELL-       ( a' la --, move to next word in vocab)
  REPEAT              ( repeat until vocabulary is exhausted )
  R> DROP NIP         ( a match is found, discard 1st and va )
  CELL-               ( restore name field address )
  DUP NAME>           ( find code field address )
  SWAP ;              ( reorder and return.  -- ca na )

: NAME? ( a -- ca na, a F )
  ( Search all context vocabularies for a string.)
  CONTEXT       ( address of context vocabulary stack )
  DUP 2@ XOR    ( are two top vocabularies the same? )
  IF            ( if not same )
    1 CELLS -   ( backup the vocab address for looping )
  THEN
  >R            ( save the prior vocabulary address )
  BEGIN
    R> CELL+    ( get the next vocabulary address )
    DUP >R      ( save it for next vocabulary )
    @ ?DUP      ( is this a valid vocabulary? )
  WHILE         ( yes)
    find        ( find the word in this vocabulary )
    ?DUP        ( word found here? )
  UNTIL         ( if not, go searching next vocabulary )
    R> DROP EXIT ( word is found, exit with ca and na )
  THEN
  R> DROP       ( word is not found in all vocabularies )
  0 ;           ( exit with a false flag )
`);
//NAME> implicitly tested by find
test('BL WORD xxx DUP C@ 1 + PAD SWAP CMOVE PAD BL WORD xxx 4 SAME? >R 2DROP R>', [0]);
test('BL WORD xxx DUP C@ 1 + PAD SWAP CMOVE PAD BL WORD xzx 4 SAME? >R 2DROP R> 0=', [0]);
test('FORTH', []);
test('BL WORD TOKEN CONTEXT @ find', testFind.map(k=>k)); // Compare with results from old version of find
test('BL WORD TOKEN NAME?', testFind); // Name searches all vocabs

// === Text input from terminal pg 78: ^H TAP kTAP accept EXPECT QUERY
// EFORTH-ERRATA CTRL used here but not defined.
interpret(`
: ^H ( bot eot cur -- bot eot cur)
  ( Backup the cursor by one character.)
  >R OVER     ( bot eot bot --)
  R@ < DUP    ( bot<cur ? )
  IF [ CTRL H ] LITERAL ( yes, echo backspace )
    'ECHO @EXECUTE 
  THEN        ( bot eot cur 0|-1 -- )
  R> + ;      ( decrement cur, but not passing bot )

: TAP ( bottom eot currrent key -- bottom eot current )
  ( Accept and echo the key stroke and bump the cursor.)
  DUP         ( duplicate character )
  'ECHO @EXECUTE ( echo it to display )
  OVER C!     ( store at current location )
  1 + ;       ( increment current pointer )

: kTAP ( bot eot cur key -- bot eot cur )
  ( Process a key stroke, CR or backspace.)
  DUP 13 XOR        ( is key a return?)
  IF [ CTRL H ] LITERAL ( is key a backspace? )
    XOR IF BL TAP   ( none of above, replace by space )
    ELSE ^H         ( backup current pointer )
    THEN
    EXIT            ( done this part )
  THEN              ( key is a return)
  DROP              ( discard bot and eot )
  NIP DUP ;         ( duplicate cur )

: accept ( b u -- b u )
  ( Accept characters to input buffer. Return with actual count.)
  OVER + OVER       ( b b+u b;  EFORTH-ERRATA fixed in v5 and STAAPL)
  BEGIN 
    2DUP XOR        ( b b+u b b=b+u = current pointer? )
  WHILE
    KEY             ( b b+u b c; get one more character )
    DUP BL - 95 U<  ( b b+u b c f; is it printable? ) 
    IF TAP          ( b b+u b+1 ; yes, accept and echo it )
    ELSE 'TAP @EXECUTE ( no, process control code )
    THEN
  REPEAT            ( b b+u b'; repeat until buffer full )
  DROP              ( b b+u ; drop current pointer
  OVER - ;          ( b u; leave actual count)

: EXPECT ( b u -- ) 
  ( Accept input stream and store count in SPAN.)
  'EXPECT @EXECUTE  ( execute accept )
  SPAN !            ( store character count in SPAN )
  DROP ;            ( discard eot address )

: QUERY ( -- )
  ( Accept input stream to terminal input buffer.)
  TIB 80          ( addr and size of terminal input buffer)
  'EXPECT @EXECUTE ( execute 'accept' )
  #TIB !          ( store number of characters received )
  DROP            ( discard buffer address )
  0 >IN ! ;       ( initialized parsing pointer )
`);
// TODO-TEST TODO-IO input handlign needs EXPECT etc

// Error Handling pg80-82 CATCH THROW NULL$ ABORT abort" ?STACK
interpret(`
: CATCH ( ca -- err#/0 )
  ( Execute word at ca and set up an error frame for it.)
  SP@ >R          ( save current stack pointer on return stack )
  HANDLER @ >R    ( save the handler pointer on return stack )
  RP@ HANDLER !   ( save the handler frame pointer in HANDLER )
  ( ca ) EXECUTE  ( execute the assigned word over this safety net )
  R> HANDLER !    ( normal return from the executed word )
                  ( restore HANDLER from the return stack )
  R> DROP         ( discard the saved data stack pointer )
  0 ;             ( push a no-error flag on data stack )

: THROW ( err# -- err# )
  ( Reset system to current local error frame and update error flag.)
  HANDLER @ RP! ( expose latest error handler frame on return stack )
  R> HANDLER !  ( restore previously saved error handler frame )
  R> SWAP >R    ( retrieve the data stack pointer saved )
  SP!           ( restore the data stack )
  DROP 
  R> ;          ( retrieved err# )
                        
CREATE NULL$ 0 , ( EFORTH-ERRATA inserts a string "coyote" after this, no idea why! )

: ABORT ( -- ) 
  ( Reset data stack and jump to QUIT.)
  NULL$   ( take address of NULL$ )
  THROW ; ( and give it to current CATCH )

: abort" ( f -- )
  ( Run time routine of ABORT" . Abort with a message.)
  IF        ( if flag is true, abort ) 
    do$     ( take address of next string )
    THROW   ( and give it to CATCH )
  THEN      ( if flag is false, continue )
  do$ DROP  ( skip over the next string ) 
  ;  COMPILE-ONLY
  
: $," ( --) ( Moved earlier from pg90)
  ( Compile a literal string up to next " .)
  34 WORD ( move string to code dictionary)
  COUNT + ALIGNED ( calculate aligned end of string)
  CP ! ; ( adjust the code pointer)

( Moved earlier from pg93 )
: ABORT" ( -- ; <string> )
  ( Conditional abort with an error message.)
  COMPILE abort"  ( compile runtime abort code ) 
  $," ; IMMEDIATE ( compile abort message )

( Moved earlier from pg93 )
: ." ( -- ; <string> )
  ( Compile an inline string literal to be typed out at run time.) 
  COMPILE ."| ( compile print string code )
  $," ; IMMEDIATE ( compile print string )
`);
// Test is tricky - the "3" in bar is thrown away during hte "THROW" while 5 is argument to THROW
test(`: bar 3 5 THROW 4 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo`, [1, 5, 2]); debugStack=[];
test(`: bar 3 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo`, [1, 3, 0, 2]);
// Note that abort restores the stack, so shouldn't have consumed something else will have random noise on stack
test(`: bar ?DUP ABORT" test" 3 ; : foo [ ' bar ] LITERAL CATCH ; 1 foo C@ 0 foo`, [1, 4, 3, 0]); debugStack=[];
//$," and abort" are implicitly tested by ABORT"
//TODO-TEST TODO-IO test ."

// === Text Interpreter loop pg83-84 $INTERPRET [ .OK ?STACK EVAL
interpret(`

: $INTERPRET ( a -- )
  ( Note jsINTERPRET has same signature as this except for THROW
  ( Interpret a word. If failed, try to convert it to an integer.)
  NAME?                   ( search dictionary for word just parsed )
  ?DUP                    ( is it a defined word? )
  IF C@                    ( yes. examine the lexicon ) ( EFORTH-ERRATA it should be C@ not @)
    [ =COMP ] LITERAL AND ( is it a compile-only word? )
    ABORT" compile ONLY"  ( if so, abort with the proper message )
    EXECUTE EXIT          ( not compile-only, execute it and exit ) 
  THEN                    ( not defined in the dictionary )
  'NUMBER @EXECUTE        ( convert it to a number ) ( TODO-NUMBER-5 merge with number in js)
  IF EXIT THEN            ( exit if conversion is successful )
  THROW ;                 ( else generated the error condition )

: .OK ( -- ) 
  ( Display 'ok' only while interpreting.)
  [ ' $INTERPRET ] LITERAL
  'EVAL @ = 
  IF ."  ok" THEN CR ;

: ?STACK ( -- ) 
  ( Abort if the data stack underflows.)
  DEPTH 0< ABORT" underflow" ; ( Note staapl uses $" THROW, v5 uses ABORT)

: EVAL ( -- )
  ( Interpret the input stream.)
  BEGIN 
    TOKEN ( -- a)   ( parse a word and leave its address )
    DUP C@          ( is the character count 0? )
  WHILE             ( no )
    'EVAL @EXECUTE  ( evaluate it )
    ?STACK          ( any stack error? overflow or underflow )
  REPEAT            ( repeat until TOKEN gets a null string )
  DROP              ( discard the string address )
  'PROMPT @EXECUTE ;  ( display the proper prompt, if any )
`);
//TODO-TEST TODO-IO .OK EVAL

test('BL PARSE 123 PAD PACK$ $INTERPRET', [123]);
test('123 BL PARSE DUP PAD PACK$ $INTERPRET', [123, 123]);
test(`: foo 1 2DROP ?STACK ; : bar [ ' foo ] LITERAL CATCH ; bar C@`, [9]); debugStack=[]; // "underflow"

// This switches to use new interpreter, its still using old jsCOMPILE
interpret(`
: [ ( -- )
  ( Start the text interpreter.) ( Replaces JS version )
  [ ' $INTERPRET ] LITERAL 
  'EVAL !                   ( store $INTERPRET in 'EVAL )
  ; IMMEDIATE               ( must be done even while compiling )
`);
test('[ 1 2 3 ROT', [2, 3, 1]);
// TODO - need to check places do EXECUTE and then anywhere else does threadtoken as won't work with colon words
// Operating System pg85-86 PRESET XIO FILE HAND I/O CONSOLE QUIT
// eForth Compiler pg 87
// Interpreter and Compiler pg 88-90: [ ] ' ALLOT , [COMPILE] COMPILE LITERAL $," RECURSE
// Control Structures pg91-92: FOR BEGIN NEXT UNTIL AGAIN IF AHEAD REPEAT THEN AFT ELSE WHILE
// String Literals pg93: ABORT" $" ." ( ABORT" ." moved to pg84 where used )
// Name Dictionary Compiler pg94-96: ?UNIQUE $,n $COMPILE OVERT ; ] call, : IMMEDIATE  (see dollarCommaN)
// Defining Words pg97: USER CREATE VARIABLE
// Utilities pg98
// Memory Dump pg99 _TYPE do+ DUMP
// Stack Dump pg100 .S
// Stack Checking pg101 !CSP ?CSP
// Dictionary Dump pg102 .ID WORDS
// Search Token Name pg103 >NAME
// The simplest Decompiler pg104 SEE
// Signon Message pg105 VER hi
// Hardware Reset pg106 COLD

// TESTING ===
run(name2xt('FORTH'));
console.log('Finished:');
