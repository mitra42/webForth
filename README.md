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
Or alternatively if running node v13, or `node --experimental-modules`
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
Firefox, Chrome, Opera, Edge, Android. 
It will not work in IE or Safari on IOS or OSX, and there are no plans to support those browsers, 
however I'll be happy to add PRs if someone else does.

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
  * 0x04 enable any safety checks (currently there arent any)
  * 0x08 run incremental tests during bootstrapping - good for catching bugs.
* `testDepthOffset` can be set to change the number of levels deep that threading is traced
* `Fbreak`: Just calls a short routine that generates a console log, when working in my IDE 
    I set a breakpoint here. 
  
TODO - document how to run ANS tests from separate repo
  
## Arduino Support

Support for Arduino is still early stage, 
but it runs to flash using the standard Arduino process, i.e. in the standar Arduino IDE
Note - this does NOT clobber your bootloader unlike some Forths.
There is an OK prompt with full forth support including defining words, 
though any words you define interactively will not be saved to flash.

To rebuild the repo, in either arduino or esp8266 folders run
```
node --experimental-modules ./build_xc.mjs
```
* I am working on the extension mechanism. [issue#72](https://github.com/mitra42/webForth/issues/72);
* a way to output via the Web UI [issue#61](https://github.com/mitra42/webForth/issues/61);
* Support for pins and interrupts [issue#63](https://github.com/mitra42/webForth/issues/63)
* Support for the Wi-Fi & TCP/IP [issue#73](https://github.com/mitra42/webForth/issues/73)

## File support
It supports the Forth2012 file extension words `REQUIRE` `INCLUDE` etc

Because browsers don't have access to `fs` it uses a separate class
that imports `fs`.
```
cd scripts
./forth_console_with_fs_via_node.mjs
...
webFORTH V0.00.15
REQUIRE ../sandbox/tester.f
\ This will load the forth in tester.f and anything that file INCLUDEs
```
File support is in its early days but as I want to extend it to be web-aware.

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
