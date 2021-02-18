/*
 *
 * const Forth = require('webforth');   // The class or obj with functions
 * foo = new Forth()                    // Instantiate a new, but incomplete instance
 * foo.compileForthInForth()            // Load the parts of Forth written in Forth
 * .then(() => foo.interpret("1 2 DUP .S")); // Run some Forth words in the instance
 * .then(() => forth.console());        // Go interactive
 * new Forth({ CELLL: 2, MEM: 16, RAMSIZE: 0x4000);  // parameterizable
 *
 * And some ideas ... not yet implemented
 * .then(() => foo.load('foo.f'))       // TODO-34-FILES Load file into the class
 * .then(() => foo.load('https://....')) // TODO-34-FILES remote file it into the instance
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

/*
  This table maps the functions that go in the dictionary to the function names in the instance.
  'foo':          Create a forth word foo linked to Forth.prototype.foo
   {  n: 'foo'    Name of forth word
      f: bar      Links to Forth.prototype.bar (defaults to same as 'n'
      token: true Create a token word that can be used as first cell of a definition - order must match constants below
      replaced: true  This word will be replaced by a Forth definition, so check for its being compiled into other definitions. TODO-83-DEFER possibly obsoleted by defer
      defer: true Build a DEFER structure and point at the definition, typically replaced later by Forth word
      jsNeeds: true The execution address of this word is needed by the JS o will be stored in js2xt[n]
 */
// it is used to build the dictionary in each instance.
const jsFunctionAttributes = [
  0, // 0 is not a valid token
  // This next list of token's must match in order the constants defined for tokenCreate etc.
  { n: 'tokenVocabulary', token: true }, // Token used for Vocabularies must be first 1
  { n: 'tokenNextVal', token: true }, // Token used for Constants must be next (2)
  { n: 'tokenDoList', token: true },
  { n: 'tokenUser', token: true },
  { n: 'tokenVar', token: true },
  { n: 'tokenCreate', token: true },
  { n: 'tokenDefer', token: true }, // Execute payload (like DoList but just one)
  { n: 'tokenValue', token: true }, // Returns value from a user variable.
  'ALIGNED',
  { n: 'find', f: 'jsFind' }, // Fast version of find - see Forth definition later
  { n: 'OVERT', replaced: true, defer: true },
  // { n: '?UNIQUE', f: 'qUnique' }, // Not used yet
  { n: '$,n', f: 'dollarCommaN', replaced: true, defer: true },
  { n: '>NAME', f: 'ToNAME' }, // Fast version of >NAME - see Forth definition later
  'MS', 'BYE', { n: 'EXIT', jsNeeds: true }, 'EXECUTE',
  { n: '?RX', f: 'QRX' }, {  n: 'TX!', f: 'TXbang' }, { n: '!IO', f: 'bangIO' },
  { n: 'doLIT', jsNeeds: true }, { n: 'DOES>', f: 'DOES' }, 'next', { n: '?branch', f: 'qBranch' }, 'branch',
  { n: '!', f: 'store' }, { n: '@', f: 'fetch' }, { n: 'C@', f: 'cFetch' }, { n: 'C!', f: 'cStore' },
  { n: 'RP@', f: 'RPat' }, { n: 'RP!', f: 'RPbang' }, { n: 'R>', f: 'Rfrom'  }, { n: 'R@', f: 'Rat'  }, { n: '>R', f: 'toR'  },
  { n: '2R>', f: 'TwoRfrom'  }, { n: '2R@', f: 'TwoRat'  }, { n: '2>R', f: 'TwoToR'  },
  { n: 'SP@', f: 'SPat' }, { n: 'SP!', f: 'SPbang' },
  'DROP', 'DUP', 'SWAP', 'OVER',
  { n: '0<', f: 'less0' }, 'AND', 'OR', 'XOR', { n: 'UM+', f: 'UMplus' },
  /* TODO-ARDUINO needs this line */ 'RSHIFT', 'LSHIFT', { n: '2/', f: 'TwoDiv' },
  'userAreaInit', 'userAreaSave',
  { n: 'PARSE', replaced: true, defer: true }, { n: 'TOKEN', replaced: true, defer: true }, { n: 'NUMBER?', f: 'NUMBERQ', replaced: true, defer: true },
  { n: '$COMPILE', f: 'dCOMPILE', replaced: true, defer: true }, { n: '$INTERPRET', f: 'dINTERPRET', replaced: true, jsNeeds: true, defer: true },
  { n: '[', f: 'openBracket', immediate: true, replaced: true, defer: true }, { n: ']', f: 'closeBracket', replaced: true, defer: true },
  { n: ':', f: 'colon', replaced: true, defer: true }, { n: ';', f: 'semicolon', immediate: true, replaced: true, defer: true }, { n: "'", f: 'tick', replaced: true, defer: true },
  'debugNA', 'testing3', 'Fbreak', 'debugPrintTIB', 'TEST', 'stringBuffer', 'TYPE',
  // TODO-ARDUINO needs from here down - some could be in Forth instead
  'loop', 'I', 'leave', 'RDROP', { n: '2RDROP', f: 'TwoRDROP' }, { n: 'FIND-NAME-IN', f: 'FIND_NAME_IN' }, { n: 'immediate?', f: 'immediateQ' },
  { n: 'ALIGN', f: 'vpAlign' }, { n: '>BODY', f: 'toBODY' }, 'DEFER', 'ROLL', 'ROT', 'of',
];

// Define the tokens used in the first cell of each word.
// Order must match the order of functions defined above with token: true
// 0 is an invalid token so that a 0 is never indirected through.
const tokenVocabulary = 1;
const tokenNextVal = 2;
const tokenDoList = 3;
const tokenUser = 4;
const tokenVar = 5;
const tokenCreate = 6;
const tokenDefer = 7;
const tokenValue = 8;

// ported to Arduino below to L.115
// === Memory Map - Zen pg26
const l = {}; // Constants that will get compiled into the dictionary
l.COMP = 0x40; // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
l.IMED = 0x80; // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
const bitsSPARE = 0x20; // Unused spare bit in names
l.BYTEMASK = 0xFF - l.COMP - l.IMED - bitsSPARE; // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
//l.TRUE = (2 ** (l.CELLL * 8)) - 1; // Also used to mask numbers
l.TRUE = -1; // Not quite correct, should be masked BUT when pushed that it is done underneath
l.FALSE = 0;
const nameMaxLength = 31; // Max number of characters in a name, length needs to be representable after BitMask (we have one spare bit here)
console.assert(nameMaxLength === l.BYTEMASK); // If this isn't true then check each of the usages below
l.BL = 32;

// === Data table used to build users.
// later the FORTH word 'USER' is defined but unlike this function it doesn't setup initialization, nor does it auto-increment to next available user slot.
// These definitions can refer to v: 'foo' to be initialized to a Forth word (which must be in jsFunctionAttributes)
// or the contents of a property of the forth instance (e.g. Forth.prototype.TIB0
const jsUsers = []; // Note 4 cells skipped for multitasking but that is in init of _USER to 4*CELLL
function USER(n, v) { jsUsers.push([n, v]); return (jsUsers.length - 1); }
USER('_USER', 0); // Size of user area
USER(undefined, 0); // Used for multitasking
USER(undefined, 0); // Used for multitasking
USER(undefined, 0); // Used for multitasking
const SP0offset = USER('SP0', undefined);      // (--a) Pointer to bottom of the data stack.
const RP0offset = USER('RP0', undefined);      // (--a) Pointer to bottom of the return stack.
USER("'?KEY", '?RX');    // Execution vector of ?KEY. Default to ?rx.
USER("'EMIT", 'TX!');  // Execution vector of EMIT. Default to TX!
// eForth difference - this next one is 'EXPECT in EFORTH )
USER('SPARE', 0);
// TODO-34-FILES consider if still want vectored I/O or prefer decision based on SOURCE-ID
USER("'TAP", 0);       // Execution vector of TAP. Default to kTAP.
USER("'ECHO", 'TX!');  // Execution vector of ECHO. Default to tx! but changed to ' EMIT later.
const PROMPToffset = USER("'PROMPT", 0);    // Execution vector of PROMPT.  Default to '.ok'.
const BASEoffset = USER('BASE', 10);
USER('temp', 0);       // A temporary storage location used in parse and find. EFORTH-ZEN-ERRATA its uses as 'temp', listing says 'tmp'
USER('SPAN', 0);       // Hold character count received by EXPECT (TODO strangely it is stored, but not accessed and EXPECT never used )
const INoffset = USER('>IN', 0);        // Hold the character pointer while parsing input stream.
const nTIBoffset = USER('#TIB', 0);       // Hold the current count of the terminal input buffer.
const TIBoffset = USER(undefined, 'TIB0');  // Hold current address of Terminal Input Buffer (must be cell after #TIB.)
USER('CSP', 0);        // Hold the stack pointer for error checking.
// eFORTH diff - eFORTH uses EVAL as vector to either $INTERPRET or $COMPILE, ANS uses a variable called STATE
const STATEoffset = USER('STATE', l.FALSE); // True if compiling - only changed by [ ] : ; ABORT QUIT https://forth-standard.org/standard/core/STATE
//const EVALoffset = USER("'EVAL", 0);      // Initialized when have JS $INTERPRET, this switches between $INTERPRET and $COMPILE
USER('SPARE2', 0);
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
// Not e there is a (hidden) assumption that CP and NP are consecutive - used to check free space
const CPoffset = USER('CP', undefined);  // eForth initializes to CTOP but we have to use this during compilation
const NPoffset = USER('NP', undefined);  // normally set on Zen pg106 but we are using it live. Its the bottom of what compiled in name space.
const LASToffset = USER('LAST', undefined); // normally set on Zen pg106 but using live
const VPoffset = USER('VP', undefined);  // not part of eForth, pointer into Data space for EPROMability
USER('SOURCE-ID', 0);  // 0 for terminal, -1 for string, fd for files
const testFlagsOffset = USER('testFlags', 0); // bit field: 1 trace interpreter 2 trace threading 4 safety checks 8 tests TODO-67-TESTING - see unreadFile above //TODO-2ARDUINO
const testDepthOffset = USER('testDepth', 0);  // Needs to autoadjust //TODO-2ARDUINO
// ported to Arduino above

