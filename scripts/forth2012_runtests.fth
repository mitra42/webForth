\ ANS Forth tests - run all tests

\ Adjust the file paths as appropriate to your system
\ Select the appropriate test harness, either the simple tester.fr
\ or the more complex ttester.fs 

CR .( Running ANS Forth and Forth 2012 test programs, version 0.13.4) CR

\ S" prelimtest.fth" INCLUDED \ exclude this, its useful only if got really serious issues (e.g. early development)
S" tester.fr" INCLUDED \ was excluded as didnt want its version of T{ and }T but (Aug 2023) using itQUIT
\ S" ttester.fs" INCLUDED

8 testFlags ! \ Have to run with testFlags on as T{ doesnt skip multi line tests
S" core.fr" INCLUDED
TRUE VERBOSE ! \ Comment this out when working

\ coreplustest works - not needed by following
\ S" coreplustest.fth" INCLUDED

S" utilities.fth" INCLUDED \ needed by other tests
S" errorreport.fth" INCLUDED \ this needs either tester or ttester for things like #ERRORS and is needed by other tests

\ coreexttest.fth works - not needed by following tests
\ S" coreexttest.fth" INCLUDED

\ BLOCK isn't implemented in Forth2012 issue#80
\ S" blocktest.fth" INCLUDED

\ Doubles aren't implemented in Forth2012 issue#93
\ S" doubletest.fth" INCLUDED

\ exceptiontest should be working - words are implemented, just dont seem to work in way test expects issue#106
\ S" exceptiontest.fth" INCLUDED

\ facility test not working - TODO look into why, and file issues
\ S" facilitytest.fth" INCLUDED
\ filetest should probably work but its possible not all words it looks for are present - see issue#97
\ S" filetest.fth" INCLUDED
\ locals not implemented yet - see issue#50
\ S" localstest.fth" INCLUDED
\ memory allocation not implemented yet - see issue#96
\ S" memorytest.fth" INCLUDED
\ interpretive [IF] etc not implemente yet - see issue#95
\ S" toolstest.fth" INCLUDED
\ Vocabularies not implemented so search order test fails - see issue#35
\ S" searchordertest.fth" INCLUDED
\ Extended string functions esp SEARCH not implemeted yet - see issue#94
\ S" stringtest.fth" INCLUDED
REPORT-ERRORS

CR .( Forth tests completed ) CR CR


