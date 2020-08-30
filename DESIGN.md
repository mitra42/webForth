# Forth for Javascript - Design criteria
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
