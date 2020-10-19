/*
 * WIP to build a Node API along the lines in https://github.com/mitra42/webForth/issues/23
 * See TODO-23-NODEAPI
 *
 * const Forth = require('webforth');   // The class or obj with functions
 * foo = new Forth()                    // Instantiate a new, but incomplete instance
 * foo.compileForthInForth()            // Load the parts of Forth written in Forth
 * .then(() => foo.interpret("1 2 DUP .S")); // Run some Forth words in the instance
 * .then(() => forth.console());        // Go interactive
 *
 * And some ideas ... not yet implemented
 * new({ CELLL: 3, xxxMemSize: 1000000});  // parameterized "new"
 * .then(() => foo.load('foo.f'))       // TODO Load file into the class
 * .then(() => foo.load('https://....')) // TODO Load remote file it into the instance
 * boo = forth.rot([1,2,3]);  // Returns [2,3,1] - will depend what can do with JS API
 */

/*
 * References see FORTH.md
 */

/* Naming conventions and abbreviations
 * xt: execution token, points at the token field of a definition
 * na: Name Address, points to the name, (first byte count+flags, then that number of characters, max 31)
 * ca: Is ambiguous, sometimes it is used to refer to the xt, and sometimes to the Codefield Address, the field 2 cells below na that holds the xt
 * la: Linkfield Address, field holding the na of the previously defined word in this vocabulary
 * u: unsigned 16 bit
 * c: character
 * w: word - 16 bit signed
 * n: word - 16 bit signed
 *
 * For routines defined in Javascript there are typically
 * c.foo = func // If the functionary is to be discarded after bootstrap it will be in 'c' else just a function
 * this.jsFunctions[tok] = func // An array that maps the tokens used in the Forth space to the addresses of the function in JS address space
 * jsFunctionsAttributes[tok] = { name, replaced } // Some attributes to allow management of the functions
 * Name Dictionary:  na-2*CELLL: <xt><link><name> // In the name directory it looks like any other word
 * Code Dictionary:  xt: <tok> // In the code directory its a single cell with the token.
 */

/* Sections below in order
 * jsFunctionAttributes: maps JS functions to Forth names and other attributes
 * Memory Map - constants that lay out the memory array
 * Other key constants - especially bitmasks
 * Data table used to build users.
 * Forth written in Forth - loaded after the functions in the class
 * Support for Debugging - constants, variables, arrays, functions used by tools
 * Javascript structures - implement the memory map and record the full state.
 * Standard Pointers used - esp IP, SP, RP, UP
 * Build dictionary, mostly from jsFunctionAttributes
 * Support for Debugging
 * Code words to support debugging on the console
 * Functions to simplify storing and retrieving 16 bit values into 8 bit stacks etc.
 * Access to the USER variables before they are defined
 * Functions related to building 'find' and its wrappers
 * JS Functions to be able to define words
 * Define this tokens used for each kind of defining word
 * INNER INTERPRETER YES THIS IS IT !
 * Basic low level key I/O and links to OS
 * Literals and Branches - using next value in dictionary
 * Primitive words for memory, stack and return access, arithmetic and logic
 * Define and initialize User variable
 * JS interpreter - could be discarded when done or built out
 * A group of words required for the JS interpreter redefined later
*/
//eslint-env node

// This is a key table mapping the functions that go in the dictionary to the function names in the instance.
// it is used to build the dictionary in each instance.
const jsFunctionAttributes = [
  { n: 'tokenVocabulary', token: true }, // Token used for Vocabularies must be first 0
  { n: 'tokenNextVal', token: true }, // Token used for Constants must be next (1)
  { n: 'tokenDoList', token: true },
  { n: 'tokenUser', token: true },
  { n: 'tokenVar', token: true },
  { n: 'find' }, // Fast version of find - see Forth definition later
  { n: 'OVERT', replaced: true },
  // { n: '?UNIQUE', f: 'qUnique' }, // Not used yet
  { n: '$,n', f: 'dollarCommaN', replaced: true },
  { n: '>NAME', f: 'ToNAME' }, // Fast version of >NAME - see Forth definition later
  'debugNA', 'testing3', 'break', 'debugPrintTIB', 'TEST',
  'MS', 'BYE', { n: 'EXIT', jsNeeds: true }, 'EXECUTE',
  { n: '?RX', f: 'QRX' }, {  n: 'TX!', f: 'TXbang' }, { n: '!IO', f: 'bangIO' },
  { n: 'doLIT', jsNeeds: true }, 'next', { n: '?branch', f: 'qBranch' }, 'branch',
  { n: '!', f: 'store' }, { n: '@', f: 'fetch' }, { n: 'C@', f: 'cFetch' }, { n: 'C!', f: 'cStore' },
  { n: 'RP@', f: 'RPat' }, { n: 'RP!', f: 'RPbang' }, { n: 'R>', f: 'Rfrom'  }, { n: 'R@', f: 'Rat'  }, { n: '>R', f: 'toR'  },
  { n: 'SP@', f: 'SPat' }, { n: 'SP!', f: 'SPbang' },
  'DROP', 'DUP', 'SWAP', 'OVER',
  { n: '0<', f: 'less0' }, 'AND', 'OR', 'XOR', { n: 'UM+', f: 'UMplus' },
  'userAreaInit',
  { n: 'PARSE', replaced: true }, { n: 'TOKEN', replaced: true }, { n: 'NUMBER?', f: 'NUMBERQ', replaced: true },
  { n: '$COMPILE', replaced: true, jsNeeds: true }, { n: '$INTERPRET', replaced: true, jsNeeds: true },
  { n: '[', f: 'openBracket', immediate: true, replaced: true }, { n: ']', f: 'closeBracket', replaced: true },
  { n: ':', f: 'colon', replaced: true }, { n: ';', f: 'semicolon', immediate: true, replaced: true }, { n: "'", f: 'tick', replaced: true },
];

// Define the tokens used in the first cell of each word.
// Order must match the order of
const tokenVocabulary = 0;
const tokenNextVal = 1;
const tokenDoList = 2;
const tokenUser = 3;
const tokenVar = 4;

// === Memory Map - Zen pg26
// TODO-27-MEM rework this into separate slots and then check if really need ! and @ into some parts of mem
// ERRATA Zen doesnt define CELLL (and presumes is 2 in multiple places)
// ERRATA In Zen the definitions on Zen pg26 dont come close to matching the addresses given as the example below. In particular UPP and RPP overlap !
const l = {}; // Constants that will get compiled into the dictionary
l.CELLL = 2;  // Using Buffers, but needs to be 2 as needs to be big enough for an address (offset into buffer) if change see CELL+ CELL- CELLS ALIGNED $USER
l.CELLbits = l.CELLL * 8;
// There is an assumption that memory is Big-Endian (higher byte in lower memory location)
// Memory is assumed not to be aligned to a CELLL boundary, but this assumption should be confined to $ALIGN()
l.US = 64 * l.CELLL;  // user area size in cells i.e. 64 variables - standard usage below is using about 37
const RTS = 0x80 * l.CELLL; // return stack/TIB size // eFORTH-DIFF was 64 which is tiny for any kind of string handling TODO review this
const SPS = 0x80 * l.CELLL; // Size of data stack 256 bytes for now
// Now the memory map itself, starting at the top of memory.
const EM = 0x4000; // top of memory
const UPP = EM - l.US; // start of user area // TODO-28-MULTI UP should be a variable, and used in most places UPP is
const RPP = UPP - (8 * l.CELLL); // top of return stack RP0 - there is an 8 cell buffer which is probably just for safety.
l['=TIB'] = RPP - RTS; // Terminal input buffer - shares space with Return stack
const SPP = l['=TIB'] - (8 * l.CELLL); // start of data stack - grows down, points at top of stack - 8 word buffer for safety
const NAMEE = SPP - SPS; // name dictionary
// And then building from the bottom up. The gap in middle is code directory
const COLDD = 0x100; // cold start vector - its unclear if these bottom 0x100 are useful outside of the DOS context.
// Above COLDD is a store of initial values for User variables
const CODEE = COLDD + l.US; // code dictionary grows up from here towards NAME dictionary.
// PAD is 80 bytes above the current top of the Code directory, and HLD (where numbers are build for output) is a few bytes growing down from PAD.

// === Other key constants. //TODO-11-CELLL
l['=COMP'] = 0x40; // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
l['=IMED'] = 0x80; // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
const bitsSPARE = 0x20; // Unused spare bit in names
l['=BYTEMASK'] = 0xFF - l['=COMP'] - l['=IMED'] - bitsSPARE; // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
const forthTrue = (2 ** (l.CELLL*8)) - 1; // Also used to mask numbers
// mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
l['=CELLMASK'] = forthTrue ^ ((0xFF ^ l['=BYTEMASK']) << (l.CELLbits - 8));
const nameMaxLength = 31; // Max number of characters in a name, length needs to be representable after BitMask (we have one spare bit here)
console.assert(nameMaxLength === l['=BYTEMASK']); // If this isn't true then check each of the usages below
l.BL = 32;

// === Data table used to build users.
// later the FORTH word 'USER' works but doesn't setup initialization, nor does it auto-increment to next available user slot.
const jsUsers = []; // Note 4 cells skipped for multitasking but that is in init of _USER to 4*CELLL
function USER(n, v) { jsUsers.push([n, v]); return (jsUsers.length - 1) * l.CELLL; }
USER(undefined, 0); // Used for multitasking
USER(undefined, 0); // Used for multitasking
USER(undefined, 0); // Used for multitasking
USER(undefined, 0); // Used for multitasking
USER('SP0', SPP);      // (--a) Pointer to bottom of the data stack.
USER('RP0', RPP);      // (--a) Pointer to bottom of the return stack.
USER("'?KEY", '?RX');    // Execution vector of ?KEY. Default to ?rx.
USER("'EMIT", 'TX!');  // Execution vector of EMIT. Default to TX!
USER("'EXPECT", 0);    // Execution vector of EXPECT. Default to 'accept' - initialized when accept defined TODO-23-COLD needs to be in COLDD
USER("'TAP", 0);       // Execution vector of TAP. Default to kTAP. TODO-23-COLD needs to be in COLDD
USER("'ECHO", 'TX!');  // Execution vector of ECHO. Default to tx!.
USER("'PROMPT", 0);    // Execution vector of PROMPT.  Default to '.ok'. TODO-23-COLD needs to be in COLDD
const BASEoffset = USER('BASE', 10);
USER('temp', 0);       // A temporary storage location used in parse and find. EFORTH-ZEN-ERRATA its uses as 'temp', listing says 'tmp'
USER('SPAN', 0);       // Hold character count received by EXPECT (strangely it is stored, but not accessed)
const INoffset = USER('>IN', 0);        // Hold the character pointer while parsing input stream.
const nTIBoffset = USER('#TIB', 0);       // Hold the current count of the terminal input buffer.
const TIBoffset = USER(undefined, l['=TIB']);  // Hold current address of Terminal Input Buffer (must be cell after #TIB.)
USER('CSP', 0);        // Hold the stack pointer for error checking.
const EVALoffset = USER("'EVAL", 0);      // Initialized when have JS $INTERPRET, this switches between $INTERPRET and $COMPILE
const NUMBERoffset = USER("'NUMBER", 'NUMBER?');    // Execution vector of number conversion. Default to NUMBER?. TODO-23-COLD needs to be in COLDD
USER('HLD', 0);        // Hold a pointer in building a numeric output string.
USER('HANDLER', 0);    // Hold the return stack pointer for error handling.
// this is set to result of currentFetch
const CONTEXToffset = USER('CONTEXT', undefined); // A area to specify vocabulary search order. Default to FORTH. Vocabulary stack, 8 cells following CONTEXT.
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);
USER(undefined, 0);    // Always 0 to indicate no more valid Vocabularies
const CURRENToffset = USER('CURRENT', undefined); // Point to the vocabulary to be extended. Default to FORTH.
// this is set to result of currentFetch
USER(undefined, undefined); // Vocabulary link uses one cell after CURRENT (not clear how this is used)
// Note there is a (hidden) assumption that CP and NP are consecutive - used to check free space
const CPoffset = USER('CP', undefined);  // eForth initializes to CTOP but we have to use this during compilation
const NPoffset = USER('NP', undefined);  // normally set on Zen pg106 but we are using it live. Its the bottom of what compiled in name space.
const LASToffset = USER('LAST', undefined); // normally set on Zen pg106 but using live

