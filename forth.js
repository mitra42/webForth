/*
References eForthAndZen 1013_eForthAndZen.pdf -- TODO need URL
 */

// TODO-VM make this something passed to each function.
// Standard pointers used (ref eForthAndZen pg22
let IP = 0;  // Interpreter Pointer
let SP = 0;  // Data Stack Pointer
let RP = 0;  // Return Stack Pointer (aka BP in 8086)
let WP = 0;  // Word or Work Pointer
let UP = 0;  // User Area Pointer

// EFORTH-DIFF difference to eForth in using indirect threaded code as makes more sense in JS

// TODO review eForth Word Set at eForthAndZen pg 25 and check all implemented

// eForthAndZen pg 26

// === Memory Map - pg26
// TODO-VM TODO-MEM rework this into separate slots and then check if really need ! and @ into some parts of mem
// EFORTH-ERRATA doesnt define CELLL (and presumes is 2 in multiple places)
const CELLL = 2;  // Using Buffers, but needs to be 2 as needs to be big enough for an address (offset into buffer) if change see CELL+ CELL- CELLS ALIGNED $USER
const EM = 0x4000; // top of memory
const COLDD = 0x100; // cold start vector
const US = 64 * CELLL;  // user area size in cells i.e. 64 variables
const RTS = 64 * CELLL; // return stack/TIB size
const RPP = EM - (8 * CELLL); // start of return stack RP0 // looks really small at depth of 8
const TIBB = RPP - RTS; // Terminal input buffer
const SPP = TIBB - (8 * CELLL); // start of data stack - bottom down, points at top of stack
const UPP = EM - (256 * CELLL); // start of user area
const NAMEE = UPP - (8 * CELLL); // name dictionary
const CODEE = COLDD + US; // code dictionary

const m = Buffer.alloc(EM); // Allocate as one big buffer for now. TODO-MEM redo as a struct of some sort or poss u16 array
const codeSpace = []; // Maps tokens to executable functions
const userInit = [0,0,0,0]; // Used for initialization of user variables - for now not in m as would be in ROM normally
const names = {}; // TODO-INTERPRETER make sure to empty this after no longer need $COLON $CODE etc

// These aren't part of eForth, but are needed when SP is a variable rather than a register
function SPfetch() { return (m[SP] << 8) | m[SP + 1]; }
function SPpop() { return (m[SP++] << 8) | m[SP++]; }
function SPpush(u16) { m[--SP] = u16 & 0xFF; m[--SP] = (u16 >> 8); }
function RPfetch() { return (m[RP] << 8) | m[RP + 1]; }
function RPpop() { return (m[RP++] << 8) | m[RP++]; }
function RPpush(u16) { m[--RP] = u16 & 0xFF; m[--RP] = (u16 >> 8); }
function IPnext() { return (m[IP++] << 8) | m[IP++]; }
function Mstore(a, v) { m[a++] = v >> 8; m[a] = v & 0xFF; }
function Mfetch(a) { return (m[a++] << 8) | m[a];}

// Handle the Code pointer, which always points after last thing compiled into dictionary - in eForthAndZen this is "$"

const CPoffset = 68; // This value is checked during the sequence of USER below

function cpFetch() {
  return Mfetch(UPP+CPoffset);
}
function cpStore(w) {
  Mstore(UPP+CPoffset, w);
}

cpStore(CODEE); // Pointer to where compiling into dic TODO-MEM will be code.length

// === ASSEMBLY MACROS (or JS equivalent) pg 30
// TODO_VM will prob need to be inside "vm"
let _LINK = 0; // force null link
let _NAME = NAMEE; // initialize name pointer
let _CODE = CODEE; // initialize code pointer - points at start of last word defined (CP points to top of dict)
let _USER = 4 * CELLL; // first user variable offset, skips 4 variables used by multitasking

function $ALIGN() {} // Not applicable since using a byte Buffer

function $DW(...words) { // Forth presumes big-endian, high word stored at low memory address (which is above on stacks)
  for(word of words) {
    if (typeof word === "string") {
      w = names[word];
      if (!w) { console.error('Cant find',word)}
    } else {
      w = word;
    }
    let cp = cpFetch();
    m[cp++] = w >> 8;
    m[cp++] = w & 0xFF;
    cpStore(cp);
  }
}

