import { ForthXC, extensions } from '../xc.js';

/*
 * This script builds a javascript version of forth, then cross compiles to two files in this (or some specified) directory.
 * Its written in Javascript - it could be written in Forth, but there is some significant string handling going on.
 *
 * To use this, see README.md and search for "Arduino support"
 */

// CELLL - size of one Forth cell. Should use 2 for Arduino, or 4 for ESP8266 for efficiency.
// MEM - size of a slot in memory. Should be CELLL * 8 bits for efficiency and may not work if mismatched.
// For Javascript, valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32 Arduino is 2:16 ESP8266 is 4:32

/*
  Specify size of areas for ROM and RAM;
  ROMSIZE:  Used for UserVariable save area; and Dictionary (code and names) until useRam() is called
            Typically 0x1000 * CELL covers the dictionary with some spare.
  RAMSIZE:  Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
            Size depends on the processor, 0x200 * 2 is about the max on Arduino Uno, ESP8266 works ok at 0x2800 * 4
            Too high and the C functionality might run out of memory for stacks etc.
  memClass  Normally undefined, but can override default memory class for esoteric or experimental requirements
  extensions  Pass through those imported above, or add to them.
 */

async function build({
  processor, CELLL, extensions = {}, MEM = undefined,
  ROMCELLS = undefined, ROMSIZE = undefined,
  RAMCELLS = undefined, RAMSIZE = undefined,
}) {
  const forth = new ForthXC({
    CELLL, MEM: MEM | (8 * CELLL), extensions,
    ROMSIZE: ROMSIZE | ((ROMCELLS | 0x1000) * CELLL), RAMSIZE: RAMSIZE | (RAMCELLS * CELLL),
  });
  await forth.compileForthInForth();
  console.log(`=== forthInForth for ${processor} compiled`);
  await forth.xcDictionary({ processor, folder: './' }); // Dump to files in folder
  console.log(`\n// ${processor} dump complete`);
}

build({
  processor: 'arduino', CELLL: 2, ROMCELLS: 0x1000, RAMCELLS: 0x200, extensions,
});