const forthInForth = `
0 TEST
: 2DROP DROP DROP ;
1 2 2DROP 0 TEST

: setHeaderBits LAST @ C@ OR LAST @ C! ;
: COMPILE-ONLY COMP setHeaderBits ;
: IMMEDIATE IMED setHeaderBits ;

: ( 41 PARSE 2DROP ; IMMEDIATE ( from Zen pg74, note dont have LITERAL so cant do [ CHAR ( ] LITERAL instead of 41 )
: \\ ( -- ; Ignore following text till the end of line.)
   #TIB @ >IN ! ( store the length of TIB in >IN )
   ; IMMEDIATE ( in effect ignore the rest of a line )
( Now these are defined we can use both kinds of comments below here )

1 2 ( 3 ) 1 2 2 TEST

( Uncomment first for production, 2nd for testing )

( TODO add a test here, or elsewhere for things like: CP+PAD+StringBuffer > NP) 

( === Test as many of the words defined in code as possible)
( EXIT & EXECUTE tested with ' )
( doLIT implicitly tested by all literals )
( next, ?branch, branch implicitly tested by control structures )
123 HLD ! HLD @ 123 1 TEST ( Also tests user variables )
222 HLD C! HLD C@ 222 1 TEST
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
: TUCK SWAP OVER ; ( w1 w2 -- w2 w1 w2 ; tuck top of stack under 2nd )
1 2 NIP 2 1 TEST
1 2 TUCK 2 1 2 3 TEST

( Note failure on this line, can be for three reasons )
( a: its the first execution of an immediate word inside a compilation )
( b: its the first execution of a word defined with a colon )
( c: its the first use of the comment
: HERE ( -- a; return top of code dictionary; Zen pg60) CP @ ;
( test is non-obvious )

( Note eForth has +, but that isn't defined till Zen pg50 )
: CELL+ CELLL UM+ DROP ;

( ERRATA - Zen pg57 presumes CELLL==2 and need to align, not case with JS and byte Buffer, moved to code )

( ERRATA v5 skips ALIGNED form this definition)
: , ( w --; Compile an integer into the code dictionary. Zen pg 89)
  HERE ALIGNED DUP CELL+ CP ! ! ;

: [COMPILE] ( -- ; <string> ) ' , ; IMMEDIATE

: COMPILE ( --; Compile the next address in colon list to code dictionary. Zen pg 90)
  R> DUP @ , CELL+ >R ; COMPILE-ONLY

: LITERAL ( w -- ) ( Compile tos to code dictionary as an integer literal.)
  COMPILE doLIT ( compile doLIT to head lit )
  , ; IMMEDIATE ( compile literal itself )

: create TOKEN $,n OVERT , 0 , ; 
( Create a new word that doesnt allocate any space, but will push address of that space. )
( redefines definitions moved up so that they will use new TOKEN etc)
: CREATE tokenCreate create ; ( Note the extra field for DOES> to patch - redefines definition moved up so that it will use new TOKEN etc)
( TODO-TEST test of above group non-obvious as writing to dictionary. )

( === Control structures - were on Zen pg91 but needed earlier Zen pg 91-92 but moved early )
( this version comes from EFORTH-V5 which introduced MARK> >MARK )

( FOR-I-NEXT FOR-AFT-I-THEN-NEXT BEGIN-AGAIN BEGIN-WHILE-REPEAT BEGIN-UNTIL IF-ELSE-THEN ?WHEN DO-I-LOOP)
: <MARK ( -- a ) HERE ; \\ Leave an address suitable for <RESOLVE
: <RESOLVE ( a -- ) , ; \\ Resolve a link back to start of structure (e.g. in a loop)
: >MARK ( -- A ) HERE 0 , ; \\ Leave a space to put a jump destination
: >RESOLVE ( A -- ) <MARK SWAP ! ; \\ Resolve a forward jump destination
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
: WHEN ( a -- a A a ) [COMPILE] IF OVER ; IMMEDIATE ( Cannot find documentation on how this is used )
: WHILE ( a -- A a )    [COMPILE] IF SWAP ; IMMEDIATE
: ?DUP DUP IF DUP THEN ; ( w--ww|0) ( Dup top of stack if its is not zero.)
: >RESOLVES ( 0 A* -- ) BEGIN ?DUP WHILE >RESOLVE REPEAT ; ( Resolve zero or more forward branches e.g. from multiple LEAVE )
: >MARKSTART 0 ;
: >MARKTHREAD ( A -- A' ) HERE SWAP , ; \\ Leave a space for a jump destination, but mark a jump back 
: >RESOLVETHREAD ( A -- ) \\ Resolve a set of forward jumps
  BEGIN ?DUP WHILE DUP @ SWAP >RESOLVE REPEAT ; 
: CASE >MARKSTART ; IMMEDIATE \\ Leave head of >MARKTHREAD chain
: OF COMPILE of >MARK ; IMMEDIATE
: ENDOF COMPILE branch SWAP >MARKTHREAD SWAP >RESOLVE ; IMMEDIATE
: ENDCASE COMPILE DROP >RESOLVETHREAD ; IMMEDIATE

( TODO-TEST of above group non-obvious as writing to dictionary. )
( IF-THEN tested in ?DUP; )

: 0= IF FALSE ELSE TRUE THEN ;
: 0<> 0= 0= ;
: D0= OR 0= ;
: ?\\ ( f -- ; Conditional compilation/interpretation - comment out if f is 0 )
  0= IF [COMPILE] \\ THEN ; IMMEDIATE 
: ?safe\\ ( compilation/interpretation line if checking for safety - overflows etc )
  testFlags @ 4 AND [COMPILE] ?\\ ; IMMEDIATE
: ?test\\  ( compilation/interpretation line if running compile time tests )
  testFlags @ 8 AND [COMPILE] ?\\ ; IMMEDIATE

( === Multitasking Zen pg48 - not implemented in eForth TODO )

( === More Stack Words Zen pg49 TODO-OPTIMIZE )
: -ROT SWAP >R SWAP R> ; ( w1, w2, w3 -- w3 w1 w2; Rotate top item to third)
: 2DUP OVER OVER ; ( w1 w2 -- w1 w2 w1 w2;)
: 2OVER >R >R 2DUP R> -ROT R> -ROT ; ( w1 w2 w3 w4 -- w1 w2 w3 w4 w1 w2 )
: 2SWAP >R -ROT R> -ROT ; ( w1 w2 w3 w4 -- w3 w4 w1 w2 )
( 2DROP & NIP moved earlier )

?test\\ 1 ?DUP 0 ?DUP 1 1 0 3 TEST
?test\\ 1 2 3 ROT 2 3 1 3 TEST
?test\\ 1 2 2DUP 1 2 1 2 4 TEST

( === More Arithmetic operators Zen pg50 and a few not in eForth but widely used )
: + UM+ DROP ; ( w1 w2 -- w1+w2)
: D+ >R SWAP >R UM+ R> R> + + ; ( d1 d2 -- d1+d2)
: INVERT -1 XOR ; ( w -- w; 1's compliment)
( NOT's meaning is deprecated use 0= logical or INVERT bitwise see http://lars.nocrew.org/forth2012/core/INVERT.html)
: 1+ 1 + ; 
: NEGATE INVERT  1+ ; ( w -- w; 2's complement)
: DNEGATE INVERT >R INVERT  1 UM+ R> + ;
: - NEGATE + ; ( n1 n2 -- n1-n2)
: ?negate ( n1 n2 -- n1|-n1 ; negate n1 if n2 negative)
  0< IF NEGATE THEN ; 
: 1- 1 - ; 

: ABS DUP ?negate ; ( n -- n; Absolute value of w)

: CHAR+ 1+ ; 
: C, ( c --; Compile a single character into code dictionary and advance pointer 1 character )
  HERE DUP CHAR+ CP ! C! ; 


?test\\ 1 2 + 3 1 TEST
?test\\ -1 1 -1 3 D+ -2 5 2 TEST ( Test contrived to be CELLL independent )
?test\\ 257 INVERT -258 1 TEST ( 257 is 0x101 65278 is 0xFEFE )
?test\\ 53 NEGATE 53 + 0 1 TEST
?test\\ 456 123 - 456 -123 - 333 579 2 TEST
?test\\ -456 ABS 456 ABS - 0 1 TEST
?test\\ 111 >R R@ RP@ R> SWAP RP@ SWAP - 111 111 CELLL 3 TEST
?test\\ 1 2 SP@ CELL+ SP! 1 1 TEST

( === More comparison Zen pg51-52 - ud< is added)
: = XOR IF FALSE EXIT THEN TRUE ; ( w w -- t)
: <> XOR IF TRUE EXIT THEN FALSE ; ( w w -- t; from ANS not eForth)
: U< 2DUP XOR 0< IF NIP 0< EXIT THEN - 0< ;
: U> SWAP U< ;
: ud< ( ud ud -- f ) ROT SWAP U< IF 2DROP TRUE ELSE U< THEN ;
: < 2DUP XOR 0< IF DROP 0< EXIT THEN - 0< ;
: > SWAP < ;
: MAX 2DUP < IF SWAP THEN DROP ;
: MIN 2DUP SWAP < IF SWAP THEN DROP ;
: WITHIN OVER - >R - R> U< ;

?test\\ 123 123 = 123 124 = -1 0 2 TEST
?test\\ 123 100 U< 100 123 U< 123 -100 U< -100 123 U< 0 -1 -1 0 4 TEST
?test\\ 123 100 < 100 123 < 123 -100 < -100 123 < 0 -1 0 -1 4 TEST
?test\\ 100 200 MAX 300 100 MAX 200 300 2 TEST
?test\\ 100 200 MIN 300 100 MIN 100 100 2 TEST
?test\\ 200 100 300 WITHIN 300 100 200 WITHIN 100 -100 200 WITHIN -1 0 -1 3 TEST

: S>D DUP 0< ; ( n -- d)

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
          1+ R>
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
: FM/MOD ( d n -- r q) M/MOD ; \\ Forth2012 https://github.com/NieDzejkob/2klinux.git

: /MOD ( n1 n2 -- r q)
  ( Signed divide. Return mod and quotient)
  >R S>D R> ( d1 n2 ; sign extend n1)
  M/MOD     ( floored divide)
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

?test\\ -1 1 2 UM/MOD 1 -1 2 TEST
?test\\ -1 1 2 M/MOD 1 -1 2 TEST
?test\\ 9 0 4 UM/MOD 1 2 2 TEST
?test\\ 9 4 /MOD 1 2 2 TEST
?test\\ 9 4 MOD 1 1 TEST
?test\\ 9 4 / 2 1 TEST
?test\\ 2 -1 UM* -2 1 2 TEST
?test\\ 3 4 * 12 1 TEST
?test\\ -2 -3 M* 6 0 2 TEST

( === Scaling Words Zen pg56 */MOD */ )

: */MOD ( n1 n2 n3 -- r q )
  ( Multiply n1 and n2, then divide by n3. Return mod and quotient)
  >R M*       ( n1*n2)
  R> M/MOD ;  ( n1*n2/n3 with remainder)

: */ ( n1 n2 n3 -- q )
  ( Multiple by n1 by n2, then divide by n3. Return quotient only)
  */MOD NIP ; ( n1*n2/n3 and discard remainder)

?test\\ 5 7 2 */MOD 1 17 2 TEST
?test\\ 5 7 2 */ 17 1 TEST

( === More arithmetic needed for ANS compliance ==== )
\\ TODO-DOUBLE word set https://forth-standard.org/standard/double
\\ implemented: D0< D0= DABS
\\ not implemented yet: 2CONSTANT 2LITERAL D+ D- D. D.R D2* D2/ D< D= D>S DMAX DMIN DNEGATE M * / M+
: D0< ( d -- f ; check if d is negative ) NIP 0< ;  
: DABS ( d -- abs d ; https://forth-standard.org/standard/double/DABS )
  2DUP D0< IF DNEGATE THEN ;
: SM/REM ( d1 n1 -- n2 n3 ; copied from FlashForth)
  2DUP XOR >R
  OVER >R
  ABS >R DABS R> UM/MOD
  SWAP R> ?negate
  SWAP R> ?negate
;

( === Memory Alignment words Zen pg57 CELL+ CELL- CELLS ALIGNED )
( CELL+ & ALIGNED moved earlier ERRATA Zen & v5 use 2 which is wrong unless CELL is '2' )

: CELL- ( a -- a)
  ( Subtract cell size in byte from address)
  CELLL - ;

: CELLS ( n - n )
  ( Multiply n by cell size in bytes)
  CELLL * ;

: CHARS ; \\ A noop since 1 address unit per char - note this is ANS CHARS, eFORTH CHARS is now emits
: 2* 2 * ; \\ TODO-83 This should be optimized to a left shift and then find where used

?test\\ 123 CELL- CELLL + 123 1 TEST
?test\\ 123 CELLS CELLL / 123 1 TEST

: ($,n)  ( na -- )
    ( na) DUP LAST !          ( save na for vocabulary link for OVERT)
    ( na) HERE ALIGNED SWAP   ( align code address )
    ( cp na) CELL-            ( link address )
    ( cp la) CURRENT @ @      ( link to current vocab)
    ( cp la na') OVER !
    ( cp la) CELL- DUP NP !   ( adjust name pointer )
    ( ptr) !                  ( save code pointer )
;
: :NONAME ( -- xt )
  NP @ CELL- 0 OVER ! DUP NP !
  ($,n)
  HERE            \\ Returns xt 
  tokenDoList , 
  ] 
;
( Words associated with DEFER - from Forth2012)
: DEFER@ ( xt -- a; ) >BODY @ ;
: >BODY! >BODY ! ;
: DEFER! ( xt1 xt2 --; ) >BODY! ; 



\\ Math routines from Forth2012
( see also in functions e.g. RSHIFT )


( === Special Characters Zen pg58 BL >CHAR )

( BL moved earlier)

: >CHAR ( c -- c; filter non printing characters, replace by _)
  127 AND DUP   ( mask off the MSB bit)
  127 BL WITHIN ( if its a control character)
  IF DROP 95 THEN ; ( replace with an underscore)

?test\\ 41 >CHAR 23 >CHAR BL >CHAR 41 95 32 3 TEST

( === Managing Data Stack Zen pg59 DEPTH PICK )

( ERRATA Staapl, v5, zen, has 2/ )
: DEPTH ( -- n)
  ( Return the depth of the data stack)
  SP@           ( current stack pointer)
  SP0 @ SWAP -  ( distance from stack origin)
  CELLL / ;     ( divide by bytes/cell)

: PICK ( ... +n -- ... w)
  ( Copy the nth stack item to tos)
  1+ CELLS     ( bytes below tos)
  SP@ + @ ;     ( fetch directly from stack)

?test\\ 1 2 3 DEPTH 1 2 3 3 4 TEST
?test\\ 11 22 33 1 PICK 11 22 33 22 4 TEST

( === Memory Access Zen pg60 +! 2! 2@ HERE PAD TIB @EXECUTE )
( Note 2! 2@ presume big-endian which is a Forth assumption (high word at low address)

: +! ( n a -- ; Add n to the contents at address a)
  SWAP OVER @ + SWAP ! ;
: ++ 1 SWAP +! ;
: -- -1 SWAP +! ;
: 2! ( d a -- ; Store double integer to address a, high part at low address)
  SWAP OVER ! CELL+ ! ;
: 2@ ( a -- d; Fetch double integer from address a, high part from low address)
  DUP CELL+ @ SWAP @ ;
( HERE is defined in moved forward words)

( Support Data separation from Code TODO rethink this as always having some code)
: vHERE ( -- a; top of data space - code space if none or after back in Ram) VP @ ?DUP IF EXIT THEN HERE ;
: v, ( w --; Compile an integer into the data area if used, else code dictionary (not part of eForth)
  VP @ ?DUP IF ALIGNED DUP CELL+ VP ! ! ELSE , THEN ;
( vCREATE is like CREATE but if VP is set it makes space in the writable DATA area) 
: vALIGN VP @ ALIGNED VP ! ; 
( vCREATE is like CREATE but if VP is set it makes space in the writable DATA area) 
: vCREATE ( -- ; <string> ) VP @ ?DUP IF tokenVar create vALIGN , ELSE CREATE THEN ; ( Compile pointer to data area )
: PAD ( -- a; Return address of a temporary buffer above code dic)
  HERE 80 + ;

: TIB ( -- a; Return address of terminal input buffer)
  #TIB CELL+ @ ; ( 1 cell after #TIB)
: @EXECUTE ( a -- ; execute vector -if any- stored in address a)
  @ ?DUP IF EXECUTE THEN ;

?test\\ HLD @ 2 HLD +! HLD @ SWAP - 2 1 TEST
?test\\ 1 2 3 SP@ 4 5 ROT 2! 1 4 5 3 TEST
?test\\ 1 2 3 SP@ 2@ 1 2 3 2 3 5 TEST
?test\\ >IN @ BL PARSE XXX SWAP TIB - ROT - 3 9 2 TEST

( === Memory Array and String Zen pg61-62: COUNT CMOVE FILL -TRAILING PACK$ )

: COUNT ( b -- b+1 +n; return count byte of string and add 1 to byte address)
  DUP 1+ SWAP C@ ;

: CMOVE ( b1 b2 u -- ; Copy u bytes from b1 to b2)
  FOR             ( repeat u+1 times)
    AFT           ( skip to THEN first time)
      >R DUP C@   ( fetch from source )
      R@ C!       ( store to destination)
      1+         ( increment source address)
      R> 1+      ( increment destination address)
    THEN
  NEXT 2DROP ;    ( done discard addresses)

: CMOVE> ( b1 b2 u -- ; Copy u bytes from b1 to b2 starting high)
  >R SWAP R@ 1- + SWAP R@ 1- + R>
  FOR             ( repeat u+1 times)
    AFT           ( skip to THEN first time)
      >R DUP C@   ( fetch from source )
      R@ C!       ( store to destination)
      1-         ( increment source address)
      R> 1-      ( increment destination address)
    THEN
  NEXT 2DROP ;    ( done discard addresses)

: FILL ( b u c --; Fill u bytes of character c to area beginning at b.)
  SWAP            ( b c u)
  FOR             ( loop u+1 times)
    SWAP          ( c b )
    AFT           ( skip to THEN)
      2DUP C!     ( c b; store c to b)
      1+         ( c b+1; increment b)
    THEN
  NEXT 2DROP ;    ( done, discard c and b)

( DIFF: Staapl has FOR AFT DUP R@ + C@ BL XOR IF R> 1 + EXIT THEN THEN NEXT 0; which only strips BL )
: -TRAILING ( b u -- b u ; Adjust the count to eliminate trailing white space.)
  FOR                 ( scan u+1 characters)
    AFT               ( skip the first loop)
      BL              ( blank for comparison)
      OVER R@ + C@ <  ( compare char at the end)
      IF R> 1+       ( non-white space, exit loop)
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
  1+ SWAP CMOVE      ( ; store characters in cells - 0 padded to end of cell)
  R> ;        ( leave only word buffer address )

?test\\ NP @ CELL+ CELL+ COUNT NIP 5 1 TEST
?test\\ NP @ CELL+ CELL+ COUNT OVER PAD ROT CMOVE C@ PAD C@ 1 TEST ( Check first character copied - expect pad="PACK$"
?test\\ PAD 3 + 5 BL FILL PAD 7 + C@ BL 1 TEST
?test\\ PAD 8 -TRAILING PAD 3 2 TEST

( === TEXT INTERPRETER ===  Zen pg63 )

( === Numeric Output Zen pg64 DIGIT EXTRACT )
: DIGIT ( u -- c ; Convert digit u to a character.)
  9 OVER <    ( if u is greater than 9)
  7 AND +     ( add 7 to make it A-F)
  48 + ;      ( add ASCII 0 for offset)
  
\\ : EXTRACT ( d base -- n/base c ; Extract the least significant digit from n.)
\\   UM/MOD   ( divide n by base)
\\  SWAP DIGIT ;    ( convert remainder to a digit)
: extract ( d base -- d c ; Extract least significant digit from d)
  >R
  0 R@ FM/MOD  ( S: l rh qh R: b )
  R> SWAP >R   ( S: l rh b R: qh )
  FM/MOD       ( S: r ql R: qh )
  R> ROT       ( S: ql qh r ) 
  DIGIT
  ;

\\ ?test\\ 123 10 EXTRACT 12 51 2 TEST
?test\\ 123 0 10 extract 12 0 51 3 TEST

( === Number formatting Zen pg65 <# HOLD #S SIGN #> )

: <# ( -- ;  Initiate the numeric output process.)
  PAD HLD ! ; ( use PAD as the number buffer)

: HOLD ( c -- ; Insert a character into the numeric output string.)
     HLD @          ( get the digit pointer in HLD)
     1- DUP HLD !  ( decrement HLD)
     C! ;           ( store c where HLD pointed to)

: # ( u -- u; Extract one digit from u and append the digit to output string.- ANS/eForth conflict eForth used single, ANS double )
  \\ eFORTH: BASE @ EXTRACT HOLD
     BASE @         ( get current base)
     extract        ( extract one digit from u)
     HOLD ;         ( save digit to number buffer)

: #S ( u -- 0 0 ; Convert u until all digits are added to the output string. - ANS/eForth conflict eForth used single, ANS double )
  \\ eFORTH BEGIN # DUP WHILE REPEAT
  BEGIN     ( begin converting all digits)
    #   ( convert one digit)
  2DUP OR WHILE     ( repeat until u is divided to 0)
  REPEAT ;

: SIGN ( n-- ; Add a minus sign to the numeric output string.)
  0< ( if n is negative)
  IF 45 HOLD THEN ; ( add a - sign to number string)

: #> ( d -- b u ; Prepare the output string to be TYPEed. - ANS/eForth conflict eForth used single, ANS double )
  2DROP          ( discard w)
  HLD @         ( address of last digit)
  PAD OVER - ;  ( return address of 1st digit and length)

?test\\ 123 0 <# OVER SIGN #S #> SWAP COUNT SWAP COUNT SWAP COUNT NIP 3 49 50 51 4 TEST ( hold="123" )
?test\\ -123 DUP ABS 0 <# #S ROT SIGN #> SWAP COUNT SWAP COUNT SWAP COUNT SWAP COUNT NIP 4 45 49 50 51 5 TEST ( hold="-123" )

( === More definitions moved up )

: EMIT ( c--;  Send a character to the output device. Zen pg69)
  'EMIT @EXECUTE ;
: SPACE ( -- ; Send the blank character to the output device. Zen pg70)
  BL EMIT ; ( send out blank character)
: emits ( +n c -- ; Send n characters to output device)
  SWAP 0 MAX FOR AFT DUP EMIT THEN NEXT DROP ; ( From Staapl and V5, not in Zen) ( TODO-ANS flagged as possible conflict)
: SPACES ( n -- ; Send n spaces to the output device. Zen pg70) ( ERRATA Zen has bad initial SWAP)
  BL emits ;
\\ use JS definition (hand coded on Arduino etc)
\\ : TYPE ( b u -- ; Output u characters from b)
\\  FOR AFT DUP C@ EMIT 1+ THEN NEXT DROP ;
: .$ ( a -- ) COUNT TYPE ; ( from Staapl, not in eForth)

?test\\ 60 EMIT SPACE 2 SPACES 61 EMIT 0 TEST
( .$ is tested by ."| and others )

( === Number output Zen pg66 str HEX DECIMAL .R U.R U. . ? )

: str ( n -- b u ; Convert a signed integer to a numeric string)
  DUP >R  ( save a copy for sign)
  ABS     ( use absolute of n)
  0 <# #S   ( convert all digits)
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
  0 <# #S #> R>   ( convert unsigned number)
  OVER - SPACES ( print leading spaces)
  TYPE ;        ( print number in +n columns)

: U. ( u -- ; Display an unsigned integer in free format.)
  0 <# #S #>  ( convert unsigned number)
  SPACE     ( print one leading space)
  TYPE ;    ( print number)

: . ( w--; Display an integer in free format, preceded by a space.)
  BASE @ 10 XOR     ( if not in decimal mode)
  IF U. EXIT THEN   ( print unsigned number)
  str SPACE TYPE ;  ( print signed number if decimal)

: ? ( a -- ; Display the contents in a memory cell.)
  @ . ; ( very simple but useful command)

?test\\ -123 5 .R 123 5 U.R 123 U. 123 . BASE ? 0 TEST

( === Numeric input Zen pg67-68 DIGIT? NUMBER? )
( ERRATA Zen NIP is used but not defined )

: DIGIT? ( c base -- u t ; Convert a character to its numeric value. A flag indicates success.)
  >R                    ( save radix )
  48 -          ( character offset from digit 0 - would be better as '[ CHAR 0 ] LITERAL' but dont have '[')
  42 OVER < 
  IF 
    32 -                ( convert lower case to upper case )
  THEN
  9 OVER <              ( is offset greater than 9? )
  IF 7 -                ( yes. offset it from digit A )
    DUP                 ( n n )
    10 <                ( if n<10, the flag will be -1, and )
    OR                  ( OR with n, result will be -1 )
  THEN                  ( if n>10, the flag will be 0 and )
  DUP                   ( OR result will still be n )
  R> U< ;               ( if n=/>radix, the digit is not valid )

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
    200       ( wait 0.5S if no keys w )
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
( TODO-TEST test ?KEY KEY NUF? )

: PACE ( --) ( Send a pace character for the file downloading process.)
  11 EMIT ; ( 11 is the pace character)
( SPACE and SPACES and TYPE and CHARS, now emits moved earlier)
( ERRATA Zen has 15 instead of 13 and 11 instead of 10)
: CR ( --) ( Output carriage return line feed)
  13 EMIT 10 EMIT ;
( CR tested after .( )

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
: S"| ( -- caddr u; ANS version )
  do$ COUNT ;


( ."| tested by ."; $"| tested by $" )

( === Word Parser Zen pg72-73 PARSE parse )
( ERRATA Zen this doesnt set >IN past the string, but the callers clearly assume it does.)
( ERRATA Zen pg72 is obviously broken as it doesn't even increment the pointer in the FOR loop)
( This version is based on v5, Staapl is significantly different )

: parse ( b u c -- b u delta ; <string> ) ( TODO evaluate control structures here)
  ( Scan string delimited by c. Return found string and its offset. )
  ( EFORTH-ZEN-ERRATA - delta appears to be to end of string, not start )
  temp !            ( save delimiter in temp )
  OVER >R DUP       ( b u u)
  IF                ( if string length u=0, nothing to parse )
    1-             ( u>0, decrement it for FOR-NEXT loop )
    temp @ BL =     ( is delimiter a space? )
    IF              ( b u' --, skip over leading spaces )
      FOR BL        ( EFORTH-ZEN-ERRATA says BLANK )
        OVER C@       ( get the next character )
        - 0<          ( is it a space? )
        INVERT
      WHILE
        1+           ( EFORTH-ZEN-ERRATA - correct in eForthOverviewv5.pdf )
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
      1+
    NEXT                ( not delimiter, keep on scanning )
      DUP >R            ( save a copy of b at the end of the loop)
    ELSE                ( early exit, discard the loop count )
      R> DROP           ( discard count )
      DUP 1+ >R        ( save a copy of b'+1)
    THEN
    OVER -              ( length of the parsed string )
    R> R> -             ( and its offset in the buffer )
    EXIT
  THEN ( b u)
  OVER                  ( buffer length is 0 )
  R> - ;                ( the offset is 0 also )

: SOURCE TIB #TIB @ ; ( Repurposing TIB and #TIB for the pointer to buffer and length whatever input source )

:NONAME ( c -- b u ; <string> ) ( Scan input stream and return counted string delimited by c.)
  >R              ( save the delimiting character )
  SOURCE          ( a u )
  SWAP >IN @ +    ( u a' ; address in TIB to start parsing )
  SWAP >IN @ -    ( a' u' ; length of remaining string in TIB )
  R> parse        ( a" u" delta ; parse the desired string )
  >IN +! ;        ( a" u" ; move parser pointer to end of string )
' PARSE DEFER! \\ IS PARSE

( === Parsing Words Zen pg74 .( ( \\ CHAR TOKEN WORD )

: CHAR BL PARSE DROP C@ ; ( Parse a word and return its first character )
: CTRL CHAR 31 AND ; ( Parse a word, return first character as a control )
?test\\ CHAR ) 41 1 TEST
?test\\ CTRL H 8 1 TEST

: .(  ( -- ) ( Output following string up to next )
  [ CHAR ) ] LITERAL PARSE
   ( parse the string until next )
  TYPE ; IMMEDIATE         ( type the string to terminal )
?test\\ .( on consecutive ) CR .( lines )

:NONAME ( -- a ; <string> ; Parse a word from input stream and copy it to name dictionary. : TOKEN )
  BL PARSE            ( parse out next space delimited string )
  BYTEMASK MIN              ( truncate it to 31 characters = nameMaxLength )
  NP @                ( word buffer below name dictionary )
  OVER - CELLL - PACK$ ;  ( copy parsed string to word buffer )
' TOKEN DEFER!

: WORD ( c -- a ; <string> ) ( Parse a word from input stream and copy it to code dictionary. Not if not in definition it will be overwritten by next)
  PARSE         ( parse out a string delimited by c )
  HERE PACK$ ;  ( copy the string into the word buffer )

?test\\ 1 2 ( 3 ) 4 \\ commenting
?test\\ 1 2 4 3 TEST
?test\\ : foo TOKEN C@ ; foo xxx 3 1 TEST
?test\\ BL WORD yyyy DUP C@ SWAP CP @ - 4 0 2 TEST
?test\\ : foo .( output at compile time) ; 0 TEST

( === Dictionary Search Zen pg75-77 NAME> SAME? find NAME? )

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
  FALSE ;               ( then push the 0 flag on the stack ) ( a1 a2 0)

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
      [ CELLMASK ] LITERAL AND ( mask off lexicon bits - note CELLMASK is endian dependent )
      R@ XOR          ( compare with 1st cell in string )
      IF              ( 1st cells do not match )
        CELL+ TRUE      ( try the next name in the vocabulary )
      ELSE CELL+      ( get address of the 2nd cell )
        temp @        ( get the length of string )
        SAME?         ( string=name? )
      THEN
    ELSE              ( end of vocabulary )
      R> DROP         ( discard the 1st cell )
      SWAP CELL- SWAP ( restore the string address ERRATA v2 & Staapl misses this - Zen has it)
      EXIT            ( exit with ca na, na=0 is false flag )
    THEN
  WHILE               ( if the name does not match the string )
    CELL- CELL-       ( a' la --, move to next word in vocab)
  REPEAT              ( repeat until vocabulary is exhausted )
  R> DROP NIP         ( a match is found, discard 1st and va )
  CELL-               ( restore name field address )
  DUP NAME>           ( find code field address )
  SWAP ;              ( reorder and return.  -- ca na )

: FIND-NAME ( caddr u -- na | F; see https://forth-standard.org/proposals/find-name#contribution-58)
  ( Note this ONLY currently works if caddr-- is a counted string )
  ( Search all context vocabularies for a string.)
  CONTEXT       ( address of context vocabulary stack )
  DUP 2@ XOR    ( are two top vocabularies the same? )
  IF            ( if not same )
    CELL-   ( backup the vocab address for looping )
  THEN
  >R            ( save the prior vocabulary address )
  BEGIN         ( caddr u R: va )
    R> CELL+ >R ( caddr u R: va'; get the next vocabulary address and save)
    R@ @        ( is this a valid vocabulary? )
  WHILE         ( caddr u R: va' ; yes)
    2DUP R@ @    ( caddr u caddr u va' R: va' )
    FIND-NAME-IN ( caddr u na R: va' | caddr u F R: va')
    ?DUP        ( word found here? )
  UNTIL         ( if not, go searching next vocabulary )
                ( caddr u na R: va)
    R> DROP NIP NIP EXIT ( word is found, exit with na )
  THEN          ( caddr u R: va' ; goes here from the WHILE )
  R> DROP 2DROP ( ; word is not found in all vocabularies )
  FALSE ;       ( F ; exit with a false flag )


: NAME? ( a -- ca na, a F )
  ( Search all context vocabularies for a string.)
  DUP COUNT         ( a caddr u ) 
  FIND-NAME     ( a na | a F) 
  ?DUP
  IF            ( a na; word found)
    NIP DUP NAME> SWAP ( ca na )
  ELSE          ( a ) 
    FALSE       ( a F )
  THEN ; 

( NAME> implicitly tested by find )
?test\\ BL WORD xxx DUP C@ 1+ PAD SWAP CMOVE PAD BL WORD xxx 4 SAME? >R 2DROP R> 0 1 TEST
?test\\ BL WORD xxx DUP C@ 1+ PAD SWAP CMOVE PAD BL WORD xzx 4 SAME? >R 2DROP R> 0= 0 1 TEST
?test\\ FORTH 0 TEST

?test\\ BL WORD TOKEN CONTEXT @ find BL WORD TOKEN CONTEXT @ FORTHfind 2 TEST
?test\\ BL WORD TOKEN CONTEXT @ find NIP BL WORD TOKEN COUNT CONTEXT @ FIND-NAME-IN 1 TEST
?test\\ BL WORD TOKEN CONTEXT @ find NIP BL WORD TOKEN COUNT FIND-NAME 1 TEST ( FIND-NAME searches all vocabs)
?test\\ BL WORD TOKEN CONTEXT @ find BL WORD TOKEN NAME? 2 TEST ( Name searches all vocabs )

: FIND ( caddr -- c-addr 0 | xt 1 | xt -1 ; https://forth-standard.org/standard/core/FIND )
    DUP COUNT ( caddr caddr' u )
    FIND-NAME ( caddr na | caddr F )
    ?DUP IF
      NIP DUP NAME> ( na xt )
      SWAP immediate? ( xt b )
      IF 1 ELSE -1 THEN
    ELSE ( caddr )
      0
    THEN ;

?test\\ BL WORD TOKEN CONTEXT @ find DROP ( xt ) -1 BL WORD TOKEN FIND ( xt -1 ) 2 TEST ( not immediate )
?test\\ BL WORD XYZZY 0 OVER FIND 2 TEST ( failure case)
?test\\ BL WORD THEN CONTEXT @ find DROP ( xt ) 1 BL WORD THEN FIND 2 TEST ( immediate)

( === Error Handling Zen pg80-82 CATCH THROW = moved in front of Text input )

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

( EFORTH DIFFERENCE - eForth always THROWs, but ANS doesnt throw if non-zero, since eForth use cases always have a err# )
( the ANS definition servers both and is used)
: THROW ( err# -- err# )
  ( Reset system to current local error frame and update error flag.)
  ?DUP IF 
    HANDLER @ RP! ( expose latest error handler frame on return stack )
    R> HANDLER !  ( restore previously saved error handler frame )
    R> SWAP >R    ( retrieve the data stack pointer saved )
    SP!           ( restore the data stack )
    DROP
    R> 
  THEN ;          ( retrieved err# )


( === Text input from terminal Zen pg 78: ^H TAP kTAP )
( EFORTH-ZEN-ERRATA CTRL used here but not defined. )

: ^H ( bot eot cur -- bot eot cur)
  ( Backup the cursor by one character.)
  >R OVER     ( bot eot bot --)
  R@ < DUP    ( bot<cur ? )
  IF
    ( This should probably be vectored , on JS it needs BS BL BS to erase a char and position cursor )
    [ CTRL H ] LITERAL 'ECHO @EXECUTE
    BL 'ECHO @EXECUTE
    [ CTRL H ] LITERAL 'ECHO @EXECUTE
  THEN        ( bot eot cur F|T -- )
  R> + ;      ( decrement cur, but not passing bot )

: TAP ( bottom eot current key -- bottom eot current )
  ( Accept and echo the key stroke and bump the cursor.)
  DUP         ( duplicate character )
  'ECHO @EXECUTE ( echo it to display )
  OVER C!     ( store at current location )
  1+ ;       ( increment current pointer )

( Diff - Staapl doesnt check for 10 - crlf? split out as used by READ-LINE )
: crlf? ( c -- f; is key a return or line feed?)
  DUP 10 = SWAP 13 = OR ;
: skipCRLF ( caddr u -- caddr' u' )
  BEGIN
    DUP IF OVER C@ crlf? ELSE FALSE THEN ( caddr u bool)
  WHILE ( caddr u )
    1- SWAP 1+ SWAP ( caddr' u')
  REPEAT
;
: skipToCRLF ( caddr u -- caddr' u' ; caddr should point at first crlf and u' is size removed from end ) 
  BEGIN
    DUP IF OVER C@ crlf? 0= ELSE FALSE THEN ( caddr u bool)
  WHILE ( caddr u )
    1- SWAP 1+ SWAP ( caddr' u')
  REPEAT
;

( ERRATA - Zen & V5 just check 13 and Ctrl-H, backspace can also be DEL and end of line can be 10 )
: kTAP ( bot eot cur key -- bot eot cur )
  ( Process a key stroke, CR or backspace.)
  DUP crlf? 0= 
  IF ( bot eot cur key )
    DUP [ CTRL H ] LITERAL = SWAP 127 = OR 0= ( bot eot cur f ; is key a backspace or DEL ? )
    IF BL TAP   ( bot eot cur' ; none of above, replace by space )
    ELSE ^H         ( bot eot cur' ; backup current pointer )
    THEN
    EXIT            ( done this part )
  THEN              ( key is a return)
  DROP              ( discard bot and eot )
  NIP DUP ;         ( bot cur cur;  duplicate cur to force ACCEPT to exit, Key not stored )

( === Error Handling Zen pg80-82 NULL$ ABORT abort" ?STACK )

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
( ERRATA v5 has obvious errata missing the + after COUNT; Zen ok; Staapl different )
: $," ( --) ( Moved earlier from Zen pg90)
  ( Compile a literal string up to next " .)
  34 WORD ( move string to code dictionary)
  COUNT + ALIGNED ( calculate aligned end of string)
  CP ! ; ( adjust the code pointer)

( Moved earlier from Zen pg93 )
: ABORT" ( C: -- ; I: f --; <string> )
  ( Conditional abort with an error message.)
  COMPILE abort"  ( compile runtime abort code )
  $," ; IMMEDIATE ( compile abort message )

( Moved earlier from Zen pg93 )
: ." ( -- ; <string> )
  ( Compile an inline string literal to be typed out at run time.)
  COMPILE ."| ( compile print string code )
  $," ; IMMEDIATE ( compile print string )

( Test is tricky - the "3" in bar is thrown away during hte "THROW" while 5 is argument to THROW )
?test\\ : bar 3 5 THROW 4 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo 1 5 2 3 TEST
?test\\ : bar 3 ; : foo 1 [ ' bar ] LITERAL CATCH 2 ; foo 1 3 0 2 4 TEST
?test\\ : foo ." hello" ; foo 0 TEST
( Note that abort restores the stack, so shouldn't have consumed something else will have random noise on stack )
?test\\ : bar ?DUP ABORT" test" 3 ; : foo [ ' bar ] LITERAL CATCH ; 1 foo C@ 0 foo 1 4 3 0 4 TEST
( $," and abort" are implicitly tested by ABORT")

( === Text Interpreter loop Zen pg83-84 $INTERPRET [ .OK ?STACK EVAL )

: POSTPONE ( "<spaces><name>" -- ; replaces COMPILE and [COMPILE] )
\\ https://forth-standard.org/standard/core/POSTPONE - seriously unclear standard definition
\\ SEE https://github.com/NieDzejkob/2klinux/blob/2665d2491d82f0f8ced8d89163199a42bcd8c5f0/image-files/stage1.frt#L302
  TOKEN ( a )
  COUNT FIND-NAME ( na | F)
  ?DUP 0= ABORT" Not found"
  DUP immediate? 0= IF 
    COMPILE COMPILE
  THEN ( na ) 
  NAME> ,
; IMMEDIATE

: [CHAR] ( "name" <spaces> -- ) CHAR POSTPONE LITERAL ; IMMEDIATE

:NONAME ( a -- ; : $INTERPRET )
  ( Note js $INTERPRET has same signature as this except for THROW
  ( Interpret a word. If failed, try to convert it to an integer.)
  NAME?                   ( search dictionary for word just parsed )
    ?DUP                    ( is it a defined word? )
  IF C@                    ( yes. examine the lexicon ) ( ERRATA Zen, V5 and Staapl use @, it should be C@)
  [ COMP ] LITERAL AND ( is it a compile-only word? )
  ABORT" compile ONLY"  ( if so, abort with the proper message )
  EXECUTE EXIT          ( not compile-only, execute it and exit )
  THEN                    ( not defined in the dictionary )
  NUMBER?                 ( convert it to a number ) ( TODO-NUMBER-5 merge with number in js)
  IF EXIT THEN            ( exit if conversion is successful )
  THROW ;                 ( else generated the error condition )
' $INTERPRET DEFER!

: .OK ( -- )
  ( Display 'ok' only while interpreting.)
  STATE @ 0= IF ."  ok" THEN CR ;

: ?STACK ( -- )
  ( Abort if the data stack underflows.)
  DEPTH 0< ABORT" underflow" ; ( Note Staapl uses $" THROW, v5 uses ABORT)

?test\\ BL PARSE 123 PAD PACK$ $INTERPRET 123 1 TEST
?test\\ 123 BL PARSE DUP PAD PACK$ $INTERPRET  123 123 2 TEST
?test\\ : foo 1 2DROP ?STACK ; : bar [ ' foo ] LITERAL CATCH ; bar C@ 9 1 TEST

( This switches to use new interpreter, its still using old js $COMPILE )

:NONAME ( -- ; Start the text interpreter : [ )
  FALSE STATE !                 ( ANS version)
  ; IMMEDIATE               ( must be done even while compiling )
' [ DEFER!

?test\\ [ 1 2 3 ROT 2 3 1 3 TEST

( === Operating System Zen pg85-86 PRESET XIO FILE HAND I/O CONSOLE )

( EFORTH-V5-ERRATA uses TIB #TIB CELL+ ! which since ' TIB #TIB CELL+ @' is a NOOP )
( EFORTH-ZEN-ERRATA uses =TIB but doesnt define =TIB which is TIB0)

: XIO ( prompt echo tap -- )
  ( Reset the I/O vectors, 'TAP, 'ECHO and 'PROMPT.)
  'TAP !                          ( init kTAP )
  'ECHO !                         ( init ECHO )
  'PROMPT ! ;                     ( init system prompt )

: FILE ( -- )
  ( Select I/O vectors for file download.)
  \\ [ ' PACE ] LITERAL  ( send 11 for acknowledge - eForth difference - this is only meaningful if feeding through serial )
  0 ( No prompt while on File )
  [ ' DROP ] LITERAL  ( do not echo characters )
  [ ' kTAP ] LITERAL  ( ignore control characters )
  XIO ;


: HAND ( -- )
  ( Select I/O vectors for terminal interface.)
  [ ' .OK  ] LITERAL  ( say 'ok' if all is well)
  ( ERRATA zen, Staapl uses 'EMIT @, current version of emit, V5's use of EMIT is better because respects changes to 'EMIT)
  ( Web extends to Drop as echoing is handled at UI level)
  [ ' EMIT ] LITERAL  ( echo characters ) 
  [ ' kTAP ] LITERAL  ( ignore control characters )
  XIO ;

( EFORTH-ZEN-ERRATA has 'RX?' should be '?RX'
( EPROM note, this is in Rom, not Ram as otherwise need to be initialized - and from what ?
CREATE I/O  ' ?RX , ' TX! , ( Array to store default I/O vectors. )

: CONSOLE ( -- )
  ( Initiate terminal interface.)
  I/O 2@ '?KEY 2!   ( get defaults from I/O ) ( EFORTH-STAAPL EFORTH-ZEN errata has 'KEY?. V5 fixes )
  HAND ;            ( keyboard input )


( TODO-IO test PRESET HAND CONSOLE QUIT )

( === eForth Compiler Zen pg 87 ====== )

( === Interpreter and Compiler Zen pg 88-90: [ ] ' ALLOT , [COMPILE] COMPILE LITERAL $," RECURSE )

( "," COMPILE LITERAL $," are moved earlier, redefinition of ] is moved later as needs $COMPILE )
:NONAME ( -- ca ) TOKEN NAME? IF EXIT THEN THROW ; ' ' DEFER!
: ['] ' POSTPONE LITERAL ; IMMEDIATE
: ALLOT ( n -- ) CP +! ; ( ERRATA Zen has +1 instead of +! fixed in V5 and Staapl)
: vALLOT ( n -- ) VP @ IF VP +! ELSE ALLOT THEN ; ( EPROM ALLOT - not part of eForth)

: '>BODY! STATE @ \\ https://forth-standard.org/standard/core/IS (nasty state dependent word)
  IF [COMPILE] ['] COMPILE >BODY!
  ELSE ' >BODY!
  THEN ; 
: IS '>BODY! ; IMMEDIATE

: ACTION-OF STATE @ \\ https://forth-standard.org/standard/core/ACTION-OF (nasty state dependent word)
  IF [COMPILE] ['] COMPILE DEFER@
  ELSE ' DEFER@
  THEN ; IMMEDIATE
( ERRATA Staapl & Zen do 'CURRENT @ !', v5 does 'NAME> ,' this is fundamentally different usage, ANS matches latter )
: RECURSE ( -- ) LAST @ NAME> , ; IMMEDIATE

?test\\ 1 ' DUP EXECUTE 1 1 2 TEST
?test\\ HERE 2 ALLOT HERE SWAP - 2 1 TEST
?test\\ : foo [COMPILE] ( ; foo 2 ) 0 TEST
?test\\ : foo ?DUP IF DUP 1- RECURSE THEN ; 3 foo 3 2 1 3 TEST

( === Control Structures Zen pg91-92: FOR BEGIN NEXT UNTIL AGAIN IF AHEAD REPEAT THEN AFT ELSE WHILE )
( All moved earlier )


( === String Literals Zen pg93: ABORT" $" ." ( ABORT" ." moved to Zen pg84 where used )

: $" ( compile time: <string> --; interpret time: -- addr ; Compile an inline string literal that puts counted string on stack.)
  COMPILE $"|     ( compile string runtime code)
  $," ; IMMEDIATE ( compile string itself )
: C" [COMPILE] $" ; IMMEDIATE ( Forth2012 version of $")
: S" ( compile time: <string> ; interpret time: -- caddr u ; ANS version puts address and length ) 
  STATE @ 
  IF COMPILE S"| $,"
  ELSE 34 PARSE stringBuffer PACK$ COUNT
  THEN
  ; IMMEDIATE

?test\\ : foo $" hello" COUNT NIP ; foo 5 1 TEST
?test\\ S" foo" TUCK + 1- C@ 3 CHAR o 2 TEST

( === Name Dictionary Compiler Zen pg94-96: ?UNIQUE $,n $COMPILE OVERT ; ] call, : IMMEDIATE  (see this.dollarCommaN)

: ?UNIQUE ( a -- a ) ( Redefining code word qUNIQUE in Forth)
  ( Display a warning message if the word already exists.)
  DUP NAME?       ( name exists already?)
  IF ."  reDef "  ( if so, print warning )
  OVER .$       ( with the offending name )
  THEN DROP ;     ( discard token address )

?test\\ TOKEN foo DUP ?UNIQUE - 0 1 TEST

:NONAME ( na -- ; : $,n )
  ( Build a new dictionary name using the string at na.)
  DUP C@            ( null input?)
  IF ?UNIQUE        ( duplicate name? )
    ($,n)
    EXIT            ( exit )
  THEN              ( here if null input )
  $" name" THROW ;  ( this is an error return )
' $,n DEFER!

:NONAME  ( a -- : $COMPILE) ( Redefining code word js $COMPILE in Forth)
  ( Compile next word to code dictionary as a token or literal.)
  NAME?         ( parse the next word out )
  ?DUP          ( successful? )
  IF C@         ( yes, get the lexicon )
    IMED AND   ( is it an immediate word? ) ( ERRATA V5 has @ - Staapl,Zen correct)
    IF EXECUTE  ( yes.  execute it )
    ELSE ,      ( no.  compile it )
    THEN
    EXIT        ( done. exit )
  THEN          ( not a valid word )
  NUMBER?       ( convert it to a number )
  IF  [COMPILE] LITERAL ( successful. compile a literal number )
    EXIT        ( done )
  THEN          ( not a number either )
  THROW ;       ( generate an error condition )
' $COMPILE DEFER!

: EVAL ( -- )
  ( Interpret the input stream.)
  BEGIN
  TOKEN ( -- a)   ( parse a word and leave its address )
  DUP C@          ( is the character count 0? )
  WHILE             ( no )
    ( Diff: eForth vectors through 'EVAL, ANS uses  STATE )
    STATE @ IF $COMPILE ELSE $INTERPRET THEN
    ?STACK          ( any stack error? overflow or underflow )
  REPEAT            ( repeat until TOKEN gets a null string )
  DROP              ( discard the string address )
  'PROMPT @EXECUTE ;  ( display the proper prompt, if any )

( === TODO-TEST TODO-IO test EVAL, not that .OK wont work here since not yet using $INTERPRET )

:NONAME  ( -- : OVERT)
  ( Link a successfully defined word into the current vocabulary. )
  LAST @        ( name field address of last word )
  DUP @ IF        ( Dont store if LAST is 0 as in :NONAME)
    CURRENT @  ! ( link it to current vocabulary )
  ELSE
    DROP NP @ 3 CELLS + NP !
  THEN ;
' OVERT DEFER!

:NONAME ( -- : ; )
  ( Terminate a colon definition. )
  COMPILE EXIT  ( compile exit code )
  [COMPILE] [   ( return to interpreter state )
  OVERT ;       ( restore current vocabulary )
' ; DEFER! COMPILE-ONLY IMMEDIATE

:NONAME ( -- ; Start compiling the words in the input stream : ] )
  TRUE STATE ! ;
' ] DEFER!

:NONAME ( -- ; <string> ) ( redefining javascript word ':' = colon )
  ( Start a new colon definition using next word as its name.)
  TOKEN $,n   ( compile new word with next name )
  tokenDoList ,
  ] ;         ( Set state to compiling )
' : DEFER!

?test\\ : foo 1 ; foo 1 1 TEST


( TODO may need JS equivalent - see if used;  : CALL, ( ca -- ; ( DTC 8086 relative call ; [ =CALL ] LITERAL , HERE CELL+ - , ; )

( === Defining Words Zen pg97: USER CREATE VARIABLE )

( EFORTH-DIFF each of V5, Zen and Staapl do this differently - this is different again because of token threaded architecture)

\\ Deprecated \\ : USER ( u -- ; <string> ) TOKEN $,n OVERT tokenUser , ;
: VALUE TOKEN $,n OVERT HERE tokenValue , _USER @ , _USER ++ >BODY! ; \\ TODO needs to initialize variable
: TO '>BODY! ; IMMEDIATE

?test\\ : foo CREATE 123 , DOES> @ ; foo BAR BAR 123 1 TEST

: VARIABLE ( -- ; <string> ) vCREATE 0 v, ;

: CONSTANT ( u -- ; <string> ) TOKEN $,n OVERT tokenNextVal , , ;

?test\\ VARIABLE foo 0 TEST
?test\\ 12 foo ! 0 TEST
\\ TEST-15-EPROM test failing: foo @ 12 1 TEST

\\ Advanced Loops   DO | ?DO ... LEAVE ... LOOP | +LOOP; I,J,I-MAX,J-MAX,UNLOOP
\\ lifted from https://github.com/NieDzejkob/2klinux/blob/2665d2491d82f0f8ced8d89163199a42bcd8c5f0/image-files/stage1.frt#L538-L649


\\ We can now define DO, ?DO, LOOP, +LOOP and LEAVE. It would be much easier if LEAVE didn't exist,
\\  but oh well. Because storing LEAVE's data on the stack would interfere with other control flow
\\  inside the loop, let's store it in a variable. )

VARIABLE leave-ptr

\\ ( Let's consider the base case: only one LEAVE in the loop. This can be trivially handled by
\\  storing the address we need to patch in the variable.

\\  This would also work quite well with nested loops. All we need to do is store the old value of
\\  the variable on the stack when opening a loop.

\\  Finally, we can extend this to an arbitrary number of LEAVEs by threading a singly-linked list
\\  through the branch target address holes. )

\\ ( The loop control variables are stored on the return stack, with the counter on top and the limit
\\   on the bottom.

\\   DO -> 2>R loop-inside

\\   ?DO -> (?do) ?branch [do the LEAVE thing but with a conditional jump] loop-inside
\\ )

: (?do)    ( limit counter R: retaddr -- R: limit counter retaddr )
  R>       ( limit counter retaddr )
  -ROT     ( retaddr limit counter )
  2DUP 2>R ( retaddr limit counter R: limit counter )
  <>       ( retaddr should-loop-at-all? )
  SWAP >R  ( should-loop-at-all? R: limit counter retaddr )
;

\\ ( This means that LOOP should look for LEAVE one cells before the actual loop body. That will make
\\   it handle ?DO correctly, and because the execution token of 2>R is not the same as the execution
\\   token of leave, this will not break DO.

\\    LOOP ->  (loop) ?branch loop-beginning 2RDROP
\\   +LOOP -> (+loop) ?branch loop-beginning 2RDROP
\\                                           ^ LEAVE jumps here
\\ )

: (loop)   ( R: limit old-counter retaddr )
  R> 2R>   ( retaddr limit old-counter )
  1+       ( retaddr limit new-counter )
  2DUP 2>R ( retaddr limit new-counter R: limit new-counter )
  =        ( retaddr should-stop-looping? R: limit new-counter )
  SWAP >R  ( should-stop-looping? R: limit new-counter retaddr )
;

: (+loop)         ( diff R: limit old-counter retaddr )
  R>              ( diff retaddr )
  SWAP            ( retaddr diff )
  2R>             ( retaddr diff limit old-counter )
  2 PICK OVER +   ( retaddr diff limit old-counter new-counter )
  ROT DUP >R      ( retaddr diff old-counter new-counter limit R: limit )
  -ROT DUP >R     ( retaddr diff limit old-counter new-counter R: limit new-counter )
  3 PICK          ( retaddr diff limit old-counter new-counter diff )
  0< IF SWAP THEN ( retaddr diff limit min-limit max-limit )
  1+ SWAP 1+ SWAP ( retaddr diff limit min-limit+1 max-limit+1 )
  WITHIN          ( retaddr diff should-stop-looping? )
  NIP SWAP >R     ( should-stop-looping? R: limit new-counter retaddr )
;

: leave,
  HERE
  leave-ptr @ ,
  leave-ptr !
;

: LEAVE COMPILE branch leave, ; IMMEDIATE

: UNLOOP ( https://forth-standard.org/standard/core/UNLOOP )
  COMPILE 2RDROP
; IMMEDIATE

: DO
  leave-ptr @
  0 leave-ptr !
  COMPILE 2>R
  HERE
; IMMEDIATE

: ?DO ( https://forth-standard.org/standard/core/qDO )
  leave-ptr @
  0 leave-ptr !
  COMPILE (?do)
  COMPILE ?branch leave, 
  HERE
; IMMEDIATE

: some-loop
  COMPILE ?branch ,
  leave-ptr @
  BEGIN
    ?DUP
  WHILE
    DUP @ >R
    HERE SWAP !
    R>
  REPEAT
  POSTPONE UNLOOP
  leave-ptr !
;

: LOOP
  COMPILE (loop)
  some-loop
; IMMEDIATE

: +LOOP
  COMPILE (+loop)
  some-loop
; IMMEDIATE

: I-MAX ( -- n ) RP@ 2 CELLS + @ ;
: J     ( -- n ) RP@ 3 CELLS + @ ;
: J-MAX ( -- n ) RP@ 4 CELLS + @ ;
\\ ---------

( === ANS number input === )
\\ TODO-83 convert eFORTH's NUMBER? to use 2012's >NUMBER, but note order of definitions tricky
\\ note that >NUMBER requires ?DO and UNLOOP
\\ note that eFORTH's NUMBER? is broader - handles sign and '$' for hex.
: accumulate ( +d0 addr digit - +d1 addr )
  SWAP >R SWAP BASE @ UM* DROP ROT BASE @ UM* D+ R> ;
: >NUMBER ( ud1 c-addr1 u1 -- ud2 c-addr2 u2 ) 
  \\ https://forth-standard.org/standard/core/toNUMBER
  \\ adapted from gForth kernel/basics.fs
  \\ Note gForth has a different 'digit?' and has I' instead of I-MAX and uses non-standard control structure
  \\ 0 ?DO COUNT BASE @ DIGIT? WHILE accumulate LOOP 0 ELSE DROP 1- I-MAX I - UNLOOP THEN 
  0 SWAP 0 ?DO DROP COUNT BASE @ DIGIT? 0= IF DROP 1- I-MAX I - LEAVE THEN accumulate 0 LOOP ; 


: (charbase) ( c -- c n ; Check if character represents a base, if so return)
  DUP 35 = IF 10 EXIT THEN ( # )
  DUP 36 = IF 16 EXIT THEN ( $ )
  DUP 37 = IF 2 EXIT THEN ( % )
  0
  \\ DUP 39 = IF 0 EXIT THEN ( '  - handled specially 
;

( EFORTH-ZEN-ERRATA it doesnt return 'n T' it returns 'n a' on success
:NONAME ( a -- n T, a F ; Convert a number string to integer. Push a flag on tos. : NUMBER? )
  DUP BASE @ >R         ( save the current radix in BASE )
  COUNT OVER >R >R  ( a a' R: base0 a+1 n ; a' always points to next char to read )
  COUNT             ( a a' c )
  (charbase)        ( a a' c base|0 ) 
  ?DUP IF           ( Did we change base ?)
    BASE !
    DROP            ( a a' )
    COUNT           ( a a' c )
  THEN              ( a a' c )
  DUP 39 = IF       ( Compare to "'" )
    DROP
    COUNT           ( a a' c ; Get single character )
    SWAP COUNT 39 <> ( a c a' f ; Get ending quote and check )
    IF ( a c a' f R: base0 a+1 n )
      2DROP 2RDROP FALSE ( a a F R: base0 )
    ELSE
      DROP NIP TRUE     ( c T )
      2RDROP
    THEN            ( a a F | c T R: base0 )
    R> BASE !
    EXIT 
  THEN ( a' c )
  45 = TUCK         ( a sign a' sign R: base0 a+1 n ; check if matches '-')
  0= IF 1- THEN     ( a sign a' ; back up to point at first digit)
  0 0 ROT           ( a sign 0 0 a' )
  R> R> + OVER -    ( a sign 0 0 a' n+a+1-a' R: base0 )
  >NUMBER           ( a sign ud a' u ; convert and see if anything left )
  IF ( its not a number )
    2DROP 2DROP FALSE  ( a F R: base0 )
  ELSE DROP ROT         ( a ud sign )
    IF DNEGATE THEN DROP NIP TRUE ( n T )
  THEN
  R> BASE !         ( n T | a F )
;
' NUMBER? DEFER!

?test\\ 50 10 DIGIT? 2 -1 2 TEST
?test\\ BL PARSE 1234 PAD PACK$ NUMBER? DROP 1234 1 TEST
?test\\ 123 123 1 TEST



( === Text input from terminal Zen pg 78: ^H TAP kTAP ACCEPT EXPECT QUERY )

( Errata Zen doesnt match the signature) 
: ACCEPT ( b u -- b u )
  ( Accept characters to input buffer. Return with actual count.)
  OVER + OVER       ( b b+u b;  EFORTH-ZEN-ERRATA fixed in v5 and STAAPL)
  BEGIN
    2DUP XOR        ( b b+u b' b'=b+u = current pointer? )
  WHILE
    KEY             ( b b+u b c; get one more character )
    DUP BL - 95 U<  ( b b+u b c f; is it printable? )
    IF TAP          ( b b+u b+1 ; yes, accept and echo it )
    ELSE 'TAP @EXECUTE ( no, process control code )
    THEN            ( kludge! if was a crlf then will have b+u replaced by b' causing the WHILE to trigger )
  REPEAT            ( b b+u b'; repeat until buffer full )
  DROP              ( b b+u ; drop current pointer
  SWAP - ;          ( u; leave actual count)

( Generic stack 
: stack CREATE HERE 0 , OVER , vHERE SWAP ! 0 v, CELLS vALLOT ;
: spop @ DUP @ CELLS OVER + @ SWAP --  ;
: spush @ DUP @ 1+ 2DUP SWAP ! CELLS + ! ;
: sempty @ 0 SWAP ! ; 

8 4 * stack sourceStack ( sourceStack holds 8 * [ SOURCE-ID buff len >IN ] )

: 0> DUP 0= SWAP 0< OR 0= ;
DEFER unreadFile
: sourcePush sourceStack >R 
  SOURCE-ID @ 
[ rqFiles ] ?\\ DUP 0> IF DUP unreadFile THROW THEN ( Check if a file and if so unread any buffered )
  SOURCE >IN @ R@ spush R@ spush R@ spush R> spush ;
: source! ( source-id buff len in ) 
  >IN ! #TIB ! #TIB CELL+ ! DUP SOURCE-ID ! 
  IF FILE ELSE HAND THEN ; ( Set prompt - same for String or File )
: sourcePop sourceStack >R R@ spop R@ spop R@ spop R> spop ( source-id buff len in ) source! ; 

DEFER READ-LINE
: REFILL ( https://forth-standard.org/standard/core/REFILL )
  0 >IN ! ( initialized parsing pointer )
  SOURCE-ID @ ( source )
  ?DUP IF ( not a terminal )  
[ rqFiles ] ?\\ DUP -1 = IF 
      DROP FALSE ( String - Always false )
[ rqFiles ] ?\\ ELSE  
[ rqFiles ] ?\\   TIB 1024 ROT READ-LINE ( u2 flag ior )
[ rqFiles ] ?\\   THROW SWAP #TIB ! ( flag ; True if more )
[ rqFiles ] ?\\ THEN
  ELSE
    ( Accept input stream to terminal input buffer.)
    TIB 80 ( addr and size of terminal input buffer)
    ACCEPT ( u ; )
    #TIB !  ( store number of characters received )
    TRUE    ( return true, never unwind from terminal )
  THEN
;
: QUERY REFILL 0= IF sourcePop THEN ; ( Read from current source, on fail go back to previous reseting >IN )

( === Operating System Zen pg85-86 PRESET XIO FILE HAND I/O CONSOLE QUIT)

: que ( -- )
  QUERY ( get a line of commands from )
  EVAL ; ( Evaluate it)

: PRESET ( -- )
  ( Reset data stack pointer and the terminal input buffer. )
  SP0 @ SP!   ( initialize data stack )
  sourceStack sempty ( empty any nested files
  0 TIB0 0 0 source!  ( and read from terminal - resets PROMPT and vectored I/O )
  ;
: quitError ( f -- )
  ( Handle a possible error returned by EVAL - common to QUIT and quit1 )
      NULL$ OVER XOR      ( is error address=NULL$ ? )
    ( V5, ZEN and Staapl differ, prefer Staapl I think)
    IF                  ( its not NULL$ )
      CR TIB #TIB @ TYPE ( Display line in TIB )
      CR >IN @ [CHAR] ^ emits ( ^ under offending word )
      CR .$ ."  ? "     ( followed by error message and "?" )
    THEN
    PRESET ;            ( reset the data stack, TIB and vectored I/O )

: QUIT ( -- )
 ( Reset return stack pointer and start text interpreter. )
  RP0 @ RP!           ( initialize the return stack )
  BEGIN
    [COMPILE] [       ( start text interpreter )
    BEGIN
      ['] que           ( get a line and evaluate it)
      CATCH             ( execute commands with error handler)
      ?DUP
    UNTIL ( a)          ( exit if an error occurred )
    'PROMPT @ >R          ( EFORTH-ZEN and EFORTH-V5 save and restore current prompt address, Staapl doesnt)
    CONSOLE             ( Initialize for terminal interaction)
    \\ Fbreak
    quitError           ( Report error and reset data stack, source/TIB and vectored I/O ) 
    R> ?DUP IF 'PROMPT ! THEN ( Restore Prompt)
    ( V5 and ZEN also send "ERR" to file handler if prompt is not OK which is a little off )
  AGAIN ;               ( go back get another command line )

: quit1 ( -- ) ( TODO-34-FILES maybe move as was near QUIT )
  ( Evaluate a line that is already in TIB - could be compiling or interpreting, if error then report it)
  ['] EVAL ( evaluate one line - not this is ' EVAL which gets a line, not 'EVAL which gets one TOKEN )
  CATCH             ( execute commands with error handler)
  ?DUP
  IF ( Its an error )
    quitError           ( Report error and reset data stack) 
    [COMPILE] [       ( Exit compiling e.g. if error in a definition )
  THEN ;


( === Utilities Zen pg98  - looks like all moved )

( === Memory Dump Zen pg99 _TYPE do+ DUMP )

( ERRATA Staapl - uses COUNT which is technically correct but poor typing )

: _TYPE ( b u -- )
  ( Send a counted string to output )
  FOR           ( repeat u+1 times )
    AFT         (  skip to THEN the first time )
    DUP C@      ( get one character from b )
    >CHAR EMIT  ( display only printable char )
    1+
  THEN NEXT     ( repeat u times )
  DROP ;        ( discard b address )

: dm+ ( b u -- b )
  ( Dump u bytes from , leaving a+u on the stack.)
  OVER 4 U.R SPACE  ( print address first )
  FOR AFT           ( repeat u times )
  DUP C@ 3 U.R      ( display bytes in 3 columns )
  1+ THEN NEXT ;   ( repeat u times )

( ERRATA Staapl & Zen - uses -ROT which is not defined (its ROT ROT)
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

( DUMP needs NUF? which needs ?RX, so will fail test if those are not defined yet )
?test\\ LAST @ 48 DUMP 0 TEST

( === Stack Dump Zen pg100 .S )

: .S ( -- )
  ( Display the contents of the data stack.)
  CR            ( start stack dump on a new line)
  DEPTH         ( get stack depth )
  FOR AFT       ( repeat that many times )
      R@ PICK . ( print one item in stack )
    THEN
  NEXT          ( repeat until done )
  ."  <sp " ;    ( print stack pointer )

?test\\ 1 2 .S 1 2 2 TEST

( === More Forth2012 words === 
: UNUSED ( -- u ; https://forth-standard.org/standard/core/UNUSED )
  NP @ CP @ - ;

( === Stack Checking Zen pg101 !CSP ?CSP )

: .BASE ( -- ; report current base in Decimal)
  BASE @ DECIMAL DUP . BASE  ! ;
: .FREE ( -- ; report free memory)
  CP 2@ - U. ;
: !CSP ( -- ; Save stack pointer for error checking )
  SP@ CSP ! ;
: ?CSP ( -- ; Check stack pointer matches saved stack pointer )
  SP@ CSP @ XOR ABORT" stack depth" ;

?test\\ .BASE .FREE 1 !CSP ?CSP 1 1 TEST

( === Dictionary Dump Zen pg102 .ID WORDS )

: .ID ( na -- )
  ( Display the name at address.)
  ?DUP                ( not valid name if na=0 )
  IF COUNT            ( get length by mask lexicon bits )
    BYTEMASK AND         ( limit length to 31 characters )
    ( ERRATA? Zen uses TYPE which presumes name is all printable chars (V5 correct )
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

?test\\ WORDS 0 TEST ( Commented out as expensive )

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
  THEN DROP FALSE ;       ( end of vocabulary, failure )
?test\\ BL WORD DUP NAME? SWAP >NAME = -1 1 TEST ( Test FAST JS version )
( : >NAME FORTH>NAME ; ) ( Uncomment to use FORTH version of >NAME )
?test\\ BL WORD DUP NAME? SWAP FORTH>NAME = -1 1 TEST

( === The simplest Decompiler Zen pg104 SEE )
: SEE ( -- ; <string> )
  '                 ( ca)
  CR
  DUP @ tokenDoList =
  IF
    ." : " 
    DUP >NAME .ID ( xt )
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

?test\\ SEE FORTH>NAME 0 TEST

( ERRATA Zen uses CONSTANT but doesnt define it )
( === Signon Message Zen pg105 VER hi )

17 CONSTANT VER ( Return the version number of this implementation.)

: version CR ." webFORTH V" BASE @ DECIMAL VER 0 <# # # 46 HOLD # # 46 HOLD # #> TYPE ( display sign-on text and version )  BASE ! CR ;

( ERRATA v5 'hi' doesnt restore BASE )
( ERRATA ZEN uses !XIO when it means !IO)
: hi ( -- )
  !IO           ( initialize terminal I/O )
  version ; COMPILE-ONLY

( === Hardware Reset Zen pg106 COLD )
( ERRATA v5 adds "6 CP 3 MOVE OVERT" without defining MOVE, and unclear what it does, Zen & Staapl dont have EMPTY)
: EMPTY ( -- )
  ( Empty out any definitions)
  FORTH CONTEXT @ DUP CURRENT 2! ;

( Note this is in ROM, as default BOOT it has to be) 
CREATE 'BOOT  ' hi , ( application vector )

( ERRATA ZEN uses but doesnt define U0 and assumes US=37 )
: COLD ( -- )
  BEGIN
    userAreaInit  ( initialize user area, often U0 UP =US CMOVE )
    ( initRegisters ; this is needed somewhere - to initialize RP, and IP, but clearly must be done before here )
    PRESET        ( Initialize TIB and SP )
    CONSOLE
    'BOOT @EXECUTE ( Vectored Boot routine, defaults to hi)
    ( EPROM: EMPTY OVERT will initialize LAST (from usersave -> FORTH -> CONTEXT & CURRENT )
    EMPTY          ( Make FORTH context vocabulary -and empty out definitions )
    OVERT         ( And Reset FORTH definition to last definition from the userAreaInit  )
    QUIT          ( Invoke Forth "operating system" )
  AGAIN ;         ( Safeguard the Forth interpreter )

: WARM CONSOLE 'BOOT @EXECUTE QUIT ;
userAreaSave ( Save current User variables for COLD boot )
`;

