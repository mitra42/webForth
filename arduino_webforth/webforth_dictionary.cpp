#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x923e /* WARM*/
#define XT_COLD 0x9226 /* COLD*/
#define XT__27BOOT 0x9220 /* 'BOOT*/
#define XT_EMPTY 0x9210 /* EMPTY*/
#define XT_hi 0x9208 /* hi*/
#define XT_version 0x91ca /* version*/
#define XT_VER 0x91c6 /* VER*/
#define XT_SEE 0x9140 /* SEE*/
#define XT_FORTH_3ENAME 0x9102 /* FORTH>NAME*/
#define XT_WORDS 0x90e0 /* WORDS*/
#define XT__2EID 0x90c0 /* .ID*/
#define XT__3FCSP 0x90a6 /* ?CSP*/
#define XT__21CSP 0x909c /* !CSP*/
#define XT__2EFREE 0x9090 /* .FREE*/
#define XT__2EBASE 0x907e /* .BASE*/
#define XT__2ES 0x905e /* .S*/
#define XT_DUMP 0x901a /* DUMP*/
#define XT_dm_2B 0x8ff2 /* dm+*/
#define XT__5FTYPE 0x8fd4 /* _TYPE*/
#define XT_CONSTANT 0x8fc4 /* CONSTANT*/
#define XT_VARIABLE 0x8fb8 /* VARIABLE*/
#define XT_vCREATE 0x8f9c /* vCREATE*/
#define XT_CREATE 0x8f94 /* CREATE*/
#define XT_create 0x8f82 /* create*/
#define XT_USER 0x8f74 /* USER*/
#define XT__3A 0x8f66 /* :*/
#define XT__5D 0x8f5a /* ]*/
#define XT__3B 0x8f4e /* ;*/
#define XT_OVERT 0x8f40 /* OVERT*/
#define XT__24COMPILE 0x8f12 /* $COMPILE*/
#define XT__24_2Cn 0x8ed6 /* $,n*/
#define XT__3FUNIQUE 0x8eba /* ?UNIQUE*/
#define XT_S_22 0x8eb0 /* S"*/
#define XT__24_22 0x8ea6 /* $"*/
#define XT_RECURSE 0x8e9a /* RECURSE*/
#define XT__5BCOMPILE_5D 0x8e92 /* [COMPILE]*/
#define XT_vALLOT 0x8e7c /* vALLOT*/
#define XT_ALLOT 0x8e74 /* ALLOT*/
#define XT__27 0x8e64 /* '*/
#define XT_quit1 0x8e50 /* quit1*/
#define XT_QUIT 0x8e30 /* QUIT*/
#define XT_quitError 0x8e00 /* quitError*/
#define XT_que 0x8df8 /* que*/
#define XT_CONSOLE 0x8dea /* CONSOLE*/
#define XT_I_2FO 0x8de2 /* I/O*/
#define XT_HAND 0x8dd0 /* HAND*/
#define XT_FILE 0x8dbe /* FILE*/
#define XT_XIO 0x8da6 /* XIO*/
#define XT_PRESET 0x8d94 /* PRESET*/
#define XT__5B 0x8d88 /* [*/
#define XT_EVAL 0x8d6a /* EVAL*/
#define XT__3FSTACK 0x8d56 /* ?STACK*/
#define XT__2EOK 0x8d3c /* .OK*/
#define XT__24INTERPRET 0x8d08 /* $INTERPRET*/
#define XT__2E_22 0x8cfe /* ."*/
#define XT_ABORT_22 0x8cf4 /* ABORT"*/
#define XT__24_2C_22 0x8ce0 /* $,"*/
#define XT_abort_22 0x8cd0 /* abort"*/
#define XT_ABORT 0x8cc8 /* ABORT*/
#define XT_NULL_24 0x8cc2 /* NULL$*/
#define XT_THROW 0x8ca0 /* THROW*/
#define XT_CATCH 0x8c7c /* CATCH*/
#define XT_QUERY 0x8c60 /* QUERY*/
#define XT_EXPECT 0x8c52 /* EXPECT*/
#define XT_accept 0x8c1a /* accept*/
#define XT_kTAP 0x8be6 /* kTAP*/
#define XT_crlf_3F 0x8bd0 /* crlf?*/
#define XT_TAP 0x8bbc /* TAP*/
#define XT__5EH 0x8b90 /* ^H*/
#define XT_NAME_3F 0x8b56 /* NAME?*/
#define XT_FORTHfind 0x8ae4 /* FORTHfind*/
#define XT_SAME_3F 0x8ab0 /* SAME?*/
#define XT_NAME_3E 0x8aa2 /* NAME>*/
#define XT_WORD 0x8a98 /* WORD*/
#define XT_TOKEN 0x8a7e /* TOKEN*/
#define XT__2E_28 0x8a72 /* .(*/
#define XT_CTRL 0x8a66 /* CTRL*/
#define XT_CHAR 0x8a5a /* CHAR*/
#define XT_PARSE 0x8a3a /* PARSE*/
#define XT_parse 0x8998 /* parse*/
#define XT_S_22_7C 0x8990 /* S"|*/
#define XT__2E_22_7C 0x8988 /* ."|*/
#define XT__24_22_7C 0x8982 /* $"|*/
#define XT_do_24 0x896c /* do$*/
#define XT_CR 0x895c /* CR*/
#define XT_PACE 0x8952 /* PACE*/
#define XT_NUF_3F 0x893c /* NUF?*/
#define XT_KEY 0x8926 /* KEY*/
#define XT__3FKEY 0x891e /* ?KEY*/
#define XT_NUMBER_3F 0x8878 /* NUMBER?*/
#define XT_DIGIT_3F 0x884a /* DIGIT?*/
#define XT__3F 0x8842 /* ?*/
#define XT__2E 0x8826 /* .*/
#define XT_U_2E 0x8818 /* U.*/
#define XT_U_2ER 0x8802 /* U.R*/
#define XT__2ER 0x87f0 /* .R*/
#define XT_DECIMAL 0x87e4 /* DECIMAL*/
#define XT_HEX 0x87d8 /* HEX*/
#define XT_str 0x87c4 /* str*/
#define XT__2E_24 0x87bc /* .$*/
#define XT_TYPE 0x87a0 /* TYPE*/
#define XT_SPACES 0x8798 /* SPACES*/
#define XT_CHARS 0x877c /* CHARS*/
#define XT_SPACE 0x8774 /* SPACE*/
#define XT_EMIT 0x876c /* EMIT*/
#define XT__23_3E 0x875c /* #>*/
#define XT_SIGN 0x874c /* SIGN*/
#define XT__23S 0x873c /* #S*/
#define XT__23 0x8730 /* #*/
#define XT_HOLD 0x871a /* HOLD*/
#define XT__3C_23 0x8710 /* <#*/
#define XT_EXTRACT 0x8700 /* EXTRACT*/
#define XT_DIGIT 0x86e6 /* DIGIT*/
#define XT_PACK_24 0x86b0 /* PACK$*/
#define XT__2DTRAILING 0x8684 /* -TRAILING*/
#define XT_FILL 0x8666 /* FILL*/
#define XT_CMOVE 0x863e /* CMOVE*/
#define XT_COUNT 0x862e /* COUNT*/
#define XT__40EXECUTE 0x861a /* @EXECUTE*/
#define XT_TIB 0x8610 /* TIB*/
#define XT_PAD 0x8604 /* PAD*/
#define XT_vCREATE 0x85e8 /* vCREATE*/
#define XT_vALIGN 0x85da /* vALIGN*/
#define XT_v_2C 0x85ba /* v,*/
#define XT_vHERE 0x85a8 /* vHERE*/
#define XT_2_40 0x859a /* 2@*/
#define XT_2_21 0x858c /* 2!*/
#define XT__2B_21 0x857c /* +!*/
#define XT_PICK 0x856a /* PICK*/
#define XT_DEPTH 0x8558 /* DEPTH*/
#define XT__3ECHAR 0x853a /* >CHAR*/
#define XT_CELLS 0x8532 /* CELLS*/
#define XT_CELL_2D 0x852a /* CELL-*/
#define XT__2A_2F 0x8522 /* * /*/
#define XT__2A_2FMOD 0x8516 /* * /MOD*/
#define XT_M_2A 0x84fa /* M**/
#define XT__2A 0x84f2 /* **/
#define XT_UM_2A 0x84b8 /* UM**/
#define XT__2F 0x84b0 /* /*/
#define XT_MOD 0x84a8 /* MOD*/
#define XT__2FMOD 0x849c /* /MOD*/
#define XT_M_2FMOD 0x8466 /* M/MOD*/
#define XT_UM_2FMOD 0x8402 /* UM/MOD*/
#define XT_WITHIN 0x83f2 /* WITHIN*/
#define XT_MIN 0x83e0 /* MIN*/
#define XT_MAX 0x83d0 /* MAX*/
#define XT__3C 0x83b8 /* <*/
#define XT_ud_3C 0x839e /* ud<*/
#define XT_U_3C 0x8386 /* U<*/
#define XT__3D 0x8372 /* =*/
#define XT_0_3D 0x835e /* 0=*/
#define XT_ABS 0x8350 /* ABS*/
#define XT__2D 0x8348 /* -*/
#define XT_DNEGATE 0x8334 /* DNEGATE*/
#define XT_NEGATE 0x8328 /* NEGATE*/
#define XT_INVERT 0x831e /* INVERT*/
#define XT_D_2B 0x830a /* D+*/
#define XT__2B 0x8302 /* +*/
#define XT_2DUP 0x82fa /* 2DUP*/
#define XT__2DROT 0x82ee /* -ROT*/
#define XT_ROT 0x82e2 /* ROT*/
#define XT__3FDUP 0x82d6 /* ?DUP*/
#define XT_WHILE 0x82ce /* WHILE*/
#define XT_WHEN 0x82c6 /* WHEN*/
#define XT_ELSE 0x82bc /* ELSE*/
#define XT_AFT 0x82b0 /* AFT*/
#define XT_THEN 0x82aa /* THEN*/
#define XT_REPEAT 0x82a2 /* REPEAT*/
#define XT_AHEAD 0x8298 /* AHEAD*/
#define XT_IF 0x828e /* IF*/
#define XT_AGAIN 0x8284 /* AGAIN*/
#define XT_UNTIL 0x827a /* UNTIL*/
#define XT_NEXT 0x8270 /* NEXT*/
#define XT_BEGIN 0x826a /* BEGIN*/
#define XT_FOR 0x8260 /* FOR*/
#define XT__3ERESOLVE 0x8256 /* >RESOLVE*/
#define XT__3EMARK 0x824a /* >MARK*/
#define XT__3CRESOLVE 0x8244 /* <RESOLVE*/
#define XT__3CMARK 0x823e /* <MARK*/
#define XT_CREATE 0x8236 /* CREATE*/
#define XT_create 0x8224 /* create*/
#define XT_LITERAL 0x821a /* LITERAL*/
#define XT_COMPILE 0x820a /* COMPILE*/
#define XT__5BCOMPILE_5D 0x8202 /* [COMPILE]*/
#define XT__2C 0x81f0 /* ,*/
#define XT_CELL_2B 0x81e6 /* CELL+*/
#define XT_HERE 0x81de /* HERE*/
#define XT_NIP 0x81d6 /* NIP*/
#define XT__5CT 0x81ca /* \T*/
#define XT__5C 0x81be /* \*/
#define XT__28 0x81b2 /* (*/
#define XT_IMMEDIATE 0x81aa /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x81a2 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x8190 /* setHeaderBits*/
#define XT_2DROP 0x8188 /* 2DROP*/
#define XT_VP 0x8184 /* VP*/
#define XT_LAST 0x8180 /* LAST*/
#define XT_NP 0x817c /* NP*/
#define XT_CP 0x8178 /* CP*/
#define XT_CURRENT 0x8174 /* CURRENT*/
#define XT_CONTEXT 0x8170 /* CONTEXT*/
#define XT_HANDLER 0x816c /* HANDLER*/
#define XT_HLD 0x8168 /* HLD*/
#define XT__27NUMBER 0x8164 /* 'NUMBER*/
#define XT__27EVAL 0x8160 /* 'EVAL*/
#define XT_CSP 0x815c /* CSP*/
#define XT__23TIB 0x8158 /* #TIB*/
#define XT__3EIN 0x8154 /* >IN*/
#define XT_SPAN 0x8150 /* SPAN*/
#define XT_temp 0x814c /* temp*/
#define XT_BASE 0x8148 /* BASE*/
#define XT__27PROMPT 0x8144 /* 'PROMPT*/
#define XT__27ECHO 0x8140 /* 'ECHO*/
#define XT__27TAP 0x813c /* 'TAP*/
#define XT__27EXPECT 0x8138 /* 'EXPECT*/
#define XT__27EMIT 0x8134 /* 'EMIT*/
#define XT__27_3FKEY 0x8130 /* '?KEY*/
#define XT_RP0 0x812c /* RP0*/
#define XT_SP0 0x8128 /* SP0*/
#define XT_TEST 0x8126 /* TEST*/
#define XT_debugPrintTIB 0x8124 /* debugPrintTIB*/
#define XT_Fbreak 0x8122 /* Fbreak*/
#define XT_testing3 0x8120 /* testing3*/
#define XT_debugNA 0x811e /* debugNA*/
#define XT_userAreaSave 0x8108 /* userAreaSave*/
#define XT_userAreaInit 0x8106 /* userAreaInit*/
#define XT_UM_2B 0x8104 /* UM+*/
#define XT_XOR 0x8102 /* XOR*/
#define XT_OR 0x8100 /* OR*/
#define XT_AND 0x80fe /* AND*/
#define XT_0_3C 0x80fc /* 0<*/
#define XT_OVER 0x80fa /* OVER*/
#define XT_SWAP 0x80f8 /* SWAP*/
#define XT_DUP 0x80f6 /* DUP*/
#define XT_DROP 0x80f4 /* DROP*/
#define XT_SP_21 0x80f2 /* SP!*/
#define XT_SP_40 0x80f0 /* SP@*/
#define XT__3ER 0x80ee /* >R*/
#define XT_R_40 0x80ec /* R@*/
#define XT_R_3E 0x80ea /* R>*/
#define XT_RP_21 0x80e8 /* RP!*/
#define XT_RP_40 0x80e6 /* RP@*/
#define XT_C_21 0x80e4 /* C!*/
#define XT_C_40 0x80e2 /* C@*/
#define XT__40 0x80e0 /* @*/
#define XT__21 0x80de /* !*/
#define XT_branch 0x80dc /* branch*/
#define XT__3Fbranch 0x80da /* ?branch*/
#define XT_next 0x80d8 /* next*/
#define XT_DOES_3E 0x80d6 /* DOES>*/
#define XT_doLIT 0x80d4 /* doLIT*/
#define XT__21IO 0x80d2 /* !IO*/
#define XT_TX_21 0x80d0 /* TX!*/
#define XT__3FRX 0x80ce /* ?RX*/
#define XT_EXECUTE 0x80cc /* EXECUTE*/
#define XT_EXIT 0x80ca /* EXIT*/
#define XT_BYE 0x80c8 /* BYE*/
#define XT_MS 0x80c6 /* MS*/
#define XT__3ENAME 0x80c4 /* >NAME*/
#define XT_find 0x80be /* find*/
#define XT_ALIGNED 0x80bc /* ALIGNED*/
#define XT_tokenCreate 0x80b8 /* tokenCreate*/
#define XT_tokenVar 0x80b4 /* tokenVar*/
#define XT_tokenUser 0x80b0 /* tokenUser*/
#define XT_tokenDoList 0x80ac /* tokenDoList*/
#define XT_tokenNextVal 0x80a8 /* tokenNextVal*/
#define XT_tokenVocabulary 0x80a4 /* tokenVocabulary*/
#define XT_BL 0x80a0 /* BL*/
#define XT_BYTEMASK 0x809c /* BYTEMASK*/
#define XT_IMED 0x8098 /* IMED*/
#define XT_COMP 0x8094 /* COMP*/
#define XT_TIB0 0x8090 /* TIB0*/
#define XT_CELLMASK 0x808c /* CELLMASK*/
#define XT_CELLbits 0x8088 /* CELLbits*/
#define XT_CELLL 0x8084 /* CELLL*/
#define XT_FORTH 0x8080 /* FORTH*/
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
/* 0x8000 undefined */ 0,
/* 0x8002 undefined */ 0,
/* 0x8004 undefined */ 0,
/* 0x8006 undefined */ 0,
/* 0x8008 SP0 */ 0x260,
/* 0x800a RP0 */ 0x370,
/* 0x800c '?KEY */ XT__3FRX,
/* 0x800e 'EMIT */ XT_TX_21,
/* 0x8010 'EXPECT */ XT_accept,
/* 0x8012 'TAP */ 0,
/* 0x8014 'ECHO */ XT_TX_21,
/* 0x8016 'PROMPT */ 0,
/* 0x8018 BASE */ 0xa,
/* 0x801a temp */ 0x20,
/* 0x801c SPAN */ 0,
/* 0x801e >IN */ 0xd,
/* 0x8020 #TIB */ 0x3a,
/* 0x8022 undefined */ TIB0,
/* 0x8024 CSP */ 0,
/* 0x8026 'EVAL */ XT__24INTERPRET,
/* 0x8028 'NUMBER */ XT_NUMBER_3F,
/* 0x802a HLD */ 0,
/* 0x802c HANDLER */ 0,
/* 0x802e CONTEXT */ 2,
/* 0x8030 undefined */ 0,
/* 0x8032 undefined */ 0,
/* 0x8034 undefined */ 0,
/* 0x8036 undefined */ 0,
/* 0x8038 undefined */ 0,
/* 0x803a undefined */ 0,
/* 0x803c undefined */ 0,
/* 0x803e undefined */ 0,
/* 0x8040 CURRENT */ 2,
/* 0x8042 undefined */ 2,
/* 0x8044 CP */ 6,
/* 0x8046 NP */ 0x160,
/* 0x8048 LAST */ 0x94d4,
/* 0x804a VP */ 0,
/* 0x804c unused */ 0,
/* 0x804e unused */ 0,
/* 0x8050 unused */ 0,
/* 0x8052 unused */ 0,
/* 0x8054 unused */ 0,
/* 0x8056 unused */ 0,
/* 0x8058 unused */ 0,
/* 0x805a unused */ 0,
/* 0x805c unused */ 0,
/* 0x805e unused */ 0,
/* 0x8060 unused */ 0,
/* 0x8062 unused */ 0,
/* 0x8064 unused */ 0,
/* 0x8066 unused */ 0,
/* 0x8068 unused */ 0,
/* 0x806a unused */ 0,
/* 0x806c unused */ 0,
/* 0x806e unused */ 0,
/* 0x8070 unused */ 0,
/* 0x8072 unused */ 0,
/* 0x8074 unused */ 0,
/* 0x8076 unused */ 0,
/* 0x8078 unused */ 0,
/* 0x807a unused */ 0,
/* 0x807c unused */ 0,
/* 0x807e unused */ 0,
/* ==== CODE DICTIONARY ==== */
/* 0x8080: FORTH */ F_tokenVocabulary, 2, 
/* 0x8084: CELLL */ F_tokenNextVal, 2, 
/* 0x8088: CELLbits */ F_tokenNextVal, 0x10, 
/* 0x808c: CELLMASK */ F_tokenNextVal, 0xff1f, 
/* 0x8090: TIB0 */ F_tokenNextVal, TIB0, 
/* 0x8094: COMP */ F_tokenNextVal, 0x40, 
/* 0x8098: IMED */ F_tokenNextVal, 0x80, 
/* 0x809c: BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x80a0: BL */ F_tokenNextVal, 0x20, 
/* 0x80a4: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x80a8: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x80ac: tokenDoList */ F_tokenNextVal, 3, 
/* 0x80b0: tokenUser */ F_tokenNextVal, 4, 
/* 0x80b4: tokenVar */ F_tokenNextVal, 5, 
/* 0x80b8: tokenCreate */ F_tokenNextVal, 6, 
/* 0x80bc: ALIGNED */ F_ALIGNED, 
/* 0x80be: find */ F_jsFind, 
/* 0x80c0: OVERT */ F_OVERT, 
/* 0x80c2: $,n */ F_dollarCommaN, 
/* 0x80c4: >NAME */ F_ToNAME, 
/* 0x80c6: MS */ F_MS, 
/* 0x80c8: BYE */ F_BYE, 
/* 0x80ca: EXIT */ F_EXIT, 
/* 0x80cc: EXECUTE */ F_EXECUTE, 
/* 0x80ce: ?RX */ F_QRX, 
/* 0x80d0: TX! */ F_TXbang, 
/* 0x80d2: !IO */ F_bangIO, 
/* 0x80d4: doLIT */ F_doLIT, 
/* 0x80d6: DOES> */ F_DOES, 
/* 0x80d8: next */ F_next, 
/* 0x80da: ?branch */ F_qBranch, 
/* 0x80dc: branch */ F_branch, 
/* 0x80de: ! */ F_store, 
/* 0x80e0: @ */ F_fetch, 
/* 0x80e2: C@ */ F_cFetch, 
/* 0x80e4: C! */ F_cStore, 
/* 0x80e6: RP@ */ F_RPat, 
/* 0x80e8: RP! */ F_RPbang, 
/* 0x80ea: R> */ F_Rfrom, 
/* 0x80ec: R@ */ F_Rat, 
/* 0x80ee: >R */ F_toR, 
/* 0x80f0: SP@ */ F_SPat, 
/* 0x80f2: SP! */ F_SPbang, 
/* 0x80f4: DROP */ F_DROP, 
/* 0x80f6: DUP */ F_DUP, 
/* 0x80f8: SWAP */ F_SWAP, 
/* 0x80fa: OVER */ F_OVER, 
/* 0x80fc: 0< */ F_less0, 
/* 0x80fe: AND */ F_AND, 
/* 0x8100: OR */ F_OR, 
/* 0x8102: XOR */ F_XOR, 
/* 0x8104: UM+ */ F_UMplus, 
/* 0x8106: userAreaInit */ F_userAreaInit, 
/* 0x8108: userAreaSave */ F_userAreaSave, 
/* 0x810a: PARSE */ F_PARSE, 
/* 0x810c: TOKEN */ F_TOKEN, 
/* 0x810e: NUMBER? */ F_NUMBERQ, 
/* 0x8110: $COMPILE */ F_dCOMPILE, 
/* 0x8112: $INTERPRET */ F_dINTERPRET, 
/* 0x8114: [ */ F_openBracket, 
/* 0x8116: ] */ F_closeBracket, 
/* 0x8118: : */ F_colon, 
/* 0x811a: ; */ F_semicolon, 
/* 0x811c: ' */ F_tick, 
/* 0x811e: debugNA */ F_debugNA, 
/* 0x8120: testing3 */ F_testing3, 
/* 0x8122: Fbreak */ F_Fbreak, 
/* 0x8124: debugPrintTIB */ F_debugPrintTIB, 
/* 0x8126: TEST */ F_TEST, 
/* 0x8128: SP0 */ F_tokenUser, 4, 
/* 0x812c: RP0 */ F_tokenUser, 5, 
/* 0x8130: '?KEY */ F_tokenUser, 6, 
/* 0x8134: 'EMIT */ F_tokenUser, 7, 
/* 0x8138: 'EXPECT */ F_tokenUser, 8, 
/* 0x813c: 'TAP */ F_tokenUser, 9, 
/* 0x8140: 'ECHO */ F_tokenUser, 0xa, 
/* 0x8144: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x8148: BASE */ F_tokenUser, 0xc, 
/* 0x814c: temp */ F_tokenUser, 0xd, 
/* 0x8150: SPAN */ F_tokenUser, 0xe, 
/* 0x8154: >IN */ F_tokenUser, 0xf, 
/* 0x8158: #TIB */ F_tokenUser, 0x10, 
/* 0x815c: CSP */ F_tokenUser, 0x12, 
/* 0x8160: 'EVAL */ F_tokenUser, 0x13, 
/* 0x8164: 'NUMBER */ F_tokenUser, 0x14, 
/* 0x8168: HLD */ F_tokenUser, 0x15, 
/* 0x816c: HANDLER */ F_tokenUser, 0x16, 
/* 0x8170: CONTEXT */ F_tokenUser, 0x17, 
/* 0x8174: CURRENT */ F_tokenUser, 0x20, 
/* 0x8178: CP */ F_tokenUser, 0x22, 
/* 0x817c: NP */ F_tokenUser, 0x23, 
/* 0x8180: LAST */ F_tokenUser, 0x24, 
/* 0x8184: VP */ F_tokenUser, 0x25, 
/* 0x8188: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x8190: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x81a2: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x81aa: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x81b2: ( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_2DROP, XT_EXIT, 
/* 0x81be: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x81ca: \T */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x81d6: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x81de: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x81e6: CELL+ */ F_tokenDoList, XT_CELLL, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x81f0: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x8202: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x820a: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x821a: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLIT, XT__2C, XT_EXIT, 
/* 0x8224: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x8236: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x823e: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x8244: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x824a: >MARK */ F_tokenDoList, XT_HERE, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x8256: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x8260: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x826a: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x8270: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x827a: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x8284: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x828e: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x8298: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x82a2: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x82aa: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x82b0: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x82bc: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x82c6: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x82ce: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x82d6: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x82e2: ROT */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x82ee: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x82fa: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x8302: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x830a: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x831e: INVERT */ F_tokenDoList, XT_doLIT, 0xffff, XT_XOR, XT_EXIT, 
/* 0x8328: NEGATE */ F_tokenDoList, XT_INVERT, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x8334: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLIT, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8348: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x8350: ABS */ F_tokenDoList, XT_DUP, XT_0_3C, XT__3Fbranch, XT_ABS + 0xc, XT_NEGATE, XT_EXIT, 
/* 0x835e: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xe, XT_doLIT, 0, XT_branch, XT_0_3D + 0x12, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x8372: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xe, XT_doLIT, 0, XT_EXIT, XT_doLIT, 0xffff, XT_EXIT, 
/* 0x8386: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x839e: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x16, XT_2DROP, XT_doLIT, 0xffff, XT_branch, XT_ud_3C + 0x18, XT_U_3C, XT_EXIT, 
/* 0x83b8: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x83d0: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x83e0: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x83f2: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x8402: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x58, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4e, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DROP, XT_doLIT, 1, XT__2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x4c, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLIT, 0xffff, XT_DUP, XT_EXIT, 
/* 0x8466: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x849c: /MOD */ F_tokenDoList, XT_OVER, XT_0_3C, XT_SWAP, XT_M_2FMOD, XT_EXIT, 
/* 0x84a8: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x84b0: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x84b8: UM* */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x84f2: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x84fa: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x8516: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x8522: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x852a: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x8532: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x853a: >CHAR */ F_tokenDoList, XT_doLIT, 0x7f, XT_AND, XT_DUP, XT_doLIT, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLIT, 0x5f, XT_EXIT, 
/* 0x8558: DEPTH */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x856a: PICK */ F_tokenDoList, XT_doLIT, 1, XT__2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x857c: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x858c: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x859a: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x85a8: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x85ba: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x85da: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x85e8: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT, 
/* 0x8604: PAD */ F_tokenDoList, XT_HERE, XT_doLIT, 0x50, XT__2B, XT_EXIT, 
/* 0x8610: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x861a: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x10, XT_EXECUTE, XT_branch, XT__40EXECUTE + 0x12, XT_Fbreak, XT_EXIT, 
/* 0x862e: COUNT */ F_tokenDoList, XT_DUP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x863e: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x20, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_doLIT, 1, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_CMOVE + 8, XT_2DROP, XT_EXIT, 
/* 0x8666: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x16, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x8684: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x22, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x22, XT_R_3E, XT_doLIT, 1, XT__2B, XT_EXIT, XT_next, XT__2DTRAILING + 8, XT_doLIT, 0, XT_EXIT, 
/* 0x86b0: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLIT, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLIT, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x86e6: DIGIT */ F_tokenDoList, XT_doLIT, 9, XT_OVER, XT__3C, XT_doLIT, 7, XT_AND, XT__2B, XT_doLIT, 0x30, XT__2B, XT_EXIT, 
/* 0x8700: EXTRACT */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_UM_2FMOD, XT_SWAP, XT_DIGIT, XT_EXIT, 
/* 0x8710: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x871a: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_doLIT, 1, XT__2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x8730: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x873c: #S */ F_tokenDoList, XT__23, XT_DUP, XT__3Fbranch, XT__23S + 0xe, XT_branch, XT__23S + 2, XT_EXIT, 
/* 0x874c: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLIT, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x875c: #> */ F_tokenDoList, XT_DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x876c: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x8774: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x877c: CHARS */ F_tokenDoList, XT_SWAP, XT_doLIT, 0, XT_MAX, XT__3ER, XT_branch, XT_CHARS + 0x14, XT_DUP, XT_EMIT, XT_next, XT_CHARS + 0x10, XT_DROP, XT_EXIT, 
/* 0x8798: SPACES */ F_tokenDoList, XT_BL, XT_CHARS, XT_EXIT, 
/* 0x87a0: TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT_TYPE + 0x14, XT_DUP, XT_C_40, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT_TYPE + 8, XT_DROP, XT_EXIT, 
/* 0x87bc: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x87c4: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x87d8: HEX */ F_tokenDoList, XT_doLIT, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x87e4: DECIMAL */ F_tokenDoList, XT_doLIT, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x87f0: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8802: U.R */ F_tokenDoList, XT__3ER, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8818: U. */ F_tokenDoList, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8826: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLIT, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8842: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x884a: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLIT, 0x30, XT__2D, XT_doLIT, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x26, XT_doLIT, 7, XT__2D, XT_DUP, XT_doLIT, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x8878: NUMBER? */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_doLIT, 0, XT_OVER, XT_COUNT, XT_OVER, XT_C_40, XT_doLIT, 0x24, XT__3D, XT__3Fbranch, XT_NUMBER_3F + 0x30, XT_HEX, XT_SWAP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_doLIT, 1, XT__2D, XT_OVER, XT_C_40, XT_doLIT, 0x2d, XT__3D, XT__3ER, XT_SWAP, XT_R_40, XT__2D, XT_SWAP, XT_R_40, XT__2B, XT__3FDUP, XT__3Fbranch, XT_NUMBER_3F + 0x9a, XT_doLIT, 1, XT__2D, XT__3ER, XT_DUP, XT__3ER, XT_C_40, XT_BASE, XT__40, XT_DIGIT_3F, XT__3Fbranch, XT_NUMBER_3F + 0x8c, XT_SWAP, XT_BASE, XT__40, XT__2A, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_NUMBER_3F + 0x56, XT_DROP, XT_R_40, XT__3Fbranch, XT_NUMBER_3F + 0x86, XT_NEGATE, XT_SWAP, XT_branch, XT_NUMBER_3F + 0x98, XT_R_3E, XT_R_3E, XT_2DROP, XT_2DROP, XT_doLIT, 0, XT_DUP, XT_R_3E, XT_2DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x891e: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x8926: KEY */ F_tokenDoList, XT_doLIT, 0, XT_MS, XT_doLIT, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT, 
/* 0x893c: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLIT, 0xd, XT__3D, XT_EXIT, 
/* 0x8952: PACE */ F_tokenDoList, XT_doLIT, 0xb, XT_EMIT, XT_EXIT, 
/* 0x895c: CR */ F_tokenDoList, XT_doLIT, 0xd, XT_EMIT, XT_doLIT, 0xa, XT_EMIT, XT_EXIT, 
/* 0x896c: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x8982: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x8988: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x8990: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x8998: parse */ F_tokenDoList, XT_temp, XT__21, XT_OVER, XT__3ER, XT_DUP, XT__3Fbranch, XT_parse + 0x9a, XT_doLIT, 1, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x4c, XT__3ER, XT_BL, XT_OVER, XT_C_40, XT__2D, XT_0_3C, XT_INVERT, XT__3Fbranch, XT_parse + 0x4a, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x24, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_DUP, XT_EXIT, XT_R_3E, XT_OVER, XT_SWAP, XT__3ER, XT_temp, XT__40, XT_OVER, XT_C_40, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x6a, XT_0_3C, XT__3Fbranch, XT_parse + 0x80, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x52, XT_DUP, XT__3ER, XT_branch, XT_parse + 0x8e, XT_R_3E, XT_DROP, XT_DUP, XT_doLIT, 1, XT__2B, XT__3ER, XT_OVER, XT__2D, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, XT_OVER, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x8a3a: PARSE */ F_tokenDoList, XT__3ER, XT_TIB, XT__3EIN, XT__40, XT__2B, XT__23TIB, XT__40, XT__3EIN, XT__40, XT__2D, XT_R_3E, XT_parse, XT__3EIN, XT__2B_21, XT_EXIT, 
/* 0x8a5a: CHAR */ F_tokenDoList, XT_BL, XT_PARSE, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x8a66: CTRL */ F_tokenDoList, XT_CHAR, XT_doLIT, 0x1f, XT_AND, XT_EXIT, 
/* 0x8a72: .( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x8a7e: TOKEN */ F_tokenDoList, XT_BL, XT_PARSE, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x8a98: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x8aa2: NAME> */ F_tokenDoList, XT_doLIT, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x8ab0: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 8, XT_doLIT, 0, XT_EXIT, 
/* 0x8ae4: FORTHfind */ F_tokenDoList, XT_SWAP, XT_DUP, XT_C_40, XT_CELLL, XT__2F, XT_temp, XT__21, XT_DUP, XT__40, XT__3ER, XT_CELL_2B, XT_SWAP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTHfind + 0x4a, XT_DUP, XT__40, XT_doLIT, 0xff1f, XT_AND, XT_R_40, XT_XOR, XT__3Fbranch, XT_FORTHfind + 0x3e, XT_CELL_2B, XT_doLIT, 0xffff, XT_branch, XT_FORTHfind + 0x46, XT_CELL_2B, XT_temp, XT__40, XT_SAME_3F, XT_branch, XT_FORTHfind + 0x56, XT_R_3E, XT_DROP, XT_SWAP, XT_CELL_2D, XT_SWAP, XT_EXIT, XT__3Fbranch, XT_FORTHfind + 0x62, XT_CELL_2D, XT_CELL_2D, XT_branch, XT_FORTHfind + 0x1a, XT_R_3E, XT_DROP, XT_NIP, XT_CELL_2D, XT_DUP, XT_NAME_3E, XT_SWAP, XT_EXIT, 
/* 0x8b56: NAME? */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_NAME_3F + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT_DUP, XT__3ER, XT__40, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x30, XT_find, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x12, XT_R_3E, XT_DROP, XT_EXIT, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x8b90: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8bbc: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_doLIT, 1, XT__2B, XT_EXIT, 
/* 0x8bd0: crlf? */ F_tokenDoList, XT_DUP, XT_doLIT, 0xa, XT__3D, XT_SWAP, XT_doLIT, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x8be6: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x2c, XT_doLIT, 8, XT__3D, XT_OVER, XT_doLIT, 0x7f, XT__3D, XT_OR, XT__3Fbranch, XT_kTAP + 0x28, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x2a, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x8c1a: accept */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_accept + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLIT, 0x5f, XT_U_3C, XT__3Fbranch, XT_accept + 0x28, XT_TAP, XT_branch, XT_accept + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_accept + 8, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8c52: EXPECT */ F_tokenDoList, XT__27EXPECT, XT__40EXECUTE, XT_SPAN, XT__21, XT_DROP, XT_EXIT, 
/* 0x8c60: QUERY */ F_tokenDoList, XT_TIB, XT_doLIT, 0x50, XT__27EXPECT, XT__40EXECUTE, XT__23TIB, XT__21, XT_DROP, XT_doLIT, 0, XT__3EIN, XT__21, XT_EXIT, 
/* 0x8c7c: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x8ca0: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x20, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x8cc2: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x8cc8: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x8cd0: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x8ce0: $," */ F_tokenDoList, XT_doLIT, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x8cf4: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x8cfe: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8d08: $INTERPRET */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24INTERPRET + 0x26, XT_C_40, XT_doLIT, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24INTERPRET + 0x30, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x8d3c: .OK */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__40, XT__3D, XT__3Fbranch, XT__2EOK + 0x16, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0x8d56: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0x8d6a: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x16, XT__27EVAL, XT__40EXECUTE, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x8d88: [ */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x8d94: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_TIB0, XT__23TIB, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x8da6: XIO */ F_tokenDoList, XT_doLIT, XT_accept, XT__27EXPECT, XT__21, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x8dbe: FILE */ F_tokenDoList, XT_doLIT, XT_PACE, XT_doLIT, XT_DROP, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x8dd0: HAND */ F_tokenDoList, XT_doLIT, XT__2EOK, XT_doLIT, XT_EMIT, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x8de2: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x8dea: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x8df8: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x8e00: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLIT, 0x5e, XT_CHARS, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0x8e30: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLIT, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT_CONSOLE, XT_quitError, XT_branch, XT_QUIT + 8, XT_EXIT, 
/* 0x8e50: quit1 */ F_tokenDoList, XT_doLIT, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0x8e64: ' */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, XT__27 + 0xc, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x8e74: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x8e7c: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0x8e92: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x8e9a: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3E, XT__2C, XT_EXIT, 
/* 0x8ea6: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8eb0: S" */ F_tokenDoList, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8eba: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x8ed6: $,n */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, XT__24_2Cn + 0x30, XT__3FUNIQUE, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0x8f12: $COMPILE */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24COMPILE + 0x1e, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, XT__24COMPILE + 0x1a, XT_EXECUTE, XT_branch, XT__24COMPILE + 0x1c, XT__2C, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24COMPILE + 0x2a, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x8f40: OVERT */ F_tokenDoList, XT_LAST, XT__40, XT_CURRENT, XT__40, XT__21, XT_EXIT, 
/* 0x8f4e: ; */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 
/* 0x8f5a: ] */ F_tokenDoList, XT_doLIT, XT__24COMPILE, XT__27EVAL, XT__21, XT_EXIT, 
/* 0x8f66: : */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x8f74: USER */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenUser, XT__2C, XT_EXIT, 
/* 0x8f82: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT, 
/* 0x8f94: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x8f9c: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x14, XT_CREATE, XT_branch, XT_vCREATE + 0x1a, XT_tokenVar, XT_create, XT__2C, XT_EXIT, 
/* 0x8fb8: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLIT, 0, XT_v_2C, XT_EXIT, 
/* 0x8fc4: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x8fd4: _TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT__5FTYPE + 0x16, XT_DUP, XT_C_40, XT__3ECHAR, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT__5FTYPE + 8, XT_DROP, XT_EXIT, 
/* 0x8ff2: dm+ */ F_tokenDoList, XT_OVER, XT_doLIT, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x22, XT_DUP, XT_C_40, XT_doLIT, 3, XT_U_2ER, XT_doLIT, 1, XT__2B, XT_next, XT_dm_2B + 0x12, XT_EXIT, 
/* 0x901a: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLIT, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLIT, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLIT, 2, XT_SPACES, XT__5FTYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x905e: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2004, 0x733c, 0x70, XT_EXIT, 
/* 0x907e: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x9090: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x909c: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x90a6: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x90c0: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT_BYTEMASK, XT_AND, XT__5FTYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x90e0: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT, 
/* 0x9102: FORTH>NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_2DUP, XT_NAME_3E, XT_XOR, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_CELL_2D, XT_branch, XT_FORTH_3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_doLIT, 0, XT_EXIT, 
/* 0x9140: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLIT, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLIT, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT, 
/* 0x91c6: VER */ F_tokenNextVal, 0xe, 
/* 0x91ca: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT__3C_23, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x9208: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x9210: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x9220: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x9226: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT, 
/* 0x923e: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x924a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x926a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x928a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x92aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x92ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x92ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x930a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x932a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x934a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x936a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x938a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x93aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x93ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x93ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x940a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x942a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x944a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x946a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x948a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x94aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172, 0x6572, 
/* 0x94ca: */ 0x5361, 0x7661, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x94d0 WARM */ XT_WARM, 0x94de, 0x5704, 0x5241, 0x4d,
/* 0x94da COLD */ XT_COLD, 0x94e8, 0x4304, 0x4c4f, 0x44,
/* 0x94e4 'BOOT */ XT__27BOOT, 0x94f2, 0x2705, 0x4f42, 0x544f,
/* 0x94ee EMPTY */ XT_EMPTY, 0x94fc, 0x4505, 0x504d, 0x5954,
/* 0x94f8 hi */ XT_hi, 0x9504, 0x6842, 0x69,
/* 0x9500 version */ XT_version, 0x9510, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0x950c VER */ XT_VER, 0x9518, 0x5603, 0x5245,
/* 0x9514 SEE */ XT_SEE, 0x9520, 0x5303, 0x4545,
/* 0x951c FORTH>NAME */ XT_FORTH_3ENAME, 0x9530, 0x460a, 0x524f, 0x4854, 0x4e3e, 0x4d41, 0x45,
/* 0x952c WORDS */ XT_WORDS, 0x953a, 0x5705, 0x524f, 0x5344,
/* 0x9536 .ID */ XT__2EID, 0x9542, 0x2e03, 0x4449,
/* 0x953e ?CSP */ XT__3FCSP, 0x954c, 0x3f04, 0x5343, 0x50,
/* 0x9548 !CSP */ XT__21CSP, 0x9556, 0x2104, 0x5343, 0x50,
/* 0x9552 .FREE */ XT__2EFREE, 0x9560, 0x2e05, 0x5246, 0x4545,
/* 0x955c .BASE */ XT__2EBASE, 0x956a, 0x2e05, 0x4142, 0x4553,
/* 0x9566 .S */ XT__2ES, 0x9572, 0x2e02, 0x53,
/* 0x956e DUMP */ XT_DUMP, 0x957c, 0x4404, 0x4d55, 0x50,
/* 0x9578 dm+ */ XT_dm_2B, 0x9584, 0x6403, 0x2b6d,
/* 0x9580 _TYPE */ XT__5FTYPE, 0x958e, 0x5f05, 0x5954, 0x4550,
/* 0x958a CONSTANT */ XT_CONSTANT, 0x959c, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0x9598 VARIABLE */ XT_VARIABLE, 0x95aa, 0x5608, 0x5241, 0x4149, 0x4c42, 0x45,
/* 0x95a6 vCREATE */ XT_vCREATE, 0x95b6, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x95b2 CREATE */ XT_CREATE, 0x95c2, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x95be create */ XT_create, 0x95ce, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x95ca USER */ XT_USER, 0x95d8, 0x5504, 0x4553, 0x52,
/* 0x95d4 : */ XT__3A, 0x95de, 0x3a01,
/* 0x95da ] */ XT__5D, 0x95e4, 0x5d01,
/* 0x95e0 ; */ XT__3B, 0x95ea, 0x3bc1,
/* 0x95e6 OVERT */ XT_OVERT, 0x95f4, 0x4f05, 0x4556, 0x5452,
/* 0x95f0 $COMPILE */ XT__24COMPILE, 0x9602, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x95fe $,n */ XT__24_2Cn, 0x960a, 0x2403, 0x6e2c,
/* 0x9606 ?UNIQUE */ XT__3FUNIQUE, 0x9616, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0x9612 S" */ XT_S_22, 0x961e, 0x5382, 0x22,
/* 0x961a $" */ XT__24_22, 0x9626, 0x2482, 0x22,
/* 0x9622 RECURSE */ XT_RECURSE, 0x9632, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0x962e [COMPILE] */ XT__5BCOMPILE_5D, 0x9640, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x963c vALLOT */ XT_vALLOT, 0x964c, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0x9648 ALLOT */ XT_ALLOT, 0x9656, 0x4105, 0x4c4c, 0x544f,
/* 0x9652 ' */ XT__27, 0x965c, 0x2701,
/* 0x9658 quit1 */ XT_quit1, 0x9666, 0x7105, 0x6975, 0x3174,
/* 0x9662 QUIT */ XT_QUIT, 0x9670, 0x5104, 0x4955, 0x54,
/* 0x966c quitError */ XT_quitError, 0x967e, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0x967a que */ XT_que, 0x9686, 0x7103, 0x6575,
/* 0x9682 CONSOLE */ XT_CONSOLE, 0x9692, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0x968e I/O */ XT_I_2FO, 0x969a, 0x4903, 0x4f2f,
/* 0x9696 HAND */ XT_HAND, 0x96a4, 0x4804, 0x4e41, 0x44,
/* 0x96a0 FILE */ XT_FILE, 0x96ae, 0x4604, 0x4c49, 0x45,
/* 0x96aa XIO */ XT_XIO, 0x96b6, 0x5803, 0x4f49,
/* 0x96b2 PRESET */ XT_PRESET, 0x96c2, 0x5006, 0x4552, 0x4553, 0x54,
/* 0x96be [ */ XT__5B, 0x96c8, 0x5b81,
/* 0x96c4 EVAL */ XT_EVAL, 0x96d2, 0x4504, 0x4156, 0x4c,
/* 0x96ce ?STACK */ XT__3FSTACK, 0x96de, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0x96da .OK */ XT__2EOK, 0x96e6, 0x2e03, 0x4b4f,
/* 0x96e2 $INTERPRET */ XT__24INTERPRET, 0x96f6, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x96f2 ." */ XT__2E_22, 0x96fe, 0x2e82, 0x22,
/* 0x96fa ABORT" */ XT_ABORT_22, 0x970a, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0x9706 $," */ XT__24_2C_22, 0x9712, 0x2403, 0x222c,
/* 0x970e abort" */ XT_abort_22, 0x971e, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0x971a ABORT */ XT_ABORT, 0x9728, 0x4105, 0x4f42, 0x5452,
/* 0x9724 NULL$ */ XT_NULL_24, 0x9732, 0x4e05, 0x4c55, 0x244c,
/* 0x972e THROW */ XT_THROW, 0x973c, 0x5405, 0x5248, 0x574f,
/* 0x9738 CATCH */ XT_CATCH, 0x9746, 0x4305, 0x5441, 0x4843,
/* 0x9742 QUERY */ XT_QUERY, 0x9750, 0x5105, 0x4555, 0x5952,
/* 0x974c EXPECT */ XT_EXPECT, 0x975c, 0x4506, 0x5058, 0x4345, 0x54,
/* 0x9758 accept */ XT_accept, 0x9768, 0x6106, 0x6363, 0x7065, 0x74,
/* 0x9764 kTAP */ XT_kTAP, 0x9772, 0x6b04, 0x4154, 0x50,
/* 0x976e crlf? */ XT_crlf_3F, 0x977c, 0x6305, 0x6c72, 0x3f66,
/* 0x9778 TAP */ XT_TAP, 0x9784, 0x5403, 0x5041,
/* 0x9780 ^H */ XT__5EH, 0x978c, 0x5e02, 0x48,
/* 0x9788 NAME? */ XT_NAME_3F, 0x9796, 0x4e05, 0x4d41, 0x3f45,
/* 0x9792 FORTHfind */ XT_FORTHfind, 0x97a4, 0x4609, 0x524f, 0x4854, 0x6966, 0x646e,
/* 0x97a0 SAME? */ XT_SAME_3F, 0x97ae, 0x5305, 0x4d41, 0x3f45,
/* 0x97aa NAME> */ XT_NAME_3E, 0x97b8, 0x4e05, 0x4d41, 0x3e45,
/* 0x97b4 WORD */ XT_WORD, 0x97c2, 0x5704, 0x524f, 0x44,
/* 0x97be TOKEN */ XT_TOKEN, 0x97cc, 0x5405, 0x4b4f, 0x4e45,
/* 0x97c8 .( */ XT__2E_28, 0x97d4, 0x2e82, 0x28,
/* 0x97d0 CTRL */ XT_CTRL, 0x97de, 0x4304, 0x5254, 0x4c,
/* 0x97da CHAR */ XT_CHAR, 0x97e8, 0x4304, 0x4148, 0x52,
/* 0x97e4 PARSE */ XT_PARSE, 0x97f2, 0x5005, 0x5241, 0x4553,
/* 0x97ee parse */ XT_parse, 0x97fc, 0x7005, 0x7261, 0x6573,
/* 0x97f8 S"| */ XT_S_22_7C, 0x9804, 0x5303, 0x7c22,
/* 0x9800 ."| */ XT__2E_22_7C, 0x980c, 0x2e03, 0x7c22,
/* 0x9808 $"| */ XT__24_22_7C, 0x9814, 0x2403, 0x7c22,
/* 0x9810 do$ */ XT_do_24, 0x981c, 0x6403, 0x246f,
/* 0x9818 CR */ XT_CR, 0x9824, 0x4302, 0x52,
/* 0x9820 PACE */ XT_PACE, 0x982e, 0x5004, 0x4341, 0x45,
/* 0x982a NUF? */ XT_NUF_3F, 0x9838, 0x4e04, 0x4655, 0x3f,
/* 0x9834 KEY */ XT_KEY, 0x9840, 0x4b03, 0x5945,
/* 0x983c ?KEY */ XT__3FKEY, 0x984a, 0x3f04, 0x454b, 0x59,
/* 0x9846 NUMBER? */ XT_NUMBER_3F, 0x9856, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x9852 DIGIT? */ XT_DIGIT_3F, 0x9862, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0x985e ? */ XT__3F, 0x9868, 0x3f01,
/* 0x9864 . */ XT__2E, 0x986e, 0x2e01,
/* 0x986a U. */ XT_U_2E, 0x9876, 0x5502, 0x2e,
/* 0x9872 U.R */ XT_U_2ER, 0x987e, 0x5503, 0x522e,
/* 0x987a .R */ XT__2ER, 0x9886, 0x2e02, 0x52,
/* 0x9882 DECIMAL */ XT_DECIMAL, 0x9892, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0x988e HEX */ XT_HEX, 0x989a, 0x4803, 0x5845,
/* 0x9896 str */ XT_str, 0x98a2, 0x7303, 0x7274,
/* 0x989e .$ */ XT__2E_24, 0x98aa, 0x2e02, 0x24,
/* 0x98a6 TYPE */ XT_TYPE, 0x98b4, 0x5404, 0x5059, 0x45,
/* 0x98b0 SPACES */ XT_SPACES, 0x98c0, 0x5306, 0x4150, 0x4543, 0x53,
/* 0x98bc CHARS */ XT_CHARS, 0x98ca, 0x4305, 0x4148, 0x5352,
/* 0x98c6 SPACE */ XT_SPACE, 0x98d4, 0x5305, 0x4150, 0x4543,
/* 0x98d0 EMIT */ XT_EMIT, 0x98de, 0x4504, 0x494d, 0x54,
/* 0x98da #> */ XT__23_3E, 0x98e6, 0x2302, 0x3e,
/* 0x98e2 SIGN */ XT_SIGN, 0x98f0, 0x5304, 0x4749, 0x4e,
/* 0x98ec #S */ XT__23S, 0x98f8, 0x2302, 0x53,
/* 0x98f4 # */ XT__23, 0x98fe, 0x2301,
/* 0x98fa HOLD */ XT_HOLD, 0x9908, 0x4804, 0x4c4f, 0x44,
/* 0x9904 <# */ XT__3C_23, 0x9910, 0x3c02, 0x23,
/* 0x990c EXTRACT */ XT_EXTRACT, 0x991c, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0x9918 DIGIT */ XT_DIGIT, 0x9926, 0x4405, 0x4749, 0x5449,
/* 0x9922 PACK$ */ XT_PACK_24, 0x9930, 0x5005, 0x4341, 0x244b,
/* 0x992c -TRAILING */ XT__2DTRAILING, 0x993e, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0x993a FILL */ XT_FILL, 0x9948, 0x4604, 0x4c49, 0x4c,
/* 0x9944 CMOVE */ XT_CMOVE, 0x9952, 0x4305, 0x4f4d, 0x4556,
/* 0x994e COUNT */ XT_COUNT, 0x995c, 0x4305, 0x554f, 0x544e,
/* 0x9958 @EXECUTE */ XT__40EXECUTE, 0x996a, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0x9966 TIB */ XT_TIB, 0x9972, 0x5403, 0x4249,
/* 0x996e PAD */ XT_PAD, 0x997a, 0x5003, 0x4441,
/* 0x9976 vCREATE */ XT_vCREATE, 0x9986, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x9982 vALIGN */ XT_vALIGN, 0x9992, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0x998e v, */ XT_v_2C, 0x999a, 0x7602, 0x2c,
/* 0x9996 vHERE */ XT_vHERE, 0x99a4, 0x7605, 0x4548, 0x4552,
/* 0x99a0 2@ */ XT_2_40, 0x99ac, 0x3202, 0x40,
/* 0x99a8 2! */ XT_2_21, 0x99b4, 0x3202, 0x21,
/* 0x99b0 +! */ XT__2B_21, 0x99bc, 0x2b02, 0x21,
/* 0x99b8 PICK */ XT_PICK, 0x99c6, 0x5004, 0x4349, 0x4b,
/* 0x99c2 DEPTH */ XT_DEPTH, 0x99d0, 0x4405, 0x5045, 0x4854,
/* 0x99cc >CHAR */ XT__3ECHAR, 0x99da, 0x3e05, 0x4843, 0x5241,
/* 0x99d6 CELLS */ XT_CELLS, 0x99e4, 0x4305, 0x4c45, 0x534c,
/* 0x99e0 CELL- */ XT_CELL_2D, 0x99ee, 0x4305, 0x4c45, 0x2d4c,
/* 0x99ea * / */ XT__2A_2F, 0x99f6, 0x2a02, 0x2f,
/* 0x99f2 * /MOD */ XT__2A_2FMOD, 0x9a00, 0x2a05, 0x4d2f, 0x444f,
/* 0x99fc M* */ XT_M_2A, 0x9a08, 0x4d02, 0x2a,
/* 0x9a04 * */ XT__2A, 0x9a0e, 0x2a01,
/* 0x9a0a UM* */ XT_UM_2A, 0x9a16, 0x5503, 0x2a4d,
/* 0x9a12 / */ XT__2F, 0x9a1c, 0x2f01,
/* 0x9a18 MOD */ XT_MOD, 0x9a24, 0x4d03, 0x444f,
/* 0x9a20 /MOD */ XT__2FMOD, 0x9a2e, 0x2f04, 0x4f4d, 0x44,
/* 0x9a2a M/MOD */ XT_M_2FMOD, 0x9a38, 0x4d05, 0x4d2f, 0x444f,
/* 0x9a34 UM/MOD */ XT_UM_2FMOD, 0x9a44, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0x9a40 WITHIN */ XT_WITHIN, 0x9a50, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0x9a4c MIN */ XT_MIN, 0x9a58, 0x4d03, 0x4e49,
/* 0x9a54 MAX */ XT_MAX, 0x9a60, 0x4d03, 0x5841,
/* 0x9a5c < */ XT__3C, 0x9a66, 0x3c01,
/* 0x9a62 ud< */ XT_ud_3C, 0x9a6e, 0x7503, 0x3c64,
/* 0x9a6a U< */ XT_U_3C, 0x9a76, 0x5502, 0x3c,
/* 0x9a72 = */ XT__3D, 0x9a7c, 0x3d01,
/* 0x9a78 0= */ XT_0_3D, 0x9a84, 0x3002, 0x3d,
/* 0x9a80 ABS */ XT_ABS, 0x9a8c, 0x4103, 0x5342,
/* 0x9a88 - */ XT__2D, 0x9a92, 0x2d01,
/* 0x9a8e DNEGATE */ XT_DNEGATE, 0x9a9e, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0x9a9a NEGATE */ XT_NEGATE, 0x9aaa, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0x9aa6 INVERT */ XT_INVERT, 0x9ab6, 0x4906, 0x564e, 0x5245, 0x54,
/* 0x9ab2 D+ */ XT_D_2B, 0x9abe, 0x4402, 0x2b,
/* 0x9aba + */ XT__2B, 0x9ac4, 0x2b01,
/* 0x9ac0 2DUP */ XT_2DUP, 0x9ace, 0x3204, 0x5544, 0x50,
/* 0x9aca -ROT */ XT__2DROT, 0x9ad8, 0x2d04, 0x4f52, 0x54,
/* 0x9ad4 ROT */ XT_ROT, 0x9ae0, 0x5203, 0x544f,
/* 0x9adc ?DUP */ XT__3FDUP, 0x9aea, 0x3f04, 0x5544, 0x50,
/* 0x9ae6 WHILE */ XT_WHILE, 0x9af4, 0x5785, 0x4948, 0x454c,
/* 0x9af0 WHEN */ XT_WHEN, 0x9afe, 0x5784, 0x4548, 0x4e,
/* 0x9afa ELSE */ XT_ELSE, 0x9b08, 0x4584, 0x534c, 0x45,
/* 0x9b04 AFT */ XT_AFT, 0x9b10, 0x4183, 0x5446,
/* 0x9b0c THEN */ XT_THEN, 0x9b1a, 0x5484, 0x4548, 0x4e,
/* 0x9b16 REPEAT */ XT_REPEAT, 0x9b26, 0x5286, 0x5045, 0x4145, 0x54,
/* 0x9b22 AHEAD */ XT_AHEAD, 0x9b30, 0x4185, 0x4548, 0x4441,
/* 0x9b2c IF */ XT_IF, 0x9b38, 0x4982, 0x46,
/* 0x9b34 AGAIN */ XT_AGAIN, 0x9b42, 0x4185, 0x4147, 0x4e49,
/* 0x9b3e UNTIL */ XT_UNTIL, 0x9b4c, 0x5585, 0x544e, 0x4c49,
/* 0x9b48 NEXT */ XT_NEXT, 0x9b56, 0x4e84, 0x5845, 0x54,
/* 0x9b52 BEGIN */ XT_BEGIN, 0x9b60, 0x4285, 0x4745, 0x4e49,
/* 0x9b5c FOR */ XT_FOR, 0x9b68, 0x4683, 0x524f,
/* 0x9b64 >RESOLVE */ XT__3ERESOLVE, 0x9b76, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x9b72 >MARK */ XT__3EMARK, 0x9b80, 0x3e05, 0x414d, 0x4b52,
/* 0x9b7c <RESOLVE */ XT__3CRESOLVE, 0x9b8e, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x9b8a <MARK */ XT__3CMARK, 0x9b98, 0x3c05, 0x414d, 0x4b52,
/* 0x9b94 CREATE */ XT_CREATE, 0x9ba4, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x9ba0 create */ XT_create, 0x9bb0, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x9bac LITERAL */ XT_LITERAL, 0x9bbc, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0x9bb8 COMPILE */ XT_COMPILE, 0x9bc8, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0x9bc4 [COMPILE] */ XT__5BCOMPILE_5D, 0x9bd6, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x9bd2 , */ XT__2C, 0x9bdc, 0x2c01,
/* 0x9bd8 CELL+ */ XT_CELL_2B, 0x9be6, 0x4305, 0x4c45, 0x2b4c,
/* 0x9be2 HERE */ XT_HERE, 0x9bf0, 0x4804, 0x5245, 0x45,
/* 0x9bec NIP */ XT_NIP, 0x9bf8, 0x4e03, 0x5049,
/* 0x9bf4 \T */ XT__5CT, 0x9c00, 0x5c02, 0x54,
/* 0x9bfc \ */ XT__5C, 0x9c06, 0x5c81,
/* 0x9c02 ( */ XT__28, 0x9c0c, 0x2881,
/* 0x9c08 IMMEDIATE */ XT_IMMEDIATE, 0x9c1a, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0x9c16 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x9c2c, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0x9c28 setHeaderBits */ XT_setHeaderBits, 0x9c3e, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0x9c3a 2DROP */ XT_2DROP, 0x9c48, 0x3205, 0x5244, 0x504f,
/* 0x9c44 VP */ XT_VP, 0x9c50, 0x5602, 0x50,
/* 0x9c4c LAST */ XT_LAST, 0x9c5a, 0x4c04, 0x5341, 0x54,
/* 0x9c56 NP */ XT_NP, 0x9c62, 0x4e02, 0x50,
/* 0x9c5e CP */ XT_CP, 0x9c6a, 0x4302, 0x50,
/* 0x9c66 CURRENT */ XT_CURRENT, 0x9c76, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0x9c72 CONTEXT */ XT_CONTEXT, 0x9c82, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0x9c7e HANDLER */ XT_HANDLER, 0x9c8e, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0x9c8a HLD */ XT_HLD, 0x9c96, 0x4803, 0x444c,
/* 0x9c92 'NUMBER */ XT__27NUMBER, 0x9ca2, 0x2707, 0x554e, 0x424d, 0x5245,
/* 0x9c9e 'EVAL */ XT__27EVAL, 0x9cac, 0x2705, 0x5645, 0x4c41,
/* 0x9ca8 CSP */ XT_CSP, 0x9cb4, 0x4303, 0x5053,
/* 0x9cb0 #TIB */ XT__23TIB, 0x9cbe, 0x2304, 0x4954, 0x42,
/* 0x9cba >IN */ XT__3EIN, 0x9cc6, 0x3e03, 0x4e49,
/* 0x9cc2 SPAN */ XT_SPAN, 0x9cd0, 0x5304, 0x4150, 0x4e,
/* 0x9ccc temp */ XT_temp, 0x9cda, 0x7404, 0x6d65, 0x70,
/* 0x9cd6 BASE */ XT_BASE, 0x9ce4, 0x4204, 0x5341, 0x45,
/* 0x9ce0 'PROMPT */ XT__27PROMPT, 0x9cf0, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0x9cec 'ECHO */ XT__27ECHO, 0x9cfa, 0x2705, 0x4345, 0x4f48,
/* 0x9cf6 'TAP */ XT__27TAP, 0x9d04, 0x2704, 0x4154, 0x50,
/* 0x9d00 'EXPECT */ XT__27EXPECT, 0x9d10, 0x2707, 0x5845, 0x4550, 0x5443,
/* 0x9d0c 'EMIT */ XT__27EMIT, 0x9d1a, 0x2705, 0x4d45, 0x5449,
/* 0x9d16 '?KEY */ XT__27_3FKEY, 0x9d24, 0x2705, 0x4b3f, 0x5945,
/* 0x9d20 RP0 */ XT_RP0, 0x9d2c, 0x5203, 0x3050,
/* 0x9d28 SP0 */ XT_SP0, 0x9d34, 0x5303, 0x3050,
/* 0x9d30 TEST */ XT_TEST, 0x9d3e, 0x5404, 0x5345, 0x54,
/* 0x9d3a debugPrintTIB */ XT_debugPrintTIB, 0x9d50, 0x640d, 0x6265, 0x6775, 0x7250, 0x6e69, 0x5474, 0x4249,
/* 0x9d4c Fbreak */ XT_Fbreak, 0x9d5c, 0x4606, 0x7262, 0x6165, 0x6b,
/* 0x9d58 testing3 */ XT_testing3, 0x9d6a, 0x7408, 0x7365, 0x6974, 0x676e, 0x33,
/* 0x9d66 debugNA */ XT_debugNA, 0x9d76, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0x9d72 ' */ XT__27, 0x9d7c, 0x2701,
/* 0x9d78 ; */ XT__3B, 0x9d82, 0x3b81,
/* 0x9d7e : */ XT__3A, 0x9d88, 0x3a01,
/* 0x9d84 ] */ XT__5D, 0x9d8e, 0x5d01,
/* 0x9d8a [ */ XT__5B, 0x9d94, 0x5b81,
/* 0x9d90 $INTERPRET */ XT__24INTERPRET, 0x9da4, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x9da0 $COMPILE */ XT__24COMPILE, 0x9db2, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x9dae NUMBER? */ XT_NUMBER_3F, 0x9dbe, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x9dba TOKEN */ XT_TOKEN, 0x9dc8, 0x5405, 0x4b4f, 0x4e45,
/* 0x9dc4 PARSE */ XT_PARSE, 0x9dd2, 0x5005, 0x5241, 0x4553,
/* 0x9dce userAreaSave */ XT_userAreaSave, 0x9de4, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0x9de0 userAreaInit */ XT_userAreaInit, 0x9df6, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0x9df2 UM+ */ XT_UM_2B, 0x9dfe, 0x5503, 0x2b4d,
/* 0x9dfa XOR */ XT_XOR, 0x9e06, 0x5803, 0x524f,
/* 0x9e02 OR */ XT_OR, 0x9e0e, 0x4f02, 0x52,
/* 0x9e0a AND */ XT_AND, 0x9e16, 0x4103, 0x444e,
/* 0x9e12 0< */ XT_0_3C, 0x9e1e, 0x3002, 0x3c,
/* 0x9e1a OVER */ XT_OVER, 0x9e28, 0x4f04, 0x4556, 0x52,
/* 0x9e24 SWAP */ XT_SWAP, 0x9e32, 0x5304, 0x4157, 0x50,
/* 0x9e2e DUP */ XT_DUP, 0x9e3a, 0x4403, 0x5055,
/* 0x9e36 DROP */ XT_DROP, 0x9e44, 0x4404, 0x4f52, 0x50,
/* 0x9e40 SP! */ XT_SP_21, 0x9e4c, 0x5303, 0x2150,
/* 0x9e48 SP@ */ XT_SP_40, 0x9e54, 0x5303, 0x4050,
/* 0x9e50 >R */ XT__3ER, 0x9e5c, 0x3e02, 0x52,
/* 0x9e58 R@ */ XT_R_40, 0x9e64, 0x5202, 0x40,
/* 0x9e60 R> */ XT_R_3E, 0x9e6c, 0x5202, 0x3e,
/* 0x9e68 RP! */ XT_RP_21, 0x9e74, 0x5203, 0x2150,
/* 0x9e70 RP@ */ XT_RP_40, 0x9e7c, 0x5203, 0x4050,
/* 0x9e78 C! */ XT_C_21, 0x9e84, 0x4302, 0x21,
/* 0x9e80 C@ */ XT_C_40, 0x9e8c, 0x4302, 0x40,
/* 0x9e88 @ */ XT__40, 0x9e92, 0x4001,
/* 0x9e8e ! */ XT__21, 0x9e98, 0x2101,
/* 0x9e94 branch */ XT_branch, 0x9ea4, 0x6206, 0x6172, 0x636e, 0x68,
/* 0x9ea0 ?branch */ XT__3Fbranch, 0x9eb0, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0x9eac next */ XT_next, 0x9eba, 0x6e04, 0x7865, 0x74,
/* 0x9eb6 DOES> */ XT_DOES_3E, 0x9ec4, 0x4405, 0x454f, 0x3e53,
/* 0x9ec0 doLIT */ XT_doLIT, 0x9ece, 0x6405, 0x4c6f, 0x5449,
/* 0x9eca !IO */ XT__21IO, 0x9ed6, 0x2103, 0x4f49,
/* 0x9ed2 TX! */ XT_TX_21, 0x9ede, 0x5403, 0x2158,
/* 0x9eda ?RX */ XT__3FRX, 0x9ee6, 0x3f03, 0x5852,
/* 0x9ee2 EXECUTE */ XT_EXECUTE, 0x9ef2, 0x4507, 0x4558, 0x5543, 0x4554,
/* 0x9eee EXIT */ XT_EXIT, 0x9efc, 0x4504, 0x4958, 0x54,
/* 0x9ef8 BYE */ XT_BYE, 0x9f04, 0x4203, 0x4559,
/* 0x9f00 MS */ XT_MS, 0x9f0c, 0x4d02, 0x53,
/* 0x9f08 >NAME */ XT__3ENAME, 0x9f16, 0x3e05, 0x414e, 0x454d,
/* 0x9f12 $,n */ XT__24_2Cn, 0x9f1e, 0x2403, 0x6e2c,
/* 0x9f1a OVERT */ XT_OVERT, 0x9f28, 0x4f05, 0x4556, 0x5452,
/* 0x9f24 find */ XT_find, 0x9f32, 0x6604, 0x6e69, 0x64,
/* 0x9f2e ALIGNED */ XT_ALIGNED, 0x9f3e, 0x4107, 0x494c, 0x4e47, 0x4445,
/* 0x9f3a tokenCreate */ XT_tokenCreate, 0x9f4e, 0x740b, 0x6b6f, 0x6e65, 0x7243, 0x6165, 0x6574,
/* 0x9f4a tokenVar */ XT_tokenVar, 0x9f5c, 0x7408, 0x6b6f, 0x6e65, 0x6156, 0x72,
/* 0x9f58 tokenUser */ XT_tokenUser, 0x9f6a, 0x7409, 0x6b6f, 0x6e65, 0x7355, 0x7265,
/* 0x9f66 tokenDoList */ XT_tokenDoList, 0x9f7a, 0x740b, 0x6b6f, 0x6e65, 0x6f44, 0x694c, 0x7473,
/* 0x9f76 tokenNextVal */ XT_tokenNextVal, 0x9f8c, 0x740c, 0x6b6f, 0x6e65, 0x654e, 0x7478, 0x6156, 0x6c,
/* 0x9f88 tokenVocabulary */ XT_tokenVocabulary, 0x9fa0, 0x740f, 0x6b6f, 0x6e65, 0x6f56, 0x6163, 0x7562, 0x616c, 0x7972,
/* 0x9f9c BL */ XT_BL, 0x9fa8, 0x4202, 0x4c,
/* 0x9fa4 BYTEMASK */ XT_BYTEMASK, 0x9fb6, 0x4208, 0x5459, 0x4d45, 0x5341, 0x4b,
/* 0x9fb2 IMED */ XT_IMED, 0x9fc0, 0x4904, 0x454d, 0x44,
/* 0x9fbc COMP */ XT_COMP, 0x9fca, 0x4304, 0x4d4f, 0x50,
/* 0x9fc6 TIB0 */ XT_TIB0, 0x9fd4, 0x5404, 0x4249, 0x30,
/* 0x9fd0 CELLMASK */ XT_CELLMASK, 0x9fe2, 0x4308, 0x4c45, 0x4d4c, 0x5341, 0x4b,
/* 0x9fde CELLbits */ XT_CELLbits, 0x9ff0, 0x4308, 0x4c45, 0x624c, 0x7469, 0x73,
/* 0x9fec CELLL */ XT_CELLL, 0x9ffa, 0x4305, 0x4c45, 0x4c4c,
/* 0x9ff6 FORTH */ XT_FORTH, 0, 0x4605, 0x524f, 0x4854,
};
// === End of Arduino source from dictionary === 
