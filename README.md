# Forth in Javascript
## Why?
I hear you ask why, which is hardly surprising. 
* Forth was the first language I got good at
* Javascript is the language I like to play in now
* You can run it in any browser, and on a server, and on some embedded devices
* Its modular enough that I could replace the JS with C, C++, Wasm or Assembler.
* Much of the Forth I've seen has been really antiquated, or over-complex, needs a fresh approach

## Installation
The only prerequisite is [`node`](https://nodejs.org) and `npm` (or `yarn`). 

```
npm install webforth
```
Installs webforth, note there are intentionally no dependencies 
in the browser versions, and the only dependency in the node version is to
the builtin `fs`

If you only want to host the web version, then cloning the git repo should be sufficient.

## Running

```
const {Forth, ForthNodeExtensions} = require('webforth');
```
Or alternatively
```
import {Forth, ForthNodeExtensions} from 'webforth';
```
Then ...
```
const foo = new Forth({extensions: ForthNodeExtensions);
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

In particular, we will be adding ability to load forth files into an instance.

Note, it should be possible to run multiple instances, but this isn't tested fully yet.
e.g. 
```
import {Forth, ForthNodeExtensions} from webforth;
const foo1 = new Forth({extensions: ForthNodeExtensions});
const foo2 = new Forth({extensions: ForthNodeExtensions});
foo2.compileForthInForth().then(() => foo2.console());
foo1.compileForthInForth().then(() => foo1.interpret('1 2 .S'));
```
## Running in a browser

You should be able to run this at https://mitra.biz/forth/console.html

To make your own copy, clone the repo,

Start a simple http server such as that included in Node
```
cd webforth # Or wherever you cloned it
http-server &
```
Open `http://localhost:8080/console.html` in a browser. 

The HTML uses Web Components and TextEncoders, so they should work in any modern browsers such as:
Firefox, Chrome, Opera, Edge, Android, iOS. It runs in Safari on OSX but slowly.

The phone experience of console.html is suboptimal, 
I might get around to doing a mobile friendly version eventually, 
but if someone else does then I'll be happy to apply a PR.

It should compile Forth (you can verify in the web console) and present a console and entry box
in which you can type any Forth. 

Everything is happening locally i.e. this is forth running in your browser.

## Debugging

For the browser version open the Console. 
The process of building the dictionary puts errors and progress there. 

Feel free to open a new issue on [the git repo](https://github.com/mitra42/webforth/issues) 
but the first thing I'm going to ask for is a copy of whatever appeared in the Console,
or in Node.

There are two useful Forth words you can insert in either a definition, or the code to help debug.
* `testFlags` is a Forth variable allowing different levels of debugging. Its binary:
  * 0x01 trace the interpreter as it loads lines 
  * 0x02 trace threading (slows it down a lot!)
  * 0x04 enable any safety checks (currently there are not any)
  * 0x08 run incremental tests during bootstrapping - good for catching bugs.
* `testDepthOffset` can be set to change the number of levels deep that threading is traced
* `Fbreak`: Just calls a short routine that generates a console log, when working in my IDE 
    I set a breakpoint here. 
  
TODO - document how to run ANS tests from separate repo
  
## Arduino Support
See [docs/Cross Compiling.md](docs/Cross Compiling.md)

## File support
It supports the Forth2012 file extension words `REQUIRE` `INCLUDE` etc

Because browsers don't have access to `fs` it uses a separate class
that imports `fs`.
```
cd scripts
node /forth_console_with_fs_via_node.js
...
webFORTH V0.00.15
REQUIRE ../sandbox/tester.f
\ This will load the forth in tester.f and anything that file INCLUDEs
```
File support is in its early days and I want to extend it to be web-aware.

## Standard support

This is intended to be standards compliant, but then Forth has multiple standards!

Its status, and progress to passing the FORTH2012 test suite is visible in 
[issue#83](https://github.com/mitra42/webForth/issues/83), 
as of now (Aug 2023):
* it implements and passes: core, coreplus, coreext 
* The following are in theory fully implemented but fail at least one test:
  [files](https://github.com/mitra42/webForth/issues/97);
* The following extensions are partially implemented so fail on unimplemented words:
  [strings](https://github.com/mitra42/webForth/issues/94);
  [double](https://github.com/mitra42/webForth/issues/93);
* there has been no attempt to implement so the following Hayes tests fail:
  [block](https://github.com/mitra42/webForth/issues/80);
  Vocabularies so [searchordertest](https://github.com/mitra42/webForth/issues/95);
* Unclear on the status of:
  [locals](https://github.com/mitra42/webForth/issues/50);
  [memory allocation](https://github.com/mitra42/webForth/issues/96);
  [tools](https://github.com/mitra42/webForth/issues/95);
  [facilitytest](https://github.com/mitra42/webForth/issues/107)
* [exceptions](https://github.com/mitra42/webForth/issues/106)
  - fails one test (ABORT"), but the [standard for THROW](https://forth-standard.org/standard/exception/THROW) has problems.

In addition it does not implement (not tested by Hayes) the Forth2012 word: ENVIRONMENT?

## Contributing

Yes please ! 

Please introduce yourself on [issue#1](https://github.com/mitra42/webforth/issues/1)

Pull requests are welcome, and even quite significant changes at this stage, 
but let us discuss first (open a new issue in GIT). 

## Cutting a release 
* Run a code inspection - surprising how many bugs this ESLint, or most IDE's catch ! 
* Update `CHANGELOG.md`
* Check `README.md` reflects any changes
* Update `VER` in index.js and version in package.json to next even number
* `npm publish`
* push to git on `master` branch
* Update `VER` in index.js and version in package.json to next odd number
* npm update; npm install
* Check how to update on mitra.biz so Console runs new one ....