let stdinBuffer = null; // Local to ?RX do not access directly - but there can be only one so global

/*
  This group of classes encapsulate memory management to hide it from the Forth code that is common
  to all of them.
 */
function align8(byteaddr) { return byteaddr; } // 8
function align16(byteAddr) { return (((byteAddr - 1) >> 1) + 1) << 1; }
function align24(byteAddr) { return ((((byteAddr - 1) / 3) >> 0) + 1) * 3; }
function align32(byteAddr) { return (((byteAddr - 1) >> 2) + 1) << 2; } // 32

// noinspection JSBitwiseOperatorUsage,JSBitwiseOperatorUsage
class FlashXX_XX {
  constructor({ romSize, ramSize, rom0, littleEndian = true }) {
    this.romSize = romSize;
    this.ramSize = ramSize;
    this.rom0 = rom0;
    this.romWritable = true; // Set to false after defined
    this.littleEndian = littleEndian;
  }
  cellRomFetch(cellAddr) {
    if (cellAddr >= this.romCells) {
      console.log('Attempt to read above top of Rom at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this.rom[cellAddr];
  }
  cellRamFetch(cellAddr) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to read above top of Ram at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this.ram[cellAddr];
  }

  cellRamStore(cellAddr, v) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to write above top of Ram at');
    } // TODO-OPTIMIZE comment out
    this.ram[cellAddr] = v;
  }

  cellRomStore(cellAddr, v) {
    if (!this.romWritable) {
      console.log('Attempt to write to Rom after closed at', cellAddr);
    } // TODO-OPTIMIZE comment out
    this.rom[cellAddr] = v;
  }

  fetchCell(byteAddr) {
    return (byteAddr & this.rom0) ? this.cellRomFetch(this.romAddr(byteAddr)) : this.cellRamFetch(this.ramAddr(byteAddr));
  }

  storeCell(byteAddr, v) {
    if (byteAddr & this.rom0) {
      this.cellRomStore(this.romAddr(byteAddr), v);
    } else {
      this.cellRamStore(this.ramAddr(byteAddr), v);
    }
  }
  _fetch8(byteAddr, mask) {
    const offset = byteAddr & mask;
    const shiftbits = 8 * (this.littleEndian ? offset : (mask - offset));
    const cell = this.fetchCell(byteAddr); // Does not have to be aligned
    return (cell >> shiftbits) & 0xFF;
  }
  _store8(byteAddr, v, mask) {
    const offset = byteAddr & mask;
    const shiftbits = 8 * (this.littleEndian ? offset : (mask - offset));
    const cell = this.fetchCell(byteAddr);
    this.storeCell(byteAddr, (cell & (-1 ^ (0xFF << shiftbits))) | (v << shiftbits));
  }
  // Encode a string into an address and return the number of bytes written
  // Does not check the start address, which will most often NOT be a cell boundary as will have length first
  encodeString(byteAddr, s) {
    return new TextEncoder().encodeInto(s,  this.buff8(byteAddr)).written; // Uint8Array
  }
  decodeString(byteStart, byteEnd) {
    return new TextDecoder().decode(this.buff8(byteStart, byteEnd - byteStart));
  }
  buff8(byteAddr, bytes) { // TODO - backport to MemXX_XX
    const isRom = byteAddr & this.rom0;
    const ramOrRom = isRom ? this.rom : this.ram;
    const start = isRom ? byteAddr - this.rom0 : byteAddr; // in bytes
    if (typeof bytes === 'undefined') { bytes = ramOrRom.byteLength - start; }
    return new Uint8Array(ramOrRom.buffer, start, bytes);
  }
  // Only used in token - which is bytes and never aligned
  copyWithin(byteDestn, byteSource, byteEnd) {
    const bytes = byteEnd - byteSource;
    const dBuf = this.buff8(byteDestn, bytes);
    const sBuf = this.buff8(byteSource, bytes);
    for (let i = 0; i < bytes; i++) {
      dBuf[i] = sBuf[i];
    }
  }
}
// noinspection JSBitwiseOperatorUsage
class Flash8_XX extends FlashXX_XX {
  constructor({ romSize, ramSize, rom0, littleEndian = true }) {
    super({ romSize, ramSize, rom0, littleEndian });
    this.ram = new Uint8Array(this.ramSize); // Note its in bytes, not cells
    this.rom = new Uint8Array(this.romSize); // Note its in bytes, not cells
    this.romCells = romSize >> 1;
    this.ramCells = ramSize >> 1;
  }
  _store16(uint8arr, byteAddr, v) {
    if (this.littleEndian) {
      uint8arr[byteAddr++] = v;
      uint8arr[byteAddr] = v >> 8;
    } else {
      uint8arr[byteAddr++] = v >> 8;
      uint8arr[byteAddr] = v;
    }
  }
  fetch8(byteAddr) {
    return (byteAddr & this.rom0) ? this.rom[byteAddr - this.rom0] : this.ram[byteAddr];
  }
  store8(byteAddr, v) {
    if (byteAddr & this.rom0) {
      this.rom[byteAddr - this.rom0] = v;
    } else {
      this.ram[byteAddr] = v;
    }
  }
}
// noinspection JSBitwiseOperatorUsage
class Flash8_16 extends Flash8_XX {
  constructor({ romSize, ramSize, rom0, littleEndian = true }) {
    super({ romSize, ramSize, rom0, littleEndian });
    this.romCells = romSize >> 1;
    this.ramCells = ramSize >> 1;
  }
  _fetch16(uint8arr, byteAddr) {
    return this.littleEndian
      ? uint8arr[byteAddr++] + (uint8arr[byteAddr] << 8)
      : uint8arr[byteAddr++] << 8 + uint8arr[byteAddr] << 8;
  }
  cellRomFetch(cellAddr) { // cell addresses are 16 bits on 8 bit base
    if (cellAddr >= this.romCells) {
      console.log('Attempt to read above top of Rom at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch16(this.rom, cellAddr << 1);
  }
  cellRamFetch(cellAddr) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to read above top of Ram at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch16(this.ram, cellAddr << 1);
  }

  cellRamStore(cellAddr, v) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to write above top of Ram at');
    } // TODO-OPTIMIZE comment out
    this._store16(this.ram, cellAddr << 1, v);
  }
  cellRomStore(cellAddr, v) {
    if (!this.romWritable) {
      console.log('Attempt to write to Rom after closed at', cellAddr);
    } // TODO-OPTIMIZE comment out
    this._store16(this.rom, cellAddr << 1, v);
  }
  fetchCell(byteAddr) {
    const isRom = byteAddr & this.rom0;
    return this._fetch16(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr);
  }
  storeCell(byteAddr, v) {
    const isRom = byteAddr & this.rom0;
    this._store16(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr, v);
  }
  //romAddr(byteAddr) { return ((byteAddr ^ this.rom0) >> 1); }
  ramAddr(byteAddr) { return (byteAddr >> 1); }
  //fromRomAddr(romAddr) { return (romAddr << 1) | this.rom0; }
  fromRamAddr(ramAddr) { return (ramAddr << 1); }
  cellAlign(byteaddr) { return align16(byteaddr); }
  memAlign(byteaddr) { return align8(byteaddr); }
  assertAlign(byteAddr) {
    // Check expectation already aligned, can comment out for speed
    console.assert(!(byteAddr & 0x01));
  }
}
// noinspection JSBitwiseOperatorUsage
class Flash8_24 extends Flash8_XX {
  constructor({ romSize, ramSize, rom0, littleEndian = true }) {
    super({ romSize, ramSize, rom0, littleEndian });
    this.romCells = (romSize / 3) >> 0;
    this.ramCells = (ramSize / 3) >> 0;
  }
  _fetch24(uint8arr, byteAddr) {
    return this.littleEndian
      ? ((((uint8arr[byteAddr + 2] << 8) | uint8arr[byteAddr + 1]) << 8) | uint8arr[byteAddr])
      : ((((uint8arr[byteAddr++] << 8) | uint8arr[byteAddr++]) << 8) | uint8arr[byteAddr]); }