const forthInForth = `
0 TEST
: 2DROP DROP DROP ;
1 2 2DROP 0 TEST

: setHeaderBits LAST @ C@ OR LAST @ C! ;
: COMPILE-ONLY =COMP setHeaderBits ;
: IMMEDIATE =IMED setHeaderBits ;

: ( 41 PARSE 2DROP ; IMMEDIATE ( from Zen pg74, note dont have LITERAL so cant do [ CHAR ( ] LITERAL instead of 41 )
  1 2 ( 3 ) 1 2 2 TEST
( Now that ( is defined we can use comments below here )

( === Test as many of the words defined in code as possible)
( EXIT & EXECUTE tested with ' )
( doLIT implicitly tested by all literals )
( next, ?branch, branch implicitly tested by control structures )
( CELLL 2 1 TEST ( Assuming small cell, otherwise it should be 2 )
123 HLD ! HLD @ 123 1 TEST ( Also tests user variables )
111 HLD ! 222 HLD C! HLD C@ 0 HLD C! HLD @ 222, 111 2 TEST
( R> >R R@ SP@ SP! tested after arithmetic operators )
30 20 DROP 30 1 TEST
30 20 DUP 30 20 20 3 TEST
10 20 SWAP 20 10 2 TEST
10 20 OVER 10 20 10 3 TEST
123 0< -123 0< 0 -1 2 TEST
16 BASE !
5050 6060 AND 5050 6060 OR 5050 6060 XOR 4040 7070 3030 3 TEST
0A BASE !

12 34 UM+ 46 0 2 TEST
( Next test is contrived to work with any CELLL size )
-1 -1 UM+ -2 1 2 TEST
( IMMEDIATE implicitly tested )
32 PARSE ABC SWAP DROP 3 1 TEST
!IO 62 TX! 0 TEST ( Should output > )
: FOO 10 EXIT 20 ; FOO 10 1 TEST
' FOO EXECUTE 30 10 30 2 TEST


( === First section is words moved earlier than they appear in eForth as they are needed for other words )
( they are mostly still in the same order as in eForth )

BL 32 1 TEST
: NIP SWAP DROP ;
1 2 NIP 2 1 TEST

( Note failure on this line, can be for three reasons )
( a: its the first execution of an immediate word inside a compilation )
( b: its the first execution of a word defined with a colon )
( c: its the first use of the comment
: HERE ( -- a; return top of code dictionary; Zen pg60) CP @ ;
( test is non-obvious )

( Note eForth has +, but that isn't defined till Zen pg50 )
: CELL+ CELLL UM+ DROP ;
( 1 CELL+ 3 1 TEST ) ( Only valid if CELLL=2)

( ERRATA - Zen pg57 presumes CELLL==2 and need to align, not case with JS and byte Buffer )
( : ALIGNED DUP 0 CELLL UM/MOD DROP DUP IF CELLL SWAP - THEN + ; )
: ALIGNED ; ( TODO-11-CELLL)
( 101 ALIGNED 101 1 TEST

( ERRATA v5 skips ALIGNED form this definition)
: , ( w --; Compile an integer into the code dictionary. Zen pg 89)
  HERE ALIGNED DUP CELL+ CP ! ! ;

: [COMPILE] ( -- ; <string> ) ' , ; IMMEDIATE ( Needs redefining pg87 to use new "'" )

: COMPILE ( --; Compile the next address in colon list to code dictionary. Zen pg 90)
  R> DUP @ , CELL+ >R ; COMPILE-ONLY

: LITERAL ( w -- ) ( Compile tos to code dictionary as an integer literal.)
  COMPILE doLIT ( compile doLIT to head lit )
  , ; IMMEDIATE ( compile literal itself )

( This definition of CREATE is redefined pg97 to use new, rather than JS versions of TOKEN $,n OVERT and COMPILE)
: CREATE TOKEN $,n OVERT tokenVar , ; 

( TODO-TEST test of above group non-obvious as writing to dictionary. )

( === Control structures - were on Zen pg91 but needed earlier Zen pg 91-92 but moved early )
( this version comes from EFORTH-V5 which introduced MARK> >MARK )

( FOR-NEXT FOR-AFT-THEN-NEXT BEGIN-AGAIN BEGIN-WHILE-REPEAT BEGIN-UNTIL AHEAD-THEN IF-ELSE-THEN ?WHEN)
: <MARK ( -- a ) HERE ;
: <RESOLVE ( a -- ) , ;
: >MARK ( -- A ) HERE 0 , ;
: >RESOLVE ( A -- ) <MARK SWAP ! ;
: FOR ( -- a ) COMPILE >R <MARK ; IMMEDIATE
: BEGIN ( -- a ) <MARK ; IMMEDIATE
: NEXT ( a -- ) COMPILE next <RESOLVE ; IMMEDIATE
: UNTIL ( a -- ) COMPILE ?branch <RESOLVE ; IMMEDIATE
: AGAIN ( a -- ) COMPILE branch <RESOLVE ; IMMEDIATE
: IF ( -- A )   COMPILE ?branch >MARK ; IMMEDIATE
: AHEAD ( -- A ) COMPILE branch >MARK ; IMMEDIATE
: REPEAT ( A a -- ) [COMPILE] AGAIN >RESOLVE ; IMMEDIATE
: THEN ( A -- ) >RESOLVE ; IMMEDIATE
( ERRATA ZEN - doesnt mark this as immediate)
: AFT ( a -- a A ) DROP [COMPILE] AHEAD [COMPILE] BEGIN SWAP ; IMMEDIATE
: ELSE ( A -- A )  [COMPILE] AHEAD SWAP [COMPILE] THEN ; IMMEDIATE
: WHEN ( a A -- a A a ) [COMPILE] IF OVER ; IMMEDIATE ( Cannot find documentation on how this is used )
: WHILE ( a -- A a )    [COMPILE] IF SWAP ; IMMEDIATE

( TODO-TEST of above group non-obvious as writing to dictionary. )
( IF-THEN tested in ?DUP; )

( === Multitasking Zen pg48 - not implemented in eForth TODO )

( === More Stack Words Zen pg49 TODO-OPTIMIZE )
: ?DUP DUP IF DUP THEN ; ( w--ww|0) ( Dup top of stack if its is not zero.)
: ROT >R SWAP R> SWAP ; ( w1, w2, w3 -- w2 w3 w1; Rotate third item to top)
: -ROT SWAP >R SWAP R> ; ( w1, w2, w3 -- w3 w1 w2; Rotate top item to third)
: 2DUP OVER OVER ; ( w1 w2 -- w1 w2 w1 w2;)
( 2DROP & NIP moved earlier )

1 ?DUP 0 ?DUP 1 1 0 3 TEST
1 2 3 ROT 2 3 1 3 TEST
1 2 2DUP 1 2 1 2 4 TEST

( === More Arithmetic operators Zen pg50 )
: + UM+ DROP ; ( w1 w2 -- w1+w2)
: D+ >R SWAP >R UM+ R> R> + + ; ( d1 d2 -- d1+d2)
: INVERT -1 XOR ; ( w -- w; 1's compliment)
( NOT's meaning is deprecated use 0= or INVERT bitwise see http://lars.nocrew.org/forth2012/core/INVERT.html)
: NEGATE INVERT  1 + ; ( w -- w; 2's complement)
: DNEGATE INVERT >R INVERT  1 UM+ R> + ;
: - NEGATE + ; ( n1 n2 -- n1-n2)
: ABS DUP 0< IF NEGATE THEN ; ( n -- n; Absolute value of w)
: 0= IF 0 ELSE -1 THEN ;

1 2 + 3 1 TEST
-1 1 -1 3 D+ -2 5 2 TEST ( Test contrived to be CELLL independent )
257 INVERT -258 1 TEST ( 257 is 0x101 65278 is 0xFEFE )
53 NEGATE 53 + 0 1 TEST
456 123 - 456 -123 - 333 579 2 TEST
-456 ABS 456 ABS - 0 1 TEST
111 >R R@ RP@ R> SWAP RP@ SWAP - 111 111 CELLL 3 TEST
1 2 SP@ CELL+ SP! 1 1 TEST

( === More comparison Zen pg51-52 )
: = XOR IF 0 EXIT THEN -1 ; ( w w -- t)
: U< 2DUP XOR 0< IF NIP 0< EXIT THEN - 0< ;
: < 2DUP XOR 0< IF DROP 0< EXIT THEN - 0< ;
: MAX 2DUP < IF SWAP THEN DROP ;
: MIN 2DUP SWAP < IF SWAP THEN DROP ;
: WITHIN OVER - >R - R> U< ;

123 123 = 123 124 = -1 0 2 TEST
123 100 U< 100 123 U< 123 -100 U< -100 123 U< 0 -1 -1 0 4 TEST
123 100 < 100 123 < 123 -100 < -100 123 < 0 -1 0 -1 4 TEST
100 200 MAX 300 100 MAX 200 300 2 TEST
100 200 MIN 300 100 MIN 100 100 2 TEST
200 100 300 WITHIN 300 100 200 WITHIN 100 -100 200 WITHIN -1 0 -1 3 TEST

( === More Math Words Zen pg53-55 UM/MOD M/MOD /MOD MOD / UM+ * M* )
: UM/MOD ( udl udh u -- ur uq ) ( needs FOR-NEXT from 91)
  ( Unsigned divide of a double by a single. Return mod and quotient)
  2DUP U<
  IF NEGATE         ( negate u for subtraction )
    CELLbits FOR          ( repeat 16 times for 16 bits)
      AFT             ( 
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
      THEN
    NEXT            ( repeat for CELLbits bits)
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
  /MOD NIP ; ( discard remainder)

: UM* ( u1 u2 -- ud)
  ( Unsigned multiply. Return double product.)
  0 SWAP          ( u1 sum u2)
  CELLbits FOR    ( repeat for 16 bits)
    AFT
      DUP UM+ >R >R ( left shift u2)
      DUP UM+       ( left shift sum)
      R> +          ( add carry to u2)
      R>            ( carry shifted out of u2?)
      IF >R OVER UM+  ( add u1 to sum)
        R> +        ( carry into u2)
      THEN
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

-1 1 2 UM/MOD 1 -1 2 TEST
-1 1 2 M/MOD 1 -1 2 TEST
9 0 4 UM/MOD 1 2 2 TEST
9 4 /MOD 1 2 2 TEST
9 4 MOD 1 1 TEST
9 4 / 2 1 TEST
2 -1 UM* -2 1 2 TEST
3 4 * 12 1 TEST
-2 -3 M* 6 0 2 TEST

( === Scaling Words Zen pg56 */MOD */ )

: */MOD ( n1 n2 n3 -- r q )
  ( Multiply n1 and n2, then divide by n3. Return mod and quotient)
  >R M*       ( n1*n2)
  R> M/MOD ;  ( n1*n2/n3 with remainder)

: */ ( n1 n2 n3 -- q )
  ( Multiple by n1 by n2, then divide by n3. Return quotient only)
  */MOD NIP ; ( n1*n2/n3 and discard remainder)

5 7 2 */MOD 1 17 2 TEST
5 7 2 */ 17 1 TEST

( === Memory Alignment words Zen pg57 CELL+ CELL- CELLS ALIGNED )
( CELL+ & ALIGNED moved earlier ERRATA Zen & v5 use 2 which is wrong unless CELL is '2' )

: CELL- ( a -- a)
  ( Subtract cell size in byte from address)
  CELLL - ;

: CELLS ( n - n )
  ( Multiply n by cell size in bytes)
  CELLL * ;

123 CELL- CELLL + 123 1 TEST
123 CELLS CELLL / 123 1 TEST

( === Special Characters Zen pg58 BL >CHAR )

( BL moved earlier)

: >CHAR ( c -- c; filter non printing characters, replace by _)
  127 AND DUP   ( mask off the MSB bit)
  127 BL WITHIN ( if its a control character)
  IF DROP 95 THEN ; ( replace with an underscore)

41 >CHAR 23 >CHAR BL >CHAR 41 95 32 3 TEST

( === Managing Data Stack Zen pg59 DEPTH PICK )

( ERRATA Staapl, v5, zen, has 2/ )
: DEPTH ( -- n)
  ( Return the depth of the data stack)
  SP@           ( current stack pointer)
  SP0 @ SWAP -  ( distance from stack origin)
  CELLL / ;     ( divide by bytes/cell)

: PICK ( ... +n -- ... w)
  ( Copy the nth stack item to tos)
  1 + CELLS     ( bytes below tos)
  SP@ + @ ;     ( fetch directly from stack)

1 2 3 DEPTH 1 2 3 3 4 TEST
11 22 33 1 PICK 11 22 33 22 4 TEST

( === Memory Access Zen pg60 +! 2! 2@ HERE PAD TIB @EXECUTE )
( Note 2! 2@ presume big-endian which is a Forth assumption (high word at low address)

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
  @ ?DUP IF EXECUTE
  ELSE break
  THEN ;

HLD @ 2 HLD +! HLD @ SWAP - 2 1 TEST
1 2 3 SP@ 4 5 ROT 2! 1 4 5 3 TEST
1 2 3 SP@ 2@ 1 2 3 2 3 5 TEST
TIB >R BL PARSE XXX SWAP R> - 3 16 2 TEST

( === Memory Array and String Zen pg61-62: COUNT CMOVE FILL -TRAILING PACK$ )

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

( DIFF: Staapl has FOR AFT DUP R@ + C@ BL XOR IF R> 1 + EXIT THEN THEN NEXT 0; which only strips BL )
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

( Note there is code in this.TOKEN which does this )
( DIFF: V5 version used; Zen&Staapl: DUP >R 2DUP C! 1 + 2DUP + 0 SWAP ! SWAP CMOVE R> )
: PACK$ ( b u a -- a; Build a counted string with u characters from b. Null fill.)
  ALIGNED             ( noop on JS celll=2 where not requiring alignment)
  DUP >R OVER         ( b u a u ; save address of word buffer )
  DUP 0 CELLL UM/MOD DROP ( b y a u r; find remainder of chars if not exact number of cells)
  - OVER + 0 SWAP !   ( b y a ; Store 0 in last cell)
  2DUP C!             ( store the character count first )
  1 + SWAP CMOVE      ( ; store characters in cells - 0 padded to end of cell)
  R> ;        ( leave only word buffer address )

  NP @ CELL+ CELL+ COUNT NIP 5 1 TEST
  ( TODO-11-CELLL - need these tests)
  ( TODO rework this  test('NP @ 4 + COUNT PAD SWAP CMOVE', [], {pad: 'PACK$'});
  ( TODO rework this  test('PAD 3 + 5 BL FILL', [], {pad: 'PAC     '});
  ( TODO rework this test('PAD 8 -TRAILING >R PAD - R>', [0, 3], {pad: 'PAC'})
  ( TODO rework this test NP @ 4 + COUNT PAD 1 - PACK$', [this.padPtr(] - 1], {pad: 'PACK$'})

( === TEXT INTERPRETER ===  Zen pg63 )

( === Numeric Output Zen pg64 DIGIT EXTRACT )
: DIGIT ( u -- c ; Convert digit u to a character.)
  9 OVER <    ( if u is greater than 9)
  7 AND +     ( add 7 to make it A-F)
  48 + ;      ( add ASCII 0 for offset)
: EXTRACT ( n base -- n/base c ; Extract the least significant digit from n.)
  0 SWAP UM/MOD   ( divide n by base)
  SWAP DIGIT ;    ( convert remainder to a digit)

123 10 EXTRACT 12 51 2 TEST

( === Number formatting Zen pg65 <# HOLD #S SIGN #> )

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

( TODO rework this test('123 <# DUP SIGN #S #>', [this.padPtr(] - 3, 3], {hold: '123'} )
( TODO rework this  test('-123 DUP ABS <# #S SWAP SIGN #>', [this.padPtr(] - 4, 4], {hold: '-123'})

( === More definitions moved up )

: EMIT ( c--;  Send a character to the output device. Zen pg69)
  'EMIT @EXECUTE ;
: SPACE ( -- ; Send the blank character to the output device. Zen pg70)
  BL EMIT ; ( send out blank character)
: CHARS ( +n c -- ; Send n characters to output device)
  SWAP 0 MAX FOR AFT DUP EMIT THEN NEXT DROP ; ( From Staapl and V5, not in Zen) ( TODO-ANS flagged as possible conflict)
: SPACES ( n -- ; Send n spaces to the output device. Zen pg70) ( ERRATA Zen has bad initial SWAP)
  BL CHARS ;
: TYPE ( b u -- ; Output u characters from b)
  FOR AFT DUP C@ EMIT 1 + THEN NEXT DROP ;
: .$ ( a -- ) COUNT TYPE ; ( from Staapl, not in eForth)

60 EMIT SPACE 2 SPACES 61 EMIT 0 TEST
( .$ is tested by ."| and others )

( === Number output Zen pg66 str HEX DECIMAL .R U.R U. . ? )

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

-123 5 .R 123 5 U.R 123 U. 123 . BASE ? 0 TEST

( === Numeric input Zen pg67-68 DIGIT? NUMBER? )
( ERRATA Zen NIP is used but not defined )

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
( EFORTH-ZEN-ERRATA it doesnt return 'n T' it returns 'n a' on success
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
      DROP ( a sum ) ( discard string address b )
      R@ ( b ?sign)  ( completely convert the string.get sign )
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

50 10 DIGIT? 2 -1 2 TEST
BL PARSE 1234 PAD PACK$ NUMBER? DROP 1234 1 TEST
' NUMBER? 'NUMBER !
123 123 1 TEST

( TODO Note the EFORTH-ZEN-ERRATA in the docs v. code for NUMBER? means we drop testing the flag will reconsider when see how used )
( === Serial I/O Zen pg69 ?KEY KEY EMIT NUF? )

( === Derived I/O Zen pg70 PACE SPACE SPACES TYPE CR )
( ERRATA Staapl calls it "KEY?" )
: ?KEY ( -- c T | F) ( Return input character and true, or a false if no input.)
  '?KEY @EXECUTE ;
: KEY ( -- c ) ( Wait for and return an input character.)
  0           ( Initial delay )
  BEGIN
    MS        ( Introduce a delay, drops CPU from 100% to insignificant)
    1000      ( Ramp to a max delay of 1S )
    ?KEY      ( delay c T | delay F; Check for key )
  UNTIL
  NIP ;       ( Drop delay )
( EMIT moved up )
( ERRATA Staapl has different flow, probably wrong)
: NUF? ( -- t) ( Return false if no input, else pause and if CR return true)
  ?KEY DUP ( -- c T T | F F;  wait for a key-stroke)
  IF 2DROP KEY
    13 = ( return true if key is CR)
  THEN ;
( TODO-TEST TODO-INPUT then test ?KEY KEY NUF? )

: PACE ( --) ( Send a pace character for the file downloading process.)
  11 EMIT ; ( 11 is the pace character)
( SPACE and SPACES and TYPE and CHARS moved earlier)
( ERRATA Zen has 15 instead of 13 and 11 instead of 10)
: CR ( --) ( Output carriage return line feed)
  13 EMIT 10 EMIT ;
( TODO-TEST TODO-INPUT then test PACE, CR )

( === String Literal Zen pg71 do$ $"| ."| )

: do$ ( --a)
  ( Return the address of a compiled string.)
  ( Relies on assumption that do$ is part of definition of something e.g. $"| or ."|  that is run time code for the string )
  R>                  ( this return address must be preserved S: R0; R: R1... )
  R@                  ( get address of the compiled string S: R0 R1; R: R1... )
  R>                  ( get another copy S: R0 R1 R1; R: R2... )
  COUNT + ALIGNED >R  ( replace it with addr after string; S: R0 R1; R: R1' R2... )
  SWAP  ( get saved address to top; S: R1 R0; R: R1' R2...)
  >R ;  ( restore the saved return address S: R1; R: R0 R1' R2 ...)

: $"| ( -- a) ( Run time routine compiled by $". Return address of a compiled string.)
  do$ ; ( return string address only)
: ."| ( -- ) ( Run time routine of ." . Output a compiled string.)
  do$        ( get string address)
  .$ ;       ( print the compiled string)

( ."| tested by ."; $"| tested by $" )

( === Word Parser Zen pg72-73 PARSE parse )
( ERRATA Zen this doesnt set >IN past the string, but the callers clearly assume it does.)
( ERRATA Zen pg72 is obviously broken as it doesn't even increment the pointer in the FOR loop)
( This version is based on v5, Staapl is significantly different )

: parse ( b u c -- b u delta ; <string> ) ( TODO evaluate control structures here)
  ( Scan string delimited by this. Return found string and its offset. )
  ( EFORTH-ZEN-ERRATA - delta appears to be to end of string, not start )
  temp !            ( save delimiter in temp )
  OVER >R DUP       ( b u u)
  IF                ( if string length u=0, nothing to parse )
    1 -             ( u>0, decrement it for FOR-NEXT loop )
    temp @ BL =     ( is delimiter a space? )
    IF              ( b u' --, skip over leading spaces )
      FOR BL        ( EFORTH-ZEN-ERRATA says BLANK )
        OVER C@       ( get the next character )
        - 0<          ( is it a space? )
        INVERT
      WHILE
        1 +           ( EFORTH-ZEN-ERRATA - correct in eForthOverviewv5.pdf )
      NEXT            ( b -- , if space, loop back and scan further)
        R> DROP       ( end of buffer, discard count )
        0 DUP EXIT    ( exit with -- b 0 0, end of line)
     THEN
     ( EFORTH-ZEN-ERRATA - correct in eForthOverview5.pdf: 1 -              ( back up the parser pointer to non-space )
     R>               ( retrieve the length of remaining string )
    THEN
    OVER SWAP           ( b' b' u' -- , start parsing non-space chars )
    FOR
      temp @            ( get delimiter )
      OVER C@ -         ( get next character )
      temp @ BL =
      IF 0<
      ( EFORTH-ZEN-ERRATA ELSE 1 + )
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

( ====== TODO COMPARE VERSIONS ZEN STAAPL V5 BELOW HERE )

( === Parsing Words Zen pg74 .( ( \\ CHAR TOKEN WORD )

: CHAR BL PARSE DROP C@ ; ( Parse a word and return its first character )
: CTRL CHAR 31 AND ; ( Parse a word, return first character as a control )
CHAR ) 41 1 TEST
CTRL H 8 1 TEST

: .(  ( -- ) ( Output following string up to next )
  [ CHAR ) ] LITERAL PARSE
   ( parse the string until next )
  TYPE ; IMMEDIATE         ( type the string to terminal )

: \\ ( -- ; Ignore following text till the end of line.)
   #TIB @ >IN ! ( store the length of TIB in >IN )
   ; IMMEDIATE ( in effect ignore the rest of a line )

( Note there is this.TOKEN which does same thing )
: TOKEN ( -- a ; <string> ; Parse a word from input stream and copy it to name dictionary.)
  BL PARSE            ( parse out next space delimited string )
  =BYTEMASK MIN              ( truncate it to 31 characters = nameMaxLength )
  NP @                ( word buffer below name dictionary )
  OVER - CELLL - PACK$ ;  ( copy parsed string to word buffer )

: WORD ( c -- a ; <string> ) ( Parse a word from input stream and copy it to code dictionary. Not if not in definition it will be overwritten by next)
  PARSE         ( parse out a string delimited by c )
  HERE PACK$ ;  ( copy the string into the word buffer )

1 2 ( 3 ) 4 \\ commenting
1 2 4 3 TEST
TOKEN xxx C@ 3 1 TEST
BL WORD yyyy DUP C@ SWAP CP @ - 4 0 2 TEST
: foo .( output at compile time) ; 0 TEST

( === Dictionary Search Zen pg75-77 NAME> SAME? find NAME? )

( TODO Reconstruct this test with the use of testFind below )
( 'BL WORD TOKEN CONTEXT @ find SWAP' )
( const testFind = [this.SPpop(, this.SPpop(]; // Get results from old find )

: NAME> ( na -- ca )
  ( Return a code address given a name address.)
  2 CELLS - ( move to code pointer field )
  @ ; ( get code field address )


: SAME? ( a1 a2 u -- a1 a2 f \\ -0+ ) ( See JS sameq )
  ( Compare u cells in two strings. Return 0 if identical.)
  ( NOTICE THIS IS CELLS NOT BYTES )
  FOR               ( scan u+1 cells ) ( a1 a2 ; R: u)
    AFT             ( skip the loop the first time ) ( a1 a2; R: u-n)
      OVER          ( copy a1 ) ( a1 a2 a1; R: u-n)
      R@ CELLS + @  ( fetch one cell from a1) ( a1 a2 a1[u-n]  R: u-n)
      OVER          ( copy a2 ) ( a1 a2 a1[u-n] a2  R: u-n)
      R@ CELLS + @  ( fetch one cell from a2) ( a1 a2 a1[u-n] a2[u-n]  R: u-n)
      -             ( compare two cells ) ( a1 a2 match=0 R: u-n)
      ?DUP          ( a1 a2 0 | a1 a2 T T  R: u-n)
      IF            ( if they are not equal ) ( a1 a2 T  R: u-n)
        R> DROP     ( drop loop count ) ( a1 a2 T )
        EXIT        ( and exit with the difference as a flag )
      THEN          ( a1 a2 )
    THEN            ( a1 a2 R: u-n)
  NEXT              ( loop u times if strings are the same ) ( a1 a2;  R: u-n-1)
  0 ;               ( then push the 0 flag on the stack ) ( a1 a2 0)

( This can replace the code definition of find, however it is approx 8x slower )
: FORTHfind ( a va -- ca na, a F )
  ( Search a vocabulary for a string. Return ca and na if succeeded.)
  SWAP                ( va a )
  DUP C@ CELLL / temp !   ( va a -- , get cell count ) ( EFORTH-ZEN-ERRATA was '2 /'
  DUP @ >R            ( va a -- , save 1st cell of string )
  CELL+ SWAP          ( a' va -- , compare string with names )
  BEGIN               ( fast test, compare only 1st cells )
    @ DUP             ( a' na na -- )
    ( debugNA )       ( uncomment for debugging find - will report each name as checked)
    IF                ( na=0 at the end of a vocabulary )
      DUP @           ( not end of vocabulary, test 1st cell )
      [ =CELLMASK ] LITERAL AND ( mask off lexicon bits )
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

( NAME> implicitly tested by find )
BL WORD xxx DUP C@ 1 + PAD SWAP CMOVE PAD BL WORD xxx 4 SAME? >R 2DROP R> 0 1 TEST
BL WORD xxx DUP C@ 1 + PAD SWAP CMOVE PAD BL WORD xzx 4 SAME? >R 2DROP R> 0= 0 1 TEST
FORTH 0 TEST
( TODO convert test now dont have testFind ; BL WORD TOKEN CONTEXT @ FORTHfind', testFind.map(k => k ; (Compare with results from old version of find )
( TODO convert this test - now dont have testFind - BL WORD TOKEN NAME?', testFind ; // Name searches all vocabs )
( === Text input from terminal Zen pg 78: ^H TAP kTAP accept EXPECT QUERY )
( EFORTH-ZEN-ERRATA CTRL used here but not defined. )

: ^H ( bot eot cur -- bot eot cur)
  ( Backup the cursor by one character.)
  >R OVER     ( bot eot bot --)
  R@ < DUP    ( bot<cur ? )
  IF [ CTRL H ] LITERAL ( yes, echo backspace )
    'ECHO @EXECUTE
  THEN        ( bot eot cur 0|-1 -- )
  R> + ;      ( decrement cur, but not passing bot )

: TAP ( bottom eot current key -- bottom eot current )
  ( Accept and echo the key stroke and bump the cursor.)
  DUP         ( duplicate character )
  'ECHO @EXECUTE ( echo it to display )
  OVER C!     ( store at current location )
  1 + ;       ( increment current pointer )

: kTAP ( bot eot cur key -- bot eot cur )
  ( Process a key stroke, CR or backspace.)
  DUP 13 = OVER 10 = OR 0= ( is key a return?)
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
  OVER + OVER       ( b b+u b;  EFORTH-ZEN-ERRATA fixed in v5 and STAAPL)
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
  OVER -
  ;          ( b u; leave actual count)

' accept 'EXPECT ! ( TODO needs to also be in COLDD area for COLD )

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
  0 >IN !         ( initialized parsing pointer )
  ( debugPrintTIB )
  ;
( TODO-TEST TODO-IO input handling needs EXPECT etc )

( === Error Handling Zen pg80-82 CATCH THROW NULL$ ABORT abort" ?STACK )

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

CREATE NULL$ 0 , ( EFORTH-ZEN-ERRATA inserts a string "coyote" after this, no idea why! )

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


( Staapl has alternate definition: : $," [ CHAR " ] LITERAL PARSE HERE PACK$ C@ 1 + ALLOT ;)
( ERRATA v5 has obvious errata missing the + after COUNT
: $," ( --) ( Moved earlier from Zen pg90)
  ( Compile a literal string up to next " .)
  34 WORD ( move string to code dictionary)
  COUNT + ALIGNED ( calculate aligned end of string)
  CP ! ; ( adjust the code pointer)

( Moved earlier from Zen pg93 )
: ABORT" ( -- ; <string> )
  ( Conditional abort with an error message.)
  COMPILE abort"  ( compile runtime abort code )
  $," ; IMMEDIATE ( compile abort message )

( Moved earlier from Zen pg93 )
: ." ( -- ; <string> )
  ( Compile an inline string literal to be typed out at run time.)
  COMPILE ."| ( compile print string code )
  $," ; IMMEDIATE ( compile print string )

( Test is tricky - the "3" in bar is thrown away during hte "THROW" while 5 is argument to THROW )
: bar 3 5 THROW 4 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo 1 5 2 3 TEST
: bar 3 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo 1 3 0 2 4 TEST
: foo ." hello" ; foo 0 TEST
( Note that abort restores the stack, so shouldn't have consumed something else will have random noise on stack )
: bar ?DUP ABORT" test" 3 ; : foo [ ' bar ] LITERAL CATCH ; 1 foo C@ 0 foo 1 4 3 0 4 TEST
( $," and abort" are implicitly tested by ABORT")

( === Text Interpreter loop Zen pg83-84 $INTERPRET [ .OK ?STACK EVAL )

: $INTERPRET ( a -- )
  ( Note js $INTERPRET has same signature as this except for THROW
                                                           ( Interpret a word. If failed, try to convert it to an integer.)
  NAME?                   ( search dictionary for word just parsed )
    ?DUP                    ( is it a defined word? )
  IF C@                    ( yes. examine the lexicon ) ( EFORTH-ZEN-ERRATA it should be C@ not @)
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
  DEPTH 0< ABORT" underflow" ; ( Note Staapl uses $" THROW, v5 uses ABORT)

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

( === TODO-TEST TODO-IO test EVAL, not that .OK wont work here since not yet using $INTERPRET )

BL PARSE 123 PAD PACK$ $INTERPRET 123 1 TEST
123 BL PARSE DUP PAD PACK$ $INTERPRET  123 123 2 TEST
: foo 1 2DROP ?STACK ; : bar [ ' foo ] LITERAL CATCH ; bar C@ 9 1 TEST

( This switches to use new interpreter, its still using old js $COMPILE )

: [ ( -- )
  ( Start the text interpreter.) ( Replaces JS version )
  [ ' $INTERPRET ] LITERAL
  'EVAL !                   ( store $INTERPRET in 'EVAL )
  ; IMMEDIATE               ( must be done even while compiling )

[ 1 2 3 ROT 2 3 1 3 TEST

( TODO-ZEN-V5-STAAPL - COMPARE ABOVE HERE)

( === Operating System Zen pg85-86 PRESET XIO FILE HAND I/O CONSOLE QUIT)

( EFORTH-V5-ERRATA uses TIB #TIB CELL+ ! which since ' TIB #TIB CELL+ @' is a NOOP )
( EFORTH-ZEN-ERRATA uses =TIB but doesnt define =TIB which is TIBB)
: PRESET ( -- )
  ( Reset data stack pointer and the terminal input buffer. )
  SP0 @ SP!   ( initialize data stack )
  [ =TIB ] LITERAL #TIB CELL+ ! ; ( initialize terminal input buffer )

: XIO ( prompt echo tap -- )
  ( Reset the I/O vectors 'EXPECT, 'TAP, 'ECHO and 'PROMPT.)
  [ ' accept ] LITERAL 'EXPECT !  ( vector EXPECT )
  'TAP !                          ( init kTAP )
  'ECHO !                         ( init ECHO )
  'PROMPT ! ;                     ( init system prompt )

: FILE ( -- )
  ( Select I/O vectors for file download.)
  [ ' PACE ] LITERAL  ( send 11 for acknowledge )
  [ ' DROP ] LITERAL  ( do not echo characters )
  [ ' kTAP ] LITERAL  ( ignore control characters )
  XIO ;


: HAND ( -- )
  ( Select I/O vectors for terminal interface.)
  [ ' .OK  ] LITERAL  ( say 'ok' if all is well)
  [ ' EMIT ] LITERAL  ( echo characters ) ( ERRATA zen, Staapl uses EMIT which is 'EMIT @', V5's use of EMIT is better because respects changes to 'EMIT
  [ ' kTAP ] LITERAL  ( ignore control characters )
  XIO ;

( EFORTH-ZEN-ERRATA has 'RX?' should be '?RX'
CREATE I/O  ' ?RX , ' TX! , ( Array to store default I/O vectors. )

: CONSOLE ( -- )
  ( Initiate terminal interface.)
  I/O 2@ '?KEY 2!   ( get defaults from I/O ) ( EFORTH-STAAPL EFORTH-ZEN errata has 'KEY?. V5 fixes )
  HAND ;            ( keyboard input )

: que ( -- )
  QUERY ( get a line of commands from )
  EVAL ; ( Evaluate it)

: QUIT ( -- )
 ( Reset return stack pointer and start text interpreter. )
  RP0 @ RP!           ( initialize the return stack )
  BEGIN
    [COMPILE] [       ( start text interpreter )
    BEGIN
      [ ' que ] LITERAL ( get a line and evaluate it)
      CATCH             ( execute commands with error handler)
      ?DUP
    UNTIL ( a)          ( exit if an error occurred )
    ( 'PROMPT @ SWAP )  ( EFORTH-ZEN and EFORTH-V5 save current prompt address, Staapl doesnt)
    CONSOLE             ( Initialize for terminal interaction)
    NULL$ OVER XOR      ( is error address=NULL$ ? )
    ( V5, ZEN and Staapl differ, prefer Staapl I think)
    IF                  ( its not NULL$ )
      CR TIB #TIB @ TYPE ( Display line in TIB )
      CR >IN @ [ CHAR ^ ] LITERAL CHARS ( ^ under offending word )
      CR .$ ."  ? "     ( followed by error message and "?" )
    THEN
    PRESET              ( reset the data stack )
    ( V5 and ZEN also send "ERR" to file handler if prompt is not OK which is a little off )
  AGAIN ;               ( go back get another command line )

( TODO-IO test PRESET HAND CONSOLE QUIT )

( TODO-ZEN-V5-STAAPL - COMPARE BELOW HERE )

( === eForth Compiler Zen pg 87 ====== )

( === Interpreter and Compiler Zen pg 88-90: [ ] ' ALLOT , [COMPILE] COMPILE LITERAL $," RECURSE )

( "," COMPILE LITERAL $," are moved earlier, redefinition of ] is moved later as needs $COMPILE )
: ' ( -- ca ) TOKEN NAME? IF EXIT THEN THROW ;

: ALLOT ( n -- ) CP +! ; ( ERRATA Zen has +1 instead of +! fixed in V5 and Staapl)

: [COMPILE] ( -- ; <string> ) ' , ; IMMEDIATE ( Needs redefining to use new "'" )

( ERRATA Staapl & Zen do 'CURRENT @ !', v5 does 'NAME> ,' this is fundamentally different usage, ANS matches latter )
: RECURSE ( -- ) LAST @ NAME> , ; IMMEDIATE

1 ' DUP EXECUTE 1 1 2 TEST
HERE 2 ALLOT HERE SWAP - 2 1 TEST
: foo [COMPILE] ( ; foo 2 ) 0 TEST
: foo ?DUP IF DUP 1 - RECURSE THEN ; 3 foo 3 2 1 3 TEST

( === Control Structures Zen pg91-92: FOR BEGIN NEXT UNTIL AGAIN IF AHEAD REPEAT THEN AFT ELSE WHILE )
( All moved earlier )


( === String Literals Zen pg93: ABORT" $" ." ( ABORT" ." moved to Zen pg84 where used )

: $" ( -- ; <string> )
  ( Compile an inline string literal.)
  COMPILE $"|     ( compile string runtime code)
  $," ; IMMEDIATE ( compile string itself )

: foo $" hello" COUNT NIP ; foo 5 1 TEST

( === Name Dictionary Compiler Zen pg94-96: ?UNIQUE $,n $COMPILE OVERT ; ] call, : IMMEDIATE  (see this.dollarCommaN)

: ?UNIQUE ( a -- a ) ( Redefining code word qUNIQUE in Forth)
  ( Display a warning message if the word already exists.)
  DUP NAME?       ( name exists already?)
  IF ."  reDef "  ( if so, print warning )
  OVER .$       ( with the offending name )
  THEN DROP ;     ( discard token address )

TOKEN foo DUP ?UNIQUE - 0 1 TEST

: $,n ( na -- ) ( See also this.dollarCommaN above)
  ( Build a new dictionary name using the string at na.)
  DUP C@                      ( null input?)
  IF ?UNIQUE                  ( duplicate name? )
    ( na) DUP LAST !          ( save na for vocabulary link for OVERT)
    ( na) HERE ALIGNED SWAP   ( align code address )
    ( cp na) CELL-            ( link address )
    ( cp la) CURRENT @ @      ( link to current vocab)
    ( cp la na') OVER !
    ( cp la) CELL- DUP NP !   ( adjust name pointer )
    ( ptr) ! EXIT             ( save code pointer and exit )
  THEN                        ( here if null input )
  $" name" THROW ;            ( this is an error return )

: $COMPILE ( a -- ) ( Redefining code word js $COMPILE in Forth)
  ( Compile next word to code dictionary as a token or literal.)
  NAME?         ( parse the next word out )
  ?DUP          ( successful? )
  IF C@         ( yes, get the lexicon )
    =IMED AND   ( is it an immediate word? ) ( ERRATA V5 has @ - Staapl,Zen correct)
    IF EXECUTE  ( yes.  execute it )
    ELSE ,      ( no.  compile it )
    THEN
    EXIT        ( done. exit )
  THEN          ( not a valid word )
  'NUMBER @EXECUTE ( convert it to a number )
  IF [COMPILE] LITERAL ( successful. compile a literal number )
    EXIT        ( done )
  THEN          ( not a number either )
  COUNT TYPE SPACE ." Not found" ( TODO remove line when have better handling of THROW)
  THROW ;       ( generate an error condition )
  
: OVERT ( -- ) ( Redefining code word in Forth)
  ( Link a successfully defined word into the current vocabulary. )
  LAST @        ( name field address of last word )
  CURRENT @  ! ; ( link it to current vocabulary )

: ; ( -- ) ( redefining code word)
  ( Terminate a colon definition. )
  COMPILE EXIT  ( compile exit code )
  [COMPILE] [   ( return to interpreter state )
  OVERT ;       ( restore current vocabulary )
  COMPILE-ONLY IMMEDIATE

: ] ( -- ) ( redefining code word)
  ( Start compiling the words in the input stream.)
  [ ' $COMPILE ] LITERAL  ( get code address of compiler )
  'EVAL ! ;               ( store it in 'EVAL )

: : ( -- ; <string> ) ( redefining code word)
  ( Start a new colon definition using next word as its name.)
  TOKEN $,n   ( compile new word with next name )
  tokenDoList ,
  ] ;

: foo 1 ; foo 1 1 TEST


( TODO may need JS equivalent - see if used;  : CALL, ( ca -- ; ( DTC 8086 relative call ; [ =CALL ] LITERAL , HERE CELL+ - , ; )

( === Defining Words Zen pg97: USER CREATE VARIABLE )

( EFORTH-DIFF each of V5, Zen and Staapl do this differently - this is different again because of token threaded architecture)

: USER ( u -- ; <string> ) TOKEN $,n OVERT tokenUser , ;

( Create a new word that doesnt allocate any space, but will push address of that space. )
: CREATE ( -- ; <string> ) TOKEN $,n OVERT tokenVar , ; ( redefines definition moved up so that it will use new TOKEN etc)

: VARIABLE ( -- ; <string> ) CREATE 0 , ;

: CONSTANT ( u -- ; <string> ) TOKEN $,n OVERT tokenNextVal , , ;

VARIABLE foo 0 TEST
12 foo ! 0 TEST
foo @ 12 1 TEST

( === Utilities Zen pg98 )
( === Memory Dump Zen pg99 _TYPE do+ DUMP )

( ERRATA Staapl & Zen - uses -ROT which is not defined (its ROT ROT)
( ERRATA Staapl - uses COUNT which is technically correct but poor typing )

: _TYPE ( b u -- )
  ( Unsigned multiply. Return double product.)
  FOR           ( repeat u+1 times )
    AFT         (  skip to THEN the first time )
    DUP C@      ( get one character from b )
    >CHAR EMIT  ( display only printable char )
    1 +
  THEN NEXT     ( repeat u times )
  DROP ;        ( discard b address )

: dm+ ( b u -- b )
  ( Dump u bytes from , leaving a+u on the stack.)
  OVER 4 U.R SPACE  ( print address first )
  FOR AFT           ( repeat u times )
  DUP C@ 3 U.R      ( display bytes in 3 columns )
  1 + THEN NEXT ;   ( repeat u times )

: DUMP ( b u -- )
  ( Dump u bytes from a, in a formatted manner.)
  BASE @ >R             ( save current radix )
  HEX                   ( always dump in hex )
  16 /                  ( dump 16 bytes at a time)
  FOR CR                ( new line for each 16 bytes )
    16 2DUP dm+         ( dump 16 bytes with address )
    -ROT 2 SPACES _TYPE ( display the ASCII characters )
    NUF? 0=             ( exit the loop if a key is hit )
  WHILE
  NEXT                  ( repeat until all bytes are dumped)
  ELSE R> DROP          ( key hit.  Discard loop count )
  THEN
  DROP R> BASE ! ;      ( restore radix )

( TODO-TEST TODO-IO test DUMP (needs NUF? which needs ?RX )
( LAST @ 48 DUMP 0 TEST )

( === Stack Dump Zen pg100 .S )

: .S ( -- )
  ( Display the contents of the data stack.)
  CR            ( start stack dump on a new line)
  DEPTH         ( get stack depth )
  FOR AFT       ( repeat that many times )
      R@ PICK . ( print one item in stack )
    THEN
  NEXT          ( repeat until done )
  ."  <sp" ;    ( print stack pointer )

1 2 .S 1 2 2 TEST

( === Stack Checking Zen pg101 !CSP ?CSP )

: .BASE ( -- ; report current base in Decimal)
  BASE @ DECIMAL DUP . BASE  ! ;
: .FREE ( -- ; report free memory)
  CP 2@ - U. ;
: !CSP ( -- ; Save stack pointer for error checking )
  SP@ CSP ! ;
: ?CSP ( -- ; Check stack pointer matches saved stack pointer )
  SP@ CSP @ XOR ABORT" stack depth" ;

.BASE .FREE 1 !CSP ?CSP 1 1 TEST

( === Dictionary Dump Zen pg102 .ID WORDS )

: .ID ( na -- )
  ( Display the name at address.)
  ?DUP                ( not valid name if na=0 )
  IF COUNT            ( get length by mask lexicon bits )
    =BYTEMASK AND         ( limit length to 31 characters )
    _TYPE ( print the name string )
    EXIT
  THEN ." {noName}" ; ( error if na is not valid)

: WORDS ( -- )
  ( Display the names in the context vocabulary.)
  CR  CONTEXT @   ( search only the context vocab )
  BEGIN @ ?DUP    ( continue if not end of vocab )
  WHILE DUP SPACE
    .ID           ( print a name)
    CELL-         ( get the link field )
    NUF?          ( exit if a key is hit)
  UNTIL           ( repeat next name )
    DROP
  THEN ;          ( end of vocab exit )

( WORDS 0 TEST ; Commented out as expensive )

( === Search Token Name Zen pg103 >NAME )
: FORTH>NAME ( ca -- na, F ) (
  ( Convert code address to a name address. )
  CURRENT             ( search only the current vocab )
  BEGIN CELL+ @ ?DUP  ( end of vocabulary? )
  WHILE 2DUP
    BEGIN @ DUP
    WHILE 2DUP NAME> XOR ( code pointer=ca? )
    WHILE CELL-
    REPEAT            ( ca not found, repeat next word)
    THEN NIP ?DUP
  UNTIL NIP NIP EXIT  ( found.  return name address )
  THEN DROP 0 ;       ( end of vocabulary, failure )
BL WORD DUP NAME? SWAP >NAME = -1 1 TEST ( Test FAST JS version )
( : >NAME FORTH>NAME ; ) ( Uncomment to use FORTH version of >NAME )
BL WORD DUP NAME? SWAP FORTH>NAME = -1 1 TEST

( === The simplest Decompiler Zen pg104 SEE )
: SEE ( -- ; <string> )
  '                 ( ca)
  CR
  DUP @ tokenDoList =
  IF
    ." : " DUP >NAME .ID ( xt )
    BEGIN CELL+        ( xt+2
      DUP @ DUP         ( xt+2 xt' xt' )
      IF >NAME          ( xt+2 na|F )
      THEN
      ?DUP IF           ( xt+2 na | xt+2)
        SPACE .ID       ( xt+2)
        DUP @ doLIT EXIT = OVER CELL+ @ 20 < AND IF DROP EXIT THEN ( Guess when have end )
      ELSE DUP @ U.     ( xt+2)
      THEN
      NUF?
    UNTIL
  ELSE ." Not colon definition"
  THEN
  DROP ;

( SEE FORTH>NAME 0 TEST ( Commented out as expensive TODO seems to crash out)

( ERRATA Zen uses CONSTANT but doesnt define it )
( === Signon Message Zen pg105 VER hi )

3 CONSTANT VER ( Return the version number of this implementation.)

( ERRATA v5 'hi' doesnt restore BASE )
: hi ( -- )
  !IO           ( initialize terminal I/O )
  CR ." webFORTH V" VER <# # # 46 HOLD # # 46 HOLD # #> TYPE ( display sign-on text and version )
  CR ; COMPILE-ONLY

( === Hardware Reset Zen pg106 COLD )
: EMPTY ( -- )
  ( Empty out any definitions)
  FORTH CONTEXT @ DUP CURRENT 2! ;

CREATE 'BOOT  ' hi , ( application vector )

( ERRATA ZEN uses but doesnt define U0 and assumes US=37 )
: COLD ( -- )
  BEGIN
    userAreaInit  ( initialize user area, often U0 UP =US CMOVE )
    ( initRegisters ; this is needed somewhere - to initialize RP, SP and IP, but clearly must be done by here )
    PRESET        ( Initialize TIB and SP )
    'BOOT @EXECUTE ( Vectored Boot routine, defaults to HI
    FORTH          ( Make FORTH context vocabulary - searches)
    CONTEXT @ DUP CURRENT 2! ( Definitions in FORTH as well )
    ( OVERT         ( And link most recent definition into dictionary  - unclear why this is useful )
    QUIT          ( Invoke Forth "operating system" )
  AGAIN ;         ( Safeguard the Forth interpreter )

: WARM CONSOLE 'BOOT @EXECUTE QUIT ;
`;