let lastDefinition;

function $CODE(lex, name) { //TODO-CELL check this carefully
  //TODO-EPRECORE extract name baking part of this
  $ALIGN();
  // Note this is going to give the name string an integral number of cells.
  const _LEN = (lex & 0x01F) / CELLL; // Truncate name length in cells TODO-CELL probably in bytes not cells
  _NAME -= ((_LEN + 3) * CELLL); // Drop down from top // CELL I think its _LEN + 3*CELLL
  let a = _NAME;
  let cp = cpFetch();
  m[a++] = cp >> 8;
  m[a++] = cp & 0xFF;
  m[a++] = _LINK >> 8;
  m[a++] = _LINK & 0xFF;
  _LINK = a; // Pointer for next word in dic
  m[a++] = lex;
  a += m.write(name, a, 'utf8');
  lastDefinition = cp; //TODO rework when have lex
  if (names[name])
    console.log(!names[name], "Duplicate definition of", name); // Catch duplicates - probably an error
  names[name] = cp;  // To allow compiling of names before have "FIND"
}

// eForthAndZen 31
// tokenFunction defines a function, puts a pointer to it in codeSpace and returns the token that should be in the dict
function tokenFunction(func) {
  const x = codeSpace.length;
  codeSpace.push(func);
  return x;
}

const tokenDoList = tokenFunction((payload) => {
  RPpush(IP); IP = payload; }); // Note same code on tokenDoes

function $COLON(name) {
  let xt = cpFetch();
  $CODE(name.length, name);
  $DW(tokenDoList);
  return xt;
}

const tokenUser = tokenFunction(payload => SPpush(Mfetch(payload)+UPP));

function $USER(name) { // Note unlike eForth we use Token threading see USER() which also initialized
  if (name) {
    $CODE(name.length, name);
    $DW(tokenUser, _USER);
  }
  _USER += CELLL; // Need to skip to next _USER in either case
}
// tokenNextVal TODO define VARIABLE and CONSTANT to use this
const tokenNextVal = tokenFunction(payload => SPpush(Mfetch(payload)));

function D$(funct, string) {
  $DW(funct, string.length);
  let cp = cpFetch()
  cp +=  m.write(string, cp, 'utf8');
  cpStore(cp);
  $ALIGN();
}
function $NEXT() {
  $DW(EXIT);
}
function initRegisters() {
  SP = SPP;
  RP = RPP;
}
function doCOLDD() {
  initRegisters();
  COLD(); // TODO-EPRECORE should run the inner interpreter on COLD
}
function code(name, func) {
  let xt = cpFetch();
  $CODE(name.length, name);
  $DW(tokenFunction(func));
  return xt;
}
//User variables initialization eForthAndZen pg33 see pg46

// Basic key I/O eForthAndZen pg 35
code('BYE', 'TODO-bye');
code('?RX', () => console.error('TODO ?RX not defined')); //TODO-IO
code('TX!', () => console.error('TODO TX! not defined')); //TODO-IO
code('!IO', () => console.error('TODO !IO not defined')); //TODO-IO
/* TODO-IO FAILED attempt to get stdin/stdout IO then code
var stream = require('stream');
var s = stream.Duplex()
function foo() {
  chunk = null;
  let i = 1000;
  while(!chunk) {
    //console.log("preread");
    chunk = s.read(1)
    if (chunk && chunk.length) { console.log("Saw chunk of len",chunk.length); }
    //console.log("Looping");
  }
  console.log("OutOLoop");
};
foo();
process.stdin.setEncoding('ascii');
process.stdin.pipe(s).pipe(process.stdout);
console.log("exited");
*/

/** ===================================================
 * INNER INTERPRET === YES THIS IS IT ! eForthAndZen#36
 * This is quite different from eForth as its threaded token
 */

