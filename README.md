# Forth in Javascript
## Why?
I hear you ask why, which is hardly surprising. 
* Forth was the first language I got good at
* Javascript is the language I like to play in now
* You can run it in any browser, and on a server, and on some embedded devices
* If its modular enough I should be able to replace the JS with C, C++, Wasm or Assembler.
* All the Forth I've seen has been really antiquated, or over-complex, needs a fresh approach

## Installation
The only prerequisite is [`node`](https://nodejs.org) and `npm` (or `yarn`). 

```
npm install webforth
```
Installs webforth, note there are intentionally no dependencies 
in the minimal node or browser versions.

If you only want to host the web version, then cloning the git repo should be sufficient.

## Running

```
const {Forth, ForthNodeOverrides} = require('webforth');
```
Or alternatively if running node v13, or `node --experimental-modules`
```
import {Forth, ForthNodeOverrides} from 'webforth';
```
Then ...
```
const foo = new Forth({overrides: ForthNodeOverrides);
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
import {Forth, ForthNodeOverrides} from webforth;
const foo1 = new Forth({overrides: ForthNodeOverrides});
const foo2 = new Forth({overrides: ForthNodeOverrides});
foo2.compileForthInForth().then(() => foo2.console());
foo1.compileForthInForth().then(() => foo1.interpret('1 2 .S'));
```
## Running in a browser
Start a simple http server such as that included in Node
```
cd webforth
http-server &
```
Open `http://localhost:8080` in a browser. 

The HTML uses Web Components and TextEncoders so they should work in any modern browsers 
(Firefox, Chrome, Opera, Edge, Android, but not IE or Safari on IOS or OSX). 
There are no plans to support those browsers, 
however I'll be happy to add PRs if someone else does.

It should compile Forth (you can verify in the console) and present a console and entry box
in which you can type any Forth. 

Everything is happening locally i.e. this is forth running in your browser.

## Debugging

For the browser version open the Console. 
The process of building the dictionary puts errors and progress there. 

Feel free to open a new issue on [the git repo](https://github.com/mitra42/webforth/issues) 
but the first thing I'm going to ask for is a copy of whatever appeared in the Console,
or in Node.

There are two useful Forth words you can insert in either a definition or the code to help debug.
* `testing3`: sets an internal flag to increase (significantly) debugging output so we 
    see stack condition before every forth word. 
    Changing debugDepth can be useful to get more or less of it. (look for the variable)
* `break`: Just calls a short routine that generates a console log, when working in my IDE 
    I set a breakpoint here. 

## Contributing

Yes please ! 

Please introduce yourself on [issue#1](https://github.com/mitra42/webforth/issues/1)

Pull requests are welcome, and even quite significant changes at this stage, 
but lets discuss first (open a new issue in GIT). 
