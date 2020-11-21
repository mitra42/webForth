/*
 * NOTES
 * See https://www.arduino.cc/reference/en/language/variables/utilities/progmem/ for reading program memory (where dictionary will be)
 */

// === Dumping Arduino source from dictionary ===
#define RAM0 32768
#define CELLL 2
#define ROMCELLS undefined
#define TIB0 33392
#define UPP 33664
#define UZERO 0
#define CELLTYPE unsigned
#define ROMCELLS 4096
#define RAMCELLS 512
#define SPP 33376
#define RP0 33648
#define NAMEE 33120
#define CODEE 32768
/* === Dumping Arduino source from names === */
#define XT_WARM 0x11fe /* WARM*/
#define XT_COLD 0x11e6 /* COLD*/
#define XT__27BOOT 0x11e0 /* 'BOOT*/
#define XT_EMPTY 0x11d0 /* EMPTY*/
#define XT_hi 0x11c8 /* hi*/
#define XT_version 0x1194 /* version*/
#define XT_VER 0x1190 /* VER*/
#define XT_SEE 0x110a /* SEE*/
#define XT_FORTH_3ENAME 0x10cc /* FORTH>NAME*/
#define XT_WORDS 0x10aa /* WORDS*/
#define XT__2EID 0x108a /* .ID*/
#define XT__3FCSP 0x1070 /* ?CSP*/
#define XT__21CSP 0x1066 /* !CSP*/
#define XT__2EFREE 0x105a /* .FREE*/
#define XT__2EBASE 0x1048 /* .BASE*/
#define XT__2ES 0x1028 /* .S*/
#define XT_DUMP 0xfe4 /* DUMP*/
#define XT_dm_2B 0xfbc /* dm+*/
#define XT__5FTYPE 0xf9e /* _TYPE*/
#define XT_CONSTANT 0xf8e /* CONSTANT*/
#define XT_VARIABLE 0xf82 /* VARIABLE*/
#define XT_vCREATE 0xf66 /* vCREATE*/
#define XT_CREATE 0xf5e /* CREATE*/
#define XT_create 0xf4c /* create*/
#define XT_USER 0xf3e /* USER*/
#define XT__3A 0xf30 /* :*/
#define XT__5D 0xf24 /* ]*/
#define XT__3B 0xf18 /* ;*/
#define XT_OVERT 0xf0a /* OVERT*/
#define XT__24COMPILE 0xedc /* $COMPILE*/
#define XT__24_2Cn 0xea0 /* $,n*/
#define XT__3FUNIQUE 0xe84 /* ?UNIQUE*/
#define XT__24_22 0xe7a /* $"*/
#define XT_RECURSE 0xe6e /* RECURSE*/
#define XT__5BCOMPILE_5D 0xe66 /* [COMPILE]*/
#define XT_vALLOT 0xe50 /* vALLOT*/
#define XT_ALLOT 0xe48 /* ALLOT*/
#define XT__27 0xe38 /* '*/
#define XT_quit1 0xe24 /* quit1*/
#define XT_QUIT 0xe04 /* QUIT*/
#define XT_quitError 0xdd4 /* quitError*/
#define XT_que 0xdcc /* que*/
#define XT_CONSOLE 0xdbe /* CONSOLE*/
#define XT_I_2FO 0xdb6 /* I/O*/
#define XT_HAND 0xda4 /* HAND*/
#define XT_FILE 0xd92 /* FILE*/
#define XT_XIO 0xd7a /* XIO*/
#define XT_PRESET 0xd68 /* PRESET*/
#define XT__5B 0xd5c /* [*/
#define XT_EVAL 0xd3e /* EVAL*/
#define XT__3FSTACK 0xd2a /* ?STACK*/
#define XT__2EOK 0xd10 /* .OK*/
#define XT__24INTERPRET 0xcdc /* $INTERPRET*/
#define XT__2E_22 0xcd2 /* ."*/
#define XT_ABORT_22 0xcc8 /* ABORT"*/
#define XT__24_2C_22 0xcb4 /* $,"*/
#define XT_abort_22 0xca4 /* abort"*/
#define XT_ABORT 0xc9c /* ABORT*/
#define XT_NULL_24 0xc96 /* NULL$*/
#define XT_THROW 0xc7a /* THROW*/
#define XT_CATCH 0xc56 /* CATCH*/
#define XT_QUERY 0xc3a /* QUERY*/
#define XT_EXPECT 0xc2c /* EXPECT*/
#define XT_accept 0xbf4 /* accept*/
#define XT_kTAP 0xbb2 /* kTAP*/
#define XT_TAP 0xb9e /* TAP*/
#define XT__5EH 0xb72 /* ^H*/
#define XT_NAME_3F 0xb38 /* NAME?*/
#define XT_FORTHfind 0xac6 /* FORTHfind*/
#define XT_SAME_3F 0xa92 /* SAME?*/
#define XT_NAME_3E 0xa84 /* NAME>*/
#define XT_WORD 0xa7a /* WORD*/
#define XT_TOKEN 0xa60 /* TOKEN*/
#define XT__2E_28 0xa54 /* .(*/
#define XT_CTRL 0xa48 /* CTRL*/
#define XT_CHAR 0xa3c /* CHAR*/
#define XT_PARSE 0xa1c /* PARSE*/
#define XT_parse 0x97a /* parse*/
#define XT__2E_22_7C 0x972 /* ."|*/
#define XT__24_22_7C 0x96c /* $"|*/
#define XT_do_24 0x956 /* do$*/
#define XT_CR 0x946 /* CR*/
#define XT_PACE 0x93c /* PACE*/
#define XT_NUF_3F 0x926 /* NUF?*/
#define XT_KEY 0x910 /* KEY*/
#define XT__3FKEY 0x908 /* ?KEY*/
#define XT_NUMBER_3F 0x862 /* NUMBER?*/
#define XT_DIGIT_3F 0x834 /* DIGIT?*/
#define XT__3F 0x82c /* ?*/
#define XT__2E 0x810 /* .*/
#define XT_U_2E 0x802 /* U.*/
#define XT_U_2ER 0x7ec /* U.R*/
#define XT__2ER 0x7da /* .R*/
#define XT_DECIMAL 0x7ce /* DECIMAL*/
#define XT_HEX 0x7c2 /* HEX*/
#define XT_str 0x7ae /* str*/
#define XT__2E_24 0x7a6 /* .$*/
#define XT_TYPE 0x78a /* TYPE*/
#define XT_SPACES 0x782 /* SPACES*/
#define XT_CHARS 0x766 /* CHARS*/
#define XT_SPACE 0x75e /* SPACE*/
#define XT_EMIT 0x756 /* EMIT*/
#define XT__23_3E 0x746 /* #>*/
#define XT_SIGN 0x736 /* SIGN*/
#define XT__23S 0x726 /* #S*/
#define XT__23 0x71a /* #*/
#define XT_HOLD 0x704 /* HOLD*/
#define XT__3C_23 0x6fa /* <#*/
#define XT_EXTRACT 0x6ea /* EXTRACT*/
#define XT_DIGIT 0x6d0 /* DIGIT*/
#define XT_PACK_24 0x696 /* PACK$*/
#define XT__2DTRAILING 0x66a /* -TRAILING*/
#define XT_FILL 0x64c /* FILL*/
#define XT_CMOVE 0x624 /* CMOVE*/
#define XT_COUNT 0x614 /* COUNT*/
#define XT__40EXECUTE 0x600 /* @EXECUTE*/
#define XT_TIB 0x5f6 /* TIB*/
#define XT_PAD 0x5ea /* PAD*/
#define XT_vCREATE 0x5ce /* vCREATE*/
#define XT_vALIGN 0x5c0 /* vALIGN*/
#define XT_v_2C 0x5a0 /* v,*/
#define XT_vHERE 0x58e /* vHERE*/
#define XT_2_40 0x580 /* 2@*/
#define XT_2_21 0x572 /* 2!*/
#define XT__2B_21 0x562 /* +!*/
#define XT_PICK 0x550 /* PICK*/
#define XT_DEPTH 0x53e /* DEPTH*/
#define XT__3ECHAR 0x520 /* >CHAR*/
#define XT_CELLS 0x518 /* CELLS*/
#define XT_CELL_2D 0x510 /* CELL-*/
#define XT__2A_2F 0x508 /* * /*/
#define XT__2A_2FMOD 0x4fc /* * /MOD*/
#define XT_M_2A 0x4e0 /* M**/
#define XT__2A 0x4d8 /* **/
#define XT_UM_2A 0x49e /* UM**/
#define XT__2F 0x496 /* /*/
#define XT_MOD 0x48e /* MOD*/
#define XT__2FMOD 0x482 /* /MOD*/
#define XT_M_2FMOD 0x44c /* M/MOD*/
#define XT_UM_2FMOD 0x3e8 /* UM/MOD*/
#define XT_WITHIN 0x3d8 /* WITHIN*/
#define XT_MIN 0x3c6 /* MIN*/
#define XT_MAX 0x3b6 /* MAX*/
#define XT__3C 0x39e /* <*/
#define XT_U_3C 0x386 /* U<*/
#define XT__3D 0x372 /* =*/
#define XT_0_3D 0x35e /* 0=*/
#define XT_ABS 0x350 /* ABS*/
#define XT__2D 0x348 /* -*/
#define XT_DNEGATE 0x334 /* DNEGATE*/
#define XT_NEGATE 0x328 /* NEGATE*/
#define XT_INVERT 0x31e /* INVERT*/
#define XT_D_2B 0x30a /* D+*/
#define XT__2B 0x302 /* +*/
#define XT_2DUP 0x2fa /* 2DUP*/
#define XT__2DROT 0x2ee /* -ROT*/
#define XT_ROT 0x2e2 /* ROT*/
#define XT__3FDUP 0x2d6 /* ?DUP*/
#define XT_WHILE 0x2ce /* WHILE*/
#define XT_WHEN 0x2c6 /* WHEN*/
#define XT_ELSE 0x2bc /* ELSE*/
#define XT_AFT 0x2b0 /* AFT*/
#define XT_THEN 0x2aa /* THEN*/
#define XT_REPEAT 0x2a2 /* REPEAT*/
#define XT_AHEAD 0x298 /* AHEAD*/
#define XT_IF 0x28e /* IF*/
#define XT_AGAIN 0x284 /* AGAIN*/
#define XT_UNTIL 0x27a /* UNTIL*/
#define XT_NEXT 0x270 /* NEXT*/
#define XT_BEGIN 0x26a /* BEGIN*/
#define XT_FOR 0x260 /* FOR*/
#define XT__3ERESOLVE 0x256 /* >RESOLVE*/
#define XT__3EMARK 0x24a /* >MARK*/
#define XT__3CRESOLVE 0x244 /* <RESOLVE*/
#define XT__3CMARK 0x23e /* <MARK*/
#define XT_CREATE 0x236 /* CREATE*/
#define XT_create 0x224 /* create*/
#define XT_LITERAL 0x21a /* LITERAL*/
#define XT_COMPILE 0x20a /* COMPILE*/
#define XT__5BCOMPILE_5D 0x202 /* [COMPILE]*/
#define XT__2C 0x1f0 /* ,*/
#define XT_CELL_2B 0x1e6 /* CELL+*/
#define XT_HERE 0x1de /* HERE*/
#define XT_NIP 0x1d6 /* NIP*/
#define XT__5CT 0x1ca /* \T*/
#define XT__5C 0x1be /* \*/
#define XT__28 0x1b2 /* (*/
#define XT_IMMEDIATE 0x1aa /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x1a2 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x190 /* setHeaderBits*/
#define XT_2DROP 0x188 /* 2DROP*/
#define XT_VP 0x184 /* VP*/
#define XT_LAST 0x180 /* LAST*/
#define XT_NP 0x17c /* NP*/
#define XT_CP 0x178 /* CP*/
#define XT_CURRENT 0x174 /* CURRENT*/
#define XT_CONTEXT 0x170 /* CONTEXT*/
#define XT_HANDLER 0x16c /* HANDLER*/
#define XT_HLD 0x168 /* HLD*/
#define XT__27NUMBER 0x164 /* 'NUMBER*/
#define XT__27EVAL 0x160 /* 'EVAL*/
#define XT_CSP 0x15c /* CSP*/
#define XT__23TIB 0x158 /* #TIB*/
#define XT__3EIN 0x154 /* >IN*/
#define XT_SPAN 0x150 /* SPAN*/
#define XT_temp 0x14c /* temp*/
#define XT_BASE 0x148 /* BASE*/
#define XT__27PROMPT 0x144 /* 'PROMPT*/
#define XT__27ECHO 0x140 /* 'ECHO*/
#define XT__27TAP 0x13c /* 'TAP*/
#define XT__27EXPECT 0x138 /* 'EXPECT*/
#define XT__27EMIT 0x134 /* 'EMIT*/
#define XT__27_3FKEY 0x130 /* '?KEY*/
#define XT_RP0 0x12c /* RP0*/
#define XT_SP0 0x128 /* SP0*/
#define XT_TEST 0x126 /* TEST*/
#define XT_debugPrintTIB 0x124 /* debugPrintTIB*/
#define XT_Fbreak 0x122 /* Fbreak*/
#define XT_testing3 0x120 /* testing3*/
#define XT_debugNA 0x11e /* debugNA*/
#define XT__27 0x11c /* '*/
#define XT__3B 0x11a /* ;*/
#define XT__3A 0x118 /* :*/
#define XT__5D 0x116 /* ]*/
#define XT__5B 0x114 /* [*/
#define XT__24INTERPRET 0x112 /* $INTERPRET*/
#define XT__24COMPILE 0x110 /* $COMPILE*/
#define XT_NUMBER_3F 0x10e /* NUMBER?*/
#define XT_TOKEN 0x10c /* TOKEN*/
#define XT_PARSE 0x10a /* PARSE*/
#define XT_userAreaSave 0x108 /* userAreaSave*/
#define XT_userAreaInit 0x106 /* userAreaInit*/
#define XT_UM_2B 0x104 /* UM+*/
#define XT_XOR 0x102 /* XOR*/
#define XT_OR 0x100 /* OR*/
#define XT_AND 0xfe /* AND*/
#define XT_0_3C 0xfc /* 0<*/
#define XT_OVER 0xfa /* OVER*/
#define XT_SWAP 0xf8 /* SWAP*/
#define XT_DUP 0xf6 /* DUP*/
#define XT_DROP 0xf4 /* DROP*/
#define XT_SP_21 0xf2 /* SP!*/
#define XT_SP_40 0xf0 /* SP@*/
#define XT__3ER 0xee /* >R*/
#define XT_R_40 0xec /* R@*/
#define XT_R_3E 0xea /* R>*/
#define XT_RP_21 0xe8 /* RP!*/
#define XT_RP_40 0xe6 /* RP@*/
#define XT_C_21 0xe4 /* C!*/
#define XT_C_40 0xe2 /* C@*/
#define XT__40 0xe0 /* @*/
#define XT__21 0xde /* !*/
#define XT_branch 0xdc /* branch*/
#define XT__3Fbranch 0xda /* ?branch*/
#define XT_next 0xd8 /* next*/
#define XT_DOES_3E 0xd6 /* DOES>*/
#define XT_doLIT 0xd4 /* doLIT*/
#define XT__21IO 0xd2 /* !IO*/
#define XT_TX_21 0xd0 /* TX!*/
#define XT__3FRX 0xce /* ?RX*/
#define XT_EXECUTE 0xcc /* EXECUTE*/
#define XT_EXIT 0xca /* EXIT*/
#define XT_BYE 0xc8 /* BYE*/
#define XT_MS 0xc6 /* MS*/
#define XT__3ENAME 0xc4 /* >NAME*/
#define XT__24_2Cn 0xc2 /* $,n*/
#define XT_OVERT 0xc0 /* OVERT*/
#define XT_find 0xbe /* find*/
#define XT_ALIGNED 0xbc /* ALIGNED*/
#define XT_tokenCreate 0xb8 /* tokenCreate*/
#define XT_tokenVar 0xb4 /* tokenVar*/
#define XT_tokenUser 0xb0 /* tokenUser*/
#define XT_tokenDoList 0xac /* tokenDoList*/
#define XT_tokenNextVal 0xa8 /* tokenNextVal*/
#define XT_tokenVocabulary 0xa4 /* tokenVocabulary*/
#define XT_BL 0xa0 /* BL*/
#define XT__3DBYTEMASK 0x9c /* =BYTEMASK*/
#define XT__3DIMED 0x98 /* =IMED*/
#define XT__3DCOMP 0x94 /* =COMP*/
#define XT_TIB0 0x90 /* TIB0*/
#define XT_CELLMASK 0x8c /* CELLMASK*/
#define XT_CELLbits 0x88 /* CELLbits*/
#define XT_CELLL 0x84 /* CELLL*/
#define XT_FORTH 0x80 /* FORTH*/
/* === Function tokens === */#define F_tokenVocabulary 1
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
const void (*f[62])() = {
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
/* 0 */ 0,
/* 2 */ 0,
/* 4 */ 0,
/* 6 */ 0,
/* 8 */ 0x8260,
/* 0xa */ 0x8370,
/* 0xc */ XT__3FRX,
/* 0xe */ XT_TX_21,
/* 0x10 */ XT_accept,
/* 0x12 */ 0,
/* 0x14 */ XT_TX_21,
/* 0x16 */ 0,
/* 0x18 */ 0xa,
/* 0x1a */ 0x20,
/* 0x1c */ 0,
/* 0x1e */ 0xd,
/* 0x20 */ 0x3a,
/* 0x22 */ 0x8270,
/* 0x24 */ 0,
/* 0x26 */ XT__24INTERPRET,
/* 0x28 */ XT_NUMBER_3F,
/* 0x2a */ 0,
/* 0x2c */ 0,
/* 0x2e */ 0x8000,
/* 0x30 */ 0,
/* 0x32 */ 0,
/* 0x34 */ 0,
/* 0x36 */ 0,
/* 0x38 */ 0,
/* 0x3a */ 0,
/* 0x3c */ 0,
/* 0x3e */ 0,
/* 0x40 */ 0x8000,
/* 0x42 */ 0x8000,
/* 0x44 */ 0x8004,
/* 0x46 */ 0x8160,
/* 0x48 */ 0x14f6,
/* 0x4a */ 0,
/* 0x4c */ 0,
/* 0x4e */ 0,
/* 0x50 */ 0,
/* 0x52 */ 0,
/* 0x54 */ 0,
/* 0x56 */ 0,
/* 0x58 */ 0,
/* 0x5a */ 0,
/* 0x5c */ 0,
/* 0x5e */ 0,
/* 0x60 */ 0,
/* 0x62 */ 0,
/* 0x64 */ 0,
/* 0x66 */ 0,
/* 0x68 */ 0,
/* 0x6a */ 0,
/* 0x6c */ 0,
/* 0x6e */ 0,
/* 0x70 */ 0,
/* 0x72 */ 0,
/* 0x74 */ 0,
/* 0x76 */ 0,
/* 0x78 */ 0,
/* 0x7a */ 0,
/* 0x7c */ 0,
/* 0x7e */ 0,
/* ==== CODE DICTIONARY ==== */
/* 0x80: FORTH */ F_tokenVocabulary, 0x8000,
/* 0x84: CELLL */ F_tokenNextVal, 2,
/* 0x88: CELLbits */ F_tokenNextVal, 0x10,
/* 0x8c: CELLMASK */ F_tokenNextVal, 0xff1f,
/* 0x90: TIB0 */ F_tokenNextVal, 0x8270,
/* 0x94: =COMP */ F_tokenNextVal, 0x40,
/* 0x98: =IMED */ F_tokenNextVal, XT_FORTH,
/* 0x9c: =BYTEMASK */ F_tokenNextVal, 0x1f,
/* 0xa0: BL */ F_tokenNextVal, 0x20,
/* 0xa4: tokenVocabulary */ F_tokenNextVal, 1,
/* 0xa8: tokenNextVal */ F_tokenNextVal, 2,
/* 0xac: tokenDoList */ F_tokenNextVal, 3,
/* 0xb0: tokenUser */ F_tokenNextVal, 4,
/* 0xb4: tokenVar */ F_tokenNextVal, 5,
/* 0xb8: tokenCreate */ F_tokenNextVal, 6,
/* 0xbc: ALIGNED */ F_ALIGNED,
/* 0xbe: find */ F_jsFind,
/* 0xc0: OVERT */ F_OVERT,
/* 0xc2: $,n */ F_dollarCommaN,
/* 0xc4: >NAME */ F_ToNAME,
/* 0xc6: MS */ F_MS,
/* 0xc8: BYE */ F_BYE,
/* 0xca: EXIT */ F_EXIT,
/* 0xcc: EXECUTE */ F_EXECUTE,
/* 0xce: ?RX */ F_QRX,
/* 0xd0: TX! */ F_TXbang,
/* 0xd2: !IO */ F_bangIO,
/* 0xd4: doLIT */ F_doLIT,
/* 0xd6: DOES> */ F_DOES,
/* 0xd8: next */ F_next,
/* 0xda: ?branch */ F_qBranch,
/* 0xdc: branch */ F_branch,
/* 0xde: ! */ F_store,
/* 0xe0: @ */ F_fetch,
/* 0xe2: C@ */ F_cFetch,
/* 0xe4: C! */ F_cStore,
/* 0xe6: RP@ */ F_RPat,
/* 0xe8: RP! */ F_RPbang,
/* 0xea: R> */ F_Rfrom,
/* 0xec: R@ */ F_Rat,
/* 0xee: >R */ F_toR,
/* 0xf0: SP@ */ F_SPat,
/* 0xf2: SP! */ F_SPbang,
/* 0xf4: DROP */ F_DROP,
/* 0xf6: DUP */ F_DUP,
/* 0xf8: SWAP */ F_SWAP,
/* 0xfa: OVER */ F_OVER,
/* 0xfc: 0< */ F_less0,
/* 0xfe: AND */ F_AND,
/* 0x100: OR */ F_OR,
/* 0x102: XOR */ F_XOR,
/* 0x104: UM+ */ F_UMplus,
/* 0x106: userAreaInit */ F_userAreaInit,
/* 0x108: userAreaSave */ F_userAreaSave,
/* 0x10a: PARSE */ F_PARSE,
/* 0x10c: TOKEN */ F_TOKEN,
/* 0x10e: NUMBER? */ F_NUMBERQ,
/* 0x110: $COMPILE */ F_dCOMPILE,
/* 0x112: $INTERPRET */ F_dINTERPRET,
/* 0x114: [ */ F_openBracket,
/* 0x116: ] */ F_closeBracket,
/* 0x118: : */ F_colon,
/* 0x11a: ; */ F_semicolon,
/* 0x11c: ' */ F_tick,
/* 0x11e: debugNA */ F_debugNA,
/* 0x120: testing3 */ F_testing3,
/* 0x122: Fbreak */ F_Fbreak,
/* 0x124: debugPrintTIB */ F_debugPrintTIB,
/* 0x126: TEST */ F_TEST,
/* 0x128: SP0 */ F_tokenUser, 4,
/* 0x12c: RP0 */ F_tokenUser, 5,
/* 0x130: '?KEY */ F_tokenUser, 6,
/* 0x134: 'EMIT */ F_tokenUser, 7,
/* 0x138: 'EXPECT */ F_tokenUser, 8,
/* 0x13c: 'TAP */ F_tokenUser, 9,
/* 0x140: 'ECHO */ F_tokenUser, 0xa,
/* 0x144: 'PROMPT */ F_tokenUser, 0xb,
/* 0x148: BASE */ F_tokenUser, 0xc,
/* 0x14c: temp */ F_tokenUser, 0xd,
/* 0x150: SPAN */ F_tokenUser, 0xe,
/* 0x154: >IN */ F_tokenUser, 0xf,
/* 0x158: #TIB */ F_tokenUser, 0x10,
/* 0x15c: CSP */ F_tokenUser, 0x12,
/* 0x160: 'EVAL */ F_tokenUser, 0x13,
/* 0x164: 'NUMBER */ F_tokenUser, 0x14,
/* 0x168: HLD */ F_tokenUser, 0x15,
/* 0x16c: HANDLER */ F_tokenUser, 0x16,
/* 0x170: CONTEXT */ F_tokenUser, 0x17,
/* 0x174: CURRENT */ F_tokenUser, 0x20,
/* 0x178: CP */ F_tokenUser, 0x22,
/* 0x17c: NP */ F_tokenUser, 0x23,
/* 0x180: LAST */ F_tokenUser, 0x24,
/* 0x184: VP */ F_tokenUser, 0x25,
/* 0x188: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT,
/* 0x190: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT,
/* 0x1a2: COMPILE-ONLY */ F_tokenDoList, XT__3DCOMP, XT_setHeaderBits, XT_EXIT,
/* 0x1aa: IMMEDIATE */ F_tokenDoList, XT__3DIMED, XT_setHeaderBits, XT_EXIT,
/* 0x1b2: ( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_2DROP, XT_EXIT,
/* 0x1be: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT,
/* 0x1ca: \T */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT,
/* 0x1d6: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT,
/* 0x1de: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT,
/* 0x1e6: CELL+ */ F_tokenDoList, XT_CELLL, XT_UM_2B, XT_DROP, XT_EXIT,
/* 0x1f0: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT,
/* 0x202: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT,
/* 0x20a: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT,
/* 0x21a: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLIT, XT__2C, XT_EXIT,
/* 0x224: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT,
/* 0x236: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT,
/* 0x23e: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT,
/* 0x244: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT,
/* 0x24a: >MARK */ F_tokenDoList, XT_HERE, XT_doLIT, 0, XT__2C, XT_EXIT,
/* 0x256: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT,
/* 0x260: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT,
/* 0x26a: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT,
/* 0x270: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT,
/* 0x27a: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT,
/* 0x284: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT,
/* 0x28e: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT,
/* 0x298: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT,
/* 0x2a2: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT,
/* 0x2aa: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT,
/* 0x2b0: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT,
/* 0x2bc: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT,
/* 0x2c6: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT,
/* 0x2ce: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT,
/* 0x2d6: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT,
/* 0x2e2: ROT */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_3E, XT_SWAP, XT_EXIT,
/* 0x2ee: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT,
/* 0x2fa: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT,
/* 0x302: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT,
/* 0x30a: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT,
/* 0x31e: INVERT */ F_tokenDoList, XT_doLIT, 0xffff, XT_XOR, XT_EXIT,
/* 0x328: NEGATE */ F_tokenDoList, XT_INVERT, XT_doLIT, 1, XT__2B, XT_EXIT,
/* 0x334: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLIT, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT,
/* 0x348: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT,
/* 0x350: ABS */ F_tokenDoList, XT_DUP, XT_0_3C, XT__3Fbranch, XT_ABS + 0xc, XT_NEGATE, XT_EXIT,
/* 0x35e: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xe, XT_doLIT, 0, XT_branch, XT_0_3D + 0x12, XT_doLIT, 0xffff, XT_EXIT,
/* 0x372: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xe, XT_doLIT, 0, XT_EXIT, XT_doLIT, 0xffff, XT_EXIT,
/* 0x386: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT,
/* 0x39e: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT,
/* 0x3b6: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT,
/* 0x3c6: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT,
/* 0x3d8: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT,
/* 0x3e8: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x58, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4e, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DROP, XT_doLIT, 1, XT__2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x4c, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLIT, 0xffff, XT_DUP, XT_EXIT,
/* 0x44c: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT,
/* 0x482: /MOD */ F_tokenDoList, XT_OVER, XT_0_3C, XT_SWAP, XT_M_2FMOD, XT_EXIT,
/* 0x48e: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT,
/* 0x496: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT,
/* 0x49e: UM* */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT,
/* 0x4d8: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT,
/* 0x4e0: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT,
/* 0x4fc: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT,
/* 0x508: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT,
/* 0x510: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT,
/* 0x518: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT,
/* 0x520: >CHAR */ F_tokenDoList, XT_doLIT, 0x7f, XT_AND, XT_DUP, XT_doLIT, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLIT, 0x5f, XT_EXIT,
/* 0x53e: DEPTH */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT,
/* 0x550: PICK */ F_tokenDoList, XT_doLIT, 1, XT__2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT,
/* 0x562: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT,
/* 0x572: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT,
/* 0x580: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT,
/* 0x58e: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT,
/* 0x5a0: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT,
/* 0x5c0: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT,
/* 0x5ce: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT,
/* 0x5ea: PAD */ F_tokenDoList, XT_HERE, XT_doLIT, 0x50, XT__2B, XT_EXIT,
/* 0x5f6: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT,
/* 0x600: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x10, XT_EXECUTE, XT_branch, XT__40EXECUTE + 0x12, XT_Fbreak, XT_EXIT,
/* 0x614: COUNT */ F_tokenDoList, XT_DUP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_C_40, XT_EXIT,
/* 0x624: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x20, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_doLIT, 1, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_CMOVE + 8, XT_2DROP, XT_EXIT,
/* 0x64c: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x16, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT,
/* 0x66a: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x22, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x22, XT_R_3E, XT_doLIT, 1, XT__2B, XT_EXIT, XT_next, XT__2DTRAILING + 8, XT_doLIT, 0, XT_EXIT,
/* 0x696: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLIT, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLIT, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_doLIT, 1, XT__2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, XT_EXIT, XT_EXIT,
/* 0x6d0: DIGIT */ F_tokenDoList, XT_doLIT, 9, XT_OVER, XT__3C, XT_doLIT, 7, XT_AND, XT__2B, XT_doLIT, 0x30, XT__2B, XT_EXIT,
/* 0x6ea: EXTRACT */ F_tokenDoList, XT_doLIT, 0, XT_SWAP, XT_UM_2FMOD, XT_SWAP, XT_DIGIT, XT_EXIT,
/* 0x6fa: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT,
/* 0x704: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_doLIT, 1, XT__2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT,
/* 0x71a: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT,
/* 0x726: #S */ F_tokenDoList, XT__23, XT_DUP, XT__3Fbranch, XT__23S + 0xe, XT_branch, XT__23S + 2, XT_EXIT,
/* 0x736: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLIT, 0x2d, XT_HOLD, XT_EXIT,
/* 0x746: #> */ F_tokenDoList, XT_DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT,
/* 0x756: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT,
/* 0x75e: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT,
/* 0x766: CHARS */ F_tokenDoList, XT_SWAP, XT_doLIT, 0, XT_MAX, XT__3ER, XT_branch, XT_CHARS + 0x14, XT_DUP, XT_EMIT, XT_next, XT_CHARS + 0x10, XT_DROP, XT_EXIT,
/* 0x782: SPACES */ F_tokenDoList, XT_BL, XT_CHARS, XT_EXIT,
/* 0x78a: TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT_TYPE + 0x14, XT_DUP, XT_C_40, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT_TYPE + 8, XT_DROP, XT_EXIT,
/* 0x7a6: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT,
/* 0x7ae: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT,
/* 0x7c2: HEX */ F_tokenDoList, XT_doLIT, 0x10, XT_BASE, XT__21, XT_EXIT,
/* 0x7ce: DECIMAL */ F_tokenDoList, XT_doLIT, 0xa, XT_BASE, XT__21, XT_EXIT,
/* 0x7da: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT,
/* 0x7ec: U.R */ F_tokenDoList, XT__3ER, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT,
/* 0x802: U. */ F_tokenDoList, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT,
/* 0x810: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLIT, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT,
/* 0x82c: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT,
/* 0x834: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLIT, 0x30, XT__2D, XT_doLIT, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x26, XT_doLIT, 7, XT__2D, XT_DUP, XT_doLIT, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT,
/* 0x862: NUMBER? */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_doLIT, 0, XT_OVER, XT_COUNT, XT_OVER, XT_C_40, XT_doLIT, 0x24, XT__3D, XT__3Fbranch, XT_NUMBER_3F + 0x30, XT_HEX, XT_SWAP, XT_doLIT, 1, XT__2B, XT_SWAP, XT_doLIT, 1, XT__2D, XT_OVER, XT_C_40, XT_doLIT, 0x2d, XT__3D, XT__3ER, XT_SWAP, XT_R_40, XT__2D, XT_SWAP, XT_R_40, XT__2B, XT__3FDUP, XT__3Fbranch, XT_NUMBER_3F + 0x9a, XT_doLIT, 1, XT__2D, XT__3ER, XT_DUP, XT__3ER, XT_C_40, XT_BASE, XT__40, XT_DIGIT_3F, XT__3Fbranch, XT_NUMBER_3F + 0x8c, XT_SWAP, XT_BASE, XT__40, XT__2A, XT__2B, XT_R_3E, XT_doLIT, 1, XT__2B, XT_next, XT_NUMBER_3F + 0x56, XT_DROP, XT_R_40, XT__3Fbranch, XT_NUMBER_3F + 0x86, XT_NEGATE, XT_SWAP, XT_branch, XT_NUMBER_3F + 0x98, XT_R_3E, XT_R_3E, XT_2DROP, XT_2DROP, XT_doLIT, 0, XT_DUP, XT_R_3E, XT_2DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT,
/* 0x908: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT,
/* 0x910: KEY */ F_tokenDoList, XT_doLIT, 0, XT_MS, XT_doLIT, XT_BYE, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT,
/* 0x926: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLIT, 0xd, XT__3D, XT_EXIT,
/* 0x93c: PACE */ F_tokenDoList, XT_doLIT, 0xb, XT_EMIT, XT_EXIT,
/* 0x946: CR */ F_tokenDoList, XT_doLIT, 0xd, XT_EMIT, XT_doLIT, 0xa, XT_EMIT, XT_EXIT,
/* 0x956: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT,
/* 0x96c: $"| */ F_tokenDoList, XT_do_24, XT_EXIT,
/* 0x972: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT,
/* 0x97a: parse */ F_tokenDoList, XT_temp, XT__21, XT_OVER, XT__3ER, XT_DUP, XT__3Fbranch, XT_parse + 0x9a, XT_doLIT, 1, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x4c, XT__3ER, XT_BL, XT_OVER, XT_C_40, XT__2D, XT_0_3C, XT_INVERT, XT__3Fbranch, XT_parse + 0x4a, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x24, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_DUP, XT_EXIT, XT_R_3E, XT_OVER, XT_SWAP, XT__3ER, XT_temp, XT__40, XT_OVER, XT_C_40, XT__2D, XT_temp, XT__40, XT_BL, XT__3D, XT__3Fbranch, XT_parse + 0x6a, XT_0_3C, XT__3Fbranch, XT_parse + 0x80, XT_doLIT, 1, XT__2B, XT_next, XT_parse + 0x52, XT_DUP, XT__3ER, XT_branch, XT_parse + 0x8e, XT_R_3E, XT_DROP, XT_DUP, XT_doLIT, 1, XT__2B, XT__3ER, XT_OVER, XT__2D, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, XT_OVER, XT_R_3E, XT__2D, XT_EXIT,
/* 0xa1c: PARSE */ F_tokenDoList, XT__3ER, XT_TIB, XT__3EIN, XT__40, XT__2B, XT__23TIB, XT__40, XT__3EIN, XT__40, XT__2D, XT_R_3E, XT_parse, XT__3EIN, XT__2B_21, XT_EXIT,
/* 0xa3c: CHAR */ F_tokenDoList, XT_BL, XT_PARSE, XT_DROP, XT_C_40, XT_EXIT,
/* 0xa48: CTRL */ F_tokenDoList, XT_CHAR, XT_doLIT, 0x1f, XT_AND, XT_EXIT,
/* 0xa54: .( */ F_tokenDoList, XT_doLIT, 0x29, XT_PARSE, XT_TYPE, XT_EXIT,
/* 0xa60: TOKEN */ F_tokenDoList, XT_BL, XT_PARSE, XT__3DBYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT,
/* 0xa7a: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT,
/* 0xa84: NAME> */ F_tokenDoList, XT_doLIT, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT,
/* 0xa92: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 8, XT_doLIT, 0, XT_EXIT,
/* 0xac6: FORTHfind */ F_tokenDoList, XT_SWAP, XT_DUP, XT_C_40, XT_CELLL, XT__2F, XT_temp, XT__21, XT_DUP, XT__40, XT__3ER, XT_CELL_2B, XT_SWAP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTHfind + 0x4a, XT_DUP, XT__40, XT_doLIT, 0xff1f, XT_AND, XT_R_40, XT_XOR, XT__3Fbranch, XT_FORTHfind + 0x3e, XT_CELL_2B, XT_doLIT, 0xffff, XT_branch, XT_FORTHfind + 0x46, XT_CELL_2B, XT_temp, XT__40, XT_SAME_3F, XT_branch, XT_FORTHfind + 0x56, XT_R_3E, XT_DROP, XT_SWAP, XT_CELL_2D, XT_SWAP, XT_EXIT, XT__3Fbranch, XT_FORTHfind + 0x62, XT_CELL_2D, XT_CELL_2D, XT_branch, XT_FORTHfind + 0x1a, XT_R_3E, XT_DROP, XT_NIP, XT_CELL_2D, XT_DUP, XT_NAME_3E, XT_SWAP, XT_EXIT,
/* 0xb38: NAME? */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_NAME_3F + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT_DUP, XT__3ER, XT__40, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x30, XT_find, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x12, XT_R_3E, XT_DROP, XT_EXIT, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT,
/* 0xb72: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLIT, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT,
/* 0xb9e: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_doLIT, 1, XT__2B, XT_EXIT,
/* 0xbb2: kTAP */ F_tokenDoList, XT_DUP, XT_doLIT, 0xd, XT__3D, XT_OVER, XT_doLIT, 0xa, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x3a, XT_doLIT, 8, XT__3D, XT_OVER, XT_doLIT, 0x7f, XT__3D, XT_OR, XT__3Fbranch, XT_kTAP + 0x36, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x38, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT,
/* 0xbf4: accept */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_accept + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLIT, 0x5f, XT_U_3C, XT__3Fbranch, XT_accept + 0x28, XT_TAP, XT_branch, XT_accept + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_accept + 8, XT_DROP, XT_OVER, XT__2D, XT_EXIT,
/* 0xc2c: EXPECT */ F_tokenDoList, XT__27EXPECT, XT__40EXECUTE, XT_SPAN, XT__21, XT_DROP, XT_EXIT,
/* 0xc3a: QUERY */ F_tokenDoList, XT_TIB, XT_doLIT, 0x50, XT__27EXPECT, XT__40EXECUTE, XT__23TIB, XT__21, XT_DROP, XT_doLIT, 0, XT__3EIN, XT__21, XT_EXIT,
/* 0xc56: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLIT, 0, XT_EXIT,
/* 0xc7a: THROW */ F_tokenDoList, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT,
/* 0xc96: NULL$ */ F_tokenCreate, 0, 0,
/* 0xc9c: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT,
/* 0xca4: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT,
/* 0xcb4: $," */ F_tokenDoList, XT_doLIT, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT,
/* 0xcc8: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT,
/* 0xcd2: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT,
/* 0xcdc: $INTERPRET */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24INTERPRET + 0x26, XT_C_40, XT_doLIT, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24INTERPRET + 0x30, XT_EXIT, XT_THROW, XT_EXIT,
/* 0xd10: .OK */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__40, XT__3D, XT__3Fbranch, XT__2EOK + 0x16, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT,
/* 0xd2a: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT,
/* 0xd3e: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x16, XT__27EVAL, XT__40EXECUTE, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT,
/* 0xd5c: [ */ F_tokenDoList, XT_doLIT, XT__24INTERPRET, XT__27EVAL, XT__21, XT_EXIT,
/* 0xd68: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_TIB0, XT__23TIB, XT_CELL_2B, XT__21, XT_EXIT,
/* 0xd7a: XIO */ F_tokenDoList, XT_doLIT, XT_accept, XT__27EXPECT, XT__21, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT,
/* 0xd92: FILE */ F_tokenDoList, XT_doLIT, XT_PACE, XT_doLIT, XT_DROP, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT,
/* 0xda4: HAND */ F_tokenDoList, XT_doLIT, XT__2EOK, XT_doLIT, XT_EMIT, XT_doLIT, XT_kTAP, XT_XIO, XT_EXIT,
/* 0xdb6: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21,
/* 0xdbe: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT,
/* 0xdcc: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT,
/* 0xdd4: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLIT, 0x5e, XT_CHARS, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT,
/* 0xe04: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLIT, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT_CONSOLE, XT_quitError, XT_branch, XT_QUIT + 8, XT_EXIT,
/* 0xe24: quit1 */ F_tokenDoList, XT_doLIT, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT,
/* 0xe38: ' */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, XT__27 + 0xc, XT_EXIT, XT_THROW, XT_EXIT,
/* 0xe48: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT,
/* 0xe50: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT,
/* 0xe66: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT,
/* 0xe6e: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3E, XT__2C, XT_EXIT,
/* 0xe7a: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT,
/* 0xe84: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT,
/* 0xea0: $,n */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, XT__24_2Cn + 0x30, XT__3FUNIQUE, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT,
/* 0xedc: $COMPILE */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, XT__24COMPILE + 0x1e, XT_C_40, XT__3DIMED, XT_AND, XT__3Fbranch, XT__24COMPILE + 0x1a, XT_EXECUTE, XT_branch, XT__24COMPILE + 0x1c, XT__2C, XT_EXIT, XT__27NUMBER, XT__40EXECUTE, XT__3Fbranch, XT__24COMPILE + 0x2a, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT,
/* 0xf0a: OVERT */ F_tokenDoList, XT_LAST, XT__40, XT_CURRENT, XT__40, XT__21, XT_EXIT,
/* 0xf18: ; */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT,
/* 0xf24: ] */ F_tokenDoList, XT_doLIT, XT__24COMPILE, XT__27EVAL, XT__21, XT_EXIT,
/* 0xf30: : */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT,
/* 0xf3e: USER */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenUser, XT__2C, XT_EXIT,
/* 0xf4c: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLIT, 0, XT__2C, XT_EXIT,
/* 0xf5e: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT,
/* 0xf66: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT_0_3D, XT__3Fbranch, XT_vCREATE + 0x14, XT_CREATE, XT_branch, XT_vCREATE + 0x1a, XT_tokenVar, XT_create, XT__2C, XT_EXIT,
/* 0xf82: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLIT, 0, XT_v_2C, XT_EXIT,
/* 0xf8e: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT,
/* 0xf9e: _TYPE */ F_tokenDoList, XT__3ER, XT_branch, XT__5FTYPE + 0x16, XT_DUP, XT_C_40, XT__3ECHAR, XT_EMIT, XT_doLIT, 1, XT__2B, XT_next, XT__5FTYPE + 8, XT_DROP, XT_EXIT,
/* 0xfbc: dm+ */ F_tokenDoList, XT_OVER, XT_doLIT, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x22, XT_DUP, XT_C_40, XT_doLIT, 3, XT_U_2ER, XT_doLIT, 1, XT__2B, XT_next, XT_dm_2B + 0x12, XT_EXIT,
/* 0xfe4: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLIT, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLIT, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLIT, 2, XT_SPACES, XT__5FTYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT,
/* 0x1028: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2004, 0x733c, 0x70, XT_EXIT,
/* 0x1048: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT,
/* 0x105a: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT,
/* 0x1066: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT,
/* 0x1070: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT,
/* 0x108a: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT__3DBYTEMASK, XT_AND, XT__5FTYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT,
/* 0x10aa: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT,
/* 0x10cc: FORTH>NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_2DUP, XT_NAME_3E, XT_XOR, XT__3Fbranch, XT_FORTH_3ENAME + 0x28, XT_CELL_2D, XT_branch, XT_FORTH_3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT_FORTH_3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_doLIT, 0, XT_EXIT,
/* 0x110a: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLIT, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLIT, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT,
/* 0x1190: VER */ F_tokenNextVal, 0xa,
/* 0x1194: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_VER, XT__3C_23, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLIT, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_CR, XT_EXIT,
/* 0x11c8: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT,
/* 0x11d0: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT,
/* 0x11e0: 'BOOT */ F_tokenCreate, 0, XT_hi,
/* 0x11e6: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT,
/* 0x11fe: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT,
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x120a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x122a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x124a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x126a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x128a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x12aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x12ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x12ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x130a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x132a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x134a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x136a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x138a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x13aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x13ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x13ea: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x140a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x142a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x144a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x146a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x148a: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x14aa: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 0x14ca: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172,
/* 0x14ea: */ 0x6572, 0x5361, 0x7661, 0x65,
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x14f2 WARM */ XT_WARM, 0x1500, 0x5704, 0x5241, 0x4d,
/* 0x14fc COLD */ XT_COLD, 0x150a, 0x4304, 0x4c4f, 0x44,
/* 0x1506 'BOOT */ XT__27BOOT, 0x1514, 0x2705, 0x4f42, 0x544f,
/* 0x1510 EMPTY */ XT_EMPTY, 0x151e, 0x4505, 0x504d, 0x5954,
/* 0x151a hi */ XT_hi, 0x1526, 0x6842, 0x69,
/* 0x1522 version */ XT_version, 0x1532, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0x152e VER */ XT_VER, 0x153a, 0x5603, 0x5245,
/* 0x1536 SEE */ XT_SEE, 0x1542, 0x5303, 0x4545,
/* 0x153e FORTH>NAME */ XT_FORTH_3ENAME, 0x1552, 0x460a, 0x524f, 0x4854, 0x4e3e, 0x4d41, 0x45,
/* 0x154e WORDS */ XT_WORDS, 0x155c, 0x5705, 0x524f, 0x5344,
/* 0x1558 .ID */ XT__2EID, 0x1564, 0x2e03, 0x4449,
/* 0x1560 ?CSP */ XT__3FCSP, 0x156e, 0x3f04, 0x5343, 0x50,
/* 0x156a !CSP */ XT__21CSP, 0x1578, 0x2104, 0x5343, 0x50,
/* 0x1574 .FREE */ XT__2EFREE, 0x1582, 0x2e05, 0x5246, 0x4545,
/* 0x157e .BASE */ XT__2EBASE, 0x158c, 0x2e05, 0x4142, 0x4553,
/* 0x1588 .S */ XT__2ES, 0x1594, 0x2e02, 0x53,
/* 0x1590 DUMP */ XT_DUMP, 0x159e, 0x4404, 0x4d55, 0x50,
/* 0x159a dm+ */ XT_dm_2B, 0x15a6, 0x6403, 0x2b6d,
/* 0x15a2 _TYPE */ XT__5FTYPE, 0x15b0, 0x5f05, 0x5954, 0x4550,
/* 0x15ac CONSTANT */ XT_CONSTANT, 0x15be, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0x15ba VARIABLE */ XT_VARIABLE, 0x15cc, 0x5608, 0x5241, 0x4149, 0x4c42, 0x45,
/* 0x15c8 vCREATE */ XT_vCREATE, 0x15d8, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x15d4 CREATE */ XT_CREATE, 0x15e4, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x15e0 create */ XT_create, 0x15f0, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x15ec USER */ XT_USER, 0x15fa, 0x5504, 0x4553, 0x52,
/* 0x15f6 : */ XT__3A, 0x1600, 0x3a01,
/* 0x15fc ] */ XT__5D, 0x1606, 0x5d01,
/* 0x1602 ; */ XT__3B, 0x160c, 0x3bc1,
/* 0x1608 OVERT */ XT_OVERT, 0x1616, 0x4f05, 0x4556, 0x5452,
/* 0x1612 $COMPILE */ XT__24COMPILE, 0x1624, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x1620 $,n */ XT__24_2Cn, 0x162c, 0x2403, 0x6e2c,
/* 0x1628 ?UNIQUE */ XT__3FUNIQUE, 0x1638, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0x1634 $" */ XT__24_22, 0x1640, 0x2482, 0x22,
/* 0x163c RECURSE */ XT_RECURSE, 0x164c, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0x1648 [COMPILE] */ XT__5BCOMPILE_5D, 0x165a, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x1656 vALLOT */ XT_vALLOT, 0x1666, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0x1662 ALLOT */ XT_ALLOT, 0x1670, 0x4105, 0x4c4c, 0x544f,
/* 0x166c ' */ XT__27, 0x1676, 0x2701,
/* 0x1672 quit1 */ XT_quit1, 0x1680, 0x7105, 0x6975, 0x3174,
/* 0x167c QUIT */ XT_QUIT, 0x168a, 0x5104, 0x4955, 0x54,
/* 0x1686 quitError */ XT_quitError, 0x1698, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0x1694 que */ XT_que, 0x16a0, 0x7103, 0x6575,
/* 0x169c CONSOLE */ XT_CONSOLE, 0x16ac, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0x16a8 I/O */ XT_I_2FO, 0x16b4, 0x4903, 0x4f2f,
/* 0x16b0 HAND */ XT_HAND, 0x16be, 0x4804, 0x4e41, 0x44,
/* 0x16ba FILE */ XT_FILE, 0x16c8, 0x4604, 0x4c49, 0x45,
/* 0x16c4 XIO */ XT_XIO, 0x16d0, 0x5803, 0x4f49,
/* 0x16cc PRESET */ XT_PRESET, 0x16dc, 0x5006, 0x4552, 0x4553, 0x54,
/* 0x16d8 [ */ XT__5B, 0x16e2, 0x5b81,
/* 0x16de EVAL */ XT_EVAL, 0x16ec, 0x4504, 0x4156, 0x4c,
/* 0x16e8 ?STACK */ XT__3FSTACK, 0x16f8, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0x16f4 .OK */ XT__2EOK, 0x1700, 0x2e03, 0x4b4f,
/* 0x16fc $INTERPRET */ XT__24INTERPRET, 0x1710, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x170c ." */ XT__2E_22, 0x1718, 0x2e82, 0x22,
/* 0x1714 ABORT" */ XT_ABORT_22, 0x1724, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0x1720 $," */ XT__24_2C_22, 0x172c, 0x2403, 0x222c,
/* 0x1728 abort" */ XT_abort_22, 0x1738, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0x1734 ABORT */ XT_ABORT, 0x1742, 0x4105, 0x4f42, 0x5452,
/* 0x173e NULL$ */ XT_NULL_24, 0x174c, 0x4e05, 0x4c55, 0x244c,
/* 0x1748 THROW */ XT_THROW, 0x1756, 0x5405, 0x5248, 0x574f,
/* 0x1752 CATCH */ XT_CATCH, 0x1760, 0x4305, 0x5441, 0x4843,
/* 0x175c QUERY */ XT_QUERY, 0x176a, 0x5105, 0x4555, 0x5952,
/* 0x1766 EXPECT */ XT_EXPECT, 0x1776, 0x4506, 0x5058, 0x4345, 0x54,
/* 0x1772 accept */ XT_accept, 0x1782, 0x6106, 0x6363, 0x7065, 0x74,
/* 0x177e kTAP */ XT_kTAP, 0x178c, 0x6b04, 0x4154, 0x50,
/* 0x1788 TAP */ XT_TAP, 0x1794, 0x5403, 0x5041,
/* 0x1790 ^H */ XT__5EH, 0x179c, 0x5e02, 0x48,
/* 0x1798 NAME? */ XT_NAME_3F, 0x17a6, 0x4e05, 0x4d41, 0x3f45,
/* 0x17a2 FORTHfind */ XT_FORTHfind, 0x17b4, 0x4609, 0x524f, 0x4854, 0x6966, 0x646e,
/* 0x17b0 SAME? */ XT_SAME_3F, 0x17be, 0x5305, 0x4d41, 0x3f45,
/* 0x17ba NAME> */ XT_NAME_3E, 0x17c8, 0x4e05, 0x4d41, 0x3e45,
/* 0x17c4 WORD */ XT_WORD, 0x17d2, 0x5704, 0x524f, 0x44,
/* 0x17ce TOKEN */ XT_TOKEN, 0x17dc, 0x5405, 0x4b4f, 0x4e45,
/* 0x17d8 .( */ XT__2E_28, 0x17e4, 0x2e82, 0x28,
/* 0x17e0 CTRL */ XT_CTRL, 0x17ee, 0x4304, 0x5254, 0x4c,
/* 0x17ea CHAR */ XT_CHAR, 0x17f8, 0x4304, 0x4148, 0x52,
/* 0x17f4 PARSE */ XT_PARSE, 0x1802, 0x5005, 0x5241, 0x4553,
/* 0x17fe parse */ XT_parse, 0x180c, 0x7005, 0x7261, 0x6573,
/* 0x1808 ."| */ XT__2E_22_7C, 0x1814, 0x2e03, 0x7c22,
/* 0x1810 $"| */ XT__24_22_7C, 0x181c, 0x2403, 0x7c22,
/* 0x1818 do$ */ XT_do_24, 0x1824, 0x6403, 0x246f,
/* 0x1820 CR */ XT_CR, 0x182c, 0x4302, 0x52,
/* 0x1828 PACE */ XT_PACE, 0x1836, 0x5004, 0x4341, 0x45,
/* 0x1832 NUF? */ XT_NUF_3F, 0x1840, 0x4e04, 0x4655, 0x3f,
/* 0x183c KEY */ XT_KEY, 0x1848, 0x4b03, 0x5945,
/* 0x1844 ?KEY */ XT__3FKEY, 0x1852, 0x3f04, 0x454b, 0x59,
/* 0x184e NUMBER? */ XT_NUMBER_3F, 0x185e, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x185a DIGIT? */ XT_DIGIT_3F, 0x186a, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0x1866 ? */ XT__3F, 0x1870, 0x3f01,
/* 0x186c . */ XT__2E, 0x1876, 0x2e01,
/* 0x1872 U. */ XT_U_2E, 0x187e, 0x5502, 0x2e,
/* 0x187a U.R */ XT_U_2ER, 0x1886, 0x5503, 0x522e,
/* 0x1882 .R */ XT__2ER, 0x188e, 0x2e02, 0x52,
/* 0x188a DECIMAL */ XT_DECIMAL, 0x189a, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0x1896 HEX */ XT_HEX, 0x18a2, 0x4803, 0x5845,
/* 0x189e str */ XT_str, 0x18aa, 0x7303, 0x7274,
/* 0x18a6 .$ */ XT__2E_24, 0x18b2, 0x2e02, 0x24,
/* 0x18ae TYPE */ XT_TYPE, 0x18bc, 0x5404, 0x5059, 0x45,
/* 0x18b8 SPACES */ XT_SPACES, 0x18c8, 0x5306, 0x4150, 0x4543, 0x53,
/* 0x18c4 CHARS */ XT_CHARS, 0x18d2, 0x4305, 0x4148, 0x5352,
/* 0x18ce SPACE */ XT_SPACE, 0x18dc, 0x5305, 0x4150, 0x4543,
/* 0x18d8 EMIT */ XT_EMIT, 0x18e6, 0x4504, 0x494d, 0x54,
/* 0x18e2 #> */ XT__23_3E, 0x18ee, 0x2302, 0x3e,
/* 0x18ea SIGN */ XT_SIGN, 0x18f8, 0x5304, 0x4749, 0x4e,
/* 0x18f4 #S */ XT__23S, 0x1900, 0x2302, 0x53,
/* 0x18fc # */ XT__23, 0x1906, 0x2301,
/* 0x1902 HOLD */ XT_HOLD, 0x1910, 0x4804, 0x4c4f, 0x44,
/* 0x190c <# */ XT__3C_23, 0x1918, 0x3c02, 0x23,
/* 0x1914 EXTRACT */ XT_EXTRACT, 0x1924, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0x1920 DIGIT */ XT_DIGIT, 0x192e, 0x4405, 0x4749, 0x5449,
/* 0x192a PACK$ */ XT_PACK_24, 0x1938, 0x5005, 0x4341, 0x244b,
/* 0x1934 -TRAILING */ XT__2DTRAILING, 0x1946, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0x1942 FILL */ XT_FILL, 0x1950, 0x4604, 0x4c49, 0x4c,
/* 0x194c CMOVE */ XT_CMOVE, 0x195a, 0x4305, 0x4f4d, 0x4556,
/* 0x1956 COUNT */ XT_COUNT, 0x1964, 0x4305, 0x554f, 0x544e,
/* 0x1960 @EXECUTE */ XT__40EXECUTE, 0x1972, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0x196e TIB */ XT_TIB, 0x197a, 0x5403, 0x4249,
/* 0x1976 PAD */ XT_PAD, 0x1982, 0x5003, 0x4441,
/* 0x197e vCREATE */ XT_vCREATE, 0x198e, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0x198a vALIGN */ XT_vALIGN, 0x199a, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0x1996 v, */ XT_v_2C, 0x19a2, 0x7602, 0x2c,
/* 0x199e vHERE */ XT_vHERE, 0x19ac, 0x7605, 0x4548, 0x4552,
/* 0x19a8 2@ */ XT_2_40, 0x19b4, 0x3202, 0x40,
/* 0x19b0 2! */ XT_2_21, 0x19bc, 0x3202, 0x21,
/* 0x19b8 +! */ XT__2B_21, 0x19c4, 0x2b02, 0x21,
/* 0x19c0 PICK */ XT_PICK, 0x19ce, 0x5004, 0x4349, 0x4b,
/* 0x19ca DEPTH */ XT_DEPTH, 0x19d8, 0x4405, 0x5045, 0x4854,
/* 0x19d4 >CHAR */ XT__3ECHAR, 0x19e2, 0x3e05, 0x4843, 0x5241,
/* 0x19de CELLS */ XT_CELLS, 0x19ec, 0x4305, 0x4c45, 0x534c,
/* 0x19e8 CELL- */ XT_CELL_2D, 0x19f6, 0x4305, 0x4c45, 0x2d4c,
/* 0x19f2 * / */ XT__2A_2F, 0x19fe, 0x2a02, 0x2f,
/* 0x19fa * /MOD */ XT__2A_2FMOD, 0x1a08, 0x2a05, 0x4d2f, 0x444f,
/* 0x1a04 M* */ XT_M_2A, 0x1a10, 0x4d02, 0x2a,
/* 0x1a0c * */ XT__2A, 0x1a16, 0x2a01,
/* 0x1a12 UM* */ XT_UM_2A, 0x1a1e, 0x5503, 0x2a4d,
/* 0x1a1a / */ XT__2F, 0x1a24, 0x2f01,
/* 0x1a20 MOD */ XT_MOD, 0x1a2c, 0x4d03, 0x444f,
/* 0x1a28 /MOD */ XT__2FMOD, 0x1a36, 0x2f04, 0x4f4d, 0x44,
/* 0x1a32 M/MOD */ XT_M_2FMOD, 0x1a40, 0x4d05, 0x4d2f, 0x444f,
/* 0x1a3c UM/MOD */ XT_UM_2FMOD, 0x1a4c, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0x1a48 WITHIN */ XT_WITHIN, 0x1a58, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0x1a54 MIN */ XT_MIN, 0x1a60, 0x4d03, 0x4e49,
/* 0x1a5c MAX */ XT_MAX, 0x1a68, 0x4d03, 0x5841,
/* 0x1a64 < */ XT__3C, 0x1a6e, 0x3c01,
/* 0x1a6a U< */ XT_U_3C, 0x1a76, 0x5502, 0x3c,
/* 0x1a72 = */ XT__3D, 0x1a7c, 0x3d01,
/* 0x1a78 0= */ XT_0_3D, 0x1a84, 0x3002, 0x3d,
/* 0x1a80 ABS */ XT_ABS, 0x1a8c, 0x4103, 0x5342,
/* 0x1a88 - */ XT__2D, 0x1a92, 0x2d01,
/* 0x1a8e DNEGATE */ XT_DNEGATE, 0x1a9e, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0x1a9a NEGATE */ XT_NEGATE, 0x1aaa, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0x1aa6 INVERT */ XT_INVERT, 0x1ab6, 0x4906, 0x564e, 0x5245, 0x54,
/* 0x1ab2 D+ */ XT_D_2B, 0x1abe, 0x4402, 0x2b,
/* 0x1aba + */ XT__2B, 0x1ac4, 0x2b01,
/* 0x1ac0 2DUP */ XT_2DUP, 0x1ace, 0x3204, 0x5544, 0x50,
/* 0x1aca -ROT */ XT__2DROT, 0x1ad8, 0x2d04, 0x4f52, 0x54,
/* 0x1ad4 ROT */ XT_ROT, 0x1ae0, 0x5203, 0x544f,
/* 0x1adc ?DUP */ XT__3FDUP, 0x1aea, 0x3f04, 0x5544, 0x50,
/* 0x1ae6 WHILE */ XT_WHILE, 0x1af4, 0x5785, 0x4948, 0x454c,
/* 0x1af0 WHEN */ XT_WHEN, 0x1afe, 0x5784, 0x4548, 0x4e,
/* 0x1afa ELSE */ XT_ELSE, 0x1b08, 0x4584, 0x534c, 0x45,
/* 0x1b04 AFT */ XT_AFT, 0x1b10, 0x4183, 0x5446,
/* 0x1b0c THEN */ XT_THEN, 0x1b1a, 0x5484, 0x4548, 0x4e,
/* 0x1b16 REPEAT */ XT_REPEAT, 0x1b26, 0x5286, 0x5045, 0x4145, 0x54,
/* 0x1b22 AHEAD */ XT_AHEAD, 0x1b30, 0x4185, 0x4548, 0x4441,
/* 0x1b2c IF */ XT_IF, 0x1b38, 0x4982, 0x46,
/* 0x1b34 AGAIN */ XT_AGAIN, 0x1b42, 0x4185, 0x4147, 0x4e49,
/* 0x1b3e UNTIL */ XT_UNTIL, 0x1b4c, 0x5585, 0x544e, 0x4c49,
/* 0x1b48 NEXT */ XT_NEXT, 0x1b56, 0x4e84, 0x5845, 0x54,
/* 0x1b52 BEGIN */ XT_BEGIN, 0x1b60, 0x4285, 0x4745, 0x4e49,
/* 0x1b5c FOR */ XT_FOR, 0x1b68, 0x4683, 0x524f,
/* 0x1b64 >RESOLVE */ XT__3ERESOLVE, 0x1b76, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x1b72 >MARK */ XT__3EMARK, 0x1b80, 0x3e05, 0x414d, 0x4b52,
/* 0x1b7c <RESOLVE */ XT__3CRESOLVE, 0x1b8e, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0x1b8a <MARK */ XT__3CMARK, 0x1b98, 0x3c05, 0x414d, 0x4b52,
/* 0x1b94 CREATE */ XT_CREATE, 0x1ba4, 0x4306, 0x4552, 0x5441, 0x45,
/* 0x1ba0 create */ XT_create, 0x1bb0, 0x6306, 0x6572, 0x7461, 0x65,
/* 0x1bac LITERAL */ XT_LITERAL, 0x1bbc, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0x1bb8 COMPILE */ XT_COMPILE, 0x1bc8, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0x1bc4 [COMPILE] */ XT__5BCOMPILE_5D, 0x1bd6, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0x1bd2 , */ XT__2C, 0x1bdc, 0x2c01,
/* 0x1bd8 CELL+ */ XT_CELL_2B, 0x1be6, 0x4305, 0x4c45, 0x2b4c,
/* 0x1be2 HERE */ XT_HERE, 0x1bf0, 0x4804, 0x5245, 0x45,
/* 0x1bec NIP */ XT_NIP, 0x1bf8, 0x4e03, 0x5049,
/* 0x1bf4 \T */ XT__5CT, 0x1c00, 0x5c02, 0x54,
/* 0x1bfc \ */ XT__5C, 0x1c06, 0x5c81,
/* 0x1c02 ( */ XT__28, 0x1c0c, 0x2881,
/* 0x1c08 IMMEDIATE */ XT_IMMEDIATE, 0x1c1a, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0x1c16 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x1c2c, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0x1c28 setHeaderBits */ XT_setHeaderBits, 0x1c3e, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0x1c3a 2DROP */ XT_2DROP, 0x1c48, 0x3205, 0x5244, 0x504f,
/* 0x1c44 VP */ XT_VP, 0x1c50, 0x5602, 0x50,
/* 0x1c4c LAST */ XT_LAST, 0x1c5a, 0x4c04, 0x5341, 0x54,
/* 0x1c56 NP */ XT_NP, 0x1c62, 0x4e02, 0x50,
/* 0x1c5e CP */ XT_CP, 0x1c6a, 0x4302, 0x50,
/* 0x1c66 CURRENT */ XT_CURRENT, 0x1c76, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0x1c72 CONTEXT */ XT_CONTEXT, 0x1c82, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0x1c7e HANDLER */ XT_HANDLER, 0x1c8e, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0x1c8a HLD */ XT_HLD, 0x1c96, 0x4803, 0x444c,
/* 0x1c92 'NUMBER */ XT__27NUMBER, 0x1ca2, 0x2707, 0x554e, 0x424d, 0x5245,
/* 0x1c9e 'EVAL */ XT__27EVAL, 0x1cac, 0x2705, 0x5645, 0x4c41,
/* 0x1ca8 CSP */ XT_CSP, 0x1cb4, 0x4303, 0x5053,
/* 0x1cb0 #TIB */ XT__23TIB, 0x1cbe, 0x2304, 0x4954, 0x42,
/* 0x1cba >IN */ XT__3EIN, 0x1cc6, 0x3e03, 0x4e49,
/* 0x1cc2 SPAN */ XT_SPAN, 0x1cd0, 0x5304, 0x4150, 0x4e,
/* 0x1ccc temp */ XT_temp, 0x1cda, 0x7404, 0x6d65, 0x70,
/* 0x1cd6 BASE */ XT_BASE, 0x1ce4, 0x4204, 0x5341, 0x45,
/* 0x1ce0 'PROMPT */ XT__27PROMPT, 0x1cf0, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0x1cec 'ECHO */ XT__27ECHO, 0x1cfa, 0x2705, 0x4345, 0x4f48,
/* 0x1cf6 'TAP */ XT__27TAP, 0x1d04, 0x2704, 0x4154, 0x50,
/* 0x1d00 'EXPECT */ XT__27EXPECT, 0x1d10, 0x2707, 0x5845, 0x4550, 0x5443,
/* 0x1d0c 'EMIT */ XT__27EMIT, 0x1d1a, 0x2705, 0x4d45, 0x5449,
/* 0x1d16 '?KEY */ XT__27_3FKEY, 0x1d24, 0x2705, 0x4b3f, 0x5945,
/* 0x1d20 RP0 */ XT_RP0, 0x1d2c, 0x5203, 0x3050,
/* 0x1d28 SP0 */ XT_SP0, 0x1d34, 0x5303, 0x3050,
/* 0x1d30 TEST */ XT_TEST, 0x1d3e, 0x5404, 0x5345, 0x54,
/* 0x1d3a debugPrintTIB */ XT_debugPrintTIB, 0x1d50, 0x640d, 0x6265, 0x6775, 0x7250, 0x6e69, 0x5474, 0x4249,
/* 0x1d4c Fbreak */ XT_Fbreak, 0x1d5c, 0x4606, 0x7262, 0x6165, 0x6b,
/* 0x1d58 testing3 */ XT_testing3, 0x1d6a, 0x7408, 0x7365, 0x6974, 0x676e, 0x33,
/* 0x1d66 debugNA */ XT_debugNA, 0x1d76, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0x1d72 ' */ XT__27, 0x1d7c, 0x2701,
/* 0x1d78 ; */ XT__3B, 0x1d82, 0x3b81,
/* 0x1d7e : */ XT__3A, 0x1d88, 0x3a01,
/* 0x1d84 ] */ XT__5D, 0x1d8e, 0x5d01,
/* 0x1d8a [ */ XT__5B, 0x1d94, 0x5b81,
/* 0x1d90 $INTERPRET */ XT__24INTERPRET, 0x1da4, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0x1da0 $COMPILE */ XT__24COMPILE, 0x1db2, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0x1dae NUMBER? */ XT_NUMBER_3F, 0x1dbe, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0x1dba TOKEN */ XT_TOKEN, 0x1dc8, 0x5405, 0x4b4f, 0x4e45,
/* 0x1dc4 PARSE */ XT_PARSE, 0x1dd2, 0x5005, 0x5241, 0x4553,
/* 0x1dce userAreaSave */ XT_userAreaSave, 0x1de4, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0x1de0 userAreaInit */ XT_userAreaInit, 0x1df6, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0x1df2 UM+ */ XT_UM_2B, 0x1dfe, 0x5503, 0x2b4d,
/* 0x1dfa XOR */ XT_XOR, 0x1e06, 0x5803, 0x524f,
/* 0x1e02 OR */ XT_OR, 0x1e0e, 0x4f02, 0x52,
/* 0x1e0a AND */ XT_AND, 0x1e16, 0x4103, 0x444e,
/* 0x1e12 0< */ XT_0_3C, 0x1e1e, 0x3002, 0x3c,
/* 0x1e1a OVER */ XT_OVER, 0x1e28, 0x4f04, 0x4556, 0x52,
/* 0x1e24 SWAP */ XT_SWAP, 0x1e32, 0x5304, 0x4157, 0x50,
/* 0x1e2e DUP */ XT_DUP, 0x1e3a, 0x4403, 0x5055,
/* 0x1e36 DROP */ XT_DROP, 0x1e44, 0x4404, 0x4f52, 0x50,
/* 0x1e40 SP! */ XT_SP_21, 0x1e4c, 0x5303, 0x2150,
/* 0x1e48 SP@ */ XT_SP_40, 0x1e54, 0x5303, 0x4050,
/* 0x1e50 >R */ XT__3ER, 0x1e5c, 0x3e02, 0x52,
/* 0x1e58 R@ */ XT_R_40, 0x1e64, 0x5202, 0x40,
/* 0x1e60 R> */ XT_R_3E, 0x1e6c, 0x5202, 0x3e,
/* 0x1e68 RP! */ XT_RP_21, 0x1e74, 0x5203, 0x2150,
/* 0x1e70 RP@ */ XT_RP_40, 0x1e7c, 0x5203, 0x4050,
/* 0x1e78 C! */ XT_C_21, 0x1e84, 0x4302, 0x21,
/* 0x1e80 C@ */ XT_C_40, 0x1e8c, 0x4302, 0x40,
/* 0x1e88 @ */ XT__40, 0x1e92, 0x4001,
/* 0x1e8e ! */ XT__21, 0x1e98, 0x2101,
/* 0x1e94 branch */ XT_branch, 0x1ea4, 0x6206, 0x6172, 0x636e, 0x68,
/* 0x1ea0 ?branch */ XT__3Fbranch, 0x1eb0, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0x1eac next */ XT_next, 0x1eba, 0x6e04, 0x7865, 0x74,
/* 0x1eb6 DOES> */ XT_DOES_3E, 0x1ec4, 0x4405, 0x454f, 0x3e53,
/* 0x1ec0 doLIT */ XT_doLIT, 0x1ece, 0x6405, 0x4c6f, 0x5449,
/* 0x1eca !IO */ XT__21IO, 0x1ed6, 0x2103, 0x4f49,
/* 0x1ed2 TX! */ XT_TX_21, 0x1ede, 0x5403, 0x2158,
/* 0x1eda ?RX */ XT__3FRX, 0x1ee6, 0x3f03, 0x5852,
/* 0x1ee2 EXECUTE */ XT_EXECUTE, 0x1ef2, 0x4507, 0x4558, 0x5543, 0x4554,
/* 0x1eee EXIT */ XT_EXIT, 0x1efc, 0x4504, 0x4958, 0x54,
/* 0x1ef8 BYE */ XT_BYE, 0x1f04, 0x4203, 0x4559,
/* 0x1f00 MS */ XT_MS, 0x1f0c, 0x4d02, 0x53,
/* 0x1f08 >NAME */ XT__3ENAME, 0x1f16, 0x3e05, 0x414e, 0x454d,
/* 0x1f12 $,n */ XT__24_2Cn, 0x1f1e, 0x2403, 0x6e2c,
/* 0x1f1a OVERT */ XT_OVERT, 0x1f28, 0x4f05, 0x4556, 0x5452,
/* 0x1f24 find */ XT_find, 0x1f32, 0x6604, 0x6e69, 0x64,
/* 0x1f2e ALIGNED */ XT_ALIGNED, 0x1f3e, 0x4107, 0x494c, 0x4e47, 0x4445,
/* 0x1f3a tokenCreate */ XT_tokenCreate, 0x1f4e, 0x740b, 0x6b6f, 0x6e65, 0x7243, 0x6165, 0x6574,
/* 0x1f4a tokenVar */ XT_tokenVar, 0x1f5c, 0x7408, 0x6b6f, 0x6e65, 0x6156, 0x72,
/* 0x1f58 tokenUser */ XT_tokenUser, 0x1f6a, 0x7409, 0x6b6f, 0x6e65, 0x7355, 0x7265,
/* 0x1f66 tokenDoList */ XT_tokenDoList, 0x1f7a, 0x740b, 0x6b6f, 0x6e65, 0x6f44, 0x694c, 0x7473,
/* 0x1f76 tokenNextVal */ XT_tokenNextVal, 0x1f8c, 0x740c, 0x6b6f, 0x6e65, 0x654e, 0x7478, 0x6156, 0x6c,
/* 0x1f88 tokenVocabulary */ XT_tokenVocabulary, 0x1fa0, 0x740f, 0x6b6f, 0x6e65, 0x6f56, 0x6163, 0x7562, 0x616c, 0x7972,
/* 0x1f9c BL */ XT_BL, 0x1fa8, 0x4202, 0x4c,
/* 0x1fa4 =BYTEMASK */ XT__3DBYTEMASK, 0x1fb6, 0x3d09, 0x5942, 0x4554, 0x414d, 0x4b53,
/* 0x1fb2 =IMED */ XT__3DIMED, 0x1fc0, 0x3d05, 0x4d49, 0x4445,
/* 0x1fbc =COMP */ XT__3DCOMP, 0x1fca, 0x3d05, 0x4f43, 0x504d,
/* 0x1fc6 TIB0 */ XT_TIB0, 0x1fd4, 0x5404, 0x4249, 0x30,
/* 0x1fd0 CELLMASK */ XT_CELLMASK, 0x1fe2, 0x4308, 0x4c45, 0x4d4c, 0x5341, 0x4b,
/* 0x1fde CELLbits */ XT_CELLbits, 0x1ff0, 0x4308, 0x4c45, 0x624c, 0x7469, 0x73,
/* 0x1fec CELLL */ XT_CELLL, 0x1ffa, 0x4305, 0x4c45, 0x4c4c,
/* 0x1ff6 FORTH */ XT_FORTH, 0, 0x4605, 0x524f, 0x4854,
};
// === End of Arduino source from dictionary ===

