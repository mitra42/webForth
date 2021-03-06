# Memory Handling in WebForth

The memory map follows the concepts of the traditional & eForth model as defined on page 27 of eForth Zen,
Note that page 27 doesn't quite match the supplied code on page 26!
The code that defines this is well commented inline.
In Javascript, it is in a pair of UintXXarray structures. In C, it is a pair of arrays.

## Epromability
One challenge with eForth is that it puts data and code in the same space,
meaning that to Eprom a running system requires copying the Eprom to Ram,
and given that small chips have limited Ram that isn't smart.

webFORTH allows for separation between the two. The dictionary is built in an area to be flashed,
and then pointers are switched to a Ram area where further words can be built. The word `FORTH` and
anything built with vCREATE will use memory in the Ram area, as do anything built with `VARIABLE`.

* ROM contains: User Save; Code Dictionary; Name dictionary
* RAM contains (Stacks, TIB, PAD, User variables; data parts of CREATE DOES> words, and continuation of code and name dictionaries).

A word "useRam" does the correct manipulation of pointers
so that the Flashed dictionaries point to Ram for a continuation.

#### Memory Map to Javascript
The primary memory, is a large area of (at least conceptually) contiguous memory.
This area is conceptually split into a Rom portion, and a Ram portion.

There are two choices as to how that is used.
Whatever the choices, Forth addresses are always in Bytes.

First choice is `CELLL` (cell length) which specifies how the size of the basic unit of data Forth processes.
This is the size of each item on a stack, each field in the definition, each User variable etc.
This defaults to `2` bytes, i.e. 16 bits, but `3` byte (24 bit) and `4` byte (64 bit) implementations
are fully supported, and in particular `4` is used for the ESP8266 to allow access to more than 64k of memory.

Secondly is `MEM` which specifies the width of memory slots.
Addresses are translated on the fly from Forth's byte addresses, to the addresses in the MEM-width buffer,
and the top bit is tested to see if the address is in the Ram or Rom area.

If CELLL and MEM are different, then cells have to be packed into memory slots,
for example if CELLL=2 and MEM = 32 then two 16 bit cells fit in each memory slot.
Usually an alignment is done, so that if CELLL is 2 then it always starts on an even border,
but this depends on memory efficiency and (may) not be done if MEM=8.
The actual packing and unpacking are done by a class that, the defaults are in `index.js`
but alternatives can be passed to the Forth constructor for special needs.

For example Flash8_32 is an 8 bit wide memory array for holding 32 bit cells which uses a `Uint8array`.

There may be future experimentation to experiment with different ways of handling memory,
or managing a large virtual memory space on a smaller device.
This would be mediated by the memory class.
