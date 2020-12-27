# Forth for Javascript - Design criteria
Mitra Ardron <mitra@mitra.biz> 27 December 2020

Welcome to my basic design document for WebForth.  

Currently it is not in a particularly useful order, in part because I haven't found an easy way to 
provide a linear reading order without needing to look ahead.  

## Key Concepts

TODO update this contents table

* Based on eForth but not quite same
* Javascript then Forth
* Memory Handling
* Colon, Code and other words
* I/O
* Async
* Token threaded
* Integrating Javascript into Forth
* Orthogonality and likely changes
* CREATE DOES>
* Epromability
* Earlier version notes

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
The memory map almost follows the eForth model as defined on page 27 of eForth,
Note that page 27 doesn't quite match the supplied code on page 26!
The code that defines these is well commented inline.
In Javascript, its in a pair of UintXXarray structures. In C, its a pair of arrays.

## Epromability
One challenge with eForth is that it puts data and code in the same space,
meaning that to Eprom it requires copying the Eprom to Ram,
and given that small chips have limited Ram that isn't smart.

webFORTH allows for separation between the two. The dictionary is built in an area to be flashed,
and then pointers are switched to a Ram area where further words can be built. The word `FORTH` and
anything built with vCREATE will use memory in the Ram area, as do anything built with `VARIABLE`.

In ROM goes: User Save; Code Dictionary; Name dictionary
and in RAM (Stacks, TIB, PAD, User variables; data parts of CREATE DOES> words).

A word "useRam" does the correct manipluation of pointers 
so that the Flashed dictionaries point to Ram for a continuation. 

#### Memory map to Javascript
The primary memory, is a large area of (at least conceptually) contiguous memory.
This area is conceptually split into a Rom portion, and a Ram portion. 

There are two choices as to how that is used. 
Whatever the choices, Forth addresses are always in Bytes.

First choice is `CELLL` (cell length) which specifies how the size of the basic unit of data Forth processes.
This is the size of each item on a stack, each field in the definition, each User variable etc. 
This defaults to `2` bytes, i.e. 16 bits. 

Secondly is `MEM` which specifies the width of memory slots.
Addresses are translated on the fly from Forth's byte addresses, to the addresses in the MEM-width buffer, 
and the top bit is tested to see if the address is in the Ram or Rom area.

If CELLL and MEM are different, then cells have to be packed into memory slots, 
for example if CELLL=2 and MEM = 32 then two 16 bit cells fit in each memory slot. 
Usually an alignment is done, so that if CELLL is 2 then it always starts on an even border,
but this depends on memory efficiency and (may) not be done if MEM=8.
The actual packing and unpacking are done by a class that can be passed to the Forth constructor.

For example Flash8_32 is a 8 bit wide memory array for holding 32 bit cells which uses a `Uint8array`.
It splits memory into two areas as described above, so that one can be flashed on a device, 
and the other is fully initialized at start up.

There may be future experimentation to experiment with different ways of handling memory,
or managing a large virtual memory space on a smaller device.
This would be mediated by the memory class.

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
and for any word implemented in pure javascript (would be CODE words in most Forths).

#### Threaded Interpreter - detail

* The Program space stores as the first cell of a function:
* an index into an array of functions,
  for a (JS or C) function to execute to interpret the function.
* That function gets can access a pointer `PAYLOAD` to the next cell after the initial cell.
* And IP which points to the next cell after the

```
Caller: 100: | tokenDoList | foo (108) | bar | EXIT 
Foo: 108: | tokenXxx | data ; 
tokenXxx gets PAYLOAD=110, IP=104
```

So tokenDoList is essentially `RPpush(IP); IP=PAYLOAD`


### Integrating Javascript into Forth 

Code words are defined as methods on the Forth class,
and then hooked to Forth names via the jsFunctionAttributes table at the top,
That table is read during dictionary building.

To extend with more JS, a similar table of functions can be passed in as an extension, 
or a caller can subclass "Forth"

### Integrating C into Forth
For the C version for Arduino and ESP8266 the code words are defined as functions, 
accessed via the JSfunctions table. 

The dictionaries are then built by defining addresses (XT_abcd) and using them to initialize
a table in ROM. 

#### Sync/Async/Event Driven
TODO write up Async

#### Compatibility
This version is based on eForth which itself is based on bForth.
There are a bunch of bugs (including documentation bugs) in eForth but it should be the same API.

There will definitely be divergences from ANS Forth, 
but while that is the only "standard" it doesnt seem to be in wide use. 
See [issue#12](https://github.com/mitra42/webForth/issues/12)

I envision compatibility vocabularies, so at the top of a file or extension one could 
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

### Portability
The intention is to make this available for different situations, 
to date there is a Javascript and a C (for Arduino) version.

## Write More about

### Orthogonality and likely changes
### Colon, Code and other words
### I/O
### Async
### Cross compiling
### Extensions
### Endian
### Anything else in https://github.com/mitra42/webForth/issues/25
