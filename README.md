# Forth in Javascript
## Why?
I hear you ask why, which is hardly surprising. 
* Forth was the first language I got good at
* Javascript is the language I like to play in now
* You can run it in any browser, and on a server, and on some embedded devices
* If its modular enough I should be able to replace the JS with C, C++, Wasm or Assembler.
* All the Forth I've seen has been really antiquated, or over-complex, needs a fresh approach

## Installation
```
npm install webforth
```
Installs webforth, note there are intentionally no dependencies in the minimal version.

## Running
You will need to be running Node v13 or later, 
OR in v12 `node --experimental-modules`
```
import Forth from webforth;
const foo = new Forth();
foo.compileForthInForth()
  .then(() => foo.interpret('1 2 3 ROT .S')) // Pass forth to interpret
  .then(() => foo.console()) // Interactive console
  .catch((err) => console.log('Error',err));
```
This ... 

* loads a bootstrap JS interpreter; 
* loads forth into it; 
* switches to the forth interpreter
* Starts a full forth console.

Try `1 2 3 ROT .S` A simple forth command and output the stack

This is an experimental API - it might change, 
- see any discussion in: [issue#23](https://github.com/mitra42/webForth/issues/23).

In particular we'll be adding ability to load forth files into an instance.

Note, it should be possible to run multiple instances, but this isn't tested fully yet.
e.g. 
```
import Forth from webforth;
const foo1 = new Forth();
const foo2 = new Forth();
foo2.compileForthInForth().then(() => foo2.console());
foo1.compileForthInForth().then(() => foo1.interpret('1 2 .S'));
```
## Contributing

Yes please ! 

Please introduce yourself on [issue#1](https://github.com/mitra42/webforth/issues/1)

Pull requests are welcome, and even quite significant changes at this stage, 
but lets discuss first (open a new issue in GIT). 
