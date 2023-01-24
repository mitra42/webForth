# String handling in webForth

## Overview

Forth handles strings as characters stored in sequential bytes of its normal memory space.
Typically, there is no heap, or automatically allocated memory as found in more abstract languages.

Historically strings were always stored with the first byte being a count,
immediately followed by the first character, 
and it was the address of the byte holding the count that was passed as an argument.
These are known as *counted-strings*

But the Forth2012 standard moved to preference an alternative where it is an address, and count, 
that are passed to a function. 

webForth takes a hybrid approach - strings are stored in the count+bytes format, but 
support for both the old `$"` and new `S"` argument styles are provided. 
There is very little overhead to this, as both sets of routines use common code. 

In webForth - as in any token threaded implementation of Forth - 
when a string is compiled the dictionary contains. 
- a prefix cell which contains the Execution token of a word that tells you what to do with the string.
- the string in consecutive bytes
- any padding to bring the bytes to a cell boundary.

## Words 

#### Support words
(please note, some markdown displays erroneously show a \ before the $)
* `$,"` - Compile a string, as a count and bytes and padding, into the code dictionary.
* `do$` - Return the address of a compiled string, skipping execution over it (this is a part of all prefixes)

#### Compiling words and prefixes

* `$"` or `C"` Compiles a string that returns address of count byte, uses `$"|` as the prefix.
* `S"` Compiles a string that returns address of first character and count, uses `S"|` as the prefix
* `."` Compiles a string that is printed, uses ."| as the prefix
* `ABORT"` compiles a string output if there is an error, uses `abort"` as the prefix

In addition `S"` is state-sensitive, when used in interpretive mode, it moves the 
string to `stringbuffer` and leaves the address on the stack. 
I *may* change ." and $" to behave the same way.

#### Escaped strings
`S\"` (one slash) works like `S"` but interprets `\` (one slash) as an escape. 
See [https://forth-standard.org/standard/core/Seq] for the escape sequences. 

#### Parsing
Strings are parsed using a series of words at varying levels of detail.

* `CMOVE` `CMOVE>` and `MOVE` (b1 b2 u --): Move a string, 
  the difference is order CMOVE from lowest, CMOVE> from highest and MOVE smartly
* `PACK$` ( b u a -- a) Move a string, along with its count to a counted-string at "a" using `CMOVE`
* `PARSE` ( delim -- a u) parses a delimited string from input
* `WORD` ( delim -- a) `PARSE`, from input buffer, up to a delimiter, moves it to the dictionary (using `PACK$`) and returns address.
* `PARSE-NAME` ( -- a u) `PARSE` a blank delimited string from input
* `TOKEN` ( -- a) uses `PARSE-NAME` to find a string and `PACK$` to move to dictionary
* `CHAR` ( -- c) uses `PARSE-NAME` to get a string, and return its first character
* `.(` ( --) uses `PARSE` to output a string delimited by `)`

## Internationalization

Forth historically did a pretty poor job of internationalization, 
and as a result there are assumptions about characters being single bytes, 
and lengths being synonymous with byte counts. 

webForth tries to tackle this, while remaining Forth2012 compliant. 
Specifically `TYPE` and words that use it `.(` `."` etc. use the underlying system's 
STRING output routine rather than iterating over a string, passes single characters to the OS.
This also has the advantage of being faster, but it means that implementations need to define
both character and string output routines `TXstoreC` and `TXstoreS`