// == INNER INTERPRETER - loops through nesting
function threadtoken(xt) {
  console.log(Object.entries(names).filter(kv => kv[1] === xt)[0][0], "S:",m.slice(SP,SPP),"R:",m.slice(RP,RPP));
  const tok = ((m[xt++] << 8) + m[xt++]);
  codeSpace[tok](xt);
}
function run(xt) {
  threadtoken(xt);
  // If this returns without changing program Counter, it will exit
  while (IP) {
    xt = IPnext(); // SEE-OTHER-ENDIAN
    threadtoken(xt);
  }
}
const EXIT = code('EXIT', () => IP = RPpop()); // SEE-OTHER-ENDIAN
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
code('SP@', SPpush(SP));
code('SP!', SP = SPpop());

// Classic Data stack words eForthAndZen#42
code('DROP', () => SP += 2);
code('DUP', () => SPpush(SPfetch()));
code('SWAP', () => { const x = SPpop(); const y = SPpop(); SPpush(x); SPpush(y); });
code('OVER', () => { const x = SPpop(); const y = SPfetch(); SPpush(x); SPpush(y); }); // TODO optimize

// Logical Words eForthAndZen43
code('0<', () => SPpush((SPpop() < 0) ? -1 : 0));
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
  userInit.push((typeof init === 'string') ?  names[init] : init);
}

USER('SP0', SPP); // (--a) Pointer to bottom of the data stack.
USER('RP0', RPP); // (--a) Pointer to bottom of the return stack.
USER("'?KEY", '?RX'); // Execution vector of ?KEY. Default to ?rx.
USER("'EMIT", 'TX!');  // Execution vector of EMIT. Default to tx!
USER("'EXPECT", 'accept'); // Execution vector of EXPECT. Default to 'accept'.
USER("'TAP", undefined); // TODO KTAP Execution vector of TAP. Default the kTAP.
USER("'ECHO", 'TX!'); // Execution vector of ECHO. Default to tx!.
USER("'PROMPT", undefined); // TODO DOTOK Execution vector of PROMPT.  Default to '.ok'.
const baseOffset = _USER;
USER("BASE", 10); // TODO BASEE Storage of the radix base for numeric I/O. Default to 10.
USER('temp', 0); // A temporary storage location used in parse and find. EFORTH-ERRATA its uses as 'temp', listing says 'tmp'
USER('SPAN', 0); // Hold character count received by EXPECT.
USER('>IN', 0); // Hold the character pointer while parsing input stream.
USER('#TIB', 0); // Hold the current count and address of the terminal input buffer.
USER(undefined, TIBB); // Terminal Input Buffer used one cell after #TIB.
USER('CSP', 0); // Hold the stack pointer for error checking.
USER("'EVAL", undefined); // TODO INTER Execution vector of EVAL. Default to EVAL.
USER("'NUMBER", undefined); // TODO NUMBQ Execution vector of number conversion. Default to NUMBER?.
USER('HLD', 0); // Hold a pointer in building a numeric output string.
USER('HANDLER', 0); // Hold the return stack pointer for error handling.
USER('CONTEXT', 0); // A area to specify vocabulary search order. Default to FORTH. Vocabulary stack, 8 cells following CONTEXT.
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0); // Always 0 to indicate no more valid Vocabularies
USER('CURRENT', 0); // Point to the vocabulary to be extended. Default to FORTH.
USER(undefined, 0); // Vocabulary link uses one cell after CURRENT.
console.assert(_USER === CPoffset, "CP mismatch offset should be ",_USER); // This is checked because need to know this earlier
USER('CP', cpFetch()); // eForth initializes to CTOP but we have to use this during compilation
USER('NP', undefined); // TODO NTOP Point to the bottom of the name dictionary. see pg 106
USER('LAST', undefined); // TODO LASTN Point to the last name in the name dictionary. see pg 106

// === JS interpreter - will be discarded when done or built out
let compiling = false; // TODO-INTERPRET replace with appropriate state flag

const immediateTokens = []; // TODO-INTERPRET discard this at end
code('IMMEDIATE', () => immediateTokens.push(lastDefinition)); // TODO-INTERPRETER replace with real IMMEDIATE in lex

let input;

function consumeWord() { // TODO-INTERPRET replace this with guts of Forth word equivalent
  let w;
//    [w, this.input] = this.input.trim().split(/\s(.*)/);
  [w, input] = input.trim().split(/(?<=^\S+)\s/);
  return w;
}

