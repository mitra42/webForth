// Experiments with IO - to migrate into forth.js when work
//const tty = require('tty');
//SEE: https://nodejs.org/dist/latest-v12.x/docs/api/process.html#process_process_stdin
//SEE: https://nodejs.org/dist/latest-v12.x/docs/api/net.html#net_class_net_socket when its terminal - though doesnt match below
//SEE https://nodejs.org/docs/latest-v12.x/api/tty.html

/*
 Also various notes about raw Mode.
 */

function v1() {
  // Example from https://nodejs.org/dist/latest-v12.x/docs/api/process.html#process_process_stdin
  // This works - but cooks line by line emitting data events

  process.stdin.setEncoding('utf8');

  //TODO Unclear if need 'readable' event or just use .read
  process.stdin.on('readable', () => {
    let chunk;
    while ((chunk = process.stdin.read()) !== null) {
      process.stdout.write(`data: ${chunk}`);
    }
  });

  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}
function v1_1() {
  // MODIFIED v1
  // Works - but looses characters typed if no return before the read.

  process.stdin.setEncoding('utf8');
  process.stdout.setEncoding('utf8');
  function read1() {
    process.stdout.write('>');
    let chunk = process.stdin.read();
    if (!chunk) {
      process.stdout.write('NONE');
    } else {
      process.stdout.write(`DATA: ${chunk}`);
    }
    setTimeout(read1, 3000);
  }
  setTimeout(read1, 3000);

  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}
function v1_1_1() {
  // MODIFIED v1_1 with raw
  // Works - but not under debugger

  let TTY = process.stdout.isTTY;
  process.stdout.write(`TTY=${Boolean(TTY)}`);
  process.stdin.setEncoding('utf8');
  if (TTY) {
    process.stdin.setRawMode(true);
  }

  //process.stdout.setEncoding('utf8');
  function read1() {
    process.stdout.write('>');
    let chunk = process.stdin.read();
    if (!chunk) {
      process.stdout.write('NONE');
    } else {
      process.stdout.write(`DATA: ${chunk}`);
    }
    setTimeout(read1, 3000);
  }
  setTimeout(read1, 3000);

  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}
function v2_1() {
  // FAILS
  let TTY = process.stdout.isTTY;
  process.stdout.write(`TTY=${Boolean(TTY)}`);
  process.stdin.setEncoding('utf8');
  if (TTY) {
    process.stdin.setRawMode(true);
  }
  process.stdout.write('>');
  let chunk;
  while ((chunk = process.stdin.read()) === null) {
    //process.stdout.write('.');
  }
  if (TTY) {
    process.stdout.write(`data: ${chunk}`);
  }
  process.stdout.write('END');

  process.stdin.on('end', () => {
    process.stdout.write('end');
  });

}
function v2_2() {
  // MODIFIED v1_1_1 with raw
  // FAILS seems to not see data

  let TTY = process.stdout.isTTY;
  process.stdout.write(`TTY=${Boolean(TTY)}`);
  process.stdin.setEncoding('utf8');
  if (TTY) {
    process.stdin.setRawMode(true);
  }

  //process.stdout.setEncoding('utf8');
  function read1() {
    //process.stdout.write('>');
    let chunk = process.stdin.read();
    if (!chunk) {
      //process.stdout.write('NONE');
    } else {
      process.stdout.write(`DATA: ${chunk}`);
    }
    //setTimeout(read1, 3000);
  }
  //setTimeout(read1, 3000);
  while(true) {
    read1();
  }
  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}
function v3_1() {
  // Different approach - use data and buffer it
  // FAILS seems to not see data

  let TTY = process.stdout.isTTY;
  process.stdout.write(`TTY=${Boolean(TTY)}`);
  process.stdin.setEncoding('utf8');
  if (TTY) {
    process.stdin.setRawMode(true);
  }

  //process.stdout.setEncoding('utf8');
  function read1() {
    //process.stdout.write('>');
    let chunk = process.stdin.read();
    if (!chunk) {
      //process.stdout.write('NONE');
    } else {
      process.stdout.write(`DATA: ${chunk}`);
    }
    //setTimeout(read1, 3000);
  }
  //setTimeout(read1, 3000);
  while(true) {
    read1();
  }
  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}

function v4_i() {
  let TTY = process.stdout.isTTY; // TODO also test stdin
  process.stdout.write(`TTY=${Boolean(TTY)}`);
  process.stdin.setEncoding('utf8');
  if (TTY) {
    //process.stdin.setRawMode(true);
  }

  process.stdin.on('end', () => {
    process.stdout.write('end');
  });
}
function v4_loop() {
  let chunk = process.stdin.read();
  if (chunk) {
    process.stdout.write(`data: ${chunk}`);
  }
  setImmediate(v4_loop);
}
function v4() {
  // This works but wont transfer to Forth because of the callback
  v4_i();
  v4_loop();
  process.stdout.write('Done')
}

function v5() {
  // Try a yield
  function* RXgen() {
    while(true) {
      let chunk = process.stdin.read();
      if (chunk) {
        process.stdout.write(`data: ${chunk}`);
      }
      yield chunk;
    }
  }
  let RX = RXgen();
  function key() {
    let c;
    process.stdout.write(`waiting`);
    while ((c = RX.next().value) === null) {
      process.stdout.write('.');
    }
    process.stdout.write(`key: ${c}`);
  }
  v4_i();
  key();
}
//v5()


function bar() {
  console.log('bar');
}

async function foo() {
  console.log("foo");
  await bar();
  console.log('foo end')
}
foo();