//TODO-ARDUINO OPTIMIZATION - check for constant parameters to functions nad mark constant in definition


//L.1777
#if CELLL == 2
#define CELLTYPE unsigned
#define CELLSHIFT 1
#endif
#if CELLL == 4
#define CELLTYPE long
#define CELLSHIFT 2
#endif
//#define WRITEROM 1 // Define if want to write to "rom" area

//L.1794

#define LITTLEENDIAN true // Arduino is little endian


// ==== In order, there is a gap (mLissing code) before each Line marker ====
//L.113-
#define COMP 0x40 // bit in first char of name field to indicate 'compile-only'  ERRATA Zen uses this but its not defined
#define IMED 0x80 // bit in first char of name field to indicate 'immediate' ERRATA Zen uses this but its not defined
#define bitsSPARE 0x20 // Unused spare bit in names
#define BYTEMASK 0xFF - COMP - IMED - bitsSPARE // bits to mask out of a call with count and first char. ERRATA Zen uses this but its not defined
// Using const for forthtrue as we care about its size
const CELLTYPE forthTrue = -1; // Not quite correct, should be masked BUT when pushed that it is done underneath
#define nameMaxLength 31
#define BL 32

// User offsets - TODO should be defined by dictionary creation - note these are in CELLS not in Bytes as in webForth
#define SP0offset 4
#define RP0offset 5
#define PROMPToffset 11
#define BASEoffset 12
#define INoffset 15
#define nTIBoffset 16
#define TIBoffset 17
#define EVALoffset 19
#define NUMBERoffset 20
#define CONTEXToffset 23
#define CURRENToffset 32
#define CPoffset 34
#define NPoffset 35
#define LASToffset 36
#define VPoffset 37
#define _USER 38

