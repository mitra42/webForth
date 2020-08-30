/* These functions will get split into different files */

const safe = true;

/**
 * CodeSpace class - implements the program area.
 * Note this could be implemented in various ways and upper code should be agnostic as to which
 * classic Forth style threaded dict (3 letters + length)
 * or headless (dict during compilation) then discarded (similar to Forth Inc used to do)
 *
 * In all of them i is the first value of the payload and c is the context
 *
 * Naming:
 *  initiateX is the first value in a definition that is jumped through (initiateColon, initiateNext, initiateVariable, initiateConstant)
 *  doX is the function, the index of which is compiled into the dic (doSemicolon doLoop doLiteral)
 */

function initiateColon(c, i) { // i contains first thing to execute in the definition
  c.returnStack.push(c.programCounter); // (R: -- nest-sys )
  c.programCounter = i;
}
// handles constant, variable and create all of which just put next field on stack
function initiateNext(c, i) {
  c.stack.push(c.dictionary.code[i]);
}

/**
 * This next set of functions are the critical call-thru functions, they depend on the assumptions in CodeSpace and Context.run but
 * need to be pure (non class) functions.
 */


/**
 * The Forth basic stack.
 * Note the assumption is multi-threaded so there can be many independent stacks IF supported
 */
class Stack extends Array {
  read(n) {
    if (safe) console.assert(n < this.length);
    return this[this.length - n - 1];
  }
  pop(n = 0) {
    return this.splice(this.length - n - 1, 1)[0];
  }

  /**
   * This tests the stack functionality, if re-implement, then probably just copy the tests
   */
  testMatch(arr) {
    console.assert(arr.length === this.length);
    // eslint-disable-next-line no-restricted-syntax,guard-for-in
    while (arr.length) {
      console.assert(arr.pop() === this.pop())
    }
  }
}

class Data {
  // Writable space, split across separate arrays
  constructor() {
    this.contiguous = [];
    this.textLiteral = [];
  }
  arrAlloc(arr, n) {
    const add = arr.length;
    while (n-- > 0) {
      arr.push(undefined);
    }
    return add;
  }
  allot(n) {
    this.arrAlloc(this.contiguous, n);
  }
  here() { return this.contiguous.length; }
}
class Dictionary {
  constructor() {
    this.nameSpace = {};
    this.immediateNameSpace = {};
    this.data = new Data();
    this.code = [null];
    this.lastDefinitionName = undefined;
  }
  here() { return this.data.here(); }

  //TODO-FIND check usages of this
  resolveArr(arr) { return arr.map(n => typeof n === 'string' ? this.find(n)[0] : n); }

  push(...arr) { // Returns the address of first element stored
    const next = this.next();
    this.code.push(...this.resolveArr(arr));
    return next;
  }
  next() { // Index of function about to define
    return this.code.length;
  }
  // Run the code starting at 'i' within context 'c'
  run(xt, c) {
    this.code[xt](c, xt + 1);
  }
  define(name, addr) {
    this.lastDefinitionName = name;
    if (name) this.nameSpace[name] = addr;
    return addr;
  }
  immediate() {
    this.immediateNameSpace[this.lastDefinitionName] = this.nameSpace[this.lastDefinitionName];
    delete this.nameSpace[this.lastDefinitionName];
    this.lastDefinitionName = undefined;
  }
  // Look up a name, return [xt, 1] if immediate, [xt -1] if not, [name, 0] if not found.
  find(name) { // TODO merge into Forth word "FIND" - needs counted strings
    const i = this.immediateNameSpace[name];
    if (i) return [i, 1];
    const n = this.nameSpace[name];
    if (n) return [n, -1];
    return [name, 0];
  }
}
/**
 * Context allows for multi-tasking, it has the different data areas code is likely to need.
 */