  cellRomFetch(cellAddr) { // cell addresses are 16 bits on 8 bit base
    if (cellAddr >= this.romCells) {
      console.log('Attempt to read above top of Rom at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch24(this.rom, cellAddr * 3);
  }
  cellRamFetch(cellAddr) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to read above top of Ram at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch24(this.ram, cellAddr * 3);
  }

  _store24(uint8arr, byteAddr, v) {
    if (this.littleEndian) {
      uint8arr[byteAddr++] = v;
      uint8arr[byteAddr++] = v >> 8;
      uint8arr[byteAddr] = v >> 16;
    } else {
      uint8arr[byteAddr++] = v >> 16;
      uint8arr[byteAddr++] = v >> 8;
      uint8arr[byteAddr] = v;
    }
  }
  cellRamStore(cellAddr, v) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to write above top of Ram at');
    } // TODO-OPTIMIZE comment out
    this._store24(this.ram, cellAddr * 3, v);
  }
  cellRomStore(cellAddr, v) {
    if (!this.romWritable) {
      console.log('Attempt to write to Rom after closed at', cellAddr);
    } // TODO-OPTIMIZE comment out
    this._store24(this.rom, cellAddr * 3, v);
  }
  fetchCell(byteAddr) {
    const isRom = byteAddr & this.rom0;
    return this._fetch24(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr);
  }
  storeCell(byteAddr, v) {
    const isRom = byteAddr & this.rom0;
    this._store24(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr, v);
  }
  //romAddr(byteAddr) { return (((byteAddr ^ this.rom0) / 3) >> 0); }
  ramAddr(byteAddr) {
    return ((byteAddr / 3) >> 0); }
  //fromRomAddr(romAddr) { return (romAddr * 3) | this.rom0; }
  fromRamAddr(ramAddr) { return (ramAddr * 3); }
  cellAlign(byteaddr) { return align24(byteaddr); }
  memAlign(byteaddr) { return align8(byteaddr); }
  assertAlign(byteAddr) {
    // Check expectation already aligned, can comment out for speed
    console.assert(!(byteAddr & 0x03));
  }
}