let stdinBuffer = null; // Local to ?RX do not access directly - but there can be only one so global

class Forth {
  // Build and return an initialized Forth memory obj
  constructor() {
    // Support paramaters for TODO-11-CELLL TODO-27-MEMORY TODO-28-MULTI
    // === Support for Debugging ============
    this.debugStack = []; // Maintains a position, like a stack trace, don't manipulate directly use functions below
    this.debugName = undefined; // Set in threadtoken()
    this.testing = 0x0; // 0x01 display words passed to interpreters; 0x02 each word in tokenthread - typically set by 'testing3'
    this.testingDepth = 2;
    this.padTestLength = 0; // Display pad length
    // === Javascript structures - implement the memory map and record the full state.
    this.m = Buffer.alloc(EM); // Allocate as one big buffer for now. TODO-27-MEM try alternatives including Uint8Array Uint16Array
    this.jsFunctions = [];  // Maps tokens to executable functions - only accessed through TODO

    // === Standard pointers used - Zen pg22
    // TODO-28-MULTI think about how these may need to be Task specific
    this.IP = 0;    // Interpreter Pointer
    this.SP = SPP;  // Data Stack Pointer
    this.RP = RPP;  // Return Stack Pointer (aka BP in 8086)
    this.UP = UPP;  // User Area Pointer // TODO-28-MULTI will move this around
    this._USER = 0; // Incremented by l.CELLL as define USER's
    // create data structures
    this.buildDictionary();
    // compiling forthInForth is done outside this as it is async TODO-VM API may change.
  }
  // === Build dictionary, mostly from jsFunctionAttributes
  buildDictionary() {
    // Setup pointers for first dictionary entries.
    this.Ustore(CPoffset, CODEE); // Pointer to where compiling into dic
    this.Ustore(NPoffset, NAMEE); // Pointer to where writing name stack
    this.Ustore(TIBoffset, l['=TIB']); // Need work area before this is initialized

    // Define the first word in the dictionary, I'm using 'FORTH' for this because we need this variable to define everything else.
    this.CODE('FORTH');
    this.DW(tokenVocabulary); // Uses assumption that tokenVocabulary is first in jsFunctionAttributes
    this.Ustore(CURRENToffset, this.cpFetch()); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.Ustore(CURRENToffset + l.CELLL, this.cpFetch()); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.Ustore(CONTEXToffset, this.cpFetch()); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.DW(0, 0);
    this.OVERT(); // Uses the initialization done by this.Ustore(CURRENToffset) above.

    // copy constants over
    Object.entries(l).forEach(kv => this.buildConstant(kv[0], kv[1]));

    this.js2xt = {};

    // Make some functions available as Forth words
    jsFunctionAttributes.forEach((attribs) => {
      // Shortcut
      if (typeof attribs === 'string') {
        attribs = { n: attribs };
      }
      const n = attribs.n;
      const f = this[attribs.f || n];
      const tok = this.jsFunctions.length; // Where function will be pushed
      // special case: token Functions that need constants
      this.jsFunctions.push(f);
      if (attribs.token) {
        this.buildConstant(n, tok);
      // regular code functions that just need a pointer.
      } else {
        const xt = this.buildCode(n, tok, attribs);
        //console.assert(xt === this.JSToXT(n));
        if (attribs.jsNeeds) { this.js2xt[n] = xt; } //TODO-VM colon table then replace this
      }
    });

    // build USER variables
    jsUsers.forEach(nv => this.buildUser(nv[0], nv[1]));
  }