class Context {
  constructor() {
    this.dictionary = new Dictionary();
    this.stack = new Stack();
    this.programCounter = 0;
    this.returnStack = []; // Thread pushes an initial 0 to it
    this.controlStack = [];
    this.compiling = false;
    this.input = undefined; // Will hold strings to parse - should possibly be in dictionary.data.input but think better here
    // Might be needed instead of passing on stack ... this.definitionStart = undefined;
  }
  // Group of redirections of function to same name on a sub-data structure
  testMatch(arr) { this.stack.testMatch(arr); }
  find(w) { return this.dictionary.find(w); }
  immediate() { this.dictionary.immediate(); }
  here() { return this.dictionary.here(); }

  return() { this.programCounter = this.returnStack.pop(); }
  returnStack0() { return this.returnStack[this.returnStack.length - 1]; }

  define(name, ...def) {
    return this.dictionary.define(name, this.dictionary.push(...def));
  }

  code(name, func) { // define a code function in the dic, return its xt
    return this.define(name, func);
  }

  colon(name) { // Closely coupled with ';'    C: -- colon-sys
    const definitionStart = this.dictionary.next();
    this.dictionary.push(initiateColon);
    this.controlStack.push(definitionStart, name || this.consumeWord());
    this.compiling = true;
  }

  semicolon() { // C: colon-sys(definitionStart name) --
    // eslint-disable-next-line no-use-before-define
    this.dictionary.push('doSemicolon');
    const name = this.controlStack.pop();
    this.compiling = false;
    return this.dictionary.define(name, this.controlStack.pop());
  }

  // For testing and for compilation before interpreter exists
  definition(name, ...def) {
    this.colon(name);
    this.dictionary.push(...def);
    this.semicolon();
  }

  consumeWord() {
    let w;
//    [w, this.input] = this.input.trim().split(/\s(.*)/);
    [w, this.input] = this.input.trim().split(/(?<=^\S+)\s/);
    return w;
  }
  interpret(inp) { // TODO-RECODE could rewrite all or parts in Forth
    if (inp) this.input = inp;
    while (this.input && this.input.length) {
      const w = this.consumeWord();
      if (((w[0] >= '0') && (w[0] <= '9')) || ((w[0] == '-') && (w.length > 1))) { // Its a number
        const base = 10; // TODO-NUM handle bases
        const n = parseInt(w, base); // TODO-NUM handle parsing errors // Needs forth to convert word
        if (this.compiling) { //TODO-RECODE STATE @ IF
          // eslint-disable-next-line no-use-before-define
          this.dictionary.push('doLiteral', n); //TODO-RECODE ['] doLiteral COMPILE, COMPILE,
        } else { // TODO-RECODE not reqd already on stack
          this.stack.push(n); //TODO-RECODE Already on stack
        } // TODO-RECODE THEN
      } else { // ELSE
        const [xt, found] = this.dictionary.find(w);  //TODO-FIND needs FIND
        if (!found) { // NOT IF
          console.error('Not found',w); //TODO handle forth-like errors //TODO-RECODE needs error handling
        } else if (found === 1 || !this.compiling) { // Immediate
          this.run(xt);
        } else {
          this.dictionary.push(xt);
        }
      }
    }
  }

  // This is the inner interpreter that loops through nesting
  run(initialXt) {
    const c = this;
    // c.programCounter = 0;
    if (initialXt) {
      c.dictionary.run(initialXt, c);
      // If this returns without changing program Counter, it will exit
    }
    while (c.programCounter) {
      const xt = c.dictionary.code[c.programCounter++]; //4
      c.dictionary.run(xt, c); // This may manipulate c.programCounter
    }
  }
  jump() { // Jump to the location specified in the next field
    this.programCounter = this.dictionary.code[this.programCounter];
  }
  jumpIf(f) { // Jump if f is true
    if (f) { this.jump(); } else { this.programCounter++; }
  }
}

const c = new Context();