class Flash8_32 extends Flash8_XX {
  constructor({ romSize, ramSize, rom0, littleEndian = true }) {
    super({ romSize, ramSize, rom0, littleEndian });
    this.romCells = romSize >> 2;
    this.ramCells = ramSize >> 2;
  }
  _fetch32(uint8arr, byteAddr) {
    return this.littleEndian
      ? (((((uint8arr[byteAddr + 3] << 8) | uint8arr[byteAddr + 2]) << 8) | uint8arr[byteAddr + 1]) << 8) | uint8arr[byteAddr]
      : (((((uint8arr[byteAddr++] << 8) | uint8arr[byteAddr++]) << 8) | uint8arr[byteAddr++]) << 8) | uint8arr[byteAddr]; }

  cellRomFetch(cellAddr) { // cell addresses are 16 bits on 8 bit base
    if (cellAddr >= this.romCells) {
      console.log('Attempt to read above top of Rom at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch32(this.rom, cellAddr << 2);
  }
  cellRamFetch(cellAddr) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to read above top of Ram at', cellAddr);
    } // TODO-OPTIMIZE comment out
    return this._fetch32(this.ram, cellAddr << 2);
  }

  _store32(uint8arr, byteAddr, v) {
    if (this.littleEndian) {
      this._store16(uint8arr, byteAddr + 2, v >> 16);
      this._store16(uint8arr, byteAddr, v);
    } else {
      this._store16(uint8arr, byteAddr, v >> 16);
      this._store16(uint8arr, byteAddr + 2, v);
    }
  }
  cellRamStore(cellAddr, v) {
    if (cellAddr >= this.ramCells) {
      console.log('Attempt to write above top of Ram at');
    } // TODO-OPTIMIZE comment out
    this._store32(this.ram, cellAddr << 2, v);
  }
  cellRomStore(cellAddr, v) {
    if (!this.romWritable) {
      console.log('Attempt to write to Rom after closed at', cellAddr);
    } // TODO-OPTIMIZE comment out
    this._store32(this.rom, cellAddr << 2, v);
  }
  fetchCell(byteAddr) {
    const isRom = byteAddr & this.rom0;
    return this._fetch32(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr);
  }
  storeCell(byteAddr, v) {
    const isRom = byteAddr & this.rom0;
    this._store32(isRom ? this.rom : this.ram, isRom ? (byteAddr - this.rom0) : byteAddr, v);
  }
  //romAddr(byteAddr) { return ((byteAddr ^ this.rom0) >> 2); }
  ramAddr(byteAddr) { return (byteAddr >> 2); }
  //fromRomAddr(romAddr) { return (romAddr << 2) | this.rom0; }
  fromRamAddr(ramAddr) { return (ramAddr << 2); }
  cellAlign(byteaddr) { return align32(byteaddr); }
  memAlign(byteaddr) { return align8(byteaddr); }
  assertAlign(byteAddr) {
    // Check expectation already aligned, can comment out for speed
    console.assert(byteAddr === align24(byteAddr));
  }
}

// noinspection JSBitwiseOperatorUsage
class Flash16_16 extends FlashXX_XX {
  constructor({ romSize, ramSize, rom0 }) {
    super({ romSize, ramSize, rom0 });
    this.romCells = romSize >> 1;
    this.ramCells = ramSize >> 1;
    this.ram = new Uint16Array(this.ramCells);
    this.rom = new Uint16Array(this.romCells);
  }

  romAddr(byteAddr) { return ((byteAddr ^ this.rom0) >> 1); }
  ramAddr(byteAddr) { return (byteAddr >> 1); }
  //fromRomAddr(romAddr) { return (romAddr << 1) | this.rom0; }
  fromRamAddr(ramAddr) { return (ramAddr << 1); }
  fetch8(byteAddr) { return this._fetch8(byteAddr, 0x01); }
  store8(byteAddr, v) { this._store8(byteAddr, v, 0x01); }
  cellAlign(byteaddr) { return align16(byteaddr); }
  memAlign(byteaddr) { return align16(byteaddr); }
  assertAlign(byteAddr) {
    // Check expectation already aligned, can comment out for speed
    console.assert(!(byteAddr & 0x01));
  }
}