  buildConstant(name, val) {
    // Defining function for constants, Replaced by CONSTANT in FORTH
    this.CODE(name);
    // Note assumption that token for constants is 1, i.e. its the 2nd tokenFunction defined
    this.DW(tokenNextVal, val);
    this.OVERT();
  }
  buildCode(name, tok, attribs) {
    this.CODE(name);
    const xt = this.cpFetch();
    this.DW(tok);  // The entire definition is the token for the JS function
    this.OVERT();                          // Make the name usable
    if (attribs.immediate) {
      this.setHeaderBits(l['=IMED']);
    }
    return xt;
  }
  buildUser(name, init) {
    init = typeof init === 'string' ? this.JSToXT(init) : typeof init === 'undefined' ? this.Ufetch(this._USER) : init;
    console.assert(typeof init !== 'undefined');
    this.Ustore(this._USER, init);         // Initialize the variable for live compilation
    this.Mstore(COLDD + this._USER, init); // Store in initialization area for COLD reboot
    if (name) {                       // Put into dictionary
      this.CODE(name);
      this.DW(tokenUser, this._USER);
      this.OVERT();
    }
    this._USER += l.CELLL; // Need to skip to next _USER
  }

  compileForthInForth() {
    this.openBracket(); // Start off interpreting
    return this.interpret(forthInForth); // return a Promise
  }
  cleanupBootstrap() {
    // Cleanup - remove routines that shouldnt be being used
    jsFunctionAttributes.forEach((attribs, i) => {
      if (attribs.replaced) {
        this.jsFunctions[i] = null;
      }
    });
  }