//L.1823
#define CELLbits CELLL * 8 // Number of bits in a cell - used for loops and shifts
// mask used when masking cells in fast search for name ERRATA Zen uses this but its not defined e.g. 0x1FFFFF if CELLL = 3
const CELLTYPE CELLMASK = forthTrue ^ ((0xFF ^ BYTEMASK) << (CELLbits - 8)); // TODO-15-EPROM will be endian dependent could #def ENDIAN and provide alternatives

//L.1831
static byte testing = 0;

//L.1840
// === Memory layout
// Memory may be aligned to a boundary depending on underlying mem store (which may or may not match CELLL), this assumption should be confined to ALIGNED
// Now the memory map itself, starting at the top of memory.



#define RAMADDR(x) ((x ^ RAM0) >> CELLSHIFT)
#define ROMADDR(x) (x >> CELLSHIFT)
#define FROMRAMADDR(x) (unsigned(x << CELLSHIFT) | RAM0)
#define FROMROMADDR(x) unsigned(x << CELLSHIFT)

// Now some cell based pointers into RAM
#define ramSPP RAMADDR(SPP) // start of data stack - grows down, points at top of stack - 8 word buffer for safety
#define ramRP0 RAMADDR(RP0)
#define ramUP0 RAMADDR(UPP)

//L.1852
static CELLTYPE ram[RAMCELLS]; // Equivalent of Mem16_16 in webForth
//L.1853 - jsFunctions[] is now fp[] and has to be after definition of functions in it.

