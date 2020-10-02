/*
 * WIP to build a Node API along the lines in https://github.com/mitra42/webForth/issues/23
 * See TODO-23-NODEAPI
 *
 * const Forth = require('webforth'); // The class or obj with functions
 * Forth.load('foo.f'); // Load it into the class
 * const forth = new Forth({ CELLL: 3, xxxMemSize: 1000000}) // Parameterized instance
 * forth.load('https://....'); // Load it into the instance
 * forth.interpret("1 2 DUP .S");
 * boo = forth.rot([1,2,3]);  // Returns [2,3,1] - will depend what can do with JS API
 * forth.console(); // Go interactive
 */


/*
 * References see FORTH.md
 */

/* Naming conventions and abbreviations
 * xt: execution token, points at the token field of a definition
 * na: Name Address, points to the name, (first byte count+flags, then that number of characters, max 31)
 * ca: Is ambiguous, sometimes it is used to refer to the xt, and sometimes to the Codefield Address, the field 2 cells below na that holds the xt
 * la: Linkfield Address, field holding the na of the previously defined word in this vocabulary
 * u: unsigned 16 bit
 * c: character
 * w: word - 16 bit signed
 * n: word - 16 bit signed
 *
 * For routines defined in Javascript there are typically
 * c.foo = func // If the functionary is to be discarded after bootstrap it will be in 'c' else just a function
 * this.jsFunctions[tok] = func // An array that maps the tokens used in the Forth space to the addresses of the function in JS address space
 * jsFunctionsAttributes[tok] = { name, replaced } // Some attributes to allow management of the functions
 * Name Dictionary:  na-2*CELLL: <xt><link><name> // In the name directory it looks like any other word
 * Code Dictionary:  xt: <tok> // In the code directory its a single cell with the token.
 */

/* Sections below in order
 * Support for Debugging - constants, variables, arrays, functions used by tools
 * Memory Map - constants that lay out the memory array
 * Javascript structures - implement the memory map and record the full state.
 * Other key constants - especially bitmasks
 * Standard Pointers used - esp IP, SP, RP, UP
 * Functions to simplify storing and retrieving 16 bit values into 8 bit stacks etc.
 * Access to the USER variables before they are defined
 * Functions related to building 'find' and its wrappers
 * JS Functions to be able to define words
 * Start the dictionary - includes defining Vocabulary token and 'FORTH'
 * Make some Javascript constants available in FORTH (these look like those defined with CONSTANT later)
 * Add functions defined earlier, now the dictionary is available
 * Code words to support debugging on the console
 * Basic low level key I/O and links to OS
 * INNER INTERPRETER YES THIS IS IT !
 * Literals and Branches - using next value in dictionary
 * Primitive words for memory, stack and return access, arithmetic and logic
 * Define and initialize User variable
 * Outer Interpreter: JS versions of NUMBER? $COMPILE $INTERPRET EVAL
 * A group of words required for the JS interpreter redefined later
*/
//eslint-env node

class Forth {


// === Vocabulary and Sort Order Zen pg47
// doVOC is not used; and 'FORTH' is moved earlier to be the first word defined


/*
static new(parms = {}) {
  const f = new Forth(parms);
}
TODO-load() {
  console.error('Forth.prototype.load not defined')
}
static TODO-load() {
  console.error('Forth.load not defined')
}

TODO-interpret() {
  console.error('Forth.prototype.interpret not defined')
}
// This needs to access the Javascript API so .rot works
TODO-rot() {
  console.error('Forth.prototype.rot not defined')
}
TODO-console() {
  console.error('Forth.prototype.console not defined')
}

 */

// TESTING ===
function startUp()  {
  //console.log('Javascript loaded:');
  this.openBracket(); // Start off interpreting
  const p = this.interpret(forthInForth)
    //.then(() => console.log('=====forthInForth compiled'))
    // Cleanup unneeded JS - this has to happen AFTER the ' WARM above
    .then(() => Forth.loaded=true)
    // Run warm boot into console
    .then(() => this.interpret("' WARM")).then(() => run(this.SPpop())).then(() => console.log('consoleInForth exited'))
    //.then(() => this.postBootstrapCleanup()) // Unclear if do this here or in caller.
    .catch(err => console.error(err));
  return p;
  //console.log('Main Finished but running promises:');
}
startUp(); // Async - this module will return before it completes
module.exports = exports = Forth;
//  .then(() => console.log("startUp done"));
