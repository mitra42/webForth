#ifndef ARDUINO_WEBFORTH_H_
#define ARDUINO_WEBFORTH_H_
#include <c_types.h>
#include <Arduino.h>
#define LITTLEENDIAN true
#define CELLL 4
#define CELLTYPE uint32_t
#define SIGNEDCELLTYPE int32_t
#define DOUBLECELLTYPE uint64_t
#define CELLSHIFT 2
#define CELLOFFSETMASK 0x03
#define ROMCELLS 0x1000
#define RAMCELLS 0x2800
#define RAM0 0
#define RAMCODEE RAM0
#define SPP 0x9cc0
#define RP0 0x9ee0
#define UPP 0x9f00
#define RAMNAMEE 0x9ac0
#define TIB0 0x9ce0
#define ROM0 0x40000000
#define UZERO ROM0

#define FUNCTIONSLENGTH 62

#define XT_COLD 0x400023e8 /* COLD*/

// Data defined currently in arduino_webforth.ino but used in arduino_functions.cpp
extern const CELLTYPE rom[ROMCELLS] PROGMEM;
extern void (* const f[FUNCTIONSLENGTH])() PROGMEM;

// Needed by setup or loop defined in arduino_functions.cpp
extern CELLTYPE IP;
extern CELLTYPE IPnext();
extern void threadtoken(const CELLTYPE xt);

#endif
