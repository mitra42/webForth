import Forth from '../index.js';

Forth.waitLoaded()
  .then(() => {
    console.log('Forth loaded and running');
    const f = new Forth();
    f.console();
  })
  .catch(err => console.log('Error', err));
/* Alternative, works - but uses require
  const foo = require('../index.js'); foo.then((res) => { console.log("Res is", res); })
*/
