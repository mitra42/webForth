#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x9b80 /* WARM*/
#define XT_COLD 0x9b68 /* COLD*/
#define XT__27BOOT 0x9b62 /* 'BOOT*/
#define XT_EMPTY 0x9b52 /* EMPTY*/
#define XT_hi 0x9b4a /* hi*/
#define XT_version 0x9b08 /* version*/
#define XT_VER 0x9b04 /* VER*/
#define XT_SEE 0x9a7e /* SEE*/
#define XT__3ENAME 0x9a42 /* >NAME*/
#define XT_WORDS 0x9a20 /* WORDS*/
#define XT__2EID 0x9a00 /* .ID*/
#define XT__3FCSP 0x99e6 /* ?CSP*/
#define XT__21CSP 0x99dc /* !CSP*/
#define XT__2EFREE 0x99d0 /* .FREE*/
#define XT__2EBASE 0x99be /* .BASE*/
#define XT_UNUSED 0x99b0 /* UNUSED*/
#define XT__2ES 0x9990 /* .S*/
#define XT_DUMP 0x994c /* DUMP*/
#define XT_dm_2B 0x9928 /* dm+*/
#define XT_EVALUATE 0x990e /* EVALUATE*/
#define XT_quit1 0x98fa /* quit1*/
#define XT_QUIT 0x98c8 /* QUIT*/
#define XT_quitError 0x9898 /* quitError*/
#define XT_PRESET 0x9874 /* PRESET*/
#define XT_que 0x986c /* que*/
#define XT_QUERY 0x9828 /* QUERY*/
#define XT_REFILL 0x97f6 /* REFILL*/
#define XT_READ_2DLINE 0x97f2 /* READ-LINE*/
#define XT_sourcePop 0x97e6 /* sourcePop*/
#define XT_RESTORE_2DINPUT 0x97bc /* RESTORE-INPUT*/
#define XT_sourcePush 0x97b2 /* sourcePush*/
#define XT_SAVE_2DINPUT 0x97a2 /* SAVE-INPUT*/
#define XT_unreadFile 0x979e /* unreadFile*/
#define XT_0_3E 0x978e /* 0>*/
#define XT_sourceStack 0x9786 /* sourceStack*/
#define XT_SOURCE_2DID 0x977e /* SOURCE-ID*/
#define XT_sempty 0x9770 /* sempty*/
#define XT_spops 0x974c /* spops*/
#define XT_spushes 0x972a /* spushes*/
#define XT_spush 0x9712 /* spush*/
#define XT_spop 0x96fc /* spop*/
#define XT_stack 0x96da /* stack*/
#define XT_ACCEPT 0x96a2 /* ACCEPT*/
#define XT__28charbase_29 0x95bc /* (charbase)*/
#define XT__3ENUMBER 0x957c /* >NUMBER*/
#define XT_accumulate 0x955e /* accumulate*/
#define XT_J_2DMAX 0x954e /* J-MAX*/
#define XT_J 0x953e /* J*/
#define XT_I_2DMAX 0x952e /* I-MAX*/
#define XT__2BLOOP 0x9524 /* +LOOP*/
#define XT_LOOP 0x951a /* LOOP*/
#define XT_some_2Dloop 0x94ee /* some-loop*/
#define XT__3FDO 0x94d2 /* ?DO*/
#define XT_DO 0x94bc /* DO*/
#define XT_UNLOOP 0x94b4 /* UNLOOP*/
#define XT_LEAVE 0x94aa /* LEAVE*/
#define XT_leave_2C 0x949a /* leave,*/
#define XT__28_2Bloop_29 0x945c /* (+loop)*/
#define XT__28loop_29 0x9448 /* (loop)*/
#define XT__28_3Fdo_29 0x9436 /* (?do)*/
#define XT_leave_2Dptr 0x9430 /* leave-ptr*/
#define XT_CONSTANT 0x9420 /* CONSTANT*/
#define XT_VARIABLE 0x9414 /* VARIABLE*/
#define XT_TO 0x940e /* TO*/
#define XT_VALUE 0x93f2 /* VALUE*/
#define XT_EVAL 0x9364 /* EVAL*/
#define XT__3FUNIQUE 0x9300 /* ?UNIQUE*/
#define XT_RECURSE 0x92f4 /* RECURSE*/
#define XT_ACTION_2DOF 0x92da /* ACTION-OF*/
#define XT_IS 0x92d4 /* IS*/
#define XT__27_3EBODY_21 0x92ba /* '>BODY!*/
#define XT_BUFFER_3A 0x92b2 /* BUFFER:*/
#define XT_vALLOT 0x929c /* vALLOT*/
#define XT_ALLOT 0x9294 /* ALLOT*/
#define XT_CONSOLE 0x9276 /* CONSOLE*/
#define XT_I_2FO 0x926e /* I/O*/
#define XT_HAND 0x925c /* HAND*/
#define XT_FILE 0x924a /* FILE*/
#define XT_XIO 0x923a /* XIO*/
#define XT__3FSTACK 0x921c /* ?STACK*/
#define XT__2EOK 0x9206 /* .OK*/
#define XT_POSTPONE 0x91a8 /* POSTPONE*/
#define XT_ABORT_22 0x919e /* ABORT"*/
#define XT__28abort_22_29 0x918e /* (abort")*/
#define XT_ABORT 0x9186 /* ABORT*/
#define XT_NULL_24 0x9180 /* NULL$*/
#define XT_S_5C_22 0x913e /* S\"*/
#define XT_pack_5C_24 0x90f6 /* pack\$*/
#define XT_cmove_5C 0x8f84 /* cmove\*/
#define XT_c_2B_21 0x8f7a /* c+!*/
#define XT_bu_2B_40 0x8f6c /* bu+@*/
#define XT_S_22 0x8f4a /* S"*/
#define XT__2E_22 0x8f40 /* ."*/
#define XT_C_22 0x8f3a /* C"*/
#define XT__24_22 0x8f30 /* $"*/
#define XT_S_22_7C 0x8f28 /* S"|*/
#define XT__2E_22_7C 0x8f20 /* ."|*/
#define XT__24_22_7C 0x8f1a /* $"|*/
#define XT__24_2C_22 0x8f06 /* $,"*/
#define XT_do_24 0x8ef0 /* do$*/
#define XT_kTAP 0x8eb8 /* kTAP*/
#define XT_skipToCRLF 0x8e90 /* skipToCRLF*/
#define XT_skipCRLF 0x8e6a /* skipCRLF*/
#define XT_crlf_3F 0x8e54 /* crlf?*/
#define XT_TAP 0x8e44 /* TAP*/
#define XT__5EH 0x8e18 /* ^H*/
#define XT_THROW 0x8df6 /* THROW*/
#define XT_CATCH 0x8dd2 /* CATCH*/
#define XT_MARKER 0x8d66 /* MARKER*/
#define XT_FIND 0x8d34 /* FIND*/
#define XT_NAME_3F 0x8d16 /* NAME?*/
#define XT_FIND_2DNAME 0x8cd4 /* FIND-NAME*/
#define XT_SAME_3F 0x8ca2 /* SAME?*/
#define XT_NAME_3EINTERPRET 0x8c94 /* NAME>INTERPRET*/
#define XT_WORD 0x8c8a /* WORD*/
#define XT__2E_28 0x8c66 /* .(*/
#define XT_CTRL 0x8c5a /* CTRL*/
#define XT__5BCHAR_5D 0x8c52 /* [CHAR]*/
#define XT_CHAR 0x8c48 /* CHAR*/
#define XT_PARSE_2DNAME 0x8c40 /* PARSE-NAME*/
#define XT_skip_2Dtill 0x8bc0 /* skip-till*/
#define XT_xt_2Dskip 0x8b9a /* xt-skip*/
#define XT_isnotspace_3F 0x8b92 /* isnotspace?*/
#define XT_isspace_3F 0x8b88 /* isspace?*/
#define XT__2FSTRING 0x8b7a /* /STRING*/
#define XT_SOURCE 0x8b70 /* SOURCE*/
#define XT__5B_27_5D 0x8b68 /* [']*/
#define XT_CR 0x8b58 /* CR*/
#define XT_PACE 0x8b4e /* PACE*/
#define XT_NUF_3F 0x8b38 /* NUF?*/
#define XT_KEY 0x8b22 /* KEY*/
#define XT__3FKEY 0x8b1a /* ?KEY*/
#define XT_DIGIT_3F 0x8ada /* DIGIT?*/
#define XT__3F 0x8ad2 /* ?*/
#define XT__2E 0x8ab6 /* .*/
#define XT_U_2E 0x8aa4 /* U.*/
#define XT_U_2ER 0x8a8a /* U.R*/
#define XT__2ER 0x8a78 /* .R*/
#define XT_DECIMAL 0x8a6c /* DECIMAL*/
#define XT_HEX 0x8a60 /* HEX*/
#define XT_str 0x8a48 /* str*/
#define XT__2E_24 0x8a40 /* .$*/
#define XT_SPACES 0x8a38 /* SPACES*/
#define XT_emits 0x8a1c /* emits*/
#define XT_SPACE 0x8a14 /* SPACE*/
#define XT_EMIT 0x8a0c /* EMIT*/
#define XT__23_3E 0x89fc /* #>*/
#define XT_SIGN 0x89ec /* SIGN*/
#define XT__23S 0x89da /* #S*/
#define XT__23 0x89ce /* #*/
#define XT_HOLDS 0x89b4 /* HOLDS*/
#define XT_HOLD 0x89a2 /* HOLD*/
#define XT__3C_23 0x8998 /* <#*/
#define XT_EXTRACT 0x897c /* EXTRACT*/
#define XT_DIGIT 0x8962 /* DIGIT*/
#define XT_PACK_24 0x8930 /* PACK$*/
#define XT__2DTRAILING 0x8908 /* -TRAILING*/
#define XT_ERASE 0x88fe /* ERASE*/
#define XT_FILL 0x88e4 /* FILL*/
#define XT_MOVE 0x88ca /* MOVE*/
#define XT_CMOVE_3E 0x8896 /* CMOVE>*/
#define XT_CMOVE 0x8876 /* CMOVE*/
#define XT_COUNT 0x886a /* COUNT*/
#define XT__40EXECUTE 0x885c /* @EXECUTE*/
#define XT_TIB 0x8852 /* TIB*/
#define XT_PAD 0x8846 /* PAD*/
#define XT_vCREATE 0x882a /* vCREATE*/
#define XT_vALIGN 0x881c /* vALIGN*/
#define XT_v_2C 0x87fc /* v,*/
#define XT_vHERE 0x87ea /* vHERE*/
#define XT_2_40 0x87dc /* 2@*/
#define XT_2_21 0x87ce /* 2!*/
#define XT__2D_2D 0x87c2 /* --*/
#define XT__2B_2B 0x87b6 /* ++*/
#define XT__2B_21 0x87a6 /* +!*/
#define XT_PICK 0x8798 /* PICK*/
#define XT__3ECHAR 0x8768 /* >CHAR*/
#define XT_DEFER_21 0x8762 /* DEFER!*/
#define XT__3EBODY_21 0x875a /* >BODY!*/
#define XT_DEFER_40 0x8752 /* DEFER@*/
#define XT__3ANONAME 0x8730 /* :NONAME*/
#define XT__28_24_2Cn_29 0x8704 /* ($,n)*/
#define XT_2_2A 0x86fa /* 2**/
#define XT_CHARS 0x86f6 /* CHARS*/
#define XT_CELLS 0x86ee /* CELLS*/
#define XT_CELL_2D 0x86e6 /* CELL-*/
#define XT_SM_2FREM 0x86c2 /* SM/REM*/
#define XT_DABS 0x86b4 /* DABS*/
#define XT_D0_3C 0x86ac /* D0<*/
#define XT__2A_2F 0x86a4 /* * /*/
#define XT__2A_2FMOD 0x8698 /* * /MOD*/
#define XT_M_2A 0x867c /* M**/
#define XT__2A 0x8674 /* **/
#define XT_UM_2A 0x863a /* UM**/
#define XT__2F 0x8632 /* /*/
#define XT_MOD 0x862a /* MOD*/
#define XT__2FMOD 0x861e /* /MOD*/
#define XT_FM_2FMOD 0x8618 /* FM/MOD*/
#define XT_M_2FMOD 0x85e2 /* M/MOD*/
#define XT_UM_2FMOD 0x8582 /* UM/MOD*/
#define XT_S_3ED 0x857a /* S>D*/
#define XT_WITHIN 0x856a /* WITHIN*/
#define XT_MIN 0x8558 /* MIN*/
#define XT_MAX 0x8548 /* MAX*/
#define XT__3E 0x8540 /* >*/
#define XT__3C 0x8528 /* <*/
#define XT_ud_3C 0x8510 /* ud<*/
#define XT_U_3E 0x8508 /* U>*/
#define XT_U_3C 0x84f0 /* U<*/
#define XT__3C_3E 0x84e0 /* <>*/
#define XT__3D 0x84d0 /* =*/
#define XT_C_2C 0x84c0 /* C,*/
#define XT_CHAR_2B 0x84ba /* CHAR+*/
#define XT_ABS 0x84b2 /* ABS*/
#define XT__3Fnegate 0x84a6 /* ?negate*/
#define XT_1_2D 0x849c /* 1-*/
#define XT__2D 0x8494 /* -*/
#define XT_DNEGATE 0x8480 /* DNEGATE*/
#define XT_NEGATE 0x8478 /* NEGATE*/
#define XT_1_2B 0x846e /* 1+*/
#define XT_INVERT 0x8464 /* INVERT*/
#define XT_D_2B 0x8450 /* D+*/
#define XT_2SWAP 0x8444 /* 2SWAP*/
#define XT_2OVER 0x8432 /* 2OVER*/
#define XT_2DUP 0x842a /* 2DUP*/
#define XT__2DROT 0x841e /* -ROT*/
#define XT__3Ftest_5C 0x840e /* ?test\*/
#define XT__3Fsafe_5C 0x83fe /* ?safe\*/
#define XT__3F_5C 0x83f2 /* ?\*/
#define XT_D0_3D 0x83ea /* D0=*/
#define XT_0_3C_3E 0x83e2 /* 0<>*/
#define XT_0_3D 0x83d2 /* 0=*/
#define XT_ENDCASE 0x83c8 /* ENDCASE*/
#define XT_ENDOF 0x83b8 /* ENDOF*/
#define XT_OF 0x83ae /* OF*/
#define XT_CASE 0x83a8 /* CASE*/
#define XT__3ERESOLVETHREAD 0x8392 /* >RESOLVETHREAD*/
#define XT__3EMARKTHREAD 0x8388 /* >MARKTHREAD*/
#define XT__3EMARKSTART 0x8380 /* >MARKSTART*/
#define XT__3ERESOLVES 0x8370 /* >RESOLVES*/
#define XT__3FDUP 0x8364 /* ?DUP*/
#define XT_WHILE 0x835c /* WHILE*/
#define XT_WHEN 0x8354 /* WHEN*/
#define XT_ELSE 0x834a /* ELSE*/
#define XT_AFT 0x833e /* AFT*/
#define XT_THEN 0x8338 /* THEN*/
#define XT_REPEAT 0x8330 /* REPEAT*/
#define XT_AHEAD 0x8326 /* AHEAD*/
#define XT_IF 0x831c /* IF*/
#define XT_AGAIN 0x8312 /* AGAIN*/
#define XT_UNTIL 0x8308 /* UNTIL*/
#define XT_NEXT 0x82fe /* NEXT*/
#define XT_BEGIN 0x82f8 /* BEGIN*/
#define XT_FOR 0x82ee /* FOR*/
#define XT__3ERESOLVE 0x82e4 /* >RESOLVE*/
#define XT__3EMARK 0x82d8 /* >MARK*/
#define XT__3CRESOLVE 0x82d2 /* <RESOLVE*/
#define XT__3CMARK 0x82cc /* <MARK*/
#define XT_CREATE 0x82c4 /* CREATE*/
#define XT_create 0x82b2 /* create*/
#define XT_LITERAL 0x82a8 /* LITERAL*/
#define XT_COMPILE 0x8298 /* COMPILE*/
#define XT__5BCOMPILE_5D 0x8290 /* [COMPILE]*/
#define XT_COMPILE_2C 0x828a /* COMPILE,*/
#define XT__2C 0x8278 /* ,*/
#define XT_CELL_2B 0x8270 /* CELL+*/
#define XT__2B 0x8268 /* +*/
#define XT_HERE 0x8260 /* HERE*/
#define XT_TUCK 0x8258 /* TUCK*/
#define XT_NIP 0x8250 /* NIP*/
#define XT__5C 0x8244 /* \*/
#define XT_IMMEDIATE 0x823c /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x8234 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x8222 /* setHeaderBits*/
#define XT_2DROP 0x821a /* 2DROP*/
#define XT_testDepth 0x8216 /* testDepth*/
#define XT_testFlags 0x8212 /* testFlags*/
#define XT_source_2Did 0x820e /* source-id*/
#define XT_VP 0x820a /* VP*/
#define XT_LAST 0x8206 /* LAST*/
#define XT_NP 0x8202 /* NP*/
#define XT_CP 0x81fe /* CP*/
#define XT_CURRENT 0x81fa /* CURRENT*/
#define XT_CONTEXT 0x81f6 /* CONTEXT*/
#define XT_HANDLER 0x81f2 /* HANDLER*/
#define XT_HLD 0x81ee /* HLD*/
#define XT_SPARE2 0x81ea /* SPARE2*/
#define XT_STATE 0x81e6 /* STATE*/
#define XT_CSP 0x81e2 /* CSP*/
#define XT__23TIB 0x81de /* #TIB*/
#define XT__3EIN 0x81da /* >IN*/
#define XT_SPAN 0x81d6 /* SPAN*/
#define XT_temp 0x81d2 /* temp*/
#define XT_BASE 0x81ce /* BASE*/
#define XT__27PROMPT 0x81ca /* 'PROMPT*/
#define XT__27ECHO 0x81c6 /* 'ECHO*/
#define XT__27TAP 0x81c2 /* 'TAP*/
#define XT_SPARE 0x81be /* SPARE*/
#define XT__27EMIT 0x81ba /* 'EMIT*/
#define XT__27_3FKEY 0x81b6 /* '?KEY*/
#define XT_RP0 0x81b2 /* RP0*/
#define XT_SP0 0x81ae /* SP0*/
#define XT__5FUSER 0x81aa /* _USER*/
#define XT__2D_3E 0x81a6 /* ->*/
#define XT__7DT 0x81a0 /* }T*/
#define XT_DEPTH 0x819a /* DEPTH*/
#define XT_T_7B 0x8194 /* T{*/
#define XT__28of_29 0x8190 /* (of)*/
#define XT_DEFER 0x818c /* DEFER*/
#define XT__3EBODY 0x8188 /* >BODY*/
#define XT_ALIGN 0x8186 /* ALIGN*/
#define XT_immediate_3F 0x8184 /* immediate?*/
#define XT_2RDrop 0x8182 /* 2RDrop*/
#define XT_RDrop 0x8180 /* RDrop*/
#define XT_I 0x817e /* I*/
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
#define XT__28next_29 0x80f2 /* (next)*/
#define XT_DOES_3E 0x80f0 /* DOES>*/
#define XT__28literal_29 0x80ee /* (literal)*/
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
#define F_literal 20
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
#define F_I 70
#define F_RDrop 71
#define F_TwoRDrop 72
#define F_immediateQ 73
#define F_vpAlign 74
#define F_toBODY 75
#define F_DEFER 76
#define F_of 77
#define F_Tbrace 78
#define F_DEPTH 79
#define F_Tunbrace 80
#define F_Tarrow 81
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
extern void literal();
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
extern void I();
extern void RDrop();
extern void TwoRDrop();
extern void immediateQ();
extern void vpAlign();
extern void toBODY();
extern void of();
void (* const f[FUNCTIONSLENGTH])() = {
 /* 0 */0, tokenVocabulary, tokenNextVal, tokenDoList, 
 /* 4 */tokenUser, tokenVar, tokenCreate, tokenDefer, 
 /* 8 */tokenValue, ALIGNED, /* FIND-NAME-IN */ findNameIn, 0, 
 /* 12 */0, ms, BYE, EXIT, 
 /* 16 */EXECUTE, /* ?RX */ QRX, /* TX! */ TXstore, /* !IO */ storeIO, 
 /* 20 *//* (literal) */ literal, /* DOES> */ DOES, /* (next) */ next, /* ?branch */ qBranch, 
 /* 24 */branch, /* ! */ store, /* @ */ fetch, /* C@ */ CFetch, 
 /* 28 *//* C! */ CStore, /* RP@ */ RPat, /* RP! */ RPStore, /* R> */ Rfrom, 
 /* 32 *//* R@ */ Rat, /* >R */ toR, /* 2R> */ TwoRfrom, /* 2R@ */ TwoRFetch, 
 /* 36 *//* 2>R */ TwotoR, /* SP@ */ SPat, /* SP! */ SPbang, DROP, 
 /* 40 */DUP, SWAP, OVER, ROLL, 
 /* 44 */ROT, /* 0< */ zeroLess, AND, OR, 
 /* 48 */XOR, /* UM+ */ UMplus, RSHIFT, LSHIFT, 
 /* 52 *//* 2/ */ TwoDiv, userAreaInit, userAreaSave, 0, 
 /* 56 */0, 0, 0, 0, 
 /* 60 */0, 0, 0, 0, 
 /* 64 */0, 0, debugNA, Fbreak, 
 /* 68 */stringBuffer, TYPE, I, RDrop, 
 /* 72 *//* 2RDrop */ TwoRDrop, /* immediate? */ immediateQ, /* ALIGN */ vpAlign, /* >BODY */ toBODY, 
 /* 76 */0, /* (of) */ of, 0, 0, 
 /* 80 */0, 0,  0 };
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
/* 0x80d6: OVERT */ F_tokenDefer, 0x938e, 0xc, 
/* 0x80dc: $,n */ F_tokenDefer, 0x931c, 
/* 0x80e0: ms */ F_ms, 
/* 0x80e2: BYE */ F_BYE, 
/* 0x80e4: EXIT */ F_EXIT, 
/* 0x80e6: EXECUTE */ F_EXECUTE, 
/* 0x80e8: ?RX */ F_QRX, 
/* 0x80ea: TX! */ F_TXstore, 
/* 0x80ec: !IO */ F_storeIO, 
/* 0x80ee: (literal) */ F_literal, 
/* 0x80f0: DOES> */ F_DOES, 
/* 0x80f2: (next) */ F_next, 
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
/* 0x8136: PARSE */ F_tokenDefer, 0x8be8, 0x38, 
/* 0x813c: ( */ F_tokenDefer, 0x9836, 0x39, 
/* 0x8142: TOKEN */ F_tokenDefer, 0x8c72, 0x3a, 
/* 0x8148: NUMBER? */ F_tokenDefer, 0x95fa, 0x3b, 
/* 0x814e: $COMPILE */ F_tokenDefer, 0x9338, 0x3c, 
/* 0x8154: $INTERPRET */ F_tokenDefer, 0x91d4, 0x3d, 
/* 0x815a: [ */ F_tokenDefer, 0x9230, 0x3e, 
/* 0x8160: ] */ F_tokenDefer, 0x93c6, 0x3f, 
/* 0x8166: : */ F_tokenDefer, 0x93d0, 0x40, 
/* 0x816c: ; */ F_tokenDefer, 0x93ba, 0x41, 
/* 0x8172: ' */ F_tokenDefer, 0x9284, 
/* 0x8176: debugNA */ F_debugNA, 
/* 0x8178: Fbreak */ F_Fbreak, 
/* 0x817a: stringBuffer */ F_stringBuffer, 
/* 0x817c: TYPE */ F_TYPE, 
/* 0x817e: I */ F_I, 
/* 0x8180: RDrop */ F_RDrop, 
/* 0x8182: 2RDrop */ F_TwoRDrop, 
/* 0x8184: immediate? */ F_immediateQ, 
/* 0x8186: ALIGN */ F_vpAlign, 
/* 0x8188: >BODY */ F_toBODY, 0x4c, 
/* 0x818c: DEFER */ F_tokenDefer, 0x93de, 
/* 0x8190: (of) */ F_of, 0x4e, 
/* 0x8194: T{ */ F_tokenDefer, 0x8192, 0x4f, 
/* 0x819a: DEPTH */ F_tokenDefer, 0x8786, 0x50, 
/* 0x81a0: }T */ F_tokenDefer, 0x819e, 0x51, 
/* 0x81a6: -> */ F_tokenDefer, 0x81a4, 
/* 0x81aa: _USER */ F_tokenUser, 0, 
/* 0x81ae: SP0 */ F_tokenUser, 4, 
/* 0x81b2: RP0 */ F_tokenUser, 5, 
/* 0x81b6: '?KEY */ F_tokenUser, 6, 
/* 0x81ba: 'EMIT */ F_tokenUser, 7, 
/* 0x81be: SPARE */ F_tokenUser, 8, 
/* 0x81c2: 'TAP */ F_tokenUser, 9, 
/* 0x81c6: 'ECHO */ F_tokenUser, 0xa, 
/* 0x81ca: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x81ce: BASE */ F_tokenUser, 0xc, 
/* 0x81d2: temp */ F_tokenUser, 0xd, 
/* 0x81d6: SPAN */ F_tokenUser, 0xe, 
/* 0x81da: >IN */ F_tokenUser, 0xf, 
/* 0x81de: #TIB */ F_tokenUser, 0x10, 
/* 0x81e2: CSP */ F_tokenUser, 0x12, 
/* 0x81e6: STATE */ F_tokenUser, 0x13, 
/* 0x81ea: SPARE2 */ F_tokenUser, 0x14, 
/* 0x81ee: HLD */ F_tokenUser, 0x15, 
/* 0x81f2: HANDLER */ F_tokenUser, 0x16, 
/* 0x81f6: CONTEXT */ F_tokenUser, 0x17, 
/* 0x81fa: CURRENT */ F_tokenUser, 0x20, 
/* 0x81fe: CP */ F_tokenUser, 0x22, 
/* 0x8202: NP */ F_tokenUser, 0x23, 
/* 0x8206: LAST */ F_tokenUser, 0x24, 
/* 0x820a: VP */ F_tokenUser, 0x25, 
/* 0x820e: source-id */ F_tokenUser, 0x26, 
/* 0x8212: testFlags */ F_tokenUser, 0x27, 
/* 0x8216: testDepth */ F_tokenUser, 0x28, 
/* 0x821a: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x8222: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x8234: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x823c: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x8244: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x8250: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x8258: TUCK */ F_tokenDoList, XT_SWAP, XT_OVER, XT_EXIT, 
/* 0x8260: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x8268: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x8270: CELL+ */ F_tokenDoList, XT_CELLL, XT__2B, XT_EXIT, 
/* 0x8278: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x828a: COMPILE, */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x8290: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x8298: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x82a8: LITERAL */ F_tokenDoList, XT_COMPILE, XT__28literal_29, XT__2C, XT_EXIT, 
/* 0x82b2: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT__28literal_29, 0, XT__2C, XT_EXIT, 
/* 0x82c4: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x82cc: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x82d2: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x82d8: >MARK */ F_tokenDoList, XT_HERE, XT__28literal_29, 0, XT__2C, XT_EXIT, 
/* 0x82e4: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x82ee: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x82f8: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x82fe: NEXT */ F_tokenDoList, XT_COMPILE, XT__28next_29, XT__3CRESOLVE, XT_EXIT, 
/* 0x8308: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x8312: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x831c: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x8326: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x8330: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x8338: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x833e: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x834a: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x8354: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x835c: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x8364: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0xa, XT_DUP, XT_EXIT, 
/* 0x8370: >RESOLVES */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVES + 0xe, XT__3ERESOLVE, XT_branch, XT__3ERESOLVES + 2, XT_EXIT, 
/* 0x8380: >MARKSTART */ F_tokenDoList, XT__28literal_29, 0, XT_EXIT, 
/* 0x8388: >MARKTHREAD */ F_tokenDoList, XT_HERE, XT_SWAP, XT__2C, XT_EXIT, 
/* 0x8392: >RESOLVETHREAD */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVETHREAD + 0x14, XT_DUP, XT__40, XT_SWAP, XT__3ERESOLVE, XT_branch, XT__3ERESOLVETHREAD + 2, XT_EXIT, 
/* 0x83a8: CASE */ F_tokenDoList, XT__3EMARKSTART, XT_EXIT, 
/* 0x83ae: OF */ F_tokenDoList, XT_COMPILE, XT__28of_29, XT__3EMARK, XT_EXIT, 
/* 0x83b8: ENDOF */ F_tokenDoList, XT_COMPILE, XT_branch, XT_SWAP, XT__3EMARKTHREAD, XT_SWAP, XT__3ERESOLVE, XT_EXIT, 
/* 0x83c8: ENDCASE */ F_tokenDoList, XT_COMPILE, XT_DROP, XT__3ERESOLVETHREAD, XT_EXIT, 
/* 0x83d2: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0xc, XT_FALSE, XT_branch, XT_0_3D + 0xe, XT_TRUE, XT_EXIT, 
/* 0x83e2: 0<> */ F_tokenDoList, XT_0_3D, XT_0_3D, XT_EXIT, 
/* 0x83ea: D0= */ F_tokenDoList, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x83f2: ?\ */ F_tokenDoList, XT_0_3D, XT__3Fbranch, XT__3F_5C + 0xa, XT__5C, XT_EXIT, 
/* 0x83fe: ?safe\ */ F_tokenDoList, XT_testFlags, XT__40, XT__28literal_29, 4, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x840e: ?test\ */ F_tokenDoList, XT_testFlags, XT__40, XT__28literal_29, 8, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x841e: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x842a: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x8432: 2OVER */ F_tokenDoList, XT__3ER, XT__3ER, XT_2DUP, XT_R_3E, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8444: 2SWAP */ F_tokenDoList, XT__3ER, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x8450: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x8464: INVERT */ F_tokenDoList, XT__28literal_29, 0xffff, XT_XOR, XT_EXIT, 
/* 0x846e: 1+ */ F_tokenDoList, XT__28literal_29, 1, XT__2B, XT_EXIT, 
/* 0x8478: NEGATE */ F_tokenDoList, XT_INVERT, XT_1_2B, XT_EXIT, 
/* 0x8480: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT__28literal_29, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8494: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x849c: 1- */ F_tokenDoList, XT__28literal_29, 1, XT__2D, XT_EXIT, 
/* 0x84a6: ?negate */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT__3Fnegate + 0xa, XT_NEGATE, XT_EXIT, 
/* 0x84b2: ABS */ F_tokenDoList, XT_DUP, XT__3Fnegate, XT_EXIT, 
/* 0x84ba: CHAR+ */ F_tokenDoList, XT_1_2B, XT_EXIT, 
/* 0x84c0: C, */ F_tokenDoList, XT_HERE, XT_DUP, XT_CHAR_2B, XT_CP, XT__21, XT_C_21, XT_EXIT, 
/* 0x84d0: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0xc, XT_FALSE, XT_EXIT, XT_TRUE, XT_EXIT, 
/* 0x84e0: <> */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3C_3E + 0xc, XT_TRUE, XT_EXIT, XT_FALSE, XT_EXIT, 
/* 0x84f0: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x12, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x8508: U> */ F_tokenDoList, XT_SWAP, XT_U_3C, XT_EXIT, 
/* 0x8510: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x14, XT_2DROP, XT_TRUE, XT_branch, XT_ud_3C + 0x16, XT_U_3C, XT_EXIT, 
/* 0x8528: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x12, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x8540: > */ F_tokenDoList, XT_SWAP, XT__3C, XT_EXIT, 
/* 0x8548: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0xc, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x8558: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0xe, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x856a: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x857a: S>D */ F_tokenDoList, XT_DUP, XT_0_3C, XT_EXIT, 
/* 0x8582: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0x54, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x4a, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x46, XT__3ER, XT_DROP, XT_1_2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x48, XT_DROP, XT_R_3E, XT__28next_29, XT_UM_2FMOD + 0x14, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT__28literal_29, 0xffff, XT_DUP, XT_EXIT, 
/* 0x85e2: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x16, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x24, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x34, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x8618: FM/MOD */ F_tokenDoList, XT_M_2FMOD, XT_EXIT, 
/* 0x861e: /MOD */ F_tokenDoList, XT__3ER, XT_S_3ED, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x862a: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x8632: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x863a: UM* */ F_tokenDoList, XT__28literal_29, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x30, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x30, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT__28next_29, XT_UM_2A + 0x10, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x8674: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x867c: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x1a, XT_DNEGATE, XT_EXIT, 
/* 0x8698: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x86a4: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x86ac: D0< */ F_tokenDoList, XT_NIP, XT_0_3C, XT_EXIT, 
/* 0x86b4: DABS */ F_tokenDoList, XT_2DUP, XT_D0_3C, XT__3Fbranch, XT_DABS + 0xc, XT_DNEGATE, XT_EXIT, 
/* 0x86c2: SM/REM */ F_tokenDoList, XT_2DUP, XT_XOR, XT__3ER, XT_OVER, XT__3ER, XT_ABS, XT__3ER, XT_DABS, XT_R_3E, XT_UM_2FMOD, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_EXIT, 
/* 0x86e6: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x86ee: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x86f6: CHARS */ F_tokenDoList, XT_EXIT, 
/* 0x86fa: 2* */ F_tokenDoList, XT__28literal_29, 2, XT__2A, XT_EXIT, 
/* 0x8704: ($,n) */ F_tokenDoList, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_DUP, XT_CP, XT__21, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, 
/* 0x8730: :NONAME */ F_tokenDoList, XT_NP, XT__40, XT_CELL_2D, XT__28literal_29, 0, XT_OVER, XT__21, XT_DUP, XT_NP, XT__21, XT__28_24_2Cn_29, XT_HERE, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x8752: DEFER@ */ F_tokenDoList, XT__3EBODY, XT__40, XT_EXIT, 
/* 0x875a: >BODY! */ F_tokenDoList, XT__3EBODY, XT__21, XT_EXIT, 
/* 0x8762: DEFER! */ F_tokenDoList, XT__3EBODY_21, XT_EXIT, 
/* 0x8768: >CHAR */ F_tokenDoList, XT__28literal_29, 0x7f, XT_AND, XT_DUP, XT__28literal_29, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x1c, XT_DROP, XT__28literal_29, 0x5f, XT_EXIT, 
/* 0x8786:  */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x8798: PICK */ F_tokenDoList, XT_1_2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x87a6: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x87b6: ++ */ F_tokenDoList, XT__28literal_29, 1, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87c2: -- */ F_tokenDoList, XT__28literal_29, 0xffff, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x87ce: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x87dc: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x87ea: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0xe, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x87fc: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x1c, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x1e, XT__2C, XT_EXIT, 
/* 0x881c: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x882a: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x18, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x1a, XT_CREATE, XT_EXIT, 
/* 0x8846: PAD */ F_tokenDoList, XT_HERE, XT__28literal_29, 0x50, XT__2B, XT_EXIT, 
/* 0x8852: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x885c: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0xc, XT_EXECUTE, XT_EXIT, 
/* 0x886a: COUNT */ F_tokenDoList, XT_DUP, XT_1_2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x8876: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x18, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2B, XT_R_3E, XT_1_2B, XT__28next_29, XT_CMOVE + 8, XT_2DROP, XT_EXIT, 
/* 0x8896: CMOVE> */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_R_3E, XT__3ER, XT_branch, XT_CMOVE_3E + 0x2c, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2D, XT_R_3E, XT_1_2D, XT__28next_29, XT_CMOVE_3E + 0x1c, XT_2DROP, XT_EXIT, 
/* 0x88ca: MOVE */ F_tokenDoList, XT__3ER, XT_2DUP, XT__3E, XT_R_3E, XT_SWAP, XT__3Fbranch, XT_MOVE + 0x16, XT_CMOVE, XT_branch, XT_MOVE + 0x18, XT_CMOVE_3E, XT_EXIT, 
/* 0x88e4: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x12, XT_2DUP, XT_C_21, XT_1_2B, XT__28next_29, XT_FILL + 0xc, XT_2DROP, XT_EXIT, 
/* 0x88fe: ERASE */ F_tokenDoList, XT__28literal_29, 0, XT_FILL, XT_EXIT, 
/* 0x8908: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x1e, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x1e, XT_R_3E, XT_1_2B, XT_EXIT, XT__28next_29, XT__2DTRAILING + 8, XT__28literal_29, 0, XT_EXIT, 
/* 0x8930: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT__28literal_29, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT__28literal_29, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_1_2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x8962: DIGIT */ F_tokenDoList, XT__28literal_29, 9, XT_OVER, XT__3C, XT__28literal_29, 7, XT_AND, XT__2B, XT__28literal_29, 0x30, XT__2B, XT_EXIT, 
/* 0x897c: EXTRACT */ F_tokenDoList, XT__3ER, XT__28literal_29, 0, XT_R_40, XT_FM_2FMOD, XT_R_3E, XT_SWAP, XT__3ER, XT_FM_2FMOD, XT_R_3E, XT_ROT, XT_DIGIT, XT_EXIT, 
/* 0x8998: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x89a2: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_1_2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x89b4: HOLDS */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_HOLDS + 0x16, XT_1_2D, XT_2DUP, XT__2B, XT_C_40, XT_HOLD, XT_branch, XT_HOLDS + 2, XT_2DROP, XT_EXIT, 
/* 0x89ce: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x89da: #S */ F_tokenDoList, XT__23, XT_2DUP, XT_OR, XT__3Fbranch, XT__23S + 0x10, XT_branch, XT__23S + 2, XT_EXIT, 
/* 0x89ec: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0xe, XT__28literal_29, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x89fc: #> */ F_tokenDoList, XT_2DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8a0c: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x8a14: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x8a1c: emits */ F_tokenDoList, XT_SWAP, XT__28literal_29, 0, XT_MAX, XT__3ER, XT_branch, XT_emits + 0x14, XT_DUP, XT_EMIT, XT__28next_29, XT_emits + 0x10, XT_DROP, XT_EXIT, 
/* 0x8a38: SPACES */ F_tokenDoList, XT_BL, XT_emits, XT_EXIT, 
/* 0x8a40: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x8a48: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__28literal_29, 0, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x8a60: HEX */ F_tokenDoList, XT__28literal_29, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a6c: DECIMAL */ F_tokenDoList, XT__28literal_29, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x8a78: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8a8a: U.R */ F_tokenDoList, XT__3ER, XT__28literal_29, 0, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x8aa4: U. */ F_tokenDoList, XT__28literal_29, 0, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8ab6: . */ F_tokenDoList, XT_BASE, XT__40, XT__28literal_29, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x14, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x8ad2: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x8ada: DIGIT? */ F_tokenDoList, XT__3ER, XT__28literal_29, 0x30, XT__2D, XT__28literal_29, 0x2a, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x1c, XT__28literal_29, 0x20, XT__2D, XT__28literal_29, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x38, XT__28literal_29, 7, XT__2D, XT_DUP, XT__28literal_29, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x8b1a: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x8b22: KEY */ F_tokenDoList, XT__28literal_29, 0, XT_ms, XT__28literal_29, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 6, XT_NIP, XT_EXIT, 
/* 0x8b38: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x14, XT_2DROP, XT_KEY, XT__28literal_29, 0xd, XT__3D, XT_EXIT, 
/* 0x8b4e: PACE */ F_tokenDoList, XT__28literal_29, 0xb, XT_EMIT, XT_EXIT, 
/* 0x8b58: CR */ F_tokenDoList, XT__28literal_29, 0xd, XT_EMIT, XT__28literal_29, 0xa, XT_EMIT, XT_EXIT, 
/* 0x8b68: ['] */ F_tokenDoList, XT__27, XT_LITERAL, XT_EXIT, 
/* 0x8b70: SOURCE */ F_tokenDoList, XT_TIB, XT__23TIB, XT__40, XT_EXIT, 
/* 0x8b7a: /STRING */ F_tokenDoList, XT_TUCK, XT__2D, XT__3ER, XT__2B, XT_R_3E, XT_EXIT, 
/* 0x8b88: isspace? */ F_tokenDoList, XT_BL, XT_1_2B, XT_U_3C, XT_EXIT, 
/* 0x8b92: isnotspace? */ F_tokenDoList, XT_isspace_3F, XT_0_3D, XT_EXIT, 
/* 0x8b9a: xt-skip */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT_OVER, XT_C_40, XT_R_40, XT_EXECUTE, XT__3Fbranch, XT_xt_2Dskip + 0x20, XT__28literal_29, 1, XT__2FSTRING, XT_branch, XT_xt_2Dskip + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8bc0: skip-till */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT_OVER, XT_C_40, XT_R_40, XT__3D, XT_0_3D, XT__3Fbranch, XT_skip_2Dtill + 0x22, XT__28literal_29, 1, XT__2FSTRING, XT_branch, XT_skip_2Dtill + 4, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x8be8:  */ F_tokenDoList, XT__3ER, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c04, XT__28literal_29, XT_isspace_3F, XT_xt_2Dskip, XT_OVER, XT_SWAP, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x8c1c, XT__28literal_29, XT_isnotspace_3F, XT_xt_2Dskip, XT_branch, 0x8c20, XT_R_40, XT_skip_2Dtill, XT_R_3E, XT_DROP, XT_2DUP, XT__28literal_29, 1, XT_MIN, XT__2B, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x8c40: PARSE-NAME */ F_tokenDoList, XT_BL, XT_PARSE, XT_EXIT, 
/* 0x8c48: CHAR */ F_tokenDoList, XT_PARSE_2DNAME, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x8c52: [CHAR] */ F_tokenDoList, XT_CHAR, XT_LITERAL, XT_EXIT, 
/* 0x8c5a: CTRL */ F_tokenDoList, XT_CHAR, XT__28literal_29, 0x1f, XT_AND, XT_EXIT, 
/* 0x8c66: .( */ F_tokenDoList, XT__28literal_29, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x8c72:  */ F_tokenDoList, XT_PARSE_2DNAME, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x8c8a: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x8c94: NAME>INTERPRET */ F_tokenDoList, XT__28literal_29, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x8ca2: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x2a, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x2a, XT_R_3E, XT_DROP, XT_EXIT, XT__28next_29, XT_SAME_3F + 8, XT_FALSE, XT_EXIT, 
/* 0x8cd4: FIND-NAME */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_FIND_2DNAME + 0x10, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT__3ER, XT_R_40, XT__40, XT__3Fbranch, XT_FIND_2DNAME + 0x38, XT_2DUP, XT_R_40, XT__40, XT_FIND_2DNAME_2DIN, XT__3FDUP, XT__3Fbranch, XT_FIND_2DNAME + 0x12, XT_R_3E, XT_DROP, XT_NIP, XT_NIP, XT_EXIT, XT_R_3E, XT_DROP, XT_2DROP, XT_FALSE, XT_EXIT, 
/* 0x8d16: NAME? */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x1a, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_branch, XT_NAME_3F + 0x1c, XT_FALSE, XT_EXIT, 
/* 0x8d34: FIND */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_FIND + 0x2c, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_immediate_3F, XT__3Fbranch, XT_FIND + 0x24, XT__28literal_29, 1, XT_branch, XT_FIND + 0x28, XT__28literal_29, 0xffff, XT_branch, XT_FIND + 0x30, XT__28literal_29, 0, XT_EXIT, 
/* 0x8d66: MARKER */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT_CONTEXT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CURRENT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CREATE, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT_DOES_3E, XT_DUP, XT__40, XT_CURRENT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CURRENT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CP, XT__21, XT_CELL_2B, XT__40, XT_NP, XT__21, XT_EXIT, 
/* 0x8dd2: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT__28literal_29, 0, XT_EXIT, 
/* 0x8df6: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x20, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x8e18: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x26, XT__28literal_29, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT__28literal_29, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x8e44: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8e54: crlf? */ F_tokenDoList, XT_DUP, XT__28literal_29, 0xa, XT__3D, XT_SWAP, XT__28literal_29, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x8e6a: skipCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipCRLF + 0x12, XT_OVER, XT_C_40, XT_crlf_3F, XT_branch, XT_skipCRLF + 0x14, XT_FALSE, XT__3Fbranch, XT_skipCRLF + 0x24, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipCRLF + 2, XT_EXIT, 
/* 0x8e90: skipToCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipToCRLF + 0x14, XT_OVER, XT_C_40, XT_crlf_3F, XT_0_3D, XT_branch, XT_skipToCRLF + 0x16, XT_FALSE, XT__3Fbranch, XT_skipToCRLF + 0x26, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipToCRLF + 2, XT_EXIT, 
/* 0x8eb8: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x30, XT_DUP, XT__28literal_29, 8, XT__3D, XT_SWAP, XT__28literal_29, 0x7f, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x2c, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x2e, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x8ef0: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x8f06: $," */ F_tokenDoList, XT__28literal_29, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x8f1a: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x8f20: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x8f28: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x8f30: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f3a: C" */ F_tokenDoList, XT__24_22, XT_EXIT, 
/* 0x8f40: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x8f4a: S" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_branch, XT_S_22 + 0x20, XT__28literal_29, 0x22, XT_PARSE, XT_stringBuffer, XT_PACK_24, XT_COUNT, XT_EXIT, 
/* 0x8f6c: bu+@ */ F_tokenDoList, XT_1_2D, XT__3ER, XT_COUNT, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x8f7a: c+! */ F_tokenDoList, XT_TUCK, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x8f84: cmove\ */ F_tokenDoList, XT_SWAP, XT_DUP, XT__3ER, XT__3ER, XT__3FDUP, XT__3Fbranch, 0x90ee, XT_bu_2B_40, XT_DUP, XT__28literal_29, 0x22, XT__3C_3E, XT__3Fbranch, 0x90ec, XT__28literal_29, 0x5c, XT__28of_29, 0x90de, XT_bu_2B_40, XT__28literal_29, 0x6d, XT__28of_29, XT_cmove_5C + 0x46, XT__28literal_29, 0xd, XT_R_3E, XT_c_2B_21, XT__28literal_29, 0xa, XT_SWAP, XT_c_2B_21, XT__3ER, XT_branch, 0x90da, XT__28literal_29, 0x78, XT__28of_29, XT_cmove_5C + 0x78, XT_bu_2B_40, XT__28literal_29, 0x10, XT_DIGIT_3F, XT_DROP, XT__28literal_29, 0x10, XT__2A, XT__3ER, XT_bu_2B_40, XT__28literal_29, 0x10, XT_DIGIT_3F, XT_DROP, XT_R_3E, XT__2B, XT_R_3E, XT_c_2B_21, XT__3ER, XT_branch, 0x90da, XT__28literal_29, 0x61, XT__28of_29, XT_cmove_5C + 0x88, XT__28literal_29, 7, XT_branch, 0x90d0, XT__28literal_29, 0x62, XT__28of_29, XT_cmove_5C + 0x98, XT__28literal_29, 8, XT_branch, 0x90d0, XT__28literal_29, 0x65, XT__28of_29, XT_cmove_5C + 0xa8, XT__28literal_29, 0x1b, XT_branch, 0x90d0, XT__28literal_29, 0x66, XT__28of_29, XT_cmove_5C + 0xb8, XT__28literal_29, 0xc, XT_branch, 0x90d0, XT__28literal_29, 0x6c, XT__28of_29, XT_cmove_5C + 0xc8, XT__28literal_29, 0xa, XT_branch, 0x90d0, XT__28literal_29, 0x6e, XT__28of_29, XT_cmove_5C + 0xd8, XT__28literal_29, 0xa, XT_branch, 0x90d0, XT__28literal_29, 0x71, XT__28of_29, XT_cmove_5C + 0xe8, XT__28literal_29, 0x22, XT_branch, 0x90d0, XT__28literal_29, 0x72, XT__28of_29, XT_cmove_5C + 0xf8, XT__28literal_29, 0xd, XT_branch, 0x90d0, XT__28literal_29, 0x74, XT__28of_29, 0x908c, XT__28literal_29, 9, XT_branch, 0x90d0, XT__28literal_29, 0x76, XT__28of_29, 0x909c, XT__28literal_29, 0xb, XT_branch, 0x90d0, XT__28literal_29, 0x7a, XT__28of_29, 0x90ac, XT__28literal_29, 0, XT_branch, 0x90d0, XT__28literal_29, 0x22, XT__28of_29, 0x90bc, XT__28literal_29, 0x22, XT_branch, 0x90d0, XT__28literal_29, 0x5c, XT__28of_29, 0x90cc, XT__28literal_29, 0x5c, XT_branch, 0x90d0, XT_DUP, XT_DROP, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, 0x90e8, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, XT_cmove_5C + 0xa, XT_2DROP, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x90f6: pack\$ */ F_tokenDoList, XT_ALIGNED, XT__3ER, XT_R_40, XT_1_2B, XT_SWAP, XT_cmove_5C, XT_DUP, XT_R_40, XT_C_21, XT_DUP, XT_R_40, XT__2B, XT_1_2B, XT_SWAP, XT__28literal_29, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__3FDUP, XT__3Fbranch, XT_pack_5C_24 + 0x42, XT_SWAP, XT__28literal_29, 0, XT_OVER, XT_C_21, XT_1_2B, XT_SWAP, XT_1_2D, XT_branch, XT_pack_5C_24 + 0x28, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x913e: S\" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x14, XT_COMPILE, XT_S_22_7C, XT_HERE, XT_branch, XT_S_5C_22 + 0x16, XT_stringBuffer, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_ROT, XT_pack_5C_24, XT_SWAP, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_COUNT, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x40, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x9180: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x9186: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x918e: (abort") */ F_tokenDoList, XT__3Fbranch, XT__28abort_22_29 + 0xa, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x919e: ABORT" */ F_tokenDoList, XT_COMPILE, XT__28abort_22_29, XT__24_2C_22, XT_EXIT, 
/* 0x91a8: POSTPONE */ F_tokenDoList, XT_TOKEN, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT_0_3D, XT__28abort_22_29, 0x4e09, 0x746f, 0x6620, 0x756f, 0x646e, XT_DUP, XT_immediate_3F, XT_0_3D, XT__3Fbranch, XT_POSTPONE + 0x26, XT_COMPILE, XT_COMPILE, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x91d4:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x91fa, XT_C_40, XT__28literal_29, 0x40, XT_AND, XT__28abort_22_29, 0x630c, 0x6d6f, 0x6970, 0x656c, 0x4f20, 0x4c4e, 0x59, XT_EXECUTE, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9202, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9206: .OK */ F_tokenDoList, XT_STATE, XT__40, XT_0_3D, XT__3Fbranch, XT__2EOK + 0x12, XT__2E_22_7C, 0x2003, 0x6b6f, XT_CR, XT_EXIT, 
/* 0x921c: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT__28abort_22_29, 0x7509, 0x646e, 0x7265, 0x6c66, 0x776f, XT_EXIT, 
/* 0x9230:  */ F_tokenDoList, XT_FALSE, XT_STATE, XT__21, XT_EXIT, 
/* 0x923a: XIO */ F_tokenDoList, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x924a: FILE */ F_tokenDoList, XT__28literal_29, 0, XT__28literal_29, XT_DROP, XT__28literal_29, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x925c: HAND */ F_tokenDoList, XT__28literal_29, XT__2EOK, XT__28literal_29, XT_EMIT, XT__28literal_29, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x926e: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x9276: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x9284:  */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, 0x9290, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9294: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x929c: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x12, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x14, XT_ALLOT, XT_EXIT, 
/* 0x92b2: BUFFER: */ F_tokenDoList, XT_CREATE, XT_vALLOT, XT_EXIT, 
/* 0x92ba: '>BODY! */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT__27_3EBODY_21 + 0x14, XT__5B_27_5D, XT_COMPILE, XT__3EBODY_21, XT_branch, XT__27_3EBODY_21 + 0x18, XT__27, XT__3EBODY_21, XT_EXIT, 
/* 0x92d4: IS */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x92da: ACTION-OF */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_ACTION_2DOF + 0x14, XT__5B_27_5D, XT_COMPILE, XT_DEFER_40, XT_branch, XT_ACTION_2DOF + 0x18, XT__27, XT_DEFER_40, XT_EXIT, 
/* 0x92f4: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x9300: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x18, XT__2E_22_7C, 0x2007, 0x6572, 0x6544, 0x2066, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x931c:  */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, 0x932c, XT__3FUNIQUE, XT__28_24_2Cn_29, XT_EXIT, XT__24_22_7C, 0x6e04, 0x6d61, 0x65, XT_THROW, XT_EXIT, 
/* 0x9338:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x9356, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, 0x9352, XT_EXECUTE, XT_branch, 0x9354, XT__2C, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x9360, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x9364: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x22, XT_STATE, XT__40, XT__3Fbranch, XT_EVAL + 0x1a, XT__24COMPILE, XT_branch, XT_EVAL + 0x1c, XT__24INTERPRET, XT__3FSTACK, XT_branch, XT_EVAL + 2, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x938e:  */ F_tokenDoList, XT_LAST, XT__40, XT_DUP, XT__40, XT__3Fbranch, 0x93a6, XT_CURRENT, XT__40, XT__21, XT_branch, 0x93b8, XT_DROP, XT_NP, XT__40, XT__28literal_29, 3, XT_CELLS, XT__2B, XT_NP, XT__21, XT_EXIT, 
/* 0x93ba:  */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 3, XT_TRUE, XT_STATE, XT__21, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDefer, XT__2C, XT__28literal_29, 0, XT__2C, XT_OVERT, XT_EXIT, 
/* 0x93f2: VALUE */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_HERE, XT_tokenValue, XT__2C, XT__5FUSER, XT__40, XT__2C, XT__5FUSER, XT__2B_2B, XT__3EBODY_21, XT_EXIT, 
/* 0x940e: TO */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x9414: VARIABLE */ F_tokenDoList, XT_vCREATE, XT__28literal_29, 0, XT_v_2C, XT_EXIT, 
/* 0x9420: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x9430: leave-ptr */ F_tokenVar, 0, 6, 
/* 0x9436: (?do) */ F_tokenDoList, XT_R_3E, XT__2DROT, XT_2DUP, XT_2_3ER, XT__3C_3E, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x9448: (loop) */ F_tokenDoList, XT_R_3E, XT_2R_3E, XT_1_2B, XT_2DUP, XT_2_3ER, XT__3D, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x945c: (+loop) */ F_tokenDoList, XT_R_3E, XT_SWAP, XT_2R_3E, XT__28literal_29, 2, XT_PICK, XT_OVER, XT__2B, XT_ROT, XT_DUP, XT__3ER, XT__2DROT, XT_DUP, XT__3ER, XT__28literal_29, 3, XT_PICK, XT_0_3C, XT__3Fbranch, XT__28_2Bloop_29 + 0x2c, XT_SWAP, XT_1_2B, XT_SWAP, XT_1_2B, XT_SWAP, XT_WITHIN, XT_NIP, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x949a: leave, */ F_tokenDoList, XT_HERE, XT_leave_2Dptr, XT__40, XT__2C, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x94aa: LEAVE */ F_tokenDoList, XT_COMPILE, XT_branch, XT_leave_2C, XT_EXIT, 
/* 0x94b4: UNLOOP */ F_tokenDoList, XT_COMPILE, XT_2RDrop, XT_EXIT, 
/* 0x94bc: DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT__28literal_29, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT_2_3ER, XT_HERE, XT_EXIT, 
/* 0x94d2: ?DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT__28literal_29, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT__28_3Fdo_29, XT_COMPILE, XT__3Fbranch, XT_leave_2C, XT_HERE, XT_EXIT, 
/* 0x94ee: some-loop */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__2C, XT_leave_2Dptr, XT__40, XT__3FDUP, XT__3Fbranch, XT_some_2Dloop + 0x24, XT_DUP, XT__40, XT__3ER, XT_HERE, XT_SWAP, XT__21, XT_R_3E, XT_branch, XT_some_2Dloop + 0xc, XT_UNLOOP, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x951a: LOOP */ F_tokenDoList, XT_COMPILE, XT__28loop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x9524: +LOOP */ F_tokenDoList, XT_COMPILE, XT__28_2Bloop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x952e: I-MAX */ F_tokenDoList, XT_RP_40, XT__28literal_29, 2, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x953e: J */ F_tokenDoList, XT_RP_40, XT__28literal_29, 3, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x954e: J-MAX */ F_tokenDoList, XT_RP_40, XT__28literal_29, 4, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x955e: accumulate */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_BASE, XT__40, XT_UM_2A, XT_DROP, XT_ROT, XT_BASE, XT__40, XT_UM_2A, XT_D_2B, XT_R_3E, XT_EXIT, 
/* 0x957c: >NUMBER */ F_tokenDoList, XT__28literal_29, 0, XT_SWAP, XT__28literal_29, 0, XT__28_3Fdo_29, XT__3Fbranch, XT__3ENUMBER + 0x3c, XT_DROP, XT_COUNT, XT_BASE, XT__40, XT_DIGIT_3F, XT_0_3D, XT__3Fbranch, XT__3ENUMBER + 0x30, XT_DROP, XT_1_2D, XT_I_2DMAX, XT_I, XT__2D, XT_branch, XT__3ENUMBER + 0x3c, XT_accumulate, XT__28literal_29, 0, XT__28loop_29, XT__3Fbranch, XT__3ENUMBER + 0x12, XT_2RDrop, XT_EXIT, 
/* 0x95bc: (charbase) */ F_tokenDoList, XT_DUP, XT__28literal_29, 0x23, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x14, XT__28literal_29, 0xa, XT_EXIT, XT_DUP, XT__28literal_29, 0x24, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x26, XT__28literal_29, 0x10, XT_EXIT, XT_DUP, XT__28literal_29, 0x25, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x38, XT__28literal_29, 2, XT_EXIT, XT__28literal_29, 0, XT_EXIT, 3, XT_DUP, XT_BASE, XT__40, XT__3ER, XT_COUNT, XT_OVER, XT__3ER, XT__3ER, XT_COUNT, XT__28charbase_29, XT__3FDUP, XT__3Fbranch, XT__28charbase_29 + 0x62, XT_BASE, XT__21, XT_DROP, XT_COUNT, XT_DUP, XT__28literal_29, 0x27, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x9a, XT_DROP, XT_COUNT, XT_SWAP, XT_COUNT, XT__28literal_29, 0x27, XT__3C_3E, XT__3Fbranch, XT__28charbase_29 + 0x8a, XT_2DROP, XT_2RDrop, XT_FALSE, XT_branch, XT__28charbase_29 + 0x92, XT_DROP, XT_NIP, XT_TRUE, XT_2RDrop, XT_R_3E, XT_BASE, XT__21, XT_EXIT, XT__28literal_29, 0x2d, XT__3D, XT_TUCK, XT_0_3D, XT__3Fbranch, XT__28charbase_29 + 0xaa, XT_1_2D, XT__28literal_29, 0, XT__28literal_29, 0, XT_ROT, XT_R_3E, XT_R_3E, XT__2B, XT_OVER, XT__2D, XT__3ENUMBER, XT__3Fbranch, XT__28charbase_29 + 0xce, XT_2DROP, XT_2DROP, XT_FALSE, XT_branch, XT__28charbase_29 + 0xde, XT_DROP, XT_ROT, XT__3Fbranch, XT__28charbase_29 + 0xd8, XT_DNEGATE, XT_DROP, XT_NIP, XT_TRUE, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x96a2: ACCEPT */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_ACCEPT + 0x30, XT_KEY, XT_DUP, XT_BL, XT__2D, XT__28literal_29, 0x5f, XT_U_3C, XT__3Fbranch, XT_ACCEPT + 0x28, XT_TAP, XT_branch, XT_ACCEPT + 0x2c, XT__27TAP, XT__40EXECUTE, XT_branch, XT_ACCEPT + 8, XT_DROP, XT_SWAP, XT__2D, XT_EXIT, 
/* 0x96da: stack */ F_tokenDoList, XT_CREATE, XT_HERE, XT__28literal_29, 0, XT__2C, XT_OVER, XT__2C, XT_vHERE, XT_SWAP, XT__21, XT__28literal_29, 0, XT_v_2C, XT_CELLS, XT_vALLOT, XT_EXIT, 
/* 0x96fc: spop */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_CELLS, XT_OVER, XT__2B, XT__40, XT_SWAP, XT__2D_2D, XT_EXIT, 
/* 0x9712: spush */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_1_2B, XT_2DUP, XT_SWAP, XT__21, XT_CELLS, XT__2B, XT__21, XT_EXIT, 
/* 0x972a: spushes */ F_tokenDoList, XT_OVER, XT__3ER, XT_SWAP, XT__28literal_29, 0, XT_2_3ER, XT_TUCK, XT_spush, XT__28loop_29, XT__3Fbranch, XT_spushes + 0xe, XT_2RDrop, XT_R_3E, XT_SWAP, XT_spush, XT_EXIT, 
/* 0x974c: spops */ F_tokenDoList, XT_DUP, XT_spop, XT__3ER, XT_R_40, XT__28literal_29, 0, XT_2_3ER, XT_DUP, XT_spop, XT_SWAP, XT__28loop_29, XT__3Fbranch, XT_spops + 0x10, XT_2RDrop, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x9770: sempty */ F_tokenDoList, XT__40, XT__28literal_29, 0, XT_SWAP, XT__21, XT_EXIT, 
/* 0x977e: SOURCE-ID */ F_tokenDoList, XT_source_2Did, XT__40, XT_EXIT, 
/* 0x9786: sourceStack */ F_tokenCreate, 0, 8, 0x20, 
/* 0x978e: 0> */ F_tokenDoList, XT_DUP, XT_0_3D, XT_SWAP, XT_0_3C, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x979e: unreadFile */ F_tokenDefer, 0, 
/* 0x97a2: SAVE-INPUT */ F_tokenDoList, XT_SOURCE_2DID, XT_SOURCE, XT__3EIN, XT__40, XT__28literal_29, 4, XT_EXIT, 
/* 0x97b2: sourcePush */ F_tokenDoList, XT_SAVE_2DINPUT, XT_sourceStack, XT_spushes, XT_EXIT, 
/* 0x97bc: RESTORE-INPUT */ F_tokenDoList, XT_DROP, XT__3EIN, XT__21, XT__23TIB, XT__21, XT__23TIB, XT_CELL_2B, XT__21, XT_DUP, XT_source_2Did, XT__21, XT__3Fbranch, XT_RESTORE_2DINPUT + 0x22, XT_FILE, XT_branch, XT_RESTORE_2DINPUT + 0x24, XT_HAND, XT__28literal_29, 0, XT_EXIT, 
/* 0x97e6: sourcePop */ F_tokenDoList, XT_sourceStack, XT_spops, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x97f2: READ-LINE */ F_tokenDefer, 0, 
/* 0x97f6: REFILL */ F_tokenDoList, XT_SOURCE_2DID, XT__3FDUP, XT__3Fbranch, XT_REFILL + 0x1a, XT_DROP, XT_FALSE, XT__28literal_29, 0, XT__3EIN, XT__21, XT_branch, XT_REFILL + 0x30, XT_TIB, XT__28literal_29, 0x50, XT_ACCEPT, XT__23TIB, XT__21, XT__28literal_29, 0, XT__3EIN, XT__21, XT_TRUE, XT_EXIT, 
/* 0x9828: QUERY */ F_tokenDoList, XT_REFILL, XT_0_3D, XT__3Fbranch, XT_QUERY + 0xc, XT_sourcePop, XT_EXIT, 3, XT__28literal_29, 0x29, XT_PARSE, XT__2B, XT_C_40, XT__28literal_29, 0x29, XT__3C_3E, XT__3Fbranch, XT_QUERY + 0x42, XT_REFILL, XT_0_3D, XT__28abort_22_29, 0x7514, 0x746e, 0x7265, 0x696d, 0x616e, 0x6574, 0x2064, 0x6f63, 0x6d6d, 0x6e65, 0x74, XT_QUERY + 0xe, XT_EXIT, 
/* 0x986c: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x9874: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_sourceStack, XT_sempty, XT__28literal_29, 0, XT_TIB0, XT__28literal_29, 0, XT__28literal_29, 0, XT__28literal_29, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x9898: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x2c, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT__28literal_29, 0x5e, XT_emits, XT_CR, XT__2E_24, XT__2E_22_7C, 0x2003, 0x203f, XT_PRESET, XT_EXIT, 
/* 0x98c8: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT__28literal_29, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0xa, XT__27PROMPT, XT__40, XT__3ER, XT_CONSOLE, XT_quitError, XT_R_3E, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x2c, XT__27PROMPT, XT__21, XT_branch, XT_QUIT + 8, XT_EXIT, 
/* 0x98fa: quit1 */ F_tokenDoList, XT__28literal_29, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x12, XT_quitError, XT__5B, XT_EXIT, 
/* 0x990e: EVALUATE */ F_tokenDoList, XT_sourcePush, XT__28literal_29, 0xffff, XT__2DROT, XT__28literal_29, 0, XT__28literal_29, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_quit1, XT_EXIT, 
/* 0x9928: dm+ */ F_tokenDoList, XT_OVER, XT__28literal_29, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x1e, XT_DUP, XT_C_40, XT__28literal_29, 3, XT_U_2ER, XT_1_2B, XT__28next_29, XT_dm_2B + 0x12, XT_EXIT, 
/* 0x994c: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT__28literal_29, 0x10, XT__2F, XT__3ER, XT_CR, XT__28literal_29, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT__28literal_29, 2, XT_SPACES, XT_TYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x36, XT__28next_29, XT_DUMP + 0x12, XT_branch, XT_DUMP + 0x3a, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x9990: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x12, XT_R_40, XT_PICK, XT__2E, XT__28next_29, XT__2ES + 0xc, XT__2E_22_7C, 0x2005, 0x733c, 0x2070, XT_EXIT, 
/* 0x99b0: UNUSED */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT__2D, XT_EXIT, 
/* 0x99be: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x99d0: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x99dc: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x99e6: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT__28abort_22_29, 0x730b, 0x6174, 0x6b63, 0x6420, 0x7065, 0x6874, XT_EXIT, 
/* 0x9a00: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x12, XT_COUNT, XT_BYTEMASK, XT_AND, XT_TYPE, XT_EXIT, XT__2E_22_7C, 0x7b08, 0x6f6e, 0x614e, 0x656d, 0x7d, XT_EXIT, 
/* 0x9a20: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x20, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 8, XT_DROP, XT_EXIT, 
/* 0x9a42: >NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 0x36, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT__3ENAME + 0x28, XT_2DUP, XT_NAME_3EINTERPRET, XT_XOR, XT__3Fbranch, XT__3ENAME + 0x28, XT_CELL_2D, XT_branch, XT__3ENAME + 0x10, XT_NIP, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 4, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_FALSE, XT_EXIT, 
/* 0x9a7e: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0x6a, XT__2E_22_7C, 0x3a02, 0x20, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x2c, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0x5a, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT__28literal_29, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT__28literal_29, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0x56, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0x60, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x1e, XT_branch, XT_SEE + 0x82, XT__2E_22_7C, 0x4e14, 0x746f, 0x6320, 0x6c6f, 0x6e6f, 0x6420, 0x6665, 0x6e69, 0x7469, 0x6f69, 0x6e, XT_DROP, XT_EXIT, 
/* 0x9b04: VER */ F_tokenNextVal, 0x64, 
/* 0x9b08: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x770a, 0x6265, 0x4f46, 0x5452, 0x2048, 0x56, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT__28literal_29, 0, XT__3C_23, XT__23, XT__23, XT__28literal_29, 0x2e, XT_HOLD, XT__23, XT__23, XT__28literal_29, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x9b4a: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x9b52: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x9b62: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x9b68: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 2, XT_EXIT, 
/* 0x9b80: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x9b8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9bec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9c8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ccc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9cec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9d8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9dec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9e8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9eac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9ecc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9eec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9f8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x9fec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa00c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa02c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa04c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa06c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa08c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa0ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa10c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa12c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa14c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa16c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa18c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa1ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa20c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa22c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa24c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa26c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa28c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa2ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa30c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa32c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa34c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa36c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa38c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa3ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa40c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa42c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa44c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa46c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa48c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa4ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa50c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa52c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa54c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa56c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa58c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa5ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa60c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa62c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa64c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa66c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa68c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa6ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa70c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa72c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa74c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa76c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa78c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa7ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa80c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa82c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa84c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa86c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa88c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa8ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa90c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa92c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa94c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa96c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa98c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xa9ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaa8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaaac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaacc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaaec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xab8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xabec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xac8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaccc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xacec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xad8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xadec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xae8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaeac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaecc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaeec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xaf8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xafec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb00c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb02c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb04c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb06c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb08c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb0ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb10c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb12c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb14c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb16c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb18c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb1ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb20c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb22c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb24c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb26c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb28c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb2ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb30c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb32c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb34c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb36c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb38c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb3ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb40c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb42c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb44c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb46c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb48c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb4ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb50c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb52c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb54c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb56c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb58c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb5ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb60c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb62c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb64c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb66c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb68c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb6ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb70c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb72c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb74c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb76c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb78c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb7ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb80c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb82c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb84c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb86c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb88c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb8ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb90c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb92c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb94c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb96c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb98c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xb9ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xba8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbaac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbacc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbaec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbb8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbbec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbc8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbccc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbcec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbd8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbdec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbe8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbeac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbecc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbeec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbf8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xbfec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc00c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc02c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc04c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc06c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc08c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc0ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc10c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc12c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc14c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc16c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc18c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc1ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc20c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc22c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc24c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc26c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc28c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc2ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc30c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc32c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc34c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc36c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc38c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc3ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc40c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc42c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc44c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc46c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc48c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc4ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc50c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc52c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc54c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc56c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc58c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc5ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc60c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc62c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc64c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc66c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc68c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc6ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc70c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc72c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc74c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc76c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc78c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc7ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc80c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc82c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc84c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc86c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc88c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc8ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc90c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc92c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc94c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc96c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc98c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9ac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9cc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xc9ec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xca8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcaac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcacc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcaec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcb8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcbec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcc8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcccc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xccec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcd8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdcc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcdec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xce8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xceac: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcecc: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xceec: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf0c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf2c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf4c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf6c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0xcf8c: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 
/* 0xcfac: */ 0x65, 
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
/* 0xd286  */ 0x93ba, 0xd290, 0xc0,
/* 0xd28c  */ 0x938e, 0xd296, 0,
/* 0xd292 EVAL */ XT_EVAL, 0xd2a0, 0x4504, 0x4156, 0x4c,
/* 0xd29c  */ 0x9338, 0xd2a6, 0,
/* 0xd2a2  */ 0x931c, 0xd2ac, 0,
/* 0xd2a8 ?UNIQUE */ XT__3FUNIQUE, 0xd2b8, 0x3f07, 0x4e55, 0x5149, 0x4555,
/* 0xd2b4 RECURSE */ XT_RECURSE, 0xd2c4, 0x5287, 0x4345, 0x5255, 0x4553,
/* 0xd2c0 ACTION-OF */ XT_ACTION_2DOF, 0xd2d2, 0x4189, 0x5443, 0x4f49, 0x2d4e, 0x464f,
/* 0xd2ce IS */ XT_IS, 0xd2da, 0x4982, 0x53,
/* 0xd2d6 '>BODY! */ XT__27_3EBODY_21, 0xd2e6, 0x2707, 0x423e, 0x444f, 0x2159,
/* 0xd2e2 BUFFER: */ XT_BUFFER_3A, 0xd2f2, 0x4207, 0x4655, 0x4546, 0x3a52,
/* 0xd2ee vALLOT */ XT_vALLOT, 0xd2fe, 0x7606, 0x4c41, 0x4f4c, 0x54,
/* 0xd2fa ALLOT */ XT_ALLOT, 0xd308, 0x4105, 0x4c4c, 0x544f,
/* 0xd304  */ 0x9284, 0xd30e, 0,
/* 0xd30a CONSOLE */ XT_CONSOLE, 0xd31a, 0x4307, 0x4e4f, 0x4f53, 0x454c,
/* 0xd316 I/O */ XT_I_2FO, 0xd322, 0x4903, 0x4f2f,
/* 0xd31e HAND */ XT_HAND, 0xd32c, 0x4804, 0x4e41, 0x44,
/* 0xd328 FILE */ XT_FILE, 0xd336, 0x4604, 0x4c49, 0x45,
/* 0xd332 XIO */ XT_XIO, 0xd33e, 0x5803, 0x4f49,
/* 0xd33a  */ 0x9230, 0xd344, 0x80,
/* 0xd340 ?STACK */ XT__3FSTACK, 0xd350, 0x3f06, 0x5453, 0x4341, 0x4b,
/* 0xd34c .OK */ XT__2EOK, 0xd358, 0x2e03, 0x4b4f,
/* 0xd354  */ 0x91d4, 0xd35e, 0,
/* 0xd35a POSTPONE */ XT_POSTPONE, 0xd36c, 0x5088, 0x534f, 0x5054, 0x4e4f, 0x45,
/* 0xd368 ABORT" */ XT_ABORT_22, 0xd378, 0x4186, 0x4f42, 0x5452, 0x22,
/* 0xd374 (abort") */ XT__28abort_22_29, 0xd386, 0x2848, 0x6261, 0x726f, 0x2274, 0x29,
/* 0xd382 ABORT */ XT_ABORT, 0xd390, 0x4105, 0x4f42, 0x5452,
/* 0xd38c NULL$ */ XT_NULL_24, 0xd39a, 0x4e05, 0x4c55, 0x244c,
/* 0xd396 S\" */ XT_S_5C_22, 0xd3a2, 0x5383, 0x225c,
/* 0xd39e pack\$ */ XT_pack_5C_24, 0xd3ae, 0x7006, 0x6361, 0x5c6b, 0x24,
/* 0xd3aa cmove\ */ XT_cmove_5C, 0xd3ba, 0x6306, 0x6f6d, 0x6576, 0x5c,
/* 0xd3b6 c+! */ XT_c_2B_21, 0xd3c2, 0x6303, 0x212b,
/* 0xd3be bu+@ */ XT_bu_2B_40, 0xd3cc, 0x6204, 0x2b75, 0x40,
/* 0xd3c8 S" */ XT_S_22, 0xd3d4, 0x5382, 0x22,
/* 0xd3d0 ." */ XT__2E_22, 0xd3dc, 0x2e82, 0x22,
/* 0xd3d8 C" */ XT_C_22, 0xd3e4, 0x4382, 0x22,
/* 0xd3e0 $" */ XT__24_22, 0xd3ec, 0x2482, 0x22,
/* 0xd3e8 S"| */ XT_S_22_7C, 0xd3f4, 0x5303, 0x7c22,
/* 0xd3f0 ."| */ XT__2E_22_7C, 0xd3fc, 0x2e03, 0x7c22,
/* 0xd3f8 $"| */ XT__24_22_7C, 0xd404, 0x2403, 0x7c22,
/* 0xd400 $," */ XT__24_2C_22, 0xd40c, 0x2403, 0x222c,
/* 0xd408 do$ */ XT_do_24, 0xd414, 0x6403, 0x246f,
/* 0xd410 kTAP */ XT_kTAP, 0xd41e, 0x6b04, 0x4154, 0x50,
/* 0xd41a skipToCRLF */ XT_skipToCRLF, 0xd42e, 0x730a, 0x696b, 0x5470, 0x436f, 0x4c52, 0x46,
/* 0xd42a skipCRLF */ XT_skipCRLF, 0xd43c, 0x7308, 0x696b, 0x4370, 0x4c52, 0x46,
/* 0xd438 crlf? */ XT_crlf_3F, 0xd446, 0x6305, 0x6c72, 0x3f66,
/* 0xd442 TAP */ XT_TAP, 0xd44e, 0x5403, 0x5041,
/* 0xd44a ^H */ XT__5EH, 0xd456, 0x5e02, 0x48,
/* 0xd452 THROW */ XT_THROW, 0xd460, 0x5405, 0x5248, 0x574f,
/* 0xd45c CATCH */ XT_CATCH, 0xd46a, 0x4305, 0x5441, 0x4843,
/* 0xd466 MARKER */ XT_MARKER, 0xd476, 0x4d06, 0x5241, 0x454b, 0x52,
/* 0xd472 FIND */ XT_FIND, 0xd480, 0x4604, 0x4e49, 0x44,
/* 0xd47c NAME? */ XT_NAME_3F, 0xd48a, 0x4e05, 0x4d41, 0x3f45,
/* 0xd486 FIND-NAME */ XT_FIND_2DNAME, 0xd498, 0x4609, 0x4e49, 0x2d44, 0x414e, 0x454d,
/* 0xd494 SAME? */ XT_SAME_3F, 0xd4a2, 0x5305, 0x4d41, 0x3f45,
/* 0xd49e NAME>INTERPRET */ XT_NAME_3EINTERPRET, 0xd4b6, 0x4e0e, 0x4d41, 0x3e45, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0xd4b2 WORD */ XT_WORD, 0xd4c0, 0x5704, 0x524f, 0x44,
/* 0xd4bc  */ 0x8c72, 0xd4c6, 0,
/* 0xd4c2 .( */ XT__2E_28, 0xd4ce, 0x2e82, 0x28,
/* 0xd4ca CTRL */ XT_CTRL, 0xd4d8, 0x4304, 0x5254, 0x4c,
/* 0xd4d4 [CHAR] */ XT__5BCHAR_5D, 0xd4e4, 0x5b86, 0x4843, 0x5241, 0x5d,
/* 0xd4e0 CHAR */ XT_CHAR, 0xd4ee, 0x4304, 0x4148, 0x52,
/* 0xd4ea PARSE-NAME */ XT_PARSE_2DNAME, 0xd4fe, 0x500a, 0x5241, 0x4553, 0x4e2d, 0x4d41, 0x45,
/* 0xd4fa  */ 0x8be8, 0xd504, 0,
/* 0xd500 skip-till */ XT_skip_2Dtill, 0xd512, 0x7309, 0x696b, 0x2d70, 0x6974, 0x6c6c,
/* 0xd50e xt-skip */ XT_xt_2Dskip, 0xd51e, 0x7807, 0x2d74, 0x6b73, 0x7069,
/* 0xd51a isnotspace? */ XT_isnotspace_3F, 0xd52e, 0x690b, 0x6e73, 0x746f, 0x7073, 0x6361, 0x3f65,
/* 0xd52a isspace? */ XT_isspace_3F, 0xd53c, 0x6908, 0x7373, 0x6170, 0x6563, 0x3f,
/* 0xd538 /STRING */ XT__2FSTRING, 0xd548, 0x2f07, 0x5453, 0x4952, 0x474e,
/* 0xd544 SOURCE */ XT_SOURCE, 0xd554, 0x5306, 0x554f, 0x4352, 0x45,
/* 0xd550 ['] */ XT__5B_27_5D, 0xd55c, 0x5b83, 0x5d27,
/* 0xd558 CR */ XT_CR, 0xd564, 0x4302, 0x52,
/* 0xd560 PACE */ XT_PACE, 0xd56e, 0x5004, 0x4341, 0x45,
/* 0xd56a NUF? */ XT_NUF_3F, 0xd578, 0x4e04, 0x4655, 0x3f,
/* 0xd574 KEY */ XT_KEY, 0xd580, 0x4b03, 0x5945,
/* 0xd57c ?KEY */ XT__3FKEY, 0xd58a, 0x3f04, 0x454b, 0x59,
/* 0xd586 DIGIT? */ XT_DIGIT_3F, 0xd596, 0x4406, 0x4749, 0x5449, 0x3f,
/* 0xd592 ? */ XT__3F, 0xd59c, 0x3f01,
/* 0xd598 . */ XT__2E, 0xd5a2, 0x2e01,
/* 0xd59e U. */ XT_U_2E, 0xd5aa, 0x5502, 0x2e,
/* 0xd5a6 U.R */ XT_U_2ER, 0xd5b2, 0x5503, 0x522e,
/* 0xd5ae .R */ XT__2ER, 0xd5ba, 0x2e02, 0x52,
/* 0xd5b6 DECIMAL */ XT_DECIMAL, 0xd5c6, 0x4407, 0x4345, 0x4d49, 0x4c41,
/* 0xd5c2 HEX */ XT_HEX, 0xd5ce, 0x4803, 0x5845,
/* 0xd5ca str */ XT_str, 0xd5d6, 0x7303, 0x7274,
/* 0xd5d2 .$ */ XT__2E_24, 0xd5de, 0x2e02, 0x24,
/* 0xd5da SPACES */ XT_SPACES, 0xd5ea, 0x5306, 0x4150, 0x4543, 0x53,
/* 0xd5e6 emits */ XT_emits, 0xd5f4, 0x6505, 0x696d, 0x7374,
/* 0xd5f0 SPACE */ XT_SPACE, 0xd5fe, 0x5305, 0x4150, 0x4543,
/* 0xd5fa EMIT */ XT_EMIT, 0xd608, 0x4504, 0x494d, 0x54,
/* 0xd604 #> */ XT__23_3E, 0xd610, 0x2302, 0x3e,
/* 0xd60c SIGN */ XT_SIGN, 0xd61a, 0x5304, 0x4749, 0x4e,
/* 0xd616 #S */ XT__23S, 0xd622, 0x2302, 0x53,
/* 0xd61e # */ XT__23, 0xd628, 0x2301,
/* 0xd624 HOLDS */ XT_HOLDS, 0xd632, 0x4805, 0x4c4f, 0x5344,
/* 0xd62e HOLD */ XT_HOLD, 0xd63c, 0x4804, 0x4c4f, 0x44,
/* 0xd638 <# */ XT__3C_23, 0xd644, 0x3c02, 0x23,
/* 0xd640 EXTRACT */ XT_EXTRACT, 0xd650, 0x4507, 0x5458, 0x4152, 0x5443,
/* 0xd64c DIGIT */ XT_DIGIT, 0xd65a, 0x4405, 0x4749, 0x5449,
/* 0xd656 PACK$ */ XT_PACK_24, 0xd664, 0x5005, 0x4341, 0x244b,
/* 0xd660 -TRAILING */ XT__2DTRAILING, 0xd672, 0x2d09, 0x5254, 0x4941, 0x494c, 0x474e,
/* 0xd66e ERASE */ XT_ERASE, 0xd67c, 0x4505, 0x4152, 0x4553,
/* 0xd678 FILL */ XT_FILL, 0xd686, 0x4604, 0x4c49, 0x4c,
/* 0xd682 MOVE */ XT_MOVE, 0xd690, 0x4d04, 0x564f, 0x45,
/* 0xd68c CMOVE> */ XT_CMOVE_3E, 0xd69c, 0x4306, 0x4f4d, 0x4556, 0x3e,
/* 0xd698 CMOVE */ XT_CMOVE, 0xd6a6, 0x4305, 0x4f4d, 0x4556,
/* 0xd6a2 COUNT */ XT_COUNT, 0xd6b0, 0x4305, 0x554f, 0x544e,
/* 0xd6ac @EXECUTE */ XT__40EXECUTE, 0xd6be, 0x4008, 0x5845, 0x4345, 0x5455, 0x45,
/* 0xd6ba TIB */ XT_TIB, 0xd6c6, 0x5403, 0x4249,
/* 0xd6c2 PAD */ XT_PAD, 0xd6ce, 0x5003, 0x4441,
/* 0xd6ca vCREATE */ XT_vCREATE, 0xd6da, 0x7607, 0x5243, 0x4145, 0x4554,
/* 0xd6d6 vALIGN */ XT_vALIGN, 0xd6e6, 0x7606, 0x4c41, 0x4749, 0x4e,
/* 0xd6e2 v, */ XT_v_2C, 0xd6ee, 0x7602, 0x2c,
/* 0xd6ea vHERE */ XT_vHERE, 0xd6f8, 0x7605, 0x4548, 0x4552,
/* 0xd6f4 2@ */ XT_2_40, 0xd700, 0x3202, 0x40,
/* 0xd6fc 2! */ XT_2_21, 0xd708, 0x3202, 0x21,
/* 0xd704 -- */ XT__2D_2D, 0xd710, 0x2d02, 0x2d,
/* 0xd70c ++ */ XT__2B_2B, 0xd718, 0x2b02, 0x2b,
/* 0xd714 +! */ XT__2B_21, 0xd720, 0x2b02, 0x21,
/* 0xd71c PICK */ XT_PICK, 0xd72a, 0x5004, 0x4349, 0x4b,
/* 0xd726  */ 0x8786, 0xd730, 0,
/* 0xd72c >CHAR */ XT__3ECHAR, 0xd73a, 0x3e05, 0x4843, 0x5241,
/* 0xd736 DEFER! */ XT_DEFER_21, 0xd746, 0x4406, 0x4645, 0x5245, 0x21,
/* 0xd742 >BODY! */ XT__3EBODY_21, 0xd752, 0x3e06, 0x4f42, 0x5944, 0x21,
/* 0xd74e DEFER@ */ XT_DEFER_40, 0xd75e, 0x4406, 0x4645, 0x5245, 0x40,
/* 0xd75a :NONAME */ XT__3ANONAME, 0xd76a, 0x3a07, 0x4f4e, 0x414e, 0x454d,
/* 0xd766 ($,n) */ XT__28_24_2Cn_29, 0xd774, 0x2805, 0x2c24, 0x296e,
/* 0xd770 2* */ XT_2_2A, 0xd77c, 0x3202, 0x2a,
/* 0xd778 CHARS */ XT_CHARS, 0xd786, 0x4305, 0x4148, 0x5352,
/* 0xd782 CELLS */ XT_CELLS, 0xd790, 0x4305, 0x4c45, 0x534c,
/* 0xd78c CELL- */ XT_CELL_2D, 0xd79a, 0x4305, 0x4c45, 0x2d4c,
/* 0xd796 SM/REM */ XT_SM_2FREM, 0xd7a6, 0x5306, 0x2f4d, 0x4552, 0x4d,
/* 0xd7a2 DABS */ XT_DABS, 0xd7b0, 0x4404, 0x4241, 0x53,
/* 0xd7ac D0< */ XT_D0_3C, 0xd7b8, 0x4403, 0x3c30,
/* 0xd7b4 * / */ XT__2A_2F, 0xd7c0, 0x2a02, 0x2f,
/* 0xd7bc * /MOD */ XT__2A_2FMOD, 0xd7ca, 0x2a05, 0x4d2f, 0x444f,
/* 0xd7c6 M* */ XT_M_2A, 0xd7d2, 0x4d02, 0x2a,
/* 0xd7ce * */ XT__2A, 0xd7d8, 0x2a01,
/* 0xd7d4 UM* */ XT_UM_2A, 0xd7e0, 0x5503, 0x2a4d,
/* 0xd7dc / */ XT__2F, 0xd7e6, 0x2f01,
/* 0xd7e2 MOD */ XT_MOD, 0xd7ee, 0x4d03, 0x444f,
/* 0xd7ea /MOD */ XT__2FMOD, 0xd7f8, 0x2f04, 0x4f4d, 0x44,
/* 0xd7f4 FM/MOD */ XT_FM_2FMOD, 0xd804, 0x4606, 0x2f4d, 0x4f4d, 0x44,
/* 0xd800 M/MOD */ XT_M_2FMOD, 0xd80e, 0x4d05, 0x4d2f, 0x444f,
/* 0xd80a UM/MOD */ XT_UM_2FMOD, 0xd81a, 0x5506, 0x2f4d, 0x4f4d, 0x44,
/* 0xd816 S>D */ XT_S_3ED, 0xd822, 0x5303, 0x443e,
/* 0xd81e WITHIN */ XT_WITHIN, 0xd82e, 0x5706, 0x5449, 0x4948, 0x4e,
/* 0xd82a MIN */ XT_MIN, 0xd836, 0x4d03, 0x4e49,
/* 0xd832 MAX */ XT_MAX, 0xd83e, 0x4d03, 0x5841,
/* 0xd83a > */ XT__3E, 0xd844, 0x3e01,
/* 0xd840 < */ XT__3C, 0xd84a, 0x3c01,
/* 0xd846 ud< */ XT_ud_3C, 0xd852, 0x7503, 0x3c64,
/* 0xd84e U> */ XT_U_3E, 0xd85a, 0x5502, 0x3e,
/* 0xd856 U< */ XT_U_3C, 0xd862, 0x5502, 0x3c,
/* 0xd85e <> */ XT__3C_3E, 0xd86a, 0x3c02, 0x3e,
/* 0xd866 = */ XT__3D, 0xd870, 0x3d01,
/* 0xd86c C, */ XT_C_2C, 0xd878, 0x4302, 0x2c,
/* 0xd874 CHAR+ */ XT_CHAR_2B, 0xd882, 0x4305, 0x4148, 0x2b52,
/* 0xd87e ABS */ XT_ABS, 0xd88a, 0x4103, 0x5342,
/* 0xd886 ?negate */ XT__3Fnegate, 0xd896, 0x3f07, 0x656e, 0x6167, 0x6574,
/* 0xd892 1- */ XT_1_2D, 0xd89e, 0x3102, 0x2d,
/* 0xd89a - */ XT__2D, 0xd8a4, 0x2d01,
/* 0xd8a0 DNEGATE */ XT_DNEGATE, 0xd8b0, 0x4407, 0x454e, 0x4147, 0x4554,
/* 0xd8ac NEGATE */ XT_NEGATE, 0xd8bc, 0x4e06, 0x4745, 0x5441, 0x45,
/* 0xd8b8 1+ */ XT_1_2B, 0xd8c4, 0x3102, 0x2b,
/* 0xd8c0 INVERT */ XT_INVERT, 0xd8d0, 0x4906, 0x564e, 0x5245, 0x54,
/* 0xd8cc D+ */ XT_D_2B, 0xd8d8, 0x4402, 0x2b,
/* 0xd8d4 2SWAP */ XT_2SWAP, 0xd8e2, 0x3205, 0x5753, 0x5041,
/* 0xd8de 2OVER */ XT_2OVER, 0xd8ec, 0x3205, 0x564f, 0x5245,
/* 0xd8e8 2DUP */ XT_2DUP, 0xd8f6, 0x3204, 0x5544, 0x50,
/* 0xd8f2 -ROT */ XT__2DROT, 0xd900, 0x2d04, 0x4f52, 0x54,
/* 0xd8fc ?test\ */ XT__3Ftest_5C, 0xd90c, 0x3f86, 0x6574, 0x7473, 0x5c,
/* 0xd908 ?safe\ */ XT__3Fsafe_5C, 0xd918, 0x3f86, 0x6173, 0x6566, 0x5c,
/* 0xd914 ?\ */ XT__3F_5C, 0xd920, 0x3f82, 0x5c,
/* 0xd91c D0= */ XT_D0_3D, 0xd928, 0x4403, 0x3d30,
/* 0xd924 0<> */ XT_0_3C_3E, 0xd930, 0x3003, 0x3e3c,
/* 0xd92c 0= */ XT_0_3D, 0xd938, 0x3002, 0x3d,
/* 0xd934 ENDCASE */ XT_ENDCASE, 0xd944, 0x4587, 0x444e, 0x4143, 0x4553,
/* 0xd940 ENDOF */ XT_ENDOF, 0xd94e, 0x4585, 0x444e, 0x464f,
/* 0xd94a OF */ XT_OF, 0xd956, 0x4f82, 0x46,
/* 0xd952 CASE */ XT_CASE, 0xd960, 0x4384, 0x5341, 0x45,
/* 0xd95c >RESOLVETHREAD */ XT__3ERESOLVETHREAD, 0xd974, 0x3e0e, 0x4552, 0x4f53, 0x564c, 0x5445, 0x5248, 0x4145, 0x44,
/* 0xd970 >MARKTHREAD */ XT__3EMARKTHREAD, 0xd984, 0x3e0b, 0x414d, 0x4b52, 0x4854, 0x4552, 0x4441,
/* 0xd980 >MARKSTART */ XT__3EMARKSTART, 0xd994, 0x3e0a, 0x414d, 0x4b52, 0x5453, 0x5241, 0x54,
/* 0xd990 >RESOLVES */ XT__3ERESOLVES, 0xd9a2, 0x3e09, 0x4552, 0x4f53, 0x564c, 0x5345,
/* 0xd99e ?DUP */ XT__3FDUP, 0xd9ac, 0x3f04, 0x5544, 0x50,
/* 0xd9a8 WHILE */ XT_WHILE, 0xd9b6, 0x5785, 0x4948, 0x454c,
/* 0xd9b2 WHEN */ XT_WHEN, 0xd9c0, 0x5784, 0x4548, 0x4e,
/* 0xd9bc ELSE */ XT_ELSE, 0xd9ca, 0x4584, 0x534c, 0x45,
/* 0xd9c6 AFT */ XT_AFT, 0xd9d2, 0x4183, 0x5446,
/* 0xd9ce THEN */ XT_THEN, 0xd9dc, 0x5484, 0x4548, 0x4e,
/* 0xd9d8 REPEAT */ XT_REPEAT, 0xd9e8, 0x5286, 0x5045, 0x4145, 0x54,
/* 0xd9e4 AHEAD */ XT_AHEAD, 0xd9f2, 0x4185, 0x4548, 0x4441,
/* 0xd9ee IF */ XT_IF, 0xd9fa, 0x4982, 0x46,
/* 0xd9f6 AGAIN */ XT_AGAIN, 0xda04, 0x4185, 0x4147, 0x4e49,
/* 0xda00 UNTIL */ XT_UNTIL, 0xda0e, 0x5585, 0x544e, 0x4c49,
/* 0xda0a NEXT */ XT_NEXT, 0xda18, 0x4e84, 0x5845, 0x54,
/* 0xda14 BEGIN */ XT_BEGIN, 0xda22, 0x4285, 0x4745, 0x4e49,
/* 0xda1e FOR */ XT_FOR, 0xda2a, 0x4683, 0x524f,
/* 0xda26 >RESOLVE */ XT__3ERESOLVE, 0xda38, 0x3e08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda34 >MARK */ XT__3EMARK, 0xda42, 0x3e05, 0x414d, 0x4b52,
/* 0xda3e <RESOLVE */ XT__3CRESOLVE, 0xda50, 0x3c08, 0x4552, 0x4f53, 0x564c, 0x45,
/* 0xda4c <MARK */ XT__3CMARK, 0xda5a, 0x3c05, 0x414d, 0x4b52,
/* 0xda56 CREATE */ XT_CREATE, 0xda66, 0x4306, 0x4552, 0x5441, 0x45,
/* 0xda62 create */ XT_create, 0xda72, 0x6306, 0x6572, 0x7461, 0x65,
/* 0xda6e LITERAL */ XT_LITERAL, 0xda7e, 0x4c87, 0x5449, 0x5245, 0x4c41,
/* 0xda7a COMPILE */ XT_COMPILE, 0xda8a, 0x4347, 0x4d4f, 0x4950, 0x454c,
/* 0xda86 [COMPILE] */ XT__5BCOMPILE_5D, 0xda98, 0x5b89, 0x4f43, 0x504d, 0x4c49, 0x5d45,
/* 0xda94 COMPILE, */ XT_COMPILE_2C, 0xdaa6, 0x4308, 0x4d4f, 0x4950, 0x454c, 0x2c,
/* 0xdaa2 , */ XT__2C, 0xdaac, 0x2c01,
/* 0xdaa8 CELL+ */ XT_CELL_2B, 0xdab6, 0x4305, 0x4c45, 0x2b4c,
/* 0xdab2 + */ XT__2B, 0xdabc, 0x2b01,
/* 0xdab8 HERE */ XT_HERE, 0xdac6, 0x4804, 0x5245, 0x45,
/* 0xdac2 TUCK */ XT_TUCK, 0xdad0, 0x5404, 0x4355, 0x4b,
/* 0xdacc NIP */ XT_NIP, 0xdad8, 0x4e03, 0x5049,
/* 0xdad4 \ */ XT__5C, 0xdade, 0x5c81,
/* 0xdada IMMEDIATE */ XT_IMMEDIATE, 0xdaec, 0x4909, 0x4d4d, 0x4445, 0x4149, 0x4554,
/* 0xdae8 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0xdafe, 0x430c, 0x4d4f, 0x4950, 0x454c, 0x4f2d, 0x4c4e, 0x59,
/* 0xdafa setHeaderBits */ XT_setHeaderBits, 0xdb10, 0x730d, 0x7465, 0x6548, 0x6461, 0x7265, 0x6942, 0x7374,
/* 0xdb0c 2DROP */ XT_2DROP, 0xdb1a, 0x3205, 0x5244, 0x504f,
/* 0xdb16 testDepth */ XT_testDepth, 0xdb28, 0x7409, 0x7365, 0x4474, 0x7065, 0x6874,
/* 0xdb24 testFlags */ XT_testFlags, 0xdb36, 0x7409, 0x7365, 0x4674, 0x616c, 0x7367,
/* 0xdb32 source-id */ XT_source_2Did, 0xdb44, 0x7309, 0x756f, 0x6372, 0x2d65, 0x6469,
/* 0xdb40 VP */ XT_VP, 0xdb4c, 0x5602, 0x50,
/* 0xdb48 LAST */ XT_LAST, 0xdb56, 0x4c04, 0x5341, 0x54,
/* 0xdb52 NP */ XT_NP, 0xdb5e, 0x4e02, 0x50,
/* 0xdb5a CP */ XT_CP, 0xdb66, 0x4302, 0x50,
/* 0xdb62 CURRENT */ XT_CURRENT, 0xdb72, 0x4307, 0x5255, 0x4552, 0x544e,
/* 0xdb6e CONTEXT */ XT_CONTEXT, 0xdb7e, 0x4307, 0x4e4f, 0x4554, 0x5458,
/* 0xdb7a HANDLER */ XT_HANDLER, 0xdb8a, 0x4807, 0x4e41, 0x4c44, 0x5245,
/* 0xdb86 HLD */ XT_HLD, 0xdb92, 0x4803, 0x444c,
/* 0xdb8e SPARE2 */ XT_SPARE2, 0xdb9e, 0x5306, 0x4150, 0x4552, 0x32,
/* 0xdb9a STATE */ XT_STATE, 0xdba8, 0x5305, 0x4154, 0x4554,
/* 0xdba4 CSP */ XT_CSP, 0xdbb0, 0x4303, 0x5053,
/* 0xdbac #TIB */ XT__23TIB, 0xdbba, 0x2304, 0x4954, 0x42,
/* 0xdbb6 >IN */ XT__3EIN, 0xdbc2, 0x3e03, 0x4e49,
/* 0xdbbe SPAN */ XT_SPAN, 0xdbcc, 0x5304, 0x4150, 0x4e,
/* 0xdbc8 temp */ XT_temp, 0xdbd6, 0x7404, 0x6d65, 0x70,
/* 0xdbd2 BASE */ XT_BASE, 0xdbe0, 0x4204, 0x5341, 0x45,
/* 0xdbdc 'PROMPT */ XT__27PROMPT, 0xdbec, 0x2707, 0x5250, 0x4d4f, 0x5450,
/* 0xdbe8 'ECHO */ XT__27ECHO, 0xdbf6, 0x2705, 0x4345, 0x4f48,
/* 0xdbf2 'TAP */ XT__27TAP, 0xdc00, 0x2704, 0x4154, 0x50,
/* 0xdbfc SPARE */ XT_SPARE, 0xdc0a, 0x5305, 0x4150, 0x4552,
/* 0xdc06 'EMIT */ XT__27EMIT, 0xdc14, 0x2705, 0x4d45, 0x5449,
/* 0xdc10 '?KEY */ XT__27_3FKEY, 0xdc1e, 0x2705, 0x4b3f, 0x5945,
/* 0xdc1a RP0 */ XT_RP0, 0xdc26, 0x5203, 0x3050,
/* 0xdc22 SP0 */ XT_SP0, 0xdc2e, 0x5303, 0x3050,
/* 0xdc2a _USER */ XT__5FUSER, 0xdc38, 0x5f05, 0x5355, 0x5245,
/* 0xdc34 -> */ XT__2D_3E, 0xdc40, 0x2d02, 0x3e,
/* 0xdc3c }T */ XT__7DT, 0xdc48, 0x7d02, 0x54,
/* 0xdc44 DEPTH */ XT_DEPTH, 0xdc52, 0x4405, 0x5045, 0x4854,
/* 0xdc4e T{ */ XT_T_7B, 0xdc5a, 0x5402, 0x7b,
/* 0xdc56 (of) */ XT__28of_29, 0xdc64, 0x2804, 0x666f, 0x29,
/* 0xdc60 DEFER */ XT_DEFER, 0xdc6e, 0x4405, 0x4645, 0x5245,
/* 0xdc6a >BODY */ XT__3EBODY, 0xdc78, 0x3e05, 0x4f42, 0x5944,
/* 0xdc74 ALIGN */ XT_ALIGN, 0xdc82, 0x4105, 0x494c, 0x4e47,
/* 0xdc7e immediate? */ XT_immediate_3F, 0xdc92, 0x690a, 0x6d6d, 0x6465, 0x6169, 0x6574, 0x3f,
/* 0xdc8e 2RDrop */ XT_2RDrop, 0xdc9e, 0x3206, 0x4452, 0x6f72, 0x70,
/* 0xdc9a RDrop */ XT_RDrop, 0xdca8, 0x5205, 0x7244, 0x706f,
/* 0xdca4 I */ XT_I, 0xdcae, 0x4901,
/* 0xdcaa TYPE */ XT_TYPE, 0xdcb8, 0x5404, 0x5059, 0x45,
/* 0xdcb4 stringBuffer */ XT_stringBuffer, 0xdcca, 0x730c, 0x7274, 0x6e69, 0x4267, 0x6675, 0x6566, 0x72,
/* 0xdcc6 Fbreak */ XT_Fbreak, 0xdcd6, 0x4606, 0x7262, 0x6165, 0x6b,
/* 0xdcd2 debugNA */ XT_debugNA, 0xdce2, 0x6407, 0x6265, 0x6775, 0x414e,
/* 0xdcde ' */ XT__27, 0xdce8, 0x2701,
/* 0xdce4 ; */ XT__3B, 0xdcee, 0x3b81,
/* 0xdcea : */ XT__3A, 0xdcf4, 0x3a01,
/* 0xdcf0 ] */ XT__5D, 0xdcfa, 0x5d01,
/* 0xdcf6 [ */ XT__5B, 0xdd00, 0x5b81,
/* 0xdcfc $INTERPRET */ XT__24INTERPRET, 0xdd10, 0x240a, 0x4e49, 0x4554, 0x5052, 0x4552, 0x54,
/* 0xdd0c $COMPILE */ XT__24COMPILE, 0xdd1e, 0x2408, 0x4f43, 0x504d, 0x4c49, 0x45,
/* 0xdd1a NUMBER? */ XT_NUMBER_3F, 0xdd2a, 0x4e07, 0x4d55, 0x4542, 0x3f52,
/* 0xdd26 TOKEN */ XT_TOKEN, 0xdd34, 0x5405, 0x4b4f, 0x4e45,
/* 0xdd30 ( */ XT__28, 0xdd3a, 0x2881,
/* 0xdd36 PARSE */ XT_PARSE, 0xdd44, 0x5005, 0x5241, 0x4553,
/* 0xdd40 userAreaSave */ XT_userAreaSave, 0xdd56, 0x750c, 0x6573, 0x4172, 0x6572, 0x5361, 0x7661, 0x65,
/* 0xdd52 userAreaInit */ XT_userAreaInit, 0xdd68, 0x750c, 0x6573, 0x4172, 0x6572, 0x4961, 0x696e, 0x74,
/* 0xdd64 2/ */ XT_2_2F, 0xdd70, 0x3202, 0x2f,
/* 0xdd6c LSHIFT */ XT_LSHIFT, 0xdd7c, 0x4c06, 0x4853, 0x4649, 0x54,
/* 0xdd78 RSHIFT */ XT_RSHIFT, 0xdd88, 0x5206, 0x4853, 0x4649, 0x54,
/* 0xdd84 UM+ */ XT_UM_2B, 0xdd90, 0x5503, 0x2b4d,
/* 0xdd8c XOR */ XT_XOR, 0xdd98, 0x5803, 0x524f,
/* 0xdd94 OR */ XT_OR, 0xdda0, 0x4f02, 0x52,
/* 0xdd9c AND */ XT_AND, 0xdda8, 0x4103, 0x444e,
/* 0xdda4 0< */ XT_0_3C, 0xddb0, 0x3002, 0x3c,
/* 0xddac ROT */ XT_ROT, 0xddb8, 0x5203, 0x544f,
/* 0xddb4 ROLL */ XT_ROLL, 0xddc2, 0x5204, 0x4c4f, 0x4c,
/* 0xddbe OVER */ XT_OVER, 0xddcc, 0x4f04, 0x4556, 0x52,
/* 0xddc8 SWAP */ XT_SWAP, 0xddd6, 0x5304, 0x4157, 0x50,
/* 0xddd2 DUP */ XT_DUP, 0xddde, 0x4403, 0x5055,
/* 0xddda DROP */ XT_DROP, 0xdde8, 0x4404, 0x4f52, 0x50,
/* 0xdde4 SP! */ XT_SP_21, 0xddf0, 0x5303, 0x2150,
/* 0xddec SP@ */ XT_SP_40, 0xddf8, 0x5303, 0x4050,
/* 0xddf4 2>R */ XT_2_3ER, 0xde00, 0x3203, 0x523e,
/* 0xddfc 2R@ */ XT_2R_40, 0xde08, 0x3203, 0x4052,
/* 0xde04 2R> */ XT_2R_3E, 0xde10, 0x3203, 0x3e52,
/* 0xde0c >R */ XT__3ER, 0xde18, 0x3e02, 0x52,
/* 0xde14 R@ */ XT_R_40, 0xde20, 0x5202, 0x40,
/* 0xde1c R> */ XT_R_3E, 0xde28, 0x5202, 0x3e,
/* 0xde24 RP! */ XT_RP_21, 0xde30, 0x5203, 0x2150,
/* 0xde2c RP@ */ XT_RP_40, 0xde38, 0x5203, 0x4050,
/* 0xde34 C! */ XT_C_21, 0xde40, 0x4302, 0x21,
/* 0xde3c C@ */ XT_C_40, 0xde48, 0x4302, 0x40,
/* 0xde44 @ */ XT__40, 0xde4e, 0x4001,
/* 0xde4a ! */ XT__21, 0xde54, 0x2101,
/* 0xde50 branch */ XT_branch, 0xde60, 0x6206, 0x6172, 0x636e, 0x68,
/* 0xde5c ?branch */ XT__3Fbranch, 0xde6c, 0x3f07, 0x7262, 0x6e61, 0x6863,
/* 0xde68 (next) */ XT__28next_29, 0xde78, 0x2806, 0x656e, 0x7478, 0x29,
/* 0xde74 DOES> */ XT_DOES_3E, 0xde82, 0x4405, 0x454f, 0x3e53,
/* 0xde7e (literal) */ XT__28literal_29, 0xde90, 0x2809, 0x696c, 0x6574, 0x6172, 0x296c,
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