// Moving things between stacks
c.code('R@', c1 => c1.stack.push(c1.returnStack0()));
c.code('R>', c1 => c1.stack.push(c1.returnStack.pop()));
c.code('>R', c1 => c1.returnStack.push(c1.stack.pop()));
c.code('>ctrl', c1 => c1.controlStack.push(c1.stack.pop())); //TODO maybe more correct name r rename >ctrl
c.code('ctrl>', c1 => c1.stack.push(c1.controlStack.pop())); //TODO maybe more correct name r rename >ctrl
c.code('next', c1 => c1.stack.push(c1.dictionary.next()));
c.code('next>ctrl', c1 => c1.controlStack.push(c1.dictionary.next()));
c.code('dict!', c1 => c1.dictionary.code[c1.stack.pop()] = c1.stack.pop()); // code_destn code_orig --; dict[code_orig] = code_destn

// Basic stack manipulation
c.code('DUP', c1 => c1.stack.push(c1.stack.read(0)));
c.code('DROP', c1 => c1.stack.pop()); // x y => x
c.code('ROLL', (c1) => {
  x = c1.stack.pop();
  v = []
  for (let i = x; i > 0; i--) { v.push(c1.stack.pop()); }
  newtop = c1.stack.pop();
  for (let i = x; i > 0; i--) { c1.stack.push(v.pop()); }
  c1.stack.push(newtop);
})
c.code('ROT', (c1) => { const x = c1.stack.pop(2); c1.stack.push(x); }); // x y z -- y z x
c.code('SWAP', (c1) => { const x = c1.stack.pop(1); c1.stack.push(x); }); // x y -- y x

// Associated with definitions
c.code('IMMEDIATE', c1 => c1.immediate());
c.code(':', c1 => c1.colon());
c.code('doSemicolon', c1 => c1.return()); // (R: nest-sys --))
c.code(';', c1 => c1.semicolon()); // C: colon-sys(definitionStart name) --
c.immediate();
//ON-NEW
c.code('doLiteral', c1 => c1.stack.push(c1.dictionary.code[c1.programCounter++]));
//NOT-ON-NEW
c.code('CONSTANT', c1 => c1.define(c1.consumeWord(), initiateNext, c1.stack.pop()));
// Typical usage : foo ['] xyz COMPILE, ;
c.code("[']", (c1) => { //TODO-FIND needs WORD and FIND and ERROR
  const w = c1.consumeWord();
  const [xt, found] = c1.find(w);
  if (found) { // immediate or not
    c1.dictionary.push('doLiteral', xt);
  } else {
    console.error(w, "not found during [']");
  }
}); c.immediate();
c.code("'", (c1) => { // TODO-RECODE as WORD FIND NOT IF ERROR THEN needs WORD FIND ERROR
  const w = c1.consumeWord();
  const [xt, found] = c1.find(w);
  if (found) { // immediate or not
    c1.stack.push(xt);
  } else {
    console.error(w, "not found during '");
  }
});
c.code('COMPILE,', (c1) => c1.dictionary.push(c1.stack.pop()));
c.code('(', c1 => c1.input = c1.input.split(/(?<=^[^\)]+)\)/)[1]); c.immediate(); // TODO-REFACTOR when have parsing of in-memory strings
//ON-NEW
c.code('EXECUTE', c1 => c1.dictionary.run(c1.stack.pop(), c1)); // This does not nest the core run code and if xt is a colon word then it should push right stuff on stack (word after EXECUTE)
//NOT-ON-NEW
// FIND and WORD in forth use the obsoleted counted string, rather than repeat that we've defined find and word to use JS strings
c.code('find', c1 => c1.stack.push(...c1.find(c1.stack.pop()))); // TODO-FIND replace other uses of find
c.code('word', c1 => c1.stack.push(c1.consumeWord())); // TODO-FIND replace other places use consumeWord TODO-REFACTOR when have input parsing in forth style

