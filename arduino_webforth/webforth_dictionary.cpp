#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x9b84 /* WARM*/
#define XT_COLD 0x9b6c /* COLD*/
#define XT__27BOOT 0x9b66 /* 'BOOT*/
#define XT_EMPTY 0x9b56 /* EMPTY*/
#define XT_hi 0x9b4e /* hi*/
#define XT_version 0x9b0c /* version*/
#define XT_VER 0x9b08 /* VER*/
#define XT_SEE 0x9a82 /* SEE*/
#define XT__3ENAME 0x9a46 /* >NAME*/
#define XT_WORDS 0x9a24 /* WORDS*/
#define XT__2EID 0x9a04 /* .ID*/
#define XT__3FCSP 0x99ea /* ?CSP*/
#define XT__21CSP 0x99e0 /* !CSP*/
#define XT__2EFREE 0x99d4 /* .FREE*/
#define XT__2EBASE 0x99c2 /* .BASE*/
#define XT_UNUSED 0x99b4 /* UNUSED*/
#define XT__2ES 0x9994 /* .S*/
#define XT_DUMP 0x9950 /* DUMP*/
#define XT_dm_2B 0x992c /* dm+*/
#define XT_EVALUATE 0x9912 /* EVALUATE*/
#define XT_quit1 0x98fe /* quit1*/
#define XT_QUIT 0x98cc /* QUIT*/
#define XT_quitError 0x989c /* quitError*/
#define XT_PRESET 0x9878 /* PRESET*/
#define XT_que 0x9870 /* que*/
#define XT_QUERY 0x982c /* QUERY*/
#define XT_REFILL 0x97fa /* REFILL*/
#define XT_READ_2DLINE 0x97f6 /* READ-LINE*/
#define XT_sourcePop 0x97ea /* sourcePop*/
#define XT_RESTORE_2DINPUT 0x97c0 /* RESTORE-INPUT*/
#define XT_sourcePush 0x97b6 /* sourcePush*/
#define XT_SAVE_2DINPUT 0x97a6 /* SAVE-INPUT*/
#define XT_unreadFile 0x97a2 /* unreadFile*/
#define XT_0_3E 0x9792 /* 0>*/
#define XT_sourceStack 0x978a /* sourceStack*/
#define XT_SOURCE_2DID 0x9782 /* SOURCE-ID*/
#define XT_sempty 0x9774 /* sempty*/
#define XT_spops 0x9750 /* spops*/
#define XT_spushes 0x972e /* spushes*/
#define XT_spush 0x9716 /* spush*/
#define XT_spop 0x9700 /* spop*/
#define XT_stack 0x96de /* stack*/
#define XT_ACCEPT 0x96a6 /* ACCEPT*/
#define XT__28charbase_29 0x95c0 /* (charbase)*/
#define XT__3ENUMBER 0x9580 /* >NUMBER*/
#define XT_accumulate 0x9562 /* accumulate*/
#define XT_J_2DMAX 0x9552 /* J-MAX*/
#define XT_J 0x9542 /* J*/
#define XT_I_2DMAX 0x9532 /* I-MAX*/
#define XT__2BLOOP 0x9528 /* +LOOP*/
#define XT_LOOP 0x951e /* LOOP*/
#define XT_some_2Dloop 0x94f2 /* some-loop*/
#define XT__3FDO 0x94d6 /* ?DO*/
#define XT_DO 0x94c0 /* DO*/
#define XT_UNLOOP 0x94b8 /* UNLOOP*/
#define XT_LEAVE 0x94ae /* LEAVE*/
#define XT_leave_2C 0x949e /* leave,*/
#define XT__28_2Bloop_29 0x9460 /* (+loop)*/
#define XT__28loop_29 0x944c /* (loop)*/
#define XT__28_3Fdo_29 0x943a /* (?do)*/
#define XT_leave_2Dptr 0x9434 /* leave-ptr*/
#define XT_CONSTANT 0x9424 /* CONSTANT*/
#define XT_VARIABLE 0x9418 /* VARIABLE*/
#define XT_TO 0x9412 /* TO*/
#define XT_VALUE 0x93f6 /* VALUE*/
#define XT_ 0x93be /* */
#define XT_ 0x9392 /* */
#define XT_EVAL 0x9368 /* EVAL*/
#define XT_ 0x933c /* */
#define XT_ 0x9320 /* */
#define XT__3FUNIQUE 0x9304 /* ?UNIQUE*/
#define XT_RECURSE 0x92f8 /* RECURSE*/
#define XT_ACTION_2DOF 0x92de /* ACTION-OF*/
#define XT_IS 0x92d8 /* IS*/
#define XT__27_3EBODY_21 0x92be /* '>BODY!*/
#define XT_BUFFER_3A 0x92b6 /* BUFFER:*/
#define XT_vALLOT 0x92a0 /* vALLOT*/
#define XT_ALLOT 0x9298 /* ALLOT*/
#define XT_ 0x9288 /* */
#define XT_CONSOLE 0x927a /* CONSOLE*/
#define XT_I_2FO 0x9272 /* I/O*/
#define XT_HAND 0x9260 /* HAND*/
#define XT_FILE 0x924e /* FILE*/
#define XT_XIO 0x923e /* XIO*/
#define XT_ 0x9234 /* */
#define XT__3FSTACK 0x9220 /* ?STACK*/
#define XT__2EOK 0x920a /* .OK*/
#define XT_ 0x91d8 /* */
#define XT_POSTPONE 0x91ac /* POSTPONE*/
#define XT_ABORT_22 0x91a2 /* ABORT"*/
#define XT_abort_22 0x9192 /* abort"*/
#define XT_ABORT 0x918a /* ABORT*/
#define XT_NULL_24 0x9184 /* NULL$*/
#define XT_S_5C_22 0x9142 /* S\"*/
#define XT_pack_5C_24 0x90fa /* pack\$*/
#define XT_cmove_5C 0x8f88 /* cmove\*/
#define XT_c_2B_21 0x8f7e /* c+!*/
#define XT_bu_2B_40 0x8f70 /* bu+@*/
#define XT_S_22 0x8f4e /* S"*/
#define XT__2E_22 0x8f44 /* ."*/
#define XT_C_22 0x8f3e /* C"*/
#define XT__24_22 0x8f34 /* $"*/
#define XT_S_22_7C 0x8f2c /* S"|*/
#define XT__2E_22_7C 0x8f24 /* ."|*/
#define XT__24_22_7C 0x8f1e /* $"|*/
#define XT__24_2C_22 0x8f0a /* $,"*/
#define XT_do_24 0x8ef4 /* do$*/
#define XT_kTAP 0x8ebc /* kTAP*/
#define XT_skipToCRLF 0x8e94 /* skipToCRLF*/
#define XT_skipCRLF 0x8e6e /* skipCRLF*/
#define XT_crlf_3F 0x8e58 /* crlf?*/
#define XT_TAP 0x8e48 /* TAP*/
#define XT__5EH 0x8e1c /* ^H*/
#define XT_THROW 0x8dfa /* THROW*/
#define XT_CATCH 0x8dd6 /* CATCH*/
#define XT_MARKER 0x8d6a /* MARKER*/
#define XT_FIND 0x8d38 /* FIND*/
#define XT_NAME_3F 0x8d1a /* NAME?*/
#define XT_FIND_2DNAME 0x8cd8 /* FIND-NAME*/
#define XT_SAME_3F 0x8ca6 /* SAME?*/
#define XT_NAME_3EINTERPRET 0x8c98 /* NAME>INTERPRET*/
#define XT_WORD 0x8c8e /* WORD*/
#define XT_ 0x8c76 /* */
#define XT__2E_28 0x8c6a /* .(*/
#define XT_CTRL 0x8c5e /* CTRL*/
#define XT__5BCHAR_5D 0x8c56 /* [CHAR]*/
#define XT_CHAR 0x8c4c /* CHAR*/
#define XT_PARSE_2DNAME 0x8c44 /* PARSE-NAME*/
#define XT_ 0x8bec /* */
#define XT_skip_2Dtill 0x8bc4 /* skip-till*/
#define XT_xt_2Dskip 0x8b9e /* xt-skip*/
#define XT_isnotspace_3F 0x8b96 /* isnotspace?*/
#define XT_isspace_3F 0x8b8c /* isspace?*/
#define XT__2FSTRING 0x8b7e /* /STRING*/
#define XT_SOURCE 0x8b74 /* SOURCE*/
#define XT__5B_27_5D 0x8b6c /* [']*/
#define XT_CR 0x8b5c /* CR*/
#define XT_PACE 0x8b52 /* PACE*/
#define XT_NUF_3F 0x8b3c /* NUF?*/
#define XT_KEY 0x8b26 /* KEY*/
#define XT__3FKEY 0x8b1e /* ?KEY*/
#define XT_DIGIT_3F 0x8ade /* DIGIT?*/
#define XT__3F 0x8ad6 /* ?*/
#define XT__2E 0x8aba /* .*/
#define XT_U_2E 0x8aa8 /* U.*/
#define XT_U_2ER 0x8a8e /* U.R*/
#define XT__2ER 0x8a7c /* .R*/
#define XT_DECIMAL 0x8a70 /* DECIMAL*/
#define XT_HEX 0x8a64 /* HEX*/
#define XT_str 0x8a4c /* str*/
#define XT__2E_24 0x8a44 /* .$*/
#define XT_SPACES 0x8a3c /* SPACES*/
#define XT_emits 0x8a20 /* emits*/
#define XT_SPACE 0x8a18 /* SPACE*/
#define XT_EMIT 0x8a10 /* EMIT*/
#define XT__23_3E 0x8a00 /* #>*/
#define XT_SIGN 0x89f0 /* SIGN*/
#define XT__23S 0x89de /* #S*/
#define XT__23 0x89d2 /* #*/
#define XT_HOLDS 0x89b8 /* HOLDS*/
#define XT_HOLD 0x89a6 /* HOLD*/
#define XT__3C_23 0x899c /* <#*/
#define XT_EXTRACT 0x8980 /* EXTRACT*/
#define XT_DIGIT 0x8966 /* DIGIT*/
#define XT_PACK_24 0x8934 /* PACK$*/
#define XT__2DTRAILING 0x890c /* -TRAILING*/
#define XT_ERASE 0x8902 /* ERASE*/
#define XT_FILL 0x88e8 /* FILL*/
#define XT_MOVE 0x88ce /* MOVE*/
#define XT_CMOVE_3E 0x889a /* CMOVE>*/
#define XT_CMOVE 0x887a /* CMOVE*/
#define XT_COUNT 0x886e /* COUNT*/
#define XT__40EXECUTE 0x8860 /* @EXECUTE*/
#define XT_TIB 0x8856 /* TIB*/
#define XT_PAD 0x884a /* PAD*/
#define XT_vCREATE 0x882e /* vCREATE*/
#define XT_vALIGN 0x8820 /* vALIGN*/
#define XT_v_2C 0x8800 /* v,*/
#define XT_vHERE 0x87ee /* vHERE*/
#define XT_2_40 0x87e0 /* 2@*/
#define XT_2_21 0x87d2 /* 2!*/
#define XT__2D_2D 0x87c6 /* --*/
#define XT__2B_2B 0x87ba /* ++*/
#define XT__2B_21 0x87aa /* +!*/
#define XT_PICK 0x879c /* PICK*/
#define XT_ 0x878a /* */
#define XT__3ECHAR 0x876c /* >CHAR*/
#define XT_DEFER_21 0x8766 /* DEFER!*/
#define XT__3EBODY_21 0x875e /* >BODY!*/
#define XT_DEFER_40 0x8756 /* DEFER@*/
#define XT__3ANONAME 0x8734 /* :NONAME*/
#define XT__28_24_2Cn_29 0x8708 /* ($,n)*/
#define XT_2_2A 0x86fe /* 2**/
#define XT_CHARS 0x86fa /* CHARS*/
#define XT_CELLS 0x86f2 /* CELLS*/
#define XT_CELL_2D 0x86ea /* CELL-*/
#define XT_SM_2FREM 0x86c6 /* SM/REM*/
#define XT_DABS 0x86b8 /* DABS*/
#define XT_D0_3C 0x86b0 /* D0<*/
#define XT__2A_2F 0x86a8 /* * /*/
#define XT__2A_2FMOD 0x869c /* * /MOD*/
#define XT_M_2A 0x8680 /* M**/
#define XT__2A 0x8678 /* **/
#define XT_UM_2A 0x863e /* UM**/
#define XT__2F 0x8636 /* /*/
#define XT_MOD 0x862e /* MOD*/
#define XT__2FMOD 0x8622 /* /MOD*/
#define XT_FM_2FMOD 0x861c /* FM/MOD*/
#define XT_M_2FMOD 0x85e6 /* M/MOD*/
#define XT_UM_2FMOD 0x8586 /* UM/MOD*/
#define XT_S_3ED 0x857e /* S>D*/
#define XT_WITHIN 0x856e /* WITHIN*/
#define XT_MIN 0x855c /* MIN*/
#define XT_MAX 0x854c /* MAX*/
#define XT__3E 0x8544 /* >*/
#define XT__3C 0x852c /* <*/
#define XT_ud_3C 0x8514 /* ud<*/
#define XT_U_3E 0x850c /* U>*/
#define XT_U_3C 0x84f4 /* U<*/
#define XT__3C_3E 0x84e4 /* <>*/
#define XT__3D 0x84d4 /* =*/
#define XT_C_2C 0x84c4 /* C,*/
#define XT_CHAR_2B 0x84be /* CHAR+*/
#define XT_ABS 0x84b6 /* ABS*/
#define XT__3Fnegate 0x84aa /* ?negate*/
#define XT_1_2D 0x84a0 /* 1-*/
#define XT__2D 0x8498 /* -*/
#define XT_DNEGATE 0x8484 /* DNEGATE*/
#define XT_NEGATE 0x847c /* NEGATE*/
#define XT_1_2B 0x8472 /* 1+*/
#define XT_INVERT 0x8468 /* INVERT*/
#define XT_D_2B 0x8454 /* D+*/
#define XT_2SWAP 0x8448 /* 2SWAP*/
#define XT_2OVER 0x8436 /* 2OVER*/
#define XT_2DUP 0x842e /* 2DUP*/
#define XT__2DROT 0x8422 /* -ROT*/
#define XT__3Ftest_5C 0x8412 /* ?test\*/
#define XT__3Fsafe_5C 0x8402 /* ?safe\*/
#define XT__3F_5C 0x83f6 /* ?\*/
#define XT_D0_3D 0x83ee /* D0=*/
#define XT_0_3C_3E 0x83e6 /* 0<>*/
#define XT_0_3D 0x83d6 /* 0=*/
#define XT_ENDCASE 0x83cc /* ENDCASE*/
#define XT_ENDOF 0x83bc /* ENDOF*/
#define XT_OF 0x83b2 /* OF*/
#define XT_CASE 0x83ac /* CASE*/
#define XT__3ERESOLVETHREAD 0x8396 /* >RESOLVETHREAD*/
#define XT__3EMARKTHREAD 0x838c /* >MARKTHREAD*/
#define XT__3EMARKSTART 0x8384 /* >MARKSTART*/
#define XT__3ERESOLVES 0x8374 /* >RESOLVES*/
#define XT__3FDUP 0x8368 /* ?DUP*/
#define XT_WHILE 0x8360 /* WHILE*/
#define XT_WHEN 0x8358 /* WHEN*/
#define XT_ELSE 0x834e /* ELSE*/
#define XT_AFT 0x8342 /* AFT*/
#define XT_THEN 0x833c /* THEN*/
#define XT_REPEAT 0x8334 /* REPEAT*/
#define XT_AHEAD 0x832a /* AHEAD*/
#define XT_IF 0x8320 /* IF*/
#define XT_AGAIN 0x8316 /* AGAIN*/
#define XT_UNTIL 0x830c /* UNTIL*/
#define XT_NEXT 0x8302 /* NEXT*/
#define XT_BEGIN 0x82fc /* BEGIN*/
#define XT_FOR 0x82f2 /* FOR*/
#define XT__3ERESOLVE 0x82e8 /* >RESOLVE*/
#define XT__3EMARK 0x82dc /* >MARK*/
#define XT__3CRESOLVE 0x82d6 /* <RESOLVE*/
#define XT__3CMARK 0x82d0 /* <MARK*/
#define XT_CREATE 0x82c8 /* CREATE*/
#define XT_create 0x82b6 /* create*/
#define XT_LITERAL 0x82ac /* LITERAL*/
#define XT_COMPILE 0x829c /* COMPILE*/
#define XT__5BCOMPILE_5D 0x8294 /* [COMPILE]*/
#define XT_COMPILE_2C 0x828e /* COMPILE,*/
#define XT__2C 0x827c /* ,*/
#define XT_CELL_2B 0x8274 /* CELL+*/
#define XT__2B 0x826c /* +*/
#define XT_HERE 0x8264 /* HERE*/
#define XT_TUCK 0x825c /* TUCK*/
#define XT_NIP 0x8254 /* NIP*/
#define XT__5C 0x8248 /* \*/
#define XT_IMMEDIATE 0x8240 /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x8238 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x8226 /* setHeaderBits*/
#define XT_2DROP 0x821e /* 2DROP*/
#define XT_testDepth 0x821a /* testDepth*/
#define XT_testFlags 0x8216 /* testFlags*/
#define XT_source_2Did 0x8212 /* source-id*/
#define XT_VP 0x820e /* VP*/
#define XT_LAST 0x820a /* LAST*/
#define XT_NP 0x8206 /* NP*/
#define XT_CP 0x8202 /* CP*/
#define XT_CURRENT 0x81fe /* CURRENT*/
#define XT_CONTEXT 0x81fa /* CONTEXT*/
#define XT_HANDLER 0x81f6 /* HANDLER*/
#define XT_HLD 0x81f2 /* HLD*/
#define XT_SPARE2 0x81ee /* SPARE2*/
#define XT_STATE 0x81ea /* STATE*/
#define XT_CSP 0x81e6 /* CSP*/
#define XT__23TIB 0x81e2 /* #TIB*/
#define XT__3EIN 0x81de /* >IN*/
#define XT_SPAN 0x81da /* SPAN*/
#define XT_temp 0x81d6 /* temp*/
#define XT_BASE 0x81d2 /* BASE*/
#define XT__27PROMPT 0x81ce /* 'PROMPT*/
#define XT__27ECHO 0x81ca /* 'ECHO*/
#define XT__27TAP 0x81c6 /* 'TAP*/
#define XT_SPARE 0x81c2 /* SPARE*/
#define XT__27EMIT 0x81be /* 'EMIT*/
#define XT__27_3FKEY 0x81ba /* '?KEY*/
#define XT_RP0 0x81b6 /* RP0*/
#define XT_SP0 0x81b2 /* SP0*/
#define XT__5FUSER 0x81ae /* _USER*/
#define XT__2D_3E 0x81aa /* ->*/
#define XT__7DT 0x81a4 /* }T*/
#define XT_DEPTH 0x819e /* DEPTH*/
#define XT_T_7B 0x8198 /* T{*/
#define XT_of 0x8194 /* of*/
#define XT_DEFER 0x8190 /* DEFER*/
#define XT__3EBODY 0x818c /* >BODY*/
#define XT_ALIGN 0x818a /* ALIGN*/
#define XT_immediate_3F 0x8188 /* immediate?*/
#define XT_2RDrop 0x8186 /* 2RDrop*/
#define XT_RDrop 0x8184 /* RDrop*/
#define XT_leave 0x8182 /* leave*/
#define XT_I 0x8180 /* I*/
#define XT_loop 0x817e /* loop*/
#define XT_TYPE 0x817c /* TYPE*/
#define XT_stringBuffer 0x817a /* stringBuffer*/
#define XT_Fbreak 0x8178 /* Fbreak*/
#define XT_debugNA 0x8176 /* debugNA*/
#define XT__27 0x8172 /* '*/
#define XT__3B 0x816c /* ;*/
#define XT__3A 0x8166 /* :*/
#define XT__5D 0x8160 /* ]*/
#define XT__5B 0x815a /* [*/
#define XT__24INTERPRET 0x8154 /* $INTERPRET*/
#define XT__24COMPILE 0x814e /* $COMPILE*/
#define XT_NUMBER_3F 0x8148 /* NUMBER?*/
#define XT_TOKEN 0x8142 /* TOKEN*/
#define XT__28 0x813c /* (*/
#define XT_PARSE 0x8136 /* PARSE*/
#define XT_userAreaSave 0x8132 /* userAreaSave*/
#define XT_userAreaInit 0x8130 /* userAreaInit*/
#define XT_2_2F 0x812e /* 2/*/
#define XT_LSHIFT 0x812c /* LSHIFT*/
#define XT_RSHIFT 0x812a /* RSHIFT*/
#define XT_UM_2B 0x8128 /* UM+*/
#define XT_XOR 0x8126 /* XOR*/
#define XT_OR 0x8124 /* OR*/
#define XT_AND 0x8122 /* AND*/
#define XT_0_3C 0x8120 /* 0<*/
#define XT_ROT 0x811e /* ROT*/
#define XT_ROLL 0x811c /* ROLL*/
#define XT_OVER 0x811a /* OVER*/
#define XT_SWAP 0x8118 /* SWAP*/
#define XT_DUP 0x8116 /* DUP*/
#define XT_DROP 0x8114 /* DROP*/
#define XT_SP_21 0x8112 /* SP!*/
#define XT_SP_40 0x8110 /* SP@*/
#define XT_2_3ER 0x810e /* 2>R*/
#define XT_2R_40 0x810c /* 2R@*/
#define XT_2R_3E 0x810a /* 2R>*/
#define XT__3ER 0x8108 /* >R*/
#define XT_R_40 0x8106 /* R@*/
#define XT_R_3E 0x8104 /* R>*/
#define XT_RP_21 0x8102 /* RP!*/
#define XT_RP_40 0x8100 /* RP@*/
#define XT_C_21 0x80fe /* C!*/
#define XT_C_40 0x80fc /* C@*/
#define XT__40 0x80fa /* @*/
#define XT__21 0x80f8 /* !*/
#define XT_branch 0x80f6 /* branch*/
#define XT__3Fbranch 0x80f4 /* ?branch*/
#define XT_next 0x80f2 /* next*/
#define XT_DOES_3E 0x80f0 /* DOES>*/
#define XT_doLit 0x80ee /* doLit*/
#define XT__21IO 0x80ec /* !IO*/
#define XT_TX_21 0x80ea /* TX!*/
#define XT__3FRX 0x80e8 /* ?RX*/
#define XT_EXECUTE 0x80e6 /* EXECUTE*/
#define XT_EXIT 0x80e4 /* EXIT*/
#define XT_BYE 0x80e2 /* BYE*/
#define XT_ms 0x80e0 /* ms*/
#define XT__24_2Cn 0x80dc /* $,n*/
#define XT_OVERT 0x80d6 /* OVERT*/
#define XT_FIND_2DNAME_2DIN 0x80d2 /* FIND-NAME-IN*/
#define XT_ALIGNED 0x80d0 /* ALIGNED*/
#define XT_tokenValue 0x80cc /* tokenValue*/
#define XT_tokenDefer 0x80c8 /* tokenDefer*/
#define XT_tokenCreate 0x80c4 /* tokenCreate*/
#define XT_tokenVar 0x80c0 /* tokenVar*/
#define XT_tokenUser 0x80bc /* tokenUser*/
#define XT_tokenDoList 0x80b8 /* tokenDoList*/
#define XT_tokenNextVal 0x80b4 /* tokenNextVal*/
#define XT_tokenVocabulary 0x80b0 /* tokenVocabulary*/
#define XT_BL 0x80ac /* BL*/
#define XT_FALSE 0x80a8 /* FALSE*/
#define XT_TRUE 0x80a4 /* TRUE*/
#define XT_BYTEMASK 0x80a0 /* BYTEMASK*/
#define XT_IMED 0x809c /* IMED*/
#define XT_COMP 0x8098 /* COMP*/
#define XT_rqFiles 0x8094 /* rqFiles*/
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
#define F_tokenDefer 7
#define F_tokenValue 8
#define F_ALIGNED 9
#define F_findNameIn 10
#define F_OVERT 11
#define F_dollarCommaN 12
#define F_ms 13
#define F_BYE 14
#define F_EXIT 15
#define F_EXECUTE 16
#define F_QRX 17
#define F_TXstore 18
#define F_storeIO 19
#define F_doLit 20
#define F_DOES 21
#define F_next 22
#define F_qBranch 23
#define F_branch 24
#define F_store 25
#define F_fetch 26
#define F_CFetch 27
#define F_CStore 28
#define F_RPat 29
#define F_RPStore 30
#define F_Rfrom 31
#define F_Rat 32
#define F_toR 33
#define F_TwoRfrom 34
#define F_TwoRFetch 35
#define F_TwotoR 36
#define F_SPat 37
#define F_SPbang 38
#define F_DROP 39
#define F_DUP 40
#define F_SWAP 41
#define F_OVER 42
#define F_ROLL 43
#define F_ROT 44
#define F_zeroLess 45
#define F_AND 46
#define F_OR 47
#define F_XOR 48
#define F_UMplus 49
#define F_RSHIFT 50
#define F_LSHIFT 51
#define F_TwoDiv 52
#define F_userAreaInit 53
#define F_userAreaSave 54
#define F_PARSE 55
#define F_parenthesis 56
#define F_TOKEN 57
#define F_NUMBERQ 58
#define F_dCOMPILE 59
#define F_dINTERPRET 60
#define F_openBracket 61
#define F_closeBracket 62
#define F_colon 63
#define F_semicolon 64
#define F_tick 65
#define F_debugNA 66
#define F_Fbreak 67
#define F_stringBuffer 68
#define F_TYPE 69
#define F_loop 70
#define F_I 71
#define F_leave 72
#define F_RDrop 73
#define F_TwoRDrop 74
#define F_immediateQ 75
#define F_vpAlign 76
#define F_toBODY 77
#define F_DEFER 78
#define F_of 79
#define F_Tbrace 80
#define F_DEPTH 81
#define F_Tunbrace 82
#define F_Tarrow 83
/* === Function table - maps tokens to functions === */
extern void tokenVocabulary();
extern void tokenNextVal();
extern void tokenDoList();
extern void tokenUser();
extern void tokenVar();
extern void tokenCreate();
extern void tokenDefer();
extern void tokenValue();
extern void ALIGNED();
extern void findNameIn();
extern void ms();
extern void BYE();
extern void EXIT();
extern void EXECUTE();
extern void QRX();
extern void TXstore();
extern void storeIO();
extern void doLit();
extern void DOES();
extern void next();
extern void qBranch();
extern void branch();
extern void store();
extern void fetch();
extern void CFetch();
extern void CStore();
extern void RPat();
extern void RPStore();
extern void Rfrom();
extern void Rat();
extern void toR();
extern void TwoRfrom();
extern void TwoRFetch();
extern void TwotoR();
extern void SPat();
extern void SPbang();
extern void DROP();
extern void DUP();
extern void SWAP();
extern void OVER();
extern void ROLL();
extern void ROT();
extern void zeroLess();
extern void AND();
extern void OR();
extern void XOR();
extern void UMplus();
extern void RSHIFT();
extern void LSHIFT();
extern void TwoDiv();
extern void userAreaInit();
extern void userAreaSave();
extern void debugNA();
extern void Fbreak();
extern void stringBuffer();
extern void TYPE();
extern void loop();
extern void I();
extern void leave();
extern void RDrop();
extern void TwoRDrop();
extern void immediateQ();
extern void vpAlign();
extern void toBODY();
extern void of();
void (* const f[FUNCTIONSLENGTH])() = {
0, tokenVocabulary, tokenNextVal, tokenDoList, 
tokenUser, tokenVar, tokenCreate, tokenDefer, 
tokenValue, ALIGNED, /* FIND-NAME-IN */ findNameIn, 0, 
0, ms, BYE, EXIT, 
EXECUTE, /* ?RX */ QRX, /* TX! */ TXstore, /* !IO */ storeIO, 
doLit, /* DOES> */ DOES, next, /* ?branch */ qBranch, 
branch, /* ! */ store, /* @ */ fetch, /* C@ */ CFetch, 
/* C! */ CStore, /* RP@ */ RPat, /* RP! */ RPStore, /* R> */ Rfrom, 
/* R@ */ Rat, /* >R */ toR, /* 2R> */ TwoRfrom, /* 2R@ */ TwoRFetch, 
/* 2>R */ TwotoR, /* SP@ */ SPat, /* SP! */ SPbang, DROP, 
DUP, SWAP, OVER, ROLL, 
ROT, /* 0< */ zeroLess, AND, OR, 
XOR, /* UM+ */ UMplus, RSHIFT, LSHIFT, 
/* 2/ */ TwoDiv, userAreaInit, userAreaSave, 0, 
0, 0, 0, 0, 
0, 0, 0, 0, 
0, 0, debugNA, Fbreak, 
stringBuffer, TYPE, loop, I, 
leave, RDrop, /* 2RDrop */ TwoRDrop, /* immediate? */ immediateQ, 
/* ALIGN */ vpAlign, /* >BODY */ toBODY, 0, of, 
0, 0, 0, 0,  0 };
const CELLTYPE rom[ROMCELLS] PROGMEM = {
/* ==== USER VARIABLE SAVE AREA ==== */
/* 0x8000 _USER */ 0x29,
/* 0x8002 undefined */ 0,
/* 0x8004 undefined */ 0,
/* 0x8006 undefined */ 0,
/* 0x8008 SP0 */ 0x260,
/* 0x800a RP0 */ 0x370,
/* 0x800c '?KEY */ XT__3FRX,
/* 0x800e 'EMIT */ XT_TX_21,
/* 0x8010 SPARE */ 0,
/* 0x8012 'TAP */ 0,
/* 0x8014 'ECHO */ XT_TX_21,
/* 0x8016 'PROMPT */ 0,
/* 0x8018 BASE */ 0xa,
/* 0x801a temp */ 0,
/* 0x801c SPAN */ 0,
/* 0x801e >IN */ 0xd,
/* 0x8020 #TIB */ 0x3a,
/* 0x8022 undefined */ TIB0,
/* 0x8024 CSP */ 0,
/* 0x8026 STATE */ 0,
/* 0x8028 SPARE2 */ 0,
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
/* 0x8044 CP */ 0x4a,
/* 0x8046 NP */ 0x160,
/* 0x8048 LAST */ 0xcfa8,
/* 0x804a VP */ 0,
/* 0x804c source-id */ 0,
/* 0x804e testFlags */ 0,
/* 0x8050 testDepth */ 1,
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
/* 0x8094: rqFiles */ F_tokenNextVal, 0, 
/* 0x8098: COMP */ F_tokenNextVal, 0x40, 
/* 0x809c: IMED */ F_tokenNextVal, 0x80, 
/* 0x80a0: BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x80a4: TRUE */ F_tokenNextVal, 0xffff, 
/* 0x80a8: FALSE */ F_tokenNextVal, 0, 
/* 0x80ac: BL */ F_tokenNextVal, 0x20, 
/* 0x80b0: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x80b4: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x80b8: tokenDoList */ F_tokenNextVal, 3, 
/* 0x80bc: tokenUser */ F_tokenNextVal, 4, 
/* 0x80c0: tokenVar */ F_tokenNextVal, 5, 
/* 0x80c4: tokenCreate */ F_tokenNextVal, 6, 
/* 0x80c8: tokenDefer */ F_tokenNextVal, 7, 
/* 0x80cc: tokenValue */ F_tokenNextVal, 8, 
/* 0x80d0: ALIGNED */ F_ALIGNED, 
/* 0x80d2: FIND-NAME-IN */ F_findNameIn, 0xb, 
/* 0x80d6: OVERT */ F_tokenDefer, XT_, 0xc, 
/* 0x80dc: $,n */ F_tokenDefer, XT_, 
/* 0x80e0: ms */ F_ms, 
/* 0x80e2: BYE */ F_BYE, 
/* 0x80e4: EXIT */ F_EXIT, 
/* 0x80e6: EXECUTE */ F_EXECUTE, 
/* 0x80e8: ?RX */ F_QRX, 
/* 0x80ea: TX! */ F_TXstore, 
/* 0x80ec: !IO */ F_storeIO, 
/* 0x80ee: doLit */ F_doLit, 
/* 0x80f0: DOES> */ F_DOES, 
/* 0x80f2: next */ F_next, 
/* 0x80f4: ?branch */ F_qBranch, 
/* 0x80f6: branch */ F_branch, 
/* 0x80f8: ! */ F_store, 
/* 0x80fa: @ */ F_fetch, 
/* 0x80fc: C@ */ F_CFetch, 
/* 0x80fe: C! */ F_CStore, 
/* 0x8100: RP@ */ F_RPat, 
/* 0x8102: RP! */ F_RPStore, 
/* 0x8104: R> */ F_Rfrom, 
/* 0x8106: R@ */ F_Rat, 
/* 0x8108: >R */ F_toR, 
/* 0x810a: 2R> */ F_TwoRfrom, 
/* 0x810c: 2R@ */ F_TwoRFetch, 
/* 0x810e: 2>R */ F_TwotoR, 
/* 0x8110: SP@ */ F_SPat, 
/* 0x8112: SP! */ F_SPbang, 
/* 0x8114: DROP */ F_DROP, 
/* 0x8116: DUP */ F_DUP, 
/* 0x8118: SWAP */ F_SWAP, 
/* 0x811a: OVER */ F_OVER, 
/* 0x811c: ROLL */ F_ROLL, 
/* 0x811e: ROT */ F_ROT, 
/* 0x8120: 0< */ F_zeroLess, 
/* 0x8122: AND */ F_AND, 
/* 0x8124: OR */ F_OR, 
/* 0x8126: XOR */ F_XOR, 
/* 0x8128: UM+ */ F_UMplus, 
/* 0x812a: RSHIFT */ F_RSHIFT, 
/* 0x812c: LSHIFT */ F_LSHIFT, 
/* 0x812e: 2/ */ F_TwoDiv, 
/* 0x8130: userAreaInit */ F_userAreaInit, 
/* 0x8132: userAreaSave */ F_userAreaSave, 0x37, 
/* 0x8136: PARSE */ F_tokenDefer, XT_, 0x38, 
/* 0x813c: ( */ F_tokenDefer, 0x983a, 0x39, 
/* 0x8142: TOKEN */ F_tokenDefer, XT_, 0x3a, 
/* 0x8148: NUMBER? */ F_tokenDefer, 0x95fe, 0x3b, 
/* 0x814e: $COMPILE */ F_tokenDefer, XT_, 0x3c, 
/* 0x8154: $INTERPRET */ F_tokenDefer, XT_, 0x3d, 
/* 0x815a: [ */ F_tokenDefer, XT_, 0x3e, 
/* 0x8160: ] */ F_tokenDefer, 0x93ca, 0x3f, 
/* 0x8166: : */ F_tokenDefer, 0x93d4, 0x40, 
/* 0x816c: ; */ F_tokenDefer, XT_, 0x41, 
/* 0x8172: ' */ F_tokenDefer, XT_, 
/* 0x8176: debugNA */ F_debugNA, 
/* 0x8178: Fbreak */ F_Fbreak, 
/* 0x817a: stringBuffer */ F_stringBuffer, 
/* 0x817c: TYPE */ F_TYPE, 
/* 0x817e: loop */ F_loop, 
/* 0x8180: I */ F_I, 
/* 0x8182: leave */ F_leave, 
/* 0x8184: RDrop */ F_RDrop, 
/* 0x8186: 2RDrop */ F_TwoRDrop, 
/* 0x8188: immediate? */ F_immediateQ, 
/* 0x818a: ALIGN */ F_vpAlign, 
/* 0x818c: >BODY */ F_toBODY, 0x4e, 
/* 0x8190: DEFER */ F_tokenDefer, 0x93e2, 
/* 0x8194: of */ F_of, 0x50, 
/* 0x8198: T{ */ F_tokenDefer, 0x8196, 0x51, 
/* 0x819e: DEPTH */ F_tokenDefer, XT_, 0x52, 
/* 0x81a4: }T */ F_tokenDefer, 0x81a2, 0x53, 
/* 0x81aa: -> */ F_tokenDefer, 0x81a8, 
/* 0x81ae: _USER */ F_tokenUser, 0, 
/* 0x81b2: SP0 */ F_tokenUser, 4, 
/* 0x81b6: RP0 */ F_tokenUser, 5, 
/* 0x81ba: '?KEY */ F_tokenUser, 6, 
/* 0x81be: 'EMIT */ F_tokenUser, 7, 
/* 0x81c2: SPARE */ F_tokenUser, 8, 
/* 0x81c6: 'TAP */ F_tokenUser, 9, 
/* 0x81ca: 'ECHO */ F_tokenUser, 0xa, 
/* 0x81ce: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x81d2: BASE */ F_tokenUser, 0xc, 
/* 0x81d6: temp */ F_tokenUser, 0xd, 
/* 0x81da: SPAN */ F_tokenUser, 0xe, 
/* 0x81de: >IN */ F_tokenUser, 0xf, 
/* 0x81e2: #TIB */ F_tokenUser, 0x10, 
/* 0x81e6: CSP */ F_tokenUser, 0x12, 
/* 0x81ea: STATE */ F_tokenUser, 0x13, 
/* 0x81ee: SPARE2 */ F_tokenUser, 0x14, 
/* 0x81f2: HLD */ F_tokenUser, 0x15, 
/* 0x81f6: HANDLER */ F_tokenUser, 0x16, 
/* 0x81fa: CONTEXT */ F_tokenUser, 0x17, 
/* 0x81fe: CURRENT */ F_tokenUser, 0x20, 
/* 0x8202: CP */ F_tokenUser, 0x22, 
/* 0x8206: NP */ F_tokenUser, 0x23, 
/* 0x820a: LAST */ F_tokenUser, 0x24, 
/* 0x820e: VP */ F_tokenUser, 0x25, 
/* 0x8212: source-id */ F_tokenUser, 0x26, 
/* 0x8216: testFlags */ F_tokenUser, 0x27, 
/* 0x821a: testDepth */ F_tokenUser, 0x28, 
/* 0x821e: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x8226: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x8238: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x8240: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x8248: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x8254: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x825c: TUCK */ F_tokenDoList, XT_SWAP, XT_OVER, XT_EXIT, 
/* 0x8264: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x826c: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x8274: CELL+ */ F_tokenDoList, XT_CELLL, XT__2B, XT_EXIT, 
/* 0x827c: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x828e: COMPILE, */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x8294: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x829c: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x82ac: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLit, XT__2C, XT_EXIT, 
/* 0x82b6: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x82c8: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x82d0: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x82d6: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x82dc: >MARK */ F_tokenDoList, XT_HERE, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x82e8: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x82f2: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x82fc: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x8302: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x830c: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x8316: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x8320: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x832a: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x8334: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x833c: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x8342: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x834e: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x8358: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x8360: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x8368: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x8374: >RESOLVES */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVES + 0xe, XT__3ERESOLVE, XT_branch, XT__3ERESOLVES + 2, XT_EXIT, 
/* 0x8384: >MARKSTART */ F_tokenDoList, XT_doLit, 0, XT_EXIT, 
/* 0x838c: >MARKTHREAD */ F_tokenDoList, XT_HERE, XT_SWAP, XT__2C, XT_EXIT, 
/* 0x8396: >RESOLVETHREAD */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVETHREAD + 0x14, XT_DUP, XT__40, XT_SWAP, XT__3ERESOLVE, XT_branch, XT__3ERESOLVETHREAD + 2, XT_EXIT, 
/* 0x83ac: CASE */ F_tokenDoList, XT__3EMARKSTART, XT_EXIT, 
/* 0x83b2: OF */ F_tokenDoList, XT_COMPILE, XT_of, XT__3EMARK, XT_EXIT, 
/* 0x83bc: ENDOF */ F_tokenDoList, XT_COMPILE, XT_branch, XT_SWAP, XT__3EMARKTHREAD, XT_SWAP, XT__3ERESOLVE, XT_EXIT, 
/* 0x83cc: ENDCASE */ F_tokenDoList, XT_COMPILE, XT_DROP, XT__3ERESOLVETHREAD, XT_EXIT, 
/* 0x83d6: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xc, XT_FALSE, XT_branch, XT_0_3D + 0xe, XT_TRUE, XT_EXIT, 
/* 0x83e6: 0<> */ F_tokenDoList, XT_0_3D, XT_0_3D, XT_EXIT, 
/* 0x83ee: D0= */ F_tokenDoList, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x83f6: ?\ */ F_tokenDoList, XT_0_3D, XT__3Fbranch, XT__3F_5C + 0xa, XT__5C, XT_EXIT, 
/* 0x8402: ?safe\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 4, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x8412: ?test\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 8, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x8422: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x842e: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x8436: 2OVER */ F_tokenDoList, XT__3ER, XT__3ER, XT_2DUP, XT_R_3E, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8448: 2SWAP */ F_tokenDoList, XT__3ER, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8454: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x8468: INVERT */ F_tokenDoList, XT_doLit, 0xffff, XT_XOR, XT_EXIT, 
/* 0x8472: 1+ */ F_tokenDoList, XT_doLit, 1, XT__2B, XT_EXIT, 
/* 0x847c: NEGATE */ F_tokenDoList, XT_INVERT, XT_1_2B, XT_EXIT, 
/* 0x8484: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLit, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8498: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x84a0: 1- */ F_tokenDoList, XT_doLit, 1, XT__2D, XT_EXIT, 
/* 0x84aa: ?negate */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT__3Fnegate + 0xa, XT_NEGATE, XT_EXIT, 
/* 0x84b6: ABS */ F_tokenDoList, XT_DUP, XT__3Fnegate, XT_EXIT, 
/* 0x84be: CHAR+ */ F_tokenDoList, XT_1_2B, XT_EXIT, 
/* 0x84c4: C, */ F_tokenDoList, XT_HERE, XT_DUP, XT_CHAR_2B, XT_CP, XT__21, XT_C_21, XT_EXIT, 
/* 0x84d4: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xc, XT_FALSE, XT_EXIT, XT_TRUE, XT_EXIT, 
/* 0x84e4: <> */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3C_3E + 0xc, XT_TRUE, XT_EXIT, XT_FALSE, XT_EXIT, 
/* 0x84f4: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x850c: U> */ F_tokenDoList, XT_SWAP, XT_U_3C, XT_EXIT, 
/* 0x8514: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x14, XT_2DROP, XT_TRUE, XT_branch, XT_ud_3C + 0x16, XT_U_3C, XT_EXIT, 
/* 0x852c: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x8544: > */ F_tokenDoList, XT_SWAP, XT__3C, XT_EXIT, 
/* 0x854c: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x855c: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x856e: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x857e: S>D */ F_tokenDoList, XT_DUP, XT_0_3C, XT_EXIT, 
/* 0x8586: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x54, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x46, XT__3ER, XT_DROP, XT_1_2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x48, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLit, 0xffff, XT_DUP, XT_EXIT, 
/* 0x85e6: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x861c: FM/MOD */ F_tokenDoList, XT_M_2FMOD, XT_EXIT, 
/* 0x8622: /MOD */ F_tokenDoList, XT__3ER, XT_S_3ED, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x862e: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x8636: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x863e: UM* */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x8678: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x8680: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x869c: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x86a8: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x86b0: D0< */ F_tokenDoList, XT_NIP, XT_0_3C, XT_EXIT, 
/* 0x86b8: DABS */ F_tokenDoList, XT_2DUP, XT_D0_3C, XT__3Fbranch, XT_DABS + 0xc, XT_DNEGATE, XT_EXIT, 
/* 0x86c6: SM/REM */ F_tokenDoList, XT_2DUP, XT_XOR, XT__3ER, XT_OVER, XT__3ER, XT_ABS, XT__3ER, XT_DABS, XT_R_3E, XT_UM_2FMOD, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_EXIT, 
/* 0x86ea: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x86f2: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x86fa: CHARS */ F_tokenDoList, XT_EXIT, 
/* 0x86fe: 2* */ F_tokenDoList, XT_doLit, 2, XT__2A, XT_EXIT, 
/* 0x8708: ($,n) */ F_tokenDoList, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_DUP, XT_CP, XT__21, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, 
/* 0x8734: :NONAME */ F_tokenDoList, XT_NP, XT__40, XT_CELL_2D, XT_doLit, 0, XT_OVER, XT__21, XT_DUP, XT_NP, XT__21, XT__28_24_2Cn_29, XT_HERE, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x8756: DEFER@ */ F_tokenDoList, XT__3EBODY, XT__40, XT_EXIT, 
/* 0x875e: >BODY! */ F_tokenDoList, XT__3EBODY, XT__21, XT_EXIT, 
/* 0x8766: DEFER! */ F_tokenDoList, XT__3EBODY_21, XT_EXIT, 
/* 0x876c: >CHAR */ F_tokenDoList, XT_doLit, 0x7f, XT_AND, XT_DUP, XT_doLit, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLit, 0x5f, XT_EXIT, 
/* 0x878a:  */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x879c: PICK */ F_tokenDoList, XT_1_2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x87aa: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x87ba: ++ */ F_tokenDoList, XT_doLit, 1, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87c6: -- */ F_tokenDoList, XT_doLit, 0xffff, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87d2: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x87e0: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x87ee: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x8800: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x8820: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x882e: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT, 
/* 0x884a: PAD */ F_tokenDoList, XT_HERE, XT_doLit, 0x50, XT__2B, XT_EXIT, 
/* 0x8856: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x8860: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0xc, XT_EXECUTE, XT_EXIT, 
/* 0x886e: COUNT */ F_tokenDoList, XT_DUP, XT_1_2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x887a: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x18, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2B, XT_R_3E, XT_1_2B, XT_next, XT_CMOVE + 8, XT_2DROP, XT_EXIT, 
/* 0x889a: CMOVE> */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_R_3E, XT__3ER, XT_branch, XT_CMOVE_3E + 0x2c, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2D, XT_R_3E, XT_1_2D, XT_next, XT_CMOVE_3E + 0x1c, XT_2DROP, XT_EXIT, 
/* 0x88ce: MOVE */ F_tokenDoList, XT__3ER, XT_2DUP, XT__3E, XT_R_3E, XT_SWAP, XT__3Fbranch, XT_MOVE + 0x16, XT_CMOVE, XT_branch, XT_MOVE + 0x18, XT_CMOVE_3E, XT_EXIT, 
/* 0x88e8: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x12, XT_2DUP, XT_C_21, XT_1_2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x8902: ERASE */ F_tokenDoList, XT_doLit, 0, XT_FILL, XT_EXIT, 
/* 0x890c: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x1e, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x1e, XT_R_3E, XT_1_2B, XT_EXIT, XT_next, XT__2DTRAILING + 8, XT_doLit, 0, XT_EXIT, 
/* 0x8934: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLit, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_1_2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x8966: DIGIT */ F_tokenDoList, XT_doLit, 9, XT_OVER, XT__3C, XT_doLit, 7, XT_AND, XT__2B, XT_doLit, 0x30, XT__2B, XT_EXIT, 
/* 0x8980: EXTRACT */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT_R_40, XT_FM_2FMOD, XT_R_3E, XT_SWAP, XT__3ER, XT_FM_2FMOD, XT_R_3E, XT_ROT, XT_DIGIT, XT_EXIT, 
/* 0x899c: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x89a6: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_1_2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x89b8: HOLDS */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_HOLDS + 0x16, XT_1_2D, XT_2DUP, XT__2B, XT_C_40, XT_HOLD, XT_branch, XT_HOLDS + 2, XT_2DROP, XT_EXIT, 
/* 0x89d2: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x89de: #S */ F_tokenDoList, XT__23, XT_2DUP, XT_OR, XT__3Fbranch, XT__23S + 0x10, XT_branch, XT__23S + 2, XT_EXIT, 
/* 0x89f0: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLit, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x8a00: #> */ F_tokenDoList, XT_2DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8a10: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x8a18: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x8a20: emits */ F_tokenDoList, XT_SWAP, XT_doLit, 0, XT_MAX, XT__3ER, XT_branch, XT_emits + 0x14, XT_DUP, XT_EMIT, XT_next, XT_emits + 0x10, XT_DROP, XT_EXIT, 
/* 0x8a3c: SPACES */ F_tokenDoList, XT_BL, XT_emits, XT_EXIT, 
/* 0x8a44: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x8a4c: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT_doLit, 0, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x8a64: HEX */ F_tokenDoList, XT_doLit, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a70: DECIMAL */ F_tokenDoList, XT_doLit, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a7c: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8a8e: U.R */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8aa8: U. */ F_tokenDoList, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8aba: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLit, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8ad6: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x8ade: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLit, 0x30, XT__2D, XT_doLit, 0x2a, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x1c, XT_doLit, 0x20, XT__2D, XT_doLit, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x38, XT_doLit, 7, XT__2D, XT_DUP, XT_doLit, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x8b1e: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x8b26: KEY */ F_tokenDoList, XT_doLit, 0, XT_ms, XT_doLit, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT, 
/* 0x8b3c: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLit, 0xd, XT__3D, XT_EXIT, 
/* 0x8b52: PACE */ F_tokenDoList, XT_doLit, 0xb, XT_EMIT, XT_EXIT, 
/* 0x8b5c: CR */ F_tokenDoList, XT_doLit, 0xd, XT_EMIT, XT_doLit, 0xa, XT_EMIT, XT_EXIT, 
/* 0x8b6c: ['] */ F_tokenDoList, XT__27, XT_LITERAL, XT_EXIT, 
/* 0x8b74: SOURCE */ F_tokenDoList, XT_TIB, XT__23TIB, XT__40, XT_EXIT, 
/* 0x8b7e: /STRING */ F_tokenDoList, XT_TUCK, XT__2D, XT__3ER, XT__2B, XT_R_3E, XT_EXIT, 
/* 0x8b8c: isspace? */ F_tokenDoList, XT_BL, XT_1_2B, XT_U_3C, XT_EXIT, 
/* 0x8b96: isnotspace? */ F_tokenDoList, XT_isspace_3F, XT_0_3D, XT_EXIT, 
/* 0x8b9e: xt-skip */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT_OVER, XT_C_40, XT_R_40, XT_EXECUTE, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_xt_2Dskip + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8bc4: skip-till */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT_OVER, XT_C_40, XT_R_40, XT__3D, XT_0_3D, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_skip_2Dtill + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8bec:  */ F_tokenDoList, XT__3ER, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c08, XT_doLit, XT_isspace_3F, XT_xt_2Dskip, XT_OVER, XT_SWAP, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c20, XT_doLit, XT_isnotspace_3F, XT_xt_2Dskip, XT_branch, 0x8c24, XT_R_40, XT_skip_2Dtill, XT_R_3E, XT_DROP, XT_2DUP, XT_doLit, 1, XT_MIN, XT__2B, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8c44: PARSE-NAME */ F_tokenDoList, XT_BL, XT_PARSE, XT_EXIT, 
/* 0x8c4c: CHAR */ F_tokenDoList, XT_PARSE_2DNAME, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x8c56: [CHAR] */ F_tokenDoList, XT_CHAR, XT_LITERAL, XT_EXIT, 
/* 0x8c5e: CTRL */ F_tokenDoList, XT_CHAR, XT_doLit, 0x1f, XT_AND, XT_EXIT, 
/* 0x8c6a: .( */ F_tokenDoList, XT_doLit, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x8c76:  */ F_tokenDoList, XT_PARSE_2DNAME, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x8c8e: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x8c98: NAME>INTERPRET */ F_tokenDoList, XT_doLit, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x8ca6: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 8, XT_FALSE, XT_EXIT, 
/* 0x8cd8: FIND-NAME */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_FIND_2DNAME + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT__3ER, XT_R_40, XT__40, XT__3Fbranch, XT_FIND_2DNAME + 0x38, XT_2DUP, XT_R_40, XT__40, XT_FIND_2DNAME_2DIN, XT__3FDUP, XT__3Fbranch, XT_FIND_2DNAME + 0x12, XT_R_3E, XT_DROP, XT_NIP, XT_NIP, XT_EXIT, XT_R_3E, XT_DROP, XT_2DROP, XT_FALSE, XT_EXIT, 
/* 0x8d1a: NAME? */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x1a, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_branch, XT_NAME_3F + 0x1c, XT_FALSE, XT_EXIT, 
/* 0x8d38: FIND */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_FIND + 0x2c, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_immediate_3F, XT__3Fbranch, XT_FIND + 0x24, XT_doLit, 1, XT_branch, XT_FIND + 0x28, XT_doLit, 0xffff, XT_branch, XT_FIND + 0x30, XT_doLit, 0, XT_EXIT, 
/* 0x8d6a: MARKER */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT_CONTEXT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CURRENT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CREATE, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT_DOES_3E, XT_DUP, XT__40, XT_CURRENT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CURRENT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CP, XT__21, XT_CELL_2B, XT__40, XT_NP, XT__21, XT_EXIT, 
/* 0x8dd6: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLit, 0, XT_EXIT, 
/* 0x8dfa: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x20, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x8e1c: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8e48: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8e58: crlf? */ F_tokenDoList, XT_DUP, XT_doLit, 0xa, XT__3D, XT_SWAP, XT_doLit, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x8e6e: skipCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipCRLF + 0x12, XT_OVER, XT_C_40, XT_crlf_3F, XT_branch, XT_skipCRLF + 0x14, XT_FALSE, XT__3Fbranch, XT_skipCRLF + 0x24, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipCRLF + 2, XT_EXIT, 
/* 0x8e94: skipToCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipToCRLF + 0x14, XT_OVER, XT_C_40, XT_crlf_3F, XT_0_3D, XT_branch, XT_skipToCRLF + 0x16, XT_FALSE, XT__3Fbranch, XT_skipToCRLF + 0x26, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipToCRLF + 2, XT_EXIT, 
/* 0x8ebc: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x30, XT_DUP, XT_doLit, 8, XT__3D, XT_SWAP, XT_doLit, 0x7f, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x2c, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x2e, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x8ef4: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x8f0a: $," */ F_tokenDoList, XT_doLit, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x8f1e: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x8f24: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x8f2c: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x8f34: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f3e: C" */ F_tokenDoList, XT__24_22, XT_EXIT, 
/* 0x8f44: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f4e: S" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_branch, XT_S_22 + 0x20, XT_doLit, 0x22, XT_PARSE, XT_stringBuffer, XT_PACK_24, XT_COUNT, XT_EXIT, 
/* 0x8f70: bu+@ */ F_tokenDoList, XT_1_2D, XT__3ER, XT_COUNT, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x8f7e: c+! */ F_tokenDoList, XT_TUCK, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8f88: cmove\ */ F_tokenDoList, XT_SWAP, XT_DUP, XT__3ER, XT__3ER, XT__3FDUP, XT__3Fbranch, 0x90f2, XT_bu_2B_40, XT_DUP, XT_doLit, 0x22, XT__3C_3E, XT__3Fbranch, 0x90f0, XT_doLit, 0x5c, XT_of, 0x90e2, XT_bu_2B_40, XT_doLit, 0x6d, XT_of, XT_cmove_5C + 0x46, XT_doLit, 0xd, XT_R_3E, XT_c_2B_21, XT_doLit, 0xa, XT_SWAP, XT_c_2B_21, XT__3ER, XT_branch, 0x90de, XT_doLit, 0x78, XT_of, XT_cmove_5C + 0x78, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_doLit, 0x10, XT__2A, XT__3ER, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_R_3E, XT__2B, XT_R_3E, XT_c_2B_21, XT__3ER, XT_branch, 0x90de, XT_doLit, 0x61, XT_of, XT_cmove_5C + 0x88, XT_doLit, 7, XT_branch, 0x90d4, XT_doLit, 0x62, XT_of, XT_cmove_5C + 0x98, XT_doLit, 8, XT_branch, 0x90d4, XT_doLit, 0x65, XT_of, XT_cmove_5C + 0xa8, XT_doLit, 0x1b, XT_branch, 0x90d4, XT_doLit, 0x66, XT_of, XT_cmove_5C + 0xb8, XT_doLit, 0xc, XT_branch, 0x90d4, XT_doLit, 0x6c, XT_of, XT_cmove_5C + 0xc8, XT_doLit, 0xa, XT_branch, 0x90d4, XT_doLit, 0x6e, XT_of, XT_cmove_5C + 0xd8, XT_doLit, 0xa, XT_branch, 0x90d4, XT_doLit, 0x71, XT_of, XT_cmove_5C + 0xe8, XT_doLit, 0x22, XT_branch, 0x90d4, XT_doLit, 0x72, XT_of, XT_cmove_5C + 0xf8, XT_doLit, 0xd, XT_branch, 0x90d4, XT_doLit, 0x74, XT_of, 0x9090, XT_doLit, 9, XT_branch, 0x90d4, XT_doLit, 0x76, XT_of, 0x90a0, XT_doLit, 0xb, XT_branch, 0x90d4, XT_doLit, 0x7a, XT_of, 0x90b0, XT_doLit, 0, XT_branch, 0x90d4, XT_doLit, 0x22, XT_of, 0x90c0, XT_doLit, 0x22, XT_branch, 0x90d4, XT_doLit, 0x5c, XT_of, 0x90d0, XT_doLit, 0x5c, XT_branch, 0x90d4, XT_DUP, XT_DROP, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, 0x90ec, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, XT_cmove_5C + 0xa, XT_2DROP, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x90fa: pack\$ */ F_tokenDoList, XT_ALIGNED, XT__3ER, XT_R_40, XT_1_2B, XT_SWAP, XT_cmove_5C, XT_DUP, XT_R_40, XT_C_21, XT_DUP, XT_R_40, XT__2B, XT_1_2B, XT_SWAP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__3FDUP, XT__3Fbranch, XT_pack_5C_24 + 0x42, XT_SWAP, XT_doLit, 0, XT_OVER, XT_C_21, XT_1_2B, XT_SWAP, XT_1_2D, XT_branch, XT_pack_5C_24 + 0x28, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x9142: S\" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT_HERE, XT_branch, XT_S_5C_22 + 0x16, XT_stringBuffer, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_ROT, XT_pack_5C_24, XT_SWAP, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_COUNT, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x40, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x9184: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x918a: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x9192: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x91a2: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x91ac: POSTPONE */ F_tokenDoList, XT_TOKEN, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT_0_3D, XT_abort_22, 0x4e09, 0x746f, 0x6620, 0x756f, 0x646e, XT_DUP, XT_immediate_3F, XT_0_3D, XT__3Fbranch, XT_POSTPONE + 0x26, XT_COMPILE, XT_COMPILE, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x91d8:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x91fe, XT_C_40, XT_doLit, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9206, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x920a: .OK */ F_tokenDoList, XT_STATE, XT__40, XT_0_3D, XT__3Fbranch, XT__2EOK + 0x12, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0x9220: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0x9234:  */ F_tokenDoList, XT_FALSE, XT_STATE, XT__21, XT_EXIT, 
/* 0x923e: XIO */ F_tokenDoList, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x924e: FILE */ F_tokenDoList, XT_doLit, 0, XT_doLit, XT_DROP, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x9260: HAND */ F_tokenDoList, XT_doLit, XT__2EOK, XT_doLit, XT_EMIT, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x9272: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x927a: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x9288:  */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, 0x9294, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9298: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x92a0: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0x92b6: BUFFER: */ F_tokenDoList, XT_CREATE, XT_vALLOT, XT_EXIT, 
/* 0x92be: '>BODY! */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT__27_3EBODY_21 + 0x14, XT__5B_27_5D, XT_COMPILE, XT__3EBODY_21, XT_branch, XT__27_3EBODY_21 + 0x18, XT__27, XT__3EBODY_21, XT_EXIT, 
/* 0x92d8: IS */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x92de: ACTION-OF */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_ACTION_2DOF + 0x14, XT__5B_27_5D, XT_COMPILE, XT_DEFER_40, XT_branch, XT_ACTION_2DOF + 0x18, XT__27, XT_DEFER_40, XT_EXIT, 
/* 0x92f8: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x9304: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x9320:  */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, 0x9330, XT__3FUNIQUE, XT__28_24_2Cn_29, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0x933c:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x935a, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, 0x9356, XT_EXECUTE, XT_branch, 0x9358, XT__2C, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9364, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9368: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x22, XT_STATE, XT__40, XT__3Fbranch, XT_EVAL + 0x1a, XT__24COMPILE, XT_branch, XT_EVAL + 0x1c, XT__24INTERPRET, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x9392:  */ F_tokenDoList, XT_LAST, XT__40, XT_DUP, XT__40, XT__3Fbranch, 0x93aa, XT_CURRENT, XT__40, XT__21, XT_branch, 0x93bc, XT_DROP, XT_NP, XT__40, XT_doLit, 3, XT_CELLS, XT__2B, XT_NP, XT__21, XT_EXIT, 
/* 0x93be:  */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 3, XT_TRUE, XT_STATE, XT__21, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDefer, XT__2C, XT_doLit, 0, XT__2C, XT_OVERT, XT_EXIT, 
/* 0x93f6: VALUE */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_HERE, XT_tokenValue, XT__2C, XT__5FUSER, XT__40, XT__2C, XT__5FUSER, XT__2B_2B, XT__3EBODY_21, XT_EXIT, 
/* 0x9412: TO */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x9418: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLit, 0, XT_v_2C, XT_EXIT, 
/* 0x9424: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x9434: leave-ptr */ F_tokenVar, 0, 6, 
/* 0x943a: (?do) */ F_tokenDoList, XT_R_3E, XT__2DROT, XT_2DUP, XT_2_3ER, XT__3C_3E, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x944c: (loop) */ F_tokenDoList, XT_R_3E, XT_2R_3E, XT_1_2B, XT_2DUP, XT_2_3ER, XT__3D, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x9460: (+loop) */ F_tokenDoList, XT_R_3E, XT_SWAP, XT_2R_3E, XT_doLit, 2, XT_PICK, XT_OVER, XT__2B, XT_ROT, XT_DUP, XT__3ER, XT__2DROT, XT_DUP, XT__3ER, XT_doLit, 3, XT_PICK, XT_0_3C, XT__3Fbranch, XT__28_2Bloop_29 + 0x2c, XT_SWAP, XT_1_2B, XT_SWAP, XT_1_2B, XT_SWAP, XT_WITHIN, XT_NIP, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x949e: leave, */ F_tokenDoList, XT_HERE, XT_leave_2Dptr, XT__40, XT__2C, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x94ae: LEAVE */ F_tokenDoList, XT_COMPILE, XT_branch, XT_leave_2C, XT_EXIT, 
/* 0x94b8: UNLOOP */ F_tokenDoList, XT_COMPILE, XT_2RDrop, XT_EXIT, 
/* 0x94c0: DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT_2_3ER, XT_HERE, XT_EXIT, 
/* 0x94d6: ?DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT__28_3Fdo_29, XT_COMPILE, XT__3Fbranch, XT_leave_2C, XT_HERE, XT_EXIT, 
/* 0x94f2: some-loop */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__2C, XT_leave_2Dptr, XT__40, XT__3FDUP, XT__3Fbranch, XT_some_2Dloop + 0x24, XT_DUP, XT__40, XT__3ER, XT_HERE, XT_SWAP, XT__21, XT_R_3E, XT_branch, XT_some_2Dloop + 0xc, XT_UNLOOP, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x951e: LOOP */ F_tokenDoList, XT_COMPILE, XT__28loop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x9528: +LOOP */ F_tokenDoList, XT_COMPILE, XT__28_2Bloop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x9532: I-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 2, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9542: J */ F_tokenDoList, XT_RP_40, XT_doLit, 3, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9552: J-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 4, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9562: accumulate */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_BASE, XT__40, XT_UM_2A, XT_DROP, XT_ROT, XT_BASE, XT__40, XT_UM_2A, XT_D_2B, XT_R_3E, XT_EXIT, 
/* 0x9580: >NUMBER */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_doLit, 0, XT__28_3Fdo_29, XT__3Fbranch, XT__3ENUMBER + 0x3c, XT_DROP, XT_COUNT, XT_BASE, XT__40, XT_DIGIT_3F, XT_0_3D, XT__3Fbranch, XT__3ENUMBER + 0x30, XT_DROP, XT_1_2D, XT_I_2DMAX, XT_I, XT__2D, XT_branch, XT__3ENUMBER + 0x3c, XT_accumulate, XT_doLit, 0, XT__28loop_29, XT__3Fbranch, XT__3ENUMBER + 0x12, XT_2RDrop, XT_EXIT, 
/* 0x95c0: (charbase) */ F_tokenDoList, XT_DUP, XT_doLit, 0x23, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x14, XT_doLit, 0xa, XT_EXIT, XT_DUP, XT_doLit, 0x24, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x26, XT_doLit, 0x10, XT_EXIT, XT_DUP, XT_doLit, 0x25, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x38, XT_doLit, 2, XT_EXIT, XT_doLit, 0, XT_EXIT, 3, XT_DUP, XT_BASE, XT__40, XT__3ER, XT_COUNT, XT_OVER, XT__3ER, XT__3ER, XT_COUNT, XT__28charbase_29, XT__3FDUP, XT__3Fbranch, XT__28charbase_29 + 0x62, XT_BASE, XT__21, XT_DROP, XT_COUNT, XT_DUP, XT_doLit, 0x27, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x9a, XT_DROP, XT_COUNT, XT_SWAP, XT_COUNT, XT_doLit, 0x27, XT__3C_3E, XT__3Fbranch, XT__28charbase_29 + 0x8a, XT_2DROP, XT_2RDrop, XT_FALSE, XT_branch, XT__28charbase_29 + 0x92, XT_DROP, XT_NIP, XT_TRUE, XT_2RDrop, XT_R_3E, XT_BASE, XT__21, XT_EXIT, XT_doLit, 0x2d, XT__3D, XT_TUCK, XT_0_3D, XT__3Fbranch, XT__28charbase_29 + 0xaa, XT_1_2D, XT_doLit, 0, XT_doLit, 0, XT_ROT, XT_R_3E, XT_R_3E, XT__2B, XT_OVER, XT__2D, XT__3ENUMBER, XT__3Fbranch, XT__28charbase_29 + 0xce, XT_2DROP, XT_2DROP, XT_FALSE, XT_branch, XT__28charbase_29 + 0xde, XT_DROP, XT_ROT, XT__3Fbranch, XT__28charbase_29 + 0xd8, XT_DNEGATE, XT_DROP, XT_NIP, XT_TRUE, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x96a6: ACCEPT */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_ACCEPT + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLit, 0x5f, XT_U_3C, XT__3Fbranch, XT_ACCEPT + 0x28, XT_TAP, XT_branch, XT_ACCEPT + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_ACCEPT + 8, XT_DROP, XT_SWAP, XT__2D, XT_EXIT, 
/* 0x96de: stack */ F_tokenDoList, XT_CREATE, XT_HERE, XT_doLit, 0, XT__2C, XT_OVER, XT__2C, XT_vHERE, XT_SWAP, XT__21, XT_doLit, 0, XT_v_2C, XT_CELLS, XT_vALLOT, XT_EXIT, 
/* 0x9700: spop */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_CELLS, XT_OVER, XT__2B, XT__40, XT_SWAP, XT__2D_2D, XT_EXIT, 
/* 0x9716: spush */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_1_2B, XT_2DUP, XT_SWAP, XT__21, XT_CELLS, XT__2B, XT__21, XT_EXIT, 
/* 0x972e: spushes */ F_tokenDoList, XT_OVER, XT__3ER, XT_SWAP, XT_doLit, 0, XT_2_3ER, XT_TUCK, XT_spush, XT__28loop_29, XT__3Fbranch, XT_spushes + 0xe, XT_2RDrop, XT_R_3E, XT_SWAP, XT_spush, XT_EXIT, 
/* 0x9750: spops */ F_tokenDoList, XT_DUP, XT_spop, XT__3ER, XT_R_40, XT_doLit, 0, XT_2_3ER, XT_DUP, XT_spop, XT_SWAP, XT__28loop_29, XT__3Fbranch, XT_spops + 0x10, XT_2RDrop, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x9774: sempty */ F_tokenDoList, XT__40, XT_doLit, 0, XT_SWAP, XT__21, XT_EXIT, 
/* 0x9782: SOURCE-ID */ F_tokenDoList, XT_source_2Did, XT__40, XT_EXIT, 
/* 0x978a: sourceStack */ F_tokenCreate, 0, 8, 0x20, 
/* 0x9792: 0> */ F_tokenDoList, XT_DUP, XT_0_3D, XT_SWAP, XT_0_3C, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x97a2: unreadFile */ F_tokenDefer, 0, 
/* 0x97a6: SAVE-INPUT */ F_tokenDoList, XT_SOURCE_2DID, XT_SOURCE, XT__3EIN, XT__40, XT_doLit, 4, XT_EXIT, 
/* 0x97b6: sourcePush */ F_tokenDoList, XT_SAVE_2DINPUT, XT_sourceStack, XT_spushes, XT_EXIT, 
/* 0x97c0: RESTORE-INPUT */ F_tokenDoList, XT_DROP, XT__3EIN, XT__21, XT__23TIB, XT__21, XT__23TIB, XT_CELL_2B, XT__21, XT_DUP, XT_source_2Did, XT__21, XT__3Fbranch, XT_RESTORE_2DINPUT + 0x22, XT_FILE, XT_branch, XT_RESTORE_2DINPUT + 0x24, XT_HAND, XT_doLit, 0, XT_EXIT, 
/* 0x97ea: sourcePop */ F_tokenDoList, XT_sourceStack, XT_spops, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x97f6: READ-LINE */ F_tokenDefer, 0, 
/* 0x97fa: REFILL */ F_tokenDoList, XT_SOURCE_2DID, XT__3FDUP, XT__3Fbranch, XT_REFILL + 0x1a, XT_DROP, XT_FALSE, XT_doLit, 0, XT__3EIN, XT__21, XT_branch, XT_REFILL + 0x30, XT_TIB, XT_doLit, 0x50, XT_ACCEPT, XT__23TIB, XT__21, XT_doLit, 0, XT__3EIN, XT__21, XT_TRUE, XT_EXIT, 
/* 0x982c: QUERY */ F_tokenDoList, XT_REFILL, XT_0_3D, XT__3Fbranch, XT_QUERY + 0xc, XT_sourcePop, XT_EXIT, 3, XT_doLit, 0x29, XT_PARSE, XT__2B, XT_C_40, XT_doLit, 0x29, XT__3C_3E, XT__3Fbranch, XT_QUERY + 0x42, XT_REFILL, XT_0_3D, XT_abort_22, 0x7514, 0x746e, 0x7265, 0x696d, 0x616e, 0x6574, 0x2064, 0x6f63, 0x6d6d, 0x6e65, 0x74, XT_QUERY + 0xe, XT_EXIT, 
/* 0x9870: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x9878: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_sourceStack, XT_sempty, XT_doLit, 0, XT_TIB0, XT_doLit, 0, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x989c: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLit, 0x5e, XT_emits, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0x98cc: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLit, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT__27PROMPT, XT__40, XT__3ER, XT_CONSOLE, XT_quitError, XT_R_3E, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x2c, XT__27PROMPT, XT__21, XT_branch, XT_QUIT + 8, XT_EXIT, 
/* 0x98fe: quit1 */ F_tokenDoList, XT_doLit, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0x9912: EVALUATE */ F_tokenDoList, XT_sourcePush, XT_doLit, 0xffff, XT__2DROT, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_quit1, XT_EXIT, 
/* 0x992c: dm+ */ F_tokenDoList, XT_OVER, XT_doLit, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x1e, XT_DUP, XT_C_40, XT_doLit, 3, XT_U_2ER, XT_1_2B, XT_next, XT_dm_2B + 0x12, XT_EXIT, 
/* 0x9950: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLit, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLit, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLit, 2, XT_SPACES, XT_TYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x9994: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2005, 0x733c, 0x2070, XT_EXIT, 
/* 0x99b4: UNUSED */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT__2D, XT_EXIT, 
/* 0x99c2: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x99d4: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x99e0: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x99ea: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x9a04: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT_BYTEMASK, XT_AND, XT_TYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x9a24: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT, 
/* 0x9a46: >NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT__3ENAME + 0x28, XT_2DUP, XT_NAME_3EINTERPRET, XT_XOR, XT__3Fbranch, XT__3ENAME + 0x28, XT_CELL_2D, XT_branch, XT__3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_FALSE, XT_EXIT, 
/* 0x9a82: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLit, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLit, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT, 
/* 0x9b08: VER */ F_tokenNextVal, 0x11, 
/* 0x9b0c: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT_doLit, 0, XT__3C_23, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x9b4e: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x9b56: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x9b66: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x9b6c: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT, 
/* 0x9b84: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x9b90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9db0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9df0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9eb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ed0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ef0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ff0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa010: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa030: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa050: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa070: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa090: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa110: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa130: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa150: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa170: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa190: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa210: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa230: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa250: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa270: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa290: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa310: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa330: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa350: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa370: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa390: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa410: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa430: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa450: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa470: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa490: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa510: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa530: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa550: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa570: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa590: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa610: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa630: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa650: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa670: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa690: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa710: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa730: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa750: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa770: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa790: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa810: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa830: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa850: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa870: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa890: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa910: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa930: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa950: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa970: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa990: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaab0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaad0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaaf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaeb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaed0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaef0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaff0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb010: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb030: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb050: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb070: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb090: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb110: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb130: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb150: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb170: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb190: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb210: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb230: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb250: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb270: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb290: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb310: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb330: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb350: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb370: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb390: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb410: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb430: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb450: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb470: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb490: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb510: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb530: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb550: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb570: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb590: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb610: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb630: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb650: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb670: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb690: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb710: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb730: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb750: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb770: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb790: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb810: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb830: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb850: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb870: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb890: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb910: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb930: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb950: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb970: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb990: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbab0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbad0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbaf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbeb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbed0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbef0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbff0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc010: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc030: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc050: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc070: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc090: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc110: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc130: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc150: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc170: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc190: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc210: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc230: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc250: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc270: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc290: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc310: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc330: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc350: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc370: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc390: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc410: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc430: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc450: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc470: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc490: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc510: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc530: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc550: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc570: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc590: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc610: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc630: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc650: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc670: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc690: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc710: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc730: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc750: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc770: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc790: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc810: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc830: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc850: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc870: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc890: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc910: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc930: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc950: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc970: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc990: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9b0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9d0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9f0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcab0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcad0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcaf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdd0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdf0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce90: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xceb0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xced0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcef0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf10: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf30: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf50: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf70: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf90: */ 0, 0, 0, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0xcfa4 WARM */ XT_WARM, 0xcfb2, 0x5704, 0x5241, 0x4d,
/* 0xcfae COLD */ XT_COLD, 0xcfbc, 0x4304, 0x4c4f, 0x44,
/* 0xcfb8 'BOOT */ XT__27BOOT, 0xcfc6, 0x2705, 0x4f42, 0x544f,
/* 0xcfc2 EMPTY */ XT_EMPTY, 0xcfd0, 0x4505, 0x504d, 0x5954,
/* 0xcfcc hi */ XT_hi, 0xcfd8, 0x6842, 0x69,
/* 0xcfd4 version */ XT_version, 0xcfe4, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0xcfe0 VER */ XT_VER, 0xcfec, 0x5603, 0x5245,
/* 0xcfe8 SEE */ XT_SEE, 0xcff4, 0x5303, 0x4545,
/* 0xcff0 >NAME */ XT__3ENAME, 0xcffe, 0x3e05, 0x414e, 0x454d,
/* 0xcffa WORDS */ XT_WORDS, 0xd008, 0x5705, 0x524f, 0x5344,
/* 0xd004 .ID */ XT__2EID, 0xd010, 0x2e03, 0x4449,
/* 0xd00c ?CSP */ XT__3FCSP, 0xd01a, 0x3f04, 0x5343, 0x50,
/* 0xd016 !CSP */ XT__21CSP, 0xd024, 0x2104, 0x5343, 0x50,
/* 0xd020 .FREE */ XT__2EFREE, 0xd02e, 0x2e05, 0x5246, 0x4545,
/* 0xd02a .BASE */ XT__2EBASE, 0xd038, 0x2e05, 0x4142, 0x4553,
/* 0xd034 UNUSED */ XT_UNUSED, 0xd044, 0x5506, 0x554e, 0x4553, 0x44,
/* 0xd040 .S */ XT__2ES, 0xd04c, 0x2e02, 0x53,
/* 0xd048 DUMP */ XT_DUMP, 0xd056, 0x4404, 0x4d55, 0x50,
/* 0xd052 dm+ */ XT_dm_2B, 0xd05e, 0x6403, 0x2b6d,
/* 0xd05a EVALUATE */ XT_EVALUATE, 0xd06c, 0x4508, 0x4156, 0x554c, 0x5441, 0x45,
/* 0xd068 quit1 */ XT_quit1, 0xd076, 0x7105, 0x6975, 0x3174,
/* 0xd072 QUIT */ XT_QUIT, 0xd080, 0x5104, 0x4955, 0x54,
/* 0xd07c quitError */ XT_quitError, 0xd08e, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0xd08a PRESET */ XT_PRESET, 0xd09a, 0x5006, 0x4552, 0x4553, 0x54,
/* 0xd096 que */ XT_que, 0xd0a2, 0x7103, 0x6575,
/* 0xd09e QUERY */ XT_QUERY, 0xd0ac, 0x5105, 0x4555, 0x5952,
/* 0xd0a8 REFILL */ XT_REFILL, 0xd0b8, 0x5206, 0x4645, 0x4c49, 0x4c,
/* 0xd0b4 READ-LINE */ XT_READ_2DLINE, 0xd0c6, 0x5209, 0x4145, 0x2d44, 0x494c, 0x454e,
/* 0xd0c2 sourcePop */ XT_sourcePop, 0xd0d4, 0x7309, 0x756f, 0x6372, 0x5065, 0x706f,
/* 0xd0d0 RESTORE-INPUT */ XT_RESTORE_2DINPUT, 0xd0e6, 0x520d, 0x5345, 0x4f54, 0x4552, 0x492d, 0x504e, 0x5455,
/* 0xd0e2 sourcePush */ XT_sourcePush, 0xd0f6, 0x730a, 0x756f, 0x6372, 0x5065, 0x7375, 0x68,
/* 0xd0f2 SAVE-INPUT */ XT_SAVE_2DINPUT, 0xd106, 0x530a, 0x5641, 0x2d45, 0x4e49, 0x5550, 0x54,
/* 0xd102 unreadFile */ XT_unreadFile, 0xd116, 0x750a, 0x726e, 0x6165, 0x4664, 0x6c69, 0x65,
/* 0xd112 0> */ XT_0_3E, 0xd11e, 0x3002, 0x3e,
/* 0xd11a sourceStack */ XT_sourceStack, 0xd12e, 0x730b, 0x756f, 0x6372, 0x5365, 0x6174, 0x6b63,
/* 0xd12a SOURCE-ID */ XT_SOURCE_2DID, 0xd13c, 0x5309, 0x554f, 0x4352, 0x2d45, 0x4449,
/* 0xd138 sempty */ XT_sempty, 0xd148, 0x7306, 0x6d65, 0x7470, 0x79,
/* 0xd144 spops */ XT_spops, 0xd152, 0x7305, 0x6f70, 0x7370,
/* 0xd14e spushes */ XT_spushes, 0xd15e, 0x7307, 0x7570, 0x6873, 0x7365,
/* 0xd15a spush */ XT_spush, 0xd168, 0x7305, 0x7570, 0x6873,
/* 0xd164 spop */ XT_spop, 0xd172, 0x7304, 0x6f70, 0x70,
/* 0xd16e stack */ XT_stack, 0xd17c, 0x7305, 0x6174, 0x6b63,
/* 0xd178 ACCEPT */ XT_ACCEPT, 0xd188, 0x4106, 0x4343, 0x5045, 0x54,
/* 0xd184 (charbase) */ XT__28charbase_29, 0xd198, 0x280a, 0x6863, 0x7261, 0x6162, 0x6573, 0x29,
/* 0xd194 >NUMBER */ XT__3ENUMBER, 0xd1a4, 0x3e07, 0x554e, 0x424d, 0x5245,
/* 0xd1a0 accumulate */ XT_accumulate, 0xd1b4, 0x610a, 0x6363, 0x6d75, 0x6c75, 0x7461, 0x65,
/* 0xd1b0 J-MAX */ XT_J_2DMAX, 0xd1be, 0x4a05, 0x4d2d, 0x5841,
/* 0xd1ba J */ XT_J, 0xd1c4, 0x4a01,
/* 0xd1c0 I-MAX */ XT_I_2DMAX, 0xd1ce, 0x4905, 0x4d2d, 0x5841,
/* 0xd1ca +LOOP */ XT__2BLOOP, 0xd1d8, 0x2b85, 0x4f4c, 0x504f,
/* 0xd1d4 LOOP */ XT_LOOP, 0xd1e2, 0x4c84, 0x4f4f, 0x50,
/* 0xd1de some-loop */ XT_some_2Dloop, 0xd1f0, 0x7309, 0x6d6f, 0x2d65, 0x6f6c, 0x706f,
/* 0xd1ec ?DO */ XT__3FDO, 0xd1f8, 0x3f83, 0x4f44,
/* 0xd1f4 DO */ XT_DO, 0xd200, 0x4482, 0x4f,
/* 0xd1fc UNLOOP */ XT_UNLOOP, 0xd20c, 0x5586, 0x4c4e, 0x4f4f, 0x50,
/* 0xd208 LEAVE */ XT_LEAVE, 0xd216, 0x4c85, 0x4145, 0x4556,
/* 0xd212 leave, */ XT_leave_2C, 0xd222, 0x6c06, 0x6165, 0x6576, 0x2c,
/* 0xd21e (+loop) */ XT__28_2Bloop_29, 0xd22e, 0x2807, 0x6c2b, 0x6f6f, 0x2970,
/* 0xd22a (loop) */ XT__28loop_29, 0xd23a, 0x2806, 0x6f6c, 0x706f, 0x29,
/* 0xd236 (?do) */ XT__28_3Fdo_29, 0xd244, 0x2805, 0x643f, 0x296f,
/* 0xd240 leave-ptr */ XT_leave_2Dptr, 0xd252, 0x6c09, 0x6165, 0x6576, 0x702d, 0x7274,
/* 0xd24e CONSTANT */ XT_CONSTANT, 0xd260, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0xd25c VARIABLE */ XT_VARIABLE, 0xd26e, 0x5608, 0x5241, 0x4149, 0x4c42, 0x45,
/* 0xd26a TO */ XT_TO, 0xd276, 0x5482, 0x4f,
/* 0xd272 VALUE */ XT_VALUE, 0xd280, 0x5605, 0x4c41, 0x4555,
/* 0xd27c  */ XT_, 0xd286, 0xc0,
/* 0xd282  */ XT_, 0xd28c, 0,
/* 0xd288 EVAL */ XT_EVAL, 0xd296, 0x4504, 0x4156, 0x4c,
/* 0xd292  */ XT_, 0xd29c, 0,
/* 0xd298  */ XT_, 0xd2a2, 0,
/* 0xd29e ?UNIQUE */ XT__3FUNIQUE, 0xd2ae, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0xd2aa RECURSE */ XT_RECURSE, 0xd2ba, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0xd2b6 ACTION-OF */ XT_ACTION_2DOF, 0xd2c8, 0x4189, 0x5443, 0x4f49, 0x2d4e, 0x464f,
/* 0xd2c4 IS */ XT_IS, 0xd2d0, 0x4982, 0x53,
/* 0xd2cc '>BODY! */ XT__27_3EBODY_21, 0xd2dc, 0x2707, 0x423e, 0x444f, 0x2159,
/* 0xd2d8 BUFFER: */ XT_BUFFER_3A, 0xd2e8, 0x4207, 0x4655, 0x4546, 0x3a52,
/* 0xd2e4 vALLOT */ XT_vALLOT, 0xd2f4, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0xd2f0 ALLOT */ XT_ALLOT, 0xd2fe, 0x4105, 0x4c4c, 0x544f,
/* 0xd2fa  */ XT_, 0xd304, 0,
/* 0xd300 CONSOLE */ XT_CONSOLE, 0xd310, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0xd30c I/O */ XT_I_2FO, 0xd318, 0x4903, 0x4f2f,
/* 0xd314 HAND */ XT_HAND, 0xd322, 0x4804, 0x4e41, 0x44,
/* 0xd31e FILE */ XT_FILE, 0xd32c, 0x4604, 0x4c49, 0x45,
/* 0xd328 XIO */ XT_XIO, 0xd334, 0x5803, 0x4f49,
/* 0xd330  */ XT_, 0xd33a, 0x80,
/* 0xd336 ?STACK */ XT__3FSTACK, 0xd346, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0xd342 .OK */ XT__2EOK, 0xd34e, 0x2e03, 0x4b4f,
/* 0xd34a  */ XT_, 0xd354, 0,
/* 0xd350 POSTPONE */ XT_POSTPONE, 0xd362, 0x5088, 0x534f, 0x5054, 0x4e4f, 0x45,
/* 0xd35e ABORT" */ XT_ABORT_22, 0xd36e, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0xd36a abort" */ XT_abort_22, 0xd37a, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0xd376 ABORT */ XT_ABORT, 0xd384, 0x4105, 0x4f42, 0x5452,
/* 0xd380 NULL$ */ XT_NULL_24, 0xd38e, 0x4e05, 0x4c55, 0x244c,
/* 0xd38a S\" */ XT_S_5C_22, 0xd396, 0x5383, 0x225c,
/* 0xd392 pack\$ */ XT_pack_5C_24, 0xd3a2, 0x7006, 0x6361, 0x5c6b, 0x24,
/* 0xd39e cmove\ */ XT_cmove_5C, 0xd3ae, 0x6306, 0x6f6d, 0x6576, 0x5c,
/* 0xd3aa c+! */ XT_c_2B_21, 0xd3b6, 0x6303, 0x212b,
/* 0xd3b2 bu+@ */ XT_bu_2B_40, 0xd3c0, 0x6204, 0x2b75, 0x40,
/* 0xd3bc S" */ XT_S_22, 0xd3c8, 0x5382, 0x22,
/* 0xd3c4 ." */ XT__2E_22, 0xd3d0, 0x2e82, 0x22,
/* 0xd3cc C" */ XT_C_22, 0xd3d8, 0x4382, 0x22,
/* 0xd3d4 $" */ XT__24_22, 0xd3e0, 0x2482, 0x22,
/* 0xd3dc S"| */ XT_S_22_7C, 0xd3e8, 0x5303, 0x7c22,
/* 0xd3e4 ."| */ XT__2E_22_7C, 0xd3f0, 0x2e03, 0x7c22,
/* 0xd3ec $"| */ XT__24_22_7C, 0xd3f8, 0x2403, 0x7c22,
/* 0xd3f4 $," */ XT__24_2C_22, 0xd400, 0x2403, 0x222c,
/* 0xd3fc do$ */ XT_do_24, 0xd408, 0x6403, 0x246f,
/* 0xd404 kTAP */ XT_kTAP, 0xd412, 0x6b04, 0x4154, 0x50,
/* 0xd40e skipToCRLF */ XT_skipToCRLF, 0xd422, 0x730a, 0x696b, 0x5470, 0x436f, 0x4c52, 0x46,
/* 0xd41e skipCRLF */ XT_skipCRLF, 0xd430, 0x7308, 0x696b, 0x4370, 0x4c52, 0x46,
/* 0xd42c crlf? */ XT_crlf_3F, 0xd43a, 0x6305, 0x6c72, 0x3f66,
/* 0xd436 TAP */ XT_TAP, 0xd442, 0x5403, 0x5041,
/* 0xd43e ^H */ XT__5EH, 0xd44a, 0x5e02, 0x48,
/* 0xd446 THROW */ XT_THROW, 0xd454, 0x5405, 0x5248, 0x574f,
/* 0xd450 CATCH */ XT_CATCH, 0xd45e, 0x4305, 0x5441, 0x4843,
/* 0xd45a MARKER */ XT_MARKER, 0xd46a, 0x4d06, 0x5241, 0x454b, 0x52,
/* 0xd466 FIND */ XT_FIND, 0xd474, 0x4604, 0x4e49, 0x44,
/* 0xd470 NAME? */ XT_NAME_3F, 0xd47e, 0x4e05, 0x4d41, 0x3f45,
/* 0xd47a FIND-NAME */ XT_FIND_2DNAME, 0xd48c, 0x4609, 0x4e49, 0x2d44, 0x414e, 0x454d,
/* 0xd488 SAME? */ XT_SAME_3F, 0xd496, 0x5305, 0x4d41, 0x3f45,
/* 0xd492 NAME>INTERPRET */ XT_NAME_3EINTERPRET, 0xd4aa, 0x4e0e, 0x4d41, 0x3e45, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0xd4a6 WORD */ XT_WORD, 0xd4b4, 0x5704, 0x524f, 0x44,
/* 0xd4b0  */ XT_, 0xd4ba, 0,
/* 0xd4b6 .( */ XT__2E_28, 0xd4c2, 0x2e82, 0x28,
/* 0xd4be CTRL */ XT_CTRL, 0xd4cc, 0x4304, 0x5254, 0x4c,
/* 0xd4c8 [CHAR] */ XT__5BCHAR_5D, 0xd4d8, 0x5b86, 0x4843, 0x5241, 0x5d,
/* 0xd4d4 CHAR */ XT_CHAR, 0xd4e2, 0x4304, 0x4148, 0x52,
/* 0xd4de PARSE-NAME */ XT_PARSE_2DNAME, 0xd4f2, 0x500a, 0x5241, 0x4553, 0x4e2d, 0x4d41, 0x45,
/* 0xd4ee  */ XT_, 0xd4f8, 0,
/* 0xd4f4 skip-till */ XT_skip_2Dtill, 0xd506, 0x7309, 0x696b, 0x2d70, 0x6974, 0x6c6c,
/* 0xd502 xt-skip */ XT_xt_2Dskip, 0xd512, 0x7807, 0x2d74, 0x6b73, 0x7069,
/* 0xd50e isnotspace? */ XT_isnotspace_3F, 0xd522, 0x690b, 0x6e73, 0x746f, 0x7073, 0x6361, 0x3f65,
/* 0xd51e isspace? */ XT_isspace_3F, 0xd530, 0x6908, 0x7373, 0x6170, 0x6563, 0x3f,
/* 0xd52c /STRING */ XT__2FSTRING, 0xd53c, 0x2f07, 0x5453, 0x4952, 0x474e,
/* 0xd538 SOURCE */ XT_SOURCE, 0xd548, 0x5306, 0x554f, 0x4352, 0x45,
/* 0xd544 ['] */ XT__5B_27_5D, 0xd550, 0x5b83, 0x5d27,
/* 0xd54c CR */ XT_CR, 0xd558, 0x4302, 0x52,
/* 0xd554 PACE */ XT_PACE, 0xd562, 0x5004, 0x4341, 0x45,
/* 0xd55e NUF? */ XT_NUF_3F, 0xd56c, 0x4e04, 0x4655, 0x3f,
/* 0xd568 KEY */ XT_KEY, 0xd574, 0x4b03, 0x5945,
/* 0xd570 ?KEY */ XT__3FKEY, 0xd57e, 0x3f04, 0x454b, 0x59,
/* 0xd57a DIGIT? */ XT_DIGIT_3F, 0xd58a, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0xd586 ? */ XT__3F, 0xd590, 0x3f01,
/* 0xd58c . */ XT__2E, 0xd596, 0x2e01,
/* 0xd592 U. */ XT_U_2E, 0xd59e, 0x5502, 0x2e,
/* 0xd59a U.R */ XT_U_2ER, 0xd5a6, 0x5503, 0x522e,
/* 0xd5a2 .R */ XT__2ER, 0xd5ae, 0x2e02, 0x52,
/* 0xd5aa DECIMAL */ XT_DECIMAL, 0xd5ba, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0xd5b6 HEX */ XT_HEX, 0xd5c2, 0x4803, 0x5845,
/* 0xd5be str */ XT_str, 0xd5ca, 0x7303, 0x7274,
/* 0xd5c6 .$ */ XT__2E_24, 0xd5d2, 0x2e02, 0x24,
/* 0xd5ce SPACES */ XT_SPACES, 0xd5de, 0x5306, 0x4150, 0x4543, 0x53,
/* 0xd5da emits */ XT_emits, 0xd5e8, 0x6505, 0x696d, 0x7374,
/* 0xd5e4 SPACE */ XT_SPACE, 0xd5f2, 0x5305, 0x4150, 0x4543,
/* 0xd5ee EMIT */ XT_EMIT, 0xd5fc, 0x4504, 0x494d, 0x54,
/* 0xd5f8 #> */ XT__23_3E, 0xd604, 0x2302, 0x3e,
/* 0xd600 SIGN */ XT_SIGN, 0xd60e, 0x5304, 0x4749, 0x4e,
/* 0xd60a #S */ XT__23S, 0xd616, 0x2302, 0x53,
/* 0xd612 # */ XT__23, 0xd61c, 0x2301,
/* 0xd618 HOLDS */ XT_HOLDS, 0xd626, 0x4805, 0x4c4f, 0x5344,
/* 0xd622 HOLD */ XT_HOLD, 0xd630, 0x4804, 0x4c4f, 0x44,
/* 0xd62c <# */ XT__3C_23, 0xd638, 0x3c02, 0x23,
/* 0xd634 EXTRACT */ XT_EXTRACT, 0xd644, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0xd640 DIGIT */ XT_DIGIT, 0xd64e, 0x4405, 0x4749, 0x5449,
/* 0xd64a PACK$ */ XT_PACK_24, 0xd658, 0x5005, 0x4341, 0x244b,
/* 0xd654 -TRAILING */ XT__2DTRAILING, 0xd666, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0xd662 ERASE */ XT_ERASE, 0xd670, 0x4505, 0x4152, 0x4553,
/* 0xd66c FILL */ XT_FILL, 0xd67a, 0x4604, 0x4c49, 0x4c,
/* 0xd676 MOVE */ XT_MOVE, 0xd684, 0x4d04, 0x564f, 0x45,
/* 0xd680 CMOVE> */ XT_CMOVE_3E, 0xd690, 0x4306, 0x4f4d, 0x4556, 0x3e,
/* 0xd68c CMOVE */ XT_CMOVE, 0xd69a, 0x4305, 0x4f4d, 0x4556,
/* 0xd696 COUNT */ XT_COUNT, 0xd6a4, 0x4305, 0x554f, 0x544e,
/* 0xd6a0 @EXECUTE */ XT__40EXECUTE, 0xd6b2, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0xd6ae TIB */ XT_TIB, 0xd6ba, 0x5403, 0x4249,
/* 0xd6b6 PAD */ XT_PAD, 0xd6c2, 0x5003, 0x4441,
/* 0xd6be vCREATE */ XT_vCREATE, 0xd6ce, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0xd6ca vALIGN */ XT_vALIGN, 0xd6da, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0xd6d6 v, */ XT_v_2C, 0xd6e2, 0x7602, 0x2c,
/* 0xd6de vHERE */ XT_vHERE, 0xd6ec, 0x7605, 0x4548, 0x4552,
/* 0xd6e8 2@ */ XT_2_40, 0xd6f4, 0x3202, 0x40,
/* 0xd6f0 2! */ XT_2_21, 0xd6fc, 0x3202, 0x21,
/* 0xd6f8 -- */ XT__2D_2D, 0xd704, 0x2d02, 0x2d,
/* 0xd700 ++ */ XT__2B_2B, 0xd70c, 0x2b02, 0x2b,
/* 0xd708 +! */ XT__2B_21, 0xd714, 0x2b02, 0x21,
/* 0xd710 PICK */ XT_PICK, 0xd71e, 0x5004, 0x4349, 0x4b,
/* 0xd71a  */ XT_, 0xd724, 0,
/* 0xd720 >CHAR */ XT__3ECHAR, 0xd72e, 0x3e05, 0x4843, 0x5241,
/* 0xd72a DEFER! */ XT_DEFER_21, 0xd73a, 0x4406, 0x4645, 0x5245, 0x21,
/* 0xd736 >BODY! */ XT__3EBODY_21, 0xd746, 0x3e06, 0x4f42, 0x5944, 0x21,
/* 0xd742 DEFER@ */ XT_DEFER_40, 0xd752, 0x4406, 0x4645, 0x5245, 0x40,
/* 0xd74e :NONAME */ XT__3ANONAME, 0xd75e, 0x3a07, 0x4f4e, 0x414e, 0x454d,
/* 0xd75a ($,n) */ XT__28_24_2Cn_29, 0xd768, 0x2805, 0x2c24, 0x296e,
/* 0xd764 2* */ XT_2_2A, 0xd770, 0x3202, 0x2a,
/* 0xd76c CHARS */ XT_CHARS, 0xd77a, 0x4305, 0x4148, 0x5352,
/* 0xd776 CELLS */ XT_CELLS, 0xd784, 0x4305, 0x4c45, 0x534c,
/* 0xd780 CELL- */ XT_CELL_2D, 0xd78e, 0x4305, 0x4c45, 0x2d4c,
/* 0xd78a SM/REM */ XT_SM_2FREM, 0xd79a, 0x5306, 0x2f4d, 0x4552, 0x4d,
/* 0xd796 DABS */ XT_DABS, 0xd7a4, 0x4404, 0x4241, 0x53,
/* 0xd7a0 D0< */ XT_D0_3C, 0xd7ac, 0x4403, 0x3c30,
/* 0xd7a8 * / */ XT__2A_2F, 0xd7b4, 0x2a02, 0x2f,
/* 0xd7b0 * /MOD */ XT__2A_2FMOD, 0xd7be, 0x2a05, 0x4d2f, 0x444f,
/* 0xd7ba M* */ XT_M_2A, 0xd7c6, 0x4d02, 0x2a,
/* 0xd7c2 * */ XT__2A, 0xd7cc, 0x2a01,
/* 0xd7c8 UM* */ XT_UM_2A, 0xd7d4, 0x5503, 0x2a4d,
/* 0xd7d0 / */ XT__2F, 0xd7da, 0x2f01,
/* 0xd7d6 MOD */ XT_MOD, 0xd7e2, 0x4d03, 0x444f,
/* 0xd7de /MOD */ XT__2FMOD, 0xd7ec, 0x2f04, 0x4f4d, 0x44,
/* 0xd7e8 FM/MOD */ XT_FM_2FMOD, 0xd7f8, 0x4606, 0x2f4d, 0x4f4d, 0x44,
/* 0xd7f4 M/MOD */ XT_M_2FMOD, 0xd802, 0x4d05, 0x4d2f, 0x444f,
/* 0xd7fe UM/MOD */ XT_UM_2FMOD, 0xd80e, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0xd80a S>D */ XT_S_3ED, 0xd816, 0x5303, 0x443e,
/* 0xd812 WITHIN */ XT_WITHIN, 0xd822, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0xd81e MIN */ XT_MIN, 0xd82a, 0x4d03, 0x4e49,
/* 0xd826 MAX */ XT_MAX, 0xd832, 0x4d03, 0x5841,
/* 0xd82e > */ XT__3E, 0xd838, 0x3e01,
/* 0xd834 < */ XT__3C, 0xd83e, 0x3c01,
/* 0xd83a ud< */ XT_ud_3C, 0xd846, 0x7503, 0x3c64,
/* 0xd842 U> */ XT_U_3E, 0xd84e, 0x5502, 0x3e,
/* 0xd84a U< */ XT_U_3C, 0xd856, 0x5502, 0x3c,
/* 0xd852 <> */ XT__3C_3E, 0xd85e, 0x3c02, 0x3e,
/* 0xd85a = */ XT__3D, 0xd864, 0x3d01,
/* 0xd860 C, */ XT_C_2C, 0xd86c, 0x4302, 0x2c,
/* 0xd868 CHAR+ */ XT_CHAR_2B, 0xd876, 0x4305, 0x4148, 0x2b52,
/* 0xd872 ABS */ XT_ABS, 0xd87e, 0x4103, 0x5342,
/* 0xd87a ?negate */ XT__3Fnegate, 0xd88a, 0x3f07, 0x656e, 0x6167, 0x6574,
/* 0xd886 1- */ XT_1_2D, 0xd892, 0x3102, 0x2d,
/* 0xd88e - */ XT__2D, 0xd898, 0x2d01,
/* 0xd894 DNEGATE */ XT_DNEGATE, 0xd8a4, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0xd8a0 NEGATE */ XT_NEGATE, 0xd8b0, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0xd8ac 1+ */ XT_1_2B, 0xd8b8, 0x3102, 0x2b,
/* 0xd8b4 INVERT */ XT_INVERT, 0xd8c4, 0x4906, 0x564e, 0x5245, 0x54,
/* 0xd8c0 D+ */ XT_D_2B, 0xd8cc, 0x4402, 0x2b,
/* 0xd8c8 2SWAP */ XT_2SWAP, 0xd8d6, 0x3205, 0x5753, 0x5041,
/* 0xd8d2 2OVER */ XT_2OVER, 0xd8e0, 0x3205, 0x564f, 0x5245,
/* 0xd8dc 2DUP */ XT_2DUP, 0xd8ea, 0x3204, 0x5544, 0x50,
/* 0xd8e6 -ROT */ XT__2DROT, 0xd8f4, 0x2d04, 0x4f52, 0x54,
/* 0xd8f0 ?test\ */ XT__3Ftest_5C, 0xd900, 0x3f86, 0x6574, 0x7473, 0x5c,
/* 0xd8fc ?safe\ */ XT__3Fsafe_5C, 0xd90c, 0x3f86, 0x6173, 0x6566, 0x5c,
/* 0xd908 ?\ */ XT__3F_5C, 0xd914, 0x3f82, 0x5c,
/* 0xd910 D0= */ XT_D0_3D, 0xd91c, 0x4403, 0x3d30,
/* 0xd918 0<> */ XT_0_3C_3E, 0xd924, 0x3003, 0x3e3c,
/* 0xd920 0= */ XT_0_3D, 0xd92c, 0x3002, 0x3d,
/* 0xd928 ENDCASE */ XT_ENDCASE, 0xd938, 0x4587, 0x444e, 0x4143, 0x4553,
/* 0xd934 ENDOF */ XT_ENDOF, 0xd942, 0x4585, 0x444e, 0x464f,
/* 0xd93e OF */ XT_OF, 0xd94a, 0x4f82, 0x46,
/* 0xd946 CASE */ XT_CASE, 0xd954, 0x4384, 0x5341, 0x45,
/* 0xd950 >RESOLVETHREAD */ XT__3ERESOLVETHREAD, 0xd968, 0x3e0e, 0x4552, 0x4f53, 0x564c, 0x5445, 0x5248, 0x4145, 0x44,
/* 0xd964 >MARKTHREAD */ XT__3EMARKTHREAD, 0xd978, 0x3e0b, 0x414d, 0x4b52, 0x4854, 0x4552, 0x4441,
/* 0xd974 >MARKSTART */ XT__3EMARKSTART, 0xd988, 0x3e0a, 0x414d, 0x4b52, 0x5453, 0x5241, 0x54,
/* 0xd984 >RESOLVES */ XT__3ERESOLVES, 0xd996, 0x3e09, 0x4552, 0x4f53, 0x564c, 0x5345,
/* 0xd992 ?DUP */ XT__3FDUP, 0xd9a0, 0x3f04, 0x5544, 0x50,
/* 0xd99c WHILE */ XT_WHILE, 0xd9aa, 0x5785, 0x4948, 0x454c,
/* 0xd9a6 WHEN */ XT_WHEN, 0xd9b4, 0x5784, 0x4548, 0x4e,
/* 0xd9b0 ELSE */ XT_ELSE, 0xd9be, 0x4584, 0x534c, 0x45,
/* 0xd9ba AFT */ XT_AFT, 0xd9c6, 0x4183, 0x5446,
/* 0xd9c2 THEN */ XT_THEN, 0xd9d0, 0x5484, 0x4548, 0x4e,
/* 0xd9cc REPEAT */ XT_REPEAT, 0xd9dc, 0x5286, 0x5045, 0x4145, 0x54,
/* 0xd9d8 AHEAD */ XT_AHEAD, 0xd9e6, 0x4185, 0x4548, 0x4441,
/* 0xd9e2 IF */ XT_IF, 0xd9ee, 0x4982, 0x46,
/* 0xd9ea AGAIN */ XT_AGAIN, 0xd9f8, 0x4185, 0x4147, 0x4e49,
/* 0xd9f4 UNTIL */ XT_UNTIL, 0xda02, 0x5585, 0x544e, 0x4c49,
/* 0xd9fe NEXT */ XT_NEXT, 0xda0c, 0x4e84, 0x5845, 0x54,
/* 0xda08 BEGIN */ XT_BEGIN, 0xda16, 0x4285, 0x4745, 0x4e49,
/* 0xda12 FOR */ XT_FOR, 0xda1e, 0x4683, 0x524f,
/* 0xda1a >RESOLVE */ XT__3ERESOLVE, 0xda2c, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda28 >MARK */ XT__3EMARK, 0xda36, 0x3e05, 0x414d, 0x4b52,
/* 0xda32 <RESOLVE */ XT__3CRESOLVE, 0xda44, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda40 <MARK */ XT__3CMARK, 0xda4e, 0x3c05, 0x414d, 0x4b52,
/* 0xda4a CREATE */ XT_CREATE, 0xda5a, 0x4306, 0x4552, 0x5441, 0x45,
/* 0xda56 create */ XT_create, 0xda66, 0x6306, 0x6572, 0x7461, 0x65,
/* 0xda62 LITERAL */ XT_LITERAL, 0xda72, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0xda6e COMPILE */ XT_COMPILE, 0xda7e, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0xda7a [COMPILE] */ XT__5BCOMPILE_5D, 0xda8c, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0xda88 COMPILE, */ XT_COMPILE_2C, 0xda9a, 0x4308, 0x4d4f, 0x4950, 0x454c, 0x2c,
/* 0xda96 , */ XT__2C, 0xdaa0, 0x2c01,
/* 0xda9c CELL+ */ XT_CELL_2B, 0xdaaa, 0x4305, 0x4c45, 0x2b4c,
/* 0xdaa6 + */ XT__2B, 0xdab0, 0x2b01,
/* 0xdaac HERE */ XT_HERE, 0xdaba, 0x4804, 0x5245, 0x45,
/* 0xdab6 TUCK */ XT_TUCK, 0xdac4, 0x5404, 0x4355, 0x4b,
/* 0xdac0 NIP */ XT_NIP, 0xdacc, 0x4e03, 0x5049,
/* 0xdac8 \ */ XT__5C, 0xdad2, 0x5c81,
/* 0xdace IMMEDIATE */ XT_IMMEDIATE, 0xdae0, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0xdadc COMPILE-ONLY */ XT_COMPILE_2DONLY, 0xdaf2, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0xdaee setHeaderBits */ XT_setHeaderBits, 0xdb04, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0xdb00 2DROP */ XT_2DROP, 0xdb0e, 0x3205, 0x5244, 0x504f,
/* 0xdb0a testDepth */ XT_testDepth, 0xdb1c, 0x7409, 0x7365, 0x4474, 0x7065, 0x6874,
/* 0xdb18 testFlags */ XT_testFlags, 0xdb2a, 0x7409, 0x7365, 0x4674, 0x616c, 0x7367,
/* 0xdb26 source-id */ XT_source_2Did, 0xdb38, 0x7309, 0x756f, 0x6372, 0x2d65, 0x6469,
/* 0xdb34 VP */ XT_VP, 0xdb40, 0x5602, 0x50,
/* 0xdb3c LAST */ XT_LAST, 0xdb4a, 0x4c04, 0x5341, 0x54,
/* 0xdb46 NP */ XT_NP, 0xdb52, 0x4e02, 0x50,
/* 0xdb4e CP */ XT_CP, 0xdb5a, 0x4302, 0x50,
/* 0xdb56 CURRENT */ XT_CURRENT, 0xdb66, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0xdb62 CONTEXT */ XT_CONTEXT, 0xdb72, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0xdb6e HANDLER */ XT_HANDLER, 0xdb7e, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0xdb7a HLD */ XT_HLD, 0xdb86, 0x4803, 0x444c,
/* 0xdb82 SPARE2 */ XT_SPARE2, 0xdb92, 0x5306, 0x4150, 0x4552, 0x32,
/* 0xdb8e STATE */ XT_STATE, 0xdb9c, 0x5305, 0x4154, 0x4554,
/* 0xdb98 CSP */ XT_CSP, 0xdba4, 0x4303, 0x5053,
/* 0xdba0 #TIB */ XT__23TIB, 0xdbae, 0x2304, 0x4954, 0x42,
/* 0xdbaa >IN */ XT__3EIN, 0xdbb6, 0x3e03, 0x4e49,
/* 0xdbb2 SPAN */ XT_SPAN, 0xdbc0, 0x5304, 0x4150, 0x4e,
/* 0xdbbc temp */ XT_temp, 0xdbca, 0x7404, 0x6d65, 0x70,
/* 0xdbc6 BASE */ XT_BASE, 0xdbd4, 0x4204, 0x5341, 0x45,
/* 0xdbd0 'PROMPT */ XT__27PROMPT, 0xdbe0, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0xdbdc 'ECHO */ XT__27ECHO, 0xdbea, 0x2705, 0x4345, 0x4f48,
/* 0xdbe6 'TAP */ XT__27TAP, 0xdbf4, 0x2704, 0x4154, 0x50,
/* 0xdbf0 SPARE */ XT_SPARE, 0xdbfe, 0x5305, 0x4150, 0x4552,
/* 0xdbfa 'EMIT */ XT__27EMIT, 0xdc08, 0x2705, 0x4d45, 0x5449,
/* 0xdc04 '?KEY */ XT__27_3FKEY, 0xdc12, 0x2705, 0x4b3f, 0x5945,
/* 0xdc0e RP0 */ XT_RP0, 0xdc1a, 0x5203, 0x3050,
/* 0xdc16 SP0 */ XT_SP0, 0xdc22, 0x5303, 0x3050,
/* 0xdc1e _USER */ XT__5FUSER, 0xdc2c, 0x5f05, 0x5355, 0x5245,
/* 0xdc28 -> */ XT__2D_3E, 0xdc34, 0x2d02, 0x3e,
/* 0xdc30 }T */ XT__7DT, 0xdc3c, 0x7d02, 0x54,
/* 0xdc38 DEPTH */ XT_DEPTH, 0xdc46, 0x4405, 0x5045, 0x4854,
/* 0xdc42 T{ */ XT_T_7B, 0xdc4e, 0x5402, 0x7b,
/* 0xdc4a of */ XT_of, 0xdc56, 0x6f02, 0x66,
/* 0xdc52 DEFER */ XT_DEFER, 0xdc60, 0x4405, 0x4645, 0x5245,
/* 0xdc5c >BODY */ XT__3EBODY, 0xdc6a, 0x3e05, 0x4f42, 0x5944,
/* 0xdc66 ALIGN */ XT_ALIGN, 0xdc74, 0x4105, 0x494c, 0x4e47,
/* 0xdc70 immediate? */ XT_immediate_3F, 0xdc84, 0x690a, 0x6d6d, 0x6465, 0x6169, 0x6574, 0x3f,
/* 0xdc80 2RDrop */ XT_2RDrop, 0xdc90, 0x3206, 0x4452, 0x6f72, 0x70,
/* 0xdc8c RDrop */ XT_RDrop, 0xdc9a, 0x5205, 0x7244, 0x706f,
/* 0xdc96 leave */ XT_leave, 0xdca4, 0x6c05, 0x6165, 0x6576,
/* 0xdca0 I */ XT_I, 0xdcaa, 0x4901,
/* 0xdca6 loop */ XT_loop, 0xdcb4, 0x6c04, 0x6f6f, 0x70,
/* 0xdcb0 TYPE */ XT_TYPE, 0xdcbe, 0x5404, 0x5059, 0x45,
/* 0xdcba stringBuffer */ XT_stringBuffer, 0xdcd0, 0x730c, 0x7274, 0x6e69, 0x4267, 0x6675, 0x6566, 0x72,
/* 0xdccc Fbreak */ XT_Fbreak, 0xdcdc, 0x4606, 0x7262, 0x6165, 0x6b,
/* 0xdcd8 debugNA */ XT_debugNA, 0xdce8, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0xdce4 ' */ XT__27, 0xdcee, 0x2701,
/* 0xdcea ; */ XT__3B, 0xdcf4, 0x3b81,
/* 0xdcf0 : */ XT__3A, 0xdcfa, 0x3a01,
/* 0xdcf6 ] */ XT__5D, 0xdd00, 0x5d01,
/* 0xdcfc [ */ XT__5B, 0xdd06, 0x5b81,
/* 0xdd02 $INTERPRET */ XT__24INTERPRET, 0xdd16, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0xdd12 $COMPILE */ XT__24COMPILE, 0xdd24, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0xdd20 NUMBER? */ XT_NUMBER_3F, 0xdd30, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0xdd2c TOKEN */ XT_TOKEN, 0xdd3a, 0x5405, 0x4b4f, 0x4e45,
/* 0xdd36 ( */ XT__28, 0xdd40, 0x2881,
/* 0xdd3c PARSE */ XT_PARSE, 0xdd4a, 0x5005, 0x5241, 0x4553,
/* 0xdd46 userAreaSave */ XT_userAreaSave, 0xdd5c, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0xdd58 userAreaInit */ XT_userAreaInit, 0xdd6e, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0xdd6a 2/ */ XT_2_2F, 0xdd76, 0x3202, 0x2f,
/* 0xdd72 LSHIFT */ XT_LSHIFT, 0xdd82, 0x4c06, 0x4853, 0x4649, 0x54,
/* 0xdd7e RSHIFT */ XT_RSHIFT, 0xdd8e, 0x5206, 0x4853, 0x4649, 0x54,
/* 0xdd8a UM+ */ XT_UM_2B, 0xdd96, 0x5503, 0x2b4d,
/* 0xdd92 XOR */ XT_XOR, 0xdd9e, 0x5803, 0x524f,
/* 0xdd9a OR */ XT_OR, 0xdda6, 0x4f02, 0x52,
/* 0xdda2 AND */ XT_AND, 0xddae, 0x4103, 0x444e,
/* 0xddaa 0< */ XT_0_3C, 0xddb6, 0x3002, 0x3c,
/* 0xddb2 ROT */ XT_ROT, 0xddbe, 0x5203, 0x544f,
/* 0xddba ROLL */ XT_ROLL, 0xddc8, 0x5204, 0x4c4f, 0x4c,
/* 0xddc4 OVER */ XT_OVER, 0xddd2, 0x4f04, 0x4556, 0x52,
/* 0xddce SWAP */ XT_SWAP, 0xdddc, 0x5304, 0x4157, 0x50,
/* 0xddd8 DUP */ XT_DUP, 0xdde4, 0x4403, 0x5055,
/* 0xdde0 DROP */ XT_DROP, 0xddee, 0x4404, 0x4f52, 0x50,
/* 0xddea SP! */ XT_SP_21, 0xddf6, 0x5303, 0x2150,
/* 0xddf2 SP@ */ XT_SP_40, 0xddfe, 0x5303, 0x4050,
/* 0xddfa 2>R */ XT_2_3ER, 0xde06, 0x3203, 0x523e,
/* 0xde02 2R@ */ XT_2R_40, 0xde0e, 0x3203, 0x4052,
/* 0xde0a 2R> */ XT_2R_3E, 0xde16, 0x3203, 0x3e52,
/* 0xde12 >R */ XT__3ER, 0xde1e, 0x3e02, 0x52,
/* 0xde1a R@ */ XT_R_40, 0xde26, 0x5202, 0x40,
/* 0xde22 R> */ XT_R_3E, 0xde2e, 0x5202, 0x3e,
/* 0xde2a RP! */ XT_RP_21, 0xde36, 0x5203, 0x2150,
/* 0xde32 RP@ */ XT_RP_40, 0xde3e, 0x5203, 0x4050,
/* 0xde3a C! */ XT_C_21, 0xde46, 0x4302, 0x21,
/* 0xde42 C@ */ XT_C_40, 0xde4e, 0x4302, 0x40,
/* 0xde4a @ */ XT__40, 0xde54, 0x4001,
/* 0xde50 ! */ XT__21, 0xde5a, 0x2101,
/* 0xde56 branch */ XT_branch, 0xde66, 0x6206, 0x6172, 0x636e, 0x68,
/* 0xde62 ?branch */ XT__3Fbranch, 0xde72, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0xde6e next */ XT_next, 0xde7c, 0x6e04, 0x7865, 0x74,
/* 0xde78 DOES> */ XT_DOES_3E, 0xde86, 0x4405, 0x454f, 0x3e53,
/* 0xde82 doLit */ XT_doLit, 0xde90, 0x6405, 0x4c6f, 0x7469,
/* 0xde8c !IO */ XT__21IO, 0xde98, 0x2103, 0x4f49,
/* 0xde94 TX! */ XT_TX_21, 0xdea0, 0x5403, 0x2158,
/* 0xde9c ?RX */ XT__3FRX, 0xdea8, 0x3f03, 0x5852,
/* 0xdea4 EXECUTE */ XT_EXECUTE, 0xdeb4, 0x4507, 0x4558, 0x5543, 0x4554,
/* 0xdeb0 EXIT */ XT_EXIT, 0xdebe, 0x4504, 0x4958, 0x54,
/* 0xdeba BYE */ XT_BYE, 0xdec6, 0x4203, 0x4559,
/* 0xdec2 ms */ XT_ms, 0xdece, 0x6d02, 0x73,
/* 0xdeca $,n */ XT__24_2Cn, 0xded6, 0x2403, 0x6e2c,
/* 0xded2 OVERT */ XT_OVERT, 0xdee0, 0x4f05, 0x4556, 0x5452,
/* 0xdedc FIND-NAME-IN */ XT_FIND_2DNAME_2DIN, 0xdef2, 0x460c, 0x4e49, 0x2d44, 0x414e, 0x454d, 0x492d, 0x4e,
/* 0xdeee ALIGNED */ XT_ALIGNED, 0xdefe, 0x4107, 0x494c, 0x4e47, 0x4445,
/* 0xdefa tokenValue */ XT_tokenValue, 0xdf0e, 0x740a, 0x6b6f, 0x6e65, 0x6156, 0x756c, 0x65,
/* 0xdf0a tokenDefer */ XT_tokenDefer, 0xdf1e, 0x740a, 0x6b6f, 0x6e65, 0x6544, 0x6566, 0x72,
/* 0xdf1a tokenCreate */ XT_tokenCreate, 0xdf2e, 0x740b, 0x6b6f, 0x6e65, 0x7243, 0x6165, 0x6574,
/* 0xdf2a tokenVar */ XT_tokenVar, 0xdf3c, 0x7408, 0x6b6f, 0x6e65, 0x6156, 0x72,
/* 0xdf38 tokenUser */ XT_tokenUser, 0xdf4a, 0x7409, 0x6b6f, 0x6e65, 0x7355, 0x7265,
/* 0xdf46 tokenDoList */ XT_tokenDoList, 0xdf5a, 0x740b, 0x6b6f, 0x6e65, 0x6f44, 0x694c, 0x7473,
/* 0xdf56 tokenNextVal */ XT_tokenNextVal, 0xdf6c, 0x740c, 0x6b6f, 0x6e65, 0x654e, 0x7478, 0x6156, 0x6c,
/* 0xdf68 tokenVocabulary */ XT_tokenVocabulary, 0xdf80, 0x740f, 0x6b6f, 0x6e65, 0x6f56, 0x6163, 0x7562, 0x616c, 0x7972,
/* 0xdf7c BL */ XT_BL, 0xdf88, 0x4202, 0x4c,
/* 0xdf84 FALSE */ XT_FALSE, 0xdf92, 0x4605, 0x4c41, 0x4553,
/* 0xdf8e TRUE */ XT_TRUE, 0xdf9c, 0x5404, 0x5552, 0x45,
/* 0xdf98 BYTEMASK */ XT_BYTEMASK, 0xdfaa, 0x4208, 0x5459, 0x4d45, 0x5341, 0x4b,
/* 0xdfa6 IMED */ XT_IMED, 0xdfb4, 0x4904, 0x454d, 0x44,
/* 0xdfb0 COMP */ XT_COMP, 0xdfbe, 0x4304, 0x4d4f, 0x50,
/* 0xdfba rqFiles */ XT_rqFiles, 0xdfca, 0x7207, 0x4671, 0x6c69, 0x7365,
/* 0xdfc6 TIB0 */ XT_TIB0, 0xdfd4, 0x5404, 0x4249, 0x30,
/* 0xdfd0 CELLMASK */ XT_CELLMASK, 0xdfe2, 0x4308, 0x4c45, 0x4d4c, 0x5341, 0x4b,
/* 0xdfde CELLbits */ XT_CELLbits, 0xdff0, 0x4308, 0x4c45, 0x624c, 0x7469, 0x73,
/* 0xdfec CELLL */ XT_CELLL, 0xdffa, 0x4305, 0x4c45, 0x4c4c,
/* 0xdff6 FORTH */ XT_FORTH, 0, 0x4605, 0x524f, 0x4854,
};
// === End of Arduino source from dictionary === 
