import Forth from '../index.js';
// Normally this would be: import Forth from 'webforth';

const foo = new Forth();
foo.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => foo.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => foo.interpret("WARM"));
  .then(() => foo.console()) // Interactive console
  .then(() => console.log('console exited'));
