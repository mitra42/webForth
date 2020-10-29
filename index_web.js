/*
This script defines elements that can be used in index.html to provide a UI to the Forth interpreter, and loads the forth interpreter.
For reference see:
https://developer.mozilla.org/en-US/docs/Web/Web_Components/Using_custom_elements
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules
 */
let Forth; // Will hold class when loaded
let forth; // Will hold instance
class ForthConsole extends HTMLDivElement {
  constructor() {
    super();
    this.attachShadow({mode: 'open'});
    this.output = document.createElement('forth-output');
    this.shadowRoot.append(this.output);
    //this.output.app("FOO BAZ"); // Doesbt work - some kind of race condition
    this.input = document.createElement('forth-input');
    this.shadowRoot.append(this.input);
    const overrides = {TXbangS: (s) => this. output.TXbangS_web(s)};
    ForthLoad({overrides}); // returns a promise that is ignored
  }
}
class ForthOutput extends HTMLElement {
  constructor() {
    super();
    this.attachShadow({mode: 'open'});
    this.pre = document.createElement('pre');
    this.shadowRoot.append(this.pre);
  }
  app(s) {
    //TODO-33-UI add styles
    //TODO-33-UI handle CR
    this.pre.textContent += s;
  }
  /*
  TXbangC_web(c) {
    this.TXbangS_web(String.fromCharCode(c));
  }
  */
  TXbangS_web(s) {
    this.app(s);
  }
}
class ForthInput extends HTMLElement { // TODO-UI should be enabled only once Forth loaded
  constructor() {
    super();
    this.attachShadow({mode: 'open'});
    const style = document.createElement('style');
    style.textContent = 'input { width: 100%}';
    this.shadowRoot.append(style);
    this.form = document.createElement('form')
    this.form.onsubmit = ev => this.submit(ev);
    this.inputbox = document.createElement('input')
    Object.entries({ type: 'text', spellcheck: false})
      .forEach(kv => this.inputbox.setAttribute(kv[0], kv[1]))
    this.form.append(this.inputbox);
    this.shadowRoot.append(this.form);
  }
  submit(event) {
    event.preventDefault(); // Stop it triggering reload
    const inp = this.inputbox.value
    console.log("SUBMITTED", inp);
    if (forth) {
      //TODO - echo it
      this.inputbox.value = "";
      forth.TXbangS(inp);
      forth.interpret(inp); // Async but dont wait
    } else {
      console.log("Premature input TODO", inp);
    }
  }
}

//customElements.define('forth-output', ForthOutput);
customElements.define('forth-console', ForthConsole, {extends: "div"});
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
