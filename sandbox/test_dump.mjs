import { ForthDumper, extensions } from '../xc.js';

/*
 * This is a first cut at a dictionary dumper aka cross-compiler for Arduino
 * Its written in Javascript - it could be written in Forth, but there is some significant string handling going on.
 *
 * To use this, see README.md and search for "Arduino support"
 */

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32 - Arduino is 2:16 and memClass = Romable16_16
const CELLL = 4; // Must use 2 for Arduino On ESP8266 better to use 4
const MEM = 32; // Must use 16 for Arduino On ESP8266 better to use 4
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x1000 * CELLL; // Set to 0x2000 should cover the standard dict plus a few extensions.
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x2800 * CELLL; // 200x2 is about the maximum Ram you can use currently on e.g. an Arduino Uno; ESP8266 seems to be ok (untested) at 0x2800 x 4
const memClass = undefined; // Flash16_16; // Can override default memory class for esoteric or experimental requirements

const forth = new ForthDumper({ CELLL, ROMSIZE, RAMSIZE, MEM, memClass, extensions });
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  .then(() => forth.xcDictionary({folder: '../arduino_webforth'})) // Interactive console
  .then(() => console.log('\n// arduino dump complete'));
