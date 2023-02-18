\ ANS Forth tests - run all tests

\ Adjust the file paths as appropriate to your system
\ Select the appropriate test harness, either the simple tester.fr
\ or the more complex ttester.fs 

CR .( Running ANS Forth and Forth 2012 test programs, version 0.13.4) CR

\ S" prelimtest.fth" INCLUDED \ exclude this, its useful only if got really serious issues (e.g. early development)
\ S" tester.fr" INCLUDED \ excluded as donnt want its version of T{ and }T
\ S" ttester.fs" INCLUDED

8 testFlags ! \ Have to run with testFlags on as T{ doesnt skip multi line tests
S" core.fr" INCLUDED

S" coreplustest.fth" INCLUDED
S" utilities.fth" INCLUDED
S" errorreport.fth" INCLUDED
S" coreexttest.fth" INCLUDED
S" blocktest.fth" INCLUDED
S" doubletest.fth" INCLUDED
S" exceptiontest.fth" INCLUDED
S" facilitytest.fth" INCLUDED
S" filetest.fth" INCLUDED
S" localstest.fth" INCLUDED
S" memorytest.fth" INCLUDED
S" toolstest.fth" INCLUDED
S" searchordertest.fth" INCLUDED
S" stringtest.fth" INCLUDED
REPORT-ERRORS

CR .( Forth tests completed ) CR CR


