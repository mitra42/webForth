#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x9b82 /* WARM*/
#define XT_COLD 0x9b6a /* COLD*/
#define XT__27BOOT 0x9b64 /* 'BOOT*/
#define XT_EMPTY 0x9b54 /* EMPTY*/
#define XT_hi 0x9b4c /* hi*/
#define XT_version 0x9b0a /* version*/
#define XT_VER 0x9b06 /* VER*/
#define XT_SEE 0x9a80 /* SEE*/
#define XT__3ENAME 0x9a44 /* >NAME*/
#define XT_WORDS 0x9a22 /* WORDS*/
#define XT__2EID 0x9a02 /* .ID*/
#define XT__3FCSP 0x99e8 /* ?CSP*/
#define XT__21CSP 0x99de /* !CSP*/
#define XT__2EFREE 0x99d2 /* .FREE*/
#define XT__2EBASE 0x99c0 /* .BASE*/
#define XT_UNUSED 0x99b2 /* UNUSED*/
#define XT__2ES 0x9992 /* .S*/
#define XT_DUMP 0x994e /* DUMP*/
#define XT_dm_2B 0x992a /* dm+*/
#define XT_EVALUATE 0x9910 /* EVALUATE*/
#define XT_quit1 0x98fc /* quit1*/
#define XT_QUIT 0x98ca /* QUIT*/
#define XT_quitError 0x989a /* quitError*/
#define XT_PRESET 0x9876 /* PRESET*/
#define XT_que 0x986e /* que*/
#define XT_QUERY 0x982a /* QUERY*/
#define XT_REFILL 0x97f8 /* REFILL*/
#define XT_READ_2DLINE 0x97f4 /* READ-LINE*/
#define XT_sourcePop 0x97e8 /* sourcePop*/
#define XT_RESTORE_2DINPUT 0x97be /* RESTORE-INPUT*/
#define XT_sourcePush 0x97b4 /* sourcePush*/
#define XT_SAVE_2DINPUT 0x97a4 /* SAVE-INPUT*/
#define XT_unreadFile 0x97a0 /* unreadFile*/
#define XT_0_3E 0x9790 /* 0>*/
#define XT_sourceStack 0x9788 /* sourceStack*/
#define XT_SOURCE_2DID 0x9780 /* SOURCE-ID*/
#define XT_sempty 0x9772 /* sempty*/
#define XT_spops 0x974e /* spops*/
#define XT_spushes 0x972c /* spushes*/
#define XT_spush 0x9714 /* spush*/
#define XT_spop 0x96fe /* spop*/
#define XT_stack 0x96dc /* stack*/
#define XT_ACCEPT 0x96a4 /* ACCEPT*/
#define XT__28charbase_29 0x95be /* (charbase)*/
#define XT__3ENUMBER 0x957e /* >NUMBER*/
#define XT_accumulate 0x9560 /* accumulate*/
#define XT_J_2DMAX 0x9550 /* J-MAX*/
#define XT_J 0x9540 /* J*/
#define XT_I_2DMAX 0x9530 /* I-MAX*/
#define XT__2BLOOP 0x9526 /* +LOOP*/
#define XT_LOOP 0x951c /* LOOP*/
#define XT_some_2Dloop 0x94f0 /* some-loop*/
#define XT__3FDO 0x94d4 /* ?DO*/
#define XT_DO 0x94be /* DO*/
#define XT_UNLOOP 0x94b6 /* UNLOOP*/
#define XT_LEAVE 0x94ac /* LEAVE*/
#define XT_leave_2C 0x949c /* leave,*/
#define XT__28_2Bloop_29 0x945e /* (+loop)*/
#define XT__28loop_29 0x944a /* (loop)*/
#define XT__28_3Fdo_29 0x9438 /* (?do)*/
#define XT_leave_2Dptr 0x9432 /* leave-ptr*/
#define XT_CONSTANT 0x9422 /* CONSTANT*/
#define XT_VARIABLE 0x9416 /* VARIABLE*/
#define XT_TO 0x9410 /* TO*/
#define XT_VALUE 0x93f4 /* VALUE*/
#define XT_ 0x93bc /* */
#define XT_ 0x9390 /* */
#define XT_EVAL 0x9366 /* EVAL*/
#define XT_ 0x933a /* */
#define XT_ 0x931e /* */
#define XT__3FUNIQUE 0x9302 /* ?UNIQUE*/
#define XT_RECURSE 0x92f6 /* RECURSE*/
#define XT_ACTION_2DOF 0x92dc /* ACTION-OF*/
#define XT_IS 0x92d6 /* IS*/
#define XT__27_3EBODY_21 0x92bc /* '>BODY!*/
#define XT_BUFFER_3A 0x92b4 /* BUFFER:*/
#define XT_vALLOT 0x929e /* vALLOT*/
#define XT_ALLOT 0x9296 /* ALLOT*/
#define XT_ 0x9286 /* */
#define XT_CONSOLE 0x9278 /* CONSOLE*/
#define XT_I_2FO 0x9270 /* I/O*/
#define XT_HAND 0x925e /* HAND*/
#define XT_FILE 0x924c /* FILE*/
#define XT_XIO 0x923c /* XIO*/
#define XT_ 0x9232 /* */
#define XT__3FSTACK 0x921e /* ?STACK*/
#define XT__2EOK 0x9208 /* .OK*/
#define XT_ 0x91d6 /* */
#define XT_POSTPONE 0x91aa /* POSTPONE*/
#define XT_ABORT_22 0x91a0 /* ABORT"*/
#define XT_abort_22 0x9190 /* abort"*/
#define XT_ABORT 0x9188 /* ABORT*/
#define XT_NULL_24 0x9182 /* NULL$*/
#define XT_S_5C_22 0x9140 /* S\"*/
#define XT_pack_5C_24 0x90f8 /* pack\$*/
#define XT_cmove_5C 0x8f86 /* cmove\*/
#define XT_c_2B_21 0x8f7c /* c+!*/
#define XT_bu_2B_40 0x8f6e /* bu+@*/
#define XT_S_22 0x8f4c /* S"*/
#define XT__2E_22 0x8f42 /* ."*/
#define XT_C_22 0x8f3c /* C"*/
#define XT__24_22 0x8f32 /* $"*/
#define XT_S_22_7C 0x8f2a /* S"|*/
#define XT__2E_22_7C 0x8f22 /* ."|*/
#define XT__24_22_7C 0x8f1c /* $"|*/
#define XT__24_2C_22 0x8f08 /* $,"*/
#define XT_do_24 0x8ef2 /* do$*/
#define XT_kTAP 0x8eba /* kTAP*/
#define XT_skipToCRLF 0x8e92 /* skipToCRLF*/
#define XT_skipCRLF 0x8e6c /* skipCRLF*/
#define XT_crlf_3F 0x8e56 /* crlf?*/
#define XT_TAP 0x8e46 /* TAP*/
#define XT__5EH 0x8e1a /* ^H*/
#define XT_THROW 0x8df8 /* THROW*/
#define XT_CATCH 0x8dd4 /* CATCH*/
#define XT_MARKER 0x8d68 /* MARKER*/
#define XT_FIND 0x8d36 /* FIND*/
#define XT_NAME_3F 0x8d18 /* NAME?*/
#define XT_FIND_2DNAME 0x8cd6 /* FIND-NAME*/
#define XT_SAME_3F 0x8ca4 /* SAME?*/
#define XT_NAME_3EINTERPRET 0x8c96 /* NAME>INTERPRET*/
#define XT_WORD 0x8c8c /* WORD*/
#define XT_ 0x8c74 /* */
#define XT__2E_28 0x8c68 /* .(*/
#define XT_CTRL 0x8c5c /* CTRL*/
#define XT__5BCHAR_5D 0x8c54 /* [CHAR]*/
#define XT_CHAR 0x8c4a /* CHAR*/
#define XT_PARSE_2DNAME 0x8c42 /* PARSE-NAME*/
#define XT_ 0x8bea /* */
#define XT_skip_2Dtill 0x8bc2 /* skip-till*/
#define XT_xt_2Dskip 0x8b9c /* xt-skip*/
#define XT_isnotspace_3F 0x8b94 /* isnotspace?*/
#define XT_isspace_3F 0x8b8a /* isspace?*/
#define XT__2FSTRING 0x8b7c /* /STRING*/
#define XT_SOURCE 0x8b72 /* SOURCE*/
#define XT__5B_27_5D 0x8b6a /* [']*/
#define XT_CR 0x8b5a /* CR*/
#define XT_PACE 0x8b50 /* PACE*/
#define XT_NUF_3F 0x8b3a /* NUF?*/
#define XT_KEY 0x8b24 /* KEY*/
#define XT__3FKEY 0x8b1c /* ?KEY*/
#define XT_DIGIT_3F 0x8adc /* DIGIT?*/
#define XT__3F 0x8ad4 /* ?*/
#define XT__2E 0x8ab8 /* .*/
#define XT_U_2E 0x8aa6 /* U.*/
#define XT_U_2ER 0x8a8c /* U.R*/
#define XT__2ER 0x8a7a /* .R*/
#define XT_DECIMAL 0x8a6e /* DECIMAL*/
#define XT_HEX 0x8a62 /* HEX*/
#define XT_str 0x8a4a /* str*/
#define XT__2E_24 0x8a42 /* .$*/
#define XT_SPACES 0x8a3a /* SPACES*/
#define XT_emits 0x8a1e /* emits*/
#define XT_SPACE 0x8a16 /* SPACE*/
#define XT_EMIT 0x8a0e /* EMIT*/
#define XT__23_3E 0x89fe /* #>*/
#define XT_SIGN 0x89ee /* SIGN*/
#define XT__23S 0x89dc /* #S*/
#define XT__23 0x89d0 /* #*/
#define XT_HOLDS 0x89b6 /* HOLDS*/
#define XT_HOLD 0x89a4 /* HOLD*/
#define XT__3C_23 0x899a /* <#*/
#define XT_EXTRACT 0x897e /* EXTRACT*/
#define XT_DIGIT 0x8964 /* DIGIT*/
#define XT_PACK_24 0x8932 /* PACK$*/
#define XT__2DTRAILING 0x890a /* -TRAILING*/
#define XT_ERASE 0x8900 /* ERASE*/
#define XT_FILL 0x88e6 /* FILL*/
#define XT_MOVE 0x88cc /* MOVE*/
#define XT_CMOVE_3E 0x8898 /* CMOVE>*/
#define XT_CMOVE 0x8878 /* CMOVE*/
#define XT_COUNT 0x886c /* COUNT*/
#define XT__40EXECUTE 0x885e /* @EXECUTE*/
#define XT_TIB 0x8854 /* TIB*/
#define XT_PAD 0x8848 /* PAD*/
#define XT_vCREATE 0x882c /* vCREATE*/
#define XT_vALIGN 0x881e /* vALIGN*/
#define XT_v_2C 0x87fe /* v,*/
#define XT_vHERE 0x87ec /* vHERE*/
#define XT_2_40 0x87de /* 2@*/
#define XT_2_21 0x87d0 /* 2!*/
#define XT__2D_2D 0x87c4 /* --*/
#define XT__2B_2B 0x87b8 /* ++*/
#define XT__2B_21 0x87a8 /* +!*/
#define XT_PICK 0x879a /* PICK*/
#define XT_ 0x8788 /* */
#define XT__3ECHAR 0x876a /* >CHAR*/
#define XT_DEFER_21 0x8764 /* DEFER!*/
#define XT__3EBODY_21 0x875c /* >BODY!*/
#define XT_DEFER_40 0x8754 /* DEFER@*/
#define XT__3ANONAME 0x8732 /* :NONAME*/
#define XT__28_24_2Cn_29 0x8706 /* ($,n)*/
#define XT_2_2A 0x86fc /* 2**/
#define XT_CHARS 0x86f8 /* CHARS*/
#define XT_CELLS 0x86f0 /* CELLS*/
#define XT_CELL_2D 0x86e8 /* CELL-*/
#define XT_SM_2FREM 0x86c4 /* SM/REM*/
#define XT_DABS 0x86b6 /* DABS*/
#define XT_D0_3C 0x86ae /* D0<*/
#define XT__2A_2F 0x86a6 /* * /*/
#define XT__2A_2FMOD 0x869a /* * /MOD*/
#define XT_M_2A 0x867e /* M**/
#define XT__2A 0x8676 /* **/
#define XT_UM_2A 0x863c /* UM**/
#define XT__2F 0x8634 /* /*/
#define XT_MOD 0x862c /* MOD*/
#define XT__2FMOD 0x8620 /* /MOD*/
#define XT_FM_2FMOD 0x861a /* FM/MOD*/
#define XT_M_2FMOD 0x85e4 /* M/MOD*/
#define XT_UM_2FMOD 0x8584 /* UM/MOD*/
#define XT_S_3ED 0x857c /* S>D*/
#define XT_WITHIN 0x856c /* WITHIN*/
#define XT_MIN 0x855a /* MIN*/
#define XT_MAX 0x854a /* MAX*/
#define XT__3E 0x8542 /* >*/
#define XT__3C 0x852a /* <*/
#define XT_ud_3C 0x8512 /* ud<*/
#define XT_U_3E 0x850a /* U>*/
#define XT_U_3C 0x84f2 /* U<*/
#define XT__3C_3E 0x84e2 /* <>*/
#define XT__3D 0x84d2 /* =*/
#define XT_C_2C 0x84c2 /* C,*/
#define XT_CHAR_2B 0x84bc /* CHAR+*/
#define XT_ABS 0x84b4 /* ABS*/
#define XT__3Fnegate 0x84a8 /* ?negate*/
#define XT_1_2D 0x849e /* 1-*/
#define XT__2D 0x8496 /* -*/
#define XT_DNEGATE 0x8482 /* DNEGATE*/
#define XT_NEGATE 0x847a /* NEGATE*/
#define XT_1_2B 0x8470 /* 1+*/
#define XT_INVERT 0x8466 /* INVERT*/
#define XT_D_2B 0x8452 /* D+*/
#define XT_2SWAP 0x8446 /* 2SWAP*/
#define XT_2OVER 0x8434 /* 2OVER*/
#define XT_2DUP 0x842c /* 2DUP*/
#define XT__2DROT 0x8420 /* -ROT*/
#define XT__3Ftest_5C 0x8410 /* ?test\*/
#define XT__3Fsafe_5C 0x8400 /* ?safe\*/
#define XT__3F_5C 0x83f4 /* ?\*/
#define XT_D0_3D 0x83ec /* D0=*/
#define XT_0_3C_3E 0x83e4 /* 0<>*/
#define XT_0_3D 0x83d4 /* 0=*/
#define XT_ENDCASE 0x83ca /* ENDCASE*/
#define XT_ENDOF 0x83ba /* ENDOF*/
#define XT_OF 0x83b0 /* OF*/
#define XT_CASE 0x83aa /* CASE*/
#define XT__3ERESOLVETHREAD 0x8394 /* >RESOLVETHREAD*/
#define XT__3EMARKTHREAD 0x838a /* >MARKTHREAD*/
#define XT__3EMARKSTART 0x8382 /* >MARKSTART*/
#define XT__3ERESOLVES 0x8372 /* >RESOLVES*/
#define XT__3FDUP 0x8366 /* ?DUP*/
#define XT_WHILE 0x835e /* WHILE*/
#define XT_WHEN 0x8356 /* WHEN*/
#define XT_ELSE 0x834c /* ELSE*/
#define XT_AFT 0x8340 /* AFT*/
#define XT_THEN 0x833a /* THEN*/
#define XT_REPEAT 0x8332 /* REPEAT*/
#define XT_AHEAD 0x8328 /* AHEAD*/
#define XT_IF 0x831e /* IF*/
#define XT_AGAIN 0x8314 /* AGAIN*/
#define XT_UNTIL 0x830a /* UNTIL*/
#define XT_NEXT 0x8300 /* NEXT*/
#define XT_BEGIN 0x82fa /* BEGIN*/
#define XT_FOR 0x82f0 /* FOR*/
#define XT__3ERESOLVE 0x82e6 /* >RESOLVE*/
#define XT__3EMARK 0x82da /* >MARK*/
#define XT__3CRESOLVE 0x82d4 /* <RESOLVE*/
#define XT__3CMARK 0x82ce /* <MARK*/
#define XT_CREATE 0x82c6 /* CREATE*/
#define XT_create 0x82b4 /* create*/
#define XT_LITERAL 0x82aa /* LITERAL*/
#define XT_COMPILE 0x829a /* COMPILE*/
#define XT__5BCOMPILE_5D 0x8292 /* [COMPILE]*/
#define XT_COMPILE_2C 0x828c /* COMPILE,*/
#define XT__2C 0x827a /* ,*/
#define XT_CELL_2B 0x8272 /* CELL+*/
#define XT__2B 0x826a /* +*/
#define XT_HERE 0x8262 /* HERE*/
#define XT_TUCK 0x825a /* TUCK*/
#define XT_NIP 0x8252 /* NIP*/
#define XT__5C 0x8246 /* \*/
#define XT_IMMEDIATE 0x823e /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x8236 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x8224 /* setHeaderBits*/
#define XT_2DROP 0x821c /* 2DROP*/
#define XT_testDepth 0x8218 /* testDepth*/
#define XT_testFlags 0x8214 /* testFlags*/
#define XT_source_2Did 0x8210 /* source-id*/
#define XT_VP 0x820c /* VP*/
#define XT_LAST 0x8208 /* LAST*/
#define XT_NP 0x8204 /* NP*/
#define XT_CP 0x8200 /* CP*/
#define XT_CURRENT 0x81fc /* CURRENT*/
#define XT_CONTEXT 0x81f8 /* CONTEXT*/
#define XT_HANDLER 0x81f4 /* HANDLER*/
#define XT_HLD 0x81f0 /* HLD*/
#define XT_SPARE2 0x81ec /* SPARE2*/
#define XT_STATE 0x81e8 /* STATE*/
#define XT_CSP 0x81e4 /* CSP*/
#define XT__23TIB 0x81e0 /* #TIB*/
#define XT__3EIN 0x81dc /* >IN*/
#define XT_SPAN 0x81d8 /* SPAN*/
#define XT_temp 0x81d4 /* temp*/
#define XT_BASE 0x81d0 /* BASE*/
#define XT__27PROMPT 0x81cc /* 'PROMPT*/
#define XT__27ECHO 0x81c8 /* 'ECHO*/
#define XT__27TAP 0x81c4 /* 'TAP*/
#define XT_SPARE 0x81c0 /* SPARE*/
#define XT__27EMIT 0x81bc /* 'EMIT*/
#define XT__27_3FKEY 0x81b8 /* '?KEY*/
#define XT_RP0 0x81b4 /* RP0*/
#define XT_SP0 0x81b0 /* SP0*/
#define XT__5FUSER 0x81ac /* _USER*/
#define XT__2D_3E 0x81a8 /* ->*/
#define XT__7DT 0x81a2 /* }T*/
#define XT_DEPTH 0x819c /* DEPTH*/
#define XT_T_7B 0x8196 /* T{*/
#define XT_of 0x8192 /* of*/
#define XT_DEFER 0x818e /* DEFER*/
#define XT__3EBODY 0x818a /* >BODY*/
#define XT_ALIGN 0x8188 /* ALIGN*/
#define XT_immediate_3F 0x8186 /* immediate?*/
#define XT_2RDrop 0x8184 /* 2RDrop*/
#define XT_RDrop 0x8182 /* RDrop*/
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
#define F_RDrop 72
#define F_TwoRDrop 73
#define F_immediateQ 74
#define F_vpAlign 75
#define F_toBODY 76
#define F_DEFER 77
#define F_of 78
#define F_Tbrace 79
#define F_DEPTH 80
#define F_Tunbrace 81
#define F_Tarrow 82
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
RDrop, /* 2RDrop */ TwoRDrop, /* immediate? */ immediateQ, /* ALIGN */ vpAlign, 
/* >BODY */ toBODY, 0, of, 0, 
0, 0, 0,  0 };
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
/* 0x8048 LAST */ 0xcfb2,
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
/* 0x813c: ( */ F_tokenDefer, 0x9838, 0x39, 
/* 0x8142: TOKEN */ F_tokenDefer, XT_, 0x3a, 
/* 0x8148: NUMBER? */ F_tokenDefer, 0x95fc, 0x3b, 
/* 0x814e: $COMPILE */ F_tokenDefer, XT_, 0x3c, 
/* 0x8154: $INTERPRET */ F_tokenDefer, XT_, 0x3d, 
/* 0x815a: [ */ F_tokenDefer, XT_, 0x3e, 
/* 0x8160: ] */ F_tokenDefer, 0x93c8, 0x3f, 
/* 0x8166: : */ F_tokenDefer, 0x93d2, 0x40, 
/* 0x816c: ; */ F_tokenDefer, XT_, 0x41, 
/* 0x8172: ' */ F_tokenDefer, XT_, 
/* 0x8176: debugNA */ F_debugNA, 
/* 0x8178: Fbreak */ F_Fbreak, 
/* 0x817a: stringBuffer */ F_stringBuffer, 
/* 0x817c: TYPE */ F_TYPE, 
/* 0x817e: loop */ F_loop, 
/* 0x8180: I */ F_I, 
/* 0x8182: RDrop */ F_RDrop, 
/* 0x8184: 2RDrop */ F_TwoRDrop, 
/* 0x8186: immediate? */ F_immediateQ, 
/* 0x8188: ALIGN */ F_vpAlign, 
/* 0x818a: >BODY */ F_toBODY, 0x4d, 
/* 0x818e: DEFER */ F_tokenDefer, 0x93e0, 
/* 0x8192: of */ F_of, 0x4f, 
/* 0x8196: T{ */ F_tokenDefer, 0x8194, 0x50, 
/* 0x819c: DEPTH */ F_tokenDefer, XT_, 0x51, 
/* 0x81a2: }T */ F_tokenDefer, 0x81a0, 0x52, 
/* 0x81a8: -> */ F_tokenDefer, 0x81a6, 
/* 0x81ac: _USER */ F_tokenUser, 0, 
/* 0x81b0: SP0 */ F_tokenUser, 4, 
/* 0x81b4: RP0 */ F_tokenUser, 5, 
/* 0x81b8: '?KEY */ F_tokenUser, 6, 
/* 0x81bc: 'EMIT */ F_tokenUser, 7, 
/* 0x81c0: SPARE */ F_tokenUser, 8, 
/* 0x81c4: 'TAP */ F_tokenUser, 9, 
/* 0x81c8: 'ECHO */ F_tokenUser, 0xa, 
/* 0x81cc: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x81d0: BASE */ F_tokenUser, 0xc, 
/* 0x81d4: temp */ F_tokenUser, 0xd, 
/* 0x81d8: SPAN */ F_tokenUser, 0xe, 
/* 0x81dc: >IN */ F_tokenUser, 0xf, 
/* 0x81e0: #TIB */ F_tokenUser, 0x10, 
/* 0x81e4: CSP */ F_tokenUser, 0x12, 
/* 0x81e8: STATE */ F_tokenUser, 0x13, 
/* 0x81ec: SPARE2 */ F_tokenUser, 0x14, 
/* 0x81f0: HLD */ F_tokenUser, 0x15, 
/* 0x81f4: HANDLER */ F_tokenUser, 0x16, 
/* 0x81f8: CONTEXT */ F_tokenUser, 0x17, 
/* 0x81fc: CURRENT */ F_tokenUser, 0x20, 
/* 0x8200: CP */ F_tokenUser, 0x22, 
/* 0x8204: NP */ F_tokenUser, 0x23, 
/* 0x8208: LAST */ F_tokenUser, 0x24, 
/* 0x820c: VP */ F_tokenUser, 0x25, 
/* 0x8210: source-id */ F_tokenUser, 0x26, 
/* 0x8214: testFlags */ F_tokenUser, 0x27, 
/* 0x8218: testDepth */ F_tokenUser, 0x28, 
/* 0x821c: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x8224: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x8236: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x823e: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x8246: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x8252: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x825a: TUCK */ F_tokenDoList, XT_SWAP, XT_OVER, XT_EXIT, 
/* 0x8262: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x826a: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x8272: CELL+ */ F_tokenDoList, XT_CELLL, XT__2B, XT_EXIT, 
/* 0x827a: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x828c: COMPILE, */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x8292: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x829a: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x82aa: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLit, XT__2C, XT_EXIT, 
/* 0x82b4: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x82c6: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x82ce: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x82d4: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x82da: >MARK */ F_tokenDoList, XT_HERE, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x82e6: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x82f0: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x82fa: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x8300: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x830a: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x8314: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x831e: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x8328: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x8332: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x833a: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x8340: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x834c: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x8356: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x835e: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x8366: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x8372: >RESOLVES */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVES + 0xe, XT__3ERESOLVE, XT_branch, XT__3ERESOLVES + 2, XT_EXIT, 
/* 0x8382: >MARKSTART */ F_tokenDoList, XT_doLit, 0, XT_EXIT, 
/* 0x838a: >MARKTHREAD */ F_tokenDoList, XT_HERE, XT_SWAP, XT__2C, XT_EXIT, 
/* 0x8394: >RESOLVETHREAD */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVETHREAD + 0x14, XT_DUP, XT__40, XT_SWAP, XT__3ERESOLVE, XT_branch, XT__3ERESOLVETHREAD + 2, XT_EXIT, 
/* 0x83aa: CASE */ F_tokenDoList, XT__3EMARKSTART, XT_EXIT, 
/* 0x83b0: OF */ F_tokenDoList, XT_COMPILE, XT_of, XT__3EMARK, XT_EXIT, 
/* 0x83ba: ENDOF */ F_tokenDoList, XT_COMPILE, XT_branch, XT_SWAP, XT__3EMARKTHREAD, XT_SWAP, XT__3ERESOLVE, XT_EXIT, 
/* 0x83ca: ENDCASE */ F_tokenDoList, XT_COMPILE, XT_DROP, XT__3ERESOLVETHREAD, XT_EXIT, 
/* 0x83d4: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xc, XT_FALSE, XT_branch, XT_0_3D + 0xe, XT_TRUE, XT_EXIT, 
/* 0x83e4: 0<> */ F_tokenDoList, XT_0_3D, XT_0_3D, XT_EXIT, 
/* 0x83ec: D0= */ F_tokenDoList, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x83f4: ?\ */ F_tokenDoList, XT_0_3D, XT__3Fbranch, XT__3F_5C + 0xa, XT__5C, XT_EXIT, 
/* 0x8400: ?safe\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 4, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x8410: ?test\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 8, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x8420: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x842c: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x8434: 2OVER */ F_tokenDoList, XT__3ER, XT__3ER, XT_2DUP, XT_R_3E, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8446: 2SWAP */ F_tokenDoList, XT__3ER, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8452: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x8466: INVERT */ F_tokenDoList, XT_doLit, 0xffff, XT_XOR, XT_EXIT, 
/* 0x8470: 1+ */ F_tokenDoList, XT_doLit, 1, XT__2B, XT_EXIT, 
/* 0x847a: NEGATE */ F_tokenDoList, XT_INVERT, XT_1_2B, XT_EXIT, 
/* 0x8482: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLit, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8496: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x849e: 1- */ F_tokenDoList, XT_doLit, 1, XT__2D, XT_EXIT, 
/* 0x84a8: ?negate */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT__3Fnegate + 0xa, XT_NEGATE, XT_EXIT, 
/* 0x84b4: ABS */ F_tokenDoList, XT_DUP, XT__3Fnegate, XT_EXIT, 
/* 0x84bc: CHAR+ */ F_tokenDoList, XT_1_2B, XT_EXIT, 
/* 0x84c2: C, */ F_tokenDoList, XT_HERE, XT_DUP, XT_CHAR_2B, XT_CP, XT__21, XT_C_21, XT_EXIT, 
/* 0x84d2: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xc, XT_FALSE, XT_EXIT, XT_TRUE, XT_EXIT, 
/* 0x84e2: <> */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3C_3E + 0xc, XT_TRUE, XT_EXIT, XT_FALSE, XT_EXIT, 
/* 0x84f2: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x850a: U> */ F_tokenDoList, XT_SWAP, XT_U_3C, XT_EXIT, 
/* 0x8512: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x14, XT_2DROP, XT_TRUE, XT_branch, XT_ud_3C + 0x16, XT_U_3C, XT_EXIT, 
/* 0x852a: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x8542: > */ F_tokenDoList, XT_SWAP, XT__3C, XT_EXIT, 
/* 0x854a: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x855a: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x856c: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x857c: S>D */ F_tokenDoList, XT_DUP, XT_0_3C, XT_EXIT, 
/* 0x8584: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x54, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x46, XT__3ER, XT_DROP, XT_1_2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x48, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLit, 0xffff, XT_DUP, XT_EXIT, 
/* 0x85e4: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x861a: FM/MOD */ F_tokenDoList, XT_M_2FMOD, XT_EXIT, 
/* 0x8620: /MOD */ F_tokenDoList, XT__3ER, XT_S_3ED, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x862c: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x8634: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x863c: UM* */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x8676: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x867e: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x869a: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x86a6: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x86ae: D0< */ F_tokenDoList, XT_NIP, XT_0_3C, XT_EXIT, 
/* 0x86b6: DABS */ F_tokenDoList, XT_2DUP, XT_D0_3C, XT__3Fbranch, XT_DABS + 0xc, XT_DNEGATE, XT_EXIT, 
/* 0x86c4: SM/REM */ F_tokenDoList, XT_2DUP, XT_XOR, XT__3ER, XT_OVER, XT__3ER, XT_ABS, XT__3ER, XT_DABS, XT_R_3E, XT_UM_2FMOD, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_EXIT, 
/* 0x86e8: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x86f0: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x86f8: CHARS */ F_tokenDoList, XT_EXIT, 
/* 0x86fc: 2* */ F_tokenDoList, XT_doLit, 2, XT__2A, XT_EXIT, 
/* 0x8706: ($,n) */ F_tokenDoList, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_DUP, XT_CP, XT__21, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, 
/* 0x8732: :NONAME */ F_tokenDoList, XT_NP, XT__40, XT_CELL_2D, XT_doLit, 0, XT_OVER, XT__21, XT_DUP, XT_NP, XT__21, XT__28_24_2Cn_29, XT_HERE, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x8754: DEFER@ */ F_tokenDoList, XT__3EBODY, XT__40, XT_EXIT, 
/* 0x875c: >BODY! */ F_tokenDoList, XT__3EBODY, XT__21, XT_EXIT, 
/* 0x8764: DEFER! */ F_tokenDoList, XT__3EBODY_21, XT_EXIT, 
/* 0x876a: >CHAR */ F_tokenDoList, XT_doLit, 0x7f, XT_AND, XT_DUP, XT_doLit, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT_doLit, 0x5f, XT_EXIT, 
/* 0x8788:  */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x879a: PICK */ F_tokenDoList, XT_1_2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x87a8: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x87b8: ++ */ F_tokenDoList, XT_doLit, 1, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87c4: -- */ F_tokenDoList, XT_doLit, 0xffff, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87d0: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x87de: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x87ec: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x87fe: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x881e: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x882c: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT, 
/* 0x8848: PAD */ F_tokenDoList, XT_HERE, XT_doLit, 0x50, XT__2B, XT_EXIT, 
/* 0x8854: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x885e: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0xc, XT_EXECUTE, XT_EXIT, 
/* 0x886c: COUNT */ F_tokenDoList, XT_DUP, XT_1_2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x8878: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x18, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2B, XT_R_3E, XT_1_2B, XT_next, XT_CMOVE + 8, XT_2DROP, XT_EXIT, 
/* 0x8898: CMOVE> */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_R_3E, XT__3ER, XT_branch, XT_CMOVE_3E + 0x2c, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2D, XT_R_3E, XT_1_2D, XT_next, XT_CMOVE_3E + 0x1c, XT_2DROP, XT_EXIT, 
/* 0x88cc: MOVE */ F_tokenDoList, XT__3ER, XT_2DUP, XT__3E, XT_R_3E, XT_SWAP, XT__3Fbranch, XT_MOVE + 0x16, XT_CMOVE, XT_branch, XT_MOVE + 0x18, XT_CMOVE_3E, XT_EXIT, 
/* 0x88e6: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x12, XT_2DUP, XT_C_21, XT_1_2B, XT_next, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x8900: ERASE */ F_tokenDoList, XT_doLit, 0, XT_FILL, XT_EXIT, 
/* 0x890a: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x1e, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x1e, XT_R_3E, XT_1_2B, XT_EXIT, XT_next, XT__2DTRAILING + 8, XT_doLit, 0, XT_EXIT, 
/* 0x8932: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLit, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_1_2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x8964: DIGIT */ F_tokenDoList, XT_doLit, 9, XT_OVER, XT__3C, XT_doLit, 7, XT_AND, XT__2B, XT_doLit, 0x30, XT__2B, XT_EXIT, 
/* 0x897e: EXTRACT */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT_R_40, XT_FM_2FMOD, XT_R_3E, XT_SWAP, XT__3ER, XT_FM_2FMOD, XT_R_3E, XT_ROT, XT_DIGIT, XT_EXIT, 
/* 0x899a: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x89a4: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_1_2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x89b6: HOLDS */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_HOLDS + 0x16, XT_1_2D, XT_2DUP, XT__2B, XT_C_40, XT_HOLD, XT_branch, XT_HOLDS + 2, XT_2DROP, XT_EXIT, 
/* 0x89d0: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x89dc: #S */ F_tokenDoList, XT__23, XT_2DUP, XT_OR, XT__3Fbranch, XT__23S + 0x10, XT_branch, XT__23S + 2, XT_EXIT, 
/* 0x89ee: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT_doLit, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x89fe: #> */ F_tokenDoList, XT_2DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8a0e: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x8a16: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x8a1e: emits */ F_tokenDoList, XT_SWAP, XT_doLit, 0, XT_MAX, XT__3ER, XT_branch, XT_emits + 0x14, XT_DUP, XT_EMIT, XT_next, XT_emits + 0x10, XT_DROP, XT_EXIT, 
/* 0x8a3a: SPACES */ F_tokenDoList, XT_BL, XT_emits, XT_EXIT, 
/* 0x8a42: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x8a4a: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT_doLit, 0, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x8a62: HEX */ F_tokenDoList, XT_doLit, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a6e: DECIMAL */ F_tokenDoList, XT_doLit, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a7a: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8a8c: U.R */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8aa6: U. */ F_tokenDoList, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8ab8: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLit, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8ad4: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x8adc: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLit, 0x30, XT__2D, XT_doLit, 0x2a, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x1c, XT_doLit, 0x20, XT__2D, XT_doLit, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x38, XT_doLit, 7, XT__2D, XT_DUP, XT_doLit, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x8b1c: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x8b24: KEY */ F_tokenDoList, XT_doLit, 0, XT_ms, XT_doLit, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT, 
/* 0x8b3a: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT_doLit, 0xd, XT__3D, XT_EXIT, 
/* 0x8b50: PACE */ F_tokenDoList, XT_doLit, 0xb, XT_EMIT, XT_EXIT, 
/* 0x8b5a: CR */ F_tokenDoList, XT_doLit, 0xd, XT_EMIT, XT_doLit, 0xa, XT_EMIT, XT_EXIT, 
/* 0x8b6a: ['] */ F_tokenDoList, XT__27, XT_LITERAL, XT_EXIT, 
/* 0x8b72: SOURCE */ F_tokenDoList, XT_TIB, XT__23TIB, XT__40, XT_EXIT, 
/* 0x8b7c: /STRING */ F_tokenDoList, XT_TUCK, XT__2D, XT__3ER, XT__2B, XT_R_3E, XT_EXIT, 
/* 0x8b8a: isspace? */ F_tokenDoList, XT_BL, XT_1_2B, XT_U_3C, XT_EXIT, 
/* 0x8b94: isnotspace? */ F_tokenDoList, XT_isspace_3F, XT_0_3D, XT_EXIT, 
/* 0x8b9c: xt-skip */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT_OVER, XT_C_40, XT_R_40, XT_EXECUTE, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_xt_2Dskip + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8bc2: skip-till */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT_OVER, XT_C_40, XT_R_40, XT__3D, XT_0_3D, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_skip_2Dtill + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8bea:  */ F_tokenDoList, XT__3ER, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c06, XT_doLit, XT_isspace_3F, XT_xt_2Dskip, XT_OVER, XT_SWAP, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c1e, XT_doLit, XT_isnotspace_3F, XT_xt_2Dskip, XT_branch, 0x8c22, XT_R_40, XT_skip_2Dtill, XT_R_3E, XT_DROP, XT_2DUP, XT_doLit, 1, XT_MIN, XT__2B, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8c42: PARSE-NAME */ F_tokenDoList, XT_BL, XT_PARSE, XT_EXIT, 
/* 0x8c4a: CHAR */ F_tokenDoList, XT_PARSE_2DNAME, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x8c54: [CHAR] */ F_tokenDoList, XT_CHAR, XT_LITERAL, XT_EXIT, 
/* 0x8c5c: CTRL */ F_tokenDoList, XT_CHAR, XT_doLit, 0x1f, XT_AND, XT_EXIT, 
/* 0x8c68: .( */ F_tokenDoList, XT_doLit, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x8c74:  */ F_tokenDoList, XT_PARSE_2DNAME, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x8c8c: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x8c96: NAME>INTERPRET */ F_tokenDoList, XT_doLit, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x8ca4: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 8, XT_FALSE, XT_EXIT, 
/* 0x8cd6: FIND-NAME */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_FIND_2DNAME + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT__3ER, XT_R_40, XT__40, XT__3Fbranch, XT_FIND_2DNAME + 0x38, XT_2DUP, XT_R_40, XT__40, XT_FIND_2DNAME_2DIN, XT__3FDUP, XT__3Fbranch, XT_FIND_2DNAME + 0x12, XT_R_3E, XT_DROP, XT_NIP, XT_NIP, XT_EXIT, XT_R_3E, XT_DROP, XT_2DROP, XT_FALSE, XT_EXIT, 
/* 0x8d18: NAME? */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x1a, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_branch, XT_NAME_3F + 0x1c, XT_FALSE, XT_EXIT, 
/* 0x8d36: FIND */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_FIND + 0x2c, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_immediate_3F, XT__3Fbranch, XT_FIND + 0x24, XT_doLit, 1, XT_branch, XT_FIND + 0x28, XT_doLit, 0xffff, XT_branch, XT_FIND + 0x30, XT_doLit, 0, XT_EXIT, 
/* 0x8d68: MARKER */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT_CONTEXT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CURRENT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CREATE, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT_DOES_3E, XT_DUP, XT__40, XT_CURRENT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CURRENT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CP, XT__21, XT_CELL_2B, XT__40, XT_NP, XT__21, XT_EXIT, 
/* 0x8dd4: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLit, 0, XT_EXIT, 
/* 0x8df8: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x20, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x8e1a: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8e46: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8e56: crlf? */ F_tokenDoList, XT_DUP, XT_doLit, 0xa, XT__3D, XT_SWAP, XT_doLit, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x8e6c: skipCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipCRLF + 0x12, XT_OVER, XT_C_40, XT_crlf_3F, XT_branch, XT_skipCRLF + 0x14, XT_FALSE, XT__3Fbranch, XT_skipCRLF + 0x24, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipCRLF + 2, XT_EXIT, 
/* 0x8e92: skipToCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipToCRLF + 0x14, XT_OVER, XT_C_40, XT_crlf_3F, XT_0_3D, XT_branch, XT_skipToCRLF + 0x16, XT_FALSE, XT__3Fbranch, XT_skipToCRLF + 0x26, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipToCRLF + 2, XT_EXIT, 
/* 0x8eba: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x30, XT_DUP, XT_doLit, 8, XT__3D, XT_SWAP, XT_doLit, 0x7f, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x2c, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x2e, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x8ef2: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x8f08: $," */ F_tokenDoList, XT_doLit, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x8f1c: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x8f22: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x8f2a: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x8f32: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f3c: C" */ F_tokenDoList, XT__24_22, XT_EXIT, 
/* 0x8f42: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f4c: S" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_branch, XT_S_22 + 0x20, XT_doLit, 0x22, XT_PARSE, XT_stringBuffer, XT_PACK_24, XT_COUNT, XT_EXIT, 
/* 0x8f6e: bu+@ */ F_tokenDoList, XT_1_2D, XT__3ER, XT_COUNT, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x8f7c: c+! */ F_tokenDoList, XT_TUCK, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8f86: cmove\ */ F_tokenDoList, XT_SWAP, XT_DUP, XT__3ER, XT__3ER, XT__3FDUP, XT__3Fbranch, 0x90f0, XT_bu_2B_40, XT_DUP, XT_doLit, 0x22, XT__3C_3E, XT__3Fbranch, 0x90ee, XT_doLit, 0x5c, XT_of, 0x90e0, XT_bu_2B_40, XT_doLit, 0x6d, XT_of, XT_cmove_5C + 0x46, XT_doLit, 0xd, XT_R_3E, XT_c_2B_21, XT_doLit, 0xa, XT_SWAP, XT_c_2B_21, XT__3ER, XT_branch, 0x90dc, XT_doLit, 0x78, XT_of, XT_cmove_5C + 0x78, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_doLit, 0x10, XT__2A, XT__3ER, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_R_3E, XT__2B, XT_R_3E, XT_c_2B_21, XT__3ER, XT_branch, 0x90dc, XT_doLit, 0x61, XT_of, XT_cmove_5C + 0x88, XT_doLit, 7, XT_branch, 0x90d2, XT_doLit, 0x62, XT_of, XT_cmove_5C + 0x98, XT_doLit, 8, XT_branch, 0x90d2, XT_doLit, 0x65, XT_of, XT_cmove_5C + 0xa8, XT_doLit, 0x1b, XT_branch, 0x90d2, XT_doLit, 0x66, XT_of, XT_cmove_5C + 0xb8, XT_doLit, 0xc, XT_branch, 0x90d2, XT_doLit, 0x6c, XT_of, XT_cmove_5C + 0xc8, XT_doLit, 0xa, XT_branch, 0x90d2, XT_doLit, 0x6e, XT_of, XT_cmove_5C + 0xd8, XT_doLit, 0xa, XT_branch, 0x90d2, XT_doLit, 0x71, XT_of, XT_cmove_5C + 0xe8, XT_doLit, 0x22, XT_branch, 0x90d2, XT_doLit, 0x72, XT_of, XT_cmove_5C + 0xf8, XT_doLit, 0xd, XT_branch, 0x90d2, XT_doLit, 0x74, XT_of, 0x908e, XT_doLit, 9, XT_branch, 0x90d2, XT_doLit, 0x76, XT_of, 0x909e, XT_doLit, 0xb, XT_branch, 0x90d2, XT_doLit, 0x7a, XT_of, 0x90ae, XT_doLit, 0, XT_branch, 0x90d2, XT_doLit, 0x22, XT_of, 0x90be, XT_doLit, 0x22, XT_branch, 0x90d2, XT_doLit, 0x5c, XT_of, 0x90ce, XT_doLit, 0x5c, XT_branch, 0x90d2, XT_DUP, XT_DROP, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, 0x90ea, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, XT_cmove_5C + 0xa, XT_2DROP, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x90f8: pack\$ */ F_tokenDoList, XT_ALIGNED, XT__3ER, XT_R_40, XT_1_2B, XT_SWAP, XT_cmove_5C, XT_DUP, XT_R_40, XT_C_21, XT_DUP, XT_R_40, XT__2B, XT_1_2B, XT_SWAP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__3FDUP, XT__3Fbranch, XT_pack_5C_24 + 0x42, XT_SWAP, XT_doLit, 0, XT_OVER, XT_C_21, XT_1_2B, XT_SWAP, XT_1_2D, XT_branch, XT_pack_5C_24 + 0x28, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x9140: S\" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT_HERE, XT_branch, XT_S_5C_22 + 0x16, XT_stringBuffer, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_ROT, XT_pack_5C_24, XT_SWAP, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_COUNT, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x40, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x9182: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x9188: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x9190: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x91a0: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x91aa: POSTPONE */ F_tokenDoList, XT_TOKEN, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT_0_3D, XT_abort_22, 0x4e09, 0x746f, 0x6620, 0x756f, 0x646e, XT_DUP, XT_immediate_3F, XT_0_3D, XT__3Fbranch, XT_POSTPONE + 0x26, XT_COMPILE, XT_COMPILE, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x91d6:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x91fc, XT_C_40, XT_doLit, 0x40, XT_AND, XT_abort_22, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9204, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9208: .OK */ F_tokenDoList, XT_STATE, XT__40, XT_0_3D, XT__3Fbranch, XT__2EOK + 0x12, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0x921e: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0x9232:  */ F_tokenDoList, XT_FALSE, XT_STATE, XT__21, XT_EXIT, 
/* 0x923c: XIO */ F_tokenDoList, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x924c: FILE */ F_tokenDoList, XT_doLit, 0, XT_doLit, XT_DROP, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x925e: HAND */ F_tokenDoList, XT_doLit, XT__2EOK, XT_doLit, XT_EMIT, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x9270: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x9278: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x9286:  */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, 0x9292, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9296: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x929e: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0x92b4: BUFFER: */ F_tokenDoList, XT_CREATE, XT_vALLOT, XT_EXIT, 
/* 0x92bc: '>BODY! */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT__27_3EBODY_21 + 0x14, XT__5B_27_5D, XT_COMPILE, XT__3EBODY_21, XT_branch, XT__27_3EBODY_21 + 0x18, XT__27, XT__3EBODY_21, XT_EXIT, 
/* 0x92d6: IS */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x92dc: ACTION-OF */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_ACTION_2DOF + 0x14, XT__5B_27_5D, XT_COMPILE, XT_DEFER_40, XT_branch, XT_ACTION_2DOF + 0x18, XT__27, XT_DEFER_40, XT_EXIT, 
/* 0x92f6: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x9302: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x931e:  */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, 0x932e, XT__3FUNIQUE, XT__28_24_2Cn_29, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0x933a:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x9358, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, 0x9354, XT_EXECUTE, XT_branch, 0x9356, XT__2C, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9362, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9366: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x22, XT_STATE, XT__40, XT__3Fbranch, XT_EVAL + 0x1a, XT__24COMPILE, XT_branch, XT_EVAL + 0x1c, XT__24INTERPRET, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x9390:  */ F_tokenDoList, XT_LAST, XT__40, XT_DUP, XT__40, XT__3Fbranch, 0x93a8, XT_CURRENT, XT__40, XT__21, XT_branch, 0x93ba, XT_DROP, XT_NP, XT__40, XT_doLit, 3, XT_CELLS, XT__2B, XT_NP, XT__21, XT_EXIT, 
/* 0x93bc:  */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 3, XT_TRUE, XT_STATE, XT__21, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDefer, XT__2C, XT_doLit, 0, XT__2C, XT_OVERT, XT_EXIT, 
/* 0x93f4: VALUE */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_HERE, XT_tokenValue, XT__2C, XT__5FUSER, XT__40, XT__2C, XT__5FUSER, XT__2B_2B, XT__3EBODY_21, XT_EXIT, 
/* 0x9410: TO */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x9416: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLit, 0, XT_v_2C, XT_EXIT, 
/* 0x9422: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x9432: leave-ptr */ F_tokenVar, 0, 6, 
/* 0x9438: (?do) */ F_tokenDoList, XT_R_3E, XT__2DROT, XT_2DUP, XT_2_3ER, XT__3C_3E, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x944a: (loop) */ F_tokenDoList, XT_R_3E, XT_2R_3E, XT_1_2B, XT_2DUP, XT_2_3ER, XT__3D, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x945e: (+loop) */ F_tokenDoList, XT_R_3E, XT_SWAP, XT_2R_3E, XT_doLit, 2, XT_PICK, XT_OVER, XT__2B, XT_ROT, XT_DUP, XT__3ER, XT__2DROT, XT_DUP, XT__3ER, XT_doLit, 3, XT_PICK, XT_0_3C, XT__3Fbranch, XT__28_2Bloop_29 + 0x2c, XT_SWAP, XT_1_2B, XT_SWAP, XT_1_2B, XT_SWAP, XT_WITHIN, XT_NIP, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x949c: leave, */ F_tokenDoList, XT_HERE, XT_leave_2Dptr, XT__40, XT__2C, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x94ac: LEAVE */ F_tokenDoList, XT_COMPILE, XT_branch, XT_leave_2C, XT_EXIT, 
/* 0x94b6: UNLOOP */ F_tokenDoList, XT_COMPILE, XT_2RDrop, XT_EXIT, 
/* 0x94be: DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT_2_3ER, XT_HERE, XT_EXIT, 
/* 0x94d4: ?DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT__28_3Fdo_29, XT_COMPILE, XT__3Fbranch, XT_leave_2C, XT_HERE, XT_EXIT, 
/* 0x94f0: some-loop */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__2C, XT_leave_2Dptr, XT__40, XT__3FDUP, XT__3Fbranch, XT_some_2Dloop + 0x24, XT_DUP, XT__40, XT__3ER, XT_HERE, XT_SWAP, XT__21, XT_R_3E, XT_branch, XT_some_2Dloop + 0xc, XT_UNLOOP, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x951c: LOOP */ F_tokenDoList, XT_COMPILE, XT__28loop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x9526: +LOOP */ F_tokenDoList, XT_COMPILE, XT__28_2Bloop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x9530: I-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 2, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9540: J */ F_tokenDoList, XT_RP_40, XT_doLit, 3, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9550: J-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 4, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x9560: accumulate */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_BASE, XT__40, XT_UM_2A, XT_DROP, XT_ROT, XT_BASE, XT__40, XT_UM_2A, XT_D_2B, XT_R_3E, XT_EXIT, 
/* 0x957e: >NUMBER */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_doLit, 0, XT__28_3Fdo_29, XT__3Fbranch, XT__3ENUMBER + 0x3c, XT_DROP, XT_COUNT, XT_BASE, XT__40, XT_DIGIT_3F, XT_0_3D, XT__3Fbranch, XT__3ENUMBER + 0x30, XT_DROP, XT_1_2D, XT_I_2DMAX, XT_I, XT__2D, XT_branch, XT__3ENUMBER + 0x3c, XT_accumulate, XT_doLit, 0, XT__28loop_29, XT__3Fbranch, XT__3ENUMBER + 0x12, XT_2RDrop, XT_EXIT, 
/* 0x95be: (charbase) */ F_tokenDoList, XT_DUP, XT_doLit, 0x23, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x14, XT_doLit, 0xa, XT_EXIT, XT_DUP, XT_doLit, 0x24, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x26, XT_doLit, 0x10, XT_EXIT, XT_DUP, XT_doLit, 0x25, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x38, XT_doLit, 2, XT_EXIT, XT_doLit, 0, XT_EXIT, 3, XT_DUP, XT_BASE, XT__40, XT__3ER, XT_COUNT, XT_OVER, XT__3ER, XT__3ER, XT_COUNT, XT__28charbase_29, XT__3FDUP, XT__3Fbranch, XT__28charbase_29 + 0x62, XT_BASE, XT__21, XT_DROP, XT_COUNT, XT_DUP, XT_doLit, 0x27, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x9a, XT_DROP, XT_COUNT, XT_SWAP, XT_COUNT, XT_doLit, 0x27, XT__3C_3E, XT__3Fbranch, XT__28charbase_29 + 0x8a, XT_2DROP, XT_2RDrop, XT_FALSE, XT_branch, XT__28charbase_29 + 0x92, XT_DROP, XT_NIP, XT_TRUE, XT_2RDrop, XT_R_3E, XT_BASE, XT__21, XT_EXIT, XT_doLit, 0x2d, XT__3D, XT_TUCK, XT_0_3D, XT__3Fbranch, XT__28charbase_29 + 0xaa, XT_1_2D, XT_doLit, 0, XT_doLit, 0, XT_ROT, XT_R_3E, XT_R_3E, XT__2B, XT_OVER, XT__2D, XT__3ENUMBER, XT__3Fbranch, XT__28charbase_29 + 0xce, XT_2DROP, XT_2DROP, XT_FALSE, XT_branch, XT__28charbase_29 + 0xde, XT_DROP, XT_ROT, XT__3Fbranch, XT__28charbase_29 + 0xd8, XT_DNEGATE, XT_DROP, XT_NIP, XT_TRUE, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x96a4: ACCEPT */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_ACCEPT + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLit, 0x5f, XT_U_3C, XT__3Fbranch, XT_ACCEPT + 0x28, XT_TAP, XT_branch, XT_ACCEPT + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_ACCEPT + 8, XT_DROP, XT_SWAP, XT__2D, XT_EXIT, 
/* 0x96dc: stack */ F_tokenDoList, XT_CREATE, XT_HERE, XT_doLit, 0, XT__2C, XT_OVER, XT__2C, XT_vHERE, XT_SWAP, XT__21, XT_doLit, 0, XT_v_2C, XT_CELLS, XT_vALLOT, XT_EXIT, 
/* 0x96fe: spop */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_CELLS, XT_OVER, XT__2B, XT__40, XT_SWAP, XT__2D_2D, XT_EXIT, 
/* 0x9714: spush */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_1_2B, XT_2DUP, XT_SWAP, XT__21, XT_CELLS, XT__2B, XT__21, XT_EXIT, 
/* 0x972c: spushes */ F_tokenDoList, XT_OVER, XT__3ER, XT_SWAP, XT_doLit, 0, XT_2_3ER, XT_TUCK, XT_spush, XT__28loop_29, XT__3Fbranch, XT_spushes + 0xe, XT_2RDrop, XT_R_3E, XT_SWAP, XT_spush, XT_EXIT, 
/* 0x974e: spops */ F_tokenDoList, XT_DUP, XT_spop, XT__3ER, XT_R_40, XT_doLit, 0, XT_2_3ER, XT_DUP, XT_spop, XT_SWAP, XT__28loop_29, XT__3Fbranch, XT_spops + 0x10, XT_2RDrop, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x9772: sempty */ F_tokenDoList, XT__40, XT_doLit, 0, XT_SWAP, XT__21, XT_EXIT, 
/* 0x9780: SOURCE-ID */ F_tokenDoList, XT_source_2Did, XT__40, XT_EXIT, 
/* 0x9788: sourceStack */ F_tokenCreate, 0, 8, 0x20, 
/* 0x9790: 0> */ F_tokenDoList, XT_DUP, XT_0_3D, XT_SWAP, XT_0_3C, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x97a0: unreadFile */ F_tokenDefer, 0, 
/* 0x97a4: SAVE-INPUT */ F_tokenDoList, XT_SOURCE_2DID, XT_SOURCE, XT__3EIN, XT__40, XT_doLit, 4, XT_EXIT, 
/* 0x97b4: sourcePush */ F_tokenDoList, XT_SAVE_2DINPUT, XT_sourceStack, XT_spushes, XT_EXIT, 
/* 0x97be: RESTORE-INPUT */ F_tokenDoList, XT_DROP, XT__3EIN, XT__21, XT__23TIB, XT__21, XT__23TIB, XT_CELL_2B, XT__21, XT_DUP, XT_source_2Did, XT__21, XT__3Fbranch, XT_RESTORE_2DINPUT + 0x22, XT_FILE, XT_branch, XT_RESTORE_2DINPUT + 0x24, XT_HAND, XT_doLit, 0, XT_EXIT, 
/* 0x97e8: sourcePop */ F_tokenDoList, XT_sourceStack, XT_spops, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x97f4: READ-LINE */ F_tokenDefer, 0, 
/* 0x97f8: REFILL */ F_tokenDoList, XT_SOURCE_2DID, XT__3FDUP, XT__3Fbranch, XT_REFILL + 0x1a, XT_DROP, XT_FALSE, XT_doLit, 0, XT__3EIN, XT__21, XT_branch, XT_REFILL + 0x30, XT_TIB, XT_doLit, 0x50, XT_ACCEPT, XT__23TIB, XT__21, XT_doLit, 0, XT__3EIN, XT__21, XT_TRUE, XT_EXIT, 
/* 0x982a: QUERY */ F_tokenDoList, XT_REFILL, XT_0_3D, XT__3Fbranch, XT_QUERY + 0xc, XT_sourcePop, XT_EXIT, 3, XT_doLit, 0x29, XT_PARSE, XT__2B, XT_C_40, XT_doLit, 0x29, XT__3C_3E, XT__3Fbranch, XT_QUERY + 0x42, XT_REFILL, XT_0_3D, XT_abort_22, 0x7514, 0x746e, 0x7265, 0x696d, 0x616e, 0x6574, 0x2064, 0x6f63, 0x6d6d, 0x6e65, 0x74, XT_QUERY + 0xe, XT_EXIT, 
/* 0x986e: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x9876: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_sourceStack, XT_sempty, XT_doLit, 0, XT_TIB0, XT_doLit, 0, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x989a: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLit, 0x5e, XT_emits, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0x98ca: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLit, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT__27PROMPT, XT__40, XT__3ER, XT_CONSOLE, XT_quitError, XT_R_3E, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x2c, XT__27PROMPT, XT__21, XT_branch, XT_QUIT + 8, XT_EXIT, 
/* 0x98fc: quit1 */ F_tokenDoList, XT_doLit, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0x9910: EVALUATE */ F_tokenDoList, XT_sourcePush, XT_doLit, 0xffff, XT__2DROT, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_quit1, XT_EXIT, 
/* 0x992a: dm+ */ F_tokenDoList, XT_OVER, XT_doLit, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x1e, XT_DUP, XT_C_40, XT_doLit, 3, XT_U_2ER, XT_1_2B, XT_next, XT_dm_2B + 0x12, XT_EXIT, 
/* 0x994e: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLit, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLit, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLit, 2, XT_SPACES, XT_TYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT_next, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x9992: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0xc, XT__2E_22_7C, 0x2005, 0x733c, 0x2070, XT_EXIT, 
/* 0x99b2: UNUSED */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT__2D, XT_EXIT, 
/* 0x99c0: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x99d2: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x99de: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x99e8: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x9a02: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT_BYTEMASK, XT_AND, XT_TYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x9a22: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT, 
/* 0x9a44: >NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT__3ENAME + 0x28, XT_2DUP, XT_NAME_3EINTERPRET, XT_XOR, XT__3Fbranch, XT__3ENAME + 0x28, XT_CELL_2D, XT_branch, XT__3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_FALSE, XT_EXIT, 
/* 0x9a80: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLit, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLit, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT, 
/* 0x9b06: VER */ F_tokenNextVal, 0x11, 
/* 0x9b0a: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT_doLit, 0, XT__3C_23, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x9b4c: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x9b54: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x9b64: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x9b6a: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT, 
/* 0x9b82: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x9b8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9eae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ece: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9eee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa00e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa02e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa04e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa06e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa08e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa10e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa12e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa14e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa16e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa18e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa20e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa22e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa24e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa26e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa28e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa30e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa32e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa34e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa36e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa38e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa40e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa42e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa44e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa46e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa48e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa50e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa52e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa54e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa56e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa58e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa60e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa62e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa64e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa66e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa68e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa70e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa72e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa74e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa76e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa78e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa80e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa82e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa84e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa86e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa88e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa90e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa92e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa94e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa96e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa98e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaaae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaace: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaaee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaeae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaece: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaeee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb00e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb02e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb04e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb06e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb08e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb10e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb12e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb14e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb16e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb18e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb20e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb22e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb24e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb26e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb28e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb30e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb32e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb34e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb36e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb38e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb40e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb42e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb44e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb46e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb48e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb50e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb52e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb54e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb56e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb58e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb60e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb62e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb64e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb66e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb68e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb70e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb72e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb74e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb76e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb78e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb80e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb82e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb84e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb86e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb88e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb90e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb92e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb94e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb96e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb98e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbaae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbace: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbaee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbeae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbece: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbeee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc00e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc02e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc04e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc06e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc08e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc10e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc12e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc14e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc16e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc18e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc20e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc22e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc24e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc26e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc28e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc30e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc32e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc34e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc36e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc38e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc40e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc42e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc44e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc46e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc48e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc50e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc52e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc54e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc56e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc58e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc60e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc62e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc64e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc66e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc68e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc70e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc72e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc74e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc76e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc78e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc80e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc82e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc84e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc86e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc88e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc90e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc92e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc94e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc96e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc98e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9ae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9ce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9ee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcaae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcace: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcaee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdce: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xceae: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcece: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xceee: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf0e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf2e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf4e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf6e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf8e: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0xcfae WARM */ XT_WARM, 0xcfbc, 0x5704, 0x5241, 0x4d,
/* 0xcfb8 COLD */ XT_COLD, 0xcfc6, 0x4304, 0x4c4f, 0x44,
/* 0xcfc2 'BOOT */ XT__27BOOT, 0xcfd0, 0x2705, 0x4f42, 0x544f,
/* 0xcfcc EMPTY */ XT_EMPTY, 0xcfda, 0x4505, 0x504d, 0x5954,
/* 0xcfd6 hi */ XT_hi, 0xcfe2, 0x6842, 0x69,
/* 0xcfde version */ XT_version, 0xcfee, 0x7607, 0x7265, 0x6973, 0x6e6f,
/* 0xcfea VER */ XT_VER, 0xcff6, 0x5603, 0x5245,
/* 0xcff2 SEE */ XT_SEE, 0xcffe, 0x5303, 0x4545,
/* 0xcffa >NAME */ XT__3ENAME, 0xd008, 0x3e05, 0x414e, 0x454d,
/* 0xd004 WORDS */ XT_WORDS, 0xd012, 0x5705, 0x524f, 0x5344,
/* 0xd00e .ID */ XT__2EID, 0xd01a, 0x2e03, 0x4449,
/* 0xd016 ?CSP */ XT__3FCSP, 0xd024, 0x3f04, 0x5343, 0x50,
/* 0xd020 !CSP */ XT__21CSP, 0xd02e, 0x2104, 0x5343, 0x50,
/* 0xd02a .FREE */ XT__2EFREE, 0xd038, 0x2e05, 0x5246, 0x4545,
/* 0xd034 .BASE */ XT__2EBASE, 0xd042, 0x2e05, 0x4142, 0x4553,
/* 0xd03e UNUSED */ XT_UNUSED, 0xd04e, 0x5506, 0x554e, 0x4553, 0x44,
/* 0xd04a .S */ XT__2ES, 0xd056, 0x2e02, 0x53,
/* 0xd052 DUMP */ XT_DUMP, 0xd060, 0x4404, 0x4d55, 0x50,
/* 0xd05c dm+ */ XT_dm_2B, 0xd068, 0x6403, 0x2b6d,
/* 0xd064 EVALUATE */ XT_EVALUATE, 0xd076, 0x4508, 0x4156, 0x554c, 0x5441, 0x45,
/* 0xd072 quit1 */ XT_quit1, 0xd080, 0x7105, 0x6975, 0x3174,
/* 0xd07c QUIT */ XT_QUIT, 0xd08a, 0x5104, 0x4955, 0x54,
/* 0xd086 quitError */ XT_quitError, 0xd098, 0x7109, 0x6975, 0x4574, 0x7272, 0x726f,
/* 0xd094 PRESET */ XT_PRESET, 0xd0a4, 0x5006, 0x4552, 0x4553, 0x54,
/* 0xd0a0 que */ XT_que, 0xd0ac, 0x7103, 0x6575,
/* 0xd0a8 QUERY */ XT_QUERY, 0xd0b6, 0x5105, 0x4555, 0x5952,
/* 0xd0b2 REFILL */ XT_REFILL, 0xd0c2, 0x5206, 0x4645, 0x4c49, 0x4c,
/* 0xd0be READ-LINE */ XT_READ_2DLINE, 0xd0d0, 0x5209, 0x4145, 0x2d44, 0x494c, 0x454e,
/* 0xd0cc sourcePop */ XT_sourcePop, 0xd0de, 0x7309, 0x756f, 0x6372, 0x5065, 0x706f,
/* 0xd0da RESTORE-INPUT */ XT_RESTORE_2DINPUT, 0xd0f0, 0x520d, 0x5345, 0x4f54, 0x4552, 0x492d, 0x504e, 0x5455,
/* 0xd0ec sourcePush */ XT_sourcePush, 0xd100, 0x730a, 0x756f, 0x6372, 0x5065, 0x7375, 0x68,
/* 0xd0fc SAVE-INPUT */ XT_SAVE_2DINPUT, 0xd110, 0x530a, 0x5641, 0x2d45, 0x4e49, 0x5550, 0x54,
/* 0xd10c unreadFile */ XT_unreadFile, 0xd120, 0x750a, 0x726e, 0x6165, 0x4664, 0x6c69, 0x65,
/* 0xd11c 0> */ XT_0_3E, 0xd128, 0x3002, 0x3e,
/* 0xd124 sourceStack */ XT_sourceStack, 0xd138, 0x730b, 0x756f, 0x6372, 0x5365, 0x6174, 0x6b63,
/* 0xd134 SOURCE-ID */ XT_SOURCE_2DID, 0xd146, 0x5309, 0x554f, 0x4352, 0x2d45, 0x4449,
/* 0xd142 sempty */ XT_sempty, 0xd152, 0x7306, 0x6d65, 0x7470, 0x79,
/* 0xd14e spops */ XT_spops, 0xd15c, 0x7305, 0x6f70, 0x7370,
/* 0xd158 spushes */ XT_spushes, 0xd168, 0x7307, 0x7570, 0x6873, 0x7365,
/* 0xd164 spush */ XT_spush, 0xd172, 0x7305, 0x7570, 0x6873,
/* 0xd16e spop */ XT_spop, 0xd17c, 0x7304, 0x6f70, 0x70,
/* 0xd178 stack */ XT_stack, 0xd186, 0x7305, 0x6174, 0x6b63,
/* 0xd182 ACCEPT */ XT_ACCEPT, 0xd192, 0x4106, 0x4343, 0x5045, 0x54,
/* 0xd18e (charbase) */ XT__28charbase_29, 0xd1a2, 0x280a, 0x6863, 0x7261, 0x6162, 0x6573, 0x29,
/* 0xd19e >NUMBER */ XT__3ENUMBER, 0xd1ae, 0x3e07, 0x554e, 0x424d, 0x5245,
/* 0xd1aa accumulate */ XT_accumulate, 0xd1be, 0x610a, 0x6363, 0x6d75, 0x6c75, 0x7461, 0x65,
/* 0xd1ba J-MAX */ XT_J_2DMAX, 0xd1c8, 0x4a05, 0x4d2d, 0x5841,
/* 0xd1c4 J */ XT_J, 0xd1ce, 0x4a01,
/* 0xd1ca I-MAX */ XT_I_2DMAX, 0xd1d8, 0x4905, 0x4d2d, 0x5841,
/* 0xd1d4 +LOOP */ XT__2BLOOP, 0xd1e2, 0x2b85, 0x4f4c, 0x504f,
/* 0xd1de LOOP */ XT_LOOP, 0xd1ec, 0x4c84, 0x4f4f, 0x50,
/* 0xd1e8 some-loop */ XT_some_2Dloop, 0xd1fa, 0x7309, 0x6d6f, 0x2d65, 0x6f6c, 0x706f,
/* 0xd1f6 ?DO */ XT__3FDO, 0xd202, 0x3f83, 0x4f44,
/* 0xd1fe DO */ XT_DO, 0xd20a, 0x4482, 0x4f,
/* 0xd206 UNLOOP */ XT_UNLOOP, 0xd216, 0x5586, 0x4c4e, 0x4f4f, 0x50,
/* 0xd212 LEAVE */ XT_LEAVE, 0xd220, 0x4c85, 0x4145, 0x4556,
/* 0xd21c leave, */ XT_leave_2C, 0xd22c, 0x6c06, 0x6165, 0x6576, 0x2c,
/* 0xd228 (+loop) */ XT__28_2Bloop_29, 0xd238, 0x2807, 0x6c2b, 0x6f6f, 0x2970,
/* 0xd234 (loop) */ XT__28loop_29, 0xd244, 0x2806, 0x6f6c, 0x706f, 0x29,
/* 0xd240 (?do) */ XT__28_3Fdo_29, 0xd24e, 0x2805, 0x643f, 0x296f,
/* 0xd24a leave-ptr */ XT_leave_2Dptr, 0xd25c, 0x6c09, 0x6165, 0x6576, 0x702d, 0x7274,
/* 0xd258 CONSTANT */ XT_CONSTANT, 0xd26a, 0x4308, 0x4e4f, 0x5453, 0x4e41, 0x54,
/* 0xd266 VARIABLE */ XT_VARIABLE, 0xd278, 0x5608, 0x5241, 0x4149, 0x4c42, 0x45,
/* 0xd274 TO */ XT_TO, 0xd280, 0x5482, 0x4f,
/* 0xd27c VALUE */ XT_VALUE, 0xd28a, 0x5605, 0x4c41, 0x4555,
/* 0xd286  */ XT_, 0xd290, 0xc0,
/* 0xd28c  */ XT_, 0xd296, 0,
/* 0xd292 EVAL */ XT_EVAL, 0xd2a0, 0x4504, 0x4156, 0x4c,
/* 0xd29c  */ XT_, 0xd2a6, 0,
/* 0xd2a2  */ XT_, 0xd2ac, 0,
/* 0xd2a8 ?UNIQUE */ XT__3FUNIQUE, 0xd2b8, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0xd2b4 RECURSE */ XT_RECURSE, 0xd2c4, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0xd2c0 ACTION-OF */ XT_ACTION_2DOF, 0xd2d2, 0x4189, 0x5443, 0x4f49, 0x2d4e, 0x464f,
/* 0xd2ce IS */ XT_IS, 0xd2da, 0x4982, 0x53,
/* 0xd2d6 '>BODY! */ XT__27_3EBODY_21, 0xd2e6, 0x2707, 0x423e, 0x444f, 0x2159,
/* 0xd2e2 BUFFER: */ XT_BUFFER_3A, 0xd2f2, 0x4207, 0x4655, 0x4546, 0x3a52,
/* 0xd2ee vALLOT */ XT_vALLOT, 0xd2fe, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0xd2fa ALLOT */ XT_ALLOT, 0xd308, 0x4105, 0x4c4c, 0x544f,
/* 0xd304  */ XT_, 0xd30e, 0,
/* 0xd30a CONSOLE */ XT_CONSOLE, 0xd31a, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0xd316 I/O */ XT_I_2FO, 0xd322, 0x4903, 0x4f2f,
/* 0xd31e HAND */ XT_HAND, 0xd32c, 0x4804, 0x4e41, 0x44,
/* 0xd328 FILE */ XT_FILE, 0xd336, 0x4604, 0x4c49, 0x45,
/* 0xd332 XIO */ XT_XIO, 0xd33e, 0x5803, 0x4f49,
/* 0xd33a  */ XT_, 0xd344, 0x80,
/* 0xd340 ?STACK */ XT__3FSTACK, 0xd350, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0xd34c .OK */ XT__2EOK, 0xd358, 0x2e03, 0x4b4f,
/* 0xd354  */ XT_, 0xd35e, 0,
/* 0xd35a POSTPONE */ XT_POSTPONE, 0xd36c, 0x5088, 0x534f, 0x5054, 0x4e4f, 0x45,
/* 0xd368 ABORT" */ XT_ABORT_22, 0xd378, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0xd374 abort" */ XT_abort_22, 0xd384, 0x6146, 0x6f62, 0x7472, 0x22,
/* 0xd380 ABORT */ XT_ABORT, 0xd38e, 0x4105, 0x4f42, 0x5452,
/* 0xd38a NULL$ */ XT_NULL_24, 0xd398, 0x4e05, 0x4c55, 0x244c,
/* 0xd394 S\" */ XT_S_5C_22, 0xd3a0, 0x5383, 0x225c,
/* 0xd39c pack\$ */ XT_pack_5C_24, 0xd3ac, 0x7006, 0x6361, 0x5c6b, 0x24,
/* 0xd3a8 cmove\ */ XT_cmove_5C, 0xd3b8, 0x6306, 0x6f6d, 0x6576, 0x5c,
/* 0xd3b4 c+! */ XT_c_2B_21, 0xd3c0, 0x6303, 0x212b,
/* 0xd3bc bu+@ */ XT_bu_2B_40, 0xd3ca, 0x6204, 0x2b75, 0x40,
/* 0xd3c6 S" */ XT_S_22, 0xd3d2, 0x5382, 0x22,
/* 0xd3ce ." */ XT__2E_22, 0xd3da, 0x2e82, 0x22,
/* 0xd3d6 C" */ XT_C_22, 0xd3e2, 0x4382, 0x22,
/* 0xd3de $" */ XT__24_22, 0xd3ea, 0x2482, 0x22,
/* 0xd3e6 S"| */ XT_S_22_7C, 0xd3f2, 0x5303, 0x7c22,
/* 0xd3ee ."| */ XT__2E_22_7C, 0xd3fa, 0x2e03, 0x7c22,
/* 0xd3f6 $"| */ XT__24_22_7C, 0xd402, 0x2403, 0x7c22,
/* 0xd3fe $," */ XT__24_2C_22, 0xd40a, 0x2403, 0x222c,
/* 0xd406 do$ */ XT_do_24, 0xd412, 0x6403, 0x246f,
/* 0xd40e kTAP */ XT_kTAP, 0xd41c, 0x6b04, 0x4154, 0x50,
/* 0xd418 skipToCRLF */ XT_skipToCRLF, 0xd42c, 0x730a, 0x696b, 0x5470, 0x436f, 0x4c52, 0x46,
/* 0xd428 skipCRLF */ XT_skipCRLF, 0xd43a, 0x7308, 0x696b, 0x4370, 0x4c52, 0x46,
/* 0xd436 crlf? */ XT_crlf_3F, 0xd444, 0x6305, 0x6c72, 0x3f66,
/* 0xd440 TAP */ XT_TAP, 0xd44c, 0x5403, 0x5041,
/* 0xd448 ^H */ XT__5EH, 0xd454, 0x5e02, 0x48,
/* 0xd450 THROW */ XT_THROW, 0xd45e, 0x5405, 0x5248, 0x574f,
/* 0xd45a CATCH */ XT_CATCH, 0xd468, 0x4305, 0x5441, 0x4843,
/* 0xd464 MARKER */ XT_MARKER, 0xd474, 0x4d06, 0x5241, 0x454b, 0x52,
/* 0xd470 FIND */ XT_FIND, 0xd47e, 0x4604, 0x4e49, 0x44,
/* 0xd47a NAME? */ XT_NAME_3F, 0xd488, 0x4e05, 0x4d41, 0x3f45,
/* 0xd484 FIND-NAME */ XT_FIND_2DNAME, 0xd496, 0x4609, 0x4e49, 0x2d44, 0x414e, 0x454d,
/* 0xd492 SAME? */ XT_SAME_3F, 0xd4a0, 0x5305, 0x4d41, 0x3f45,
/* 0xd49c NAME>INTERPRET */ XT_NAME_3EINTERPRET, 0xd4b4, 0x4e0e, 0x4d41, 0x3e45, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0xd4b0 WORD */ XT_WORD, 0xd4be, 0x5704, 0x524f, 0x44,
/* 0xd4ba  */ XT_, 0xd4c4, 0,
/* 0xd4c0 .( */ XT__2E_28, 0xd4cc, 0x2e82, 0x28,
/* 0xd4c8 CTRL */ XT_CTRL, 0xd4d6, 0x4304, 0x5254, 0x4c,
/* 0xd4d2 [CHAR] */ XT__5BCHAR_5D, 0xd4e2, 0x5b86, 0x4843, 0x5241, 0x5d,
/* 0xd4de CHAR */ XT_CHAR, 0xd4ec, 0x4304, 0x4148, 0x52,
/* 0xd4e8 PARSE-NAME */ XT_PARSE_2DNAME, 0xd4fc, 0x500a, 0x5241, 0x4553, 0x4e2d, 0x4d41, 0x45,
/* 0xd4f8  */ XT_, 0xd502, 0,
/* 0xd4fe skip-till */ XT_skip_2Dtill, 0xd510, 0x7309, 0x696b, 0x2d70, 0x6974, 0x6c6c,
/* 0xd50c xt-skip */ XT_xt_2Dskip, 0xd51c, 0x7807, 0x2d74, 0x6b73, 0x7069,
/* 0xd518 isnotspace? */ XT_isnotspace_3F, 0xd52c, 0x690b, 0x6e73, 0x746f, 0x7073, 0x6361, 0x3f65,
/* 0xd528 isspace? */ XT_isspace_3F, 0xd53a, 0x6908, 0x7373, 0x6170, 0x6563, 0x3f,
/* 0xd536 /STRING */ XT__2FSTRING, 0xd546, 0x2f07, 0x5453, 0x4952, 0x474e,
/* 0xd542 SOURCE */ XT_SOURCE, 0xd552, 0x5306, 0x554f, 0x4352, 0x45,
/* 0xd54e ['] */ XT__5B_27_5D, 0xd55a, 0x5b83, 0x5d27,
/* 0xd556 CR */ XT_CR, 0xd562, 0x4302, 0x52,
/* 0xd55e PACE */ XT_PACE, 0xd56c, 0x5004, 0x4341, 0x45,
/* 0xd568 NUF? */ XT_NUF_3F, 0xd576, 0x4e04, 0x4655, 0x3f,
/* 0xd572 KEY */ XT_KEY, 0xd57e, 0x4b03, 0x5945,
/* 0xd57a ?KEY */ XT__3FKEY, 0xd588, 0x3f04, 0x454b, 0x59,
/* 0xd584 DIGIT? */ XT_DIGIT_3F, 0xd594, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0xd590 ? */ XT__3F, 0xd59a, 0x3f01,
/* 0xd596 . */ XT__2E, 0xd5a0, 0x2e01,
/* 0xd59c U. */ XT_U_2E, 0xd5a8, 0x5502, 0x2e,
/* 0xd5a4 U.R */ XT_U_2ER, 0xd5b0, 0x5503, 0x522e,
/* 0xd5ac .R */ XT__2ER, 0xd5b8, 0x2e02, 0x52,
/* 0xd5b4 DECIMAL */ XT_DECIMAL, 0xd5c4, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0xd5c0 HEX */ XT_HEX, 0xd5cc, 0x4803, 0x5845,
/* 0xd5c8 str */ XT_str, 0xd5d4, 0x7303, 0x7274,
/* 0xd5d0 .$ */ XT__2E_24, 0xd5dc, 0x2e02, 0x24,
/* 0xd5d8 SPACES */ XT_SPACES, 0xd5e8, 0x5306, 0x4150, 0x4543, 0x53,
/* 0xd5e4 emits */ XT_emits, 0xd5f2, 0x6505, 0x696d, 0x7374,
/* 0xd5ee SPACE */ XT_SPACE, 0xd5fc, 0x5305, 0x4150, 0x4543,
/* 0xd5f8 EMIT */ XT_EMIT, 0xd606, 0x4504, 0x494d, 0x54,
/* 0xd602 #> */ XT__23_3E, 0xd60e, 0x2302, 0x3e,
/* 0xd60a SIGN */ XT_SIGN, 0xd618, 0x5304, 0x4749, 0x4e,
/* 0xd614 #S */ XT__23S, 0xd620, 0x2302, 0x53,
/* 0xd61c # */ XT__23, 0xd626, 0x2301,
/* 0xd622 HOLDS */ XT_HOLDS, 0xd630, 0x4805, 0x4c4f, 0x5344,
/* 0xd62c HOLD */ XT_HOLD, 0xd63a, 0x4804, 0x4c4f, 0x44,
/* 0xd636 <# */ XT__3C_23, 0xd642, 0x3c02, 0x23,
/* 0xd63e EXTRACT */ XT_EXTRACT, 0xd64e, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0xd64a DIGIT */ XT_DIGIT, 0xd658, 0x4405, 0x4749, 0x5449,
/* 0xd654 PACK$ */ XT_PACK_24, 0xd662, 0x5005, 0x4341, 0x244b,
/* 0xd65e -TRAILING */ XT__2DTRAILING, 0xd670, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0xd66c ERASE */ XT_ERASE, 0xd67a, 0x4505, 0x4152, 0x4553,
/* 0xd676 FILL */ XT_FILL, 0xd684, 0x4604, 0x4c49, 0x4c,
/* 0xd680 MOVE */ XT_MOVE, 0xd68e, 0x4d04, 0x564f, 0x45,
/* 0xd68a CMOVE> */ XT_CMOVE_3E, 0xd69a, 0x4306, 0x4f4d, 0x4556, 0x3e,
/* 0xd696 CMOVE */ XT_CMOVE, 0xd6a4, 0x4305, 0x4f4d, 0x4556,
/* 0xd6a0 COUNT */ XT_COUNT, 0xd6ae, 0x4305, 0x554f, 0x544e,
/* 0xd6aa @EXECUTE */ XT__40EXECUTE, 0xd6bc, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0xd6b8 TIB */ XT_TIB, 0xd6c4, 0x5403, 0x4249,
/* 0xd6c0 PAD */ XT_PAD, 0xd6cc, 0x5003, 0x4441,
/* 0xd6c8 vCREATE */ XT_vCREATE, 0xd6d8, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0xd6d4 vALIGN */ XT_vALIGN, 0xd6e4, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0xd6e0 v, */ XT_v_2C, 0xd6ec, 0x7602, 0x2c,
/* 0xd6e8 vHERE */ XT_vHERE, 0xd6f6, 0x7605, 0x4548, 0x4552,
/* 0xd6f2 2@ */ XT_2_40, 0xd6fe, 0x3202, 0x40,
/* 0xd6fa 2! */ XT_2_21, 0xd706, 0x3202, 0x21,
/* 0xd702 -- */ XT__2D_2D, 0xd70e, 0x2d02, 0x2d,
/* 0xd70a ++ */ XT__2B_2B, 0xd716, 0x2b02, 0x2b,
/* 0xd712 +! */ XT__2B_21, 0xd71e, 0x2b02, 0x21,
/* 0xd71a PICK */ XT_PICK, 0xd728, 0x5004, 0x4349, 0x4b,
/* 0xd724  */ XT_, 0xd72e, 0,
/* 0xd72a >CHAR */ XT__3ECHAR, 0xd738, 0x3e05, 0x4843, 0x5241,
/* 0xd734 DEFER! */ XT_DEFER_21, 0xd744, 0x4406, 0x4645, 0x5245, 0x21,
/* 0xd740 >BODY! */ XT__3EBODY_21, 0xd750, 0x3e06, 0x4f42, 0x5944, 0x21,
/* 0xd74c DEFER@ */ XT_DEFER_40, 0xd75c, 0x4406, 0x4645, 0x5245, 0x40,
/* 0xd758 :NONAME */ XT__3ANONAME, 0xd768, 0x3a07, 0x4f4e, 0x414e, 0x454d,
/* 0xd764 ($,n) */ XT__28_24_2Cn_29, 0xd772, 0x2805, 0x2c24, 0x296e,
/* 0xd76e 2* */ XT_2_2A, 0xd77a, 0x3202, 0x2a,
/* 0xd776 CHARS */ XT_CHARS, 0xd784, 0x4305, 0x4148, 0x5352,
/* 0xd780 CELLS */ XT_CELLS, 0xd78e, 0x4305, 0x4c45, 0x534c,
/* 0xd78a CELL- */ XT_CELL_2D, 0xd798, 0x4305, 0x4c45, 0x2d4c,
/* 0xd794 SM/REM */ XT_SM_2FREM, 0xd7a4, 0x5306, 0x2f4d, 0x4552, 0x4d,
/* 0xd7a0 DABS */ XT_DABS, 0xd7ae, 0x4404, 0x4241, 0x53,
/* 0xd7aa D0< */ XT_D0_3C, 0xd7b6, 0x4403, 0x3c30,
/* 0xd7b2 * / */ XT__2A_2F, 0xd7be, 0x2a02, 0x2f,
/* 0xd7ba * /MOD */ XT__2A_2FMOD, 0xd7c8, 0x2a05, 0x4d2f, 0x444f,
/* 0xd7c4 M* */ XT_M_2A, 0xd7d0, 0x4d02, 0x2a,
/* 0xd7cc * */ XT__2A, 0xd7d6, 0x2a01,
/* 0xd7d2 UM* */ XT_UM_2A, 0xd7de, 0x5503, 0x2a4d,
/* 0xd7da / */ XT__2F, 0xd7e4, 0x2f01,
/* 0xd7e0 MOD */ XT_MOD, 0xd7ec, 0x4d03, 0x444f,
/* 0xd7e8 /MOD */ XT__2FMOD, 0xd7f6, 0x2f04, 0x4f4d, 0x44,
/* 0xd7f2 FM/MOD */ XT_FM_2FMOD, 0xd802, 0x4606, 0x2f4d, 0x4f4d, 0x44,
/* 0xd7fe M/MOD */ XT_M_2FMOD, 0xd80c, 0x4d05, 0x4d2f, 0x444f,
/* 0xd808 UM/MOD */ XT_UM_2FMOD, 0xd818, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0xd814 S>D */ XT_S_3ED, 0xd820, 0x5303, 0x443e,
/* 0xd81c WITHIN */ XT_WITHIN, 0xd82c, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0xd828 MIN */ XT_MIN, 0xd834, 0x4d03, 0x4e49,
/* 0xd830 MAX */ XT_MAX, 0xd83c, 0x4d03, 0x5841,
/* 0xd838 > */ XT__3E, 0xd842, 0x3e01,
/* 0xd83e < */ XT__3C, 0xd848, 0x3c01,
/* 0xd844 ud< */ XT_ud_3C, 0xd850, 0x7503, 0x3c64,
/* 0xd84c U> */ XT_U_3E, 0xd858, 0x5502, 0x3e,
/* 0xd854 U< */ XT_U_3C, 0xd860, 0x5502, 0x3c,
/* 0xd85c <> */ XT__3C_3E, 0xd868, 0x3c02, 0x3e,
/* 0xd864 = */ XT__3D, 0xd86e, 0x3d01,
/* 0xd86a C, */ XT_C_2C, 0xd876, 0x4302, 0x2c,
/* 0xd872 CHAR+ */ XT_CHAR_2B, 0xd880, 0x4305, 0x4148, 0x2b52,
/* 0xd87c ABS */ XT_ABS, 0xd888, 0x4103, 0x5342,
/* 0xd884 ?negate */ XT__3Fnegate, 0xd894, 0x3f07, 0x656e, 0x6167, 0x6574,
/* 0xd890 1- */ XT_1_2D, 0xd89c, 0x3102, 0x2d,
/* 0xd898 - */ XT__2D, 0xd8a2, 0x2d01,
/* 0xd89e DNEGATE */ XT_DNEGATE, 0xd8ae, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0xd8aa NEGATE */ XT_NEGATE, 0xd8ba, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0xd8b6 1+ */ XT_1_2B, 0xd8c2, 0x3102, 0x2b,
/* 0xd8be INVERT */ XT_INVERT, 0xd8ce, 0x4906, 0x564e, 0x5245, 0x54,
/* 0xd8ca D+ */ XT_D_2B, 0xd8d6, 0x4402, 0x2b,
/* 0xd8d2 2SWAP */ XT_2SWAP, 0xd8e0, 0x3205, 0x5753, 0x5041,
/* 0xd8dc 2OVER */ XT_2OVER, 0xd8ea, 0x3205, 0x564f, 0x5245,
/* 0xd8e6 2DUP */ XT_2DUP, 0xd8f4, 0x3204, 0x5544, 0x50,
/* 0xd8f0 -ROT */ XT__2DROT, 0xd8fe, 0x2d04, 0x4f52, 0x54,
/* 0xd8fa ?test\ */ XT__3Ftest_5C, 0xd90a, 0x3f86, 0x6574, 0x7473, 0x5c,
/* 0xd906 ?safe\ */ XT__3Fsafe_5C, 0xd916, 0x3f86, 0x6173, 0x6566, 0x5c,
/* 0xd912 ?\ */ XT__3F_5C, 0xd91e, 0x3f82, 0x5c,
/* 0xd91a D0= */ XT_D0_3D, 0xd926, 0x4403, 0x3d30,
/* 0xd922 0<> */ XT_0_3C_3E, 0xd92e, 0x3003, 0x3e3c,
/* 0xd92a 0= */ XT_0_3D, 0xd936, 0x3002, 0x3d,
/* 0xd932 ENDCASE */ XT_ENDCASE, 0xd942, 0x4587, 0x444e, 0x4143, 0x4553,
/* 0xd93e ENDOF */ XT_ENDOF, 0xd94c, 0x4585, 0x444e, 0x464f,
/* 0xd948 OF */ XT_OF, 0xd954, 0x4f82, 0x46,
/* 0xd950 CASE */ XT_CASE, 0xd95e, 0x4384, 0x5341, 0x45,
/* 0xd95a >RESOLVETHREAD */ XT__3ERESOLVETHREAD, 0xd972, 0x3e0e, 0x4552, 0x4f53, 0x564c, 0x5445, 0x5248, 0x4145, 0x44,
/* 0xd96e >MARKTHREAD */ XT__3EMARKTHREAD, 0xd982, 0x3e0b, 0x414d, 0x4b52, 0x4854, 0x4552, 0x4441,
/* 0xd97e >MARKSTART */ XT__3EMARKSTART, 0xd992, 0x3e0a, 0x414d, 0x4b52, 0x5453, 0x5241, 0x54,
/* 0xd98e >RESOLVES */ XT__3ERESOLVES, 0xd9a0, 0x3e09, 0x4552, 0x4f53, 0x564c, 0x5345,
/* 0xd99c ?DUP */ XT__3FDUP, 0xd9aa, 0x3f04, 0x5544, 0x50,
/* 0xd9a6 WHILE */ XT_WHILE, 0xd9b4, 0x5785, 0x4948, 0x454c,
/* 0xd9b0 WHEN */ XT_WHEN, 0xd9be, 0x5784, 0x4548, 0x4e,
/* 0xd9ba ELSE */ XT_ELSE, 0xd9c8, 0x4584, 0x534c, 0x45,
/* 0xd9c4 AFT */ XT_AFT, 0xd9d0, 0x4183, 0x5446,
/* 0xd9cc THEN */ XT_THEN, 0xd9da, 0x5484, 0x4548, 0x4e,
/* 0xd9d6 REPEAT */ XT_REPEAT, 0xd9e6, 0x5286, 0x5045, 0x4145, 0x54,
/* 0xd9e2 AHEAD */ XT_AHEAD, 0xd9f0, 0x4185, 0x4548, 0x4441,
/* 0xd9ec IF */ XT_IF, 0xd9f8, 0x4982, 0x46,
/* 0xd9f4 AGAIN */ XT_AGAIN, 0xda02, 0x4185, 0x4147, 0x4e49,
/* 0xd9fe UNTIL */ XT_UNTIL, 0xda0c, 0x5585, 0x544e, 0x4c49,
/* 0xda08 NEXT */ XT_NEXT, 0xda16, 0x4e84, 0x5845, 0x54,
/* 0xda12 BEGIN */ XT_BEGIN, 0xda20, 0x4285, 0x4745, 0x4e49,
/* 0xda1c FOR */ XT_FOR, 0xda28, 0x4683, 0x524f,
/* 0xda24 >RESOLVE */ XT__3ERESOLVE, 0xda36, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda32 >MARK */ XT__3EMARK, 0xda40, 0x3e05, 0x414d, 0x4b52,
/* 0xda3c <RESOLVE */ XT__3CRESOLVE, 0xda4e, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda4a <MARK */ XT__3CMARK, 0xda58, 0x3c05, 0x414d, 0x4b52,
/* 0xda54 CREATE */ XT_CREATE, 0xda64, 0x4306, 0x4552, 0x5441, 0x45,
/* 0xda60 create */ XT_create, 0xda70, 0x6306, 0x6572, 0x7461, 0x65,
/* 0xda6c LITERAL */ XT_LITERAL, 0xda7c, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0xda78 COMPILE */ XT_COMPILE, 0xda88, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0xda84 [COMPILE] */ XT__5BCOMPILE_5D, 0xda96, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0xda92 COMPILE, */ XT_COMPILE_2C, 0xdaa4, 0x4308, 0x4d4f, 0x4950, 0x454c, 0x2c,
/* 0xdaa0 , */ XT__2C, 0xdaaa, 0x2c01,
/* 0xdaa6 CELL+ */ XT_CELL_2B, 0xdab4, 0x4305, 0x4c45, 0x2b4c,
/* 0xdab0 + */ XT__2B, 0xdaba, 0x2b01,
/* 0xdab6 HERE */ XT_HERE, 0xdac4, 0x4804, 0x5245, 0x45,
/* 0xdac0 TUCK */ XT_TUCK, 0xdace, 0x5404, 0x4355, 0x4b,
/* 0xdaca NIP */ XT_NIP, 0xdad6, 0x4e03, 0x5049,
/* 0xdad2 \ */ XT__5C, 0xdadc, 0x5c81,
/* 0xdad8 IMMEDIATE */ XT_IMMEDIATE, 0xdaea, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0xdae6 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0xdafc, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0xdaf8 setHeaderBits */ XT_setHeaderBits, 0xdb0e, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0xdb0a 2DROP */ XT_2DROP, 0xdb18, 0x3205, 0x5244, 0x504f,
/* 0xdb14 testDepth */ XT_testDepth, 0xdb26, 0x7409, 0x7365, 0x4474, 0x7065, 0x6874,
/* 0xdb22 testFlags */ XT_testFlags, 0xdb34, 0x7409, 0x7365, 0x4674, 0x616c, 0x7367,
/* 0xdb30 source-id */ XT_source_2Did, 0xdb42, 0x7309, 0x756f, 0x6372, 0x2d65, 0x6469,
/* 0xdb3e VP */ XT_VP, 0xdb4a, 0x5602, 0x50,
/* 0xdb46 LAST */ XT_LAST, 0xdb54, 0x4c04, 0x5341, 0x54,
/* 0xdb50 NP */ XT_NP, 0xdb5c, 0x4e02, 0x50,
/* 0xdb58 CP */ XT_CP, 0xdb64, 0x4302, 0x50,
/* 0xdb60 CURRENT */ XT_CURRENT, 0xdb70, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0xdb6c CONTEXT */ XT_CONTEXT, 0xdb7c, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0xdb78 HANDLER */ XT_HANDLER, 0xdb88, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0xdb84 HLD */ XT_HLD, 0xdb90, 0x4803, 0x444c,
/* 0xdb8c SPARE2 */ XT_SPARE2, 0xdb9c, 0x5306, 0x4150, 0x4552, 0x32,
/* 0xdb98 STATE */ XT_STATE, 0xdba6, 0x5305, 0x4154, 0x4554,
/* 0xdba2 CSP */ XT_CSP, 0xdbae, 0x4303, 0x5053,
/* 0xdbaa #TIB */ XT__23TIB, 0xdbb8, 0x2304, 0x4954, 0x42,
/* 0xdbb4 >IN */ XT__3EIN, 0xdbc0, 0x3e03, 0x4e49,
/* 0xdbbc SPAN */ XT_SPAN, 0xdbca, 0x5304, 0x4150, 0x4e,
/* 0xdbc6 temp */ XT_temp, 0xdbd4, 0x7404, 0x6d65, 0x70,
/* 0xdbd0 BASE */ XT_BASE, 0xdbde, 0x4204, 0x5341, 0x45,
/* 0xdbda 'PROMPT */ XT__27PROMPT, 0xdbea, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0xdbe6 'ECHO */ XT__27ECHO, 0xdbf4, 0x2705, 0x4345, 0x4f48,
/* 0xdbf0 'TAP */ XT__27TAP, 0xdbfe, 0x2704, 0x4154, 0x50,
/* 0xdbfa SPARE */ XT_SPARE, 0xdc08, 0x5305, 0x4150, 0x4552,
/* 0xdc04 'EMIT */ XT__27EMIT, 0xdc12, 0x2705, 0x4d45, 0x5449,
/* 0xdc0e '?KEY */ XT__27_3FKEY, 0xdc1c, 0x2705, 0x4b3f, 0x5945,
/* 0xdc18 RP0 */ XT_RP0, 0xdc24, 0x5203, 0x3050,
/* 0xdc20 SP0 */ XT_SP0, 0xdc2c, 0x5303, 0x3050,
/* 0xdc28 _USER */ XT__5FUSER, 0xdc36, 0x5f05, 0x5355, 0x5245,
/* 0xdc32 -> */ XT__2D_3E, 0xdc3e, 0x2d02, 0x3e,
/* 0xdc3a }T */ XT__7DT, 0xdc46, 0x7d02, 0x54,
/* 0xdc42 DEPTH */ XT_DEPTH, 0xdc50, 0x4405, 0x5045, 0x4854,
/* 0xdc4c T{ */ XT_T_7B, 0xdc58, 0x5402, 0x7b,
/* 0xdc54 of */ XT_of, 0xdc60, 0x6f02, 0x66,
/* 0xdc5c DEFER */ XT_DEFER, 0xdc6a, 0x4405, 0x4645, 0x5245,
/* 0xdc66 >BODY */ XT__3EBODY, 0xdc74, 0x3e05, 0x4f42, 0x5944,
/* 0xdc70 ALIGN */ XT_ALIGN, 0xdc7e, 0x4105, 0x494c, 0x4e47,
/* 0xdc7a immediate? */ XT_immediate_3F, 0xdc8e, 0x690a, 0x6d6d, 0x6465, 0x6169, 0x6574, 0x3f,
/* 0xdc8a 2RDrop */ XT_2RDrop, 0xdc9a, 0x3206, 0x4452, 0x6f72, 0x70,
/* 0xdc96 RDrop */ XT_RDrop, 0xdca4, 0x5205, 0x7244, 0x706f,
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
