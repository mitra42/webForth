/*
This script defines elements that can be used in index.html to provide a UI to the Forth interpreter, and loads the forth interpreter.
For reference see:
https://developer.mozilla.org/en-US/docs/Web/Web_Components/Using_custom_elements
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules
 */
let Forth; // Will hold class when loaded
let forth; // Will hold instance

// A simple (adaptable) utility to make it easier to write nested elements in JS
function EL(tag, attributes = {}, children) {
  const el = document.createElement(tag);
  Object.entries(attributes)
    .forEach(kv => {
      if (['textContent','onsubmit'].includes(kv[0])) {
        el[kv[0]] = kv[1]
      } else {
        el.setAttribute(kv[0], kv[1])
      }
    });
  if (children) el.append(...children);
  return el;
}

class ForthConsole extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({mode: 'open'});
    // Create an output area
    this.output = document.createElement('forth-output');
    this.div = EL("div", {}, [ this.output ]);
    this.shadowRoot.append(this.div);
    // Create an input area, but only attach once Forth is loaded.
    this.input = document.createElement('forth-input');
    // Define hooks for IO to these areas
    const overrides = {TXbangS: (s) => this.output.TXbangS_web(s)};
    // Load Forth can also define CELL, EM, memClass //TODO-33-UI export class from forth.js and pass here as a class not a name
    const CELLL = 2;
    const MEM = 8;
    ForthLoad({CELLL, MEM, memClass: `${MEM}_${CELLL*8}`, overrides})
      .then(() => this.shadowRoot.append(this.input)) ; // Only add input area when Forth defined
      // returns a promise that is ignored
  }
}

// Defines a basic pre-formated text area so can display forth output including CR etc
class ForthOutput extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({mode: 'open'});
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
    this.attachShadow({mode: 'open'});
    this.inputbox = EL('input', { type: 'text', spellcheck: false}, )
    this.shadowRoot.append(
      // Style it as 100% of width of parent, by default will be boxed
      EL('style', { textContent: 'input { width: 100%}'}),
      // Define a form with a single Input element
      EL('form', {onsubmit: ev => this.submit(ev) }, [this.inputbox])
    );
  }
  submit(event) {
    event.preventDefault();           // Stop it triggering reload
    const inp = this.inputbox.value;  // Fetch the value entered
    console.log(">>", inp);           // Debugging output on console
    if (!forth) {                      // Should only be enabled once forth is defined, but check
      console.log("Premature input TODO", inp);
    } else {
      this.inputbox.value = "";       // Clear result
      forth.TXbangS(inp);             // But echo - via forth, should go to Console
      forth.interpret(inp);           // Async interpretation of text, but dont wait for it
    }
  }
}

//customElements.define('forth-output', ForthOutput);
customElements.define('forth-console', ForthConsole);
customElements.define('forth-output', ForthOutput);
customElements.define('forth-input', ForthInput);

async function ForthLoad({overrides={}} = {}) {
  const CELLL = 2;
  const MEM = 8;
  const EM = 0x2000 * CELLL; // default is 0x2000 * CELLL
  try {
      const module = await import("./index.js");
      //console.log("module is", Forth);
      Forth = module.Forth; // Make available globally to this file
      const f = new Forth({
        CELLL, EM, memClass: `${MEM}_${CELLL * 8}`, // Define memory
        overrides,
      });         // Setup I/O (just output currently)
      await f.compileForthInForth();
      console.log('===forthInForth compiled');
      f.interpret("' .OK ' DROP ' kTAP XIO");
      forth = f; // Make available to other components when, and only when, forthInForth compiled.
  } catch(err) {
    console.log("Failed to load Forth", err);
  }
}
//ForthLoad();

console.log("Imported");
