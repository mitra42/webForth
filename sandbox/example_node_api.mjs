import { Forth, ForthNodeExtensions, Flash8_16, Flash8_24, Flash8_32, Flash16_16, Flash32_32 } from '../index.js';
// Normally this would be: import Forth from 'webforth';

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32
const CELLL = 4; // 2 bytes for CELLL
const MEM = 32; // Use 16 bit memory
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x1000 * CELLL;
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x2800 * CELLL;
const extensions = ForthNodeExtensions;
let memClass = undefined;
//memClass = Flash8_24; // Uncomment this to simulate a chip with separate Rom and Ram (like an Arduino).

const forth = new Forth({ CELLL, ROMSIZE, RAMSIZE, MEM, extensions, memClass });
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => forth.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => forth.interpret("WARM"));
  .then(() => forth.console()) // Interactive console
  .then(() => console.log('\nconsole exited'));

