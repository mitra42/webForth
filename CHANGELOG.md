* 2021-03-06: v0.1.0
  * Major changes to support Forth2012 standard - see [Issue#83](https://github.com/mitra42/webForth/issues/83)
    * Passes core, coreext, coreplus except for ENVIRONMENT?
  * Fix bitrot (RAMSIZE, ROMSIZE) in console.js 
  * Use String output for TYPE instead of CHAR (issue#52)
  * Add: DO ?DO I I-MAX J J-MAX LEAVE UNLOOP LOOP +LOOP
  * Add: RDROP >RESOLVES IMMEDIATE? ALIGN >BODY CHAR+ C, ['] BIN
  * Add: MOVE CMOVE> 2* POSTPONE MARKER BUFFER ROLL UNUSED TUCK SAVE-INPUT RESTORE-INPUT
  * More math: 0<> FM/MOD SM/REM 2/ <> > U> 0<>
  * Add: SOURCE SOURCE-ID and a stack to manage them
  * NUMBER? now uses >NUMBER and handles $ # % and 'x'
  * Support :NONAME DEFER DEFER! DEFER@ IS ACTION-OF and refactor JS routines to use it 
  * Replace some vectored User variables with DEFERs
  * Support VALUE and TO
  * Add CASE OF ENDOF ENDCASE
  * Refactor strings to support Forth2012 S" C" /STRING and eForth $"
  * Add T{ -> }T and replace tests with it
  * CHARS is now Forth2012 (pointer increment) rather than eForth (output)
  * <# # #S #> HOLDS now work on double numbers (Forth2012) not single (eForth)
  * Replace testing3 with testFlags
  * Add Double handling: D0= 2OVER 2SWAP S>D 2RDROP D0< DABS
  * Refactor FIND to FIND-NAME and FIND-NAME-IN, NAME?  (Forth2012)
  * Better error handling in Javascript (not perfect yet)
  * Most console.log should be funnelled through logAndTrace for breakpointing
  * Rename some words to align with Forth2012 conventions for non-alpha characters
  * Test 8,24,32 bit versions on different size arrays and test Console
  * Port new material to Arduino, ESP8266 and test

* 2021-01-19: v0.0.16
  * Added support for files (REQUIRE, INCLUDE etc)
  * ANS: Replace 'EVAL with STATE
  * Backport PAYLOAD from Arduino and optimize to use it
  * Moved debugging flags (this.testing) to testFlags and testDepth user variables
* 2020-12-25: v0.0.14
  * ESP8266 sketch
  * Reorganize folders for sketches etc and build process
  * Build FlashXX_XX classes 8_16, 8_32, 16_16. 32_32 - flips Rom to high addresses
  * Complete comparison of eForth Zen, v5 and Staapl variants
  * Fix tests commented out
  * Refactor extensions - mechanism; support constants; 
  * Bugs in EXECUTE; 
  * Add words: SPpushD SPpopD SPpopString FlashXX_XX.buff8 ud< S"| S" crlf?
  * File support (experimental) CREATE|WRITE|READ|OPEN|DELETE|RENAME-FILE FILE-SIZE FLUSH-FILE READ|WRITE-LINE
  * Error string handling
* 2020-11-28: v0.0.12
  * Flash-able memory storage class (backports concept from Arduino to JS)
* 2020-11-23: v0.0.11
  * Rework extension mechanism to be similar to `jsFunctionAttributes`
  * Remove obsolete sandbox command files
  * Change base of tokens from 0 to 1, so that indirecting through 0 fails.
  * Add this.CELLMASK (endian compliant)
  * Fix some bugs with division by CELLL leaving floating point numbers
  * Find etc
    * Optimize _sameq to use cells rather than bytes
    * Separate out xt2na from _find
    * Handle some bugs with not padding strings we are searching for
  * Support port to Arduino
    * Change names of a few functions (`find` `jsFind`; `$INTERPRET` `dINTERPRET`; `$COMPILE` `dCOMPILE`; 
      `break` `Fbreak`; `=COMP` `COMP`; `=IMED` `IMED`; `=BYTEMASK` `BYTEMASK`; `run` `runXT`)
    * Add an arduino sketch and support for functions it needs
    * Move some `const` (`UPP` `RP0` `NAMEE` `CODEE` as instance variables so accessible from cross-compiler 
  * Support separation of Ram from Rom - includes
    * New `VP` user variable as pointer into variable area when defining in Rom, 
    * add `vHERE`, `v,`, `vALLOT`, `vALIGN`, `vCREATE` to use it,
    * Add `tokenCreate`
    * `VARIABLE` and `FORTH` to use Ram area
    * Change API to take ROMSIZE and RAMSIZE instead of EM
    * Changing User variables to have an offset in cells rather than bytes
    * Pad is in Ram area
* 2020-11-10: v0.0.10
  * Significant memory refactoring to make it quicker - involves SP and RP being in cells rather than bytes
* 2020-11-09: v0.0.9
  * Add bottom text for help etc
  * Better error handling in the console
* 2020-11-08: v0.0.7
  * Console interface working, with stack display
  * Refactoring of memory classes
* 2020-10-31: v0.0.6
  * Add index.html and index_web.js for simple POC UI 
  * Refactor node specific IO out of Forth and add ForthNodeOverrides to simplify API
  * Fix node Raw echoing issue
* 2020-10-27: v0.0.5
  * Remove forth.js, add multitask example, 
  * CELLL and memClass and EM configurability
  * Add BYE and COLD and CREATE...DOES>
* 2020-10-03: v0.0.3 Node API with Forth instances
* 2020-09-26: v0.0.2 Published to NPM
* 2020-09-17: v0.0.1 First working version
* 2020-08-08: Had the idea, first files and outline of classes


