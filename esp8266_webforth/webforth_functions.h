#ifndef ARDUINO_WEBFORTH_H_
#define ARDUINO_WEBFORTH_H_
#include <Arduino.h>
#define RAM0 0
#define ROM0 0x40000000
#define CELLL 4
#define TIB0 0x9ce0
#define UPP 0x9f00
#define UZERO 0x40000000
#define CELLTYPE uint32_t
#define SIGNEDCELLTYPE int32_t
#define DOUBLECELLTYPE uint64_t
#define CELLSHIFT 2
#define CELLOFFSETMASK 3
#define LITTLEENDIAN true
#define ROMCELLS 0x3000
#define RAMCELLS 0x2800
#define SPP 0x9cc0
#define RP0 0x9ee0
#define RAMNAMEE 0x9ac0
#define RAMCODEE 0
#define ROM(cellAddr) pgm_read_dword_near(&rom[cellAddr])
#define FUNCTIONSLENGTH 83
#define XT_COLD 0x40003650 /* COLD*/
// Data defined currently in arduino_webforth.ino but used in webforth_functions.cpp
extern const CELLTYPE rom[ROMCELLS] PROGMEM;
extern void (* const f[FUNCTIONSLENGTH])() PROGMEM;
// Needed by setup or loop defined in webforth_functions.cpp
extern CELLTYPE IP;
extern CELLTYPE IPnext();
extern void threadtoken(const CELLTYPE xt);

// Tokens are needed by webforth_functions.cpp which does not include webforth_dictionary.cpp
/* === Function tokens === */
#define F_tokenVocabulary 1
#define F_tokenNextVal 2
#define F_tokenDoList 3
#define F_tokenUser 4
#define F_tokenVar 5
#define F_tokenCreate 6
#define F_tokenDefer 7
#define F_tokenValue 8
#endif