import Forth from '../index.js';
Forth.waitLoaded()
.then(()=>console.log("waitLoaded returned to test_import"));
/*
// Works as long as file is extension .mgs or package contains type: module
import r1 from '../index.js';
console.log('r1 is', r1); // r1 is Promise
r1.then((r2) => {
  console.log('r2 is', r2); //r2 is class Forth
})
*/
/* WORKS - but uses require
const foo = require('../index.js');

foo.then((res) => {
  console.log("Res is", res);
})
*/
