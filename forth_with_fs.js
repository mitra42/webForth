import fs from 'fs';
import { Forth, ForthNodeExtensions } from './index.js';
// Normally this would be: import Forth from 'webforth';

/* This extends the standard Forth class to add capability for Files.
  It can't be fully integrated because of its dependence on "fs" which
  cannot be imported (I don't think) on a browser.
 */

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
            // noinspection JSUnresolvedFunction
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
          // noinspection JSUnresolvedFunction
          this.JSerrToCounted(err);
          resolve(); });
    }); },
  },
  { n: 'DELETE-FILE', // c-addr u -- ior ; https://forth-standard.org/standard/file/DELETE-FILE
    f() { return new Promise((resolve) => {
      const filename = this.SPpopString();
      fs.unlink(filename,
        (err) => {
          // noinspection JSUnresolvedFunction
          this.JSerrToCounted(err); resolve(); });
    }); },
  },
  /*
  { n: 'exists-file', // c-addr u -- F
    f() {
      const u = SPpop(); const filepath = this.SPpopString();
      return new Promise((resolve) => fs.access(filepath, fs.constants.F_OK, (err) => {this.SPpush(err ? l.FALSE : l.TRUE); resolve(); } ))}
  },
 */
  { n: 'CREATE-FILE', // c-addr u fam -- fileid ior ; https://forth-standard.org/standard/file/CREATE-FILE)
    f() {
      const fam = this.SPpop() | fs.constants.O_CREAT | fs.constants.O_TRUNC; const filepath = this.SPpopString();
      return new Promise((resolve) => fs.open(filepath, fam, 0o666,
        (err, fd) => {
          fsDescriptors[fd] = { filepath, fam, position: 0 };
          this.SPpush(fd || 0);
          // noinspection JSUnresolvedFunction
          this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'FILE-SIZE', // fileid -- ud ior ; https://forth-standard.org/standard/file/FILE-SIZE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.fstat(fd, (err, stats) => {
        this.SPpushD(stats ? stats.size : 0);
        // noinspection JSUnresolvedFunction
        this.JSerrToCounted(err);
        resolve(); })); },
  },
  { n: 'FLUSH-FILE', // fileid -- ior ; https://forth-standard.org/standard/file/FLUSH-FILE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.fsync(fd, (err) => {
        // noinspection JSUnresolvedFunction
        this.JSerrToCounted(err); resolve(); })); },
  },
  {
    n: 'RENAME-FILE', // c-addr1 u1 c-addr2 u2 -- ior ; https://forth-standard.org/standard/file/RENAME-FILE )
    f() {
      const filepath2 = this.SPpopString(); const filepath1 = this.SPpopString();
      return new Promise((resolve) => fs.rename(filepath1, filepath2, (err) => {
        // noinspection JSUnresolvedFunction
        this.JSerrToCounted(err); resolve(); })); },
  },
  {
    n: 'RESIZE-FILE', // ud fileid -- ior ; https://forth-standard.org/standard/file/RESIZE-FILE )
    // TODO This is probably not compliant - FILE-SIZE probably wont match if len > current size
    f() {
      const fd = this.SPpop(); const len = this.SPpopD();
      fsDescriptors[fd].position = Math.min(fsDescriptors[fd].position, len);
      return new Promise((resolve) => fs.truncate(fd, len, (err) => {
        // noinspection JSUnresolvedFunction
        this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'READ-FILE', //  ( c-addr u1 fileid -- u2 ior )  https://forth-standard.org/standard/file/READ-FILE
    f() {
      const fd = this.SPpop(); const len = this.SPpop(); const caddr = this.SPpop();
      const buf = this.m.buff8(caddr, len); // THis is exposing something that probably shouldnt be
      return new Promise((resolve) => fs.read(fd, buf, 0, len, fsDescriptors[fd].position,
        (err, bytesRead, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesRead; }
          this.SPpush(bytesRead || 0);
          // noinspection JSUnresolvedFunction
          this.JSerrToCounted(err); resolve();
        })); },
  },
  { n: 'WRITE-FILE', // ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-FILE )
    f() {
      const fd = this.SPpop(); const len = this.SPpop(); const caddr = this.SPpop(); const buf = this.m.buff8(caddr, len);
      return new Promise((resolve) => fs.write(fd, buf, 0, len, fsDescriptors[fd].position,
        (err, bytesWritten, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesWritten; }
          // noinspection JSUnresolvedFunction
          this.JSerrToCounted(err); resolve(); })); },
  },
  { n: 'write-cr', // ( fileid -- ior ; https://forth-standard.org/standard/file/WRITE-FILE )
    f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.write(fd, lineEnding, fsDescriptors[fd].position, 'utf8',
        (err, bytesWritten, unusedBuf) => {
          if (!err) { fsDescriptors[fd].position += bytesWritten; }
          // noinspection JSUnresolvedFunction
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
      // console.log("Setting fd:", fd,"to pos", pos, "#TIB=", this.Ufetch(16));
      this.SPpush(0);
    },
  },
  { n: 'R/O', constant: fs.constants.O_RDONLY },
  { n: 'R/W', constant: fs.constants.O_RDWR },
  { n: 'W/O', constant: fs.constants.O_WRONLY },

];
const filesExtension = `
: BIN ; \\ No-op its always binary
: WRITE-LINE ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-LINE )
  DUP >R WRITE-FILE R> SWAP ?DUP 0= IF write-cr ELSE DROP THEN ;

: eof? ( fd -- F )
  DUP FILE-POSITION THROW ( fd udouble )
  ROT FILE-SIZE THROW ( udouble udouble )
  ud< 0= ;

: reposRelativeFile ( ud fd - ior )
  DUP >R FILE-POSITION ( ud ud' ior ^ fd )
  ?DUP IF R> DROP >R 2DROP 2DROP R> EXIT THEN
  ( ud ud' ^ fd )
  D+ R> REPOSITION-FILE ( ior )
;
:NONAME ( fd - ior; Move fd back to >IN, so reading will start where left off : unreadFile )
  SOURCE + 1024 SOURCE NIP - ( fd TIB+#TIB 1024-#TIB)
  skipCRLF ( ptr after crlf, number to end of buf)
  NIP 1024 SWAP - >IN @ - 0 DNEGATE ROT  ( ud fd ; size of remaining buf + crlf* ) 
  0 >IN ! 0 #TIB ! ( Reset pointers so dont try and read it)
  reposRelativeFile ( ior )
;
' unreadFile DEFER! ( vector forward reference ) 

:NONAME ( caddr umax fd -- u2 flag ior ; https://forth-standard.org/standard/file/READ-LINE : READ-LINE)
  DUP eof? IF DROP 2DROP 0 0 0 EXIT THEN
  ( caddr umax fd )
  >R OVER SWAP R@
  ( caddr caddr umax fd ^ fd )
  READ-FILE ( caddr u ior ^ fd )
  ?DUP IF R> DROP EXIT THEN ( caddr u ^ fd )
  2DUP skipToCRLF  ( c u c' u' ^  fd )
  DUP >R SWAP >R - R> R>
  ( caddr u~ caddr' u' ^ fd ; u~ is size up to but excluding first crlf u' is amount from crlf to end )
  skipCRLF ( caddr u~ caddr" u" ^ fd ; u" is size from first after CRLF to end)
  NIP 0 DNEGATE R> reposRelativeFile ( position file to after crlf )
  >R NIP TRUE R> ( u~ T ior )
;
' READ-LINE DEFER! 
   
vCREATE buf 1024 vALLOT

: INCLUDE-FILE ( i * x fileid -- j * x ; https://forth-standard.org/standard/file/INCLUDE-FILE )
  sourcePush buf 0 0 4 RESTORE-INPUT THROW ;
: INCLUDED ( caddr u -- ; https://forth-standard.org/standard/file/INCLUDED e.g. $" filename" INCLUDED )
  R/O OPEN-FILE ( fileid ior ) THROW INCLUDE-FILE ;
: INCLUDE PARSE-NAME INCLUDED ; ( i*x "name" -- j*x ; https://forth-standard.org/standard/file/INCLUDE )

( TODO-34-FILES blocks - this would be handled in SOURCE I think https://forth-standard.org/standard/block)

: ALLOCATE ( u -- a ior; Shortcut to https://forth-standard.org/standard/memory/ALLOCATE rewrite if want to use FREE) 
    HERE SWAP ALLOT 0 ;
: n2sign DUP IF 0< IF -1 ELSE 1 THEN THEN ; ( u -- -1 | 0 | 1)
: COMPARE ( c-addr1 u1 c-addr2 u2 -- n ; https://forth-standard.org/standard/string/COMPARE )
  ROT SWAP 2DUP 2>R \\ c1 c2 u1 u2 ^ u1,u2 ; save lengths
  MIN FOR AFT \\ c1 c2 ^ u' u1,u2 ; iterate over minimum length
    1+ SWAP 1+ SWAP
    OVER C@ OVER C@ - \\ c1 c2 char1-char2
    ?DUP IF \\ c1 c2 char1-char2 ^ u' u1,u2
      NIP NIP R> DROP 2R> 2DROP \\ char1-char2
      n2sign EXIT
    THEN \\ c1 c2 ^ u' u1,u2
  THEN NEXT \\ c1 c2 ^ u1,u2
  2DROP 2R> - \\ u1-u2
  n2sign
;  \\ TODO Non conformant definition should be -1|0|1 not 0|n

\\ Implementation comes from https://forth-standard.org/standard/file/REQUIRED except ...
: save-mem ( addr1 u -- addr2 u ) \\ gforth
\\ copy a memory block into a newly allocated region in the heap
 SWAP >R
 HERE OVER ALLOT SWAP
 2DUP R> ROT ROT 
 MOVE ;

: name-add ( addr u listp -- )
   >R save-mem ( addr1 u )
   3 CELLS ALLOCATE THROW \\ allocate list node
   R@ @ OVER ! \\ set next pointer
   DUP R> ! \\ store current node in list var
   CELL+ 2!
;
: name-present? ( addr u list -- f )
   ROT ROT 2>R BEGIN ( list R: addr u )
     DUP
   WHILE
     DUP CELL+ 2@ 2R@ COMPARE 0= IF
       DROP 2R> 2DROP TRUE 
       EXIT
     THEN
     @
   REPEAT
   ( DROP 0 ) 2R> 2DROP 
;

: name-join ( addr u list -- )
   >R 2DUP R@ @ name-present? IF
     R> DROP 2DROP
   ELSE
     R> name-add
   THEN ;

VARIABLE included-names 0 included-names !

: included ( i*x addr u -- j*x )
   2DUP included-names name-join
   INCLUDED 
   ;

: REQUIRED ( i*x addr u -- i*x )
   2DUP included-names @ name-present? 0= IF
     included
   ELSE
     2DROP
   THEN ; 

: REQUIRE [COMPILE] S" REQUIRED ;



( ==== BELOW HERE STILL NEED DEFINING ==== )
( : S\\" ( "ccc<quote>" -- c-addr u ; read and translate escape chars )
( : ( ( needs to skip till gets to end of file )
( TODO-34-FILES check second group of words on standard )

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
  DUP buf 1024 ROT READ-FILE THROW ( fd u )
  buf SWAP TYPE ( fd )
  DUP FILE-POSITION THROW DROP . ."  of " ( fd)
  DUP FILE-SIZE THROW DROP . ."  bytes " ( fd)
  DUP 6 0 ROT REPOSITION-FILE THROW ( fd)
  DUP FILE-POSITION THROW DROP ."  repositioned to " . ( fd -- reposition to "world" )
  DUP buf 1024 ROT READ-FILE THROW ( fd u )
  buf SWAP TYPE ( fd )
  CLOSE-FILE THROW ( )
  S" TEST2.FTH" R/O OPEN-FILE THROW
  BEGIN
    DUP buf 1024 ROT READ-LINE THROW ( fd u T|F )
  WHILE
    buf SWAP TYPE CR
  REPEAT DROP ( fd )
  CLOSE-FILE THROW ( )
  S" TEST2.FTH" DELETE-FILE THROW
  ;
: TESTER ." starting test" ['] TESTFILES CATCH ?DUP .$ ."  After " ;
`;

class Forth_with_fs extends Forth {
  constructor(opts) {
    // This constructor just passes on the arguments for Forth mostly unchanged
    opts.rqFiles = -1; // Make sure hooks are there for files
    super(opts); // Note this will add any 'extensions' from opts (typically ForthNodeExtensions)
    // Has to add extensions be before compileForthInForth as uses READ-LINE
    fsExtensions.forEach((e) => this.extensionAdd(e));
  }
  async initialize() {
    // TODO-34-FILES can we use EVALUATE or similar for filesExtension or is that self-reference
    await this.compileForthInForth();
    await this.interpret(filesExtension);
  }
}
export { Forth_with_fs, ForthNodeExtensions };
