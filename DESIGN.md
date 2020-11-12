# Forth for Javascript - Design criteria
Mitra Ardron <mitra@mitra.biz> 17 Sept 2020

Welcome to my basic design document for WebForth.  

Currently its not in a particularly useful order, in part because I haven't found an easy way to 
provide a linear reading order without needing to look ahead.  
Also at the end are some remnants of an earlier design doc that need updating. 

## Key Concepts

TODO update this contents table

* Based on eForth but not quite same
* Javascript then Forth
* Memory Handling
* Colon, Code and other words
* I/O
* Async
* Token threaded
* Orthogonality and likely changes

#### Based on eForth but not quite same
This system is based on C.H. Ting's eForth, 
I primarily used the version of eForth in "Zen and Forth", 
but it has a not insignificant number of bugs,
some of the bugs are fixed in the `v5` version, 
and others in the version ported to `staapl`, 
so I've picked and chosen and flagged the errors with "ERRATA" in the code. 

I have tried, but failed to contact C.H.Ting (emails bounce) 
so I don't have a constructive way to feed those bugs back to him.

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
The code that defines these is well commented inline.

#### Memory map to Javascript
The primary memory, is a large area of (at least conceptually) contiguous memory.

There are two choices as to how that is used. 
Whatever the choices, Forth addresses are always in Bytes.

First choice is `CELLL` (cell length) which specifies how the size of the basic unit of data Forth processes.
This is the size of each item on a stack, each field in the definition, each User variable etc. 
This defaults to `2` bytes, i.e. 16 bits. 

Secondly is `MEM` which specifies the width of memory slots.
Addresses are translated on the fly from Forth's byte addresses, to the addresses in the MEM-width buffer.
If CELLL and MEM are different, then cells have to be packed into memory slots, 
for example if CELLL=2 and MEM = 32 then two 16 bit cells fit in each memory slot. 
Usually an alignment is done, so that if CELLL is 2 then it always starts on an even border,
but this depends on memory efficiency and is not done if MEM=8.
The actual packing and unpacking are done by a class that can be passed to the Forth constructor.

For example Mem16_32 is a 8 bit wide memory array for holding 32 bit cells which uses a `Uint16array`.

There may be future experimentation to experiment with different ways of handling memory,
for example handling read-only memory different from variable memory, 
or managing a large virtual memory space on a smaller device.
This would be mediated by the memory class.

See [issue-15](https://www.github.com/mitra42/issues/15) 
and [issue-11](https://www.github.com/mitra42/issues/11) 

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
The first word of each definition contains an index into a table of code. 
This code table is used for both defining words (colon, constant etc) 
and for any word implemented in pure javacript (would be CODE words in most Forths).

### Integrating Javascript into Forth 

Code words are defined as methods on the Forth class,
and then hooked to Forth names via the jsFunctionAttributes table at the top,
That table is read during dictionary building.

There is currently no way to extend Forth with more Javascript 
See [Issue#39](https://github.com/mitra42/webForth/issues/39)

### Orthogonality and likely changes

#### Sync/Async/Event Driven
TODO write up Async

#### Compatibility
This version is based on eForth which itself is based on bForth.
There are a bunch of bugs (including documentation bugs) in eForth but it should be the same API.

There will definitely be divergences from ANS Forth, 
but while that is the only "standard" it doesnt seem to be in wide use. 
See [issue#12](https://github.com/mitra42/webForth/issues/12)

I envision compatability vocabularies, so at the top of a file or extension one could 
put e.g. `ANS : foo xxx ; FORTH` and know that foo used the ANS dialect.

#### Module wish list
* Multi-task - like I did for Forth in 80s
* IO from URLs
* IO from disk
* Web server
* Interaction with DOM
* Event handling interaction with Forth


### CREATE DOES>
This is hairy to get your head around ... 

Assume a trivial definition which defines words that push their square on the stack:
`: square CREATE , DOES> @ DUP * ;`
Creates in the dictionary. 
```
Dictionary: 100: | tokenDoList | CREATE | , | EXIT 
Dictionary: 108: | @ | DUP | * | ; 
Namespace: square->100
```
Then its used as `2 square sq2`.

During the execution of `square`, `CREATE` sets up:
```
Dictionary: 116: | tokenvar | 0
Namespace: sq2->116
```
And then `,` compiles the data so ...
```
Dictionary: 116: | tokenvar | 0 | 2
```
At this point its identical to something defined with `VARIABLE`.

When the `DOES>` is called the function finds the most recent definition (using `LAST`), 
and edits it point at its own code.
```
Dictionary: 116: | tokenvar | 108 | 2
```
Then lets assume sq2 is executed.
```
Dictionary: 110 | icolon | sq2 | ; 
```
`tokenvar` sees `118` in `IP` and reads `108` which points at the `DOES>` code (`@ DUP *`)
It pushes the pointer to the data `120` onto the stack and acts like `tokenDoList` to run the code,
which leaves 4 on the stack.

## Earlier version - pretty much everything below here was for a version now deleted
Mitra Ardron <mitra@mitra.biz> 8 Aug 2020

This doc may or may not match the code, 
and is being randomly written as I come up with ideas,
(mostly) newer ideas at the bottom.

### Random ideas to incorporate

#### Portability
* Avoid JS specific stuff where possible 
* This probably means avoiding classes, but maybe not
* Try to avoid expensive constructs (even possibly dict)


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
