# FORTH language and links

Forth is a fun, but odd language, but if you are here the chances are you know that. 
There are also not many people using it, and the ANSI standard is pretty poor 
(for example it doesn't appear to define counted strings).

These are the links I found useful developing this. 
* https://www.taygeta.com/forth/ is a 1994 draft of the ANSI spec which is apparently 
the same as the final version.
* http://forth.org/ Forth Interest Group - now defunct 
* https://www.forth.com/ Forth Inc - 
* 1013_eForthAndZen.pdf - eForth, I'm going to switch to this version

Errata: There are quite a few bugs in eForthAndZen, 
* some are fixed in [eForthOverviewv5.pdf](http://www.exemark.com/FORTH/eForthOverviewv5.pdf)
* others in [staapl](http://planet.racket-lang.org/package-source/zwizwa/staapl.plt/1/9/mcf/eforth/eforth.f)
* in the code in index.js these are flagged as EFORTH-ZEN-ERRATA

And some links I have still to research.

* http://forth.org/whoswho.html
* http://web.archive.org/web/20090311031548/http://www.fig-uk.org/
* 

Some github projects (maybe) of note
* https://github.com/larsbrinkhoff/lbForth - seems to have a lot of code, cross compiler etc
* https://github.com/philburk/pforth/blob/master/fth/strings.fth
* https://github.com/zeroflag/punyforth ESP forth-like
* https://github.com/ForthHub/forth Forth in JS as node module
* One of the other git - search for forth - look for javascript tag repos had javascript interoperability code
* https://github.com/marianoguerra/ricardo-forth compiles to wasm, but via C so probably loses efficiency
* https://github.com/drom/wast-forth wast > Forth 

Some other browser based forths
* http://nhiro.org/learn_language/FORTH-on-browser.html
JEforth [source](https://github.com/yapcheahshen/jeforth/)
Nick Morgan's EasyForth as a [notebook](https://skilldrick.github.io/easyforth/)
* [FB comment about them](https://www.facebook.com/groups/273924826349346/permalink/885462278528928/)

There are also some that are just a remote terminal to for example WinForth
that I haven't listed here as they do not "run in the browser".
