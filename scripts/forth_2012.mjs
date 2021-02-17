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

\\ TODO-35-VOCAB this will definitely need attention
: MARKER NP @ CP @ CONTEXT @ DUP @ SWAP CURRENT @ DUP @ SWAP CREATE , , , , , ,
  DOES> DUP @ CURRENT ! CELL+ DUP @ CURRENT @ !
   CELL+ DUP @ CONTEXT ! CELL+ DUP @ CONTEXT @ ! 
   CELL+ DUP @ CP ! CELL+ @ NP ! ;  

: BUFFER: CREATE vALLOT ; \\ TODO may need vBUFFER:

\\ VALUE - depends on 

`;

const forth = new Forth_with_fs({ CELLL, MEM, ROMSIZE, RAMSIZE, extensions, testFlags, memClass });
forth.initialize()
  .then(() => console.log('Forth with FS built'))
  .then(() => forth.interpret(preTest))
  // TODO-83 next line fails because it only switches SOURCE-ID, so it returns immediately.
  //.then(() => forth.interpret('REQUIRE prelimtest.fth'))
  .then(() => forth.console());
  // .then(() => console.log('EXITING AFTER TEST'));
