import { Forth, ForthNodeExtensions, Romable16_16 } from '../index.js';
// Normally this would be: import Forth from 'webforth';
import fs from 'fs';

// Valid choices for CELL:MEM are 2:8 2:16 2:32 3:8 4:8 4:16 4:32
const CELLL = 2; // 2 bytes for CELLL
const MEM = 16; // Use 16 bit memory
// Specify areas for ROM and RAM, currently they have to be specified separately as there is a bug with setting ROMSIZE = 0;
// ROM: Used for UserVariable save area and Dictionary (code and names) until useRam() is called
const ROMSIZE = 0x2000 * CELLL;
// RAM: Used for UserVariables, stacks, TIB, PAD etc and Dictionary (code and names) after useRam() is called
const RAMSIZE = 0x400 * CELLL;
const extensions = ForthNodeExtensions;
let memClass = undefined;
//memClass = Romable16_16; // Uncomment this to simulate a chip with separate Rom and Ram (like an Arduino).

/* Files design decisions
  At this point no local data is stored - File descriptors are returned.
  If reqd, this could shift to storing the fd in a CREATE DOES> structure

  See:
    https://github.com/mitra42/webForth/issues/34
    https://nodejs.org/api/fs.html and
    https://man7.org/linux/man-pages/man2/open.2.html
 */

