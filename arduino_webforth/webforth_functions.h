#ifndef ARDUINO_WEBFORTH_H_
#define ARDUINO_WEBFORTH_H_
#include <Arduino.h>
#define RAM0 0
#define ROM0 0x8000
#define CELLL 2
#define TIB0 0x270
#define UPP 0x380
#define UZERO 0x8000
#define CELLTYPE uint16_t
#define SIGNEDCELLTYPE int16_t
#define DOUBLECELLTYPE uint32_t
#define CELLSHIFT 1
#define CELLOFFSETMASK 1
#define LITTLEENDIAN true
#define ROMCELLS 0x3000
#define RAMCELLS 0x200
#define SPP 0x260
#define RP0 0x370
#define RAMNAMEE 0x160
#define RAMCODEE 0
#define ROM(cellAddr) pgm_read_word_near(&rom[cellAddr])
#define FUNCTIONSLENGTH 84
#define XT_COLD 0x9b6a /* COLD*/
// Data defined currently in arduino_webforth.ino but used in webforth_functions.cpp
extern const CELLTYPE rom[ROMCELLS] PROGMEM;
extern void (* const f[FUNCTIONSLENGTH])();
// Needed by setup or loop defined in webforth_functions.cpp
extern CELLTYPE IP;
extern CELLTYPE IPnext();
extern void threadtoken(const CELLTYPE xt);
#endif