  // === Support for Debugging ============
  debugClear() { this.debugStack = []; }
  debugPush() { this.debugStack.push(this.debugName); } // in tokenDoList
  debugPop() { this.debugStack.pop(); } // in EXIT

  debugThread(xt) {
    if (this.testing & 0x02) {
      this.debugName = this.xt2name(xt); // Expensive so only done when testing
      if (this.testingDepth > this.debugStack.length) {
        console.log('R:', RPP === this.RP ? '' : this.m.slice(this.RP, RPP), this.debugStack, this.xt2name(xt), 'S:', SPP === this.SP ? '' : this.m.slice(this.SP, SPP),
          this.padTestLength ? ('pad: ' + (this.padTestLength > 0 ? this.m.slice(this.padPtr(), this.padPtr() + this.padTestLength) : this.m.slice(this.padPtr() + this.padTestLength, this.padPtr())).toString()) : '');
      }
    }
  }
  // === Code words to support debugging on the console
  // Put debugNA in a definition to print a counted string on the console
  debugNA() { console.log('NAME=', this.countedToJS(this.SPfetch())); } // Print the NA on console
  // Put testing3 in a definition to start outputing stack trace on console.
  testing3() {
    this.testing |= 3; }
  // Put break in a definition.
  break() {
    console.log('break in a FORTH word'); } // Put a breakpoint in your IDE at this line
  // debugPrintTIB will print the current TIB.
  debugPrintTIB() {
    console.log('TIB: ', this.m.slice(this.Ufetch(TIBoffset) + this.Ufetch(INoffset),
      this.Ufetch(TIBoffset) + this.Ufetch(nTIBoffset)).toString('utf8'));
  }
  // TEST will (destructively) check the stack matches expected result, used for testing the compiler.
  // e.g. this.interpret(`10 DUP 10 10 2 TEST`); // Confirm stack finishes with 2 items (10 10)
  TEST() { //  a1 a2 a3 b1 b2 b3 n -- ; Check n parameters on stack
    // eslint-disable-next-line no-unused-vars
    const stackDepth = this.SPpop();
    // Copy stack matching against
    const b = []; // Store matching stack here
    for (let i = 0; i < stackDepth; i++) {
      b.unshift(this.SPpop());
    }
    // Check stack depth matches
    console.assert((SPP - this.SP) / l.CELLL === stackDepth);
    // Compare stacks
    for (let i = 0; i < stackDepth; i++) {
      console.assert(this.SPpop() === b.pop());
    }
    this.debugClear(); // Reset Debug Stack as can be mucked up by THROW and CATCH
  }

