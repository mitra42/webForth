# Forth for Javascript - Design criteria
Mitra Ardron <mitra@mitra.biz> 17 Sept 2020

## Key Concepts

* Based on eForth but not quite same
* Javascript then Forth
* Memory Handling
* Colon, Code and other words
* I/O
* Async
* Token threaded
* Orthogonality and likely changes

#### Based on eForth but not quite same
This system is based on eForth, 
I primarily used the version of eForth in "Zen and Forth", but this has a lot of bugs,
some of the bugs are fixed in the `v5` version, 
and others in the version ported to `staapl`, 
so I've picked and chosen and flagged the errors with "ERRATA" in the code. 

#### Javascript then Forth
There are several ways to bootstrap Forth. 
A common way on bigger systems is Forth written in Forth and cross-compiled to an image.
However this requires a Forth system to build it on. 
eForth relies on a Macro-Assembler, but the code is only available in text form, 
which you have to assemble by hand - and then figure out the numerous bugs.

As an alternative this system bootstraps in Javascript, 
* first some javascript functions are written - equivalent of the core code functions in eForth
* then some JS functions that enable a simple interpreter, especially `find` which is a key efficiency enabler anyway.
* that interpreter can compile a FORTH dictionary to bring up the rest of the language, 
* at some point in the compilation process the interpreter switches so it is itself running in FORTH.  

### Memory Handling
The memory map follows the eForth model as defined on page 27 of eForth,
Note this doesn't quite match the supplied code on page 26! 
The code that defines these is well commented

#### Memory map to Javascript
The primary memory, is a large byte buffer. 
This may change and alternatives get tried such as Uint8Array or Uint16Array. 
In future different parts of memory could be split, especially for multi-tasking, 
but eForth doesn't lend itself easily to that. 
See issue-15 and issue-11.

### Colon, Code and other words
### I/O
### Async

### Token Threaded
The key to Forth is a threaded interpreter. 
Each word consists of a list of pointers to other words.
The inner interpreter iterates over those lists. 

There are three common ways to implement the interpreters. 

1. Direct threaded, where you call the word directly - eForth does this. 
2. Indirect threaded, the first word of the definition has a pointer to code. 
3. Token threaded, the first word contains a token. 

We are using Token threading 
because we can't easily mix javascript code into the byte-array of Forth.
The first word contains an index into a table of code. 
This code table is used for both defining words (colon, constant etc) 
and for any word implemented in pure javacript. 

Code words are defined in javascript with `c.code(<name>, () => {javascript});`


Which iterates through lists of pointers to other wo
### Orthogonality and likely changes

* Sync/Async/Event Driven
* Cell size
* Memory handling

#### Compatibility
This version is based on eForth which itself is based on bForth.
There are a bunch of bugs (including documentation bugs) in eForth but it should be the same API.

