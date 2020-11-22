import { Forth, ForthNodeExtensions} from '../index.js';
// Normally this would be: import Forth from 'webforth';

const CELLL = 2;
const MEM = 8;
const ROMSIZE = 0x2000 * CELLL;
const RAMSIZE = 0x400 * CELLL;
const extensions = ForthNodeExtensions;



const foo = new Forth({CELLL, ROMSIZE, RAMSIZE, MEM, extensions});
foo.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => foo.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => foo.interpret("WARM"));
  .then(() => foo.console()) // Interactive console
  .then(() => console.log('\nconsole exited'));