function userVal(name) {
  return Mfetch(UPP+Mfetch(names[name]+2));
}
// Look up a name, return [xt, 1] if immediate, [xt -1] if not, [name, 0] if not found.
function find(name) { // TODO-INTERPRET merge into Forth word "FIND" - needs counted strings
  const n = names[name];
  if (n) {
    return [n, immediateTokens.includes(n) ? 1 : -1]
  } else {
    return [name, 0]
  }
}

function jsNUMBER(w) {
  const base = userVal("BASE");
  const n = parseInt(w, base); // TODO-NUM handle parsing errors // Needs forth to convert word
  if (isNaN(n)) {
    console.error('Not found', w);
  } else {
    return n;
  }
}
function jsCOMPILE(w) {
  const [xt, found] = find(w);
  if (found === 1) {
      run(xt);
  } else if (found) {
      $DW(xt);
  } else {
    $DW('doLIT', jsNUMBER(w));
  }
}
function jsINTERPRET(w) {
  const [xt, found] = find(w);
  if (found) {
    run(xt);
  } else {
    SPpush(jsNUMBER(w));
  }
}
function interpret(inp) {
  input = inp; // Could point at TIB
  let w;
  while (input && input.length) {
    w = consumeWord(input);
    console.log('>', w); //TODO comment out
    if (compiling) {
      jsCOMPILE(w);
    } else {
      jsINTERPRET(w);
    }
  }
}
initRegisters(); //TODO-TEST maybe need to move initRegisters

// === A group of words defined relative to the JS interpreter but will be redefined to the Forth interpreter at pg TODO
code(':', () => { $COLON(consumeWord()); compiling = true; }); // TODO-INTERPRETER Replace with : ':' TOKEN $,n [ ' doLIST ] LITERAL CALL, ] ;
code(';', () => { $DW(EXIT); compiling = false; }); // TODO-INTERPRETER replace with deftn of ;
interpret('IMMEDIATE');
code('(', () => input = input.split(/(?<=^[^\)]+)\)/)[1]); interpret('IMMEDIATE'); //pg74
code('[', () => compiling = false); interpret('IMMEDIATE'); //pg84 and pg88
code(']', () => compiling = true); // pg88
code('CHAR',() => SPpush(consumeWord()[0]))

// === Vocabulary and Sort Order eForthAndZen pg47

// EFORTH-DIFF with direct threaded code makes sense to put function, prefer here to use a tokenized Does>

//TODO doesnt belong here as not used for FORTH - move to defntn of CREATE DOES>
//tokenDoes = tokenFunction(payload => { RPpush(IP); IP = (m[payload++]<<8)+m[payload++]; SPpush(payload++); ); // Almost same as tokenDoList

//TODO define VOCABULARY as CREATE DOES> word
interpret(': doVOC R> CONTEXT ! ;');
$COLON('FORTH'), $DW('doVOC', 0, 0);
// $DW(tokenDoes, (first word of doVOC), 0, 0);

// === Words moved earlier ....

// Comment character - from here on we can use ( xxx) in interpreted strings
// pg74 : ( [ CHAR ) ] LITERAL PARSE 2DROP ; IMMEDIATE

interpret(`: HERE ( -- a; return top of code dictionary; pg60)
  CP @ ;`);

$CODE(5, 'CELLL'), $DW(tokenNextVal, CELLL); // effectively '2 CONSTANT CELLL' but dont have CONSTANT at this point

console.assert(CELLL <= 2); // Assuming small cell, otherwise it should be 2
// Note eForth has +, but that isn't defined till pa50
interpret(": CELL+ CELLL UM+ DROP ;");