  // === Functions to simplify storing and retrieving 16 bit values into 8 bit stacks etc.
  // These aren't part of eForth, but are here to simplify storing multi-byte words into 8 bit bytes in the Buffer.
  //console.assert(l.CELLL === 2); // Presuming its 2 TODO-11-CELLL will need reworking for Uint16Array
  Mfetch(a) { let v = this.m[a++]; let i = l.CELLL - 1; while (i-- > 0) v = (v << 8) | this.m[a++]; return v; }
  // Push below address a, return new pointer (where its stored)
  Mpush(a, v) { let i = l.CELLL; while (i-- > 0) { this.m[--a] = v & 0xFF; v >>= 8; }; return a; }
  // Push at address a, return new pointer above where its stored
  Mstore(a, v) { const a2 = a + l.CELLL; this.Mpush(a2, v); return a2; } // Returns address after the store
  SPfetch() { return this.Mfetch(this.SP); }
  SPpop() { const v = this.Mfetch(this.SP); this.SP += l.CELLL; return v; }
  SPpush(v) { this.SP = this.Mpush(this.SP, v); }
  RPfetch() { return this.Mfetch(this.RP); }
  RPpop() { const v = this.Mfetch(this.RP); this.RP += l.CELLL; return v; }
  RPpush(v) { this.RP = this.Mpush(this.RP, v); }
  IPnext() { const v = this.Mfetch(this.IP); this.IP += l.CELLL; return v; }
  Ufetch(userindex, offset = 0) { return this.Mfetch(this.UP + userindex + offset); }
  Ustore(userindex, w, offset = 0) { return this.Mstore(this.UP + userindex + offset, w); }
  //TODO-11-CELLL add a McharFetch and McharStore and search for uses of this.m[..] as that code presumes reading single byte
  // TODO-11-CELLL look for this.m.copy and this.m.write which assume bytes

  // === Access to the USER variables before they are defined
  currentFetch() { return this.Ufetch(CURRENToffset); }
  cpFetch() { return this.Ufetch(CPoffset); }
  npFetch() { return this.Ufetch(NPoffset); }
  lastFetch() { return this.Ufetch(LASToffset); }
  padPtr() { return this.cpFetch() + 80; } // Sometimes JS needs the pad pointer

  // === Functions related to building 'find'  and its wrappers ====

  // Convert a string made up of a count and that many bytes to a Javascript string.
  // it assumes a maximum of nameMaxLength (31) characters.
  // Mostly used for debugging but also in number conversion.
  countedToJS(a) { //TODO-11-CELLL
    return this.m.slice(a + 1, a + (this.m[a] & l['=BYTEMASK']) + 1).toString('utf8');
  }
  // Convert a name address to the code dictionary definition.
  na2xt(na) {
    return this.Mfetch(na - 2 * l.CELLL);
  }

  // Inner function of find, traverses a linked list Name dictionary.
  // name   javascript string looking for
  // va     pointer holding address of first element in the list.
  // cell1  if present, gives it a quick first-cell test to apply.
  // xt     if present we are looking for name pointing at this executable (for decompiler)
  // returns 0 or na
  // TODO-11-CELLL
  _sameq(na1, na2, chars) { // return f
    // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
    for (let i = 0; i < chars; i++) {
      if (this.m[na1 + i] !== this.m[na2 + i]) {
        return false;
      }
    }
    return true;
  }

