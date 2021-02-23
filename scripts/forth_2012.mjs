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
const testFlags = 0; // bit field: 1 trace interpreter 2 trace threading 4 safety checks 8 tests TODO-67-TESTING - see unreadFile above //TODO-2ARDUINO

const preTest = `
\\ TODO multi line comments, once put this in a file
\\ : ( 41 PARSE ." XXX(" 2DUP + C@ 41 = IF ... ; IMMEDIATE
\\ ( testing one line comment )
\\ ( testing multi line comment
\\   second line )


\\ Copied from forth2012 test suite tester.fs
VARIABLE testActualDepth        \\ STACK RECORD
CREATE testResults 20 CELLS ALLOT

: testReset   SP0 @ SP! ;  ( Re-initialize data stack )
: testError \\ ( C-ADDR U -- ) DISPLAY AN ERROR MESSAGE FOLLOWED BY THE LINE THAT HAD THE ERROR.
   CR TYPE SOURCE TYPE       \\ DISPLAY LINE CORRESPONDING TO ERROR
   testReset                  \\ THROW AWAY EVERY THING ELSE
   QUIT  \\ *** Uncomment this line to QUIT on an error
;

:NONAME \\ Different from tester, allows stack to be non-empty and treats as comment if testFlags!&8  : T{
  testFlags @ 8 AND IF [COMPILE] ?\\ THEN ;
' T{ DEFER!
:NONAME \\ ( ... -- ) Record depth and content of stack : ->
   DEPTH DUP testActualDepth ! \\ RECORD DEPTH since T{
   ?DUP IF 0 DO testResults I CELLS + ! LOOP THEN ;
' -> DEFER! 
:NONAME }T \\ ( ... -- ) COMPARE STACK (EXPECTED) CONTENTS WITH SAVED (ACTUAL) CONTENTS.
   DEPTH testActualDepth @ = IF      \\ IF DEPTHS MATCH
      DEPTH ?DUP IF         \\ IF THERE IS SOMETHING ON THE STACK
         0  DO            \\ FOR EACH STACK ITEM
           testResults I CELLS + @   \\ COMPARE ACTUAL WITH EXPECTED
           = 0= IF S" INCORRECT RESULT: " testError LEAVE THEN
         LOOP
      THEN
   ELSE               \\ DEPTH MISMATCH
      S" WRONG NUMBER OF RESULTS: " testError
   THEN ;
' ?T DEFER!
`;

const forth = new Forth_with_fs({ CELLL, MEM, ROMSIZE, RAMSIZE, extensions, testFlags, memClass });
forth.initialize()
  .then(() => console.log('Forth with FS built'))
  .then(() => forth.interpret(preTest))
  // TODO-83 next line fails because it only switches SOURCE-ID, so it returns immediately.
  //.then(() => forth.interpret('REQUIRE prelimtest.fth'))
  .then(() => forth.console());
  // .then(() => console.log('EXITING AFTER TEST'));