// pg89 : ' ( -- ca ) TOKEN NAME? IF EXIT THEN THROW ;
code("'", () => { // -- xt; Search for next word in input stream
                  // TODO-RECODE as WORD FIND NOT IF ERROR THEN needs WORD FIND ERROR reqs FIND
  const w = consumeWord();
  const [xt, found] = find(w);
  if (found) { // immediate or not
    SPpush(xt);
  } else {
    console.error(w, "not found during '");
  }
});
interpret(`
: , HERE ( w --; Compile an integer into the code dictionary. pg 90)
  DUP CELL+ CP ! ! ; 
: [COMPILE] ( --; <string>; Compile next immediate word into code dictionary; pg90)
  ' , ; IMMEDIATE 
: COMPILE ( --; Compile the next address in colon list to code dictionary. pg 90)
  R> DUP @ , CELL+ >R ;
`);
// == Control structures - were on pg91 but needed earlier pg 91-92 but moved early
interpret(`
: FOR ( -- a; Start a FOR-NEXT loop structure in a colon definition)
  COMPILE >R HERE ; IMMEDIATE
`); interpret(`
: BEGIN ( -- a ; Start an infinite or indefinite loop structure)
  HERE ; IMMEDIATE ( push HERE for later ref. )
`); interpret(`
: NEXT ( a --; Terminate a FOR-NEXT loop structure)
  COMPILE next , ; IMMEDIATE
`); interpret(`
: UNTIL ( a -- ; Terminate a BEGIN-UNTIL indefinate loop structure )
  COMPILE ?branch , ; IMMEDIATE
`); interpret(`
: AGAIN ( a -- ; Terminate a BEGIN-AGAIN infinite loop structure )
  COMPILE branch , ; IMMEDIATE
( TODO interpret 'COMPILE-ONLY' - how is COMPILE-ONLY used, where does it set flags?)
`); interpret(`
: IF ( -- A; begin conditional branch structure pg 92)
  COMPILE ?branch HERE 0 , ; IMMEDIATE
`); interpret(`
: AHEAD ( -- A; compile a forward branch instruction. pg  92)
  COMPILE branch HERE 0 , ; IMMEDIATE
`); interpret(`
: REPEAT ( A a -- ; Terminate BEGIN-WHILE-REPEAT loop )
  [COMPILE] AGAIN HERE SWAP ! ; IMMEDIATE
`); interpret(`
: THEN ( A --; terminate conditional branch structure pg 92)
  HERE SWAP ! ; IMMEDIATE
`); interpret(`
: AFT ( a -- a A ; Jump to THEN in a FOR-AFT-THEN-NEXT loop the first time through. pg92)
  DROP            ( discard address left by IF )
  [COMPILE] AHEAD ( compile uncondition jump )
  [COMPILE] BEGIN ( leave HERE on stack )
  SWAP ;          ( realign jump addresses )
`); interpret(`
: ELSE ( A -- A; False clause of IF ELSE THEN structure pg 92)
  [COMPILE] AHEAD SWAP [COMPILE] THEN ; IMMEDIATE
`); interpret(`
: WHILE ( a -- A a ; Conditional branch out of a BEGIN-WHILE-REPEAT loop.) 
  [COMPILE] IF
  SWAP ; IMMEDIATE
`);
// === Multitasking pg48 - not implemented in eForth TODO

// === More Stack Words pg49
interpret(`
: ?DUP DUP IF DUP THEN ; ( w--ww|0) ( Dup top of stack if its is not zero.)
: ROT >R SWAP R> SWAP ; ( w1, w2, w3 -- w2 w3 w1; Rotate third item to top)
: 2DROP DROP DROP ; ( w1 w2 -- ; Drop two items)
: 2DUP OVER OVER ; ( w1 w2 -- w1 w2 w1 w2;)
`);

// === More Arithetic operators pg50
interpret(`
: + UM+ DROP ; ( w1 w2 -- w1+w2)
: D+ >R SWAP >R UM+ R> R> + + ; ( d1 d2 -- d1+d2)
: INVERT -1 XOR ; ( w -- w; 1's compliment)
( NOT's meaning is deprecated use 0= or INVERT bitwise see http://lars.nocrew.org/forth2012/core/INVERT.html)
: NEGATE INVERT  1 + ; ( w -- w; 2's complement)
: DNEGATE INVERT >R INVERT  1 UM+ ;
: - NEGATE + ; ( n1 n2 -- n1-n2)
: ABS DUP 0< IF NEGATE THEN ; ( n -- n; Absolute value of w)
`);
// More comparisom pg51-52
interpret(`
: = XOR IF 0 EXIT THEN -1 ; ( w w -- t)
: U< 2DUP XOR 0< IF SWAP DROP 0< EXIT THEN - 0< ;
: < 2DUP XOR 0< IF DROP 0< EXIT THEN - 0< ;
: MAX 2DUP < IF SWAP THEN DROP ;
: MIN 2DUP SWAP < IF SWAP THEN DROP ;
: WITHIN OVER - >R - R> U< ;
`);
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