// Key pointers used - would ideally be registers in a register based system
static CELLTYPE IP = 0;    // Interpreter Pointer (this is a byte pointer - cannot use CellPointer as could be into Rom or Ram)
static CELLTYPE PAYLOAD = 0;    // XT pointer - its either put this here OR make every function take a XT parameter - unlike JS C wont allow un-passed parameters
static CELLTYPE ramSP = ramSPP;  // Data Stack Pointer (cant call SP as that is reserved) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramRP = ramRP0;  // Return Stack Pointer (aka BP in 8086) (this is a cell pointer into ram i.e. (SP-RAM0)>>CELLSHIFT
static CELLTYPE ramUP = ramUP0;  // User Area Pointer // TODO-28-MULTI will move this around

//L.2023
void debugNA() { Serial.print(F("NAME=")); printCounted(SPfetch()); } // Print the NA on console
// Put testing3 in a definition to start outputing stack trace on console.
void testing3() { testing |= 3; };

// Put break in a definition.
void Fbreak() {
  Serial.println(F("\nbreak in a FORTH word")); 
} // Put a breakpoint in your IDE at this line

// debugPrintTIB will print the current TIB.
void debugPrintTIB() {
  Serial.print(F("TIB: ")); TXbangS(Ufetch(TIBoffset) + Ufetch(INoffset), Ufetch(nTIBoffset) - Ufetch(INoffset));
}