There will definitely be divergences from ANS Forth, 
but while that is the only "standard" it doesnt seem to be in wide use. 
See [issue#12](https://github.com/mitra42/webForth/issues/12)

I envision compatability vocabularies, so at the top of a file or extension one could 
put e.g. `ANS : foo xxx ; FORTH` and know that foo used the ANS dialect.


## Earlier version - pretty much everything below here was for a version now deleted
Mitra Ardron <mitra@mitra.biz> 8 Aug 2020

This doc may or may not match the code, 
and is being randomly written as I come up with ideas,
(mostly) newer ideas at the bottom.

### Random ideas to incorporate

#### Imagine a set of modules
* Kernel - written in JS, includes:
  * Stack management
  * Threaded interpreter
  * Program space management - primitives the interpreter uses
  * Primitives - bridge between Forth and Javascript, kept simple
  * What else
* Interpreter - parses text and passes to Kernel:programmer
* Core Functions - written in Forth but with knowledge of some primitives
* Forth language - written in Forth 

#### Portability
* Avoid JS specific stuff where possible 
* This probably means avoiding classes, but maybe not
* Try to avoid expensive constructs (even possibly dict)

#### Compatibility
Seriously.... I haven't gone back and looked at Forth, and last time was 35 years ago, 
so a lot of this may change once I review it, but I wanted a fresh unbiased look first.

Known Divergences (currently) include:
* Stacks store Javascript variables - not bytes

Forth has two kinds of strings c-addr & len, and counted strings, where the pointer is to the length. 
The latter are deprecated, but WORD and FIND still use them.  
Since neither make much sense in Javascript I defined a third kind which uses Javascript strings
and is the equivalent. So this includes `s"`, `word` and `find`, instead of `S"`, `WORD` and `FIND`

#### Module wish list
* Multi-task - like I did for Forth in 80s
* IO from URLs
* IO from disk
* Web server

### Threaded Interpreter - v1

* The Program space stores as the first value of a function: 
* a pointer to the Javascript function to execute to interpret the function.
* That function gets past (index in program space of first value, context).
* Where the context is { program, stack, variables .... }

The context should always be read only, if it needs changing copy it and edit the values. 

Forth needs at least the following ...
* Code is just a pointer to a javascript function. TODO how does it return?
* Colon is a pointer to the Colon function which iterates over the functions 
  it is ended by a semicolon
* Variable the data holds an index into the variable space
* Constant the data is the value to push on the stack
* Builds-Does the data is the pointer to the Colon function to execute for the "Does" part

-|PC|Z|Prog Stack|Reg stack
----|----|---|---|----
Before call|A| |0|
After call|A+1|B+1|0|
After Colon|B+1| |A+1,0|
After Semicolon|A+1| |0| |
After Const|A+1| | |@B+1
After Lit|A+2| | |@A+1
After Var|A+1| | |variables[@B+1]
After run call|0|B+1| |

## Documentation

* Word definitions https://www.taygeta.com/forth/dpans6.htm 

## Implementation decisions and details

### Implementation dependent choices for data saved

define|as|created|consumed
----|----|---|---
colon-sys|definitionStart name|: initiateDoes|; DOES>
next-sys|programCounter|initiateColon|runSemicolon DOES>
do-sys|dicPointer (to initiate field)|DO|LOOP
loop-sys|limit i|doDO|doLOOP I J

### CREATE DOES>
This is hairy to get your head around ... 

Assume:
`: square CREATE , DOES> @ DUP ;`
Creates in the dictionary. 
```
Dictionary: 100 | icolon | CREATE | , | DOES> 
Dictionary: 104 | @ | DUP | ; 
Namespace: square->100
```
Then its used as `2 square sq2`.

During the executation of `square`, `CREATE` sets up:
```
Dictionary: 107 | icreate | 900
Namespace: sq2->107
Data: 900: 2
```
When the `DOES>` is called the function sees `C: colon-sys(104)` and uses that 
to edit the definition to:
```
Dictionary: 107 | idoes | 900 | 104
```
It also sees R: nest-sys(code-ptr) and returns control
Then lets assume sq2 is used `: foo sq2 ;` which creates:
```
Dictionary: 110 | icolon | sq2 | ; 
```
`idoes(c,p)` sees `p=108` `PC=112`, it pushes the value at `108`, `900` to the stack.
Pushes `112` to the Return stack (colon-sys) and sets PC=`104`.

At this point `@ DUP` fetches the data from `900` and DUPs it. 

### Possible architecture

#### Bottom layer - compatability
Seperate files for e.g. in JS, WASM, PIC-C, ESP ASM etc
Minimal 30-ish words potentially using eForth, or inspired by it.

#### Optimisation layer
Not sure how to fit this in yet, but it would be words optimized from Forth
to underlying platform

#### Forth in Forth 
The rest of Forth in Forth 

#### Compatability layer 
Dictionaries for F83, ANSI etc 

#### Optional Extensions layer
Ideally builds on ForthInForth layer, but could build on specific dialects
e.g. Blocks, Serial, Web Server, Web fetcher, Files, etc

#### Integration layer
Integrate code from other places, especially for example a JS compatability layer to call code from node. 

### Possible Projects
This list will end up on GIT at some point

* Module handling 
* http(s) fetching (including for modules)
* DOM integration
