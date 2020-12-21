#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x523e /* WARM*/
#define XT_COLD 0x5226 /* COLD*/
#define XT__27BOOT 0x5220 /* 'BOOT*/
#define XT_EMPTY 0x5210 /* EMPTY*/
#define XT_hi 0x5208 /* hi*/
#define XT_version 0x51ca /* version*/
#define XT_VER 0x51c6 /* VER*/
#define XT_SEE 0x5140 /* SEE*/
#define XT_FORTH_3ENAME 0x5102 /* FORTH>NAME*/
#define XT_WORDS 0x50e0 /* WORDS*/
#define XT__2EID 0x50c0 /* .ID*/
#define XT__3FCSP 0x50a6 /* ?CSP*/
#define XT__21CSP 0x509c /* !CSP*/
#define XT__2EFREE 0x5090 /* .FREE*/
#define XT__2EBASE 0x507e /* .BASE*/
#define XT__2ES 0x505e /* .S*/
#define XT_DUMP 0x501a /* DUMP*/
#define XT_dm_2B 0x4ff2 /* dm+*/
#define XT__5FTYPE 0x4fd4 /* _TYPE*/
#define XT_CONSTANT 0x4fc4 /* CONSTANT*/
#define XT_VARIABLE 0x4fb8 /* VARIABLE*/
#define XT_vCREATE 0x4f9c /* vCREATE*/
#define XT_CREATE 0x4f94 /* CREATE*/
#define XT_create 0x4f82 /* create*/
#define XT_USER 0x4f74 /* USER*/
#define XT__3A 0x4f66 /* :*/
#define XT__5D 0x4f5a /* ]*/
#define XT__3B 0x4f4e /* ;*/
#define XT_OVERT 0x4f40 /* OVERT*/
#define XT__24COMPILE 0x4f12 /* $COMPILE*/
#define XT__24_2Cn 0x4ed6 /* $,n*/
#define XT__3FUNIQUE 0x4eba /* ?UNIQUE*/
#define XT_S_22 0x4eb0 /* S"*/
#define XT__24_22 0x4ea6 /* $"*/
#define XT_RECURSE 0x4e9a /* RECURSE*/
#define XT__5BCOMPILE_5D 0x4e92 /* [COMPILE]*/
#define XT_vALLOT 0x4e7c /* vALLOT*/
#define XT_ALLOT 0x4e74 /* ALLOT*/
#define XT__27 0x4e64 /* '*/
#define XT_quit1 0x4e50 /* quit1*/
#define XT_QUIT 0x4e30 /* QUIT*/
#define XT_quitError 0x4e00 /* quitError*/
#define XT_que 0x4df8 /* que*/
#define XT_CONSOLE 0x4dea /* CONSOLE*/
#define XT_I_2FO 0x4de2 /* I/O*/
#define XT_HAND 0x4dd0 /* HAND*/
#define XT_FILE 0x4dbe /* FILE*/
#define XT_XIO 0x4da6 /* XIO*/
#define XT_PRESET 0x4d94 /* PRESET*/
#define XT__5B 0x4d88 /* [*/
#define XT_EVAL 0x4d6a /* EVAL*/
#define XT__3FSTACK 0x4d56 /* ?STACK*/
#define XT__2EOK 0x4d3c /* .OK*/
#define XT__24INTERPRET 0x4d08 /* $INTERPRET*/
#define XT__2E_22 0x4cfe /* ."*/
#define XT_ABORT_22 0x4cf4 /* ABORT"*/
#define XT__24_2C_22 0x4ce0 /* $,"*/
#define XT_abort_22 0x4cd0 /* abort"*/
#define XT_ABORT 0x4cc8 /* ABORT*/
#define XT_NULL_24 0x4cc2 /* NULL$*/
#define XT_THROW 0x4ca0 /* THROW*/
#define XT_CATCH 0x4c7c /* CATCH*/
#define XT_QUERY 0x4c60 /* QUERY*/
#define XT_EXPECT 0x4c52 /* EXPECT*/
#define XT_accept 0x4c1a /* accept*/
#define XT_kTAP 0x4be6 /* kTAP*/
#define XT_crlf_3F 0x4bd0 /* crlf?*/
#define XT_TAP 0x4bbc /* TAP*/
#define XT__5EH 0x4b90 /* ^H*/
#define XT_NAME_3F 0x4b56 /* NAME?*/
#define XT_FORTHfind 0x4ae4 /* FORTHfind*/
#define XT_SAME_3F 0x4ab0 /* SAME?*/
#define XT_NAME_3E 0x4aa2 /* NAME>*/
#define XT_WORD 0x4a98 /* WORD*/
#define XT_TOKEN 0x4a7e /* TOKEN*/
#define XT__2E_28 0x4a72 /* .(*/
#define XT_CTRL 0x4a66 /* CTRL*/
#define XT_CHAR 0x4a5a /* CHAR*/
#define XT_PARSE 0x4a3a /* PARSE*/
#define XT_parse 0x4998 /* parse*/
#define XT_S_22_7C 0x4990 /* S"|*/
#define XT__2E_22_7C 0x4988 /* ."|*/
#define XT__24_22_7C 0x4982 /* $"|*/
#define XT_do_24 0x496c /* do$*/
#define XT_CR 0x495c /* CR*/
#define XT_PACE 0x4952 /* PACE*/
#define XT_NUF_3F 0x493c /* NUF?*/
#define XT_KEY 0x4926 /* KEY*/
#define XT__3FKEY 0x491e /* ?KEY*/
#define XT_NUMBER_3F 0x4878 /* NUMBER?*/
#define XT_DIGIT_3F 0x484a /* DIGIT?*/
#define XT__3F 0x4842 /* ?*/
#define XT__2E 0x4826 /* .*/
#define XT_U_2E 0x4818 /* U.*/
#define XT_U_2ER 0x4802 /* U.R*/
#define XT__2ER 0x47f0 /* .R*/
#define XT_DECIMAL 0x47e4 /* DECIMAL*/
#define XT_HEX 0x47d8 /* HEX*/
#define XT_str 0x47c4 /* str*/
#define XT__2E_24 0x47bc /* .$*/
#define XT_TYPE 0x47a0 /* TYPE*/
#define XT_SPACES 0x4798 /* SPACES*/
#define XT_CHARS 0x477c /* CHARS*/
#define XT_SPACE 0x4774 /* SPACE*/
#define XT_EMIT 0x476c /* EMIT*/
#define XT__23_3E 0x475c /* #>*/
#define XT_SIGN 0x474c /* SIGN*/
#define XT__23S 0x473c /* #S*/
#define XT__23 0x4730 /* #*/
#define XT_HOLD 0x471a /* HOLD*/
#define XT__3C_23 0x4710 /* <#*/
#define XT_EXTRACT 0x4700 /* EXTRACT*/
#define XT_DIGIT 0x46e6 /* DIGIT*/
#define XT_PACK_24 0x46b0 /* PACK$*/
#define XT__2DTRAILING 0x4684 /* -TRAILING*/
#define XT_FILL 0x4666 /* FILL*/
#define XT_CMOVE 0x463e /* CMOVE*/
#define XT_COUNT 0x462e /* COUNT*/
#define XT__40EXECUTE 0x461a /* @EXECUTE*/
#define XT_TIB 0x4610 /* TIB*/
#define XT_PAD 0x4604 /* PAD*/
#define XT_vCREATE 0x45e8 /* vCREATE*/
#define XT_vALIGN 0x45da /* vALIGN*/
#define XT_v_2C 0x45ba /* v,*/
#define XT_vHERE 0x45a8 /* vHERE*/
#define XT_2_40 0x459a /* 2@*/
#define XT_2_21 0x458c /* 2!*/
#define XT__2B_21 0x457c /* +!*/
#define XT_PICK 0x456a /* PICK*/
#define XT_DEPTH 0x4558 /* DEPTH*/
#define XT__3ECHAR 0x453a /* >CHAR*/
#define XT_CELLS 0x4532 /* CELLS*/
#define XT_CELL_2D 0x452a /* CELL-*/
#define XT__2A_2F 0x4522 /* * /*/
#define XT__2A_2FMOD 0x4516 /* * /MOD*/
#define XT_M_2A 0x44fa /* M**/
#define XT__2A 0x44f2 /* **/
#define XT_UM_2A 0x44b8 /* UM**/
#define XT__2F 0x44b0 /* /*/
#define XT_MOD 0x44a8 /* MOD*/
#define XT__2FMOD 0x449c /* /MOD*/
#define XT_M_2FMOD 0x4466 /* M/MOD*/
#define XT_UM_2FMOD 0x4402 /* UM/MOD*/
#define XT_WITHIN 0x43f2 /* WITHIN*/
#define XT_MIN 0x43e0 /* MIN*/
#define XT_MAX 0x43d0 /* MAX*/
#define XT__3C 0x43b8 /* <*/
#define XT_ud_3C 0x439e /* ud<*/
#define XT_U_3C 0x4386 /* U<*/
#define XT__3D 0x4372 /* =*/
#define XT_0_3D 0x435e /* 0=*/
#define XT_ABS 0x4350 /* ABS*/
#define XT__2D 0x4348 /* -*/
#define XT_DNEGATE 0x4334 /* DNEGATE*/
#define XT_NEGATE 0x4328 /* NEGATE*/
#define XT_INVERT 0x431e /* INVERT*/
#define XT_D_2B 0x430a /* D+*/
#define XT__2B 0x4302 /* +*/
#define XT_2DUP 0x42fa /* 2DUP*/
#define XT__2DROT 0x42ee /* -ROT*/
#define XT_ROT 0x42e2 /* ROT*/
#define XT__3FDUP 0x42d6 /* ?DUP*/
#define XT_WHILE 0x42ce /* WHILE*/
#define XT_WHEN 0x42c6 /* WHEN*/
#define XT_ELSE 0x42bc /* ELSE*/
#define XT_AFT 0x42b0 /* AFT*/
#define XT_THEN 0x42aa /* THEN*/
#define XT_REPEAT 0x42a2 /* REPEAT*/
#define XT_AHEAD 0x4298 /* AHEAD*/
#define XT_IF 0x428e /* IF*/
#define XT_AGAIN 0x4284 /* AGAIN*/
#define XT_UNTIL 0x427a /* UNTIL*/
#define XT_NEXT 0x4270 /* NEXT*/
#define XT_BEGIN 0x426a /* BEGIN*/
#define XT_FOR 0x4260 /* FOR*/
#define XT__3ERESOLVE 0x4256 /* >RESOLVE*/
#define XT__3EMARK 0x424a /* >MARK*/
#define XT__3CRESOLVE 0x4244 /* <RESOLVE*/
#define XT__3CMARK 0x423e /* <MARK*/
#define XT_CREATE 0x4236 /* CREATE*/
#define XT_create 0x4224 /* create*/
#define XT_LITERAL 0x421a /* LITERAL*/
#define XT_COMPILE 0x420a /* COMPILE*/
#define XT__5BCOMPILE_5D 0x4202 /* [COMPILE]*/
#define XT__2C 0x41f0 /* ,*/
#define XT_CELL_2B 0x41e6 /* CELL+*/
#define XT_HERE 0x41de /* HERE*/
#define XT_NIP 0x41d6 /* NIP*/
#define XT__5CT 0x41ca /* \T*/
#define XT__5C 0x41be /* \*/
#define XT__28 0x41b2 /* (*/
#define XT_IMMEDIATE 0x41aa /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x41a2 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x4190 /* setHeaderBits*/
#define XT_2DROP 0x4188 /* 2DROP*/
#define XT_VP 0x4184 /* VP*/
#define XT_LAST 0x4180 /* LAST*/
#define XT_NP 0x417c /* NP*/
#define XT_CP 0x4178 /* CP*/
#define XT_CURRENT 0x4174 /* CURRENT*/
#define XT_CONTEXT 0x4170 /* CONTEXT*/
#define XT_HANDLER 0x416c /* HANDLER*/
#define XT_HLD 0x4168 /* HLD*/
#define XT__27NUMBER 0x4164 /* 'NUMBER*/
#define XT__27EVAL 0x4160 /* 'EVAL*/
#define XT_CSP 0x415c /* CSP*/
#define XT__23TIB 0x4158 /* #TIB*/
#define XT__3EIN 0x4154 /* >IN*/
#define XT_SPAN 0x4150 /* SPAN*/
#define XT_temp 0x414c /* temp*/
#define XT_BASE 0x4148 /* BASE*/
#define XT__27PROMPT 0x4144 /* 'PROMPT*/
#define XT__27ECHO 0x4140 /* 'ECHO*/
#define XT__27TAP 0x413c /* 'TAP*/
#define XT__27EXPECT 0x4138 /* 'EXPECT*/
#define XT__27EMIT 0x4134 /* 'EMIT*/
#define XT__27_3FKEY 0x4130 /* '?KEY*/
#define XT_RP0 0x412c /* RP0*/
#define XT_SP0 0x4128 /* SP0*/
#define XT_TEST 0x4126 /* TEST*/
#define XT_debugPrintTIB 0x4124 /* debugPrintTIB*/
#define XT_Fbreak 0x4122 /* Fbreak*/
#define XT_testing3 0x4120 /* testing3*/
#define XT_debugNA 0x411e /* debugNA*/
#define XT_userAreaSave 0x4108 /* userAreaSave*/
#define XT_userAreaInit 0x4106 /* userAreaInit*/
#define XT_UM_2B 0x4104 /* UM+*/
#define XT_XOR 0x4102 /* XOR*/
#define XT_OR 0x4100 /* OR*/
#define XT_AND 0x40fe /* AND*/
#define XT_0_3C 0x40fc /* 0<*/
#define XT_OVER 0x40fa /* OVER*/
#define XT_SWAP 0x40f8 /* SWAP*/
#define XT_DUP 0x40f6 /* DUP*/
#define XT_DROP 0x40f4 /* DROP*/
#define XT_SP_21 0x40f2 /* SP!*/
#define XT_SP_40 0x40f0 /* SP@*/
#define XT__3ER 0x40ee /* >R*/
#define XT_R_40 0x40ec /* R@*/
#define XT_R_3E 0x40ea /* R>*/
#define XT_RP_21 0x40e8 /* RP!*/
#define XT_RP_40 0x40e6 /* RP@*/
#define XT_C_21 0x40e4 /* C!*/
#define XT_C_40 0x40e2 /* C@*/
#define XT__40 0x40e0 /* @*/
#define XT__21 0x40de /* !*/
#define XT_branch 0x40dc /* branch*/
#define XT__3Fbranch 0x40da /* ?branch*/
#define XT_next 0x40d8 /* next*/
#define XT_DOES_3E 0x40d6 /* DOES>*/
#define XT_doLIT 0x40d4 /* doLIT*/
#define XT__21IO 0x40d2 /* !IO*/
#define XT_TX_21 0x40d0 /* TX!*/
#define XT__3FRX 0x40ce /* ?RX*/
#define XT_EXECUTE 0x40cc /* EXECUTE*/
#define XT_EXIT 0x40ca /* EXIT*/
#define XT_BYE 0x40c8 /* BYE*/
#define XT_MS 0x40c6 /* MS*/
#define XT__3ENAME 0x40c4 /* >NAME*/
#define XT_find 0x40be /* find*/
#define XT_ALIGNED 0x40bc /* ALIGNED*/
#define XT_tokenCreate 0x40b8 /* tokenCreate*/
#define XT_tokenVar 0x40b4 /* tokenVar*/
#define XT_tokenUser 0x40b0 /* tokenUser*/
#define XT_tokenDoList 0x40ac /* tokenDoList*/
#define XT_tokenNextVal 0x40a8 /* tokenNextVal*/
#define XT_tokenVocabulary 0x40a4 /* tokenVocabulary*/
#define XT_BL 0x40a0 /* BL*/
#define XT_BYTEMASK 0x409c /* BYTEMASK*/
#define XT_IMED 0x4098 /* IMED*/
#define XT_COMP 0x4094 /* COMP*/
#define XT_TIB0 0x4090 /* TIB0*/
#define XT_CELLMASK 0x408c /* CELLMASK*/
#define XT_CELLbits 0x4088 /* CELLbits*/
#define XT_CELLL 0x4084 /* CELLL*/
#define XT_FORTH 0x4080 /* FORTH*/
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
void (* const f[FUNCTIONSLENGTH])() = {
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
/* 0x4000 undefined */ 0,
/* 0x4002 undefined */ 0,
/* 0x4004 undefined */ 0,
/* 0x4006 undefined */ 0,
/* 0x4008 SP0 */ 0x260,
/* 0x400a RP0 */ 0x370,
/* 0x400c '?KEY */ XT__3FRX,
/* 0x400e 'EMIT */ XT_TX_21,
/* 0x4010 'EXPECT */ XT_accept,
/* 0x4012 'TAP */ 0,
/* 0x4014 'ECHO */ XT_TX_21,
/* 0x4016 'PROMPT */ 0,
/* 0x4018 BASE */ 0xa,
/* 0x401a temp */ 0x20,
/* 0x401c SPAN */ 0,
/* 0x401e >IN */ 0xd,
/* 0x4020 #TIB */ 0x3a,
/* 0x4022 undefined */ TIB0,
/* 0x4024 CSP */ 0,
/* 0x4026 'EVAL */ XT__24INTERPRET,
/* 0x4028 'NUMBER */ XT_NUMBER_3F,
/* 0x402a HLD */ 0,
/* 0x402c HANDLER */ 0,
/* 0x402e CONTEXT */ 2,
/* 0x4030 undefined */ 0,
/* 0x4032 undefined */ 0,
/* 0x4034 undefined */ 0,
/* 0x4036 undefined */ 0,
/* 0x4038 undefined */ 0,
/* 0x403a undefined */ 0,
/* 0x403c undefined */ 0,
/* 0x403e undefined */ 0,
/* 0x4040 CURRENT */ 2,
/* 0x4042 undefined */ 2,
/* 0x4044 CP */ 6,
/* 0x4046 NP */ 0x160,
/* 0x4048 LAST */ 0x54d4,
/* 0x404a VP */ 0,
/* 0x404c unused */ 0,
/* 0x404e unused */ 0,
/* 0x4050 unused */ 0,
/* 0x4052 unused */ 0,
/* 0x4054 unused */ 0,
/* 0x4056 unused */ 0,
/* 0x4058 unused */ 0,
/* 0x405a unused */ 0,
/* 0x405c unused */ 0,
/* 0x405e unused */ 0,
/* 0x4060 unused */ 0,
/* 0x4062 unused */ 0,
/* 0x4064 unused */ 0,
/* 0x4066 unused */ 0,
/* 0x4068 unused */ 0,
/* 0x406a unused */ 0,
/* 0x406c unused */ 0,
/* 0x406e unused */ 0,
/* 0x4070 unused */ 0,
/* 0x4072 unused */ 0,
/* 0x4074 unused */ 0,
/* 0x4076 unused */ 0,
/* 0x4078 unused */ 0,
/* 0x407a unused */ 0,
/* 0x407c unused */ 0,
/* 0x407e unused */ 0,
/* ==== CODE DICTIONARY ==== */
/* 0x4080: FORTH */ F_tokenVocabulary, 2, 
/* 0x4084: CELLL */ F_tokenNextVal, 2, 
/* 0x4088: CELLbits */ F_tokenNextVal, 0x10, 
/* 0x408c: CELLMASK */ F_tokenNextVal, 0xff1f, 
/* 0x4090: TIB0 */ F_tokenNextVal, TIB0, 
/* 0x4094: COMP */ F_tokenNextVal, 0x40, 
/* 0x4098: IMED */ F_tokenNextVal, 0x80, 
/* 0x409c: BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x40a0: BL */ F_tokenNextVal, 0x20, 
/* 0x40a4: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x40a8: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x40ac: tokenDoList */ F_tokenNextVal, 3, 
/* 0x40b0: tokenUser */ F_tokenNextVal, 4, 
/* 0x40b4: tokenVar */ F_tokenNextVal, 5, 
/* 0x40b8: tokenCreate */ F_tokenNextVal, 6, 
/* 0x40bc: ALIGNED */ F_ALIGNED, 
/* 0x40be: find */ F_jsFind, 
/* 0x40c0: OVERT */ F_OVERT, 
/* 0x40c2: $,n */ F_dollarCommaN, 
/* 0x40c4: >NAME */ F_ToNAME, 
/* 0x40c6: MS */ F_MS, 
/* 0x40c8: BYE */ F_BYE, 
/* 0x40ca: EXIT */ F_EXIT, 
/* 0x40cc: EXECUTE */ F_EXECUTE, 
/* 0x40ce: ?RX */ F_QRX, 
/* 0x40d0: TX! */ F_TXbang, 
/* 0x40d2: !IO */ F_bangIO, 
/* 0x40d4: doLIT */ F_doLIT, 
/* 0x40d6: DOES> */ F_DOES, 
/* 0x40d8: next */ F_next, 
/* 0x40da: ?branch */ F_qBranch, 
/* 0x40dc: branch */ F_branch, 
/* 0x40de: ! */ F_store, 
/* 0x40e0: @ */ F_fetch, 
/* 0x40e2: C@ */ F_cFetch, 
/* 0x40e4: C! */ F_cStore, 
/* 0x40e6: RP@ */ F_RPat, 
/* 0x40e8: RP! */ F_RPbang, 
/* 0x40ea: R> */ F_Rfrom, 
/* 0x40ec: R@ */ F_Rat, 
/* 0x40ee: >R */ F_toR, 
/* 0x40f0: SP@ */ F_SPat, 
/* 0x40f2: SP! */ F_SPbang, 
/* 0x40f4: DROP */ F_DROP, 
/* 0x40f6: DUP */ F_DUP, 
/* 0x40f8: SWAP */ F_SWAP, 
/* 0x40fa: OVER */ F_OVER, 
/* 0x40fc: 0< */ F_less0, 
/* 0x40fe: AND */ F_AND, 
/* 0x4100: OR */ F_OR, 
/* 0x4102: XOR */ F_XOR, 
/* 0x4104: UM+ */ F_UMplus, 
/* 0x4106: userAreaInit */ F_userAreaInit, 
/* 0x4108: userAreaSave */ F_userAreaSave, 
/* 0x410a: PARSE */ F_PARSE, 
/* 0x410c: TOKEN */ F_TOKEN, 
/* 0x410e: NUMBER? */ F_NUMBERQ, 
/* 0x4110: $COMPILE */ F_dCOMPILE, 
/* 0x4112: $INTERPRET */ F_dINTERPRET, 
/* 0x4114: [ */ F_openBracket, 
/* 0x4116: ] */ F_closeBracket, 
/* 0x4118: : */ F_colon, 
/* 0x411a: ; */ F_semicolon, 
/* 0x411c: ' */ F_tick, 
/* 0x411e: debugNA */ F_debugNA, 
/* 0x4120: testing3 */ F_testing3, 
/* 0x4122: Fbreak */ F_Fbreak, 
/* 0x4124: debugPrintTIB */ F_debugPrintTIB, 
/* 0x4126: TEST */ F_TEST, 
/* 0x4128: SP0 */ F_tokenUser, 4, 
/* 0x412c: RP0 */ F_tokenUser, 5, 
/* 0x4130: '?KEY */ F_tokenUser, 6, 
/* 0x4134: 'EMIT */ F_tokenUser, 7, 
/* 0x4138: 'EXPECT */ F_tokenUser, 8, 
/* 0x413c: 'TAP */ F_tokenUser, 9, 
/* 0x4140: 'ECHO */ F_tokenUser, 0xa, 
/* 0x4144: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x4148: BASE */ F_tokenUser, 0xc, 
/* 0x414c: temp */ F_tokenUser, 0xd, 
/* 0x4150: SPAN */ F_tokenUser, 0xe, 
/* 0x4154: >IN */ F_tokenUser, 0xf, 
/* 0x4158: #TIB */ F_tokenUser, 0x10, 
/* 0x415c: CSP */ F_tokenUser, 0x12, 
/* 0x4160: 'EVAL */ F_tokenUser, 0x13, 
/* 0x4164: 'NUMBER */ F_tokenUser, 0x14, 
/* 0x4168: HLD */ F_tokenUser, 0x15, 
/* 0x416c: HANDLER */ F_tokenUser, 0x16, 
/* 0x4170: CONTEXT */ F_tokenUser, 0x17, 
/* 0x4174: CURRENT */ F_tokenUser, 0x20, 
/* 0x4178: CP */ F_tokenUser, 0x22, 
/* 0x417c: NP */ F_tokenUser, 0x23, 
/* 0x4180: LAST */ F_tokenUser, 0x24, 
/* 0x4184: VP */ F_tokenUser, 0x25, 
/* 0x4188: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x4190: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x41a2: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x41aa: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x41b2: ( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_2DROP, XT_EXIT, 
/* 0x41be: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x41ca: \T */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x41d6: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x41de: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x41e6: CELL+ */ F_tokenDoList, XT_CELLL, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x41f0: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x4202: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x420a: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x421a: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLIT, XT__2C, XT_EXIT, 
/* 0x4224: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x4236: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x423e: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x4244: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x424a: >MARK */ F_tokenDoList, XT_HERE, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x4256: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x4260: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x426a: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x4270: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x427a: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x4284: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x428e: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x4298: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x42a2: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x42aa: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x42b0: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x42bc: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x42c6: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x42ce: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x42d6: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x42e2: ROT */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x42ee: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x42fa: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x4302: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x430a: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x431e: INVERT */ F_tokenDoList, XT_doLIT, 0xffff, XT_XOR, XT_EXIT, 
/* 0x4328: NEGATE */ F_tokenDoList, XT_INVERT, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x4334: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLIT, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x4348: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x4350: ABS */ F_tokenDoList, XT_DUP, XT_0_3C, XT__3Fbranch, XT_ABS + 0xc, XT_NEGATE, XT_EXIT, 
/* 0x435e: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xe, XT_doLIT, 0, XT_branch, XT_0_3D + 0x12, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x4372: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xe, XT_doLIT, 0, XT_EXIT, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x4386: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x439e: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x16, XT_2DROP, XT_doLIT, 0xffff, XT_branch, XT_ud_3C + 0x18, XT_U_3C, XT_EXIT, 
/* 0x43b8: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x43d0: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x43e0: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x43f2: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x4402: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x58, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4e, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DROP, XT_doLIT, 1, XT__2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x4c, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLIT, 0xffff, XT_DUP, XT_EXIT, 
/* 0x4466: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x449c: /MOD */ F_tokenDoList, XT_OVER, XT_0_3C, XT_SWAP, XT_M_2FMOD, XT_EXIT, 
/* 0x44a8: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x44b0: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x44b8: UM* */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x44f2: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x44fa: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x4516: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x4522: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x452a: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x4532: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x453a: >CHAR */ F_tokenDoList, XT_doLIT, 0x7f, XT_AND, XT_DUP, XT_doLIT, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLIT, 0x5f, XT_EXIT, 
/* 0x4558: DEPTH */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x456a: PICK */ F_tokenDoList, XT_doLIT, 1, XT__2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x457c: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x458c: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x459a: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x45a8: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x45ba: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x45da: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x45e8: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT, 
/* 0x4604: PAD */ F_tokenDoList, XT_HERE, XT_doLIT, 0x50, XT__2B, XT_EXIT, 
/* 0x4610: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x461a: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x10, XT_EXECUTE, XT_branch, XT__40EXECUTE + 0x12, XT_Fbreak, XT_EXIT, 
/* 0x462e: COUNT */ F_tokenDoList, XT_DUP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x463e: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x20, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_doLIT, 1, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_CMOVE + 8, XT_2DROP, XT_EXIT, 
/* 0x4666: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x16, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x4684: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x22, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x22, XT_R_3E, XT_doLIT, 1, XT__2B, XT_EXIT, XT_next, XT__2DTRAILING + 8, XT_doLIT, 0, XT_EXIT, 
/* 0x46b0: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLIT, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLIT, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x46e6: DIGIT */ F_tokenDoList, XT_doLIT, 9, XT_OVER, XT__3C, XT_doLIT, 7, XT_AND, XT__2B, XT_doLIT, 0x30, XT__2B, XT_EXIT, 
/* 0x4700: EXTRACT */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_UM_2FMOD, XT_SWAP, XT_DIGIT, XT_EXIT, 
/* 0x4710: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x471a: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_doLIT, 1, XT__2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x4730: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x473c: #S */ F_tokenDoList, XT__23, XT_DUP, XT__3Fbranch, XT__23S + 0xe, XT_branch, XT__23S + 2, XT_EXIT, 
/* 0x474c: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLIT, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x475c: #> */ F_tokenDoList, XT_DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x476c: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x4774: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x477c: CHARS */ F_tokenDoList, XT_SWAP, XT_doLIT, 0, XT_MAX, XT__3ER, XT_branch, XT_CHARS + 0x14, XT_DUP, XT_EMIT, XT_next, XT_CHARS + 0x10, XT_DROP, XT_EXIT, 
/* 0x4798: SPACES */ F_tokenDoList, XT_BL, XT_CHARS, XT_EXIT, 
/* 0x47a0: TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT_TYPE + 0x14, XT_DUP, XT_C_40, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT_TYPE + 8, XT_DROP, XT_EXIT, 
/* 0x47bc: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x47c4: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x47d8: HEX */ F_tokenDoList, XT_doLIT, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x47e4: DECIMAL */ F_tokenDoList, XT_doLIT, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x47f0: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x4802: U.R */ F_tokenDoList, XT__3ER, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x4818: U. */ F_tokenDoList, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x4826: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLIT, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x4842: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x484a: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLIT, 0x30, XT__2D, XT_doLIT, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x26, XT_doLIT, 7, XT__2D, XT_DUP, XT_doLIT, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x4878: NUMBER? */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_doLIT, 0, XT_OVER, XT_COUNT, XT_OVER, XT_C_40, XT_doLIT, 0x24, XT__3D, XT__3Fbranch, XT_NUMBER_3F + 0x30, XT_HEX, XT_SWAP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_doLIT, 1, XT__2D, XT_OVER, XT_C_40, XT_doLIT, 0x2d, XT__3D, XT__3ER, XT_SWAP, XT_R_40, XT__2D, XT_SWAP, XT_R_40, XT__2B, XT__3FDUP, XT__3Fbranch, XT_NUMBER_3F + 0x9a, XT_doLIT, 1, XT__2D, XT__3ER, XT_DUP, XT__3ER, XT_C_40, XT_BASE, XT__40, XT_DIGIT_3F, XT__3Fbranch, XT_NUMBER_3F + 0x8c, XT_SWAP, XT_BASE, XT__40, XT__2A, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_NUMBER_3F + 0x56, XT_DROP, XT_R_40, XT__3Fbranch, XT_NUMBER_3F + 0x86, XT_NEGATE, XT_SWAP, XT_branch, XT_NUMBER_3F + 0x98, XT_R_3E, XT_R_3E, XT_2DROP, XT_2DROP, XT_doLIT, 0, XT_DUP, XT_R_3E, XT_2DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x491e: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x4926: KEY */ F_tokenDoList, XT_doLIT, 0, XT_MS, XT_doLIT, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT, 
/* 0x493c: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLIT, 0xd, XT__3D, XT_EXIT, 
/* 0x4952: PACE */ F_tokenDoList, XT_doLIT, 0xb, XT_EMIT, XT_EXIT, 
/* 0x495c: CR */ F_tokenDoList, XT_doLIT, 0xd, XT_EMIT, XT_doLIT, 0xa, XT_EMIT, XT_EXIT, 
/* 0x496c: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x4982: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x4988: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x4990: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x4998: parse */ F_tokenDoList, XT_temp, XT__21, XT_OVER, XT__3ER, XT_DUP, XT__3Fbranch, XT_parse + 0x9a, XT_doLIT, 1, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x4c, XT__3ER, XT_BL, XT_OVER, XT_C_40, XT__2D, XT_0_3C, XT_INVERT, XT__3Fbranch, XT_parse + 0x4a, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x24, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_DUP, XT_EXIT, XT_R_3E, XT_OVER, XT_SWAP, XT__3ER, XT_temp, XT__40, XT_OVER, XT_C_40, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x6a, XT_0_3C, XT__3Fbranch, XT_parse + 0x80, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x52, XT_DUP, XT__3ER, XT_branch, XT_parse + 0x8e, XT_R_3E, XT_DROP, XT_DUP, XT_doLIT, 1, XT__2B, XT__3ER, XT_OVER, XT__2D, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, XT_OVER, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x4a3a: PARSE */ F_tokenDoList, XT__3ER, XT_TIB, XT__3EIN, XT__40, XT__2B, XT__23TIB, XT__40, XT__3EIN, XT__40, XT__2D, XT_R_3E, XT_parse, XT__3EIN, XT__2B_21, XT_EXIT, 
/* 0x4a5a: CHAR */ F_tokenDoList, XT_BL, XT_PARSE, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x4a66: CTRL */ F_tokenDoList, XT_CHAR, XT_doLIT, 0x1f, XT_AND, XT_EXIT, 
/* 0x4a72: .( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x4a7e: TOKEN */ F_tokenDoList, XT_BL, XT_PARSE, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x4a98: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x4aa2: NAME> */ F_tokenDoList, XT_doLIT, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x4ab0: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 8, XT_doLIT, 0, XT_EXIT, 
/* 0x4ae4: FORTHfind */ F_tokenDoList, XT_SWAP, XT_DUP, XT_C_40, XT_CELLL, XT__2F, XT_temp, XT__21, XT_DUP, XT__40, XT__3ER, XT_CELL_2B, XT_SWAP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTHfind + 0x4a, XT_DUP, XT__40, XT_doLIT, 0xff1f, XT_AND, XT_R_40, XT_XOR, XT__3Fbranch, XT_FORTHfind + 0x3e, XT_CELL_2B, XT_doLIT, 0xffff, XT_branch, XT_FORTHfind + 0x46, XT_CELL_2B, XT_temp, XT__40, XT_SAME_3F, XT_branch, XT_FORTHfind + 0x56, XT_R_3E, XT_DROP, XT_SWAP, XT_CELL_2D, XT_SWAP, XT_EXIT, XT__3Fbranch, XT_FORTHfind + 0x62, XT_CELL_2D, XT_CELL_2D, XT_branch, XT_FORTHfind + 0x1a, XT_R_3E, XT_DROP, XT_NIP, XT_CELL_2D, XT_DUP, XT_NAME_3E, XT_SWAP, XT_EXIT, 
/* 0x4b56: NAME? */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_NAME_3F + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT_DUP, XT__3ER, XT__40, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x30, XT_find, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x12, XT_R_3E, XT_DROP, XT_EXIT, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x4b90: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x4bbc: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x4bd0: crlf? */ F_tokenDoList, XT_DUP, XT_doLIT, 0xa, XT__3D, XT_SWAP, XT_doLIT, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x4be6: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x2c, XT_doLIT, 8, XT__3D, XT_OVER, XT_doLIT, 0x7f, XT__3D, XT_OR, XT__3Fbranch, XT_kTAP + 0x28, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x2a, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x4c1a: accept */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_accept + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLIT, 0x5f, XT_U_3C, XT__3Fbranch, XT_accept + 0x28, XT_TAP, XT_branch, XT_accept + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_accept + 8, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x4c52: EXPECT */ F_tokenDoList, XT__27EXPECT, XT__40EXECUTE, XT_SPAN, XT__21, XT_DROP, XT_EXIT, 
/* 0x4c60: QUERY */ F_tokenDoList, XT_TIB, XT_doLIT, 0x50, XT__27EXPECT, XT__40EXECUTE, XT__23TIB, XT__21, XT_DROP, XT_doLIT, 0, XT__3EIN, XT__21, XT_EXIT, 
/* 0x4c7c: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x4ca0: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x20, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x4cc2: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x4cc8: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x4cd0: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x4ce0: $," */ F_tokenDoList, XT_doLIT, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x4cf4: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x4cfe: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x4d08: $INTERPRET */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24INTERPRET + 0x26, XT_C_40, XT_doLIT, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24INTERPRET + 0x30, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x4d3c: .OK */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__40, XT__3D, XT__3Fbranch, XT__2EOK + 0x16, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0x4d56: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0x4d6a: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x16, XT__27EVAL, XT__40EXECUTE, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x4d88: [ */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x4d94: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_TIB0, XT__23TIB, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x4da6: XIO */ F_tokenDoList, XT_doLIT, XT_accept, XT__27EXPECT, XT__21, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x4dbe: FILE */ F_tokenDoList, XT_doLIT, XT_PACE, XT_doLIT, XT_DROP, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x4dd0: HAND */ F_tokenDoList, XT_doLIT, XT__2EOK, XT_doLIT, XT_EMIT, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x4de2: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x4dea: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x4df8: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x4e00: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLIT, 0x5e, XT_CHARS, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0x4e30: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLIT, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT_CONSOLE, XT_quitError, XT_branch, XT_QUIT + 8, XT_EXIT, 
/* 0x4e50: quit1 */ F_tokenDoList, XT_doLIT, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0x4e64: ' */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, XT__27 + 0xc, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x4e74: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x4e7c: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0x4e92: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x4e9a: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3E, XT__2C, XT_EXIT, 
/* 0x4ea6: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x4eb0: S" */ F_tokenDoList, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x4eba: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x4ed6: $,n */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, XT__24_2Cn + 0x30, XT__3FUNIQUE, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0x4f12: $COMPILE */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24COMPILE + 0x1e, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, XT__24COMPILE + 0x1a, XT_EXECUTE, XT_branch, XT__24COMPILE + 0x1c, XT__2C, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24COMPILE + 0x2a, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x4f40: OVERT */ F_tokenDoList, XT_LAST, XT__40, XT_CURRENT, XT__40, XT__21, XT_EXIT, 
/* 0x4f4e: ; */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 
/* 0x4f5a: ] */ F_tokenDoList, XT_doLIT, XT__24COMPILE, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x4f66: : */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x4f74: USER */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenUser, XT__2C, XT_EXIT, 
/* 0x4f82: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x4f94: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x4f9c: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x14, XT_CREATE, XT_branch, XT_vCREATE + 0x1a, XT_tokenVar, XT_create, XT__2C, XT_EXIT, 
/* 0x4fb8: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLIT, 0, XT_v_2C, XT_EXIT, 
/* 0x4fc4: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x4fd4: _TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT__5FTYPE + 0x16, XT_DUP, XT_C_40, XT__3ECHAR, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT__5FTYPE + 8, XT_DROP, XT_EXIT, 
/* 0x4ff2: dm+ */ F_tokenDoList, XT_OVER, XT_doLIT, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x22, XT_DUP, XT_C_40, XT_doLIT, 3, XT_U_2ER, XT_doLIT, 1, XT__2B, XT_next, XT_dm_2B + 0x12, XT_EXIT, 
/* 0x501a: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLIT, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLIT, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLIT, 2, XT_SPACES, XT__5FTYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x505e: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2004, 0x733c, 0x70, XT_EXIT, 
/* 0x507e: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x5090: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x509c: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x50a6: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x50c0: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT_BYTEMASK, XT_AND, XT__5FTYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x50e0: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT, 
/* 0x5102: FORTH>NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_2DUP, XT_NAME_3E, XT_XOR, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_CELL_2D, XT_branch, XT_FORTH_3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x5140: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLIT, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLIT, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT, 
/* 0x51c6: VER */ F_tokenNextVal, 0xc, 
/* 0x51ca: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT__3C_23, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x5208: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x5210: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x5220: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x5226: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT, 
/* 0x523e: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x524a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x526a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x528a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x52aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x52ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x52ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x530a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x532a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x534a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x536a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x538a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x53aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x53ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x53ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x540a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x542a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x544a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x546a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x548a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x54aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172, 0x6572, 
/* 0x54ca: */ 0x5361, 0x7661, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x54d0 WARM */ XT_WARM, 0x54de, 0x5704, XT_WARM + 3, 0x4d,
/* 0x54da COLD */ XT_COLD, 0x54e8, 0x4304, 0x4c4f, 0x44,
/* 0x54e4 'BOOT */ XT__27BOOT, 0x54f2, 0x2705, 0x4f42, 0x544f,
/* 0x54ee EMPTY */ XT_EMPTY, 0x54fc, 0x4505, 0x504d, 0x5954,
/* 0x54f8 hi */ XT_hi, 0x5504, 0x6842, 0x69,
/* 0x5500 version */ XT_version, 0x5510, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0x550c VER */ XT_VER, 0x5518, 0x5603, XT_VER + 7,
/* 0x5514 SEE */ XT_SEE, 0x5520, XT_SEE + 0xc5, 0x4545,
/* 0x551c FORTH>NAME */ XT_FORTH_3ENAME, 0x5530, 0x460a, XT_FORTH_3ENAME + 0x11, 0x4854, 0x4e3e, 0x4d41, 0x45,
/* 0x552c WORDS */ XT_WORDS, 0x553a, 0x5705, XT_WORDS + 0x11, 0x5344,
/* 0x5536 .ID */ XT__2EID, 0x5542, 0x2e03, 0x4449,
/* 0x553e ?CSP */ XT__3FCSP, 0x554c, 0x3f04, 0x5343, 0x50,
/* 0x5548 !CSP */ XT__21CSP, 0x5556, 0x2104, 0x5343, 0x50,
/* 0x5552 .FREE */ XT__2EFREE, 0x5560, 0x2e05, XT__2EFREE + 8, 0x4545,
/* 0x555c .BASE */ XT__2EBASE, 0x556a, 0x2e05, 0x4142, 0x4553,
/* 0x5566 .S */ XT__2ES, 0x5572, 0x2e02, 0x53,
/* 0x556e DUMP */ XT_DUMP, 0x557c, 0x4404, 0x4d55, 0x50,
/* 0x5578 dm+ */ XT_dm_2B, 0x5584, 0x6403, 0x2b6d,
/* 0x5580 _TYPE */ XT__5FTYPE, 0x558e, 0x5f05, 0x5954, 0x4550,
/* 0x558a CONSTANT */ XT_CONSTANT, 0x559c, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0x5598 VARIABLE */ XT_VARIABLE, 0x55aa, 0x5608, XT_VARIABLE + 3, 0x4149, 0x4c42, 0x45,
/* 0x55a6 vCREATE */ XT_vCREATE, 0x55b6, 0x7607, XT_vCREATE + 5, 0x4145, 0x4554,
/* 0x55b2 CREATE */ XT_CREATE, 0x55c2, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x55be create */ XT_create, 0x55ce, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x55ca USER */ XT_USER, 0x55d8, 0x5504, 0x4553, 0x52,
/* 0x55d4 : */ XT__3A, 0x55de, 0x3a01,
/* 0x55da ] */ XT__5D, 0x55e4, 0x5d01,
/* 0x55e0 ; */ XT__3B, 0x55ea, 0x3bc1,
/* 0x55e6 OVERT */ XT_OVERT, 0x55f4, 0x4f05, 0x4556, 0x5452,
/* 0x55f0 $COMPILE */ XT__24COMPILE, 0x5602, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x55fe $,n */ XT__24_2Cn, 0x560a, 0x2403, 0x6e2c,
/* 0x5606 ?UNIQUE */ XT__3FUNIQUE, 0x5616, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0x5612 S" */ XT_S_22, 0x561e, 0x5382, 0x22,
/* 0x561a $" */ XT__24_22, 0x5626, 0x2482, 0x22,
/* 0x5622 RECURSE */ XT_RECURSE, 0x5632, XT_RECURSE + 0x49, 0x4345, XT_RECURSE + 0x17, 0x4553,
/* 0x562e [COMPILE] */ XT__5BCOMPILE_5D, 0x5640, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x563c vALLOT */ XT_vALLOT, 0x564c, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0x5648 ALLOT */ XT_ALLOT, 0x5656, 0x4105, 0x4c4c, 0x544f,
/* 0x5652 ' */ XT__27, 0x565c, 0x2701,
/* 0x5658 quit1 */ XT_quit1, 0x5666, 0x7105, 0x6975, 0x3174,
/* 0x5662 QUIT */ XT_QUIT, 0x5670, 0x5104, 0x4955, 0x54,
/* 0x566c quitError */ XT_quitError, 0x567e, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0x567a que */ XT_que, 0x5686, 0x7103, 0x6575,
/* 0x5682 CONSOLE */ XT_CONSOLE, 0x5692, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0x568e I/O */ XT_I_2FO, 0x569a, 0x4903, 0x4f2f,
/* 0x5696 HAND */ XT_HAND, 0x56a4, 0x4804, 0x4e41, 0x44,
/* 0x56a0 FILE */ XT_FILE, 0x56ae, XT_PAD, 0x4c49, 0x45,
/* 0x56aa XIO */ XT_XIO, 0x56b6, 0x5803, 0x4f49,
/* 0x56b2 PRESET */ XT_PRESET, 0x56c2, 0x5006, 0x4552, 0x4553, 0x54,
/* 0x56be [ */ XT__5B, 0x56c8, 0x5b81,
/* 0x56c4 EVAL */ XT_EVAL, 0x56d2, 0x4504, 0x4156, 0x4c,
/* 0x56ce ?STACK */ XT__3FSTACK, 0x56de, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0x56da .OK */ XT__2EOK, 0x56e6, 0x2e03, 0x4b4f,
/* 0x56e2 $INTERPRET */ XT__24INTERPRET, 0x56f6, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x56f2 ." */ XT__2E_22, 0x56fe, 0x2e82, 0x22,
/* 0x56fa ABORT" */ XT_ABORT_22, 0x570a, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0x5706 $," */ XT__24_2C_22, 0x5712, 0x2403, 0x222c,
/* 0x570e abort" */ XT_abort_22, 0x571e, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0x571a ABORT */ XT_ABORT, 0x5728, 0x4105, 0x4f42, 0x5452,
/* 0x5724 NULL$ */ XT_NULL_24, 0x5732, 0x4e05, 0x4c55, 0x244c,
/* 0x572e THROW */ XT_THROW, 0x573c, 0x5405, XT_THROW + 0xa, 0x574f,
/* 0x5738 CATCH */ XT_CATCH, 0x5746, 0x4305, 0x5441, 0x4843,
/* 0x5742 QUERY */ XT_QUERY, 0x5750, 0x5105, 0x4555, 0x5952,
/* 0x574c EXPECT */ XT_EXPECT, 0x575c, 0x4506, 0x5058, 0x4345, 0x54,
/* 0x5758 accept */ XT_accept, 0x5768, 0x6106, 0x6363, 0x7065, 0x74,
/* 0x5764 kTAP */ XT_kTAP, 0x5772, 0x6b04, XT__3EIN, 0x50,
/* 0x576e crlf? */ XT_crlf_3F, 0x577c, 0x6305, 0x6c72, 0x3f66,
/* 0x5778 TAP */ XT_TAP, 0x5784, 0x5403, 0x5041,
/* 0x5780 ^H */ XT__5EH, 0x578c, 0x5e02, 0x48,
/* 0x5788 NAME? */ XT_NAME_3F, 0x5796, 0x4e05, 0x4d41, 0x3f45,
/* 0x5792 FORTHfind */ XT_FORTHfind, 0x57a4, 0x4609, XT_FORTHfind + 0x11, 0x4854, 0x6966, 0x646e,
/* 0x57a0 SAME? */ XT_SAME_3F, 0x57ae, XT_SAME_3F + 0xc7, 0x4d41, 0x3f45,
/* 0x57aa NAME> */ XT_NAME_3E, 0x57b8, 0x4e05, 0x4d41, 0x3e45,
/* 0x57b4 WORD */ XT_WORD, 0x57c2, 0x5704, XT_WORD + 0x11, 0x44,
/* 0x57be TOKEN */ XT_TOKEN, 0x57cc, 0x5405, 0x4b4f, 0x4e45,
/* 0x57c8 .( */ XT__2E_28, 0x57d4, 0x2e82, 0x28,
/* 0x57d0 CTRL */ XT_CTRL, 0x57de, 0x4304, XT_CTRL + 0x16, 0x4c,
/* 0x57da CHAR */ XT_CHAR, 0x57e8, 0x4304, XT_BASE, 0x52,
/* 0x57e4 PARSE */ XT_PARSE, 0x57f2, 0x5005, XT_PARSE + 3, 0x4553,
/* 0x57ee parse */ XT_parse, 0x57fc, 0x7005, 0x7261, 0x6573,
/* 0x57f8 S"| */ XT_S_22_7C, 0x5804, XT_S_22_7C + 0xc5, 0x7c22,
/* 0x5800 ."| */ XT__2E_22_7C, 0x580c, 0x2e03, 0x7c22,
/* 0x5808 $"| */ XT__24_22_7C, 0x5814, 0x2403, 0x7c22,
/* 0x5810 do$ */ XT_do_24, 0x581c, 0x6403, 0x246f,
/* 0x5818 CR */ XT_CR, 0x5824, XT__2B, 0x52,
/* 0x5820 PACE */ XT_PACE, 0x582e, 0x5004, 0x4341, 0x45,
/* 0x582a NUF? */ XT_NUF_3F, 0x5838, 0x4e04, 0x4655, 0x3f,
/* 0x5834 KEY */ XT_KEY, 0x5840, 0x4b03, 0x5945,
/* 0x583c ?KEY */ XT__3FKEY, 0x584a, 0x3f04, 0x454b, 0x59,
/* 0x5846 NUMBER? */ XT_NUMBER_3F, 0x5856, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x5852 DIGIT? */ XT_DIGIT_3F, 0x5862, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0x585e ? */ XT__3F, 0x5868, 0x3f01,
/* 0x5864 . */ XT__2E, 0x586e, 0x2e01,
/* 0x586a U. */ XT_U_2E, 0x5876, 0x5502, 0x2e,
/* 0x5872 U.R */ XT_U_2ER, 0x587e, 0x5503, 0x522e,
/* 0x587a .R */ XT__2ER, 0x5886, 0x2e02, 0x52,
/* 0x5882 DECIMAL */ XT_DECIMAL, 0x5892, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0x588e HEX */ XT_HEX, 0x589a, 0x4803, 0x5845,
/* 0x5896 str */ XT_str, 0x58a2, 0x7303, 0x7274,
/* 0x589e .$ */ XT__2E_24, 0x58aa, 0x2e02, 0x24,
/* 0x58a6 TYPE */ XT_TYPE, 0x58b4, 0x5404, 0x5059, 0x45,
/* 0x58b0 SPACES */ XT_SPACES, 0x58c0, XT_SPACES + 0xc8, XT_SPAN, 0x4543, 0x53,
/* 0x58bc CHARS */ XT_CHARS, 0x58ca, 0x4305, XT_BASE, 0x5352,
/* 0x58c6 SPACE */ XT_SPACE, 0x58d4, XT_SPACE + 0xc7, XT_SPAN, 0x4543,
/* 0x58d0 EMIT */ XT_EMIT, 0x58de, 0x4504, 0x494d, 0x54,
/* 0x58da #> */ XT__23_3E, 0x58e6, 0x2302, 0x3e,
/* 0x58e2 SIGN */ XT_SIGN, 0x58f0, XT_SIGN + 0xc6, 0x4749, 0x4e,
/* 0x58ec #S */ XT__23S, 0x58f8, 0x2302, 0x53,
/* 0x58f4 # */ XT__23, 0x58fe, 0x2301,
/* 0x58fa HOLD */ XT_HOLD, 0x5908, 0x4804, 0x4c4f, 0x44,
/* 0x5904 <# */ XT__3C_23, 0x5910, 0x3c02, 0x23,
/* 0x590c EXTRACT */ XT_EXTRACT, 0x591c, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0x5918 DIGIT */ XT_DIGIT, 0x5926, 0x4405, 0x4749, 0x5449,
/* 0x5922 PACK$ */ XT_PACK_24, 0x5930, 0x5005, 0x4341, 0x244b,
/* 0x592c -TRAILING */ XT__2DTRAILING, 0x593e, 0x2d09, XT__2DTRAILING + 0x16, 0x4941, 0x494c, 0x474e,
/* 0x593a FILL */ XT_FILL, 0x5948, XT_PAD, 0x4c49, 0x4c,
/* 0x5944 CMOVE */ XT_CMOVE, 0x5952, 0x4305, 0x4f4d, 0x4556,
/* 0x594e COUNT */ XT_COUNT, 0x595c, 0x4305, 0x554f, 0x544e,
/* 0x5958 @EXECUTE */ XT__40EXECUTE, 0x596a, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0x5966 TIB */ XT_TIB, 0x5972, 0x5403, 0x4249,
/* 0x596e PAD */ XT_PAD, 0x597a, 0x5003, 0x4441,
/* 0x5976 vCREATE */ XT_vCREATE, 0x5986, 0x7607, XT_vCREATE + 5, 0x4145, 0x4554,
/* 0x5982 vALIGN */ XT_vALIGN, 0x5992, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0x598e v, */ XT_v_2C, 0x599a, 0x7602, 0x2c,
/* 0x5996 vHERE */ XT_vHERE, 0x59a4, 0x7605, 0x4548, 0x4552,
/* 0x59a0 2@ */ XT_2_40, 0x59ac, 0x3202, 0x40,
/* 0x59a8 2! */ XT_2_21, 0x59b4, 0x3202, 0x21,
/* 0x59b0 +! */ XT__2B_21, 0x59bc, 0x2b02, 0x21,
/* 0x59b8 PICK */ XT_PICK, 0x59c6, 0x5004, 0x4349, 0x4b,
/* 0x59c2 DEPTH */ XT_DEPTH, 0x59d0, 0x4405, 0x5045, 0x4854,
/* 0x59cc >CHAR */ XT__3ECHAR, 0x59da, 0x3e05, 0x4843, XT__3ECHAR + 3,
/* 0x59d6 CELLS */ XT_CELLS, 0x59e4, 0x4305, 0x4c45, 0x534c,
/* 0x59e0 CELL- */ XT_CELL_2D, 0x59ee, 0x4305, 0x4c45, 0x2d4c,
/* 0x59ea * / */ XT__2A_2F, 0x59f6, 0x2a02, 0x2f,
/* 0x59f2 * /MOD */ XT__2A_2FMOD, 0x5a00, 0x2a05, 0x4d2f, 0x444f,
/* 0x59fc M* */ XT_M_2A, 0x5a08, 0x4d02, 0x2a,
/* 0x5a04 * */ XT__2A, 0x5a0e, 0x2a01,
/* 0x5a0a UM* */ XT_UM_2A, 0x5a16, 0x5503, 0x2a4d,
/* 0x5a12 / */ XT__2F, 0x5a1c, 0x2f01,
/* 0x5a18 MOD */ XT_MOD, 0x5a24, 0x4d03, 0x444f,
/* 0x5a20 /MOD */ XT__2FMOD, 0x5a2e, 0x2f04, 0x4f4d, 0x44,
/* 0x5a2a M/MOD */ XT_M_2FMOD, 0x5a38, 0x4d05, 0x4d2f, 0x444f,
/* 0x5a34 UM/MOD */ XT_UM_2FMOD, 0x5a44, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0x5a40 WITHIN */ XT_WITHIN, 0x5a50, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0x5a4c MIN */ XT_MIN, 0x5a58, 0x4d03, 0x4e49,
/* 0x5a54 MAX */ XT_MAX, 0x5a60, 0x4d03, 0x5841,
/* 0x5a5c < */ XT__3C, 0x5a66, 0x3c01,
/* 0x5a62 ud< */ XT_ud_3C, 0x5a6e, 0x7503, 0x3c64,
/* 0x5a6a U< */ XT_U_3C, 0x5a76, 0x5502, 0x3c,
/* 0x5a72 = */ XT__3D, 0x5a7c, 0x3d01,
/* 0x5a78 0= */ XT_0_3D, 0x5a84, 0x3002, 0x3d,
/* 0x5a80 ABS */ XT_ABS, 0x5a8c, 0x4103, 0x5342,
/* 0x5a88 - */ XT__2D, 0x5a92, 0x2d01,
/* 0x5a8e DNEGATE */ XT_DNEGATE, 0x5a9e, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0x5a9a NEGATE */ XT_NEGATE, 0x5aaa, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0x5aa6 INVERT */ XT_INVERT, 0x5ab6, 0x4906, 0x564e, XT_INVERT + 7, 0x54,
/* 0x5ab2 D+ */ XT_D_2B, 0x5abe, XT_UM_2FMOD, 0x2b,
/* 0x5aba + */ XT__2B, 0x5ac4, 0x2b01,
/* 0x5ac0 2DUP */ XT_2DUP, 0x5ace, 0x3204, 0x5544, 0x50,
/* 0x5aca -ROT */ XT__2DROT, 0x5ad8, 0x2d04, 0x4f52, 0x54,
/* 0x5ad4 ROT */ XT_ROT, 0x5ae0, 0x5203, 0x544f,
/* 0x5adc ?DUP */ XT__3FDUP, 0x5aea, 0x3f04, 0x5544, 0x50,
/* 0x5ae6 WHILE */ XT_WHILE, 0x5af4, 0x5785, 0x4948, 0x454c,
/* 0x5af0 WHEN */ XT_WHEN, 0x5afe, 0x5784, 0x4548, 0x4e,
/* 0x5afa ELSE */ XT_ELSE, 0x5b08, 0x4584, 0x534c, 0x45,
/* 0x5b04 AFT */ XT_AFT, 0x5b10, 0x4183, 0x5446,
/* 0x5b0c THEN */ XT_THEN, 0x5b1a, 0x5484, 0x4548, 0x4e,
/* 0x5b16 REPEAT */ XT_REPEAT, 0x5b26, XT_REPEAT + 0x48, 0x5045, 0x4145, 0x54,
/* 0x5b22 AHEAD */ XT_AHEAD, 0x5b30, 0x4185, 0x4548, 0x4441,
/* 0x5b2c IF */ XT_IF, 0x5b38, XT__24_22_7C, 0x46,
/* 0x5b34 AGAIN */ XT_AGAIN, 0x5b42, 0x4185, 0x4147, 0x4e49,
/* 0x5b3e UNTIL */ XT_UNTIL, 0x5b4c, 0x5585, 0x544e, 0x4c49,
/* 0x5b48 NEXT */ XT_NEXT, 0x5b56, 0x4e84, 0x5845, 0x54,
/* 0x5b52 BEGIN */ XT_BEGIN, 0x5b60, 0x4285, 0x4745, 0x4e49,
/* 0x5b5c FOR */ XT_FOR, 0x5b68, 0x4683, XT_FOR + 0x11,
/* 0x5b64 >RESOLVE */ XT__3ERESOLVE, 0x5b76, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x5b72 >MARK */ XT__3EMARK, 0x5b80, 0x3e05, 0x414d, 0x4b52,
/* 0x5b7c <RESOLVE */ XT__3CRESOLVE, 0x5b8e, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x5b8a <MARK */ XT__3CMARK, 0x5b98, 0x3c05, 0x414d, 0x4b52,
/* 0x5b94 CREATE */ XT_CREATE, 0x5ba4, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x5ba0 create */ XT_create, 0x5bb0, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x5bac LITERAL */ XT_LITERAL, 0x5bbc, 0x4c87, 0x5449, XT_LITERAL + 7, 0x4c41,
/* 0x5bb8 COMPILE */ XT_COMPILE, 0x5bc8, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0x5bc4 [COMPILE] */ XT__5BCOMPILE_5D, 0x5bd6, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x5bd2 , */ XT__2C, 0x5bdc, 0x2c01,
/* 0x5bd8 CELL+ */ XT_CELL_2B, 0x5be6, 0x4305, 0x4c45, 0x2b4c,
/* 0x5be2 HERE */ XT_HERE, 0x5bf0, 0x4804, XT_HERE + 7, 0x45,
/* 0x5bec NIP */ XT_NIP, 0x5bf8, 0x4e03, 0x5049,
/* 0x5bf4 \T */ XT__5CT, 0x5c00, 0x5c02, 0x54,
/* 0x5bfc \ */ XT__5C, 0x5c06, 0x5c81,
/* 0x5c02 ( */ XT__28, 0x5c0c, 0x2881,
/* 0x5c08 IMMEDIATE */ XT_IMMEDIATE, 0x5c1a, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0x5c16 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x5c2c, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0x5c28 setHeaderBits */ XT_setHeaderBits, 0x5c3e, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0x5c3a 2DROP */ XT_2DROP, 0x5c48, 0x3205, XT_2DROP + 6, 0x504f,
/* 0x5c44 VP */ XT_VP, 0x5c50, 0x5602, 0x50,
/* 0x5c4c LAST */ XT_LAST, 0x5c5a, 0x4c04, 0x5341, 0x54,
/* 0x5c56 NP */ XT_NP, 0x5c62, 0x4e02, 0x50,
/* 0x5c5e CP */ XT_CP, 0x5c6a, XT__2B, 0x50,
/* 0x5c66 CURRENT */ XT_CURRENT, 0x5c76, 0x4307, XT_CURRENT + 0x17, 0x4552, 0x544e,
/* 0x5c72 CONTEXT */ XT_CONTEXT, 0x5c82, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0x5c7e HANDLER */ XT_HANDLER, 0x5c8e, 0x4807, 0x4e41, 0x4c44, XT_HANDLER + 7,
/* 0x5c8a HLD */ XT_HLD, 0x5c96, 0x4803, 0x444c,
/* 0x5c92 'NUMBER */ XT__27NUMBER, 0x5ca2, 0x2707, 0x554e, 0x424d, XT__27NUMBER + 7,
/* 0x5c9e 'EVAL */ XT__27EVAL, 0x5cac, 0x2705, 0x5645, 0x4c41,
/* 0x5ca8 CSP */ XT_CSP, 0x5cb4, 0x4303, 0x5053,
/* 0x5cb0 #TIB */ XT__23TIB, 0x5cbe, 0x2304, 0x4954, 0x42,
/* 0x5cba >IN */ XT__3EIN, 0x5cc6, 0x3e03, 0x4e49,
/* 0x5cc2 SPAN */ XT_SPAN, 0x5cd0, XT_SPAN + 0xc6, XT_SPAN, 0x4e,
/* 0x5ccc temp */ XT_temp, 0x5cda, 0x7404, 0x6d65, 0x70,
/* 0x5cd6 BASE */ XT_BASE, 0x5ce4, 0x4204, 0x5341, 0x45,
/* 0x5ce0 'PROMPT */ XT__27PROMPT, 0x5cf0, 0x2707, XT__27PROMPT + 0x12, 0x4d4f, 0x5450,
/* 0x5cec 'ECHO */ XT__27ECHO, 0x5cfa, 0x2705, 0x4345, 0x4f48,
/* 0x5cf6 'TAP */ XT__27TAP, 0x5d04, 0x2704, XT__3EIN, 0x50,
/* 0x5d00 'EXPECT */ XT__27EXPECT, 0x5d10, 0x2707, 0x5845, 0x4550, 0x5443,
/* 0x5d0c 'EMIT */ XT__27EMIT, 0x5d1a, 0x2705, 0x4d45, 0x5449,
/* 0x5d16 '?KEY */ XT__27_3FKEY, 0x5d24, 0x2705, 0x4b3f, 0x5945,
/* 0x5d20 RP0 */ XT_RP0, 0x5d2c, 0x5203, 0x3050,
/* 0x5d28 SP0 */ XT_SP0, 0x5d34, XT_SP0 + 0xc5, 0x3050,
/* 0x5d30 TEST */ XT_TEST, 0x5d3e, 0x5404, 0x5345, 0x54,
/* 0x5d3a debugPrintTIB */ XT_debugPrintTIB, 0x5d50, 0x640d, 0x6265, 0x6775, 0x7250, 0x6e69, 0x5474, 0x4249,
/* 0x5d4c Fbreak */ XT_Fbreak, 0x5d5c, 0x4606, 0x7262, 0x6165, 0x6b,
/* 0x5d58 testing3 */ XT_testing3, 0x5d6a, 0x7408, 0x7365, 0x6974, 0x676e, 0x33,
/* 0x5d66 debugNA */ XT_debugNA, 0x5d76, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0x5d72 ' */ XT__27, 0x5d7c, 0x2701,
/* 0x5d78 ; */ XT__3B, 0x5d82, 0x3b81,
/* 0x5d7e : */ XT__3A, 0x5d88, 0x3a01,
/* 0x5d84 ] */ XT__5D, 0x5d8e, 0x5d01,
/* 0x5d8a [ */ XT__5B, 0x5d94, 0x5b81,
/* 0x5d90 $INTERPRET */ XT__24INTERPRET, 0x5da4, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x5da0 $COMPILE */ XT__24COMPILE, 0x5db2, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x5dae NUMBER? */ XT_NUMBER_3F, 0x5dbe, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x5dba TOKEN */ XT_TOKEN, 0x5dc8, 0x5405, 0x4b4f, 0x4e45,
/* 0x5dc4 PARSE */ XT_PARSE, 0x5dd2, 0x5005, XT_PARSE + 3, 0x4553,
/* 0x5dce userAreaSave */ XT_userAreaSave, 0x5de4, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0x5de0 userAreaInit */ XT_userAreaInit, 0x5df6, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0x5df2 UM+ */ XT_UM_2B, 0x5dfe, 0x5503, 0x2b4d,
/* 0x5dfa XOR */ XT_XOR, 0x5e06, 0x5803, XT_XOR + 0x11,
/* 0x5e02 OR */ XT_OR, 0x5e0e, 0x4f02, 0x52,
/* 0x5e0a AND */ XT_AND, 0x5e16, 0x4103, 0x444e,
/* 0x5e12 0< */ XT_0_3C, 0x5e1e, 0x3002, 0x3c,
/* 0x5e1a OVER */ XT_OVER, 0x5e28, 0x4f04, 0x4556, 0x52,
/* 0x5e24 SWAP */ XT_SWAP, 0x5e32, XT_SWAP + 0xc6, 0x4157, 0x50,
/* 0x5e2e DUP */ XT_DUP, 0x5e3a, 0x4403, 0x5055,
/* 0x5e36 DROP */ XT_DROP, 0x5e44, 0x4404, 0x4f52, 0x50,
/* 0x5e40 SP! */ XT_SP_21, 0x5e4c, XT_SP_21 + 0xc5, 0x2150,
/* 0x5e48 SP@ */ XT_SP_40, 0x5e54, XT_SP_40 + 0xc5, 0x4050,
/* 0x5e50 >R */ XT__3ER, 0x5e5c, 0x3e02, 0x52,
/* 0x5e58 R@ */ XT_R_40, 0x5e64, 0x5202, 0x40,
/* 0x5e60 R> */ XT_R_3E, 0x5e6c, 0x5202, 0x3e,
/* 0x5e68 RP! */ XT_RP_21, 0x5e74, 0x5203, 0x2150,
/* 0x5e70 RP@ */ XT_RP_40, 0x5e7c, 0x5203, 0x4050,
/* 0x5e78 C! */ XT_C_21, 0x5e84, XT__2B, 0x21,
/* 0x5e80 C@ */ XT_C_40, 0x5e8c, XT__2B, 0x40,
/* 0x5e88 @ */ XT__40, 0x5e92, 0x4001,
/* 0x5e8e ! */ XT__21, 0x5e98, 0x2101,
/* 0x5e94 branch */ XT_branch, 0x5ea4, 0x6206, 0x6172, 0x636e, 0x68,
/* 0x5ea0 ?branch */ XT__3Fbranch, 0x5eb0, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0x5eac next */ XT_next, 0x5eba, 0x6e04, 0x7865, 0x74,
/* 0x5eb6 DOES> */ XT_DOES_3E, 0x5ec4, 0x4405, 0x454f, 0x3e53,
/* 0x5ec0 doLIT */ XT_doLIT, 0x5ece, 0x6405, 0x4c6f, 0x5449,
/* 0x5eca !IO */ XT__21IO, 0x5ed6, 0x2103, 0x4f49,
/* 0x5ed2 TX! */ XT_TX_21, 0x5ede, 0x5403, 0x2158,
/* 0x5eda ?RX */ XT__3FRX, 0x5ee6, 0x3f03, 0x5852,
/* 0x5ee2 EXECUTE */ XT_EXECUTE, 0x5ef2, 0x4507, XT_DEPTH, 0x5543, 0x4554,
/* 0x5eee EXIT */ XT_EXIT, 0x5efc, 0x4504, 0x4958, 0x54,
/* 0x5ef8 BYE */ XT_BYE, 0x5f04, 0x4203, 0x4559,
/* 0x5f00 MS */ XT_MS, 0x5f0c, 0x4d02, 0x53,
/* 0x5f08 >NAME */ XT__3ENAME, 0x5f16, 0x3e05, 0x414e, 0x454d,
/* 0x5f12 $,n */ XT__24_2Cn, 0x5f1e, 0x2403, 0x6e2c,
/* 0x5f1a OVERT */ XT_OVERT, 0x5f28, 0x4f05, 0x4556, 0x5452,
/* 0x5f24 find */ XT_find, 0x5f32, 0x6604, 0x6e69, 0x64,
/* 0x5f2e ALIGNED */ XT_ALIGNED, 0x5f3e, 0x4107, 0x494c, 0x4e47, 0x4445,
/* 0x5f3a tokenCreate */ XT_tokenCreate, 0x5f4e, 0x740b, 0x6b6f, 0x6e65, 0x7243, 0x6165, 0x6574,
/* 0x5f4a tokenVar */ XT_tokenVar, 0x5f5c, 0x7408, 0x6b6f, 0x6e65, 0x6156, 0x72,
/* 0x5f58 tokenUser */ XT_tokenUser, 0x5f6a, 0x7409, 0x6b6f, 0x6e65, 0x7355, 0x7265,
/* 0x5f66 tokenDoList */ XT_tokenDoList, 0x5f7a, 0x740b, 0x6b6f, 0x6e65, 0x6f44, 0x694c, 0x7473,
/* 0x5f76 tokenNextVal */ XT_tokenNextVal, 0x5f8c, 0x740c, 0x6b6f, 0x6e65, 0x654e, 0x7478, 0x6156, 0x6c,
/* 0x5f88 tokenVocabulary */ XT_tokenVocabulary, 0x5fa0, 0x740f, 0x6b6f, 0x6e65, 0x6f56, 0x6163, 0x7562, 0x616c, 0x7972,
/* 0x5f9c BL */ XT_BL, 0x5fa8, XT__5BCOMPILE_5D, 0x4c,
/* 0x5fa4 BYTEMASK */ XT_BYTEMASK, 0x5fb6, 0x4208, 0x5459, 0x4d45, 0x5341, 0x4b,
/* 0x5fb2 IMED */ XT_IMED, 0x5fc0, 0x4904, 0x454d, 0x44,
/* 0x5fbc COMP */ XT_COMP, 0x5fca, 0x4304, 0x4d4f, 0x50,
/* 0x5fc6 TIB0 */ XT_TIB0, 0x5fd4, 0x5404, 0x4249, 0x30,
/* 0x5fd0 CELLMASK */ XT_CELLMASK, 0x5fe2, 0x4308, 0x4c45, 0x4d4c, 0x5341, 0x4b,
/* 0x5fde CELLbits */ XT_CELLbits, 0x5ff0, 0x4308, 0x4c45, 0x624c, 0x7469, 0x73,
/* 0x5fec CELLL */ XT_CELLL, 0x5ffa, 0x4305, 0x4c45, 0x4c4c,
/* 0x5ff6 FORTH */ XT_FORTH, 0, 0x4605, XT_FORTH + 0x11, 0x4854,
};
// === End of Arduino source from dictionary === 