// TEST will (destructively) check the stack matches expected result, used for testing the compiler.
// e.g. this.interpret(`10 DUP 10 10 2 TEST`); // Confirm stack finishes with 2 items (10 10)
void TEST() { //  a1 a2 a3 b1 b2 b3 n -- ; Check n parameters on stack
  const byte stackDepth = SPpop();
  if ((ramSPP - ramSP) != (stackDepth << 1)) {
    Serial.println(F("Stack depth wrong"));
  } else {
    for (byte i = 0; i < stackDepth; i++) {
      const CELLTYPE onStack = cellRamFetch(ramSP + i);
      const CELLTYPE expected = SPpop(); // What we expect to see
      if (onStack != expected) {
        Serial.print(F("Expected")); 
        Serial.print(expected); 
        Serial.print(F("got")); 
        Serial.println(onStack); 
      }
    }
    ramSP = ramSPP; // Clear stack
  }
  //this.debugClear(); // Reset Debug Stack as can be mucked up by THROW and CATCH
}

// TODO if only used here then might merge into Mfetch and Mstore
#ifdef WRITEROM
#define ROM(cellAddr) rom[cellAddr]
#else
#define ROM(cellAddr) pgm_read_word_near(rom + cellAddr)
#endif
CELLTYPE cellRomFetch(CELLTYPE cellAddr) { 
  if (cellAddr >= ROMCELLS) { Serial.print("Attempt to read above top of Rom at "); Serial.println(cellAddr); delay(10000); } // TODO-OPTIMIZE comment out
  return ROM(cellAddr); };