  _find(va, na, byte1, xt) { // return na that matches or 0
    let p = va;
    while (p = this.Mfetch(p)) {
      //console.log('_find: comparing:', this.countedToJS(p)) // comment out except when debugging find
      if (xt) {
        if (this.na2xt(p) === xt) {
          return p;
        }
      } else { // Searching on na
        const b1 = this.m[p] & l['=BYTEMASK']; // count TODO-11-CELLL
        if (!byte1 || (byte1 === b1)) { // first cell matches (if cell1 not passed then does slow compare
          if (this._sameq(p + 1, na + 1, b1)) {
            return p;
          }
        }
      }
      p -= l.CELLL; // point at link address and loop for next word
    }
    // Drop through not found
    return 0;
  }

  // Search a single vocabulary for a string
  // This has same footprint as eForth's 'find' but we do not replace it since this is approx 8x faster
  find() { // a va -- ca na | a 0
    const va = this.SPpop();
    const a = this.SPpop();
    const byte1 = this.m[a]; //TODO-11-CELLL
    //console.log('find: Looking for', name) // comment out except when debugging find
    const na = this._find(va, a, byte1);
    if (na) {
      this.SPpush(this.na2xt(na));
      this.SPpush(na);
    } else {
      this.SPpush(a);
      this.SPpush(0);
    }
  }

  // Traverse dictionary to convert xt back to a na (for decompiler or debugging)
  xt2na(xt) {
    return this._find(this.currentFetch(), undefined, undefined, xt);
  }

  // Convert xt to a Javascript string of its name or 'undefined' (only used for debugging).
  xt2name(xt) {
    const na = this.xt2na(xt);
    return na ? this.countedToJS(na) : 'undefined';
  }

  ToNAME() { this.SPpush(this.xt2na(this.SPpop())); }  // Fast version of >NAME see Forth definition below


  // TODO-29-VOCABULARY This just looks up a in the Context vocabulary, it makes no attempt to use multiple vocabularies
  // If required then fixing this to iterate over the context array should not break anything (this is what NAME? does)
  findName() { // a -- xt na | a F
    this.SPpush(this.Ufetch(CONTEXToffset));  // a va
    this.find();                           // xt na | a F
  }

  // -- a; Push a Javascript string to a temporary location as a counted string, and put its address on the stack
  JStoCounted(s) {
    const tempBuf = this.cpFetch() + 50; // Above Code below HLD which builds numbers down from PAD which is cpFetch + 80
    this.m[tempBuf] = s.length;
    this.m.write(s, tempBuf + 1, 'utf8'); // copy string to TIB, and return length
    this.SPpush(tempBuf);
  }

  // Search for a string and return either its XT or 0
  JSToXT(s) {
    this.JStoCounted(s);
    this.findName(); // xt na | a F
    return this.SPpop() ? this.SPpop() : undefined;
  }

  // === JS Functions to be able to define words ==== in Zen pg30 these are Macros.

  $ALIGN() { } // Not applicable since using a byte Buffer TODO-11-CELLL

  // Compile one or more words into the next consecutive code cells.
  DW(...words) {
    words.forEach((word) => this.Ustore(CPoffset, this.Mstore(this.cpFetch(), word)));
  }

  // a -- a; Check if a definition of the word at 'a' would be unique and display warning (but continue) if it would not be.
  // Same profile as ?UNIQUE but not turned into a code word as not used prior to
  qUnique() {
    this.SPpush(this.SPfetch());      // DUP
    this.SPpush(this.currentFetch()); // dictionary to search
    this.find();                 // a xt na | a a F
    if (this.SPpop()) {
      const xt = this.SPpop();              // Discard xt
      const name = this.countedToJS(this.SPfetch());
      if (!['foo', 'bar'].includes(name)) {
        console.log(jsFunctionAttributes[this.Mfetch(xt)].replaced ? 'Expected' : '', 'Duplicate definition of', this.countedToJS(this.SPfetch())); // Catch duplicates - report, but allow
      }
    } else {
      this.SPpop(); // DROP a
    }
  }

  // na -- ; Builds bytes around a newly entered name. Same function as $,n on Zen pg94 used by all defining words (this.CODE ':')
  dollarCommaN() {
    if (this.m[this.SPfetch()]) {         // DUP C@ IF  ; test for no word
      this.qUnique();
      let a = this.SPpop();
      this.Ustore(LASToffset, a);    // DUP LAST ! ; a=na  ; LAST=na
      // Link address points to previous NA (prev value of LAST)
      // Note that first time this is run, it gets a 0 (CURRENT is 0, @0 is 0) if that changes will need to test Current here.
      a = this.Mpush(a, this.Mfetch(this.currentFetch())); // CURRENT @ @ OVER ! ; a = la = top of current dic
      // Push CP (code field to where will build in dictionary) into ca, below a and store that ca into NP
      this.Ustore(NPoffset, this.Mpush(a, this.cpFetch())); // ca=CP ;
    } else {                    // THEN $" name" THROW ;
      console.log('name error'); // This is an error - in FORTH equivalent its a THROW
    }
  }

  // Make the most recent definition available in the directory. This is part of closing every 'defining word'
  OVERT() {
    this.Mstore(this.currentFetch(), this.lastFetch()); // LAST @ CURRENT @ !
  }

  //  Build a new definition - part of all defining words.
  CODE(name) {
    console.assert(name.length <= nameMaxLength);
    // <NP-after>CPh CPl <_LINK> LINKh LINKl count name... <NP-BEFORE>
    this.$ALIGN();
    // Note this is going to give the name string an integral number of cells.
    const len = ((name.length / l.CELLL) + 1) * l.CELLL;
    let a = this.npFetch() - len;
    this.Ustore(NPoffset, a);
    this.SPpush(a); // so this.dollarCommaN can find it
    this.m[a++] = name.length; // This byte will be updated by this.IMMEDIATE() IMMEDIATE or COMPILE-ONLY
    this.m.write(name, a, 'utf8');
    this.dollarCommaN(); // Build the headers that precede the name
  }

  // ERRATA ZEN IMMEDIATE COMPILE-ONLY =COMP =IMED is not defined, in EFORTHv5 its defined as 0x80
  setHeaderBits(b) {
    const lastNA = this.lastFetch(); // LAST points at the name field of the last defined word
    this.m[lastNA] |= b;
  }

  // === Define this tokens used for each kind of defining word
  // Zen pg31
  // Tokens are just JS functions with an entry in jsFunctions with token:true
  // Words that will use a Javascript function for its action are just JS functions with an entry in jsFunctionAttributes

  //TODO-29 define VOCABULARY as CREATE DOES> word then come back and replace this
  tokenVocabulary(payload) {
    // : doVOC R> CONTEXT ! ;
    this.Ustore(CONTEXToffset, payload);
  }

  // Put the contents of the payload (1 word) onto Stack, used for CONSTANT
  tokenNextVal(payload) { this.SPpush(this.Mfetch(payload)); }

  // This is the most important token function - used for a Colon word to iterate over the list.
  tokenDoList(payload) {
    this.debugPush(); // Pop is in EXIT. this will be undefined if not 'testing'
    this.RPpush(this.IP);
    this.IP = payload; // Point at first word in the definition
  }

  // Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
  tokenUser(payload) { this.SPpush(this.Mfetch(payload) + this.UP); }

  // Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
  tokenVar(payload) { this.SPpush(payload); }

  // === INNER INTERPRETER YES THIS IS IT ! ==================== eForthAndZen#36
  // This is quite different from eForth as its token-threaded rather than direct threaded

  threadtoken(xt) {
    // console.assert(xt >= CODEE && xt < NAMEE); // Uncomment to catch bizarre xt values earlier
    // This next section is only done while testing, and outputs a trace, so set it on (with testing3) immediately before a likely error.
    this.debugThread(xt);
    const tok = this.Mfetch(xt);
    xt += l.CELLL;
    // console.assert(tok < this.jsFunctions.length); // commented out for efficiency, a fail will just break in the next line anyway.
    return this.jsFunctions[tok].call(this, xt); // Run the token function - like tokenDoList or tokenVar - will return null or a Promise
  }

  // This is not re-entrant, normally its threadtoken you want ....
  // In particular you cannot use this to nest forth in code in forth
  // If that becomes necessary, it MIGHT work to save IP (where?) and restore after while loop
  // Cant use R or S for it as words use that across calls to the 'EVAL
  async run(xt) {
    let waitFrequency = 0;
    console.assert(this.IP === 0); // Cant nest run()
    await this.threadtoken(xt);
    // If this returns without changing program Counter, it will exit
    while (this.IP) {
      // console.assert(this.IP >= CODEE && this.IP <= NAMEE); // uncomment if tracking down jumping into odd places
      xt = this.IPnext();
      // Comment this out except when needed for debugging, they are slow
      // debugTIB =  this.m.slice(this.Ufetch(TIBoffset) + this.Ufetch(INoffset), this.Ufetch(TIBoffset) + this.Ufetch(nTIBoffset)).toString('utf8');
      // 'await this.threadtoken(xt)' would be legit, but creates a stack frame in critical inner loop, when usually not reqd.
      const maybePromise = this.threadtoken(xt);
      if (maybePromise) {
        await maybePromise;
      } else if (!waitFrequency--) {
        await new Promise(resolve => setImmediate(resolve)); //ASYNC: to allow IO to run
        waitFrequency = 100; // How many cycles to allow a thread swap
      }
    }
  }
  async MS() { // ms --; delay for a period of time.
    await new Promise(resolve => setTimeout(resolve, this.SPpop()));
  }

  BYE() { console.log('TODO-bye'); } // TODO-30-BYE think thru how to exit

  // Unwind the effect of tokenDoList restoring IP to the next definition out.
  // The XT of this is stored in this.js2xt.EXIT
  EXIT() {
    this.debugPop(); // Pushed in tokenDoList
    this.IP = this.RPpop();
  }
  // EXECUTE runs the word on the stack,
  // TODO-ASYNC it works because it itself is a code word, included in colon words
  // and because there is nothing after the return from threadtoken which would get executed out of order
  // Note that it has a return which could be a promise, which the 'run' will await on.
  // This pattern may or may not work in other situations.
  EXECUTE() { this.threadtoken(this.SPpop()); }

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
  QRX() {
    // If there is no data in the buffer, check the stdin and reload the buffer.
    if (!(stdinBuffer && stdinBuffer.length)) {
      const s = process.stdin.read(); // Synchronous
      if (s) stdinBuffer = Buffer.from(s, 'utf8');
    }
    // If there is any data (old or new) in the buffer, return the first character and True
    if (stdinBuffer && stdinBuffer.length) {
      this.SPpush(stdinBuffer[0]);
      stdinBuffer = stdinBuffer.slice(1);
      this.SPpush(forthTrue);
    } else {
      // If there is nothing (old or new) return False
      this.SPpush(0);
    }
  }

  // Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.
  TXbang() {
    process.stdout.write(Uint8Array.from([this.SPpop()])); }

  // Setup I/O to the terminal
  bangIO() {
    if (process.stdin.isTTY) {
      //process.stdout.write('RAW'); //TODO-31-RAW maybe comment out
      //process.stdin.setRawMode();
    }
    process.stdin.setEncoding('utf8');
    process.stdout.setEncoding('utf8');
  }

  // === Literals and Branches - using next value in dictionary === eForthAndZen#37

  // push the value in the next code word
  // The XT of this is stored in this.doLIT
  doLIT() { this.SPpush(this.IPnext()); }

  // Address Literals (aka branches and jumps) eForthAndZen#38

  // decrement count on Return stack, and branch if not decremented past zero (FOR..NEXT)
  next() {
    let x = this.RPpop();
    const destn = this.IPnext(); // Increments over it
    if (--x >= 0) {
      this.RPpush(x);
      this.IP = destn; // Jump back
    }
  }

  // Jump if flag on stack is zero to destn in dictionary
  qBranch() {
    const destn = this.IPnext();
    if (!this.SPpop()) {
      this.IP = destn;
    }
  }
  // Unconditional jump to destn in dictionary
  branch() { this.IP = this.IPnext(); }

  // === Primitive words for memory, stack and return access.

