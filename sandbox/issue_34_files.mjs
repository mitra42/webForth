import fs from 'fs';
import { Forth, ForthNodeExtensions } from '../index.js';
// Normally this would be: import Forth from 'webforth';

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32
const CELLL = 2; // 2 bytes for CELLL
const MEM = 16; // Use 16 bit memory
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x2000 * CELLL;
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x2000 * CELLL; // Make it larger will use
const extensions = ForthNodeExtensions;
const memClass = undefined; // Define to override default based on CELLL and MEM

/* Files design decisions
  At this point no local data is stored - File descriptors are returned.
  If reqd, this could shift to storing the fd in a CREATE DOES> structure

  See:
    https://github.com/mitra42/webForth/issues/34
    https://nodejs.org/api/fs.html and
    https://man7.org/linux/man-pages/man2/open.2.html
 */

const lineEnding = `
`;
const fsDescriptors = {}; // Filled with info available to JS only (opaque to Forth)

const fsExtensions = [
  { f: function JSerrToCounted(err) { // Place error or zero on stack
    if (err) { this.JStoCounted(err.message); } else { this.SPpush(0); } } },
  {
    n: 'OPEN-FILE', // c-addr u fam -- fileid ior ; https://forth-standard.org/standard/file/OPEN-FILE eg.  : X ... S" TEST.FTH" R/W OPEN-FILE ABORT" OPEN-FILE FAILED" ... ;
    f() { // TODO refactor out the common parts of this - probably a Promise with the results of a callback.
      const fam = this.SPpop(); const filepath = this.SPpopString();
      return new Promise(
        (resolve) => fs.open(filepath,
          fam, // # TODO-FILES figure out how map flags unix wants to a constant see https://man7.org/linux/man-pages/man2/open.2.html and header files it points at
          (err, fd) => {
            fsDescriptors[fd] = { filepath, fam, position: 0 };
            this.SPpush(fd || 0); // will be indeterminate if error
            this.JSerrToCounted(err);
            resolve();
          }),
      );
    },
  },
  {
    n: 'CLOSE-FILE',  // fileid -- ior ; https://forth-standard.org/standard/file/CLOSE-FILE
    f() { return new Promise((resolve) => {
      const fd = this.SPpop();
      fs.close(fd,
        (err) => {
          delete fsDescriptors[fd];
          this.JSerrToCounted(err);
          resolve(); });
    }); },
  },
  { n: 'DELETE-FILE', // c-addr u -- ior ; https://forth-standard.org/standard/file/DELETE-FILE
    f() { return new Promise((resolve) => {
      const filename = this.SPpopString();
      fs.unlink(filename,
        (err) => { this.JSerrToCounted(err); resolve(); });
    }); },
  },
  /*
  { n: 'exists-file', // c-addr u -- F
    f() {
      const u = SPpop(); const filepath = this.SPpopString();
      return new Promise((resolve) => fs.access(filepath, fs.constants.F_OK, (err) => {this.SPpush(err ? 0 : -1); resolve(); } ))}
  },
 */
  { n: 'CREATE-FILE', // c-addr u fam -- fileid ior ; https://forth-standard.org/standard/file/CREATE-FILE)
    f() {
      const fam = this.SPpop() | fs.constants.O_CREAT | fs.constants.O_TRUNC; const filepath = this.SPpopString();
      return new Promise((resolve) => fs.open(filepath, fam, 0o666,
        (err, fd) => {
          fsDescriptors[fd] = { filepath, fam, position: 0 };
          this.SPpush(fd || 0); this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'FILE-SIZE', // fileid -- ud ior ; https://forth-standard.org/standard/file/FILE-SIZE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.fstat(fd, (err, stats) => {
        this.SPpushD(stats ? stats.size : 0);
        this.JSerrToCounted(err);
        resolve(); })); },
  },
  { n: 'FLUSH-FILE', // fileid -- ior ; https://forth-standard.org/standard/file/FLUSH-FILE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.fsync(fd, (err) => { this.JSerrToCounted(err); resolve(); })); },
  },
  {
    n: 'RENAME-FILE', // c-addr1 u1 c-addr2 u2 -- ior ; https://forth-standard.org/standard/file/RENAME-FILE )
    f() {
      const filepath2 = this.SPpopString(); const filepath1 = this.SPpopString();
      return new Promise((resolve) => fs.rename(filepath1, filepath2, (err) => { this.JSerrToCounted(err); resolve(); })); },
  },
  {
    n: 'RESIZE-FILE', // ud fileid -- ior ; https://forth-standard.org/standard/file/RESIZE-FILE )
    // TODO This is probably not compliant - FILE-SIZE probably wont match if len > current size
    f() {
      const fd = this.SPpop(); const len = this.SPpopD();
      fsDescriptors[fd].position = Math.min(fsDescriptors[fd].position, len);
      return new Promise((resolve) => fs.truncate(fd, len, (err) => { this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'READ-FILE', //  ( c-addr u1 fileid -- u2 ior )  https://forth-standard.org/standard/file/READ-FILE
    f() {
      const fd = this.SPpop(); const len = this.SPpop(); const caddr = this.SPpop();
      const buf = this.m.buff8(caddr, len); // THis is exposing something that probably shouldnt be
      return new Promise((resolve) => fs.read(fd, buf, 0, len, fsDescriptors[fd].position,
        (err, bytesRead, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesRead; }
          this.SPpush(bytesRead || 0); this.JSerrToCounted(err); resolve();
        })); },
  },
  { n: 'WRITE-FILE', // ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-FILE )
    f() {
      const fd = this.SPpop(); const len = this.SPpop(); const caddr = this.SPpop(); const buf = this.m.buff8(caddr, len);
      return new Promise((resolve) => fs.write(fd, buf, 0, len, fsDescriptors[fd].position,
        (err, bytesWritten, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesWritten; }
          this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'write-cr', // ( fileid -- ior ; https://forth-standard.org/standard/file/WRITE-FILE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.write(fd, lineEnding, fsDescriptors[fd].position, 'utf8',
        (err, bytesWritten, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesWritten; }
          this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'FILE-POSITION', // fileid - ud iod ; https://forth-standard.org/standard/file/FILE-POSITION and https://www.npmjs.com/package/fs-ext)
    f() { // fileid - ud iod ; https://forth-standard.org/standard/file/FILE-POSITION and https://www.npmjs.com/package/fs-ext)
      const fd = this.SPpop();
      this.SPpushD(fsDescriptors[fd].position); this.SPpush(0);
    },
  },
  { n: 'REPOSITION-FILE', // ud fileid -- ior ; https://forth-standard.org/standard/file/REPOSITION-FILE )
    f() {
      const fd = this.SPpop();
      // noinspection UnnecessaryLocalVariableJS
      const pos = this.SPpopD();
      // Cant reposition in node so set internal position which is used on each read/write
      fsDescriptors[fd].position = pos;
      this.SPpush(0);
    },
  },
  { n: 'R/O', constant: fs.constants.O_RDONLY },
  { n: 'R/W', constant: fs.constants.O_RDWR },
  { n: 'W/O', constant: fs.constants.O_WRONLY },

];
const filesExtension = `
testing3
: WRITE-LINE ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-LINE )
  DUP >R WRITE-FILE R> SWAP ?DUP 0= IF write-cr ELSE DROP THEN ;

: eof? ( fd -- F )
  DUP FILE-POSITION THROW ( fd udouble )
  ROT FILE-SIZE THROW ( udouble udouble )
  ud< 0= ;

: skipCRLF ( caddr u -- caddr u )
  BEGIN
    DUP IF OVER C@ crlf? ELSE 0 THEN ( caddr u bool)
  WHILE ( caddr u )
    1 - SWAP 1 + SWAP ( caddr' u')
  REPEAT
;
: skipToCRLF ( caddr u -- caddr' u' )
  BEGIN
    DUP IF OVER C@ crlf? 0= ELSE 0 THEN ( caddr u bool)
  WHILE ( caddr u )
    1 - SWAP 1 + SWAP ( caddr' u')
  REPEAT
;
: reposRelativeFile ( ud fd - ior )
  DUP >R FILE-POSITION ( ud ud' ior ^ fd )
  ?DUP IF R> DROP >R 2DROP 2DROP R> EXIT THEN
  ( ud ud' ^ fd )
  D+ R> REPOSITION-FILE ( ior )
;
: READ-LINE ( caddr umax fd -- u2 flag ior ; https://forth-standard.org/standard/file/READ-LINE)
  DUP eof? IF DROP 2DROP 0 0 0 EXIT THEN
  ( caddr umax fd )
  >R OVER SWAP R@
  ( caddr caddr umax fd ^ fd )
  READ-FILE ( caddr u ior ^ fd )
  ?DUP IF R> DROP EXIT THEN ( caddr u ^ fd )
  2DUP skipToCRLF  ( c u c' u' ^  fd )
  DUP >R SWAP >R - R> R>
  ( caddr u~ caddr' u' ^ fd)
  skipCRLF
  ( caddr u~ caddr" u" ^ fd )
  NIP 0 DNEGATE R> reposRelativeFile ( )
  >R NIP -1 R> ( u~ T ior )
;

VARIABLE sourceBuff ( TODO-MULTI make this a user variable)
VARIABLE SOURCE-ID
: sourcePush R> SOURCE-ID @ >R SPAN @ >R >IN @ >R >R ; ( TODO-NEST needs to reposition existing file  )
: sourcePop R> R> >IN ! R> SPAN ! R> SOURCE-ID ! >R ;
: EVALUATE ( xxx caddr u -- yyy;  https://forth-standard.org/standard/core/EVALUATE )
  sourcePush SPAN ! sourceBuff ! -1 SOURCE-ID ! 0 >IN ! ;
: SOURCE SOURCE-ID @
  IF sourceBuff @ SPAN @ ( String or FD )
  ELSE TIB #TIB @
  THEN ;
( almost nothing )
: xPARSE >R SOURCE (a u) SWAP >IN @ + >IN @ - R> parse >IN +! ; ( TODO replace in index.js )
( nothing )
: REFILL ( https://forth-standard.org/standard/core/REFILL )
  0 >IN !
  SOURCE-ID @
  ?DUP IF
    DUP -1 =
    IF 0 // Always false
    ELSE BUF 1024 ROT READ-LINE ( u2 flag ior ) ( TODO check if need sourceBuff )
      THROW SWAP SPAN ! // True if more
    THEN
  ELSE
    TIB 80 'EXPECT @EXECUTE ( caddr u ;  vectors to accept)
    #TIB ! DROP -1
  THEN
;
: QUERY REFILL 0= IF sourcePop THEN ; ( Read from current source, on fail go back to previous reseting >IN )

: INCLUDE-FILE ( i * x fileid -- j * x ; https://forth-standard.org/standard/file/INCLUDE-FILE )
  sourcePush SOURCE-ID ! 0 >IN ! ;
: INCLUDED ( caddr u -- ; https://forth-standard.org/standard/file/INCLUDED e.g. $" filename" INCLUDED )
  R/O OPEN-FILE ( fileid ior ) THROW INCLUDE-FILE ;
: PARSE-NAME 34 WORD COUNT ; ( TODO look in index.js for other places it does part of this - 34 WORD)
: INCLUDE PARSE-NAME INCLUDED ; ( i*x "name" -- j*x ; https://forth-standard.org/standard/file/INCLUDE )

( TODO Maybe retire 'EXPECT and EXPECT and rename accept to EXPECT, retire SPAN as not used )
( TODO blocks - this would be handled in SOURCE I think https://forth-standard.org/standard/block)

( Redefining for testing purposes )
: que ( -- )
  QUERY ( get a line of commands from )
  EVAL ; ( Evaluate it)

: QUIT ( -- )
  ( Reset return stack pointer and start text interpreter. )
  RP0 @ RP!           ( initialize the return stack )
  BEGIN
    [COMPILE] [       ( start text interpreter )
  BEGIN
    [ ' que ] LITERAL ( get a line and evaluate it)
  CATCH             ( execute commands with error handler)
    ?DUP
    UNTIL ( a)          ( exit if an error occurred )
  ( 'PROMPT @ SWAP )  ( EFORTH-ZEN and EFORTH-V5 save current prompt address, Staapl doesnt)
  CONSOLE             ( Initialize for terminal interaction)
  quitError           ( Report error and reset data stack)
  ( V5 and ZEN also send "ERR" to file handler if prompt is not OK which is a little off )
  AGAIN ;               ( go back get another command line )




( ==== BELOW HERE STILL NEED DEFINING ==== )
( : S\\" ( "ccc<quote>" -- c-addr u ; read and translate escape chars )
( : ( ( needs to skip till gets to end of file )
( Need some other ANS words here esp ALLOCATED )
( : REQUIRED XXX ; ( https://forth-standard.org/standard/file/REQUIRED -- needs INCLUDED needed REQUIRE )
( : REQUIRE [COMPILE] S" REQUIRED ; )

CREATE BUF 1024 ALLOT
: TESTFILES
  S" TEST.FTH" W/O CREATE-FILE THROW ( fd )
  DUP S" Hello world" ROT WRITE-LINE THROW ( fd )
  DUP S" Hello earth" ROT WRITE-LINE THROW ( fd )
  DUP FILE-POSITION THROW DROP . ."  of "
  DUP FILE-SIZE THROW DROP . ."  bytes "
  DUP FLUSH-FILE THROW
  CLOSE-FILE THROW ( )
  S" TEST.FTH" S" TEST2.FTH" RENAME-FILE THROW ( )
  S" TEST2.FTH" R/W OPEN-FILE THROW ( fd )
  DUP BUF 1024 ROT READ-FILE THROW ( fd u )
  BUF SWAP TYPE ( fd )
  DUP FILE-POSITION THROW DROP . ."  of " ( fd)
  DUP FILE-SIZE THROW DROP . ."  bytes " ( fd)
  DUP 6 0 ROT REPOSITION-FILE THROW ( fd)
  DUP FILE-POSITION THROW DROP ."  repositioned to " . ( fd -- reposition to "world" )
  DUP BUF 1024 ROT READ-FILE THROW ( fd u )
  BUF SWAP TYPE ( fd )
  CLOSE-FILE THROW ( )
  S" TEST2.FTH" R/O OPEN-FILE THROW
  BEGIN
    DUP BUF 1024 ROT READ-LINE THROW ( fd u T|F )
  WHILE
    BUF SWAP TYPE CR
  REPEAT DROP ( fd )
  CLOSE-FILE THROW ( )
  S" TEST2.FTH" DELETE-FILE THROW
  ;
: TESTER ." starting test" doLIT TESTFILES CATCH ?DUP .$ ."  After " ;
`;
const forth = new Forth({ CELLL, ROMSIZE, RAMSIZE, MEM, extensions, memClass });
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => forth.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => forth.interpret("WARM"));
  .then(() => fsExtensions.forEach((e) => forth.extensionAdd(e)))
  .then(() => forth.interpret(filesExtension))
  .then(() => forth.console()) // Old Interactive console
  //.then(() => forth.interpret("QUIT")) // New interactive console
  .then(() => console.log('\nconsole exited'));