CELLTYPE cellRamFetch(CELLTYPE cellAddr) {
  if (cellAddr >= RAMCELLS) { Serial.print("Attempt to read above top of Ram at "); Serial.println(cellAddr); delay(10000); } // TODO-OPTIMIZE comment out
  return ram[cellAddr]; };
void cellRamStore(CELLTYPE cellAddr, CELLTYPE v) { 
  if (cellAddr >= RAMCELLS) { Serial.print("Attempt to write above top of Ram at "); Serial.println(cellAddr); delay(10000); } // TODO-OPTIMIZE comment out
  ram[cellAddr] = v; };
#ifdef WRITEROM
void cellRomStore(CELLTYPE cellAddr, CELLTYPE v) { rom[cellAddr] = v; };
#endif
CELLTYPE Mfetch(CELLTYPE byteAddr) { return (byteAddr >= RAM0) ? cellRamFetch(RAMADDR(byteAddr)) : cellRomFetch(ROMADDR(byteAddr)) ; }
#ifdef WRITEROM
void Mstore(CELLTYPE byteAddr, CELLTYPE v) {  if (byteAddr >= RAM0) { cellRamStore(RAMADDR(byteAddr), v) } else { cellRomStore(ROMADDR(byteAddr), v) } }
#else
void Mstore(CELLTYPE byteAddr, CELLTYPE v) { 
  if (byteAddr < RAM0) { Serial.print("Attempt to write to Rom at "); Serial.print(byteAddr); Serial.print(" v="); Serial.println(v); delay(10000); } // TODO-OPTIMIZE comment out
  cellRamStore(RAMADDR(byteAddr), v); }
#endif
// 8 bit equivalents
byte Mfetch8(CELLTYPE byteAddr) {
  const bool offset = byteAddr & 0x01;
  const CELLTYPE cell = Mfetch(byteAddr); // Does not have to be aligned
#ifdef LITTLEENDIAN
  return offset ? (cell >> 8) : (cell & 0xFF) ;
#else
  return offset ? (cell & 0xFF) : (cell >> 8);
#endif
}; // Returns byte at a

void Mstore8(CELLTYPE byteAddr, byte v) {
  const bool offset = byteAddr & 0x01;
  const CELLTYPE cell = Mfetch(byteAddr);
#ifdef LITTLEENDIAN
    if (offset) {
      Mstore(byteAddr, (cell & 0x00FF) | (v << 8));
    } else {
      Mstore(byteAddr, (cell & 0xFF00) | v);
    }
#else
    if (offset) {
      Mstore(cellAddr, (cell & 0xFF00) | v);
    } else {
      Mstore(cellAddr, (cell & 0x00FF) | (v << 8));
    }
#endif
}

// TODO-MEM this is really dependent on MEM not CELLL
CELLTYPE align(CELLTYPE byteAddr) { return (((byteAddr - 1) >> CELLSHIFT) + 1) << CELLSHIFT; }
// Only used in token - which is bytes and never aligned
void copyWithin(CELLTYPE byteDestn, CELLTYPE byteSource, CELLTYPE byteEnd) {
  while(byteSource < byteEnd) {
    Mstore8(byteDestn++, Mfetch8(byteSource++));
  }
}

void ALIGNED() { SPpush(align(SPpop())); }
CELLTYPE SPfetch() { return ram[ramSP]; }
CELLTYPE SPpop() { return ram[ramSP++]; }
void SPpush(CELLTYPE v) { ram[--ramSP] = v; }
CELLTYPE RPfetch() { return ram[ramRP]; }
CELLTYPE RPpop() { return ram[ramRP++]; }
void RPpush(CELLTYPE v) { ram[--ramRP] = v; }
CELLTYPE IPnext() {
  const CELLTYPE v = Mfetch(IP);
  IP += CELLL;
  return v; }
CELLTYPE Ufetch(byte userindex) { return ram[ramUP + userindex]; } // userindex is a cell index, not a byte index
void Ustore(byte userindex, CELLTYPE w) { ram[ramUP + userindex] = w; } // userindex is a cell index not a byte index
// === Access to the USER variables before they are defined
CELLTYPE currentFetch() { return Ufetch(CURRENToffset); }
CELLTYPE cpFetch() { return Ufetch(CPoffset); }
CELLTYPE vpFetch() { return Ufetch(VPoffset) || Ufetch(CPoffset); }
CELLTYPE cpAlign() { Ustore(CPoffset, align(cpFetch())); }
CELLTYPE vpAlign() { Ustore(VPoffset, align(vpFetch())); }
CELLTYPE npFetch() { return Ufetch(NPoffset); }
CELLTYPE lastFetch() { return Ufetch(LASToffset); }
CELLTYPE padPtr() { return vpFetch() + 80; } // Sometimes JS needs the pad pointer

// === Functions related to building 'find'  and its wrappers ====