  // Memory access eForthAndZen#39
  store() { this.Mstore(this.SPpop(), this.SPpop()); } //!  w a -- , Store
  fetch() { this.SPpush(this.Mfetch(this.SPpop())); }//@ a -- w, fetch
  // TODO-11-CELLL character access
  cStore() { this.m[this.SPpop()] = this.SPpop(); }//C! c a -- , Store character
  cFetch() { this.SPpush(this.m[this.SPpop()]); }//C@ a -- c, Fetch character

  // Return stack words eForthAndZen#40
  RPat() { this.SPpush(this.RP); } //RP@
  RPbang() { this.RP = this.SPpop(); } // RP!
  Rfrom() { this.SPpush(this.RPpop()); } // R>
  Rat() { this.SPpush(this.RPfetch()); } // R@
  toR() { this.RPpush(this.SPpop()); } // >R

  // Data stack initialization eForthAndZen#41
  SPat() { this.SPpush(this.SP); } //SP@
  SPbang() { this.SP = this.SPpop(); } //SP!

  // Classic Data stack words eForthAndZen#42
  DROP() { this.SP += l.CELLL; }
  DUP() { this.SPpush(this.SPfetch()); }
  SWAP() {
    const x = this.SPpop();
    const y = this.SPpop();
    this.SPpush(x);
    this.SPpush(y);
  }
  OVER() {
    const x = this.SPpop();
    const y = this.SPfetch();
    this.SPpush(x);
    this.SPpush(y);
  } // TODO optimize

  // Logical Words eForthAndZen43
  // noinspection JSBitwiseOperatorUsage
  less0() { this.SPpush((this.SPpop() & (1 << (l.CELLbits - 1))) ? -1 : 0); } //0<  e.g. 0x8000 for CELLL=2
  AND() { this.SPpush(this.SPpop() & this.SPpop()); }
  OR() { this.SPpush(this.SPpop() | this.SPpop()); }
  XOR() { this.SPpush(this.SPpop() ^ this.SPpop()); }

  // Primitive Arithmetic Word eForthAndZen44
  UMplus() {
    const a = this.SPpop();
    const b = this.SPpop();
    if (l.CELLL === 4) {
      // JS truncates to 32 bits before shift, so use it here rather than getting bitten below
      const x = (a>>>0)+(b>>>0);
      this.SPpush(x>>>0);
      this.SPpush(x >= 0x100000000) ? 1 : 0;
    } else {
      // Note there is also what I believe is a JS bug where x >> 32 is a noop
      const x = a + b;
      this.SPpush(x & forthTrue);
      this.SPpush(x >> (l.CELLL * 8));
    }
  }
  // === Define and initialize User variables Zen pg33 see Zen pg46
  // See Zen pg31 for tokenUser etc and $USER and Zen pg33 for USER initialization values

  // TODO-28-MULTITASK will need to think carefully about how to move all, or part of the USER space to task-specific space.
  // TODO-28-MULTITASK this is non-trivial since somethings are clearly across all tasks (e.g. CP and NP)
  userAreaInit() {
    for (let a = 0; a < this._USER; a += l.CELLL) {
      this.Ustore(a, this.Mfetch(COLDD + a));
    }
  }


  // === JS interpreter - could be discarded when done or built out

  PARSE() { // returns b (address) and u (length)
    const delimiter = this.SPpop(); // delimiter
    const tib = this.Ufetch(TIBoffset);
    const ntib = this.Ufetch(nTIBoffset);
    let inoffset = this.Ufetch(INoffset);
    if (delimiter === l.BL) {
      while ((inoffset < ntib) && (this.m[tib + inoffset] <= l.BL)) {
        inoffset++;
      }  // If blank then skip over leading BL /control chars
    }
    // inoffset now points at first non-delimiter or #TIB
    const b = tib + inoffset; // Save start of string
    while ((inoffset < ntib) && ((delimiter === l.BL) ? (delimiter < this.m[tib + inoffset]) : (delimiter !== this.m[tib + inoffset]))) {
      inoffset++;
    } // Exit with inoffset at #TIB or after delimiter
    this.SPpush(b);
    this.SPpush(tib + inoffset - b); // Store length not including trailing delimiter
    this.Ustore(INoffset, inoffset < ntib ? ++inoffset : inoffset); // Skip over delimiter - TODO its not clear this is what FORTH wants. eForth doc is almost certainly wrong
  }

  // JS version of TOKEN - same signature
  TOKEN() { // -- a; <string>; copy blank delimited string to name buffer, immediately below name dictionary (location is important as ':' take a shortcut in eForth.
    this.SPpush(l.BL);
    this.PARSE();   // b u (counted string, adjusts >IN)
    const u = Math.min(this.SPpop(), nameMaxLength); // length of string
    const b = this.SPpop(); // start of string
    const np = this.npFetch() - u - l.CELLL; // Enough space in Name Directory to copy string
    this.m.copy(this.m, np + 1, b, b + u);
    this.m[np] = u;  // 1 byte count
    this.m[np + u + 1] = 0;  // ERRATA  Zen pg62 - PACK$ does `0 !` which I think will overwrite bottom value of name dict as NP is last byte used
    this.SPpush(np); // Note that NP is not updated, the same buffer will be used for each word until hit ':'
  }

  NUMBERQ() { // Same footprint as NUMBER?, this will be stored vectored from 'NUMBER
    const a = this.SPpop();
    const w = this.countedToJS(a); // I believe this is the only place we use this.countedToJS to make JS strings outside of debugging
    const base = this.Ufetch(BASEoffset);
    const n = parseInt(w, base); // TODO-32-ERRORS handle parsing errors // Needs forth to convert word
    if (isNaN(n)) {
      this.SPpush(a);
      this.SPpush(0);
    } else {
      this.SPpush(n);
      this.SPpush(forthTrue);
    }
  }

  // If we are going to compile it, then check its not compiling into the dict, code we plan on replacing. (See same code on "'")
  checkNotCompilingReplaceable(xt, na) {
    if (jsFunctionAttributes[this.Mfetch(xt)].replaced) {
      const inDefOf = this.countedToJS(this.lastFetch());
      if (!['[COMPILE]', '(', 'CREATE'].includes(inDefOf)) { // We redefine ( so ok with redefinition
        console.log('Compiling', this.countedToJS(na), 'in', inDefOf, 'when code will be deleted');
        console.assert(false); // Break here, shouldn't be happening.
      }
    }
  }

  async $COMPILE() { // a -- ...; same signature as to $COMPILE at Zen pg96
    this.findName(); // xt na | a F
    const na = this.SPpop();
    if (na) { // ca
      const xt = this.SPpop();
      const ch = this.m[na];
      // noinspection JSBitwiseOperatorUsage
      if (ch & l['=IMED']) {
        await this.run(xt); // This will work as long as this $INTERPRET never called from Forth as cant nest 'run' even indirectly
      } else {
        this.checkNotCompilingReplaceable(xt, na);
        if (this.testing & 0x02) console.log('COMPILING:', this.countedToJS(na));
        this.DW(xt);
      }
    } else { // a
      await this.run(this.Ufetch(NUMBERoffset)); // n T | a F // Works as long as NUMBER is code, OR this is called from code.
      if (this.SPpop()) {
        this.DW(this.js2xt.doLIT, this.SPpop());
      } else {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        console.log('Number conversion of', this.countedToJS(this.SPpop()), 'failed');
      }
    }
  }

  async $INTERPRET() { // a -- ...; Based on signature of $INTERPRET at Zen pg83
    this.findName(); // xt na | a F
    const na = this.SPpop();
    if (na) { // ca
      const xt = this.SPpop();
      await this.run(xt); //TODO-ASYNC maybe should be threadToken - but that won't work if this isn't running inside run already
    } else {
      await this.run(this.Ufetch(NUMBERoffset)); // n T | a F
      if (!this.SPpop()) {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        console.log('Number conversion of', this.countedToJS(this.SPpop()), 'failed');
      }
    }
  }

  JStoTIB(s) {
    console.assert(s.length < (RTS - 10)); // Check for overlong lines
    this.Ustore(INoffset, 0); // Start at beginning of TIB
    this.Ustore(nTIBoffset,  this.m.write(s, this.Ufetch(TIBoffset), 'utf8')); // copy string to TIB, and store length in #TIB
  }
  // equivalent to Forth EVAL with few things wrapped around it - so not exact same TODO align it
  async EVAL(inp) {
    if (this.testing & 0x01) {
      console.log(this.m.slice(this.SP, SPP), ' >>', inp);
    }
    this.JStoTIB(inp);
    while (this.Ufetch(INoffset) < this.Ufetch(nTIBoffset)) {
      this.TOKEN(); // a ; pointing to word in Name Buffer (NB)
      // There may be case where this.TOKEN returns empty string at end of line or similar
      if (this.m[this.SPfetch()] === 0) { // Skip zero length string
        this.SPpop();
      } else {
        // This is currently OK since its calling JS routines that may call Forth, there is no Forth-in-Forth
        await this.run(this.Ufetch(EVALoffset));
      }
      console.assert(this.SP <= SPP && this.RP <= RPP); // Side effect of making SP and SPP available to debugger.
    }
  }

  // Take a multiline string, and pass line by line to EVAL
  async interpret(inp) {
    const inputs = inp.split('\n');
    // eslint-disable-next-line no-restricted-syntax,guard-for-in
    for (const i in inputs) {
      await this.EVAL(inputs[i]);
    }
  }

  // === A group of words required for the JS interpreter redefined later

  // : [  doLIT $INTERPRET 'EVAL ! ; IMMEDIATE
  //Zen pg84 and Zen pg88  redefined below to use FORTH $INTERPRET
  openBracket() {
    this.Ustore(EVALoffset, this.js2xt.$INTERPRET); // uses JS $INTERPRET
  }

  // : ] doLIT $COMPILE 'EVAL ! ;
  //Zen pg84 and Zen pg95  redefined below to use FORTH $COMPILE
  closeBracket() {
    this.Ustore(EVALoffset, this.js2xt.$COMPILE);
  }

  // : : TOKEN $,n [ ' doLIST ] LITERAL ] ; see Zen pg96
  colon() {
    this.TOKEN();  // a; (counted string in named space)
    this.dollarCommaN();
    this.DW(tokenDoList); // Must be after creating the name and links etc
    this.closeBracket();
  }

  // : ; doLIT EXIT , OVERT [ ;
  semicolon() { // Zen pg95
    this.DW(this.js2xt.EXIT); //TODO-VM use a simplified interpreter then replace the setting of this.js2xt.EXIT
    this.OVERT();
    this.openBracket();
  }

  // : ' ( -- xt ) TOKEN NAME? IF EXIT THEN THROW ; // Zen pg89 needs TOKEN NAME? THROW all of which are advanced
  tick() { // -- xt; Search for next word in input stream
    this.TOKEN(); // -- a; String with count in first byte
    //const a = this.SPfetch(); // used for debugging
    this.findName(); // xt na | a 0
    const na = this.SPpop();
    if (!na) {
      console.error(this.countedToJS(this.SPpop()), "not found during '");
    } else {
      // For debugging need to make sure we are not including code that will replaced by Forth versions.
      this.checkNotCompilingReplaceable(this.SPfetch(), na);
    }
  }

  console() {
    return this.run(this.JSToXT('WARM'));
  }
  // TODO-29 define DOES> for CREATE-DOES> and tokenDoes - this is not part of eForth, THEN defined Vocabulary as CREATE-DOES word
  //tokenDoes = Forth.tokenFunction(payload => { this.RPpush(this.IP); this.IP = (this.m[payload++]<<8)+this.m[payload++]; this.SPpush(payload++); ); // Almost same as tokenDoList
}
/*
const foo = new Forth();
foo.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => foo.cleanupBootstrap())
  //.then(() => console.log('===forthInForth cleaned up'))
  //.then(() => foo.interpret("WARM"));
  .then(() => foo.console())
  .then(() => console.log('console exited'));
*/
module.exports = exports = Forth;
