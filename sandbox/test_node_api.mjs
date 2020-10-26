import Forth from '../index.js';
// Normally this would be: import Forth from 'webforth';

const CELLL = 2;
const MEM = 8;
const EM = 0x2000 * CELLL; // default is 0x2000 * CELLL
const foo = new Forth({CELLL, EM, memClass: `${MEM}_${CELLL*8}`});
foo.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => foo.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => foo.interpret("WARM"));
  .then(() => foo.console()) // Interactive console
  .then(() => console.log('\nconsole exited'));