function JSerr(err) {
  if (!err) return null;
  this.JStoCounted()
}
const fsExtensions = [
  { f: async function JSerrToCounted(err) { return err ? this.JStoCounted(err.message) : 0; }},
  {
    n: 'OPEN-FILE', // c-addr u fam -- fileid ior ; https://forth-standard.org/standard/file/OPEN-FILE eg.  : X ... S" TEST.FTH" R/W OPEN-FILE ABORT" OPEN-FILE FAILED" ... ;
    async f() { // TODO refactor out the common parts of this - probably a Promise with the results of a callback.
      const fam = SPpop(); const u = SPpop(); const a = SPpop(); const filepath = this.stringToJS(a, u);
      return new Promise(
        (resolve) => fs.open(filepath,
          fam, // # TODO-FILES figure out how map flags unix wants to a constant see https://man7.org/linux/man-pages/man2/open.2.html and header files it points at
          (err, fd) => {
            this.SPpush(fd); // will be indeterminate if error
            this.SPpush(this.JSerrToCounted(err));
            resolve();
          }),
      );
    },
  },
  {
    n: 'CLOSE-FILE',  // fileid -- ior ; https://forth-standard.org/standard/file/CLOSE-FILE
    async f() { return new Promise((resolve) => fs.close(this.SPpop(), (err) => { this.SPpush(this.JSerrToCounted(err)); resolve(); })); },
  },
  { n: 'DELETE-FILE', // c-addr u -- ior ; https://forth-standard.org/standard/file/DELETE-FILE
    async f() { return new Promise((resolve) => fs.unlink(this.SPpop(), (err) => { this.SPpush(this.JSerrToCounted(err)); resolve(); })); },
  },
  /*
  { n: 'exists-file', // c-addr u -- F
    async f() {
      const u = SPpop(); const a = SPpop(); const filepath = this.stringToJS(a, u);
      return new Promise((resolve) => fs.access(filepath, fs.constants.F_OK, (err) => {this.SPpush(err ? 0 : -1); resolve(); } ))}
  },
 */
  { n: 'CREATE-FILE', // c-addr u fam -- fileid ior ; https://forth-standard.org/standard/file/CREATE-FILE)
    async f() {
      const fam = this.SPpop() | fs.constants.O_CREAT; const u = this.SPpop(); const a = this.SPpop(); const filepath = this.stringToJS(a, u);
      return new Promise((resolve) => fs.open(filepath, fam, 0o666, (err) => { this.SPpush(this.JSerrToCounted(err)); resolve(); })); },
  },
  { n: 'FILE-SIZE', ( fileid -- ud ior ; https://forth-standard.org/standard/file/FILE-SIZE )
    async f() {
      const fd = this.SPpop();
      return new Promise((resolve) => fs.fstat(fd, (err, stats) => {
        this.SPpushD(stats ? stats.size : 0);
        this.SPpush(this.JSerrToCounted(err)); resolve(); })); },
    }
  }
  { n: 'R/O', constant: fs.constants.O_RDONLY },
  { n: 'R/W', constant: fs.constants.O_RDWR },
  { n: 'W/O', constant: fs.constants.O_WRONLY },


];
const filesExtension = `
: S"| do$ COUNT ; ( -- caddr u)
: S| COMPILE S"| $," ; IMMEDIATE ( merge into $| )
  
( Code words on OS )
( : FILE-POSITION ( fileid - ud iod ; https://forth-standard.org/standard/file/FILE-POSITION and https://www.npmjs.com/package/fs-ext)
( : FLUSH-FILE ( fileid -- ior ; https://forth-standard.org/standard/file/FLUSH-FILE )
( RENAME-FILE ( c-addr1 u1 c-addr2 u2 -- ior ; https://forth-standard.org/standard/file/RENAME-FILE )
( REPOSITION-FILE (  ud fileid -- ior ; https://forth-standard.org/standard/file/REPOSITION-FILE )
( RESIZE-FILE ( ud fileid -- ior ; https://forth-standard.org/standard/file/RESIZE-FILE )


USER SOURCE-ID ... but needs a stack as nested - 0 Terminal -1 STRING evaluate or fileid
PARSE-NAME ( needed INCLUDED )

Modifications and extensions
: S\\" ( "ccc<quote>" -- c-addr u ; read and translate escape chars )
: ( ( needs to skip till gets to end of file )


( Work with above and >IN SOURCE-FILE etc)
( : READ-FILE  https://forth-standard.org/standard/file/READ-FILE  - prob equal depth to READ-LINE )
: WRITE-FILE ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-FILE ) 
( : READ-LINE ( caddr u fileid -- u2 flag ior ; https://forth-standard.org/standard/file/READ-LINE) 
WRITE-LINE ( c-addr u fileid -- ior ; https://forth-standard.org/standard/file/WRITE-LINE )
REFILL ( -- flag ; https://forth-standard.org/standard/file/REFILL )


( Build on code words order significant )
( INCLUDE-FILE ( i * x fileid -- j * x ; https://forth-standard.org/standard/file/INCLUDE-FILE - needed by INCLUDED 
( : INCLUDED ( caddr u -- ; https://forth-standard.org/standard/file/INCLUDED e.g. $" filename" INCLUDED -- needs INCLUDE-FILE needed REQUIRED )
( : INCLUDE PARSE-NAME INCLUDED ; ( i*x "name" -- j*x ; https://forth-standard.org/standard/file/INCLUDE )
( Need some other ANS words here esp ALLOCATED )
( : REQUIRED XXX ; ( https://forth-standard.org/standard/file/REQUIRED -- needs INCLUDED needed REQUIRE )
( : REQUIRE [COMPILE] S" REQUIRED ;
`;

const forth = new Forth({ CELLL, ROMSIZE, RAMSIZE, MEM, extensions, memClass });
forth.compileForthInForth()
  .then(() => console.log('===forthInForth compiled'))
  //.then(() => forth.cleanupBootstrap()).then(() => console.log('===forthInForth cleaned up'))
  //.then(() => forth.interpret("WARM"));
  .then(() => forth.extensionAdd({
    n: 'ramSP',
    f: function() { this.SPpush(this.ramSP); }
  }))
  .then(() => forth.extensionAdd({
    n: 'OPEN-FILE',
    f: function() { }
  }))
  //.then(() => forth.interpret(filesExtension))
  .then(() => forth.console()) // Interactive console
  .then(() => console.log('\nconsole exited'));