// === Memory Alignment words pg57 CELL+ CELL- CELLS ALIGNED
/*
( CELL+ is moved earlier)
: CELL+ ( a -- a)
  ( Add cell size in byte from address )
  CELLL + DROP ;  ( eForth uses '2 +' which is wrong unless CELL is "2" )
*/
interpret(`
: CELL- ( a -- a)
  ( Subtract cell size in byte from address)
  CELLL - ;

: CELLS ( n - n )
  ( Multiply n by cell size in bytes)
  CELLL * ;
`);

/* EFORTH-ERRATA - pg57 presumes CELLL==2 and need to align, not case with JS and byte Buffer
: ALIGNED ( b -- a)
  ( Align address to the cell boundary)
  DUP 0 CELLL UM/MOD    ( divide b by 2)
  DROP DUP          ( save remainder)
  IF CELLL SWAP - THEN  ( add 1 if remainder is 1)
  + ;
*/
interpret(': ALIGNED ;');

// === Special Characters pg58 BL >CHAR
interpret(`
: BL ( -- 32; the blank character)
  32 ;

: >CHAR ( c -- c; filter non printing characters, replace by _)
  127 AND DUP   ( maso off the MSB bit)
  127 BL WITHIN ( if its a control character)
  IF DROP 95 THEN ; ( replace with an underscore)
`);
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
: TIB ( -- a; Return address of terminal input buffer) ( TODO replace "input" with this)
  #TIB CELL+ @ ; ( 1 cell after #TIB)
: @EXECUTE ( a -- ; excute vector -if any- stored in address a)
  @ ?DUP IF EXECUTE THEN ;
`);

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

: PACK$ ( b u a -- a; Build a counted string with u characters from b. Null fill.)
  DUP >R      ( save address of word buffer )
  2DUP C!     ( store the character count first )
  1 + 2DUP +  ( go to the end of the string)
  0 SWAP !    ( fill the end with 0's )
  SWAP CMOVE  ( copy the string over )
  R> ;        ( leave only word buffer address )
`);
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

// Number formating pg65 <# HOLD #S SIGN #>
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

: #> ( w -- b u ; Prepare the output string to be TYPE'd.)
  DROP          ( discard w)
  HLD @         ( address of last digit)
  PAD OVER - ;  ( return address of 1st digit and length)
`)
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

: . ( w--; Display an integer in free format, preceeded by a space.)
  BASE @ 10 XOR     ( if not in decimal mode)
  IF U. EXIT THEN   ( print unsigned number)
  str SPACE TYPE ;  ( print signed number if decimal)
  
: ? ( a -- ; Display the contents in a memory cell.)
  @ . ; ( very simple but useful command)

`);
// === Numeric input pg67-68 DIGIT? NUMBER?
// eFORTH-ERRATA NIP isnt designed
interpret(`
: NIP ( x1 x2 -- x2 ) 
  SWAP DROP ;
: DIGIT? ( c base -- u t ; Convert a character to its numeric value. A flag indicates success.) 
  >R                    ( save radix )
  48 -          ( character offset from digit 0 - would be better as '[ CHAR 0 ] LITERAL' but dont hace "[")
  9 OVER <              ( is offset greater than 9? )
  IF 7 -                ( yes. offset it from digit A )
    DUP                 ( n n )
    10 <                ( if n<10, the flag will be -1, and )
    OR                  ( OR with n, result will be -1 )
  THEN                  ( if n>10, the flag will be 0 and )
  DUP                   ( OR result will still be n )
  R> U< ;               ( if n=/>radix, the digit is not valid )

( TODO evaluate control structures here)
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
// === Derived I/O pg70 PACE SPACE SPACES TYPE CR
interpret(`
: PACE ( --) ( Send a pace character for the file downloading process.)
  11 EMIT ; ( 11 is the pace character)
( SPACE and SPACES and TYPE moved earlier)
: CR ( --) ( Output carriage return line feed)
  15 EMIT 11 EMIT ;
`)
// === String Literal pg71 do$ $"| ."|
interpret(` 
: do$ ( --a) ( Return the address of a compiled string.)
  R>    ( this return addres must be preserved)
  R@    ( get address of the compiled string)
  R>    ( get another copy)
  COUNT + ALIGNED >R  ( replace it with addr after string)
  SWAP  ( get saved address to top)
  >R ;  ( restore the saved retrun address)

: $"| ( -- a) ( Run time routine compiled by $". Return address of a compiled string.)
  do$ ; ( return string address only)
