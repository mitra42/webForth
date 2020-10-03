const Forth = require('../index.js');
// Normally this would be: import Forth from 'webforth';
const foo = new Forth();
foo.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  .then(() => foo.console()) // Interactive console
  .catch((err) => console.log('console error', err));

const foo1 = new Forth();
foo1.compileForthInForth()
  .then(() => console.log('===forthInForth 1 compiled'))
  .then(() => foo1.interpret("12345 .S"))
  .catch((err) => console.log('console error', err));

