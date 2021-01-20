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

const preTest = `
.( starting pretest)
: 2* 2 * ; \\ TODO-83 This should be optimized to a left shift and then find where used
.( finishing pretest)
\\ REQUIRE prelimtest.fth \\ TODO-83 figure out why cant include REQUIRE here
`;


const forth = new Forth_with_fs({ CELLL, MEM, ROMSIZE, RAMSIZE, extensions, memClass });
forth.initialize()
  .then(() => console.log("Forth with FS built"))
  .then(() => forth.interpret(preTest))
  .then(() => forth.interpret('WARM'))
  .then(() => console.log('EXITING AFTER TEST'));
