# Cross Compiling in WebForth

WebForth was designed from the outset for cross-compiling. 

The core idea is that code is defined and tested in the javascript / browser version, 
but can then cross compile to C files (or similar) that can be built, and debugged,
in the devices native tools. 

#### No Boot loaders harmed in this process
Importantly, it was a design goal NOT to clobber the device's bootloader as some other forths do. 

#### Current support
This is currently done for the Arduino and for the ESP8266. 
These are very similar platforms, so no claim is made about generality.
In particular there is plenty more work to be done to really support these (or other) platforms well.

#### IDE and console
The examples included in this repo will compile and load in the standard Arduino IDE (and presumably others)
and once sent to the device will provide an OK prompt in the serial console on the IDE.

That OK prompt includes defining words, i.e. the full dictionary headers are present, 
though at this point any words defined interactively will not be saved to flash.

#### Memory usage - Flash over RAM
Another important design choice is that the dictionaries are not only loaded into flash, 
but they run in flash, i.e. the dictionary does not use precious RAM at run time.
Variables are carefully seperated from dictionaries. 

#### Building
To rebuild the repo, in either arduino or esp8266 folders run
```
node ./build_xc.js
```
This will build
* webforth_functions.h - which defines constants such as cell size
* webforth_dictionary.cpp - a set of defines to build the dictionary.

#### Porting to a new platform
These instructions may take some tweaking as more is learnt about different platforms.

Create a new directory, naming the platform. 

Create any platform specific files the IDE needs, 
for example on Arduino its a .ino file specifying serial speed etc. 
On Arduino, this also kicks off the interpreter by setting an initial `IP` 
and looping `threadtoken(IPnext())`

Copy `build_xc.js` from the most similar machine - 
if in doubt, esp8266_webforth is probably good. 
Edit the line close to the bottom that defines the following:
* CELLL cell length in bytes 2 is standard forth, 
  but some are 4 bytes (32 bits). 
  3 (24 bits) should work on most platforms but is not guaranteed!
* MEM is the size in bits of a single memory slots. 
  Typically, this will be 8*CELLL for efficiency. 
  (e.g. Arduino is CELLL=2 MEM=16, and ESP8266 is CELLL=4 MEM=32).
  Other combinations should work, but no promises! 
* ROMCELLS and RAMCELLS define the size of the memory the forth will use, 
  the C has to use memory outside this for its stacks etc.
* extensions shouldn't need changing - 
  note these are like writing extra code words. 
  The defaults are I/O hookups.
  Note these apply to the the cross-compilation, not for the target.
  see [forth_with_fs.js](../forth_with_fs.js) for an example of usage
  to implement ability to read from file system.

Copy and edit `webforth_functions.cpp` this may require no changes, 
(Arduino and ESP8266 are currently the same)

Look at [xc.js](../xc.js), there are a couple of places where "processor" specific 
changes are made, for example on the ESP8266 it is neccesary to specify "PROGMEM" to define an 
array in Program Memory (aka flash).

If you succeed in porting to a new platform please submit a PR to GitHub so it can be shared by others.

#### Future work includes:
* The extension mechanism. [issue#72](https://github.com/mitra42/webForth/issues/72);
* a way to output via the Web UI [issue#61](https://github.com/mitra42/webForth/issues/61);
* Support for pins and interrupts [issue#63](https://github.com/mitra42/webForth/issues/63)
* Support for the Wi-Fi & TCP/IP [issue#73](https://github.com/mitra42/webForth/issues/73)


