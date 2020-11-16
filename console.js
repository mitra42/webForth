/*
This script defines elements that can be used in index.html to provide a UI to the Forth interpreter, and loads the forth interpreter.
For reference see:
https://developer.mozilla.org/en-US/docs/Web/Web_Components/Using_custom_elements
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules
 */
let Forth; // Will hold class when loaded
let forth; // Will hold instance

async function ForthLoad({ extensions = [] } = {}) {
  const fLog = extensions.map(x=>x.f).find(f => f.name === "bound TXbangS") || console.log;
  const CELLL = 2;
  const MEM = 8;
  const EM = 0x2000 * CELLL; // default is 0x2000 * CELLL
  try {
    const module = await import('./index.js');
    Forth = module.Forth; // Make available globally to this file
    const f = new Forth({
      CELLL, EM, MEM, memClass: module.Mem8_16, // Define memory
      extensions,
    });         // Setup I/O (just output currently)
    fLog('\nCompiling Forth from Forth\n');
    // noinspection JSUnresolvedFunction
    await f.compileForthInForth();
    fLog('\nforth in forth compiled\n');
    // noinspection JSUnresolvedFunction
    await f.interpret("' .OK ' DROP ' kTAP XIO");
    forth = f; // Make available to other components when, and only when, forthInForth compiled.
  } catch (err) {
    fLog('Failed to load Forth - see console for details');
    console.log(err);
  }
}

// A simple (adaptable) utility to make it easier to write nested elements in JS
function EL(tag, attributes = {}, children) {
  const el = document.createElement(tag);
  Object.entries(attributes)
    .forEach((kv) => {
      if (['textContent', 'onsubmit'].includes(kv[0]) || (typeof(kv[1]) === "object")) {
        el[kv[0]] = kv[1];
      } else {
        el.setAttribute(kv[0], kv[1]);
      }
    });
  if (children) el.append(...children);
  return el;
}

const consoleStyle = `
.grid-container {
  display: grid;
  grid-template-columns: auto auto;
  grid-gap: 3px;
  background-color: #2196F3;
  padding: 3px;
}
.grid-under {
  display: grid;
  gri-template-columns: auto auto auto;
  grid-gap: 3px;
  padding:  0px 3px 3px 3px;
  background-color: #2196F3;
  font-size: smaller;
}
.grid-under div {
  padding: 1px;
  background-color: rgba(255, 255, 255, 0.8);
  text-align: center;
}
forth-stack, forth-output, forth-input, .banner {
  padding: 5px;
  background-color: rgba(255, 255, 255, 0.8);
}
.banner { text-align: center; font-size: larger; grid-column-start: 1; grid-column-end: 3}
forth-stack { text-align: right; grid-column-start: 2; grid-column-end: 3} 
forth-output { text-align: left; grid-column-start: 1; grid-column-end: 2} 
forth-input { text-align: left; grid-row-start: 3; grid-row-end: 4; grid-column-start: 1; grid-column-end: 3; } 
`;
class ForthConsole extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({ mode: 'open' });
    this.shadowRoot.append(
      EL('style', { textContent: consoleStyle }),
      this.grid = EL('div', { class: 'grid-container' }, [
        EL('div', { class: 'banner', textContent: 'webForth console' }),
        // Create an output area
        this.output = EL('forth-output'),
      ]),
      EL('div', { class: 'grid-under' }, [
        EL('div',{style: 'grid-column-start: 1;grid-column-end: 2;'}, [
          EL('a', {  href: 'https://github.com/mitra42/webForth' }, [
            EL('span', { textContent: 'help' }),
          ]),
        ]),
        EL('div',{ style: 'grid-column-start: 2;grid-column-end: 3;'}, [
          EL('a', { href: 'https://mitra.biz' }, [
            EL('span', { textContent: 'mitra ardron 2020' }),
          ]),
        ]),
        EL('div',{ style: 'grid-column-start: 3;grid-column-end: 4;'}, [
          EL('a', { href: 'https://github.com/mitra42/webForth' }, [
            EL('span', { textContent: 'git repo' }),
          ]),
        ]),
      ]),
    );
    this.stack = EL('forth-stack');
    // Create an input area, but only attach once Forth is loaded.
    this.input = EL('forth-input', { stack: this.stack });
    // Define hooks for IO to these areas
    const extensions = [{ f: (function TXbangS(s) {
      this.output.TXbangS_web(s); }).bind(this) }]; // Note this is instance of ForthConsole not Forth
    // Load Forth can also define CELL, EM, memClass
    const CELLL = 2;
    const MEM = 8;
    ForthLoad({ CELLL, MEM, extensions })
      .then(() => this.grid.append(this.input, this.stack)) // Only add input area when Forth defined
      .then(() => forth.interpret1('version'));
    // returns a promise that is ignored
  }
}

// Defines a basic pre-formatted text area so can display forth output including CR etc
class ForthOutput extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({ mode: 'open' });
    this.pre = document.createElement('pre');
    this.shadowRoot.append(this.pre);
  }
  // Append string to area, this function is passed to the Forth instance on construction.
  TXbangS_web(s) {
    this.pre.textContent += s;
  }
}

class ForthInput extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({ mode: 'open' });
    this.inputbox = EL('input', { type: 'text', spellcheck: false });
    this.shadowRoot.append(
      // Style it as 100% of width of parent, by default will be boxed
      EL('style', { textContent: 'input { width: 98%; padding: 0.2em; }' }),
      // Define a form with a single Input element
      EL('form', { onsubmit: (ev) => this.submit(ev) }, [this.inputbox]),
    );
  }
  submit(event) {
    event.preventDefault();           // Stop it triggering reload
    const inp = this.inputbox.value;  // Fetch the value entered
    console.log('>>', inp);           // Debugging output on console
    if (!forth) {                      // Should only be enabled once forth is defined, but check
      console.log('Premature input TODO', inp);
    } else {
      this.inputbox.value = '';       // Clear result
      forth.TXbangS(inp);             // But echo - via forth, should go to Console
      // noinspection JSIgnoredPromiseFromCall
      forth.interpret1(inp)            // Async interpretation of text
        // Attempt to debug a race condition - commented out as condition disappeared
        //.then((res) => forth.debug1 = forth.m.debug(forth.SP,forth.SPP))
      .then((res) => this.stack.render(res));     // Then reprint stack
    }
  }
}

class ForthStack extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({ mode: 'open' });
    this.shadowRoot.append(
      EL('style', { textContent: '.stack ul {margin-top: 0px; list-style-type: none;}' }),
      EL('div', { class: 'stack' }, [
        EL('span', { textContent: 'STACK' }),
        this.sdiv = EL('div', {}, []),
      ]),
    );
  }
  render(res) {
    if (this.sul) this.sul.remove();
    this.sdiv.append(
      this.sul = EL('ul', { },
        forth.debugStack().map((s) => EL('li', { textContent: s }))),
    );
  }
}
//customElements.define('forth-output', ForthOutput);
customElements.define('forth-console', ForthConsole);
customElements.define('forth-output', ForthOutput);
customElements.define('forth-input', ForthInput);
customElements.define('forth-stack', ForthStack);

console.log('Imported');
