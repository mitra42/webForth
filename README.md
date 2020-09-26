# Forth in Javascript
## Why?
I hear you ask why, which is hardly surprising. 
* Forth was the first language I got good at
* Javascript is the language I like to play in now
* You can run it in any browser, and on a server, and on some embedded devices
* If its modular enough I should be able to replace the JS with C, C++, Wasm or Assembler.
* All the Forth I've seen has been really antiquated, or over-complex, needs a fresh approach

## Status 

At v0.0.2.... 

```
npm install webforth
cd node_modules
node ./forth.js
```

* Installs webforth, note there are intentionally no dependencies in the minimal version.
* loads a bootstrap JS interpreter; 
* loads forth into it; 
* switches to the forth interpreter
* Starts a full forth console.
* `1 2 3 ROT .S` A simple forth command and output the stack

This is an experimental API - a better API for use in node, is being built
- early notes are in: [issue#23](https://github.com/mitra42/webForth/issues/23).
The code for that new API will be in index.js for node compatability. 

## Contributing

Yes please ! 

Please introduce yourself on [issue#1](https://github.com/mitra42/webforth/issues/1)

Pull requests are welcome, and even quite significant changes at this stage, 
but lets discuss first (open a new issue in GIT). 