// noinspection JSBitwiseOperatorUsage
class Flash32_32 extends FlashXX_XX {
  constructor({ romSize, ramSize, rom0 }) {
    super({ romSize, ramSize, rom0 });
    this.romCells = romSize >> 2;
    this.ramCells = ramSize >> 2;
    this.ram = new Uint32Array(this.ramCells);
    this.rom = new Uint32Array(this.romCells);
  }
  romAddr(byteAddr) { return ((byteAddr ^ this.rom0) >> 2); }
  ramAddr(byteAddr) { return (byteAddr >> 2); }
  //fromRomAddr(romAddr) { return (romAddr << 2) | this.rom0; }
  fromRamAddr(ramAddr) { return (ramAddr << 2); }
  fetch8(byteAddr) { return this._fetch8(byteAddr, 0x03); }
  store8(byteAddr, v) { this._store8(byteAddr, v, 0x03); }
  cellAlign(byteaddr) { return align32(byteaddr); }
  memAlign(byteaddr) { return align32(byteaddr); }
  assertAlign(byteAddr) {
    // Check expectation already aligned, can comment out for speed
    console.assert(!(byteAddr & 0x03));
  }
}

// Default memory class for different combinations of MEM and CELL
// note 16_24 and 32_24 are intentionally unsupported 16_32 and 32_16 aren't implemented but could easily be if there is a need
const MemClasses = {
  '8_16': Flash8_16,
  '8_24': Flash8_24,
  '8_32': Flash8_32,
  '16_16': Flash16_16,
  // '16_32': Flash16_32, // Not implemented yet
  // '32_16': Flash32_16, // Not implemented yet
  '32_32': Flash32_32,
};

// noinspection JSBitwiseOperatorUsage,JSUnusedGlobalSymbols
class Forth {
  // Build and return an initialized Forth memory obj
  constructor({ CELLL = 2, MEM = 8, memClass = undefined,
    ROMSIZE = undefined, RAMSIZE = undefined,
    testFlags = 0, testDepth = 1,
    rqFiles = 0,
    extensions = [] }) {
    // ERRATA Zen doesnt define CELLL (and presumes is 2 in multiple places)
    this.CELLL = CELLL;  // 2,3 or 4. Needs to be big enough for an address
    // ported to Arduino below here to L.1823
    this.CELLbits = CELLL * 8; // Number of bits in a cell - used for loops and shifts
    // mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
    // Support parameters for TODO-27-MEMORY TODO-28-MULTI
    // ported to Arduino above
    // === Support for Debugging ============

    jsUsers[testFlagsOffset][1] = testFlags; // Pass configuration through to user variable
    jsUsers[testDepthOffset][1] = testDepth; // Pass configuration through to user variable
    this.debugExcecutionStack = []; // Maintains a position, like a stack trace, don't manipulate directly use functions below
    this.debugName = '?'; // Set in threadtoken()
    this.padTestLength = 0; // Display pad length TODO check - probably obsolete
    // === Javascript structures - implement the memory map and record the full state.

    // ported below to L.1840 - but most things output by XC
    // === Memory layout
    // Memory may be aligned to a boundary depending on underlying mem store (which may or may not match CELLL), this assumption should be confined to ALIGNED
    // Now the memory map itself, starting at the top of memory.
    // ERRATA In Zen the definitions on Zen pg26 dont come close to matching the addresses given as the example below. In particular UPP and RPP(RP0) overlap !
    // Arbitrary address to use for RAM - but must be power of 2 and note avoiding 0x80000000 for CELLL=4 as hits math issues in JS with negative addresses
    this.RAM0 = 0;
    this.ROMSIZE = ROMSIZE;
    this.RAMSIZE = RAMSIZE;
    //TODO there is bad code in the Arduino that does wrong compares on 0x8000 or 0x80000000 fix it !
    this.ROM0 = this.ROMSIZE ? (CELLL === 4 ? 0x40000000 : CELLL === 3 ? 0x800000 : 0x8000) : 0;
    const RAMTOP = this.RAM0 + this.RAMSIZE; // top of memory default to 4K cells
    const US = 0x40 * this.CELLL;  // user area size in cells i.e. 64 variables - standard usage below is using about 37
    this.UPP = RAMTOP - US; // start of user area // TODO-28-MULTI UP should be a variable, and used in most places UPP is
    // 8 cell buffer between RP0 and UPP
    const RP0 = this.UPP - (8 * this.CELLL);  // top of return stack RP0
    const RTS = 0x80 * this.CELLL; // return stack/TIB size // eFORTH-DIFF was 64 which is tiny for any kind of string handling
    this.TIB0 = RP0 - RTS; // Terminal input buffer - shares space with Return stack //TODO-28-MULTITASK will move
    // 8 cell buffer between Stack and TIB
    this.SPP = this.TIB0 - 8 * this.CELLL; // top of data stack SP0
    const SPS = 0x80 * this.CELLL; // Size of data stack 256 bytes for now
    // Start of Ram (Below here should only be changed during compilation),
    // PAD is 80 bytes above the current top of Data space or Code directory, and HLD (where numbers are build for output) is a few bytes growing down from PAD.
    this.RAMNAMEE = this.SPP - SPS; // name dictionary in Ram (there may be another in Rom)

    // And then building ROM from the bottom up. The gap in middle is code directory
    // const COLDD = 0x100; // cold start vector - is only relevant to DOS
    this.UZERO = ROMSIZE ? this.ROM0 : 0;
    // Above UZERO is a store of initial values for User variables
    this.RAMCODEE = ROMSIZE ? this.RAM0 : (this.UZERO + US); // In Flashable - RAM code dictionary is at start of RAM, in single memspace it grows up from top of US to NAMEE
    // PAD is 80 bytes above the current top of Data space or Code directory, and HLD (where numbers are build for output) is a few bytes growing down from PAD.
    console.log('Space for', this.RAMNAMEE - this.RAMCODEE, 'bytes for code and names');

    // Memory definition in ROM area - during startup
    if (ROMSIZE) {
      this.ROMNAMEE = this.ROM0 + ROMSIZE;
      this.ROMCODEE = this.UZERO + US;
    }
    this.rqFiles = rqFiles;

    // Get a instance of a class to store in
    this.m = new (memClass || MemClasses[`${MEM}_${this.CELLbits}`])({ ramSize: this.RAMSIZE, romSize: this.ROMSIZE, rom0: this.ROM0 });
    this.jsFunctions = [];  // Maps tokens to executable functions - first is zero as a invalid token

    // Needs to be after the call to create this.m, its endian dependent as lowest address byte is always the count
    if (this.m.littleEndian) {
      this.CELLMASK = l.TRUE ^ (0xFF ^ l.BYTEMASK);
    } else {
      this.CELLMASK = l.TRUE ^ ((0xFF ^ l.BYTEMASK) << (this.CELLbits - 8));
    }

    // === Standard pointers used - Zen pg22
    // TODO-28-MULTI think about how these may need to be Task specific
    this.ramSPP = this.m.ramAddr(this.SPP); // start of data stack - grows down, points at top of stack - 8 word buffer for safety
    this.IP = 0;    // Interpreter Pointer
    this.PAYLOAD = 0; // Used by functions to know where to get argument
    this.ramSP = this.ramSPP;  // Data Stack Pointer but in MEM units rather than bytes
    this.ramRP = this.m.ramAddr(RP0);  // Return Stack Pointer (aka BP in 8086)
    this.ramUP = this.m.ramAddr(this.UPP);  // User Area Pointer // TODO-28-MULTI will move this around
    // ported to Arduino above

    // Ported to Android below to L.1898
    // create data structures
    // Setup pointers for first dictionary entries.
    this.Ustore(CPoffset, this.ROMCODEE || this.RAMCODEE); // Pointer to where compiling into dic
    this.Ustore(NPoffset, this.ROMNAMEE || this.RAMNAMEE); // Pointer to where writing name stack
    this.Ustore(VPoffset, this.ROMCODEE ? this.RAMCODEE : 0); // Pointer to start of writing variables, might be 0 if using code space like eForth does
    //console.assert(this.npFetch() > 0); // Quick test that above worked - should be commented out
    this.Ustore(RP0offset, RP0);
    this.Ustore(SP0offset, this.m.fromRamAddr(this.ramSPP));
    // Allow extensions of functions by caller - used for example to vector console I/O
    // Order is significant, as buildDictionary will define a jsFunction that points to the function as defined then.
    jsFunctionAttributes.forEach((e, i) => { jsFunctionAttributes[i] = this.extensionExpandDefaults(e); }); // Expand things like "name"
    extensions.forEach((e) => this.extensionAdd(e));
    this.buildDictionary();
    // compiling forthInForth is done outside this as it is async. TODO-23-NODEAPI may change
  }
  // Extract some memory writing functions

  // === Build dictionary, mostly from jsFunctionAttributes
  buildDictionary() {
    // Define the first word in the dictionary, I'm using 'FORTH' for this because we need this variable to define everything else.
    this.CODE('FORTH');

    this.DW(tokenVocabulary); // Uses assumption that tokenVocabulary is first in jsFunctionAttributes
    // Complicated: If there is ROM then point at RAM (VP) but if its zero skip a CELL as vocab ptr of 0 assumed empty
    const vocabPtr = (this.ROM0 ? (this.Ufetch(VPoffset) || this.CELLL) : (this.cpFetch() + this.CELLL));
    this.DW(vocabPtr); // Point to first cell in VP (data area in RAM or of not separated the next word)
    if (this.ROM0) { // Increment VP over area
      this.Ustore(VPoffset, vocabPtr + 2 * this.CELLL); // ALLOT 2 spaces (should default to zero)
    } else {
      this.DW(0, 0);
    }
    this.Ustore(CURRENToffset, vocabPtr); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.Ustore(CURRENToffset + 1, vocabPtr); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.Ustore(CONTEXToffset, vocabPtr); // Initialize Current. Context & Current+CELLL initialized in USER process Zen pg46
    this.OVERT(); // Uses the initialization done by this.Ustore(CURRENToffset) above.

    // copy constants over
    ['CELLL', 'CELLbits', 'CELLMASK', 'TIB0', 'rqFiles'].forEach((k) => this.buildConstant(k, this[k]));
    Object.entries(l).forEach((kv) => this.buildConstant(kv[0], kv[1]));

    this.js2xt = {};

    // Make some functions available as Forth words
    jsFunctionAttributes.forEach((e) => this.extensionAddToJSFunctions(e));

    // Build user variables
    // Bracket with a sanity check - also initializes TIB0 from this.TIB0
    console.assert(this.Ufetch(NPoffset) > 0);
    jsUsers.forEach((nv) => this.buildUser(nv[0], nv[1]));
    console.assert(this.Ufetch(NPoffset) > 0);
  }
  extensionAddConstant(e) {
    if (typeof e.constant === 'number') {
      if (this.lastFetch()) {
        this.buildConstant(e.n, e.constant);
      } else {
        l[e.n] = e.constant; // Will be added later
      }
    }
  }
  buildConstant(name, val) {
    // Defining function for constants, Replaced by CONSTANT in FORTH
    this.CODE(name);
    // Note assumption that token for constants is 1, i.e. its the 2nd tokenFunction defined
    this.DW(tokenNextVal, val);
    this.OVERT();
  }
  buildCode(name, tok, attribs) {
    let xt;
    if (attribs.defer) {
      const xtCode = this.cpFetch();
      this.DW(tok); // Entire definition is token for JS function
      this.CODE(name); // Will point at next byte of dict (not the tok)
      xt = this.cpFetch();
      this.DW(tokenDefer);
      this.DW(xtCode);
    } else {
      this.CODE(name);
      xt = this.cpFetch();
      this.DW(tok);  // The entire definition is the token for the JS function
    }
    this.OVERT();
    if (attribs.immediate) {
      this.setHeaderBits(l.IMED);
    }
    return xt;
  }
  buildUser(name, init) {
    if (this.isTestFlags(0x01)) console.log('USER>>', name, init);
    const _USER = this.Ufetch(0) || 0;
    const initVal = typeof init === 'string'
      ? (typeof this[init] !== 'undefined' ? this[init] : this.JStoXT(init)) // Either field of this, or function
      : typeof init === 'undefined'
        ? this.Ufetch(_USER) // Already storing during build (e.g. NP)
        : init;
    console.assert(typeof initVal !== 'undefined');
    this.Ustore(_USER, initVal);         // Initialize the variable for live compilation
    const offsetInCells = this.Ufetch(0);
    //UZERO is initialized at userAreaSave
    if (name) {                       // Put into dictionary
      this.CODE(name);
      this.DW(tokenUser, offsetInCells);
      this.OVERT();
    }
    this.Ustore(0, _USER + 1); // Need to skip to next _USER
  }

  // Add an extension, there are two cases of this
  // a: right at the start before building the dictionary, overriding any prior definition but not adding to jsFunctions
  // b: after dictionary is built, when need to add to, or replace, in jsFunctions
  extensionAdd(e) {
    this.extensionExpandDefaults(e); // Expand "foo" to {n: "foo"}
    this.extensionAddFunction(e); // If its a function, add it to the instance
    this.extensionAddConstant(e); // If its a constant add to dictionary (or to "l" if not yet build dictionary
    if (e.n && this.extensionFindFunction(e)) { // Have a forth name for this and its a function
      // Add to or replace jsFunctionAttributes for dictionary building.
      const i = jsFunctionAttributes.findIndex((j) => j.n === e.n);
      if (i === -1) { // Not found and have a name (forth name) for it.
        jsFunctionAttributes.push(e);
        if (this.jsFunctions.length) { // Have we built it already
          this.extensionAddToJSFunctions(e); // Add into JSFunctions
        }
      } else {
        Object.keys(e).forEach((k) => jsFunctionAttributes[i][k] = e[k]); // Copy over attributes as may not define all of the options
        if (this.jsFunctions.length) { // Have we built it already
          this.extensionReplaceInJSFunctions(e, i);
        }
      }
    }
  }

  extensionExpandDefaults(e) {
    if (typeof e === 'string') {
      e = { n: e };
    }
    return e;
  }
  // if an extension includes a function, add (or replace) this to the instance
  // This allows replacing any of Forth's functions, or adding new ones
  // Called when parsing extensions, or in extensionAdd()
  extensionAddFunction(e) {
    if (typeof e.f === 'function') { // It could be a string, referring to an existing function, or not a function at all
      let fname = e.f.name; // Might be 'f' if undefined
      if (fname.startsWith('bound ')) { fname = fname.slice(6); } // name gets changed if bind it.
      if (fname === 'f') fname = undefined; // an anonymous function will be called 'f' since assigned to a field f.
      if (fname) {
        this[fname] = e.f;
      }
    }
  }
  // Add a JS function (or token?) to make it available to the dictionary (see extensionAddFunction for where its added to the instance)
  // It is an error to call this if don't have a function (unless e is 0)
  extensionAddToJSFunctions(e) {
    if (e === 0) {
      this.jsFunctions.push(e); // Intentionally invalid pointer in slot 0
    } else {
      // Shortcut
      if (this.isTestFlags(0x01)) console.log('>> ', e);
      // for the function - first choice is a supplied, function otherwise look up either string supplied or n as a method of the forth instance.
      // noinspection JSUnresolvedVariable
      const f = this.extensionFindFunction(e);
      const tok = this.jsFunctions.length; // Where function will be pushed
      // special case: token Functions that need constants
      this.jsFunctions.push(f);
      if (e.token) {
        this.buildConstant(e.n, tok);
      } else {
        // regular code functions that just need a pointer in the dictionary.
        const xt = this.buildCode(e.n, tok, e);
        //console.assert(xt === this.JStoXT(e.n));
        if (e.jsNeeds) {
          this.js2xt[e.n] = xt;
        }
      }
    }
  }

  extensionReplaceInJSFunctions(e, i) {
    this.jsFunctions[i] = this.extensionFindFunction(e);
  }

  extensionFindFunction(e) {
    // for the function - first choice is a supplied, function otherwise look up either string supplied or n as a method of the forth instance.
    // noinspection JSUnresolvedVariable
    return typeof e.f === 'function' ? e.f : this[e.f || e.n];
  }

  compileForthInForth() {
    this.openBracket(); // Start off interpreting
    return this.interpret(forthInForth); // return a Promise
  }

  cleanupBootstrap() {
    // Cleanup - remove routines that shouldnt be being used
    jsFunctionAttributes.forEach((attribs, i) => {
      // noinspection JSUnresolvedVariable
      if (attribs.replaced) {
        this.jsFunctions[i] = null;
      }
    });
  }

  // === Support for Debugging ============
  debugClear() { this.debugExcecutionStack = []; }
  debugPush() { this.debugExcecutionStack.push(this.debugName); } // in tokenDoList
  debugPop() { this.debugExcecutionStack.pop(); } // in EXIT

  // Return an array of stack entries
  debugRam(start, end) {
    if (end < start) return 'UNDERFLOW';
    const res = [];
    for (let i = start; i < end; i++) { res.push(this.m.cellRamFetch(i)); }
    return res;
  }
  debugStack() {
    return this.debugRam(this.ramSP, this.ramSPP);
  }
  debugReturnStack() {
    return this.debugRam(this.ramRP, this.m.ramAddr(this.Ufetch(RP0offset)));
  }
  debugThread(xt) { //TODO comment out call to this, its expensive even to test flag in the middle of loop
    if (this.isTestFlags(0x02)) {
      this.debugName = this.xt2name(xt); // Expensive so only done when testing
      if (this.Ufetch(testDepthOffset) > this.debugExcecutionStack.length) {
        //TODO-28-MULTITASK RPP(RP0) and SPP will move
        console.log('R:', this.debugReturnStack(), this.debugExcecutionStack, this.xt2name(xt), 'S:', this.ramSPP === this.ramSP ? '' : this.debugStack(),
          this.padTestLength ? ('pad: ' + (this.padTestLength > 0 ? this.m.decodeString(this.padPtr(), this.padPtr() + this.padTestLength) : this.m.decodeString(this.padPtr() + this.padTestLength, this.padPtr()))) : '');
      }
    }
  }

  // ported to Arduino below L.2023

  // === Code words to support debugging on the console
  // Put debugNA in a definition to print a counted string on the console
  debugNA() { console.log('NAME=', this.countedToJS(this.SPfetch())); } // Print the NA on console
  // Put testing3 in a definition to start outputing stack trace on console.
  testing3(n = this.SPpop()) { this.Ustore(testFlagsOffset, n); } // TODO unclear if need this now
  isTestFlags(bb) { return (this.Ufetch(testFlagsOffset) & bb); }
  // Put Fbreak in a definition.
  Fbreak() {
    console.log('S:', this.debugStack());
    console.log('\nbreak in a FORTH word'); } // Put a breakpoint in your IDE at this line
  // debugPrintTIB will print the current TIB.
  debugPrintTIB() {
    console.log('TIB: ', this.m.decodeString(this.Ufetch(TIBoffset) + this.Ufetch(INoffset),
      this.Ufetch(TIBoffset) + this.Ufetch(nTIBoffset)));
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
    console.assert((this.ramSPP - this.ramSP) === stackDepth);
    // Compare stacks
    for (let i = 0; i < stackDepth; i++) {
      console.assert(this.SPpop() === b.pop());
    }
    this.debugClear(); // Reset Debug Stack as can be mucked up by THROW and CATCH
  }