// String handling
c.code('doString', c1 => { const s = c1.dictionary.code[c1.programCounter++]; c1.stack.push(s, s.length); });
// This is not quite S" as unclear what that means if string not contiguous in dic, this will put string and length on stack
c.code('s"', c1 => {
  let s;
  [s, c1.input] = c1.input.split(/(?<=^[^"]+)"/);
  c1.dictionary.push('doString', s);
}); c.immediate(); // TODO-REFACTOR when have parsing of in-memory strings

// Data space manipulation
c.code('HERE', c1 => c1.stack.push(c1.here()));
c.code('ALLOT', c1 => c1.dictionary.data.allot(c1.stack.pop()));
c.code('@', c1 => c1.stack.push(c1.dictionary.data.contiguous[c1.stack.pop()]));
c.code('!', c1 => c1.dictionary.data.contiguous[c1.stack.pop()] = c1.stack.pop());
c.code(',', c1 => c1.dictionary.data.contiguous.push(c1.stack.pop()));

// See CREATE-DOES in Design.md
c.code('CREATE', (c1) => c1.define(c1.consumeWord(), initiateNext, c1.dictionary.data.contiguous.length));
// -- addr; code: initiateDoes dataPtr codePtr(after DOES>); execute content of DOES> part of definition
function initiateDoes(c1, p) {
  c1.stack.push(c1.dictionary.code[p++]);
  initiateColon(c1, c1.dictionary.code[p]);
}
// R: next-sys --; dict: icreate data-ptr -- idoes data-ptr code-ptr; complete definition.
// NOTE THIS IS NOT IMMEDIATE
c.code('DOES>', (c1) => {
  c1.dictionary.code[c1.dictionary.next()-2] = initiateDoes; // replace initiateNext put there by Create
  c1.dictionary.push(c1.programCounter);
  // Note this assumes control stack not implemented on return stack
  c1.return(); // Return to code that called square
});

// Control stuctures:  BEGIN..UNTIL BEGIN..WHILE..REPEAT DO..LEAVE..LOOP IF...ELSE...THEN
c.code('branch', c1 => c1.jump()); // branch is in some older F83 Forths
c.code('!?branch', c1 => c1.jumpIf(c1.stack.pop()));
//ON-NEW
c.code('?branch', c1 => c1.jumpIf(!c1.stack.pop())); // ?branch is in some older F83 Forths
//NOT-ON-NEW

c.code('doDo', (c1) => { c1.returnStack.push(c1.stack.pop()); c1.returnStack.push(c1.stack.pop()); }); // limit index -- R: -- loop-sys(index, limit)
function popLoop(c1) { c1.returnStack.pop(); c1.returnStack.pop(); }
const doLeave = c.code('doLeave', (c1) => { popLoop(c1); c1.jump(); })
c.code('doLoop', (c1) => { // R do-sys -- | do-sys
  const endloop = (++c1.returnStack[c.returnStack.length - 2] === c1.returnStack[c.returnStack.length - 1])
  if (endloop) popLoop(c1);
  c1.jumpIf(!endloop);
});

// Fetch indexes, note its -2 and -4 because they are code function not colon
c.code('I', (c1) => c1.stack.push(c1.returnStack[c.returnStack.length - 2]));
c.code('J', (c1) => c1.stack.push(c1.returnStack[c.returnStack.length - 4]));

// Math TODO-MATH check definitions - and make sure conforms - including sizes, signs and floats, for now its intuitive
c.code('-', (c1) => { const y = c1.stack.pop(); c1.stack.push(c1.stack.pop() - y); });
c.code('+', c1 => c1.stack.push(c1.stack.pop() + c1.stack.pop()));
c.code('/', (c1) => { const y = c1.stack.pop(); c1.stack.push(c1.pop() / y); }); //TODO-MATH will be float, want int etc
c.code('*', c1 => c1.stack.push(c1.stack.pop() * c1.stack.pop()));
c.code('=', c1 => c1.stack.push(c1.stack.pop() === c1.stack.pop())); //TODO-MATH check what forth wants for bool


c.interpret(`
( Data manipulation )
: , HERE 1 ALLOT ! ; ( x --  Data: -- x )

( Variable is a trivial use of CREATE )
: VARIABLE CREATE 1 ALLOT ;

( Loops and control structures ) 
: backwardreference next>ctrl ; ( C: -- destn )
: forwardreference next>ctrl 0 COMPILE, ; ( C: -- orig, D: -- 0, orig points at 0)
: jumpforwardifnot ['] ?branch COMPILE, forwardreference ; ( C: -- orig, D: -- ?branch 0@orig )
: jumpforward ['] branch COMPILE, forwardreference ; ( C: -- orig, D: -- branch 0 )
: jumpbackifnot ['] ?branch COMPILE, ctrl> COMPILE, ; ( C: destn --, D: -- ?branch destn )
: jumpback ['] branch COMPILE, ctrl> COMPILE, ; ( C: destn --, D: -- branch destn )
: resolvejump next ctrl> dict! ; ( C: orig --, D: ...jumpx 0@orig... -- ...jumpx next ... )
: IF jumpforwardifnot ; IMMEDIATE ( compilation: C: -- orig, D: -- ?branch 0@orig, execution: if stack zero jump )
: ELSE ctrl> jumpforward >ctrl resolvejump ; IMMEDIATE
( compilation: orig1 -- orig2 D: ...?branch 0@orig1 ... -- ...?branch next ... branch 0@orig2 ) 
: THEN resolvejump ; IMMEDIATE ( compilation: orig --, D: ... jumpx 0@orig... == ...jumpx next ... )
: BEGIN backwardreference ; IMMEDIATE ( C: -- destn )
: UNTIL jumpbackifnot ; IMMEDIATE ( C: destn --, D: -- ?branch destn )
: WHILE ctrl> jumpforwardifnot >ctrl ; IMMEDIATE ( C: destn -- orig destn, D: ...?branch 0@orig... )
: REPEAT jumpback resolvejump ; IMMEDIATE ( C: orig destn --, D: ... ?branch next ... branch destn )
: DO ['] doDo COMPILE, backwardreference 0 >ctrl ; IMMEDIATE ( C: -- destn=next 0, D: .. doDo ) 
: LEAVE ['] doLeave COMPILE, forwardreference ; IMMEDIATE ( C: -- destn 0 orig D: -- doLeave 0@orig )
: LOOP ['] doLoop COMPILE, forwardreference ctrl>
  BEGIN ctrl> DUP >ctrl WHILE resolvejump REPEAT
  ctrl> DROP ctrl> SWAP dict! ; IMMEDIATE
( C:   D: doDo ... [doLeave 0@orig ...]*... -- doDo ... [doLeave next...]*... doLoop destn )
: AHEAD jumpforward ; ( C: -- orig, D: -- branch 0 ) ( unclear if forth standard wants this to be immediate )

( Doubles - this might not work as stack used for colon, may need to be code or cleverer TODO test these )
: 2>R SWAP >R >R ; ( x1 x2 -- R: -- x1 x2 )
: 2R> R> R> SWAP ; ( -- x1 x2   R: x1 x2 -- )
: 2R@ R> R> 2DUP >R >R SWAP ; ( -- x1 x2 R: x1 x2 -- x1 x2 )

( : POSTPONE WORD FIND IF COMPILE, ELSE ERROR THEN ; ( TODO-RECODE needs WORD FIND ERROR )
( EVALUATE ( x* c-addr u -- j*, TODO-RECODE needs counted strings )
`);


// TESTING
c.code('print', (c1) => console.log(c1.stack.pop())); // Print to console for testing purposes  maybe more Forth-ish name

function test(c) {
  /* Test stack primitives */
  c.interpret('10 DUP');
  c.testMatch([10, 10]);
  c.interpret('1 DROP');
  c.testMatch([]);
  c.interpret('10 20 SWAP');
  c.testMatch([20, 10]);
  c.interpret('10 20 30 ROT');
  c.testMatch([20, 30, 10]);
  c.interpret('11 12 13 14 15 3 ROLL');
  c.testMatch([11, 13, 14, 15, 12]);
  c.definition('rotswap', 'ROT', 'SWAP');
  c.interpret('10 20 30 rotswap');
  c.testMatch([20, 10, 30]);
  c.interpret(': swaprot SWAP ROT ;');
  c.interpret('10 20 30 swaprot');
  c.testMatch([30, 20, 10]);
  c.interpret('5 CONSTANT five five');
  c.testMatch([5]);
  c.interpret('HERE 3 ALLOT HERE SWAP -');
  c.testMatch([3]);
  c.interpret('VARIABLE counter 40 counter ! counter @');
  c.testMatch([40]);
  c.definition('lit4', 'doLiteral', 4); // Check can define a literal in-line using definition
  c.interpret('lit4');
  c.testMatch([4]);
  c.interpret('40 >R R@ R>');
  c.testMatch([40, 40]);
  c.interpret(': test3a 3 1 DO I LOOP ; test3a');
  c.testMatch([1, 2]);
  c.interpret(': test3b 3 1 DO 3 1 DO J 10 * I + LOOP LOOP 0 ; test3b');
  c.testMatch([11, 12, 21, 22, 0]);
  c.interpret(': test3c 3 1 DO 3 1 DO J 10 * I + LOOP LOOP 0 ; test3c');
  c.testMatch([11, 12, 21, 22, 0]);
  c.interpret(': test4 3 1 DO 3 1 DO J 10 * I + LEAVE 5 LOOP LOOP 0 ; test4');
  c.testMatch([11, 21, 0]);
  c.interpret(': square CREATE , DOES> @ DUP ; 2 square sq2x2 sq2x2 *');
  c.testMatch([4]);
  c.interpret(': testBU 5 BEGIN DUP 1 - DUP 0 = UNTIL ; testBU');
  c.testMatch([5, 4, 3, 2, 1, 0]);
  c.interpret(': testBWR 5 BEGIN DUP WHILE DUP 1 - REPEAT ; testBWR');
  c.testMatch([ 5, 4, 3, 2, 1, 0]);
  c.interpret(': testif IF 10 ELSE 20 THEN 30 ; 0 testif');
  c.testMatch([20, 30]);
  c.interpret(': testif IF 10 ELSE 20 THEN 30 ; 1 testif');
  c.testMatch([10, 30]);
  c.interpret(": testex 123 ['] DUP EXECUTE 456 ; testex");
  c.testMatch([123, 123, 456]);
  c.interpret("123 ' DUP EXECUTE 456");
  c.testMatch([123, 123, 456]);
  c.interpret(': testS s" hello word" 123 ; testS');
  console.assert(c.stack.pop() === 123);
  console.assert(c.stack.pop() === c.stack.pop().length);
  // TODO test 2R> >2R etc
}
test(c);

/** TODO next steps
 * define counted strings, then use for FIND support S" and C" -
 * Document s" find and word
 * Define an Error
 * * only support S" define find and word as versions using c-addr u TODO-FIND needs ERROR
 * https://www.taygeta.com/forth/dpans6.htm progressive from top or work through "A" first
 * pass through TODO's - some may be urgent
 * Interpret string sequence for execution https://www.taygeta.com/forth/dpans3.htm#3.4
 * Compilation set: done: ['] COMPILE, EXECUTE , ' delayed: POSTPONE EVALUATE (needs WORD FIND)
 * Check other loops etc in https://www.taygeta.com/forth/dpans3.htm#3.2.3.3 +LOOP UNLOOP EXIT
 * https://www.taygeta.com/forth/dpans15.htm esp .S ? SEE AHEAD STATE
 * Think about integers (32bit), double-cell integers (64 bit);  if x is integer x 0 is double
 * Implement environment queries in https://www.taygeta.com/forth/dpans3.htm#3.2.6
 * TODO-MATH redo and check definitions
 *
*/