// Convert a string made up of a count and that many bytes to a Javascript string.
// it assumes a maximum of nameMaxLength (31) characters.
// Mostly used for debugging but also in number conversion.
void printCounted(CELLTYPE a) { const byte c = Mfetch8(a++); TXbangS(a, c); }  // TODO-backport maybe use this in TYPE
//countedToJS(a) {
//  return this.m.decodeString(a + 1, a + (this.Mfetch8(a) & l['=BYTEMASK']) + 1);
//}

//L.2096-
// Convert a name address to the code dictionary definition.
CELLTYPE na2xt(CELLTYPE na) {
    return Mfetch(na - (2 << CELLSHIFT));
}

// Inner function of find, traverses a linked list Name dictionary.
// name   javascript string looking for
// va     pointer holding address of first element in the list.
// cell1  if present, gives it a quick first-cell test to apply.
// xt     if present we are looking for name pointing at this executable (for decompiler)
// returns 0 or na
bool _sameq(CELLTYPE na1, CELLTYPE na2, byte cells) {
  // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
  // Note this is similar to SAME? but takes a count (not count of cells, and returns boolean
  for (byte i = 0; i < cells; i++) {
      if ( Mfetch(na1 + (i<<CELLSHIFT)) != Mfetch(na2 + (i<<CELLSHIFT))) {
        return false;
      }
    }
    return true;
}
CELLTYPE _find(CELLTYPE va, CELLTYPE na) { // return na that matches or 0
  const byte cellCount = (Mfetch8(na) & BYTEMASK)  >> CELLSHIFT; // Count of cells after first one (formula is not as obvious as you think)
  const CELLTYPE cell1 = Mfetch(na);  // Could be little or big-endian
  CELLTYPE p = va;
  while (p = Mfetch(p)) {
    const CELLTYPE c1 = Mfetch(p) & CELLMASK; // count
    if (cell1 == c1) { // first cell matches (if cell1 not passed then does slow compare
      if (_sameq(p + CELLL, na + CELLL, cellCount)) {
        return p;
      }
    }
    p -= CELLL; // point at link address and loop for next word
  }
  // Drop through not found
  return 0;
}

// Search a single vocabulary for a string
// This has same footprint as eForth's 'find' but we do not replace it since this is approx 8x faster
void jsFind() { // a va -- ca na | a 0
  const CELLTYPE va = SPpop();
  const CELLTYPE a = SPpop();
  const CELLTYPE na = _find(va, a);  // return matching na or 0
  if (na) {
    SPpush(na2xt(na));
    SPpush(na);
  } else {
    SPpush(a);
    SPpush(0);
  }
}
// Traverse dictionary to convert xt back to a na (for decompiler or debugging)
CELLTYPE xt2na(CELLTYPE xt) {
  CELLTYPE p = currentFetch(); // vocabulary
  if (!Mfetch(p)) { p = lastFetch() - CELLL; } // Note this is not quite correct, it will miss the first definition (WARM)
  //Serial.print("xt2na: p="); Serial.println(p);
  while (p = Mfetch(p)) {
    //Serial.print("xt2na comparing"); Serial.print(na2xt(p)),Serial.print(" "); Serial.println(xt);
    if (na2xt(p) == xt) {
      //Serial.println("xt2na: Got it");
      return p;
    }
    p -= CELLL; // point at link address and loop for next word
  }
  //Serial.println("xt2na: Drop through");
  // Drop through not found
  return 0;
}

//L.2180-
void ToNAME() { SPpush(xt2na(SPpop())); }  // Fast version of >NAME see Forth definition below

// TODO-29-VOCABULARY This just looks up a in the Context vocabulary, it makes no attempt to use multiple vocabularies
// If required then fixing this to iterate over the context array should not break anything (this is what NAME? does)
void findName() { // a -- xt na | a F
  SPpush(Ufetch(CONTEXToffset));  // a va
  jsFind();                           // xt na | a F
}

//L.2214-
// === JS Functions to be able to define words ==== in Zen pg30 these are Macros.

// Compile one or more words into the next consecutive code cells.
void DW(CELLTYPE word) {
  CELLTYPE cp = cpFetch();
  Mstore(cp, word);
  cp += CELLL;
  Ustore(CPoffset, cp);
}

/* REPLACED BY FORTH DEFINITION
// a -- a; Check if a definition of the word at 'a' would be unique and display warning (but continue) if it would not be.
// Same profile as ?UNIQUE but not turned into a code word as not used prior to
void qUnique() {
  SPpush(SPfetch());      // DUP
  SPpush(currentFetch()); // a a va; dictionary to search
  jsFind();                 // a xt na | a a F
  if (SPpop()) {
    const CELLTYPE xt = SPpop();              // Discard xt
    Serial.println(F("Duplicate definition of")); // Catch duplicates - report, but allow
    //TODO-ARDUINO
    //  const char* name = countedToJS(SPfetch());
    //  if (!['foo', 'bar'].includes(name)) {
    //    Serial.println(F("Duplicate definition of"), name); // Catch duplicates - report, but allow
    //    //Serial.println(jsFunctionAttributes[Mfetch(xt)].replaced ? 'Expected' : '', 'Duplicate definition of', countedToJS(SPfetch())); // Catch duplicates - report, but allow
    //  }
    //
  } else {
    SPpop(); // DROP a
  }
}

// na -- ; Builds bytes around a newly entered name. Same function as $,n on Zen pg94 used by all defining words (CODE ':')
// expects in Name dictionary: <count><string><opt padding>
// prepends:   <aligned address of next cell of code><address of na of last definition in vocabulary>...
// Side effects are important: specifically.
// LAST <= na
void dollarCommaN() {
  if (Mfetch8(SPfetch())) {         // DUP C@ IF  ; test for no word
    qUnique();
    CELLTYPE a = SPpop();
    Ustore(LASToffset, a);    // DUP LAST ! ; a=na  ; LAST=na
    // Link address points to previous NA (prev value of LAST)
    // Note that first time this is run, it gets a 0 (CURRENT is 0, @0 is 0) if that changes will need to test Current here.
    a -= CELLL; // CURRENT @ @ OVER ! ; a = la = top of current dic
    Mstore(a, Mfetch(currentFetch())); // CURRENT @ @ OVER ! ; a = la = top of current dic
    // Push CP (code field to where will build in dictionary) into ca, below a and store that ca into NP
    a -= CELLL;
    Mstore(a, cpFetch()); // ca=CP ;
    Ustore(NPoffset, a); // ca=CP ;
  } else {                    // THEN $" name" THROW ;
    Serial.println(F("name error")); // This is an error - in FORTH equivalent its a THROW
  }
}
*/

/* REPLACED BY FORTH DEFINITION
// Make the most recent definition available in the directory. This is part of closing every 'defining word'
// See also forth version
void OVERT() {
  Mstore(currentFetch(), lastFetch()); // LAST @ CURRENT @ !
}
*/

//L.2278-
void tokenVocabulary() {
  Ustore(CONTEXToffset, PAYLOAD);
};
// Put the contents of the payload (1 word) onto Stack, used for CONSTANT
void tokenNextVal() {
  SPpush(Mfetch(PAYLOAD));

};

// This is the most important token function - used for a Colon word to iterate over the list.
void tokenDoList() {
  if (testing) {
      Serial.println(":");
  }
  RPpush(IP);
  IP = PAYLOAD; // Point at first word in the definition
}
// Leaves an address in the user area, note it doesnt compile the actual address since UP will change when multi-tasking
void tokenUser() {
  //Serial.print("tokenUser payload="); Serial.print(PAYLOAD); Serial.print(" @payload="); Serial.print(Mfetch(PAYLOAD));
  SPpush(FROMRAMADDR((Mfetch(PAYLOAD) + ramUP)));
  //Serial.print(" result="); Serial.print(SPfetch()); Serial.print(" @="); Serial.println(Mfetch(SPfetch()));
}
// Put the address of the payload onto Stack - used for CREATE which is used by VARIABLE
void _tokenDoes() {
  const CELLTYPE does = Mfetch(PAYLOAD);
  if (does) {
    //debugPush();
    RPpush(IP);
    IP = does;
  }
}

// Put next address on the stack  -- byteAddr
void tokenCreate() {
  SPpush(PAYLOAD+CELLL);
  _tokenDoes();
}

void tokenVar() {
  SPpush(Mfetch(PAYLOAD+CELLL));
  _tokenDoes();
}

// === INNER INTERPRETER YES THIS IS IT ! ==================== eForthAndZen#36
// This is quite different from eForth as its token-threaded rather than direct threaded

void threadtoken(CELLTYPE xt) {
  // console.assert(xt >= CODEE && xt < NAMEE); // Uncomment to catch bizarre xt values earlier
  // This next section is only done while testing, and outputs a trace, so set it on (with testing3) immediately before a likely error.
  //debugThread(xt);
  const CELLTYPE tok = Mfetch(xt);
  PAYLOAD = xt + CELLL;
  // console.assert(tok < jsFunctions.length); // commented out for efficiency, a fail will just break in the next line anyway.
  if ((tok < 61) && f[tok]) {
    if (testing) {
        Serial.print(IP-CELLL); Serial.print(":");
        if (CELLTYPE p = xt2na(xt)) { byte count = Mfetch8(p++) & 0x1F; while (count--) { Serial.write(Mfetch8(p++)); } } else { Serial.print(xt); }
        //Serial.print(xt);
        Serial.print(":"); Serial.print(tok); Serial.print("  ");
    }
    f[tok](); // Run the token function - like tokenDoList or tokenVar - doesnt return - (JS returns null or a Promise)
  } else {
    Serial.print("XXX bad tok =");
    Serial.print(IP-CELLL); Serial.print(":"); Serial.print(xt); Serial.print(":"); Serial.print(tok); Serial.println("  "); delay(10000);
  }
}

// This is not re-entrant, normally its threadtoken you want ....
// In particular you cannot use this to nest forth in code in forth
// If that becomes necessary, it MIGHT work to save IP (where?) and restore after while loop
// Cant use R or S for it as words use that across calls to the 'EVAL
/* ARDUINO REPLACED BY LOOP
void runXT(CELLTYPE xt) {
  //let waitFrequency = 0;
  //console.assert(this.IP === 0); // Cant nest run()
  threadtoken(xt);
  // If this returns without changing program Counter, it will exit
  while (IP) {
    // console.assert(this.IP >= CODEE && this.IP <= NAMEE); // uncomment if tracking down jumping into odd places
    xt = IPnext();
    // Comment this out except when needed for debugging, they are slow
    // debugTIB =  this.m.decodeString(this.Ufetch(TIBoffset) + this.Ufetch(INoffset), this.Ufetch(TIBoffset) + this.Ufetch(nTIBoffset));
    // 'await this.threadtoken(xt)' would be legit, but creates a stack frame in critical inner loop, when usually not reqd.
    threadtoken(xt);
  }
}
*/

void MS() { delay(SPpop()); } // ms --; delay for a period of time.
void BYE() {  IP = 0; } // Should exit all the way out

// Unwind the effect of tokenDoList restoring IP to the next definition out.
void EXIT() {
  if (testing) Serial.println(";");
  IP = RPpop(); }

// EXECUTE runs the word on the stack,
// and because there is nothing after the return from threadtoken which would get executed out of order
// Note that it has a return which could be a promise, which the 'run' will await on.
// This pattern may or may not work in other situations.
//TODO ARDUINO try and figure out how to do this in the loop() then move threadtoken into the loop
void EXECUTE() { threadtoken(SPpop()); }

// === Basic low level key I/O and links to OS - Zen pg 35
// This section will need editing for other systems.
/*
 * Input call chain is
 * ?RX  read one char if present
 * ?KEY via '?KEY to ?RX
 * KEY loop till ?KEY
 * accept read a line via KEY, processing control chars via 'TAP  to kTAP
 * QUERY read a line via 'EXPECT to accept into TIB and reset >IN
 * que read an evaluate a line
 * QUIT loop over que, handling errors
 *
 * See https://github.com/mitra42/webForth/issues/17 for strategy for async version
 */

// Call chain is ?RX < '?KEY  < ?KEY < KEY < accept < 'EXPECT < QUERY < que < QUIT
// -- char T | F
static byte watched[10];
void watch(byte n) {
  if (!watched[n]) {
    //Serial.println('watched',n);
    watched[n] = 1;
  }
}
void QRX() { // ?RX
   if (Serial.available() > 0) {
    SPpush(Serial.read());
    SPpush(forthTrue);
  } else {
    SPpush(0);
  }
}
// Low level TX!, output one character to stdout, inefficient, but not likely to be bottleneck.

void TXbang() { //watch(3); return;
  Serial.write(SPpop());
} // TX!
void bangIO() { //watch(2); return;
//Serial.begin(57600); // DONE IN SETUP
} // !IO: Initialize IO port
void TXbangS(CELLTYPE byteaddr, byte len) {
  //watch(1); return;
  for (byte i=len; i > 0; i--) {
  Serial.write(Mfetch8(byteaddr++));
  }
 }

// === Literals and Branches - using next value in dictionary === eForthAndZen#37

// push the value in the next code word
// The XT of this is stored in doLIT
void doLIT() { SPpush(IPnext()); }

// See DOES> and CREATE, this patches the field after the token compiled by the create to point to the code following the DOES>
// : DOES> R> LAST @ 2 CELLS - @ CELLL + ! ; // Untested Forth version, note side effect of the R> of doing an exit.
void DOES() {
  Mstore(
    Mfetch(Ufetch(LASToffset) - (2 << CELLSHIFT) ) + CELLL, // field after tokenVar compile by CREATE
    IP // The address after the doDOES
  );
  EXIT(); // Exit the CREATE part
}

// Address Literals (aka branches and jumps) eForthAndZen#38

// decrement count on Return stack, and branch if not decremented past zero (FOR..NEXT)
// noinspection JSUnusedGlobalSymbols
void next() {
  CELLTYPE x = RPpop();
  const CELLTYPE destn = IPnext(); // Increments over it
  if (--x >= 0) {
    RPpush(x);
    IP = destn; // Jump back
  }
}

// Jump if flag on stack is zero to destn in dictionary
void qBranch() {
  const CELLTYPE destn = IPnext();
  if (!SPpop()) {
    IP = destn;
  }
}

// Unconditional jump to destn in dictionary
void branch() { IP = IPnext(); }

// Memory access eForthAndZen#39
void store() { 
  CELLTYPE a = SPpop();
  CELLTYPE v = SPpop();
  Mstore(a, v); } //!  w a -- , Store