  // === Functions to simplify storing and retrieving 16 bit values into 8 bit stacks etc.
  // These aren't part of eForth, but are here to simplify storing multi-byte words into 8 bit bytes in the Buffer.
  Mfetch(a) { return this.m.fetchCell(a); }
  Mstore(a, v) { this.m.storeCell(a, v); }  // Store at address a
  // 8 bit equivalents
  Mfetch8(a) { return this.m.fetch8(a); } // Returns byte at a
  Mstore8(a, v) { this.m.store8(a, v); }
  ALIGNED() { this.SPpush(this.m.cellAlign(this.SPpop())); }
  SPfetch() { return this.m.cellRamFetch(this.ramSP); }
  SPpop() { return this.m.cellRamFetch(this.ramSP++); }
  SPpush(v) { this.m.cellRamStore(--this.ramSP, v); }
  RPfetch() { return this.m.cellRamFetch(this.ramRP); }
  RPpop() { return this.m.cellRamFetch(this.ramRP++); }
  RPpush(v) { this.m.cellRamStore(--this.ramRP, v); }
  IPnext() { const v = this.Mfetch(this.IP); this.IP += this.CELLL; return v; }
  Ufetch(userindex) {
    return this.m.cellRamFetch(this.ramUP + userindex); }
  Ustore(userindex, w) {
    this.m.cellRamStore(this.ramUP + userindex, w); }
  SPpushD(x) {
    this.SPpush(x); // This should only push the bottom cell.
    this.SPpush(x >> (this.CELLL * 4) >> (this.CELLL * 4)); // Work around JS bug with >> 32
  }
  // d -- ; Pop double word off stack
  SPpopD() {
    return (this.SPpop() << (this.CELLL * 4) << (this.CELLL * 4)) + this.SPpop();
  }

  // === Access to the USER variables before they are defined
  currentFetch() { return this.Ufetch(CURRENToffset); }
  cpFetch() { return this.Ufetch(CPoffset); }
  // Return pointer to writable address space (aka data space), if code is going to RAM this will be CP, if code is going to ROM it will be VP
  vpFetch() { return this.Ufetch(VPoffset) || this.Ufetch(CPoffset); }
  cpAlign() { this.Ustore(CPoffset, this.m.cellAlign(this.cpFetch())); }
  // TODO-ARDUINO vpAlign needs updating
  // OLD vpAlign() { this.Ustore(VPoffset, this.m.cellAlign(this.vpFetch())); }
  // Align whichever pointer using for data space.
  vpAlign() {
    let h = this.Ufetch(VPoffset);
    const o = h ? VPoffset : CPoffset;
    h = this.m.cellAlign(h || this.Ufetch(CPoffset));
    this.Ustore(o, h);
  }
  npFetch() { return this.Ufetch(NPoffset) || this.ROMNAMEE; } // If ROMNAMEE is top of memory it will be 0, leading to negative results
  lastFetch() { return this.Ufetch(LASToffset); }
  padPtr() { return this.vpFetch() + 80; } // Sometimes JS needs the pad pointer

  stringBuffer() {
    this.SPpush(this.vpFetch() + 160); } // A string buffer used for input - not same as PAD see S" //TODO-24-FILES add to Arduino

  // === Functions related to building 'find'  and its wrappers ====

  // Convert a string made up of a count and that many bytes to a Javascript string.
  // it assumes a maximum of nameMaxLength (31) characters.
  // Mostly used for debugging but also in number conversion.
  stringToJS(caddr, u) {  // Convert string specified by address and count
    return this.m.decodeString(caddr, caddr + u); }
  countedToJS(a) { // Convert string specified by address which holds a count - possibly with a bytemask to JS
    return this.stringToJS(a + 1, this.Mfetch8(a) & l.BYTEMASK); }
  // Convert a name address to the code dictionary definition.
  na2xt(na) { return this.Mfetch(na - (2 * this.CELLL)); } // Forth version is NAME>
  // a u --; return JS string given an ANS style string on stack.
  SPpopString() {
    const u = this.SPpop();
    const a = this.SPpop();
    return this.stringToJS(a, u);
  }

  // Inner function of find, traverses a linked list Name dictionary.
  // name   javascript string looking for
  // va     pointer holding address of first element in the list.
  // cell1  if present, gives it a quick first-cell test to apply.
  // xt     if present we are looking for name pointing at this executable (for decompiler)
  // returns 0 or na
  _sameq(na1, na2, cells) { // return f
    // Note this is similar to SAME? but returns boolean
    const bytes = cells * this.CELLL;
    for (let i = 0; i < bytes; i += this.CELLL) {
      if (this.Mfetch(na1 + i) !== this.Mfetch(na2 + i)) {
        return false;
      }
    }
    return true;
  }

  //TODO-84-ARDUINO needs
  _findNameIn(caddr, u, va) { // c-addr u va -- nt | 0 ; https://forth-standard.org/proposals/find-name#contribution-58
    const cellCount = (u / this.CELLL) >> 0; // Count of cells after first one
    const na = caddr--; // Point at count
    const cell1 = this.Mfetch(na);  // Could be little or big-endian
    let p = va;
    while (p = this.Mfetch(p)) {
      //console.log('_find: comparing:', this.countedToJS(p)) // comment out except when debugging find
      const c1 = this.Mfetch(p) & this.CELLMASK; // count
      if (cell1 === c1) { // first cell matches (if cell1 not passed then does slow compare
        if (this._sameq(p + this.CELLL, na + this.CELLL, cellCount)) {
          return p;
        }
      }
      p -= this.CELLL; // point at link address and loop for next word
    }
    // Drop through not found
    return l.FALSE;
  }
  FIND_NAME_IN() { // caddr u va -- na; Note this ONLY currently works if caddr-- is a counted string
    const va = this.SPpop();
    const u = this.SPpop();
    const caddr = this.SPpop();
    this.SPpush(this._findNameIn(caddr, u, va));
  }
  //TODO-84-ARDUINO needs change from _find to _findNameIn and usage in jsFind
  // Search a single vocabulary for a string
  // This has same footprint as eForth's 'find' but we do not replace it since this is approx 8x faster
  // Note the string must be aligned to CELLL boundary even if using a non-aligned mem (e.g. celll=2 mem=8)
  jsFind() { // a va -- ca na | a 0
    const va = this.SPpop();
    const a = this.SPpop();
    //this.m.assertAlign(a);
    //console.log('find: Looking for', name) // comment out except when debugging find
    //const na = this._find(va, a);  // return matching na or 0

    const charCount = this.Mfetch8(a) & l.BYTEMASK;
    const na = this._findNameIn(a + 1, charCount, va);
    if (na) {
      this.SPpush(this.na2xt(na));
      this.SPpush(na);
    } else {
      this.SPpush(a);
      this.SPpush(l.FALSE);
    }
  }

  // Traverse dictionary to convert xt back to a na (for decompiler or debugging)
  xt2na(xt) {
    let p = this.currentFetch(); // vocabulary
    while (p = this.Mfetch(p)) {
      //console.log('_find: comparing:', this.countedToJS(p)) // comment out except when debugging find
      if (this.na2xt(p) === xt) {
        return p;
      }
      p -= this.CELLL; // point at link address and loop for next word
    }
    // Drop through not found
    return l.FALSE;
  }
  // ported to Arduino above L.2177-

  // Convert xt to a Javascript string of its name or 'undefined' (only used for debugging).
  xt2name(xt) {
    const na = this.xt2na(xt);
    return na ? this.countedToJS(na) : 'undefined';
  }

  // ported below L.2180-
  ToNAME() { this.SPpush(this.xt2na(this.SPpop())); }  // Fast version of >NAME see Forth definition below

  // TODO-29-VOCABULARY This just looks up a in the Context vocabulary, it makes no attempt to use multiple vocabularies
  // If required then fixing this to iterate over the context array should not break anything (this is what NAME? does)
  findName() { // a -- xt na | a F
    this.SPpush(this.Ufetch(CONTEXToffset));  // a va
    this.jsFind();                           // xt na | a F
  }
  // ported to Arduino above L.2180-

  // -- a; Push a Javascript string to a temporary location as a counted string, and put its address on the stack
  JStoCounted(s) {
    const tempBuf = this.m.cellAlign(this.vpFetch() + 12); // Above Data or Code below HLD which builds numbers down from PAD which is vpFetch + 80
    // copy string to TIB, and return length in bytes (which may not be same as s.length if UTF8;
    const count = this.m.encodeString(tempBuf + 1, s);
    this.Mstore8(tempBuf, count);
    let p = tempBuf + count + 1;
    const aligned = this.m.cellAlign(p);
    while (p < aligned) {
      this.Mstore8(p++, 0);
    }
    this.SPpush(tempBuf);
  }

  // Search for a string and return either its XT or 0
  JStoXT(s, save = false) {
    let xt = this.js2xt[s];
    if (xt) return xt; // Quick check for cached
    this.JStoCounted(s); // a;
    this.findName(); // xt na | a F
    if (this.SPpop()) {
      xt = this.SPpop();
      if (save) this.js2xt[s] = xt;
      return xt;
    } else {
      this.SPpop(); // Lose the address
      return undefined;
    }
  }

  // ported to Arduino below to L.2214-
  // === JS Functions to be able to define words ==== in Zen pg30 these are Macros.

  // Compile one or more words into the next consecutive code cells.
  DW(...words) {
    let cp = this.cpFetch();
    words.forEach((word) => {
      this.Mstore(cp, word);
      cp += this.CELLL;
    });
    this.Ustore(CPoffset, cp);
  }

