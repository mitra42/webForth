import { Forth_with_fs, ForthNodeExtensions } from '../forth_with_fs.js';
// Normally this would be: import Forth from 'webforth';

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32
const CELLL = 2; // 2 bytes for CELLL
const MEM = 16; // Use 16 bit memory
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x4000 * CELLL;
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x2000 * CELLL; // Make it larger will use
const extensions = ForthNodeExtensions; // Only current case is Node for running fs but that could change
const memClass = undefined; // Define to override default based on CELLL and MEM
const testFlags = 0;

const preTest = `
\\ TODO multi line comments, once put this in a file
\\ : ( 41 PARSE ." XXX(" 2DUP + C@ 41 = IF ... ; IMMEDIATE
\\ ( testing one line comment )
\\ ( testing multi line comment
\\   second line )



.( starting pretest)
: 2* 2 * ; \\ TODO-83 This should be optimized to a left shift and then find where used
\\ SEE https://github.com/NieDzejkob/2klinux/blob/2665d2491d82f0f8ced8d89163199a42bcd8c5f0/image-files/stage1.frt#L302
: POSTPONE 
  TOKEN ( a )
  COUNT FIND-NAME ( na | F)
  ?DUP 0= ABORT" Not found"
  DUP immediate? 0= IF 
    COMPILE COMPILE
  THEN ( na ) 
  NAME> ,
; IMMEDIATE

: [CHAR] ( "name" <spaces> -- ) CHAR POSTPONE LITERAL ; IMMEDIATE
.( finishing pretest)
\\ REQUIRE prelimtest.fth \\ TODO-83 figure out why cant include REQUIRE here


\\ lifted from https://github.com/NieDzejkob/2klinux/blob/2665d2491d82f0f8ced8d89163199a42bcd8c5f0/image-files/stage1.frt#L538-L649

\\ TODO-83 fix capitalization so non-standard are lower case
\\ We can now define DO, ?DO, LOOP, +LOOP and LEAVE. It would be much easier if LEAVE didn't exist,
\\  but oh well. Because storing LEAVE's data on the stack would interfere with other control flow
\\  inside the loop, let's store it in a variable. )

VARIABLE LEAVE-PTR

\\ ( Let's consider the base case: only one LEAVE in the loop. This can be trivially handled by
\\  storing the address we need to patch in the variable.

\\  This would also work quite well with nested loops. All we need to do is store the old value of
\\  the variable on the stack when opening a loop.

\\  Finally, we can extend this to an arbitrary number of LEAVEs by threading a singly-linked list
\\  through the branch target address holes. )

\\ ( The loop control variables are stored on the return stack, with the counter on top and the limit
\\   on the bottom.

\\   DO -> 2>R loop-inside

\\   ?DO -> (?DO) ?branch [do the LEAVE thing but with a conditional jump] loop-inside
\\ )

: (?DO)    ( limit counter R: retaddr -- R: limit counter retaddr )
  R>       ( limit counter retaddr )
  -ROT     ( retaddr limit counter )
  2DUP 2>R ( retaddr limit counter R: limit counter )
  <>       ( retaddr should-loop-at-all? )
  SWAP >R  ( should-loop-at-all? R: limit counter retaddr )
;

\\ ( This means that LOOP should look for LEAVE one cells before the actual loop body. That will make
\\   it handle ?DO correctly, and because the execution token of 2>R is not the same as the execution
\\   token of LEAVE, this will not break DO.

\\    LOOP ->  (LOOP) ?branch loop-beginning 2RDROP
\\   +LOOP -> (+LOOP) ?branch loop-beginning 2RDROP
\\                                           ^ LEAVE jumps here
\\ )

: (LOOP)   ( R: limit old-counter retaddr )
  R> 2R>   ( retaddr limit old-counter )
  1+       ( retaddr limit new-counter )
  2DUP 2>R ( retaddr limit new-counter R: limit new-counter )
  =        ( retaddr should-stop-looping? R: limit new-counter )
  SWAP >R  ( should-stop-looping? R: limit new-counter retaddr )
;

: (+LOOP)         ( diff R: limit old-counter retaddr )
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

: LEAVE,
  HERE
  LEAVE-PTR @ ,
  LEAVE-PTR !
;

: LEAVE COMPILE branch LEAVE, ; IMMEDIATE

: UNLOOP
  COMPILE 2RDROP
; IMMEDIATE

: DO
  LEAVE-PTR @
  0 LEAVE-PTR !
  COMPILE 2>R
  HERE
; IMMEDIATE

: ?DO
  LEAVE-PTR @
  0 LEAVE-PTR !
  COMPILE (?DO)
  COMPILE ?branch LEAVE, 
  HERE
; IMMEDIATE

: SOME-LOOP
  COMPILE ?branch ,
  LEAVE-PTR @
  BEGIN
    ?DUP
  WHILE
    DUP @ >R
    HERE SWAP !
    R>
  REPEAT
  POSTPONE UNLOOP
  LEAVE-PTR !
;

: LOOP
  COMPILE (LOOP)
  SOME-LOOP
; IMMEDIATE

: +LOOP
  COMPILE (+LOOP)
  SOME-LOOP
; IMMEDIATE

: I-MAX ( -- n ) RP@ 2 CELLS + @ ;
: J     ( -- n ) RP@ 3 CELLS + @ ;
: J-MAX ( -- n ) RP@ 4 CELLS + @ ;

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
: ['] ' POSTPONE LITERAL ; IMMEDIATE

`;

// DOUBLE word set https://forth-standard.org/standard/double
// implemented: D0< D0= DABS
// not implemented yet: 2CONSTANT 2LITERAL D+ D- D. D.R D2* D2/ D< D= D>S DMAX DMIN DNEGATE M * / M+



const forth = new Forth_with_fs({ CELLL, MEM, ROMSIZE, RAMSIZE, extensions, testFlags, memClass });
forth.initialize()
  .then(() => console.log("Forth with FS built"))
  .then(() => forth.interpret(preTest))
  // TODO-83 next line fails because it only switches SOURCE-ID, so it returns immediately.
  //.then(() => forth.interpret('REQUIRE prelimtest.fth'))
  .then(() => forth.console())
  // .then(() => console.log('EXITING AFTER TEST'));
