# Forth for Javascript - Design criteria
Mitra Ardron <mitra@mitra.biz> 4th March 2021

Welcome to my basic design document for WebForth.  

Currently, it is not in a particularly useful order, in part because I haven't found an easy way to 
provide a linear reading order without needing to look ahead.  

## Key Concepts

TODO update this contents table

* Based on eForth but extended to Forth2012
* [Memory Handling](docs/Memory%20Handling.md)

* Colon, Code and other words
* I/O
* Async
* Token threaded
* Integrating Javascript into Forth
* Orthogonality and likely changes
* CREATE DOES>
* Epromability
* Earlier version notes

#### Based on eForth but extended to Forth2012
This system is based on C.H. Ting's eForth, 
I primarily used the version of eForth in "Zen and Forth", 
but it has a not insignificant number of bugs,
some bugs are fixed in the `v5` version, 
and others in the version ported to `staapl`, 
so I've picked and chosen and flagged the errors with "ERRATA" in the code. 

The code is then extended so that it meets the Forth2012 Standard, 
or more specifically - since that standard has lots of ambiguity, 
to pass the "core" parts of the Hayes test suite. 
Mostly this is compatible with eForth except for: 

* Some USER variables are now unused, and removed
* `CHARS` emits characters in eForth and is a multiplier in Forth2012
* `<# # #S #>` operate on Doubles in Forth2012
* THROW always throws in eForth but only when non-zero argument in Forth2012

#### Memory Handling in WebForth
Please see [docs/strings.md](docs/strings.md)

#### Cross Compiling 
See [docs/Cross Compiling.md](docs/Cross Compiling.md) for details of support for different platforms
such as Arduino and ESP8266

=====REVIEWED DOWN TO HERE == 4th March 2021 ====

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
This code table is used for both defining words (colon, constant etc.) 
and for any word implemented in pure javascript (would be CODE words in most Forths).

#### Threaded Interpreter - detail

* The Program space stores as the first cell of a function:
* an index into an array of functions,
  for a (JS or C) function to execute to interpret the function.
* That function gets can access a pointer `PAYLOAD` to the next cell after the initial cell.
* And IP which points to the next cell after the pointer to this function. 

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
There are a bunch of bugs (including documentation bugs) in eForth, but it should be the same API.

There will definitely be divergences from ANS Forth, 
but while that is the only "standard" it does not seem to be in wide use. 
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
At this point it is identical to something defined with `VARIABLE`.

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
to date there is a Javascript, and a C (for Arduino) version.

### Strings
Please see [docs/strings.md](docs/strings.md)

## Write More about

### Orthogonality and likely changes
### Colon, Code and other words
### I/O
### Async
### Cross compiling
### Extensions
### Endian
### Anything else in https://github.com/mitra42/webForth/issues/25

TODO Redo content table at the top ! 