void fetch() { SPpush(Mfetch(SPpop())); } //@ a -- w, fetch
void cStore() { Mstore8(SPpop(), SPpop()); } //C! c a -- , Store character
void cFetch() { SPpush(Mfetch8(SPpop())); } //C@ a -- c, Fetch character


  // Return stack words eForthAndZen#40
void RPat() { SPpush(FROMRAMADDR(ramRP)); } //RP@
void RPbang() { ramRP = RAMADDR(SPpop()); } // RP! must be aligned
void Rfrom() { SPpush(RPpop()); } // R>
void Rat() { SPpush(RPfetch()); } // R@
void toR() { RPpush(SPpop()); } // >R

  // Data stack initialization eForthAndZen#41
void SPat() { SPpush(FROMRAMADDR(ramSP)); } //SP@
void SPbang() { ramSP = RAMADDR(SPpop()); } //SP! must be aligned

// Classic Data stack words eForthAndZen#42
void DROP() { ramSP++; };
void DUP() { SPpush(SPfetch()); };
void SWAP() {
  const CELLTYPE x = SPpop();
  const CELLTYPE y = SPpop();
  SPpush(x);
  SPpush(y);
};
void OVER() {
  const CELLTYPE x = SPpop();
  const CELLTYPE y = SPfetch();
  SPpush(x);
  SPpush(y);
}; // TODO optimize

  // Logical Words eForthAndZen43
  // noinspection JSBitwiseOperatorUsage
void less0() { SPpush((SPpop() & (1 << (CELLbits - 1))) ? -1 : 0); } //0<  e.g. 0x8000 for CELLL=2
void AND() { SPpush(SPpop() & SPpop()); }
void OR() { SPpush(SPpop() | SPpop()); }
void XOR() { SPpush(SPpop() ^ SPpop()); }

  // Primitive Arithmetic Word eForthAndZen44
void UMplus() {
  const CELLTYPE a = SPpop();
  const CELLTYPE b = SPpop();
  /*
  if (CELLL === 4) {
    // JS truncates to 32 bits before shift, so use it here rather than getting bitten below
    const x = (a >>> 0) + (b >>> 0);
    SPpush(x >>> 0);
    SPpush(x >= 0x100000000 ? 1 : 0);
  } else {
  */
    // Note there is what I believe is a JS bug where x >> 32 is a noop so do th double shift
    const CELLTYPE x = a + b;
    SPpush(x); // This should only push the bottom cell.
    SPpush(x >> CELLbits);
  //}
}
  // === Define and initialize User variables Zen pg33 see Zen pg46
  // See Zen pg31 for tokenUser etc and $USER and Zen pg33 for USER initialization values

  // TODO-28-MULTITASK will need to think carefully about how to move all, or part of the USER space to task-specific space.
  // TODO-28-MULTITASK this is non-trivial since somethings are clearly across all tasks (e.g. CP and NP)
void userAreaInit() {
  for (byte a = 0; a < _USER; a++) {
    Ustore(a, cellRomFetch(UZERO + a));
  }
  //testing3();
}

  // The opposite of userAreaInit - save values for restoration at COLD
  // Note it saves the value of LAST which is also in "FORTH", the "OVERT" in COLD restores that
void userAreaSave() {
  #ifdef WRITEROM
    for (byte a = 0; a < _USER; a++) {
      cellRomStore(UZERO + a, Ufetch(a));
    }
  #else
    Serial.println(F("Cannot write to Rom area"));
  #endif
}

  // === Forth words written in JS as needed for the interpreter
/* REPLACED BY FORTH DEFINITION
void PARSE() { // returns b (address) and u (length)
  const byte delimiter = SPpop(); // delimiter
  const CELLTYPE tib = Ufetch(TIBoffset);
  const byte ntib = Ufetch(nTIBoffset);
  byte inoffset = Ufetch(INoffset);
  if (delimiter == BL) {
    while ((inoffset < ntib) && (Mfetch8(tib + inoffset) <= BL)) {
      inoffset++;
    }  // If blank then skip over leading BL /control chars
  }
  // inoffset now points at first non-delimiter or #TIB
  const CELLTYPE b = tib + inoffset; // Save start of string
  while ((inoffset < ntib) && ((delimiter == BL) ? (delimiter < Mfetch8(tib + inoffset)) : (delimiter != Mfetch8(tib + inoffset)))) {
    inoffset++;
  } // Exit with inoffset at #TIB or after delimiter
  SPpush(b);
  SPpush(tib + inoffset - b); // Store length not including trailing delimiter
  Ustore(INoffset, inoffset < ntib ? ++inoffset : inoffset); // Skip over delimiter - TODO its not clear this is what FORTH wants. eForth doc is almost certainly wrong
}
*/
/* REPLACED BY FORTH DEFINITION
// JS version of TOKEN - same signature
//TODO-ARDUINO optimize TOKEN to use cell pointers
void TOKEN() { // -- a; <string>; copy blank delimited string to name buffer, immediately below name dictionary (location is important as ':' take a shortcut in eForth.
  SPpush(BL);
  PARSE();   // b u (counted string, adjusts >IN)
  const byte u = min(SPpop(), nameMaxLength); // length of string
  const CELLTYPE b = SPpop(); // start of string
  const CELLTYPE np = align(npFetch() - u - CELLL); // Enough space in Name Directory to copy string optionally with one zero after
  // Careful if edit next formula, align doesnt change if mem=8, AND in this case np may not be on a cell boundary
  Mstore(np + ((u / CELLL)>>0) * CELLL, 0); // Write a zero in the last cell where the last letter of word will be written
  copyWithin(np + 1, b, b + u);
  Mstore8(np, u);  // 1 byte count
  SPpush(np); // Note that NP is not updated, the same buffer will be used for each word until hit ':'
}
*/

/* REPLACED BY FORTH DEFINITION
// Same footprint as NUMBER?, this will be stored vectored from 'NUMBER and then replaced by FORTH version.
void NUMBERQ() {
  CELLTYPE a = SPpop();
  const CELLTYPE aa = a;
  const byte radix = Ufetch(BASEoffset); //TODO-ANDROID handle base other than 10 BUT maybe not needed as switch to Forth version before ever use non-decimal
  bool neg = false;
  CELLTYPE acc = 0;
  for (byte i = Mfetch8(a++); i > 0; i--) {
    byte c = Mfetch8(a++);
    if (c == '-') {
       neg = true;
    } else if ((c > '9') || (c < '0')) {
        SPpush(aa);
        SPpush(0);
        return;
    } else {
      c = c - '0';
      acc = (acc * radix) + acc;
    }
  }
  if (neg) { acc = -acc; }
  SPpush(acc);
  SPpush(forthTrue);
}
*/
/* Not needed on Arduino
  // If we are going to compile it, then check its not compiling into the dict, code we plan on replacing. (See same code on "'")
  checkNotCompilingReplaceable(xt, na) {
    if (jsFunctionAttributes[Mfetch(xt)].replaced) {
      const inDefOf = countedToJS(lastFetch());
      if (!['[COMPILE]', '(', 'create', 'CREATE', 'vCREATE'].includes(inDefOf)) { // Intentionally redefine ( so ok with redefinition
        console.log('Compiling', countedToJS(na), 'in', inDefOf, 'when code will be deleted');
        console.assert(false); // Break here, shouldn't be happening.
      }
    }
  }
*/

/* REPLACED BY FORTH DEFINITION
void dCOMPILE() { // a -- ...; same signature as to $COMPILE at Zen pg96
    findName(); // xt na | a F
    const CELLTYPE na = SPpop();
    if (na) { // ca
      const CELLTYPE xt = SPpop();
      const byte ch = Mfetch8(na);
      // noinspection JSBitwiseOperatorUsage
      if (ch & IMED) {
        runXT(xt);
      } else {
        //TODO-ARDUINO dont think needed: checkNotCompilingReplaceable(xt, na);
        //if (testing & 0x02) console.log('COMPILING:', countedToJS(na));
        DW(xt);
      }
    } else { // a
      runXT(Ufetch(NUMBERoffset)); // n T | a F // Works as long as NUMBER is code, OR this is called from code.
      if (SPpop()) {
        DW(XT_doLIT);
        DW(SPpop());
      } else {
        // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
        Serial.print(F("Cannot find or convert to number")); printCounted(SPpop());
      }
    }
  }
*/
/* REPLACED BY FORTH DEFINITION
void dINTERPRET() { // a -- ...; Based on signature of $INTERPRET at Zen pg83
  findName(); // xt na | a F
  const CELLTYPE na = SPpop();
  if (na) { // ca
    const CELLTYPE xt = SPpop();
    runXT(xt); //TODO-ASYNC maybe should be threadToken - but that won't work if this isn't running inside run already
  } else {
    runXT(Ufetch(NUMBERoffset)); // n T | a F
    if (!SPpop()) {
      // TODO-32-ERRORS handle error in Forth-ish way (via Throw) - this is harder than it looks !
      Serial.print(F("Cannot find or convert to number")); printCounted(SPpop());
    }
  }
}
*/
/*
void EVAL() { // Same signature as Forth EVAL, reads tokens from TIB and interprets
  while (Ufetch(INoffset) < Ufetch(nTIBoffset)) {
    TOKEN(); // a ; pointing to word in Name Buffer (NB)
    // There may be case where TOKEN returns empty string at end of line or similar
    if (Mfetch8(SPfetch()) == 0) { // Skip zero length string
      SPpop();
    } else {
      // This is currently OK since its calling JS routines that may call Forth, there is no Forth-in-Forth
      runXT(Ufetch(EVALoffset));
    }
    // TODO-28-MULTITASK RP0 will move
    //console.assert(cellSP <= cellSPP && (cellRP * CELLL) <= Ufetch(RP0offset)); // Side effect of making SP and SPP available to debugger.
  }
  const CELLTYPE prompt = Ufetch(PROMPToffset);
  if (prompt) {
    runXT(prompt);
  }
}
*/
// ==== FORTH Interpreter - words that have no Forth equivalent ====
/*
void JStoTIB(s) {
  const TIBoff = Ufetch(TIBoffset);
  console.assert((TIBoff + s.length) < (Ufetch(RP0offset) - 10)); // Check for overlong lines
  Ustore(INoffset, 0); // Start at beginning of TIB
  Ustore(nTIBoffset,  m.encodeString(TIBoff, s)); // copy string to TIB, and store length in #TIB
}
*/
/*
// Take a multiline string, and pass line by line to EVAL
interpret(inp) {
  const inputs = inp.split('\n');
  // eslint-disable-next-line no-restricted-syntax,guard-for-in
  for (const i in inputs) {
    // noinspection JSUnfilteredForInLoop
    const inputline = inputs[i];
    if (testing & 0x01) {
      console.log(debugCells(cellSP, cellSPP), ' >>', inputline);
    }
    JStoTIB(inputline);
    await EVAL();
  }
}
*/
/*
async interpret1(inp) {
  JStoTIB(inp);
  await runXT(JStoXT('quit1', true));
}
// === A group of words required for the JS interpreter redefined later
*/

/* REPLACED BY FORTH DEFINITION
// : [  doLIT $INTERPRET 'EVAL ! ; IMMEDIATE
//Zen pg84 and Zen pg88  redefined below to use FORTH $INTERPRET
void openBracket() {
  Ustore(EVALoffset, XT__24INTERPRET); // uses JS $INTERPRET
}
*/

/* REPLACED BY FORTH DEFINITION
// : ] doLIT $COMPILE 'EVAL ! ;
//Zen pg84 and Zen pg95  redefined below to use FORTH $COMPILE
void closeBracket() {
  Ustore(EVALoffset, XT__24COMPILE);
}
*/

/* REPLACED BY FORTH DEFINITION
// : : TOKEN $,n [ ' doLIST ] LITERAL ] ; see Zen pg96
void colon() {
  TOKEN();  // a; (counted string in named space)
  cpAlign(); // Before dollarCommaN so code field in Name dictionary correct
  dollarCommaN();
  DW(F_tokenDoList); // Must be after creating the name and links etc
  closeBracket();
}
*/
/* REPLACED BY FORTH DEFINITION
// : ; doLIT EXIT , OVERT [ ; IMMEDIATE
void semicolon() { // Zen pg95
  DW(XT_EXIT);
  OVERT();
  openBracket();
}
*/
/* REPLACED BY FORTH DEFINITION
// : ' ( -- xt ) TOKEN NAME? IF EXIT THEN THROW ; // Zen pg89 needs TOKEN NAME? THROW all of which are advanced
void tick() { // -- xt; Search for next word in input stream
  TOKEN(); // -- a; String with count in first byte
  //const a = SPfetch(); // used for debugging
  findName(); // xt na | a 0
  const CELLTYPE na = SPpop();
  if (!na) {
    printCounted(SPpop()); Serial.println(F("not found during"));
  } else {
    // For debugging need to make sure we are not including code that will replaced by Forth versions.
    // checkNotCompilingReplaceable(SPfetch(), na);
  }
}
*/
/* not relevant on Arduino - we'll be running cold at startup
void console() {
  runXT(XT_WARM);
}
*/



// ==== NEXT GROUP - HAVE TO BE MOVED DOWN BECAUSE OF USE ===
// L.1853 jsFunctions[]=

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); // Initialize IO port TODO move to somewhere Forth wants it
  //(*f[0])(); // TEST function pointer
  Serial.print(F("Starting: Space for, ")); Serial.print(NAMEE - CODEE), Serial.println(F("bytes for code and names"));
  delay(10000);
  //L.1898
  //TODO I think most of these will be in the Usersave area with values setup by the call useRam() run in the XC before saving.
  // Importantly - CPoffset won't be CODEE, it will be at least 2 cells higher as 'FORTH's data area is underneath it.
  //Ustore(CPoffset, CODEE); //TODO-ARDUINO set from user variables
  //Ustore(NPoffset, NAMEE);  //TODO-ARDUINO set from user variables
  //Ustore(VPoffset, 0); // Bottom of RAM - Note that this is set to 0 t make it use CP (which by now is in RAM) for variables
  //Ustore(RP0offset, RP0);
  //Ustore(SP0offset, cellSPP << CELLSHIFT); // Shouldnt be needed as should be in ROM
  IP = XT_COLD+CELLL; // This has a tight interaction with loop - which will look at next value and threadToken on it. (So this only works on a colon definition)
  Serial.println("XXX end setup");
  delay(1000);
}

void loop() {
  threadtoken(IPnext());
}