: ."| ( -- ) ( Run time routine of ." . Output a compiled string.) 
  do$           ( get string address)
  COUNT TYPE ;  ( print the compiled string)
`);
// === Word Parser pg72-73 PARSE parse
interpret(`

: parse ( b u c -- b u delta ; <string> ) ( TODO evaluate control structures here)
  ( Scan string delimited by c. Return found string and its offset.
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
      NEXT            ( b -- , if space, loop back and scan further)
        R> DROP       ( end of buffer, discard count )
        0 DUP EXIT    ( exit with -- b 0 0, end of line)
     THEN 
     1 -              ( back up the parser pointer to non-space )
     R>               ( retrieve the length of remaining string )
    THEN
    OVER SWAP           ( b' b' u' -- , start parsing non-space chars )
    FOR
      temp @            ( get delimiter )
      OVER C@ -         ( get next character )
      temp @ BL =       
      IF 0<
      ELSE 1 + 
      THEN
    WHILE               ( if delimiter, exit the loop )
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
/*
// Parsing Words pg74 .( ( \ CHAR TOKEN WORD
interpret(`
: CHAR ( -- c ; Parse next word and return its first character.)
  BL PARSE  ( get the next string )
  DROP C@ ; ( return the code of the 1st character )
`); interpret(`
: .(  ( -- ) ( Output following string up to next )
  [ CHAR ) ] LITERAL PARSE ( parse the string until next )
  TYPE ; IMMEDIATE         ( type the string to terminal )
`); interpret(`
: ( ( --) ( Ignore following string up to next. A comment.)
  [ CHAR ) ] LITERAL PARSE      ( parse the string until )
  2DROP ; IMMEDIATE             ( and ignore it as a comment )
`); interpret(`
: \\ ( -- ; Ignore following text till the end of line.)
   #TIB @ >IN ! ( store the length of TIB in >IN )
   ; IMMEDIATE ( in effect ignore the rest of a line )
`); interpret(`
: TOKEN ( -- a \ <string> ; Parse a word from input stream and copy it to name dictionary.)
  BL PARSE            ( parse out next space delimited string )
  31 MIN              ( truncate it to 31 characters )
  NP @                ( word buffer below name dictionary )
  OVER - 2 - PACK$ ;  ( copy parsed string to word buffer )
`); interpret(`
: WORD ( c -- a \\ <string> ) ( Parse a word from input stream and copy it to code dictionary.)
  PARSE         ( parse out a string delimited by c )
  HERE PACK$ ;  ( copy the string into the word buffer )
`)
*/
// Dictionary Search pg75-77 NAME> SAME? find NAME?
// Text input from terminal pg 78: ^H TAP kTAP accept EXPECT QUERY
// Error Handling pg80-82 CATCH THROW NULL$ ABORT abort" ?STACK
// Text Interpreter loop pg83-84 $INTERPRET [ .OK ?STACK EVAL //TODO good place to model JS interpreter on
// Operating System pg85-86 PRESET XIO FILE HAND I/O CONSOLE QUIT
// eForth Compiler pg 87
// Interpreter and Compiler pg 88-90: [ ] ' ALLOT , [COMPILE] COMPILE LITERAL $," RECURSE
// Control Structures pg91-92: FOR BEGIN NEXT UNTIL AGAIN IF AHEAD REPEAT THEN AFT ELSE WHILE
// String Literals pg93: ABORT" $" ."
// Name Dictionary Compiler pg94-96: ?UNIQUE $,n $COMPILE OVERT ; ] call, : IMMEDIATE
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
const print = code('print', () =>
  console.log('SPfetch()'));
run(names['FORTH']);
console.log('Finished:', SPfetch());

//TODO - build JS interpreter from forth_v1.js then interpet all the colon stuff and below