  // a -- a; Check if a definition of the word at 'a' would be unique and display warning (but continue) if it would not be.
  // Same profile as ?UNIQUE but not turned into a code word as not used prior to
  qUnique() {
    this.SPpush(this.SPfetch());      // DUP
    this.SPpush(this.currentFetch()); // a a va; dictionary to search
    this.jsFind();                 // a xt na | a a F
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
  // expects in Name dictionary: <count><string><opt padding>
  // prepends:   <aligned address of next cell of code><address of na of last definition in vocabulary>...
  // Side effects are important: specifically.
  // LAST <= na
  dollarCommaN() {
    if (this.Mfetch8(this.SPfetch())) {         // DUP C@ IF  ; test for no word
      this.qUnique();
      let a = this.SPpop();
      this.Ustore(LASToffset, a);    // DUP LAST ! ; a=na  ; LAST=na
      // Link address points to previous NA (prev value of LAST)
      // Note that first time this is run, it gets a 0 (CURRENT is 0, @0 is 0) if that changes will need to test Current here.
      a -= this.CELLL; // CURRENT @ @ OVER ! ; a = la = top of current dic
      this.Mstore(a, this.Mfetch(this.currentFetch())); // CURRENT @ @ OVER ! ; a = la = top of current dic
      // Push CP (code field to where will build in dictionary) into ca, below a and store that ca into NP
      a -= this.CELLL;
      this.Mstore(a, this.cpFetch()); // ca=CP ;
      this.Ustore(NPoffset, a); // ca=CP ;
    } else {                    // THEN $" name" THROW ;
      this.ramSP++;// DROP
      console.log('name error'); // This is an error - in FORTH equivalent its a THROW
    }
  }

  // Make the most recent definition available in the directory. This is part of closing every 'defining word'
  OVERT() {
    this.Mstore(this.currentFetch(), this.lastFetch()); // LAST @ CURRENT @ !
  }
  // ported to Arduino above here

  //  Build a new definition - part of all defining words.
  CODE(name) {
    console.assert(name.length <= nameMaxLength);
    // <NP-after>CPh CPl <_LINK> LINKh LINKl count name... <NP-BEFORE>
    this.cpAlign(); // If required by memory store, align to boundary.
    // Note this is going to give the name string an integral number of cells.
    const a = this.m.cellAlign(this.npFetch() - name.length - this.CELLL);
    this.Ustore(NPoffset, a);
    this.SPpush(a); // so this.dollarCommaN can find it
    // This byte will be updated by this.IMMEDIATE() IMMEDIATE or COMPILE-ONLY
    // Note that the result of m.encodeString may not be same as name.length because of unicode issues
    this.Mstore8(a, this.m.encodeString(a + 1, name));
    this.dollarCommaN(); // Build the headers that precede the name
  }

  // ERRATA ZEN IMMEDIATE COMPILE-ONLY COMP IMED is not defined, in EFORTHv5 its defined as 0x80
  setHeaderBits(b) {
    const lastNA = this.lastFetch(); // LAST points at the name field of the last defined word
    this.Mstore8(lastNA, this.Mfetch8(lastNA) | b);
  }

  // ported below L.2278-
  // === Define this tokens used for each kind of defining word
  // Zen pg31
  // Tokens are just JS functions with an entry in jsFunctions with token:true
  // Words that will use a Javascript function for its action are just JS functions with an entry in jsFunctionAttributes

  //TODO-29 maybe define VOCABULARY as CREATE DOES> word then come back
  tokenVocabulary() {
    // : doVOC R> CONTEXT ! ;
    this.Ustore(CONTEXToffset, this.Mfetch(this.PAYLOAD));
  }

  // Put the contents of the payload (1 word) onto Stack, used for CONSTANT
  tokenNextVal() { this.SPpush(this.Mfetch(this.PAYLOAD)); }

  // This is the most important token function - used for a Colon word to iterate over the list.
  tokenDoList() {
    this.debugPush(); // Pop is in EXIT. this will be undefined if not 'testing'
    this.RPpush(this.IP);
    this.IP = this.PAYLOAD; // Point at first word in the definition
  }

  tokenDefer() { // TODO-ARDUINO needed
    // Payload contains XT of word to be executed, nothing goes on return stack as not unwound
    const xt = this.Mfetch(this.PAYLOAD);
    if (xt) this.threadtoken(xt);
  }
  // Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
  tokenUser() { this.SPpush(this.m.fromRamAddr(this.Mfetch(this.PAYLOAD) + this.ramUP)); }

  tokenValue() { //TODO-83-ARDUINO needs this
    // Get content of Payload which is offset in cells past ramUP, read that value and push it
    this.SPpush(this.m.cellRamFetch(this.Mfetch(this.PAYLOAD) + this.ramUP)); }

  // Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
  _tokenDoes() {
    const does = this.Mfetch(this.PAYLOAD);
    if (does) {
      this.debugPush();
      this.RPpush(this.IP);
      this.IP = does;
    }
  }
  tokenCreate() {
    this.SPpush(this.PAYLOAD + this.CELLL);
    this._tokenDoes();
  }

  toBODY(xt = this.SPpop()) { // xt -- a; push address of data space for something built with VARIABLE or CREATE or DEFER
    // defined for tokenVar, tokenCreate, tokenDefer, tokenValue
    const token = this.Mfetch(xt); // token - ideally tokenCreate or tokenVar
    // TokenVar and tokenCreate have an extra cell with a possible pointer to DOES>
    let dataSpace = ([tokenVar, tokenCreate].includes(token)) ? xt + (this.CELLL * 2) : xt + this.CELLL;
    if ([tokenVar, tokenValue].includes(token)) {
      dataSpace = this.Mfetch(dataSpace);
    }
    if (token === tokenValue) {
      dataSpace = this.m.fromRamAddr(dataSpace + this.ramUP);
    }
    this.SPpush(dataSpace);
  }
  // Used when the data is going to be in Ram and Code in ROM
  tokenVar() {
    this.SPpush(this.Mfetch(this.PAYLOAD + this.CELLL));
    this._tokenDoes();
  }

  // === INNER INTERPRETER YES THIS IS IT ! ==================== eForthAndZen#36
  // This is quite different from eForth as its token-threaded rather than direct threaded

  threadtoken(xt) {
    // This next section is only done while testing, and outputs a trace, so set it on (with testing3) immediately before a likely error.
    this.debugThread(xt); //TODO comment out this expensive call
    const tok = this.Mfetch(xt);
    this.PAYLOAD = xt + this.CELLL;
    return this.jsFunctions[tok].call(this); // Run the token function - like tokenDoList or tokenVar - will return null or a Promise
  }

  // This is not re-entrant, normally its threadtoken you want ....
  // In particular you cannot use this to nest forth in code in forth
  // If that becomes necessary, it MIGHT work to save IP (where?) and restore after while loop
  // Cant use R or S for it as words use that across calls to the 'EVAL
  async runXT(xt) {
    let waitFrequency = 0;
    //console.assert(xt && this.IP === 0); // Cant nest runXT()
    // eslint-disable-next-line no-constant-condition
    while (true) {
      try {
        await this.threadtoken(xt);
        // If this returns without changing program Counter, it will exit
        while (this.IP) {
          // console.assert(this.IP >= this.CODEE && this.IP <= this.NAMEE); // uncomment if tracking down jumping into odd places
          xt = this.IPnext();
          // 'await this.threadtoken(xt)' would be legit, but creates a stack frame in critical inner loop, when usually not reqd.
          const maybePromise = this.threadtoken(xt);
          if (maybePromise) {
            await maybePromise;
          } else if (!waitFrequency--) {
            //setTimeout(resolve, 0) is same as setImmediate(resolve) but latter is not available in browsers
            await new Promise((resolve) => setTimeout(resolve, 0)); //ASYNC: to allow IO to run
            waitFrequency = 100; // How many cycles to allow a thread swap
          }
        }
        return;
      } catch (err) {
        console.log('Error caught in runXT');
        console.error(err);
        xt = this.JStoXT('THROW', true);
        console.log('Looping back for a good throw');
      }
    }
  }

  MS() { // ms --; delay for a period of time  (async but just returns a promise)
    return new Promise((resolve) => setTimeout(resolve, this.SPpop()));
  }

  BYE() { // Should exit all the way out
    this.IP = 0;
  }

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
  EXECUTE() { return this.threadtoken(this.SPpop()); }

  // === Basic low level key I/O and links to OS - Zen pg 35
  // This section will need editing for other systems.
  /*
   * Input call chain is
   * ?RX  read one char if present
   * ?KEY via '?KEY to ?RX
   * KEY loop till ?KEY
   * ACCEPT read a line via KEY, processing control chars via 'TAP  to kTAP
   * QUERY read a line via REFILL to ACCEPT into TIB and reset >IN
   * que read an evaluate a line
   * QUIT loop over que, handling errors
   *
   * See https://github.com/mitra42/webForth/issues/17 for strategy for async version
   */

  // Call chain is ?RX < '?KEY  < ?KEY < KEY < ACCEPT < REFILL < QUERY < que < QUIT
  QRX() {
    const [f, c] = this.qrx();
    if (f) {
      this.SPpush(c);
      this.SPpush(l.TRUE);
    } else {
      this.SPpush(l.FALSE);
    }
  }

  // Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.
  TXbangC(c) { // noinspection JSUnresolvedFunction
    this.TXbangS(String.fromCharCode(c)); } // TXbangS is passed in by node and console.js
  TXbang() { this.TXbangC(this.SPpop()); }
  qrx() { return [false]; } // Overridden by node
  TYPE() { // a u -- ; same signature as Forth this.TYPE
    this.TXbangS(this.SPpopString());
  }

  bangIO() { } // Default to nothing to do, but Node extends

  // === Literals and Branches - using next value in dictionary === eForthAndZen#37

  // push the value in the next code word
  // The XT of this is stored in this.doLIT
  doLIT() { this.SPpush(this.IPnext()); }

  // See DOES> and CREATE, this patches the field after the token compiled by the create to point to the code following the DOES>
  // : DOES> R> LAST @ 2 CELLS - @ CELLL + ! ; // Untested Forth version, note side effect of the R> of doing an exit.
  DOES() {
    this.Mstore(
      this.Mfetch(this.Ufetch(LASToffset) - 2 * this.CELLL) + this.CELLL, // field after tokenVar compile by CREATE
      this.IP, // The address after the doDOES
    );
    this.EXIT(); // Exit the CREATE part
  }

  // Address Literals (aka branches and jumps) eForthAndZen#38

  // decrement count on Return stack, and branch if not decremented past zero (FOR..NEXT)
  // noinspection JSUnusedGlobalSymbols
  next() {
    let x = this.RPpop();
    const destn = this.IPnext(); // Increments over it
    if (--x >= 0) {
      this.RPpush(x);
      this.IP = destn; // Jump back
    }
  }
  // ASN, not eForth
  loop() { // R: I limit -- I+1 limit | ; loop if I < limit
    let i = this.RPpop();
    const destn = this.IPnext(); // Increment over loop
    if (++i < this.RPfetch()) {
      this.RPpush(i);
      this.IP = destn; // jump back
    } else {
      this.RPpop();
    }
  }
  I() { this.SPpush(this.RPfetch()); }

  // Jump if flag on stack is zero to destn in dictionary
  qBranch() {
    const destn = this.IPnext();
    if (!this.SPpop()) {
      this.IP = destn;
    }
  }

  // Unconditional jump to destn in dictionary
  branch() { this.IP = this.IPnext(); }
  leave() { this.RPpop(); this.RPpop(); this.branch(); }

  of() { // TODO-ARDUINO needs this
    const destn = this.IPnext();
    if (this.SPpop() !== this.SPfetch()) {
      this.IP = destn;
    } else {
      this.ramSP++; // DROP value
    }
  }

  // === Primitive words for memory, stack and return access.

  // Memory access eForthAndZen#39
  store() { this.Mstore(this.SPpop(), this.SPpop()); } //!  w a -- , Store
  fetch() { this.SPpush(this.Mfetch(this.SPpop())); } //@ a -- w, fetch
  cStore() { this.Mstore8(this.SPpop(), this.SPpop()); } //C! c a -- , Store character
  cFetch() { this.SPpush(this.Mfetch8(this.SPpop())); } //C@ a -- c, Fetch character

  // Return stack words eForthAndZen#40
  RPat() { this.SPpush(this.m.fromRamAddr(this.ramRP)); } //RP@
  RPbang() { this.ramRP = this.m.ramAddr(this.SPpop()); } // RP! must be aligned
  Rfrom() { this.SPpush(this.RPpop()); } // R>
  Rat() { this.SPpush(this.RPfetch()); } // R@
  toR() { this.RPpush(this.SPpop()); } // >R
  // 2>R 2R> 2R@ are odd - they swap the order so 2>R !=== >R >R
  TwoToR() { const x2 = this.SPpop(); this.RPpush(this.SPpop()); this.RPpush(x2); }
  TwoRfrom() { const x2 = this.RPpop(); this.SPpush(this.RPpop()); this.SPpush(x2); }
  TwoRat() { const x2 = this.RPpop(); this.SPpush(this.RPfetch()); this.SPpush(x2); this.RPpush(x2); }
  RDROP() { this.ramRP++; } // TODO-ARDUINO needs
  TwoRDROP() { this.ramRP += 2; } // TODO-ARDUINO needs

  // Data stack initialization eForthAndZen#41
  SPat() { this.SPpush(this.m.fromRamAddr(this.ramSP)); } //SP@
  SPbang() { this.ramSP = this.m.ramAddr(this.SPpop()); } //SP! must be aligned

  // Classic Data stack words eForthAndZen#42
  _roll(n) { // _roll(2) is like ROT TODO-ARDUINO needed
    let bottom = this.ramSP + n;
    const val = this.m.cellRamFetch(bottom);
    for (; n > 0; n--) {
      this.m.cellRamStore(bottom, this.m.cellRamFetch(bottom - 1));
      bottom--;
    }
    this.m.cellRamStore(bottom, val);
  }
  ROLL() { this._roll(this.SPpop()); } // TODO-ARDUINO needed
  DROP() { this.ramSP++; }
  DUP() { this.SPpush(this.SPfetch()); }
  SWAP() { this._roll(1); } // TODO-ARDUINO rewrote
  ROT() { this._roll(2); } // TODO-ARDUINO rewrote
  OVER() {
    const x = this.SPpop();
    const y = this.SPfetch();
    this.SPpush(x);
    this.SPpush(y);
  } // TODO optimize

  // Logical Words eForthAndZen43
  // noinspection JSBitwiseOperatorUsage
  less0() { this.SPpush((this.SPpop() & (1 << (this.CELLbits - 1))) ? l.TRUE : l.FALSE); } //0<  e.g. 0x8000 for CELLL=2
  AND() { this.SPpush(this.SPpop() & this.SPpop()); }
  OR() { this.SPpush(this.SPpop() | this.SPpop()); }
  XOR() { this.SPpush(this.SPpop() ^ this.SPpop()); }

  // Primitive Arithmetic Word eForthAndZen44
  UMplus() { // w w -- d )
    const a = this.SPpop();
    const b = this.SPpop();
    if (this.CELLL === 4) {
      // JS truncates to 32 bits before shift, so use it here rather than getting bitten below
      const x = (a >>> 0) + (b >>> 0);
      this.SPpush(x >>> 0);
      this.SPpush(x >= 0x100000000 ? 1 : 0);
    } else {
      // Note there is what I believe is a JS bug where x >> 32 is a noop so do th double shift
      const x = a + b;
      this.SPpushD(x); // Push double word
    }
  }

  // Math from Forth2012 - could probably define in Forth but efficiency important
  RSHIFT(u = this.SPpop(), x = this.SPpop()) {
    this.SPpush(x >> u);
  }
  LSHIFT(u = this.SPpop(), x = this.SPpop()) {
    this.SPpush(x << u);
  }
  TwoDiv(x = this.SPpop()) {
    this.SPpush((x & (1 << (this.CELLbits - 1))) | (x >> 1));
  }
  // === Define and initialize User variables Zen pg33 see Zen pg46
  // See Zen pg31 for tokenUser etc and $USER and Zen pg33 for USER initialization values

  // TODO-28-MULTITASK will need to think carefully about how to move all, or part of the USER space to task-specific space.
  // TODO-28-MULTITASK this is non-trivial since somethings are clearly across all tasks (e.g. CP and NP)
  userAreaInit() {
    const _USER = this.m.cellRomFetch(this.UZERO / this.CELLL); // 0th item in user space is its size
    for (let a = 0; a < _USER; a++) {
      //console.log(a, this.Ufetch(a), this.Mfetch(this.UZERO + a * this.CELLL));
      this.Ustore(a, this.m.cellRomFetch(this.UZERO / this.CELLL + a));
    }
  }
  // The opposite of userAreaInit - save values for restoration at COLD
  // Note it saves the value of LAST which is also in "FORTH", the "OVERT" in COLD restores that
  userAreaSave() {
    this.useRam(); // If were using ROM then switch
    const _USER = this.Ufetch(0);
    for (let a = 0; a < _USER; a++) {
      this.Mstore(this.UZERO + (this.CELLL * a), this.Ufetch(a));
    }
  }

  // === Forth words written in JS as needed for the interpreter

  PARSE() { // returns b (address) and u (length)
    const delimiter = this.SPpop(); // delimiter
    const tib = this.Ufetch(TIBoffset);
    const ntib = this.Ufetch(nTIBoffset);
    let inoffset = this.Ufetch(INoffset);
    if (delimiter === l.BL) {
      while ((inoffset < ntib) && (this.Mfetch8(tib + inoffset) <= l.BL)) {
        inoffset++;
      }  // If blank then skip over leading BL /control chars
    }
    // inoffset now points at first non-delimiter or #TIB
    const b = tib + inoffset; // Save start of string
    while ((inoffset < ntib) && ((delimiter === l.BL) ? (delimiter < this.Mfetch8(tib + inoffset)) : (delimiter !== this.Mfetch8(tib + inoffset)))) {
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
    const np = this.m.cellAlign(this.npFetch() - u - this.CELLL); // Enough space in Name Directory to copy string optionally with one zero after
    // Careful if edit next formula, m.align doesnt change if mem=8, AND in this case np may not be on a cell boundary
    this.Mstore(np + ((u / this.CELLL) >> 0) * this.CELLL, 0); // Write a zero in the last cell where the last letter of word will be written
    this.m.copyWithin(np + 1, b, b + u);
    this.Mstore8(np, u);  // 1 byte count
    this.SPpush(np); // Note that NP is not updated, the same buffer will be used for each word until hit ':'
  }

  NUMBERQ() { // Same footprint as NUMBER?,but less functionality (Decimal only)
    // TODO-backport simple number conversion from Arduino
    const a = this.SPpop();
    const w = this.countedToJS(a);
    const base = this.Ufetch(BASEoffset);
    const n = parseInt(w, base); // TODO-32-ERRORS handle parsing errors // Needs forth to convert word
    if (isNaN(n)) {
      this.SPpush(a);
      this.SPpush(l.FALSE);
    } else {
      this.SPpush(n);
      this.SPpush(l.TRUE);
    }
    /*
      // ALTERNATIVE without using parseInt and countedToJS (backported fromArduino TODO - port and test
      const a = this.SPpop();
      const aa = a;
      const radix = this.Ufetch(BASEoffset); //TODO handle base other than 10 BUT maybe not needed as switch to Forth version before ever use non-decimal
      let neg = false;
      let acc = 0;
      for (let i = this.Mfetch8(a++); i > 0; i--) {
        const c = this.Mfetch8(a++);
        if (c === '-') { // TODO not sure can compare byte to char
           neg = true;
        } else if ((c > '9') || (c < '0')) {
            this.SPpush(aa);
            this.SPpush(0);
            return;
        } else {
          c = c - '0';
          acc = (acc * radix) + acc;
        }
      }
      if (neg) { acc = -acc; }
      this.SPpush(acc);
      this.SPpush(l.TRUE);
    */
  }

  // If we are going to compile it, then check its not compiling into the dict, code we plan on replacing. (See same code on "'")
  checkNotCompilingReplaceable(xt, na) {
    if (jsFunctionAttributes[this.Mfetch(xt)].replaced) {
      const inDefOf = this.countedToJS(this.lastFetch());
      if (!['[COMPILE]', '(', 'create', 'CREATE', 'vCREATE'].includes(inDefOf)) { // Intentionally redefine ( so ok with redefinition
        console.log('Compiling', this.countedToJS(na), 'in', inDefOf, 'when code will be deleted');
        console.log('XXXX TODO-83');
        //console.assert(false); // Break here, shouldn't be happening.
      }
    }
  }

  _immediateQ(na) {
    const ch = this.Mfetch8(na);
    return ch & l.IMED;
  }
  immediateQ() {
    this.SPpush(this.Mfetch8(this.SPpop()) & l.IMED);
  }
  async dCOMPILE() { // a -- ...; same signature as to $COMPILE at Zen pg96
    this.findName(); // xt na | a F
    const na = this.SPpop();
    if (na) { // ca
      const xt = this.SPpop();
      if (this._immediateQ(na)) {
        await this.runXT(xt); // This will work as long as this $INTERPRET never called from Forth as cant nest 'run' even indirectly
      } else {
        this.checkNotCompilingReplaceable(xt, na);
        if (this.isTestFlags(0x02)) console.log('COMPILING:', this.countedToJS(na));
        this.DW(xt);
      }
    } else { // a
      this.NUMBERQ();
      if (this.SPpop()) {
        this.DW(this.js2xt.doLIT, this.SPpop());
      } else {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        console.log('Number conversion of', this.countedToJS(this.SPpop()), 'failed');
      }
    }
  }

  async dINTERPRET() { // a -- ...; Based on signature of $INTERPRET at Zen pg83
    this.findName(); // xt na | a F
    const na = this.SPpop();
    if (na) { // ca
      const xt = this.SPpop();
      await this.runXT(xt); //TODO-ASYNC maybe should be threadToken - but that won't work if this isn't running inside run already
    } else {
      this.NUMBERQ(); // n T | a F
      if (!this.SPpop()) {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        console.log('Number conversion of', this.countedToJS(this.SPpop()), 'failed');
      }
    }
  }

  async EVAL() { // Same signature as Forth EVAL, reads tokens from TIB and interprets )
    // EVAL and $COMPILE and $INTERPRET are redefined in FORTH below
    while (this.Ufetch(INoffset) < this.Ufetch(nTIBoffset)) {
      this.TOKEN(); // a ; pointing to word in Name Buffer (NB)
      // There may be case where this.TOKEN returns empty string at end of line or similar
      if (this.Mfetch8(this.SPfetch()) === 0) { // Skip zero length string
        this.SPpop();
      } else if (this.Ufetch(STATEoffset)) {
        // This is currently OK since its calling JS routines that may call Forth, there is no Forth-in-Forth
        await this.dCOMPILE();
      } else {
        await this.dINTERPRET();
      }
      // TODO-28-MULTITASK RP0 will move
      console.assert(this.ramSP <= this.ramSPP && (this.m.fromRamAddr(this.ramRP) <= this.Ufetch(RP0offset))); // Side effect of making SP and SPP available to debugger.
    }
    const prompt = this.Ufetch(PROMPToffset);
    if (prompt) {
      await this.runXT(prompt); //TODO-BACKPORT changed line
    }
  }

  // ==== FORTH Interpreter - words that have no Forth equivalent ====
  JStoTIB(s) {
    const TIBoff = this.Ufetch(TIBoffset);
    console.assert((TIBoff + s.length) < (this.Ufetch(RP0offset) - 10)); // Check for overlong lines
    this.Ustore(INoffset, 0); // Start at beginning of TIB
    this.Ustore(nTIBoffset,  this.m.encodeString(TIBoff, s)); // copy string to TIB, and store length in #TIB
  }

  // Take a multiline string, and pass line by line to EVAL
  async interpret(inp) {
    const inputs = inp.split('\n');
    // eslint-disable-next-line no-restricted-syntax,guard-for-in
    for (const i in inputs) {
      // noinspection JSUnfilteredForInLoop
      const inputline = inputs[i];
      if (this.isTestFlags(0x01)) {
        console.log(this.debugStack(), ' >>', inputline);
      }
      this.JStoTIB(inputline);
      await this.EVAL(); // TODO-34-FILES-STATE maybe should use EVALUATE
    }
  }
  interpret1(inp) { /* async by return a promise*/
    this.JStoTIB(inp);
    return this.runXT(this.JStoXT('quit1', true)); // async
  }
  // === A group of words required for the JS interpreter redefined later

  // : [  FALSE STATE ! ; IMMEDIATE
  openBracket() {
    this.Ustore(STATEoffset, l.FALSE); } // uses JS dINTERPRET

  // : ] TRUE STATE ! ;
  closeBracket() {
    this.Ustore(STATEoffset, l.TRUE); } // uses JS dINTERPRET

  // : : TOKEN $,n [ ' doLIST ] LITERAL ] ; see Zen pg96
  _colon(tok) {
    this.TOKEN();  // a; (counted string in named space)
    this.cpAlign(); // Before dollarCommaN so code field in Name dictionary correct
    this.dollarCommaN();
    this.DW(tok); // Must be after creating the name and links etc
  }
  colon() { this._colon(tokenDoList); this.closeBracket(); }
  DEFER() {  this._colon(tokenDefer); this.DW(0); this.OVERT(); } //TODO-ARDUINO needs this

  // : ; doLIT EXIT , OVERT [ ; IMMEDIATE
  semicolon() { // Zen pg95
    this.DW(this.js2xt.EXIT);
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

  useRam() {
    // Move CP and NP pointers to ram dictionary
    // LAST points to entry in ROM which first word in RAM should link to
    if (this.ROMCODEE) {
      this.romCodeTop = this.cpFetch(); // For XC
      this.romNameBottom = this.npFetch(); // For XC
      this.Ustore(NPoffset, this.RAMNAMEE);
      this.Ustore(CPoffset, this.Ufetch(VPoffset)); // Started at CODEE then moved up as vALLOT or v,
      this.Ustore(VPoffset, 0); // Once set to 0 routines will use CPoffset
    }
  }
  console() { /* async via returning a promise from runXT */
    return this.runXT(
      this.JStoXT('WARM'),
    ); // Async returns a promise
  }
  // ported to Arduino above L.2382-

  // TODO-29-DOES define DOES> for CREATE-DOES> and tokenDoes - this is not part of eForth, THEN defined Vocabulary as CREATE-DOES word
  //tokenDoes = Forth.tokenFunction(payload => { this.RPpush(this.IP); this.IP = (this.Mfetch8(payload++)<<8)+this.Mfetch8(payload++); this.SPpush(payload++); ); // Almost same as tokenDoList
}

/*
{  n: 'foo'    Name of forth word - do NOT specify a name if this also appears in
  f: bar      Links to Forth.prototype.bar (defaults to same as 'n'
  token: true Create a token word that can be used as first cell of a definition - order must match constants below
  replaced: true  This word will be replaced by a Forth definition, so check for its being compiled into other definitions.
  jsNeeds: true The execution address of this word is needed by the JS o will be stored in js2xt[n]
*/
const ForthNodeExtensions = [
  { f: function TXbangS(s) { process.stdout.write(s); } }, // Named function so will override in Forth instance
  { n: '!IO',
    f: function bangIO() {
      if (process.stdin.isTTY) {
        // process.stdout.write('RAW');
        process.stdin.setRawMode(true);
      }
      process.stdin.setEncoding('utf8');
      process.stdout.setEncoding('utf8');
    } },
  // Call chain is ?RX < '?KEY  < ?KEY < KEY < ACCEPT < REFILL < QUERY < que < QUIT
  { // Note - replacing qrx() not QRX() so there is no forth name for this
    f: function qrx() {
      // If there is no data in the buffer, check the stdin and reload the buffer.
      if (!(stdinBuffer && stdinBuffer.length)) {
        const s = process.stdin.read(); // Synchronous
        if (s) stdinBuffer = Buffer.from(s, 'utf8');
      }
      // If there is any data (old or new) in the buffer, return the first character and True
      if (stdinBuffer && stdinBuffer.length) {
        const c = stdinBuffer[0];
        stdinBuffer = stdinBuffer.slice(1);
        return [true, c];
      } else {
        // If there is nothing (old or new) return False
        return [false];
      }
    } },
];
export { Forth,
  ForthNodeExtensions, jsUsers, // Needed by example_node_api.js and test_dump.mjs (XC Cross compiler)
  Flash8_16, Flash8_24, Flash8_32, Flash16_16, Flash32_32, // Needed by console.js
  jsFunctionAttributes, RP0offset, // Needed by test_dump.mjs (XC Cross compiler)
};
