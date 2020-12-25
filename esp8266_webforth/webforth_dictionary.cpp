#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x40002418 /* WARM*/
#define XT_COLD 0x400023e8 /* COLD*/
#define XT__27BOOT 0x400023dc /* 'BOOT*/
#define XT_EMPTY 0x400023bc /* EMPTY*/
#define XT_hi 0x400023ac /* hi*/
#define XT_version 0x4000233c /* version*/
#define XT_VER 0x40002334 /* VER*/
#define XT_SEE 0x40002240 /* SEE*/
#define XT_FORTH_3ENAME 0x400021c4 /* FORTH>NAME*/
#define XT_WORDS 0x40002180 /* WORDS*/
#define XT__2EID 0x40002148 /* .ID*/
#define XT__3FCSP 0x40002120 /* ?CSP*/
#define XT__21CSP 0x4000210c /* !CSP*/
#define XT__2EFREE 0x400020f4 /* .FREE*/
#define XT__2EBASE 0x400020d0 /* .BASE*/
#define XT__2ES 0x40002094 /* .S*/
#define XT_DUMP 0x4000200c /* DUMP*/
#define XT_dm_2B 0x40001fbc /* dm+*/
#define XT__5FTYPE 0x40001f80 /* _TYPE*/
#define XT_CONSTANT 0x40001f60 /* CONSTANT*/
#define XT_VARIABLE 0x40001f48 /* VARIABLE*/
#define XT_vCREATE 0x40001f10 /* vCREATE*/
#define XT_CREATE 0x40001f00 /* CREATE*/
#define XT_create 0x40001edc /* create*/
#define XT_USER 0x40001ec0 /* USER*/
#define XT__3A 0x40001ea4 /* :*/
#define XT__5D 0x40001e8c /* ]*/
#define XT__3B 0x40001e74 /* ;*/
#define XT_OVERT 0x40001e58 /* OVERT*/
#define XT__24COMPILE 0x40001dfc /* $COMPILE*/
#define XT__24_2Cn 0x40001d88 /* $,n*/
#define XT__3FUNIQUE 0x40001d58 /* ?UNIQUE*/
#define XT_S_22 0x40001d44 /* S"*/
#define XT__24_22 0x40001d30 /* $"*/
#define XT_RECURSE 0x40001d18 /* RECURSE*/
#define XT__5BCOMPILE_5D 0x40001d08 /* [COMPILE]*/
#define XT_vALLOT 0x40001cdc /* vALLOT*/
#define XT_ALLOT 0x40001ccc /* ALLOT*/
#define XT__27 0x40001cac /* '*/
#define XT_quit1 0x40001c84 /* quit1*/
#define XT_QUIT 0x40001c44 /* QUIT*/
#define XT_quitError 0x40001be8 /* quitError*/
#define XT_que 0x40001bd8 /* que*/
#define XT_CONSOLE 0x40001bbc /* CONSOLE*/
#define XT_I_2FO 0x40001bac /* I/O*/
#define XT_HAND 0x40001b88 /* HAND*/
#define XT_FILE 0x40001b64 /* FILE*/
#define XT_XIO 0x40001b34 /* XIO*/
#define XT_PRESET 0x40001b10 /* PRESET*/
#define XT__5B 0x40001af8 /* [*/
#define XT_EVAL 0x40001abc /* EVAL*/
#define XT__3FSTACK 0x40001a9c /* ?STACK*/
#define XT__2EOK 0x40001a6c /* .OK*/
#define XT__24INTERPRET 0x40001a10 /* $INTERPRET*/
#define XT__2E_22 0x400019fc /* ."*/
#define XT_ABORT_22 0x400019e8 /* ABORT"*/
#define XT__24_2C_22 0x400019c0 /* $,"*/
#define XT_abort_22 0x400019a0 /* abort"*/
#define XT_ABORT 0x40001990 /* ABORT*/
#define XT_NULL_24 0x40001984 /* NULL$*/
#define XT_THROW 0x40001940 /* THROW*/
#define XT_CATCH 0x400018f8 /* CATCH*/
#define XT_QUERY 0x400018c0 /* QUERY*/
#define XT_EXPECT 0x400018a4 /* EXPECT*/
#define XT_accept 0x40001834 /* accept*/
#define XT_kTAP 0x400017cc /* kTAP*/
#define XT_crlf_3F 0x400017a0 /* crlf?*/
#define XT_TAP 0x40001778 /* TAP*/
#define XT__5EH 0x40001720 /* ^H*/
#define XT_NAME_3F 0x400016ac /* NAME?*/
#define XT_FORTHfind 0x400015c8 /* FORTHfind*/
#define XT_SAME_3F 0x40001560 /* SAME?*/
#define XT_NAME_3E 0x40001544 /* NAME>*/
#define XT_WORD 0x40001530 /* WORD*/
#define XT_TOKEN 0x400014fc /* TOKEN*/
#define XT__2E_28 0x400014e4 /* .(*/
#define XT_CTRL 0x400014cc /* CTRL*/
#define XT_CHAR 0x400014b4 /* CHAR*/
#define XT_PARSE 0x40001474 /* PARSE*/
#define XT_parse 0x40001330 /* parse*/
#define XT_S_22_7C 0x40001320 /* S"|*/
#define XT__2E_22_7C 0x40001310 /* ."|*/
#define XT__24_22_7C 0x40001304 /* $"|*/
#define XT_do_24 0x400012d8 /* do$*/
#define XT_CR 0x400012b8 /* CR*/
#define XT_PACE 0x400012a4 /* PACE*/
#define XT_NUF_3F 0x40001278 /* NUF?*/
#define XT_KEY 0x4000124c /* KEY*/
#define XT__3FKEY 0x4000123c /* ?KEY*/
#define XT_NUMBER_3F 0x400010f0 /* NUMBER?*/
#define XT_DIGIT_3F 0x40001094 /* DIGIT?*/
#define XT__3F 0x40001084 /* ?*/
#define XT__2E 0x4000104c /* .*/
#define XT_U_2E 0x40001030 /* U.*/
#define XT_U_2ER 0x40001004 /* U.R*/
#define XT__2ER 0x40000fe0 /* .R*/
#define XT_DECIMAL 0x40000fc8 /* DECIMAL*/
#define XT_HEX 0x40000fb0 /* HEX*/
#define XT_str 0x40000f88 /* str*/
#define XT__2E_24 0x40000f78 /* .$*/
#define XT_TYPE 0x40000f40 /* TYPE*/
#define XT_SPACES 0x40000f30 /* SPACES*/
#define XT_CHARS 0x40000ef8 /* CHARS*/
#define XT_SPACE 0x40000ee8 /* SPACE*/
#define XT_EMIT 0x40000ed8 /* EMIT*/
#define XT__23_3E 0x40000eb8 /* #>*/
#define XT_SIGN 0x40000e98 /* SIGN*/
#define XT__23S 0x40000e78 /* #S*/
#define XT__23 0x40000e60 /* #*/
#define XT_HOLD 0x40000e34 /* HOLD*/
#define XT__3C_23 0x40000e20 /* <#*/
#define XT_EXTRACT 0x40000e00 /* EXTRACT*/
#define XT_DIGIT 0x40000dcc /* DIGIT*/
#define XT_PACK_24 0x40000d60 /* PACK$*/
#define XT__2DTRAILING 0x40000d08 /* -TRAILING*/
#define XT_FILL 0x40000ccc /* FILL*/
#define XT_CMOVE 0x40000c7c /* CMOVE*/
#define XT_COUNT 0x40000c5c /* COUNT*/
#define XT__40EXECUTE 0x40000c34 /* @EXECUTE*/
#define XT_TIB 0x40000c20 /* TIB*/
#define XT_PAD 0x40000c08 /* PAD*/
#define XT_vCREATE 0x40000bd0 /* vCREATE*/
#define XT_vALIGN 0x40000bb4 /* vALIGN*/
#define XT_v_2C 0x40000b74 /* v,*/
#define XT_vHERE 0x40000b50 /* vHERE*/
#define XT_2_40 0x40000b34 /* 2@*/
#define XT_2_21 0x40000b18 /* 2!*/
#define XT__2B_21 0x40000af8 /* +!*/
#define XT_PICK 0x40000ad4 /* PICK*/
#define XT_DEPTH 0x40000ab0 /* DEPTH*/
#define XT__3ECHAR 0x40000a74 /* >CHAR*/
#define XT_CELLS 0x40000a64 /* CELLS*/
#define XT_CELL_2D 0x40000a54 /* CELL-*/
#define XT__2A_2F 0x40000a44 /* * /*/
#define XT__2A_2FMOD 0x40000a2c /* * /MOD*/
#define XT_M_2A 0x400009f4 /* M**/
#define XT__2A 0x400009e4 /* **/
#define XT_UM_2A 0x40000970 /* UM**/
#define XT__2F 0x40000960 /* /*/
#define XT_MOD 0x40000950 /* MOD*/
#define XT__2FMOD 0x40000938 /* /MOD*/
#define XT_M_2FMOD 0x400008cc /* M/MOD*/
#define XT_UM_2FMOD 0x40000804 /* UM/MOD*/
#define XT_WITHIN 0x400007e4 /* WITHIN*/
#define XT_MIN 0x400007c0 /* MIN*/
#define XT_MAX 0x400007a0 /* MAX*/
#define XT__3C 0x40000770 /* <*/
#define XT_ud_3C 0x4000073c /* ud<*/
#define XT_U_3C 0x4000070c /* U<*/
#define XT__3D 0x400006e4 /* =*/
#define XT_0_3D 0x400006bc /* 0=*/
#define XT_ABS 0x400006a0 /* ABS*/
#define XT__2D 0x40000690 /* -*/
#define XT_DNEGATE 0x40000668 /* DNEGATE*/
#define XT_NEGATE 0x40000650 /* NEGATE*/
#define XT_INVERT 0x4000063c /* INVERT*/
#define XT_D_2B 0x40000614 /* D+*/
#define XT__2B 0x40000604 /* +*/
#define XT_2DUP 0x400005f4 /* 2DUP*/
#define XT__2DROT 0x400005dc /* -ROT*/
#define XT_ROT 0x400005c4 /* ROT*/
#define XT__3FDUP 0x400005ac /* ?DUP*/
#define XT_WHILE 0x4000059c /* WHILE*/
#define XT_WHEN 0x4000058c /* WHEN*/
#define XT_ELSE 0x40000578 /* ELSE*/
#define XT_AFT 0x40000560 /* AFT*/
#define XT_THEN 0x40000554 /* THEN*/
#define XT_REPEAT 0x40000544 /* REPEAT*/
#define XT_AHEAD 0x40000530 /* AHEAD*/
#define XT_IF 0x4000051c /* IF*/
#define XT_AGAIN 0x40000508 /* AGAIN*/
#define XT_UNTIL 0x400004f4 /* UNTIL*/
#define XT_NEXT 0x400004e0 /* NEXT*/
#define XT_BEGIN 0x400004d4 /* BEGIN*/
#define XT_FOR 0x400004c0 /* FOR*/
#define XT__3ERESOLVE 0x400004ac /* >RESOLVE*/
#define XT__3EMARK 0x40000494 /* >MARK*/
#define XT__3CRESOLVE 0x40000488 /* <RESOLVE*/
#define XT__3CMARK 0x4000047c /* <MARK*/
#define XT_CREATE 0x4000046c /* CREATE*/
#define XT_create 0x40000448 /* create*/
#define XT_LITERAL 0x40000434 /* LITERAL*/
#define XT_COMPILE 0x40000414 /* COMPILE*/
#define XT__5BCOMPILE_5D 0x40000404 /* [COMPILE]*/
#define XT__2C 0x400003e0 /* ,*/
#define XT_CELL_2B 0x400003cc /* CELL+*/
#define XT_HERE 0x400003bc /* HERE*/
#define XT_NIP 0x400003ac /* NIP*/
#define XT__5CT 0x40000394 /* \T*/
#define XT__5C 0x4000037c /* \*/
#define XT__28 0x40000364 /* (*/
#define XT_IMMEDIATE 0x40000354 /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x40000344 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x40000320 /* setHeaderBits*/
#define XT_2DROP 0x40000310 /* 2DROP*/
#define XT_VP 0x40000308 /* VP*/
#define XT_LAST 0x40000300 /* LAST*/
#define XT_NP 0x400002f8 /* NP*/
#define XT_CP 0x400002f0 /* CP*/
#define XT_CURRENT 0x400002e8 /* CURRENT*/
#define XT_CONTEXT 0x400002e0 /* CONTEXT*/
#define XT_HANDLER 0x400002d8 /* HANDLER*/
#define XT_HLD 0x400002d0 /* HLD*/
#define XT__27NUMBER 0x400002c8 /* 'NUMBER*/
#define XT__27EVAL 0x400002c0 /* 'EVAL*/
#define XT_CSP 0x400002b8 /* CSP*/
#define XT__23TIB 0x400002b0 /* #TIB*/
#define XT__3EIN 0x400002a8 /* >IN*/
#define XT_SPAN 0x400002a0 /* SPAN*/
#define XT_temp 0x40000298 /* temp*/
#define XT_BASE 0x40000290 /* BASE*/
#define XT__27PROMPT 0x40000288 /* 'PROMPT*/
#define XT__27ECHO 0x40000280 /* 'ECHO*/
#define XT__27TAP 0x40000278 /* 'TAP*/
#define XT__27EXPECT 0x40000270 /* 'EXPECT*/
#define XT__27EMIT 0x40000268 /* 'EMIT*/
#define XT__27_3FKEY 0x40000260 /* '?KEY*/
#define XT_RP0 0x40000258 /* RP0*/
#define XT_SP0 0x40000250 /* SP0*/
#define XT_TEST 0x4000024c /* TEST*/
#define XT_debugPrintTIB 0x40000248 /* debugPrintTIB*/
#define XT_Fbreak 0x40000244 /* Fbreak*/
#define XT_testing3 0x40000240 /* testing3*/
#define XT_debugNA 0x4000023c /* debugNA*/
#define XT_userAreaSave 0x40000210 /* userAreaSave*/
#define XT_userAreaInit 0x4000020c /* userAreaInit*/
#define XT_UM_2B 0x40000208 /* UM+*/
#define XT_XOR 0x40000204 /* XOR*/
#define XT_OR 0x40000200 /* OR*/
#define XT_AND 0x400001fc /* AND*/
#define XT_0_3C 0x400001f8 /* 0<*/
#define XT_OVER 0x400001f4 /* OVER*/
#define XT_SWAP 0x400001f0 /* SWAP*/
#define XT_DUP 0x400001ec /* DUP*/
#define XT_DROP 0x400001e8 /* DROP*/
#define XT_SP_21 0x400001e4 /* SP!*/
#define XT_SP_40 0x400001e0 /* SP@*/
#define XT__3ER 0x400001dc /* >R*/
#define XT_R_40 0x400001d8 /* R@*/
#define XT_R_3E 0x400001d4 /* R>*/
#define XT_RP_21 0x400001d0 /* RP!*/
#define XT_RP_40 0x400001cc /* RP@*/
#define XT_C_21 0x400001c8 /* C!*/
#define XT_C_40 0x400001c4 /* C@*/
#define XT__40 0x400001c0 /* @*/
#define XT__21 0x400001bc /* !*/
#define XT_branch 0x400001b8 /* branch*/
#define XT__3Fbranch 0x400001b4 /* ?branch*/
#define XT_next 0x400001b0 /* next*/
#define XT_DOES_3E 0x400001ac /* DOES>*/
#define XT_doLIT 0x400001a8 /* doLIT*/
#define XT__21IO 0x400001a4 /* !IO*/
#define XT_TX_21 0x400001a0 /* TX!*/
#define XT__3FRX 0x4000019c /* ?RX*/
#define XT_EXECUTE 0x40000198 /* EXECUTE*/
#define XT_EXIT 0x40000194 /* EXIT*/
#define XT_BYE 0x40000190 /* BYE*/
#define XT_MS 0x4000018c /* MS*/
#define XT__3ENAME 0x40000188 /* >NAME*/
#define XT_find 0x4000017c /* find*/
#define XT_ALIGNED 0x40000178 /* ALIGNED*/
#define XT_tokenCreate 0x40000170 /* tokenCreate*/
#define XT_tokenVar 0x40000168 /* tokenVar*/
#define XT_tokenUser 0x40000160 /* tokenUser*/
#define XT_tokenDoList 0x40000158 /* tokenDoList*/
#define XT_tokenNextVal 0x40000150 /* tokenNextVal*/
#define XT_tokenVocabulary 0x40000148 /* tokenVocabulary*/
#define XT_BL 0x40000140 /* BL*/
#define XT_BYTEMASK 0x40000138 /* BYTEMASK*/
#define XT_IMED 0x40000130 /* IMED*/
#define XT_COMP 0x40000128 /* COMP*/
#define XT_TIB0 0x40000120 /* TIB0*/
#define XT_CELLMASK 0x40000118 /* CELLMASK*/
#define XT_CELLbits 0x40000110 /* CELLbits*/
#define XT_CELLL 0x40000108 /* CELLL*/
#define XT_FORTH 0x40000100 /* FORTH*/
/* === Function tokens === */
#define F_tokenVocabulary 1
#define F_tokenNextVal 2
#define F_tokenDoList 3
#define F_tokenUser 4
#define F_tokenVar 5
#define F_tokenCreate 6
#define F_ALIGNED 7
#define F_jsFind 8
#define F_OVERT 9
#define F_dollarCommaN 10
#define F_ToNAME 11
#define F_MS 12
#define F_BYE 13
#define F_EXIT 14
#define F_EXECUTE 15
#define F_QRX 16
#define F_TXbang 17
#define F_bangIO 18
#define F_doLIT 19
#define F_DOES 20
#define F_next 21
#define F_qBranch 22
#define F_branch 23
#define F_store 24
#define F_fetch 25
#define F_cFetch 26
#define F_cStore 27
#define F_RPat 28
#define F_RPbang 29
#define F_Rfrom 30
#define F_Rat 31
#define F_toR 32
#define F_SPat 33
#define F_SPbang 34
#define F_DROP 35
#define F_DUP 36
#define F_SWAP 37
#define F_OVER 38
#define F_less0 39
#define F_AND 40
#define F_OR 41
#define F_XOR 42
#define F_UMplus 43
#define F_userAreaInit 44
#define F_userAreaSave 45
#define F_PARSE 46
#define F_TOKEN 47
#define F_NUMBERQ 48
#define F_dCOMPILE 49
#define F_dINTERPRET 50
#define F_openBracket 51
#define F_closeBracket 52
#define F_colon 53
#define F_semicolon 54
#define F_tick 55
#define F_debugNA 56
#define F_testing3 57
#define F_Fbreak 58
#define F_debugPrintTIB 59
#define F_TEST 60
/* === Function table - maps tokens to functions === */
extern void tokenVocabulary();
extern void tokenNextVal();
extern void tokenDoList();
extern void tokenUser();
extern void tokenVar();
extern void tokenCreate();
extern void ALIGNED();
extern void jsFind();
extern void ToNAME();
extern void MS();
extern void BYE();
extern void EXIT();
extern void EXECUTE();
extern void QRX();
extern void TXbang();
extern void bangIO();
extern void doLIT();
extern void DOES();
extern void next();
extern void qBranch();
extern void branch();
extern void store();
extern void fetch();
extern void cFetch();
extern void cStore();
extern void RPat();
extern void RPbang();
extern void Rfrom();
extern void Rat();
extern void toR();
extern void SPat();
extern void SPbang();
extern void DROP();
extern void DUP();
extern void SWAP();
extern void OVER();
extern void less0();
extern void AND();
extern void OR();
extern void XOR();
extern void UMplus();
extern void userAreaInit();
extern void userAreaSave();
extern void debugNA();
extern void testing3();
extern void Fbreak();
extern void debugPrintTIB();
extern void TEST();
void (* const f[FUNCTIONSLENGTH])() PROGMEM = {
0, tokenVocabulary, tokenNextVal, tokenDoList, 
tokenUser, tokenVar, tokenCreate, ALIGNED, 
/* find */ jsFind, 0, 0, /* >NAME */ ToNAME, 
MS, BYE, EXIT, EXECUTE, 
/* ?RX */ QRX, /* TX! */ TXbang, /* !IO */ bangIO, doLIT, 
/* DOES> */ DOES, next, /* ?branch */ qBranch, branch, 
/* ! */ store, /* @ */ fetch, /* C@ */ cFetch, /* C! */ cStore, 
/* RP@ */ RPat, /* RP! */ RPbang, /* R> */ Rfrom, /* R@ */ Rat, 
/* >R */ toR, /* SP@ */ SPat, /* SP! */ SPbang, DROP, 
DUP, SWAP, OVER, /* 0< */ less0, 
AND, OR, XOR, /* UM+ */ UMplus, 
userAreaInit, userAreaSave, 0, 0, 
0, 0, 0, 0, 
0, 0, 0, 0, 
debugNA, testing3, Fbreak, debugPrintTIB, 
TEST,  0 };
const CELLTYPE rom[ROMCELLS] PROGMEM = {
/* ==== USER VARIABLE SAVE AREA ==== */
/* 0x40000000 undefined */ 0,
/* 0x40000004 undefined */ 0,
/* 0x40000008 undefined */ 0,
/* 0x4000000c undefined */ 0,
/* 0x40000010 SP0 */ 0x9cc0,
/* 0x40000014 RP0 */ 0x9ee0,
/* 0x40000018 '?KEY */ XT__3FRX,
/* 0x4000001c 'EMIT */ XT_TX_21,
/* 0x40000020 'EXPECT */ XT_accept,
/* 0x40000024 'TAP */ 0,
/* 0x40000028 'ECHO */ XT_TX_21,
/* 0x4000002c 'PROMPT */ 0,
/* 0x40000030 BASE */ 0xa,
/* 0x40000034 temp */ 0x20,
/* 0x40000038 SPAN */ 0,
/* 0x4000003c >IN */ 0xd,
/* 0x40000040 #TIB */ 0x3a,
/* 0x40000044 undefined */ TIB0,
/* 0x40000048 CSP */ 0,
/* 0x4000004c 'EVAL */ XT__24INTERPRET,
/* 0x40000050 'NUMBER */ XT_NUMBER_3F,
/* 0x40000054 HLD */ 0,
/* 0x40000058 HANDLER */ 0,
/* 0x4000005c CONTEXT */ 4,
/* 0x40000060 undefined */ 0,
/* 0x40000064 undefined */ 0,
/* 0x40000068 undefined */ 0,
/* 0x4000006c undefined */ 0,
/* 0x40000070 undefined */ 0,
/* 0x40000074 undefined */ 0,
/* 0x40000078 undefined */ 0,
/* 0x4000007c undefined */ 0,
/* 0x40000080 CURRENT */ 4,
/* 0x40000084 undefined */ 4,
/* 0x40000088 CP */ 0xc,
/* 0x4000008c NP */ 0x9ac0,
/* 0x40000090 LAST */ 0x40002f28,
/* 0x40000094 VP */ 0,
/* 0x40000098 unused */ 0,
/* 0x4000009c unused */ 0,
/* 0x400000a0 unused */ 0,
/* 0x400000a4 unused */ 0,
/* 0x400000a8 unused */ 0,
/* 0x400000ac unused */ 0,
/* 0x400000b0 unused */ 0,
/* 0x400000b4 unused */ 0,
/* 0x400000b8 unused */ 0,
/* 0x400000bc unused */ 0,
/* 0x400000c0 unused */ 0,
/* 0x400000c4 unused */ 0,
/* 0x400000c8 unused */ 0,
/* 0x400000cc unused */ 0,
/* 0x400000d0 unused */ 0,
/* 0x400000d4 unused */ 0,
/* 0x400000d8 unused */ 0,
/* 0x400000dc unused */ 0,
/* 0x400000e0 unused */ 0,
/* 0x400000e4 unused */ 0,
/* 0x400000e8 unused */ 0,
/* 0x400000ec unused */ 0,
/* 0x400000f0 unused */ 0,
/* 0x400000f4 unused */ 0,
/* 0x400000f8 unused */ 0,
/* 0x400000fc unused */ 0,
/* ==== CODE DICTIONARY ==== */
/* 0x40000100: FORTH */ F_tokenVocabulary, 4, 
/* 0x40000108: CELLL */ F_tokenNextVal, 4, 
/* 0x40000110: CELLbits */ F_tokenNextVal, 0x20, 
/* 0x40000118: CELLMASK */ F_tokenNextVal, 0xffffff1f, 
/* 0x40000120: TIB0 */ F_tokenNextVal, TIB0, 
/* 0x40000128: COMP */ F_tokenNextVal, 0x40, 
/* 0x40000130: IMED */ F_tokenNextVal, 0x80, 
/* 0x40000138: BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x40000140: BL */ F_tokenNextVal, 0x20, 
/* 0x40000148: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x40000150: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x40000158: tokenDoList */ F_tokenNextVal, 3, 
/* 0x40000160: tokenUser */ F_tokenNextVal, 4, 
/* 0x40000168: tokenVar */ F_tokenNextVal, 5, 
/* 0x40000170: tokenCreate */ F_tokenNextVal, 6, 
/* 0x40000178: ALIGNED */ F_ALIGNED, 
/* 0x4000017c: find */ F_jsFind, 
/* 0x40000180: OVERT */ F_OVERT, 
/* 0x40000184: $,n */ F_dollarCommaN, 
/* 0x40000188: >NAME */ F_ToNAME, 
/* 0x4000018c: MS */ F_MS, 
/* 0x40000190: BYE */ F_BYE, 
/* 0x40000194: EXIT */ F_EXIT, 
/* 0x40000198: EXECUTE */ F_EXECUTE, 
/* 0x4000019c: ?RX */ F_QRX, 
/* 0x400001a0: TX! */ F_TXbang, 
/* 0x400001a4: !IO */ F_bangIO, 
/* 0x400001a8: doLIT */ F_doLIT, 
/* 0x400001ac: DOES> */ F_DOES, 
/* 0x400001b0: next */ F_next, 
/* 0x400001b4: ?branch */ F_qBranch, 
/* 0x400001b8: branch */ F_branch, 
/* 0x400001bc: ! */ F_store, 
/* 0x400001c0: @ */ F_fetch, 
/* 0x400001c4: C@ */ F_cFetch, 
/* 0x400001c8: C! */ F_cStore, 
/* 0x400001cc: RP@ */ F_RPat, 
/* 0x400001d0: RP! */ F_RPbang, 
/* 0x400001d4: R> */ F_Rfrom, 
/* 0x400001d8: R@ */ F_Rat, 
/* 0x400001dc: >R */ F_toR, 
/* 0x400001e0: SP@ */ F_SPat, 
/* 0x400001e4: SP! */ F_SPbang, 
/* 0x400001e8: DROP */ F_DROP, 
/* 0x400001ec: DUP */ F_DUP, 
/* 0x400001f0: SWAP */ F_SWAP, 
/* 0x400001f4: OVER */ F_OVER, 
/* 0x400001f8: 0< */ F_less0, 
/* 0x400001fc: AND */ F_AND, 
/* 0x40000200: OR */ F_OR, 
/* 0x40000204: XOR */ F_XOR, 
/* 0x40000208: UM+ */ F_UMplus, 
/* 0x4000020c: userAreaInit */ F_userAreaInit, 
/* 0x40000210: userAreaSave */ F_userAreaSave, 
/* 0x40000214: PARSE */ F_PARSE, 
/* 0x40000218: TOKEN */ F_TOKEN, 
/* 0x4000021c: NUMBER? */ F_NUMBERQ, 
/* 0x40000220: $COMPILE */ F_dCOMPILE, 
/* 0x40000224: $INTERPRET */ F_dINTERPRET, 
/* 0x40000228: [ */ F_openBracket, 
/* 0x4000022c: ] */ F_closeBracket, 
/* 0x40000230: : */ F_colon, 
/* 0x40000234: ; */ F_semicolon, 
/* 0x40000238: ' */ F_tick, 
/* 0x4000023c: debugNA */ F_debugNA, 
/* 0x40000240: testing3 */ F_testing3, 
/* 0x40000244: Fbreak */ F_Fbreak, 
/* 0x40000248: debugPrintTIB */ F_debugPrintTIB, 
/* 0x4000024c: TEST */ F_TEST, 
/* 0x40000250: SP0 */ F_tokenUser, 4, 
/* 0x40000258: RP0 */ F_tokenUser, 5, 
/* 0x40000260: '?KEY */ F_tokenUser, 6, 
/* 0x40000268: 'EMIT */ F_tokenUser, 7, 
/* 0x40000270: 'EXPECT */ F_tokenUser, 8, 
/* 0x40000278: 'TAP */ F_tokenUser, 9, 
/* 0x40000280: 'ECHO */ F_tokenUser, 0xa, 
/* 0x40000288: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x40000290: BASE */ F_tokenUser, 0xc, 
/* 0x40000298: temp */ F_tokenUser, 0xd, 
/* 0x400002a0: SPAN */ F_tokenUser, 0xe, 
/* 0x400002a8: >IN */ F_tokenUser, 0xf, 
/* 0x400002b0: #TIB */ F_tokenUser, 0x10, 
/* 0x400002b8: CSP */ F_tokenUser, 0x12, 
/* 0x400002c0: 'EVAL */ F_tokenUser, 0x13, 
/* 0x400002c8: 'NUMBER */ F_tokenUser, 0x14, 
/* 0x400002d0: HLD */ F_tokenUser, 0x15, 
/* 0x400002d8: HANDLER */ F_tokenUser, 0x16, 
/* 0x400002e0: CONTEXT */ F_tokenUser, 0x17, 
/* 0x400002e8: CURRENT */ F_tokenUser, 0x20, 
/* 0x400002f0: CP */ F_tokenUser, 0x22, 
/* 0x400002f8: NP */ F_tokenUser, 0x23, 
/* 0x40000300: LAST */ F_tokenUser, 0x24, 
/* 0x40000308: VP */ F_tokenUser, 0x25, 
/* 0x40000310: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x40000320: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x40000344: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x40000354: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x40000364: ( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_2DROP, XT_EXIT, 
/* 0x4000037c: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x40000394: \T */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x400003ac: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x400003bc: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x400003cc: CELL+ */ F_tokenDoList, XT_CELLL, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x400003e0: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x40000404: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x40000414: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x40000434: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLIT, XT__2C, XT_EXIT, 
/* 0x40000448: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x4000046c: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x4000047c: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x40000488: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x40000494: >MARK */ F_tokenDoList, XT_HERE, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x400004ac: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x400004c0: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x400004d4: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x400004e0: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x400004f4: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000508: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x4000051c: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x40000530: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x40000544: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000554: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000560: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x40000578: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x4000058c: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x4000059c: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x400005ac: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0x14, XT_DUP, XT_EXIT, 
/* 0x400005c4: ROT */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x400005dc: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x400005f4: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x40000604: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x40000614: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x4000063c: INVERT */ F_tokenDoList, XT_doLIT, 0xffffffff, XT_XOR, XT_EXIT, 
/* 0x40000650: NEGATE */ F_tokenDoList, XT_INVERT, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x40000668: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLIT, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40000690: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x400006a0: ABS */ F_tokenDoList, XT_DUP, XT_0_3C, XT__3Fbranch, XT_ABS + 0x18, XT_NEGATE, XT_EXIT, 
/* 0x400006bc: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0x1c, XT_doLIT, 0, XT_branch, XT_0_3D + 0x24, XT_doLIT, 0xffffffff, XT_EXIT, 
/* 0x400006e4: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0x1c, XT_doLIT, 0, XT_EXIT, XT_doLIT, 0xffffffff, XT_EXIT, 
/* 0x4000070c: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x24, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x4000073c: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x2c, XT_2DROP, XT_doLIT, 0xffffffff, XT_branch, XT_ud_3C + 0x30, XT_U_3C, XT_EXIT, 
/* 0x40000770: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x24, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x400007a0: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0x18, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x400007c0: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0x1c, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x400007e4: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x40000804: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0xb0, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x9c, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x94, XT__3ER, XT_DROP, XT_doLIT, 1, XT__2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x98, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x28, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLIT, 0xffffffff, XT_DUP, XT_EXIT, 
/* 0x400008cc: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x2c, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x48, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x68, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x40000938: /MOD */ F_tokenDoList, XT_OVER, XT_0_3C, XT_SWAP, XT_M_2FMOD, XT_EXIT, 
/* 0x40000950: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x40000960: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000970: UM* */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x60, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x60, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x20, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x400009e4: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x400009f4: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x34, XT_DNEGATE, XT_EXIT, 
/* 0x40000a2c: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x40000a44: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000a54: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x40000a64: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x40000a74: >CHAR */ F_tokenDoList, XT_doLIT, 0x7f, XT_AND, XT_DUP, XT_doLIT, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x38, XT_DROP, XT_doLIT, 0x5f, XT_EXIT, 
/* 0x40000ab0: DEPTH */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x40000ad4: PICK */ F_tokenDoList, XT_doLIT, 1, XT__2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x40000af8: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x40000b18: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x40000b34: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x40000b50: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0x1c, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x40000b74: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x38, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x3c, XT__2C, XT_EXIT, 
/* 0x40000bb4: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x40000bd0: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x30, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x34, XT_CREATE, XT_EXIT, 
/* 0x40000c08: PAD */ F_tokenDoList, XT_HERE, XT_doLIT, 0x50, XT__2B, XT_EXIT, 
/* 0x40000c20: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x40000c34: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x20, XT_EXECUTE, XT_branch, XT__40EXECUTE + 0x24, XT_Fbreak, XT_EXIT, 
/* 0x40000c5c: COUNT */ F_tokenDoList, XT_DUP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x40000c7c: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x40, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_doLIT, 1, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_CMOVE + 0x10, XT_2DROP, XT_EXIT, 
/* 0x40000ccc: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x2c, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_next, XT_FILL + 0x18, XT_2DROP, XT_EXIT, 
/* 0x40000d08: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x44, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x44, XT_R_3E, XT_doLIT, 1, XT__2B, XT_EXIT, XT_next, XT__2DTRAILING + 0x10, XT_doLIT, 0, XT_EXIT, 
/* 0x40000d60: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLIT, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLIT, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x40000dcc: DIGIT */ F_tokenDoList, XT_doLIT, 9, XT_OVER, XT__3C, XT_doLIT, 7, XT_AND, XT__2B, XT_doLIT, 0x30, XT__2B, XT_EXIT, 
/* 0x40000e00: EXTRACT */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_UM_2FMOD, XT_SWAP, XT_DIGIT, XT_EXIT, 
/* 0x40000e20: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x40000e34: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_doLIT, 1, XT__2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x40000e60: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x40000e78: #S */ F_tokenDoList, XT__23, XT_DUP, XT__3Fbranch, XT__23S + 0x1c, XT_branch, XT__23S + 4, XT_EXIT, 
/* 0x40000e98: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0x1c, XT_doLIT, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x40000eb8: #> */ F_tokenDoList, XT_DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x40000ed8: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x40000ee8: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x40000ef8: CHARS */ F_tokenDoList, XT_SWAP, XT_doLIT, 0, XT_MAX, XT__3ER, XT_branch, XT_CHARS + 0x28, XT_DUP, XT_EMIT, XT_next, XT_CHARS + 0x20, XT_DROP, XT_EXIT, 
/* 0x40000f30: SPACES */ F_tokenDoList, XT_BL, XT_CHARS, XT_EXIT, 
/* 0x40000f40: TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT_TYPE + 0x28, XT_DUP, XT_C_40, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT_TYPE + 0x10, XT_DROP, XT_EXIT, 
/* 0x40000f78: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x40000f88: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x40000fb0: HEX */ F_tokenDoList, XT_doLIT, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x40000fc8: DECIMAL */ F_tokenDoList, XT_doLIT, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x40000fe0: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x40001004: U.R */ F_tokenDoList, XT__3ER, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x40001030: U. */ F_tokenDoList, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x4000104c: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLIT, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x28, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x40001084: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x40001094: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLIT, 0x30, XT__2D, XT_doLIT, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x4c, XT_doLIT, 7, XT__2D, XT_DUP, XT_doLIT, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x400010f0: NUMBER? */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_doLIT, 0, XT_OVER, XT_COUNT, XT_OVER, XT_C_40, XT_doLIT, 0x24, XT__3D, XT__3Fbranch, XT_NUMBER_3F + 0x60, XT_HEX, XT_SWAP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_doLIT, 1, XT__2D, XT_OVER, XT_C_40, XT_doLIT, 0x2d, XT__3D, XT__3ER, XT_SWAP, XT_R_40, XT__2D, XT_SWAP, XT_R_40, XT__2B, XT__3FDUP, XT__3Fbranch, 0x40001224, XT_doLIT, 1, XT__2D, XT__3ER, XT_DUP, XT__3ER, XT_C_40, XT_BASE, XT__40, XT_DIGIT_3F, XT__3Fbranch, 0x40001208, XT_SWAP, XT_BASE, XT__40, XT__2A, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_NUMBER_3F + 0xac, XT_DROP, XT_R_40, XT__3Fbranch, 0x400011fc, XT_NEGATE, XT_SWAP, XT_branch, 0x40001220, XT_R_3E, XT_R_3E, XT_2DROP, XT_2DROP, XT_doLIT, 0, XT_DUP, XT_R_3E, XT_2DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x4000123c: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x4000124c: KEY */ F_tokenDoList, XT_doLIT, 0, XT_MS, XT_doLIT, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 0xc, XT_NIP, XT_EXIT, 
/* 0x40001278: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x28, XT_2DROP, XT_KEY, XT_doLIT, 0xd, XT__3D, XT_EXIT, 
/* 0x400012a4: PACE */ F_tokenDoList, XT_doLIT, 0xb, XT_EMIT, XT_EXIT, 
/* 0x400012b8: CR */ F_tokenDoList, XT_doLIT, 0xd, XT_EMIT, XT_doLIT, 0xa, XT_EMIT, XT_EXIT, 
/* 0x400012d8: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40001304: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x40001310: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x40001320: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x40001330: parse */ F_tokenDoList, XT_temp, XT__21, XT_OVER, XT__3ER, XT_DUP, XT__3Fbranch, 0x40001464, XT_doLIT, 1, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x98, XT__3ER, XT_BL, XT_OVER, XT_C_40, XT__2D, XT_0_3C, XT_INVERT, XT__3Fbranch, XT_parse + 0x94, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x48, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_DUP, XT_EXIT, XT_R_3E, XT_OVER, XT_SWAP, XT__3ER, XT_temp, XT__40, XT_OVER, XT_C_40, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0xd4, XT_0_3C, XT__3Fbranch, 0x40001430, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0xa4, XT_DUP, XT__3ER, XT_branch, 0x4000144c, XT_R_3E, XT_DROP, XT_DUP, XT_doLIT, 1, XT__2B, XT__3ER, XT_OVER, XT__2D, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, XT_OVER, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x40001474: PARSE */ F_tokenDoList, XT__3ER, XT_TIB, XT__3EIN, XT__40, XT__2B, XT__23TIB, XT__40, XT__3EIN, XT__40, XT__2D, XT_R_3E, XT_parse, XT__3EIN, XT__2B_21, XT_EXIT, 
/* 0x400014b4: CHAR */ F_tokenDoList, XT_BL, XT_PARSE, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x400014cc: CTRL */ F_tokenDoList, XT_CHAR, XT_doLIT, 0x1f, XT_AND, XT_EXIT, 
/* 0x400014e4: .( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x400014fc: TOKEN */ F_tokenDoList, XT_BL, XT_PARSE, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x40001530: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x40001544: NAME> */ F_tokenDoList, XT_doLIT, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x40001560: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x54, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x54, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 0x10, XT_doLIT, 0, XT_EXIT, 
/* 0x400015c8: FORTHfind */ F_tokenDoList, XT_SWAP, XT_DUP, XT_C_40, XT_CELLL, XT__2F, XT_temp, XT__21, XT_DUP, XT__40, XT__3ER, XT_CELL_2B, XT_SWAP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTHfind + 0x94, XT_DUP, XT__40, XT_doLIT, 0xffffff1f, XT_AND, XT_R_40, XT_XOR, XT__3Fbranch, XT_FORTHfind + 0x7c, XT_CELL_2B, XT_doLIT, 0xffffffff, XT_branch, XT_FORTHfind + 0x8c, XT_CELL_2B, XT_temp, XT__40, XT_SAME_3F, XT_branch, XT_FORTHfind + 0xac, XT_R_3E, XT_DROP, XT_SWAP, XT_CELL_2D, XT_SWAP, XT_EXIT, XT__3Fbranch, XT_FORTHfind + 0xc4, XT_CELL_2D, XT_CELL_2D, XT_branch, XT_FORTHfind + 0x34, XT_R_3E, XT_DROP, XT_NIP, XT_CELL_2D, XT_DUP, XT_NAME_3E, XT_SWAP, XT_EXIT, 
/* 0x400016ac: NAME? */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_NAME_3F + 0x20, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT_DUP, XT__3ER, XT__40, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x60, XT_find, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x24, XT_R_3E, XT_DROP, XT_EXIT, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x40001720: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x4c, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40001778: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x400017a0: crlf? */ F_tokenDoList, XT_DUP, XT_doLIT, 0xa, XT__3D, XT_SWAP, XT_doLIT, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x400017cc: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x58, XT_doLIT, 8, XT__3D, XT_OVER, XT_doLIT, 0x7f, XT__3D, XT_OR, XT__3Fbranch, XT_kTAP + 0x50, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x54, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x40001834: accept */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_accept + 0x60, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLIT, 0x5f, XT_U_3C, XT__3Fbranch, XT_accept + 0x50, XT_TAP, XT_branch, XT_accept + 0x58, XT__27TAP, XT__40EXECUTE, XT_branch, XT_accept + 0x10, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x400018a4: EXPECT */ F_tokenDoList, XT__27EXPECT, XT__40EXECUTE, XT_SPAN, XT__21, XT_DROP, XT_EXIT, 
/* 0x400018c0: QUERY */ F_tokenDoList, XT_TIB, XT_doLIT, 0x50, XT__27EXPECT, XT__40EXECUTE, XT__23TIB, XT__21, XT_DROP, XT_doLIT, 0, XT__3EIN, XT__21, XT_EXIT, 
/* 0x400018f8: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x40001940: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x40, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40001984: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x40001990: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x400019a0: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0x14, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x400019c0: $," */ F_tokenDoList, XT_doLIT, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x400019e8: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x400019fc: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001a10: $INTERPRET */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24INTERPRET + 0x40, XT_C_40, XT_doLIT, 0x40, XT_AND, XT_abort_22, 0x6d6f630c, 0x656c6970, 0x4c4e4f20, 0x59, XT_EXECUTE, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24INTERPRET + 0x54, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40001a6c: .OK */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__40, XT__3D, XT__3Fbranch, XT__2EOK + 0x28, XT__2E_22_7C, 0x6b6f2003, XT_CR, XT_EXIT, 
/* 0x40001a9c: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x646e7509, 0x6c667265, 0x776f, XT_EXIT, 
/* 0x40001abc: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x2c, XT__27EVAL, XT__40EXECUTE, XT__3FSTACK, XT_branch, XT_EVAL + 4, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x40001af8: [ */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x40001b10: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_TIB0, XT__23TIB, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x40001b34: XIO */ F_tokenDoList, XT_doLIT, XT_accept, XT__27EXPECT, XT__21, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x40001b64: FILE */ F_tokenDoList, XT_doLIT, XT_PACE, XT_doLIT, XT_DROP, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x40001b88: HAND */ F_tokenDoList, XT_doLIT, XT__2EOK, XT_doLIT, XT_EMIT, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x40001bac: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x40001bbc: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x40001bd8: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x40001be8: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x54, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLIT, 0x5e, XT_CHARS, XT_CR, XT__2E_24, XT__2E_22_7C, 0x203f2003, XT_PRESET, XT_EXIT, 
/* 0x40001c44: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLIT, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x14, XT_CONSOLE, XT_quitError, XT_branch, XT_QUIT + 0x10, XT_EXIT, 
/* 0x40001c84: quit1 */ F_tokenDoList, XT_doLIT, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x24, XT_quitError, XT__5B, XT_EXIT, 
/* 0x40001cac: ' */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, XT__27 + 0x18, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40001ccc: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x40001cdc: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x24, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x28, XT_ALLOT, XT_EXIT, 
/* 0x40001d08: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x40001d18: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3E, XT__2C, XT_EXIT, 
/* 0x40001d30: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001d44: S" */ F_tokenDoList, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001d58: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x28, XT__2E_22_7C, 0x65722007, 0x20666544, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x40001d88: $,n */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, XT__24_2Cn + 0x60, XT__3FUNIQUE, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, XT__24_22_7C, 0x6d616e04, 0x65, XT_THROW, XT_EXIT, 
/* 0x40001dfc: $COMPILE */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24COMPILE + 0x3c, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, XT__24COMPILE + 0x34, XT_EXECUTE, XT_branch, XT__24COMPILE + 0x38, XT__2C, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24COMPILE + 0x54, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40001e58: OVERT */ F_tokenDoList, XT_LAST, XT__40, XT_CURRENT, XT__40, XT__21, XT_EXIT, 
/* 0x40001e74: ; */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 
/* 0x40001e8c: ] */ F_tokenDoList, XT_doLIT, XT__24COMPILE, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x40001ea4: : */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x40001ec0: USER */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenUser, XT__2C, XT_EXIT, 
/* 0x40001edc: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x40001f00: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x40001f10: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x28, XT_CREATE, XT_branch, XT_vCREATE + 0x34, XT_tokenVar, XT_create, XT__2C, XT_EXIT, 
/* 0x40001f48: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLIT, 0, XT_v_2C, XT_EXIT, 
/* 0x40001f60: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x40001f80: _TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT__5FTYPE + 0x2c, XT_DUP, XT_C_40, XT__3ECHAR, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT__5FTYPE + 0x10, XT_DROP, XT_EXIT, 
/* 0x40001fbc: dm+ */ F_tokenDoList, XT_OVER, XT_doLIT, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x44, XT_DUP, XT_C_40, XT_doLIT, 3, XT_U_2ER, XT_doLIT, 1, XT__2B, XT_next, XT_dm_2B + 0x24, XT_EXIT, 
/* 0x4000200c: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLIT, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLIT, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLIT, 2, XT_SPACES, XT__5FTYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x6c, XT_next, XT_DUMP + 0x24, XT_branch, XT_DUMP + 0x74, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x40002094: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x24, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0x18, XT__2E_22_7C, 0x733c2004, 0x70, XT_EXIT, 
/* 0x400020d0: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x400020f4: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x4000210c: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x40002120: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x6174730b, 0x64206b63, 0x68747065, XT_EXIT, 
/* 0x40002148: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x24, XT_COUNT, XT_BYTEMASK, XT_AND, XT__5FTYPE, XT_EXIT, XT__2E_22_7C, 0x6f6e7b08, 0x656d614e, 0x7d, XT_EXIT, 
/* 0x40002180: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x40, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 0x10, XT_DROP, XT_EXIT, 
/* 0x400021c4: FORTH>NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x6c, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x50, XT_2DUP, XT_NAME_3E, XT_XOR, XT__3Fbranch, XT_FORTH_3ENAME + 0x50, XT_CELL_2D, XT_branch, XT_FORTH_3ENAME + 0x20, XT_NIP, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 8, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x40002240: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0xd0, XT__2E_22_7C, 0x203a02, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x54, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0xb0, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLIT, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLIT, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0xa8, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0xbc, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x38, XT_branch, XT_SEE + 0xec, XT__2E_22_7C, 0x746f4e14, 0x6c6f6320, 0x64206e6f, 0x6e696665, 0x6f697469, 0x6e, XT_DROP, XT_EXIT, 
/* 0x40002334: VER */ F_tokenNextVal, 0xe, 
/* 0x4000233c: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x6265770a, 0x54524f46, 0x562048, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT__3C_23, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x400023ac: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x400023bc: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x400023dc: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x400023e8: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 4, XT_EXIT, 
/* 0x40002418: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x40002430: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002470: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400024b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400024f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002530: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002570: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400025b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400025f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002630: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002670: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400026b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400026f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002730: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002770: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400027b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400027f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002830: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002870: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400028b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400028f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002930: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002970: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400029b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400029f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002a30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002a70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002ab0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002af0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002b30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002b70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002bb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002bf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002c30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002c70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002cb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002cf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002d30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002d70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002db0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002df0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002e30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002e70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002eb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40002ef0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0x6573750c, 0x65724172, 0x76615361, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x40002f20 WARM */ XT_WARM, 0x40002f38, 0x52415704, 0x4d,
/* 0x40002f30 COLD */ XT_COLD, 0x40002f48, 0x4c4f4304, 0x44,
/* 0x40002f40 'BOOT */ XT__27BOOT, 0x40002f58, 0x4f422705, 0x544f,
/* 0x40002f50 EMPTY */ XT_EMPTY, 0x40002f68, 0x504d4505, 0x5954,
/* 0x40002f60 hi */ XT_hi, 0x40002f74, 0x696842,
/* 0x40002f6c version */ XT_version, 0x40002f84, 0x72657607, 0x6e6f6973,
/* 0x40002f7c VER */ XT_VER, 0x40002f90, 0x52455603,
/* 0x40002f88 SEE */ XT_SEE, 0x40002f9c, 0x45455303,
/* 0x40002f94 FORTH>NAME */ XT_FORTH_3ENAME, 0x40002fb0, 0x524f460a, 0x4e3e4854, 0x454d41,
/* 0x40002fa8 WORDS */ XT_WORDS, 0x40002fc0, 0x524f5705, 0x5344,
/* 0x40002fb8 .ID */ XT__2EID, 0x40002fcc, 0x44492e03,
/* 0x40002fc4 ?CSP */ XT__3FCSP, 0x40002fdc, 0x53433f04, 0x50,
/* 0x40002fd4 !CSP */ XT__21CSP, 0x40002fec, 0x53432104, 0x50,
/* 0x40002fe4 .FREE */ XT__2EFREE, 0x40002ffc, 0x52462e05, 0x4545,
/* 0x40002ff4 .BASE */ XT__2EBASE, 0x4000300c, 0x41422e05, 0x4553,
/* 0x40003004 .S */ XT__2ES, 0x40003018, 0x532e02,
/* 0x40003010 DUMP */ XT_DUMP, 0x40003028, 0x4d554404, 0x50,
/* 0x40003020 dm+ */ XT_dm_2B, 0x40003034, 0x2b6d6403,
/* 0x4000302c _TYPE */ XT__5FTYPE, 0x40003044, 0x59545f05, 0x4550,
/* 0x4000303c CONSTANT */ XT_CONSTANT, 0x40003058, 0x4e4f4308, 0x4e415453, 0x54,
/* 0x40003050 VARIABLE */ XT_VARIABLE, 0x4000306c, 0x52415608, 0x4c424149, 0x45,
/* 0x40003064 vCREATE */ XT_vCREATE, 0x4000307c, 0x52437607, 0x45544145,
/* 0x40003074 CREATE */ XT_CREATE, 0x4000308c, 0x45524306, 0x455441,
/* 0x40003084 create */ XT_create, 0x4000309c, 0x65726306, 0x657461,
/* 0x40003094 USER */ XT_USER, 0x400030ac, 0x45535504, 0x52,
/* 0x400030a4 : */ XT__3A, 0x400030b8, 0x3a01,
/* 0x400030b0 ] */ XT__5D, 0x400030c4, 0x5d01,
/* 0x400030bc ; */ XT__3B, 0x400030d0, 0x3bc1,
/* 0x400030c8 OVERT */ XT_OVERT, 0x400030e0, 0x45564f05, 0x5452,
/* 0x400030d8 $COMPILE */ XT__24COMPILE, 0x400030f4, 0x4f432408, 0x4c49504d, 0x45,
/* 0x400030ec $,n */ XT__24_2Cn, 0x40003100, 0x6e2c2403,
/* 0x400030f8 ?UNIQUE */ XT__3FUNIQUE, 0x40003110, 0x4e553f07, 0x45555149,
/* 0x40003108 S" */ XT_S_22, 0x4000311c, 0x225382,
/* 0x40003114 $" */ XT__24_22, 0x40003128, 0x222482,
/* 0x40003120 RECURSE */ XT_RECURSE, 0x40003138, 0x43455287, 0x45535255,
/* 0x40003130 [COMPILE] */ XT__5BCOMPILE_5D, 0x4000314c, 0x4f435b89, 0x4c49504d, 0x5d45,
/* 0x40003144 vALLOT */ XT_vALLOT, 0x4000315c, 0x4c417606, 0x544f4c,
/* 0x40003154 ALLOT */ XT_ALLOT, 0x4000316c, 0x4c4c4105, 0x544f,
/* 0x40003164 ' */ XT__27, 0x40003178, 0x2701,
/* 0x40003170 quit1 */ XT_quit1, 0x40003188, 0x69757105, 0x3174,
/* 0x40003180 QUIT */ XT_QUIT, 0x40003198, 0x49555104, 0x54,
/* 0x40003190 quitError */ XT_quitError, 0x400031ac, 0x69757109, 0x72724574, 0x726f,
/* 0x400031a4 que */ XT_que, 0x400031b8, 0x65757103,
/* 0x400031b0 CONSOLE */ XT_CONSOLE, 0x400031c8, 0x4e4f4307, 0x454c4f53,
/* 0x400031c0 I/O */ XT_I_2FO, 0x400031d4, 0x4f2f4903,
/* 0x400031cc HAND */ XT_HAND, 0x400031e4, 0x4e414804, 0x44,
/* 0x400031dc FILE */ XT_FILE, 0x400031f4, 0x4c494604, 0x45,
/* 0x400031ec XIO */ XT_XIO, 0x40003200, 0x4f495803,
/* 0x400031f8 PRESET */ XT_PRESET, 0x40003210, 0x45525006, 0x544553,
/* 0x40003208 [ */ XT__5B, 0x4000321c, 0x5b81,
/* 0x40003214 EVAL */ XT_EVAL, 0x4000322c, 0x41564504, 0x4c,
/* 0x40003224 ?STACK */ XT__3FSTACK, 0x4000323c, 0x54533f06, 0x4b4341,
/* 0x40003234 .OK */ XT__2EOK, 0x40003248, 0x4b4f2e03,
/* 0x40003240 $INTERPRET */ XT__24INTERPRET, 0x4000325c, 0x4e49240a, 0x50524554, 0x544552,
/* 0x40003254 ." */ XT__2E_22, 0x40003268, 0x222e82,
/* 0x40003260 ABORT" */ XT_ABORT_22, 0x40003278, 0x4f424186, 0x225452,
/* 0x40003270 $," */ XT__24_2C_22, 0x40003284, 0x222c2403,
/* 0x4000327c abort" */ XT_abort_22, 0x40003294, 0x6f626146, 0x227472,
/* 0x4000328c ABORT */ XT_ABORT, 0x400032a4, 0x4f424105, 0x5452,
/* 0x4000329c NULL$ */ XT_NULL_24, 0x400032b4, 0x4c554e05, 0x244c,
/* 0x400032ac THROW */ XT_THROW, 0x400032c4, 0x52485405, 0x574f,
/* 0x400032bc CATCH */ XT_CATCH, 0x400032d4, 0x54414305, 0x4843,
/* 0x400032cc QUERY */ XT_QUERY, 0x400032e4, 0x45555105, 0x5952,
/* 0x400032dc EXPECT */ XT_EXPECT, 0x400032f4, 0x50584506, 0x544345,
/* 0x400032ec accept */ XT_accept, 0x40003304, 0x63636106, 0x747065,
/* 0x400032fc kTAP */ XT_kTAP, 0x40003314, 0x41546b04, 0x50,
/* 0x4000330c crlf? */ XT_crlf_3F, 0x40003324, 0x6c726305, 0x3f66,
/* 0x4000331c TAP */ XT_TAP, 0x40003330, 0x50415403,
/* 0x40003328 ^H */ XT__5EH, 0x4000333c, 0x485e02,
/* 0x40003334 NAME? */ XT_NAME_3F, 0x4000334c, 0x4d414e05, 0x3f45,
/* 0x40003344 FORTHfind */ XT_FORTHfind, 0x40003360, 0x524f4609, 0x69664854, 0x646e,
/* 0x40003358 SAME? */ XT_SAME_3F, 0x40003370, 0x4d415305, 0x3f45,
/* 0x40003368 NAME> */ XT_NAME_3E, 0x40003380, 0x4d414e05, 0x3e45,
/* 0x40003378 WORD */ XT_WORD, 0x40003390, 0x524f5704, 0x44,
/* 0x40003388 TOKEN */ XT_TOKEN, 0x400033a0, 0x4b4f5405, 0x4e45,
/* 0x40003398 .( */ XT__2E_28, 0x400033ac, 0x282e82,
/* 0x400033a4 CTRL */ XT_CTRL, 0x400033bc, 0x52544304, 0x4c,
/* 0x400033b4 CHAR */ XT_CHAR, 0x400033cc, 0x41484304, 0x52,
/* 0x400033c4 PARSE */ XT_PARSE, 0x400033dc, 0x52415005, 0x4553,
/* 0x400033d4 parse */ XT_parse, 0x400033ec, 0x72617005, 0x6573,
/* 0x400033e4 S"| */ XT_S_22_7C, 0x400033f8, 0x7c225303,
/* 0x400033f0 ."| */ XT__2E_22_7C, 0x40003404, 0x7c222e03,
/* 0x400033fc $"| */ XT__24_22_7C, 0x40003410, 0x7c222403,
/* 0x40003408 do$ */ XT_do_24, 0x4000341c, 0x246f6403,
/* 0x40003414 CR */ XT_CR, 0x40003428, 0x524302,
/* 0x40003420 PACE */ XT_PACE, 0x40003438, 0x43415004, 0x45,
/* 0x40003430 NUF? */ XT_NUF_3F, 0x40003448, 0x46554e04, 0x3f,
/* 0x40003440 KEY */ XT_KEY, 0x40003454, 0x59454b03,
/* 0x4000344c ?KEY */ XT__3FKEY, 0x40003464, 0x454b3f04, 0x59,
/* 0x4000345c NUMBER? */ XT_NUMBER_3F, 0x40003474, 0x4d554e07, 0x3f524542,
/* 0x4000346c DIGIT? */ XT_DIGIT_3F, 0x40003484, 0x47494406, 0x3f5449,
/* 0x4000347c ? */ XT__3F, 0x40003490, 0x3f01,
/* 0x40003488 . */ XT__2E, 0x4000349c, 0x2e01,
/* 0x40003494 U. */ XT_U_2E, 0x400034a8, 0x2e5502,
/* 0x400034a0 U.R */ XT_U_2ER, 0x400034b4, 0x522e5503,
/* 0x400034ac .R */ XT__2ER, 0x400034c0, 0x522e02,
/* 0x400034b8 DECIMAL */ XT_DECIMAL, 0x400034d0, 0x43454407, 0x4c414d49,
/* 0x400034c8 HEX */ XT_HEX, 0x400034dc, 0x58454803,
/* 0x400034d4 str */ XT_str, 0x400034e8, 0x72747303,
/* 0x400034e0 .$ */ XT__2E_24, 0x400034f4, 0x242e02,
/* 0x400034ec TYPE */ XT_TYPE, 0x40003504, 0x50595404, 0x45,
/* 0x400034fc SPACES */ XT_SPACES, 0x40003514, 0x41505306, 0x534543,
/* 0x4000350c CHARS */ XT_CHARS, 0x40003524, 0x41484305, 0x5352,
/* 0x4000351c SPACE */ XT_SPACE, 0x40003534, 0x41505305, 0x4543,
/* 0x4000352c EMIT */ XT_EMIT, 0x40003544, 0x494d4504, 0x54,
/* 0x4000353c #> */ XT__23_3E, 0x40003550, 0x3e2302,
/* 0x40003548 SIGN */ XT_SIGN, 0x40003560, 0x47495304, 0x4e,
/* 0x40003558 #S */ XT__23S, 0x4000356c, 0x532302,
/* 0x40003564 # */ XT__23, 0x40003578, 0x2301,
/* 0x40003570 HOLD */ XT_HOLD, 0x40003588, 0x4c4f4804, 0x44,
/* 0x40003580 <# */ XT__3C_23, 0x40003594, 0x233c02,
/* 0x4000358c EXTRACT */ XT_EXTRACT, 0x400035a4, 0x54584507, 0x54434152,
/* 0x4000359c DIGIT */ XT_DIGIT, 0x400035b4, 0x47494405, 0x5449,
/* 0x400035ac PACK$ */ XT_PACK_24, 0x400035c4, 0x43415005, 0x244b,
/* 0x400035bc -TRAILING */ XT__2DTRAILING, 0x400035d8, 0x52542d09, 0x494c4941, 0x474e,
/* 0x400035d0 FILL */ XT_FILL, 0x400035e8, 0x4c494604, 0x4c,
/* 0x400035e0 CMOVE */ XT_CMOVE, 0x400035f8, 0x4f4d4305, 0x4556,
/* 0x400035f0 COUNT */ XT_COUNT, 0x40003608, 0x554f4305, 0x544e,
/* 0x40003600 @EXECUTE */ XT__40EXECUTE, 0x4000361c, 0x58454008, 0x54554345, 0x45,
/* 0x40003614 TIB */ XT_TIB, 0x40003628, 0x42495403,
/* 0x40003620 PAD */ XT_PAD, 0x40003634, 0x44415003,
/* 0x4000362c vCREATE */ XT_vCREATE, 0x40003644, 0x52437607, 0x45544145,
/* 0x4000363c vALIGN */ XT_vALIGN, 0x40003654, 0x4c417606, 0x4e4749,
/* 0x4000364c v, */ XT_v_2C, 0x40003660, 0x2c7602,
/* 0x40003658 vHERE */ XT_vHERE, 0x40003670, 0x45487605, 0x4552,
/* 0x40003668 2@ */ XT_2_40, 0x4000367c, 0x403202,
/* 0x40003674 2! */ XT_2_21, 0x40003688, 0x213202,
/* 0x40003680 +! */ XT__2B_21, 0x40003694, 0x212b02,
/* 0x4000368c PICK */ XT_PICK, 0x400036a4, 0x43495004, 0x4b,
/* 0x4000369c DEPTH */ XT_DEPTH, 0x400036b4, 0x50454405, 0x4854,
/* 0x400036ac >CHAR */ XT__3ECHAR, 0x400036c4, 0x48433e05, 0x5241,
/* 0x400036bc CELLS */ XT_CELLS, 0x400036d4, 0x4c454305, 0x534c,
/* 0x400036cc CELL- */ XT_CELL_2D, 0x400036e4, 0x4c454305, 0x2d4c,
/* 0x400036dc * / */ XT__2A_2F, 0x400036f0, 0x2f2a02,
/* 0x400036e8 * /MOD */ XT__2A_2FMOD, 0x40003700, 0x4d2f2a05, 0x444f,
/* 0x400036f8 M* */ XT_M_2A, 0x4000370c, 0x2a4d02,
/* 0x40003704 * */ XT__2A, 0x40003718, 0x2a01,
/* 0x40003710 UM* */ XT_UM_2A, 0x40003724, 0x2a4d5503,
/* 0x4000371c / */ XT__2F, 0x40003730, 0x2f01,
/* 0x40003728 MOD */ XT_MOD, 0x4000373c, 0x444f4d03,
/* 0x40003734 /MOD */ XT__2FMOD, 0x4000374c, 0x4f4d2f04, 0x44,
/* 0x40003744 M/MOD */ XT_M_2FMOD, 0x4000375c, 0x4d2f4d05, 0x444f,
/* 0x40003754 UM/MOD */ XT_UM_2FMOD, 0x4000376c, 0x2f4d5506, 0x444f4d,
/* 0x40003764 WITHIN */ XT_WITHIN, 0x4000377c, 0x54495706, 0x4e4948,
/* 0x40003774 MIN */ XT_MIN, 0x40003788, 0x4e494d03,
/* 0x40003780 MAX */ XT_MAX, 0x40003794, 0x58414d03,
/* 0x4000378c < */ XT__3C, 0x400037a0, 0x3c01,
/* 0x40003798 ud< */ XT_ud_3C, 0x400037ac, 0x3c647503,
/* 0x400037a4 U< */ XT_U_3C, 0x400037b8, 0x3c5502,
/* 0x400037b0 = */ XT__3D, 0x400037c4, 0x3d01,
/* 0x400037bc 0= */ XT_0_3D, 0x400037d0, 0x3d3002,
/* 0x400037c8 ABS */ XT_ABS, 0x400037dc, 0x53424103,
/* 0x400037d4 - */ XT__2D, 0x400037e8, 0x2d01,
/* 0x400037e0 DNEGATE */ XT_DNEGATE, 0x400037f8, 0x454e4407, 0x45544147,
/* 0x400037f0 NEGATE */ XT_NEGATE, 0x40003808, 0x47454e06, 0x455441,
/* 0x40003800 INVERT */ XT_INVERT, 0x40003818, 0x564e4906, 0x545245,
/* 0x40003810 D+ */ XT_D_2B, 0x40003824, 0x2b4402,
/* 0x4000381c + */ XT__2B, 0x40003830, 0x2b01,
/* 0x40003828 2DUP */ XT_2DUP, 0x40003840, 0x55443204, 0x50,
/* 0x40003838 -ROT */ XT__2DROT, 0x40003850, 0x4f522d04, 0x54,
/* 0x40003848 ROT */ XT_ROT, 0x4000385c, 0x544f5203,
/* 0x40003854 ?DUP */ XT__3FDUP, 0x4000386c, 0x55443f04, 0x50,
/* 0x40003864 WHILE */ XT_WHILE, 0x4000387c, 0x49485785, 0x454c,
/* 0x40003874 WHEN */ XT_WHEN, 0x4000388c, 0x45485784, 0x4e,
/* 0x40003884 ELSE */ XT_ELSE, 0x4000389c, 0x534c4584, 0x45,
/* 0x40003894 AFT */ XT_AFT, 0x400038a8, 0x54464183,
/* 0x400038a0 THEN */ XT_THEN, 0x400038b8, 0x45485484, 0x4e,
/* 0x400038b0 REPEAT */ XT_REPEAT, 0x400038c8, 0x50455286, 0x544145,
/* 0x400038c0 AHEAD */ XT_AHEAD, 0x400038d8, 0x45484185, 0x4441,
/* 0x400038d0 IF */ XT_IF, 0x400038e4, 0x464982,
/* 0x400038dc AGAIN */ XT_AGAIN, 0x400038f4, 0x41474185, 0x4e49,
/* 0x400038ec UNTIL */ XT_UNTIL, 0x40003904, 0x544e5585, 0x4c49,
/* 0x400038fc NEXT */ XT_NEXT, 0x40003914, 0x58454e84, 0x54,
/* 0x4000390c BEGIN */ XT_BEGIN, 0x40003924, 0x47454285, 0x4e49,
/* 0x4000391c FOR */ XT_FOR, 0x40003930, 0x524f4683,
/* 0x40003928 >RESOLVE */ XT__3ERESOLVE, 0x40003944, 0x45523e08, 0x564c4f53, 0x45,
/* 0x4000393c >MARK */ XT__3EMARK, 0x40003954, 0x414d3e05, 0x4b52,
/* 0x4000394c <RESOLVE */ XT__3CRESOLVE, 0x40003968, 0x45523c08, 0x564c4f53, 0x45,
/* 0x40003960 <MARK */ XT__3CMARK, 0x40003978, 0x414d3c05, 0x4b52,
/* 0x40003970 CREATE */ XT_CREATE, 0x40003988, 0x45524306, 0x455441,
/* 0x40003980 create */ XT_create, 0x40003998, 0x65726306, 0x657461,
/* 0x40003990 LITERAL */ XT_LITERAL, 0x400039a8, 0x54494c87, 0x4c415245,
/* 0x400039a0 COMPILE */ XT_COMPILE, 0x400039b8, 0x4d4f4347, 0x454c4950,
/* 0x400039b0 [COMPILE] */ XT__5BCOMPILE_5D, 0x400039cc, 0x4f435b89, 0x4c49504d, 0x5d45,
/* 0x400039c4 , */ XT__2C, 0x400039d8, 0x2c01,
/* 0x400039d0 CELL+ */ XT_CELL_2B, 0x400039e8, 0x4c454305, 0x2b4c,
/* 0x400039e0 HERE */ XT_HERE, 0x400039f8, 0x52454804, 0x45,
/* 0x400039f0 NIP */ XT_NIP, 0x40003a04, 0x50494e03,
/* 0x400039fc \T */ XT__5CT, 0x40003a10, 0x545c02,
/* 0x40003a08 \ */ XT__5C, 0x40003a1c, 0x5c81,
/* 0x40003a14 ( */ XT__28, 0x40003a28, 0x2881,
/* 0x40003a20 IMMEDIATE */ XT_IMMEDIATE, 0x40003a3c, 0x4d4d4909, 0x41494445, 0x4554,
/* 0x40003a34 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x40003a54, 0x4d4f430c, 0x454c4950, 0x4c4e4f2d, 0x59,
/* 0x40003a4c setHeaderBits */ XT_setHeaderBits, 0x40003a6c, 0x7465730d, 0x64616548, 0x69427265, 0x7374,
/* 0x40003a64 2DROP */ XT_2DROP, 0x40003a7c, 0x52443205, 0x504f,
/* 0x40003a74 VP */ XT_VP, 0x40003a88, 0x505602,
/* 0x40003a80 LAST */ XT_LAST, 0x40003a98, 0x53414c04, 0x54,
/* 0x40003a90 NP */ XT_NP, 0x40003aa4, 0x504e02,
/* 0x40003a9c CP */ XT_CP, 0x40003ab0, 0x504302,
/* 0x40003aa8 CURRENT */ XT_CURRENT, 0x40003ac0, 0x52554307, 0x544e4552,
/* 0x40003ab8 CONTEXT */ XT_CONTEXT, 0x40003ad0, 0x4e4f4307, 0x54584554,
/* 0x40003ac8 HANDLER */ XT_HANDLER, 0x40003ae0, 0x4e414807, 0x52454c44,
/* 0x40003ad8 HLD */ XT_HLD, 0x40003aec, 0x444c4803,
/* 0x40003ae4 'NUMBER */ XT__27NUMBER, 0x40003afc, 0x554e2707, 0x5245424d,
/* 0x40003af4 'EVAL */ XT__27EVAL, 0x40003b0c, 0x56452705, 0x4c41,
/* 0x40003b04 CSP */ XT_CSP, 0x40003b18, 0x50534303,
/* 0x40003b10 #TIB */ XT__23TIB, 0x40003b28, 0x49542304, 0x42,
/* 0x40003b20 >IN */ XT__3EIN, 0x40003b34, 0x4e493e03,
/* 0x40003b2c SPAN */ XT_SPAN, 0x40003b44, 0x41505304, 0x4e,
/* 0x40003b3c temp */ XT_temp, 0x40003b54, 0x6d657404, 0x70,
/* 0x40003b4c BASE */ XT_BASE, 0x40003b64, 0x53414204, 0x45,
/* 0x40003b5c 'PROMPT */ XT__27PROMPT, 0x40003b74, 0x52502707, 0x54504d4f,
/* 0x40003b6c 'ECHO */ XT__27ECHO, 0x40003b84, 0x43452705, 0x4f48,
/* 0x40003b7c 'TAP */ XT__27TAP, 0x40003b94, 0x41542704, 0x50,
/* 0x40003b8c 'EXPECT */ XT__27EXPECT, 0x40003ba4, 0x58452707, 0x54434550,
/* 0x40003b9c 'EMIT */ XT__27EMIT, 0x40003bb4, 0x4d452705, 0x5449,
/* 0x40003bac '?KEY */ XT__27_3FKEY, 0x40003bc4, 0x4b3f2705, 0x5945,
/* 0x40003bbc RP0 */ XT_RP0, 0x40003bd0, 0x30505203,
/* 0x40003bc8 SP0 */ XT_SP0, 0x40003bdc, 0x30505303,
/* 0x40003bd4 TEST */ XT_TEST, 0x40003bec, 0x53455404, 0x54,
/* 0x40003be4 debugPrintTIB */ XT_debugPrintTIB, 0x40003c04, 0x6265640d, 0x72506775, 0x54746e69, 0x4249,
/* 0x40003bfc Fbreak */ XT_Fbreak, 0x40003c14, 0x72624606, 0x6b6165,
/* 0x40003c0c testing3 */ XT_testing3, 0x40003c28, 0x73657408, 0x676e6974, 0x33,
/* 0x40003c20 debugNA */ XT_debugNA, 0x40003c38, 0x62656407, 0x414e6775,
/* 0x40003c30 ' */ XT__27, 0x40003c44, 0x2701,
/* 0x40003c3c ; */ XT__3B, 0x40003c50, 0x3b81,
/* 0x40003c48 : */ XT__3A, 0x40003c5c, 0x3a01,
/* 0x40003c54 ] */ XT__5D, 0x40003c68, 0x5d01,
/* 0x40003c60 [ */ XT__5B, 0x40003c74, 0x5b81,
/* 0x40003c6c $INTERPRET */ XT__24INTERPRET, 0x40003c88, 0x4e49240a, 0x50524554, 0x544552,
/* 0x40003c80 $COMPILE */ XT__24COMPILE, 0x40003c9c, 0x4f432408, 0x4c49504d, 0x45,
/* 0x40003c94 NUMBER? */ XT_NUMBER_3F, 0x40003cac, 0x4d554e07, 0x3f524542,
/* 0x40003ca4 TOKEN */ XT_TOKEN, 0x40003cbc, 0x4b4f5405, 0x4e45,
/* 0x40003cb4 PARSE */ XT_PARSE, 0x40003ccc, 0x52415005, 0x4553,
/* 0x40003cc4 userAreaSave */ XT_userAreaSave, 0x40003ce4, 0x6573750c, 0x65724172, 0x76615361, 0x65,
/* 0x40003cdc userAreaInit */ XT_userAreaInit, 0x40003cfc, 0x6573750c, 0x65724172, 0x696e4961, 0x74,
/* 0x40003cf4 UM+ */ XT_UM_2B, 0x40003d08, 0x2b4d5503,
/* 0x40003d00 XOR */ XT_XOR, 0x40003d14, 0x524f5803,
/* 0x40003d0c OR */ XT_OR, 0x40003d20, 0x524f02,
/* 0x40003d18 AND */ XT_AND, 0x40003d2c, 0x444e4103,
/* 0x40003d24 0< */ XT_0_3C, 0x40003d38, 0x3c3002,
/* 0x40003d30 OVER */ XT_OVER, 0x40003d48, 0x45564f04, 0x52,
/* 0x40003d40 SWAP */ XT_SWAP, 0x40003d58, 0x41575304, 0x50,
/* 0x40003d50 DUP */ XT_DUP, 0x40003d64, 0x50554403,
/* 0x40003d5c DROP */ XT_DROP, 0x40003d74, 0x4f524404, 0x50,
/* 0x40003d6c SP! */ XT_SP_21, 0x40003d80, 0x21505303,
/* 0x40003d78 SP@ */ XT_SP_40, 0x40003d8c, 0x40505303,
/* 0x40003d84 >R */ XT__3ER, 0x40003d98, 0x523e02,
/* 0x40003d90 R@ */ XT_R_40, 0x40003da4, 0x405202,
/* 0x40003d9c R> */ XT_R_3E, 0x40003db0, 0x3e5202,
/* 0x40003da8 RP! */ XT_RP_21, 0x40003dbc, 0x21505203,
/* 0x40003db4 RP@ */ XT_RP_40, 0x40003dc8, 0x40505203,
/* 0x40003dc0 C! */ XT_C_21, 0x40003dd4, 0x214302,
/* 0x40003dcc C@ */ XT_C_40, 0x40003de0, 0x404302,
/* 0x40003dd8 @ */ XT__40, 0x40003dec, 0x4001,
/* 0x40003de4 ! */ XT__21, 0x40003df8, 0x2101,
/* 0x40003df0 branch */ XT_branch, 0x40003e08, 0x61726206, 0x68636e,
/* 0x40003e00 ?branch */ XT__3Fbranch, 0x40003e18, 0x72623f07, 0x68636e61,
/* 0x40003e10 next */ XT_next, 0x40003e28, 0x78656e04, 0x74,
/* 0x40003e20 DOES> */ XT_DOES_3E, 0x40003e38, 0x454f4405, 0x3e53,
/* 0x40003e30 doLIT */ XT_doLIT, 0x40003e48, 0x4c6f6405, 0x5449,
/* 0x40003e40 !IO */ XT__21IO, 0x40003e54, 0x4f492103,
/* 0x40003e4c TX! */ XT_TX_21, 0x40003e60, 0x21585403,
/* 0x40003e58 ?RX */ XT__3FRX, 0x40003e6c, 0x58523f03,
/* 0x40003e64 EXECUTE */ XT_EXECUTE, 0x40003e7c, 0x45584507, 0x45545543,
/* 0x40003e74 EXIT */ XT_EXIT, 0x40003e8c, 0x49584504, 0x54,
/* 0x40003e84 BYE */ XT_BYE, 0x40003e98, 0x45594203,
/* 0x40003e90 MS */ XT_MS, 0x40003ea4, 0x534d02,
/* 0x40003e9c >NAME */ XT__3ENAME, 0x40003eb4, 0x414e3e05, 0x454d,
/* 0x40003eac $,n */ XT__24_2Cn, 0x40003ec0, 0x6e2c2403,
/* 0x40003eb8 OVERT */ XT_OVERT, 0x40003ed0, 0x45564f05, 0x5452,
/* 0x40003ec8 find */ XT_find, 0x40003ee0, 0x6e696604, 0x64,
/* 0x40003ed8 ALIGNED */ XT_ALIGNED, 0x40003ef0, 0x494c4107, 0x44454e47,
/* 0x40003ee8 tokenCreate */ XT_tokenCreate, 0x40003f04, 0x6b6f740b, 0x72436e65, 0x65746165,
/* 0x40003efc tokenVar */ XT_tokenVar, 0x40003f18, 0x6b6f7408, 0x61566e65, 0x72,
/* 0x40003f10 tokenUser */ XT_tokenUser, 0x40003f2c, 0x6b6f7409, 0x73556e65, 0x7265,
/* 0x40003f24 tokenDoList */ XT_tokenDoList, 0x40003f40, 0x6b6f740b, 0x6f446e65, 0x7473694c,
/* 0x40003f38 tokenNextVal */ XT_tokenNextVal, 0x40003f58, 0x6b6f740c, 0x654e6e65, 0x61567478, 0x6c,
/* 0x40003f50 tokenVocabulary */ XT_tokenVocabulary, 0x40003f70, 0x6b6f740f, 0x6f566e65, 0x75626163, 0x7972616c,
/* 0x40003f68 BL */ XT_BL, 0x40003f7c, 0x4c4202,
/* 0x40003f74 BYTEMASK */ XT_BYTEMASK, 0x40003f90, 0x54594208, 0x53414d45, 0x4b,
/* 0x40003f88 IMED */ XT_IMED, 0x40003fa0, 0x454d4904, 0x44,
/* 0x40003f98 COMP */ XT_COMP, 0x40003fb0, 0x4d4f4304, 0x50,
/* 0x40003fa8 TIB0 */ XT_TIB0, 0x40003fc0, 0x42495404, 0x30,
/* 0x40003fb8 CELLMASK */ XT_CELLMASK, 0x40003fd4, 0x4c454308, 0x53414d4c, 0x4b,
/* 0x40003fcc CELLbits */ XT_CELLbits, 0x40003fe8, 0x4c454308, 0x7469624c, 0x73,
/* 0x40003fe0 CELLL */ XT_CELLL, 0x40003ff8, 0x4c454305, 0x4c4c,
/* 0x40003ff0 FORTH */ XT_FORTH, 0, 0x524f4605, 0x4854,
};
// === End of Arduino source from dictionary === 
