#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x40003688 /* WARM*/
#define XT_COLD 0x40003658 /* COLD*/
#define XT__27BOOT 0x4000364c /* 'BOOT*/
#define XT_EMPTY 0x4000362c /* EMPTY*/
#define XT_hi 0x4000361c /* hi*/
#define XT_version 0x400035a4 /* version*/
#define XT_VER 0x4000359c /* VER*/
#define XT_SEE 0x400034a8 /* SEE*/
#define XT__3ENAME 0x40003430 /* >NAME*/
#define XT_WORDS 0x400033ec /* WORDS*/
#define XT__2EID 0x400033b4 /* .ID*/
#define XT__3FCSP 0x4000338c /* ?CSP*/
#define XT__21CSP 0x40003378 /* !CSP*/
#define XT__2EFREE 0x40003360 /* .FREE*/
#define XT__2EBASE 0x4000333c /* .BASE*/
#define XT_UNUSED 0x40003320 /* UNUSED*/
#define XT__2ES 0x400032e4 /* .S*/
#define XT_DUMP 0x4000325c /* DUMP*/
#define XT_dm_2B 0x40003214 /* dm+*/
#define XT_EVALUATE 0x400031e0 /* EVALUATE*/
#define XT_quit1 0x400031b8 /* quit1*/
#define XT_QUIT 0x40003154 /* QUIT*/
#define XT_quitError 0x400030f8 /* quitError*/
#define XT_PRESET 0x400030b0 /* PRESET*/
#define XT_que 0x400030a0 /* que*/
#define XT_QUERY 0x4000302c /* QUERY*/
#define XT_REFILL 0x40002fc8 /* REFILL*/
#define XT_READ_2DLINE 0x40002fc0 /* READ-LINE*/
#define XT_sourcePop 0x40002fa8 /* sourcePop*/
#define XT_RESTORE_2DINPUT 0x40002f54 /* RESTORE-INPUT*/
#define XT_sourcePush 0x40002f40 /* sourcePush*/
#define XT_SAVE_2DINPUT 0x40002f20 /* SAVE-INPUT*/
#define XT_unreadFile 0x40002f18 /* unreadFile*/
#define XT_0_3E 0x40002ef8 /* 0>*/
#define XT_sourceStack 0x40002ee8 /* sourceStack*/
#define XT_SOURCE_2DID 0x40002ed8 /* SOURCE-ID*/
#define XT_sempty 0x40002ebc /* sempty*/
#define XT_spops 0x40002e74 /* spops*/
#define XT_spushes 0x40002e30 /* spushes*/
#define XT_spush 0x40002e00 /* spush*/
#define XT_spop 0x40002dd4 /* spop*/
#define XT_stack 0x40002d90 /* stack*/
#define XT_ACCEPT 0x40002d20 /* ACCEPT*/
#define XT__28charbase_29 0x40002b54 /* (charbase)*/
#define XT__3ENUMBER 0x40002ad4 /* >NUMBER*/
#define XT_accumulate 0x40002a98 /* accumulate*/
#define XT_J_2DMAX 0x40002a78 /* J-MAX*/
#define XT_J 0x40002a58 /* J*/
#define XT_I_2DMAX 0x40002a38 /* I-MAX*/
#define XT__2BLOOP 0x40002a24 /* +LOOP*/
#define XT_LOOP 0x40002a10 /* LOOP*/
#define XT_some_2Dloop 0x400029b8 /* some-loop*/
#define XT__3FDO 0x40002980 /* ?DO*/
#define XT_DO 0x40002954 /* DO*/
#define XT_UNLOOP 0x40002944 /* UNLOOP*/
#define XT_LEAVE 0x40002930 /* LEAVE*/
#define XT_leave_2C 0x40002910 /* leave,*/
#define XT__28_2Bloop_29 0x40002894 /* (+loop)*/
#define XT__28loop_29 0x4000286c /* (loop)*/
#define XT__28_3Fdo_29 0x40002848 /* (?do)*/
#define XT_leave_2Dptr 0x4000283c /* leave-ptr*/
#define XT_CONSTANT 0x4000281c /* CONSTANT*/
#define XT_VARIABLE 0x40002804 /* VARIABLE*/
#define XT_TO 0x400027f8 /* TO*/
#define XT_VALUE 0x400027c0 /* VALUE*/
#define XT_ 0x40002750 /* */
#define XT_ 0x400026f8 /* */
#define XT_EVAL 0x400026a4 /* EVAL*/
#define XT_ 0x4000264c /* */
#define XT_ 0x40002618 /* */
#define XT__3FUNIQUE 0x400025e8 /* ?UNIQUE*/
#define XT_RECURSE 0x400025d0 /* RECURSE*/
#define XT_ACTION_2DOF 0x4000259c /* ACTION-OF*/
#define XT_IS 0x40002590 /* IS*/
#define XT__27_3EBODY_21 0x4000255c /* '>BODY!*/
#define XT_BUFFER_3A 0x4000254c /* BUFFER:*/
#define XT_vALLOT 0x40002520 /* vALLOT*/
#define XT_ALLOT 0x40002510 /* ALLOT*/
#define XT_ 0x400024f0 /* */
#define XT_CONSOLE 0x400024d4 /* CONSOLE*/
#define XT_I_2FO 0x400024c4 /* I/O*/
#define XT_HAND 0x400024a0 /* HAND*/
#define XT_FILE 0x4000247c /* FILE*/
#define XT_XIO 0x4000245c /* XIO*/
#define XT_ 0x40002448 /* */
#define XT__3FSTACK 0x40002428 /* ?STACK*/
#define XT__2EOK 0x40002400 /* .OK*/
#define XT_ 0x400023a8 /* */
#define XT_POSTPONE 0x40002358 /* POSTPONE*/
#define XT_ABORT_22 0x40002344 /* ABORT"*/
#define XT_abort_22 0x40002324 /* abort"*/
#define XT_ABORT 0x40002314 /* ABORT*/
#define XT_NULL_24 0x40002308 /* NULL$*/
#define XT_S_5C_22 0x40002284 /* S\"*/
#define XT_pack_5C_24 0x400021f4 /* pack\$*/
#define XT_cmove_5C 0x40001f10 /* cmove\*/
#define XT_c_2B_21 0x40001efc /* c+!*/
#define XT_bu_2B_40 0x40001ee0 /* bu+@*/
#define XT_S_22 0x40001e9c /* S"*/
#define XT__2E_22 0x40001e88 /* ."*/
#define XT_C_22 0x40001e7c /* C"*/
#define XT__24_22 0x40001e68 /* $"*/
#define XT_S_22_7C 0x40001e58 /* S"|*/
#define XT__2E_22_7C 0x40001e48 /* ."|*/
#define XT__24_22_7C 0x40001e3c /* $"|*/
#define XT__24_2C_22 0x40001e14 /* $,"*/
#define XT_do_24 0x40001de8 /* do$*/
#define XT_kTAP 0x40001d78 /* kTAP*/
#define XT_skipToCRLF 0x40001d28 /* skipToCRLF*/
#define XT_skipCRLF 0x40001cdc /* skipCRLF*/
#define XT_crlf_3F 0x40001cb0 /* crlf?*/
#define XT_TAP 0x40001c90 /* TAP*/
#define XT__5EH 0x40001c38 /* ^H*/
#define XT_THROW 0x40001bf4 /* THROW*/
#define XT_CATCH 0x40001bac /* CATCH*/
#define XT_MARKER 0x40001ad4 /* MARKER*/
#define XT_FIND 0x40001a70 /* FIND*/
#define XT_NAME_3F 0x40001a34 /* NAME?*/
#define XT_FIND_2DNAME 0x400019b0 /* FIND-NAME*/
#define XT_SAME_3F 0x4000194c /* SAME?*/
#define XT_NAME_3EINTERPRET 0x40001930 /* NAME>INTERPRET*/
#define XT_WORD 0x4000191c /* WORD*/
#define XT_ 0x400018ec /* */
#define XT__2E_28 0x400018d4 /* .(*/
#define XT_CTRL 0x400018bc /* CTRL*/
#define XT__5BCHAR_5D 0x400018ac /* [CHAR]*/
#define XT_CHAR 0x40001898 /* CHAR*/
#define XT_PARSE_2DNAME 0x40001888 /* PARSE-NAME*/
#define XT_ 0x400017d8 /* */
#define XT_skip_2Dtill 0x40001788 /* skip-till*/
#define XT_xt_2Dskip 0x4000173c /* xt-skip*/
#define XT_isnotspace_3F 0x4000172c /* isnotspace?*/
#define XT_isspace_3F 0x40001718 /* isspace?*/
#define XT__2FSTRING 0x400016fc /* /STRING*/
#define XT_SOURCE 0x400016e8 /* SOURCE*/
#define XT__5B_27_5D 0x400016d8 /* [']*/
#define XT_CR 0x400016b8 /* CR*/
#define XT_PACE 0x400016a4 /* PACE*/
#define XT_NUF_3F 0x40001678 /* NUF?*/
#define XT_KEY 0x4000164c /* KEY*/
#define XT__3FKEY 0x4000163c /* ?KEY*/
#define XT_DIGIT_3F 0x400015bc /* DIGIT?*/
#define XT__3F 0x400015ac /* ?*/
#define XT__2E 0x40001574 /* .*/
#define XT_U_2E 0x40001550 /* U.*/
#define XT_U_2ER 0x4000151c /* U.R*/
#define XT__2ER 0x400014f8 /* .R*/
#define XT_DECIMAL 0x400014e0 /* DECIMAL*/
#define XT_HEX 0x400014c8 /* HEX*/
#define XT_str 0x40001498 /* str*/
#define XT__2E_24 0x40001488 /* .$*/
#define XT_SPACES 0x40001478 /* SPACES*/
#define XT_emits 0x40001440 /* emits*/
#define XT_SPACE 0x40001430 /* SPACE*/
#define XT_EMIT 0x40001420 /* EMIT*/
#define XT__23_3E 0x40001400 /* #>*/
#define XT_SIGN 0x400013e0 /* SIGN*/
#define XT__23S 0x400013bc /* #S*/
#define XT__23 0x400013a4 /* #*/
#define XT_HOLDS 0x40001370 /* HOLDS*/
#define XT_HOLD 0x4000134c /* HOLD*/
#define XT__3C_23 0x40001338 /* <#*/
#define XT_EXTRACT 0x40001300 /* EXTRACT*/
#define XT_DIGIT 0x400012cc /* DIGIT*/
#define XT_PACK_24 0x40001268 /* PACK$*/
#define XT__2DTRAILING 0x40001218 /* -TRAILING*/
#define XT_ERASE 0x40001204 /* ERASE*/
#define XT_FILL 0x400011d0 /* FILL*/
#define XT_MOVE 0x4000119c /* MOVE*/
#define XT_CMOVE_3E 0x40001134 /* CMOVE>*/
#define XT_CMOVE 0x400010f4 /* CMOVE*/
#define XT_COUNT 0x400010dc /* COUNT*/
#define XT__40EXECUTE 0x400010c0 /* @EXECUTE*/
#define XT_TIB 0x400010ac /* TIB*/
#define XT_PAD 0x40001094 /* PAD*/
#define XT_vCREATE 0x4000105c /* vCREATE*/
#define XT_vALIGN 0x40001040 /* vALIGN*/
#define XT_v_2C 0x40001000 /* v,*/
#define XT_vHERE 0x40000fdc /* vHERE*/
#define XT_2_40 0x40000fc0 /* 2@*/
#define XT_2_21 0x40000fa4 /* 2!*/
#define XT__2D_2D 0x40000f8c /* --*/
#define XT__2B_2B 0x40000f74 /* ++*/
#define XT__2B_21 0x40000f54 /* +!*/
#define XT_PICK 0x40000f38 /* PICK*/
#define XT_ 0x40000f14 /* */
#define XT__3ECHAR 0x40000ed8 /* >CHAR*/
#define XT_DEFER_21 0x40000ecc /* DEFER!*/
#define XT__3EBODY_21 0x40000ebc /* >BODY!*/
#define XT_DEFER_40 0x40000eac /* DEFER@*/
#define XT__3ANONAME 0x40000e68 /* :NONAME*/
#define XT__28_24_2Cn_29 0x40000e10 /* ($,n)*/
#define XT_2_2A 0x40000dfc /* 2**/
#define XT_CHARS 0x40000df4 /* CHARS*/
#define XT_CELLS 0x40000de4 /* CELLS*/
#define XT_CELL_2D 0x40000dd4 /* CELL-*/
#define XT_SM_2FREM 0x40000d8c /* SM/REM*/
#define XT_DABS 0x40000d70 /* DABS*/
#define XT_D0_3C 0x40000d60 /* D0<*/
#define XT__2A_2F 0x40000d50 /* * /*/
#define XT__2A_2FMOD 0x40000d38 /* * /MOD*/
#define XT_M_2A 0x40000d00 /* M**/
#define XT__2A 0x40000cf0 /* **/
#define XT_UM_2A 0x40000c7c /* UM**/
#define XT__2F 0x40000c6c /* /*/
#define XT_MOD 0x40000c5c /* MOD*/
#define XT__2FMOD 0x40000c44 /* /MOD*/
#define XT_FM_2FMOD 0x40000c38 /* FM/MOD*/
#define XT_M_2FMOD 0x40000bcc /* M/MOD*/
#define XT_UM_2FMOD 0x40000b0c /* UM/MOD*/
#define XT_S_3ED 0x40000afc /* S>D*/
#define XT_WITHIN 0x40000adc /* WITHIN*/
#define XT_MIN 0x40000ab8 /* MIN*/
#define XT_MAX 0x40000a98 /* MAX*/
#define XT__3E 0x40000a88 /* >*/
#define XT__3C 0x40000a58 /* <*/
#define XT_ud_3C 0x40000a28 /* ud<*/
#define XT_U_3E 0x40000a18 /* U>*/
#define XT_U_3C 0x400009e8 /* U<*/
#define XT__3C_3E 0x400009c8 /* <>*/
#define XT__3D 0x400009a8 /* =*/
#define XT_C_2C 0x40000988 /* C,*/
#define XT_CHAR_2B 0x4000097c /* CHAR+*/
#define XT_ABS 0x4000096c /* ABS*/
#define XT__3Fnegate 0x40000954 /* ?negate*/
#define XT_1_2D 0x40000940 /* 1-*/
#define XT__2D 0x40000930 /* -*/
#define XT_DNEGATE 0x40000908 /* DNEGATE*/
#define XT_NEGATE 0x400008f8 /* NEGATE*/
#define XT_1_2B 0x400008e4 /* 1+*/
#define XT_INVERT 0x400008d0 /* INVERT*/
#define XT_D_2B 0x400008a8 /* D+*/
#define XT_2SWAP 0x40000890 /* 2SWAP*/
#define XT_2OVER 0x4000086c /* 2OVER*/
#define XT_2DUP 0x4000085c /* 2DUP*/
#define XT__2DROT 0x40000844 /* -ROT*/
#define XT__3Ftest_5C 0x40000824 /* ?test\*/
#define XT__3Fsafe_5C 0x40000804 /* ?safe\*/
#define XT__3F_5C 0x400007ec /* ?\*/
#define XT_D0_3D 0x400007dc /* D0=*/
#define XT_0_3C_3E 0x400007cc /* 0<>*/
#define XT_0_3D 0x400007ac /* 0=*/
#define XT_ENDCASE 0x40000798 /* ENDCASE*/
#define XT_ENDOF 0x40000778 /* ENDOF*/
#define XT_OF 0x40000764 /* OF*/
#define XT_CASE 0x40000758 /* CASE*/
#define XT__3ERESOLVETHREAD 0x4000072c /* >RESOLVETHREAD*/
#define XT__3EMARKTHREAD 0x40000718 /* >MARKTHREAD*/
#define XT__3EMARKSTART 0x40000708 /* >MARKSTART*/
#define XT__3ERESOLVES 0x400006e8 /* >RESOLVES*/
#define XT__3FDUP 0x400006d0 /* ?DUP*/
#define XT_WHILE 0x400006c0 /* WHILE*/
#define XT_WHEN 0x400006b0 /* WHEN*/
#define XT_ELSE 0x4000069c /* ELSE*/
#define XT_AFT 0x40000684 /* AFT*/
#define XT_THEN 0x40000678 /* THEN*/
#define XT_REPEAT 0x40000668 /* REPEAT*/
#define XT_AHEAD 0x40000654 /* AHEAD*/
#define XT_IF 0x40000640 /* IF*/
#define XT_AGAIN 0x4000062c /* AGAIN*/
#define XT_UNTIL 0x40000618 /* UNTIL*/
#define XT_NEXT 0x40000604 /* NEXT*/
#define XT_BEGIN 0x400005f8 /* BEGIN*/
#define XT_FOR 0x400005e4 /* FOR*/
#define XT__3ERESOLVE 0x400005d0 /* >RESOLVE*/
#define XT__3EMARK 0x400005b8 /* >MARK*/
#define XT__3CRESOLVE 0x400005ac /* <RESOLVE*/
#define XT__3CMARK 0x400005a0 /* <MARK*/
#define XT_CREATE 0x40000590 /* CREATE*/
#define XT_create 0x4000056c /* create*/
#define XT_LITERAL 0x40000558 /* LITERAL*/
#define XT_COMPILE 0x40000538 /* COMPILE*/
#define XT__5BCOMPILE_5D 0x40000528 /* [COMPILE]*/
#define XT_COMPILE_2C 0x4000051c /* COMPILE,*/
#define XT__2C 0x400004f8 /* ,*/
#define XT_CELL_2B 0x400004e8 /* CELL+*/
#define XT__2B 0x400004d8 /* +*/
#define XT_HERE 0x400004c8 /* HERE*/
#define XT_TUCK 0x400004b8 /* TUCK*/
#define XT_NIP 0x400004a8 /* NIP*/
#define XT__5C 0x40000490 /* \*/
#define XT_IMMEDIATE 0x40000480 /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x40000470 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x4000044c /* setHeaderBits*/
#define XT_2DROP 0x4000043c /* 2DROP*/
#define XT_testDepth 0x40000434 /* testDepth*/
#define XT_testFlags 0x4000042c /* testFlags*/
#define XT_source_2Did 0x40000424 /* source-id*/
#define XT_VP 0x4000041c /* VP*/
#define XT_LAST 0x40000414 /* LAST*/
#define XT_NP 0x4000040c /* NP*/
#define XT_CP 0x40000404 /* CP*/
#define XT_CURRENT 0x400003fc /* CURRENT*/
#define XT_CONTEXT 0x400003f4 /* CONTEXT*/
#define XT_HANDLER 0x400003ec /* HANDLER*/
#define XT_HLD 0x400003e4 /* HLD*/
#define XT_SPARE2 0x400003dc /* SPARE2*/
#define XT_STATE 0x400003d4 /* STATE*/
#define XT_CSP 0x400003cc /* CSP*/
#define XT__23TIB 0x400003c4 /* #TIB*/
#define XT__3EIN 0x400003bc /* >IN*/
#define XT_SPAN 0x400003b4 /* SPAN*/
#define XT_temp 0x400003ac /* temp*/
#define XT_BASE 0x400003a4 /* BASE*/
#define XT__27PROMPT 0x4000039c /* 'PROMPT*/
#define XT__27ECHO 0x40000394 /* 'ECHO*/
#define XT__27TAP 0x4000038c /* 'TAP*/
#define XT_SPARE 0x40000384 /* SPARE*/
#define XT__27EMIT 0x4000037c /* 'EMIT*/
#define XT__27_3FKEY 0x40000374 /* '?KEY*/
#define XT_RP0 0x4000036c /* RP0*/
#define XT_SP0 0x40000364 /* SP0*/
#define XT__5FUSER 0x4000035c /* _USER*/
#define XT__2D_3E 0x40000354 /* ->*/
#define XT__7DT 0x40000348 /* }T*/
#define XT_DEPTH 0x4000033c /* DEPTH*/
#define XT_T_7B 0x40000330 /* T{*/
#define XT_of 0x40000328 /* of*/
#define XT_DEFER 0x40000320 /* DEFER*/
#define XT__3EBODY 0x40000318 /* >BODY*/
#define XT_ALIGN 0x40000314 /* ALIGN*/
#define XT_immediate_3F 0x40000310 /* immediate?*/
#define XT_2RDrop 0x4000030c /* 2RDrop*/
#define XT_RDrop 0x40000308 /* RDrop*/
#define XT_leave 0x40000304 /* leave*/
#define XT_I 0x40000300 /* I*/
#define XT_loop 0x400002fc /* loop*/
#define XT_TYPE 0x400002f8 /* TYPE*/
#define XT_stringBuffer 0x400002f4 /* stringBuffer*/
#define XT_Fbreak 0x400002f0 /* Fbreak*/
#define XT_debugNA 0x400002ec /* debugNA*/
#define XT__27 0x400002e4 /* '*/
#define XT__3B 0x400002d8 /* ;*/
#define XT__3A 0x400002cc /* :*/
#define XT__5D 0x400002c0 /* ]*/
#define XT__5B 0x400002b4 /* [*/
#define XT__24INTERPRET 0x400002a8 /* $INTERPRET*/
#define XT__24COMPILE 0x4000029c /* $COMPILE*/
#define XT_NUMBER_3F 0x40000290 /* NUMBER?*/
#define XT_TOKEN 0x40000284 /* TOKEN*/
#define XT__28 0x40000278 /* (*/
#define XT_PARSE 0x4000026c /* PARSE*/
#define XT_userAreaSave 0x40000264 /* userAreaSave*/
#define XT_userAreaInit 0x40000260 /* userAreaInit*/
#define XT_2_2F 0x4000025c /* 2/*/
#define XT_LSHIFT 0x40000258 /* LSHIFT*/
#define XT_RSHIFT 0x40000254 /* RSHIFT*/
#define XT_UM_2B 0x40000250 /* UM+*/
#define XT_XOR 0x4000024c /* XOR*/
#define XT_OR 0x40000248 /* OR*/
#define XT_AND 0x40000244 /* AND*/
#define XT_0_3C 0x40000240 /* 0<*/
#define XT_ROT 0x4000023c /* ROT*/
#define XT_ROLL 0x40000238 /* ROLL*/
#define XT_OVER 0x40000234 /* OVER*/
#define XT_SWAP 0x40000230 /* SWAP*/
#define XT_DUP 0x4000022c /* DUP*/
#define XT_DROP 0x40000228 /* DROP*/
#define XT_SP_21 0x40000224 /* SP!*/
#define XT_SP_40 0x40000220 /* SP@*/
#define XT_2_3ER 0x4000021c /* 2>R*/
#define XT_2R_40 0x40000218 /* 2R@*/
#define XT_2R_3E 0x40000214 /* 2R>*/
#define XT__3ER 0x40000210 /* >R*/
#define XT_R_40 0x4000020c /* R@*/
#define XT_R_3E 0x40000208 /* R>*/
#define XT_RP_21 0x40000204 /* RP!*/
#define XT_RP_40 0x40000200 /* RP@*/
#define XT_C_21 0x400001fc /* C!*/
#define XT_C_40 0x400001f8 /* C@*/
#define XT__40 0x400001f4 /* @*/
#define XT__21 0x400001f0 /* !*/
#define XT_branch 0x400001ec /* branch*/
#define XT__3Fbranch 0x400001e8 /* ?branch*/
#define XT_next 0x400001e4 /* next*/
#define XT_DOES_3E 0x400001e0 /* DOES>*/
#define XT_doLit 0x400001dc /* doLit*/
#define XT__21IO 0x400001d8 /* !IO*/
#define XT_TX_21 0x400001d4 /* TX!*/
#define XT__3FRX 0x400001d0 /* ?RX*/
#define XT_EXECUTE 0x400001cc /* EXECUTE*/
#define XT_EXIT 0x400001c8 /* EXIT*/
#define XT_BYE 0x400001c4 /* BYE*/
#define XT_ms 0x400001c0 /* ms*/
#define XT__24_2Cn 0x400001b8 /* $,n*/
#define XT_OVERT 0x400001ac /* OVERT*/
#define XT_FIND_2DNAME_2DIN 0x400001a4 /* FIND-NAME-IN*/
#define XT_ALIGNED 0x400001a0 /* ALIGNED*/
#define XT_tokenValue 0x40000198 /* tokenValue*/
#define XT_tokenDefer 0x40000190 /* tokenDefer*/
#define XT_tokenCreate 0x40000188 /* tokenCreate*/
#define XT_tokenVar 0x40000180 /* tokenVar*/
#define XT_tokenUser 0x40000178 /* tokenUser*/
#define XT_tokenDoList 0x40000170 /* tokenDoList*/
#define XT_tokenNextVal 0x40000168 /* tokenNextVal*/
#define XT_tokenVocabulary 0x40000160 /* tokenVocabulary*/
#define XT_BL 0x40000158 /* BL*/
#define XT_FALSE 0x40000150 /* FALSE*/
#define XT_TRUE 0x40000148 /* TRUE*/
#define XT_BYTEMASK 0x40000140 /* BYTEMASK*/
#define XT_IMED 0x40000138 /* IMED*/
#define XT_COMP 0x40000130 /* COMP*/
#define XT_rqFiles 0x40000128 /* rqFiles*/
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
void (* const f[FUNCTIONSLENGTH])() PROGMEM = {
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
/* 0x40000000 _USER */ 0x29,
/* 0x40000004 undefined */ 0,
/* 0x40000008 undefined */ 0,
/* 0x4000000c undefined */ 0,
/* 0x40000010 SP0 */ 0x9cc0,
/* 0x40000014 RP0 */ 0x9ee0,
/* 0x40000018 '?KEY */ XT__3FRX,
/* 0x4000001c 'EMIT */ XT_TX_21,
/* 0x40000020 SPARE */ 0,
/* 0x40000024 'TAP */ 0,
/* 0x40000028 'ECHO */ XT_TX_21,
/* 0x4000002c 'PROMPT */ 0,
/* 0x40000030 BASE */ 0xa,
/* 0x40000034 temp */ 0,
/* 0x40000038 SPAN */ 0,
/* 0x4000003c >IN */ 0xd,
/* 0x40000040 #TIB */ 0x3a,
/* 0x40000044 undefined */ TIB0,
/* 0x40000048 CSP */ 0,
/* 0x4000004c STATE */ 0,
/* 0x40000050 SPARE2 */ 0,
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
/* 0x40000088 CP */ 0x94,
/* 0x4000008c NP */ 0x9ac0,
/* 0x40000090 LAST */ 0x4000a7b8,
/* 0x40000094 VP */ 0,
/* 0x40000098 source-id */ 0,
/* 0x4000009c testFlags */ 0,
/* 0x400000a0 testDepth */ 1,
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
/* 0x40000128: rqFiles */ F_tokenNextVal, 0, 
/* 0x40000130: COMP */ F_tokenNextVal, 0x40, 
/* 0x40000138: IMED */ F_tokenNextVal, 0x80, 
/* 0x40000140: BYTEMASK */ F_tokenNextVal, 0x1f, 
/* 0x40000148: TRUE */ F_tokenNextVal, 0xffffffff, 
/* 0x40000150: FALSE */ F_tokenNextVal, 0, 
/* 0x40000158: BL */ F_tokenNextVal, 0x20, 
/* 0x40000160: tokenVocabulary */ F_tokenNextVal, 1, 
/* 0x40000168: tokenNextVal */ F_tokenNextVal, 2, 
/* 0x40000170: tokenDoList */ F_tokenNextVal, 3, 
/* 0x40000178: tokenUser */ F_tokenNextVal, 4, 
/* 0x40000180: tokenVar */ F_tokenNextVal, 5, 
/* 0x40000188: tokenCreate */ F_tokenNextVal, 6, 
/* 0x40000190: tokenDefer */ F_tokenNextVal, 7, 
/* 0x40000198: tokenValue */ F_tokenNextVal, 8, 
/* 0x400001a0: ALIGNED */ F_ALIGNED, 
/* 0x400001a4: FIND-NAME-IN */ F_findNameIn, 0xb, 
/* 0x400001ac: OVERT */ F_tokenDefer, XT_, 0xc, 
/* 0x400001b8: $,n */ F_tokenDefer, XT_, 
/* 0x400001c0: ms */ F_ms, 
/* 0x400001c4: BYE */ F_BYE, 
/* 0x400001c8: EXIT */ F_EXIT, 
/* 0x400001cc: EXECUTE */ F_EXECUTE, 
/* 0x400001d0: ?RX */ F_QRX, 
/* 0x400001d4: TX! */ F_TXstore, 
/* 0x400001d8: !IO */ F_storeIO, 
/* 0x400001dc: doLit */ F_doLit, 
/* 0x400001e0: DOES> */ F_DOES, 
/* 0x400001e4: next */ F_next, 
/* 0x400001e8: ?branch */ F_qBranch, 
/* 0x400001ec: branch */ F_branch, 
/* 0x400001f0: ! */ F_store, 
/* 0x400001f4: @ */ F_fetch, 
/* 0x400001f8: C@ */ F_CFetch, 
/* 0x400001fc: C! */ F_CStore, 
/* 0x40000200: RP@ */ F_RPat, 
/* 0x40000204: RP! */ F_RPStore, 
/* 0x40000208: R> */ F_Rfrom, 
/* 0x4000020c: R@ */ F_Rat, 
/* 0x40000210: >R */ F_toR, 
/* 0x40000214: 2R> */ F_TwoRfrom, 
/* 0x40000218: 2R@ */ F_TwoRFetch, 
/* 0x4000021c: 2>R */ F_TwotoR, 
/* 0x40000220: SP@ */ F_SPat, 
/* 0x40000224: SP! */ F_SPbang, 
/* 0x40000228: DROP */ F_DROP, 
/* 0x4000022c: DUP */ F_DUP, 
/* 0x40000230: SWAP */ F_SWAP, 
/* 0x40000234: OVER */ F_OVER, 
/* 0x40000238: ROLL */ F_ROLL, 
/* 0x4000023c: ROT */ F_ROT, 
/* 0x40000240: 0< */ F_zeroLess, 
/* 0x40000244: AND */ F_AND, 
/* 0x40000248: OR */ F_OR, 
/* 0x4000024c: XOR */ F_XOR, 
/* 0x40000250: UM+ */ F_UMplus, 
/* 0x40000254: RSHIFT */ F_RSHIFT, 
/* 0x40000258: LSHIFT */ F_LSHIFT, 
/* 0x4000025c: 2/ */ F_TwoDiv, 
/* 0x40000260: userAreaInit */ F_userAreaInit, 
/* 0x40000264: userAreaSave */ F_userAreaSave, 0x37, 
/* 0x4000026c: PARSE */ F_tokenDefer, XT_, 0x38, 
/* 0x40000278: ( */ F_tokenDefer, 0x40003048, 0x39, 
/* 0x40000284: TOKEN */ F_tokenDefer, XT_, 0x3a, 
/* 0x40000290: NUMBER? */ F_tokenDefer, 0x40002bd0, 0x3b, 
/* 0x4000029c: $COMPILE */ F_tokenDefer, XT_, 0x3c, 
/* 0x400002a8: $INTERPRET */ F_tokenDefer, XT_, 0x3d, 
/* 0x400002b4: [ */ F_tokenDefer, XT_, 0x3e, 
/* 0x400002c0: ] */ F_tokenDefer, 0x40002768, 0x3f, 
/* 0x400002cc: : */ F_tokenDefer, 0x4000277c, 0x40, 
/* 0x400002d8: ; */ F_tokenDefer, XT_, 0x41, 
/* 0x400002e4: ' */ F_tokenDefer, XT_, 
/* 0x400002ec: debugNA */ F_debugNA, 
/* 0x400002f0: Fbreak */ F_Fbreak, 
/* 0x400002f4: stringBuffer */ F_stringBuffer, 
/* 0x400002f8: TYPE */ F_TYPE, 
/* 0x400002fc: loop */ F_loop, 
/* 0x40000300: I */ F_I, 
/* 0x40000304: leave */ F_leave, 
/* 0x40000308: RDrop */ F_RDrop, 
/* 0x4000030c: 2RDrop */ F_TwoRDrop, 
/* 0x40000310: immediate? */ F_immediateQ, 
/* 0x40000314: ALIGN */ F_vpAlign, 
/* 0x40000318: >BODY */ F_toBODY, 0x4e, 
/* 0x40000320: DEFER */ F_tokenDefer, 0x40002798, 
/* 0x40000328: of */ F_of, 0x50, 
/* 0x40000330: T{ */ F_tokenDefer, 0x4000032c, 0x51, 
/* 0x4000033c: DEPTH */ F_tokenDefer, XT_, 0x52, 
/* 0x40000348: }T */ F_tokenDefer, 0x40000344, 0x53, 
/* 0x40000354: -> */ F_tokenDefer, 0x40000350, 
/* 0x4000035c: _USER */ F_tokenUser, 0, 
/* 0x40000364: SP0 */ F_tokenUser, 4, 
/* 0x4000036c: RP0 */ F_tokenUser, 5, 
/* 0x40000374: '?KEY */ F_tokenUser, 6, 
/* 0x4000037c: 'EMIT */ F_tokenUser, 7, 
/* 0x40000384: SPARE */ F_tokenUser, 8, 
/* 0x4000038c: 'TAP */ F_tokenUser, 9, 
/* 0x40000394: 'ECHO */ F_tokenUser, 0xa, 
/* 0x4000039c: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x400003a4: BASE */ F_tokenUser, 0xc, 
/* 0x400003ac: temp */ F_tokenUser, 0xd, 
/* 0x400003b4: SPAN */ F_tokenUser, 0xe, 
/* 0x400003bc: >IN */ F_tokenUser, 0xf, 
/* 0x400003c4: #TIB */ F_tokenUser, 0x10, 
/* 0x400003cc: CSP */ F_tokenUser, 0x12, 
/* 0x400003d4: STATE */ F_tokenUser, 0x13, 
/* 0x400003dc: SPARE2 */ F_tokenUser, 0x14, 
/* 0x400003e4: HLD */ F_tokenUser, 0x15, 
/* 0x400003ec: HANDLER */ F_tokenUser, 0x16, 
/* 0x400003f4: CONTEXT */ F_tokenUser, 0x17, 
/* 0x400003fc: CURRENT */ F_tokenUser, 0x20, 
/* 0x40000404: CP */ F_tokenUser, 0x22, 
/* 0x4000040c: NP */ F_tokenUser, 0x23, 
/* 0x40000414: LAST */ F_tokenUser, 0x24, 
/* 0x4000041c: VP */ F_tokenUser, 0x25, 
/* 0x40000424: source-id */ F_tokenUser, 0x26, 
/* 0x4000042c: testFlags */ F_tokenUser, 0x27, 
/* 0x40000434: testDepth */ F_tokenUser, 0x28, 
/* 0x4000043c: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x4000044c: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x40000470: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x40000480: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x40000490: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x400004a8: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x400004b8: TUCK */ F_tokenDoList, XT_SWAP, XT_OVER, XT_EXIT, 
/* 0x400004c8: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x400004d8: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x400004e8: CELL+ */ F_tokenDoList, XT_CELLL, XT__2B, XT_EXIT, 
/* 0x400004f8: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x4000051c: COMPILE, */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x40000528: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x40000538: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x40000558: LITERAL */ F_tokenDoList, XT_COMPILE, XT_doLit, XT__2C, XT_EXIT, 
/* 0x4000056c: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x40000590: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x400005a0: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x400005ac: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x400005b8: >MARK */ F_tokenDoList, XT_HERE, XT_doLit, 0, XT__2C, XT_EXIT, 
/* 0x400005d0: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x400005e4: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x400005f8: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x40000604: NEXT */ F_tokenDoList, XT_COMPILE, XT_next, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000618: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x4000062c: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000640: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x40000654: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x40000668: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000678: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000684: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x4000069c: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x400006b0: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x400006c0: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x400006d0: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0x14, XT_DUP, XT_EXIT, 
/* 0x400006e8: >RESOLVES */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVES + 0x1c, XT__3ERESOLVE, XT_branch, XT__3ERESOLVES + 4, XT_EXIT, 
/* 0x40000708: >MARKSTART */ F_tokenDoList, XT_doLit, 0, XT_EXIT, 
/* 0x40000718: >MARKTHREAD */ F_tokenDoList, XT_HERE, XT_SWAP, XT__2C, XT_EXIT, 
/* 0x4000072c: >RESOLVETHREAD */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVETHREAD + 0x28, XT_DUP, XT__40, XT_SWAP, XT__3ERESOLVE, XT_branch, XT__3ERESOLVETHREAD + 4, XT_EXIT, 
/* 0x40000758: CASE */ F_tokenDoList, XT__3EMARKSTART, XT_EXIT, 
/* 0x40000764: OF */ F_tokenDoList, XT_COMPILE, XT_of, XT__3EMARK, XT_EXIT, 
/* 0x40000778: ENDOF */ F_tokenDoList, XT_COMPILE, XT_branch, XT_SWAP, XT__3EMARKTHREAD, XT_SWAP, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000798: ENDCASE */ F_tokenDoList, XT_COMPILE, XT_DROP, XT__3ERESOLVETHREAD, XT_EXIT, 
/* 0x400007ac: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0x18, XT_FALSE, XT_branch, XT_0_3D + 0x1c, XT_TRUE, XT_EXIT, 
/* 0x400007cc: 0<> */ F_tokenDoList, XT_0_3D, XT_0_3D, XT_EXIT, 
/* 0x400007dc: D0= */ F_tokenDoList, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x400007ec: ?\ */ F_tokenDoList, XT_0_3D, XT__3Fbranch, XT__3F_5C + 0x14, XT__5C, XT_EXIT, 
/* 0x40000804: ?safe\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 4, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x40000824: ?test\ */ F_tokenDoList, XT_testFlags, XT__40, XT_doLit, 8, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x40000844: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x4000085c: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x4000086c: 2OVER */ F_tokenDoList, XT__3ER, XT__3ER, XT_2DUP, XT_R_3E, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x40000890: 2SWAP */ F_tokenDoList, XT__3ER, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x400008a8: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x400008d0: INVERT */ F_tokenDoList, XT_doLit, 0xffffffff, XT_XOR, XT_EXIT, 
/* 0x400008e4: 1+ */ F_tokenDoList, XT_doLit, 1, XT__2B, XT_EXIT, 
/* 0x400008f8: NEGATE */ F_tokenDoList, XT_INVERT, XT_1_2B, XT_EXIT, 
/* 0x40000908: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT_doLit, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40000930: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x40000940: 1- */ F_tokenDoList, XT_doLit, 1, XT__2D, XT_EXIT, 
/* 0x40000954: ?negate */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT__3Fnegate + 0x14, XT_NEGATE, XT_EXIT, 
/* 0x4000096c: ABS */ F_tokenDoList, XT_DUP, XT__3Fnegate, XT_EXIT, 
/* 0x4000097c: CHAR+ */ F_tokenDoList, XT_1_2B, XT_EXIT, 
/* 0x40000988: C, */ F_tokenDoList, XT_HERE, XT_DUP, XT_CHAR_2B, XT_CP, XT__21, XT_C_21, XT_EXIT, 
/* 0x400009a8: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0x18, XT_FALSE, XT_EXIT, XT_TRUE, XT_EXIT, 
/* 0x400009c8: <> */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3C_3E + 0x18, XT_TRUE, XT_EXIT, XT_FALSE, XT_EXIT, 
/* 0x400009e8: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x24, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x40000a18: U> */ F_tokenDoList, XT_SWAP, XT_U_3C, XT_EXIT, 
/* 0x40000a28: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x28, XT_2DROP, XT_TRUE, XT_branch, XT_ud_3C + 0x2c, XT_U_3C, XT_EXIT, 
/* 0x40000a58: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x24, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x40000a88: > */ F_tokenDoList, XT_SWAP, XT__3C, XT_EXIT, 
/* 0x40000a98: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0x18, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x40000ab8: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0x1c, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x40000adc: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x40000afc: S>D */ F_tokenDoList, XT_DUP, XT_0_3C, XT_EXIT, 
/* 0x40000b0c: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0xa8, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x94, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x8c, XT__3ER, XT_DROP, XT_1_2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x90, XT_DROP, XT_R_3E, XT_next, XT_UM_2FMOD + 0x28, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT_doLit, 0xffffffff, XT_DUP, XT_EXIT, 
/* 0x40000bcc: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x2c, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x48, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x68, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x40000c38: FM/MOD */ F_tokenDoList, XT_M_2FMOD, XT_EXIT, 
/* 0x40000c44: /MOD */ F_tokenDoList, XT__3ER, XT_S_3ED, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x40000c5c: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x40000c6c: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000c7c: UM* */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x60, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x60, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT_next, XT_UM_2A + 0x20, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x40000cf0: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x40000d00: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x34, XT_DNEGATE, XT_EXIT, 
/* 0x40000d38: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x40000d50: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000d60: D0< */ F_tokenDoList, XT_NIP, XT_0_3C, XT_EXIT, 
/* 0x40000d70: DABS */ F_tokenDoList, XT_2DUP, XT_D0_3C, XT__3Fbranch, XT_DABS + 0x18, XT_DNEGATE, XT_EXIT, 
/* 0x40000d8c: SM/REM */ F_tokenDoList, XT_2DUP, XT_XOR, XT__3ER, XT_OVER, XT__3ER, XT_ABS, XT__3ER, XT_DABS, XT_R_3E, XT_UM_2FMOD, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_EXIT, 
/* 0x40000dd4: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x40000de4: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x40000df4: CHARS */ F_tokenDoList, XT_EXIT, 
/* 0x40000dfc: 2* */ F_tokenDoList, XT_doLit, 2, XT__2A, XT_EXIT, 
/* 0x40000e10: ($,n) */ F_tokenDoList, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_DUP, XT_CP, XT__21, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, 
/* 0x40000e68: :NONAME */ F_tokenDoList, XT_NP, XT__40, XT_CELL_2D, XT_doLit, 0, XT_OVER, XT__21, XT_DUP, XT_NP, XT__21, XT__28_24_2Cn_29, XT_HERE, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x40000eac: DEFER@ */ F_tokenDoList, XT__3EBODY, XT__40, XT_EXIT, 
/* 0x40000ebc: >BODY! */ F_tokenDoList, XT__3EBODY, XT__21, XT_EXIT, 
/* 0x40000ecc: DEFER! */ F_tokenDoList, XT__3EBODY_21, XT_EXIT, 
/* 0x40000ed8: >CHAR */ F_tokenDoList, XT_doLit, 0x7f, XT_AND, XT_DUP, XT_doLit, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x38, XT_DROP, XT_doLit, 0x5f, XT_EXIT, 
/* 0x40000f14:  */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x40000f38: PICK */ F_tokenDoList, XT_1_2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x40000f54: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x40000f74: ++ */ F_tokenDoList, XT_doLit, 1, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x40000f8c: -- */ F_tokenDoList, XT_doLit, 0xffffffff, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x40000fa4: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x40000fc0: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x40000fdc: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0x1c, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x40001000: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x38, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x3c, XT__2C, XT_EXIT, 
/* 0x40001040: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x4000105c: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x30, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x34, XT_CREATE, XT_EXIT, 
/* 0x40001094: PAD */ F_tokenDoList, XT_HERE, XT_doLit, 0x50, XT__2B, XT_EXIT, 
/* 0x400010ac: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x400010c0: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x18, XT_EXECUTE, XT_EXIT, 
/* 0x400010dc: COUNT */ F_tokenDoList, XT_DUP, XT_1_2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x400010f4: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x30, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2B, XT_R_3E, XT_1_2B, XT_next, XT_CMOVE + 0x10, XT_2DROP, XT_EXIT, 
/* 0x40001134: CMOVE> */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_R_3E, XT__3ER, XT_branch, XT_CMOVE_3E + 0x58, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2D, XT_R_3E, XT_1_2D, XT_next, XT_CMOVE_3E + 0x38, XT_2DROP, XT_EXIT, 
/* 0x4000119c: MOVE */ F_tokenDoList, XT__3ER, XT_2DUP, XT__3E, XT_R_3E, XT_SWAP, XT__3Fbranch, XT_MOVE + 0x2c, XT_CMOVE, XT_branch, XT_MOVE + 0x30, XT_CMOVE_3E, XT_EXIT, 
/* 0x400011d0: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x24, XT_2DUP, XT_C_21, XT_1_2B, XT_next, XT_FILL + 0x18, XT_2DROP, XT_EXIT, 
/* 0x40001204: ERASE */ F_tokenDoList, XT_doLit, 0, XT_FILL, XT_EXIT, 
/* 0x40001218: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x3c, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x3c, XT_R_3E, XT_1_2B, XT_EXIT, XT_next, XT__2DTRAILING + 0x10, XT_doLit, 0, XT_EXIT, 
/* 0x40001268: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT_doLit, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_1_2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x400012cc: DIGIT */ F_tokenDoList, XT_doLit, 9, XT_OVER, XT__3C, XT_doLit, 7, XT_AND, XT__2B, XT_doLit, 0x30, XT__2B, XT_EXIT, 
/* 0x40001300: EXTRACT */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT_R_40, XT_FM_2FMOD, XT_R_3E, XT_SWAP, XT__3ER, XT_FM_2FMOD, XT_R_3E, XT_ROT, XT_DIGIT, XT_EXIT, 
/* 0x40001338: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x4000134c: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_1_2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x40001370: HOLDS */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_HOLDS + 0x2c, XT_1_2D, XT_2DUP, XT__2B, XT_C_40, XT_HOLD, XT_branch, XT_HOLDS + 4, XT_2DROP, XT_EXIT, 
/* 0x400013a4: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x400013bc: #S */ F_tokenDoList, XT__23, XT_2DUP, XT_OR, XT__3Fbranch, XT__23S + 0x20, XT_branch, XT__23S + 4, XT_EXIT, 
/* 0x400013e0: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0x1c, XT_doLit, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x40001400: #> */ F_tokenDoList, XT_2DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x40001420: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x40001430: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x40001440: emits */ F_tokenDoList, XT_SWAP, XT_doLit, 0, XT_MAX, XT__3ER, XT_branch, XT_emits + 0x28, XT_DUP, XT_EMIT, XT_next, XT_emits + 0x20, XT_DROP, XT_EXIT, 
/* 0x40001478: SPACES */ F_tokenDoList, XT_BL, XT_emits, XT_EXIT, 
/* 0x40001488: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x40001498: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT_doLit, 0, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x400014c8: HEX */ F_tokenDoList, XT_doLit, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x400014e0: DECIMAL */ F_tokenDoList, XT_doLit, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x400014f8: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x4000151c: U.R */ F_tokenDoList, XT__3ER, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x40001550: U. */ F_tokenDoList, XT_doLit, 0, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x40001574: . */ F_tokenDoList, XT_BASE, XT__40, XT_doLit, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x28, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x400015ac: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x400015bc: DIGIT? */ F_tokenDoList, XT__3ER, XT_doLit, 0x30, XT__2D, XT_doLit, 0x2a, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x38, XT_doLit, 0x20, XT__2D, XT_doLit, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x70, XT_doLit, 7, XT__2D, XT_DUP, XT_doLit, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x4000163c: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x4000164c: KEY */ F_tokenDoList, XT_doLit, 0, XT_ms, XT_doLit, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 0xc, XT_NIP, XT_EXIT, 
/* 0x40001678: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x28, XT_2DROP, XT_KEY, XT_doLit, 0xd, XT__3D, XT_EXIT, 
/* 0x400016a4: PACE */ F_tokenDoList, XT_doLit, 0xb, XT_EMIT, XT_EXIT, 
/* 0x400016b8: CR */ F_tokenDoList, XT_doLit, 0xd, XT_EMIT, XT_doLit, 0xa, XT_EMIT, XT_EXIT, 
/* 0x400016d8: ['] */ F_tokenDoList, XT__27, XT_LITERAL, XT_EXIT, 
/* 0x400016e8: SOURCE */ F_tokenDoList, XT_TIB, XT__23TIB, XT__40, XT_EXIT, 
/* 0x400016fc: /STRING */ F_tokenDoList, XT_TUCK, XT__2D, XT__3ER, XT__2B, XT_R_3E, XT_EXIT, 
/* 0x40001718: isspace? */ F_tokenDoList, XT_BL, XT_1_2B, XT_U_3C, XT_EXIT, 
/* 0x4000172c: isnotspace? */ F_tokenDoList, XT_isspace_3F, XT_0_3D, XT_EXIT, 
/* 0x4000173c: xt-skip */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_xt_2Dskip + 0x40, XT_OVER, XT_C_40, XT_R_40, XT_EXECUTE, XT__3Fbranch, XT_xt_2Dskip + 0x40, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_xt_2Dskip + 8, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x40001788: skip-till */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_skip_2Dtill + 0x44, XT_OVER, XT_C_40, XT_R_40, XT__3D, XT_0_3D, XT__3Fbranch, XT_skip_2Dtill + 0x44, XT_doLit, 1, XT__2FSTRING, XT_branch, XT_skip_2Dtill + 8, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x400017d8:  */ F_tokenDoList, XT__3ER, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x40001810, XT_doLit, XT_isspace_3F, XT_xt_2Dskip, XT_OVER, XT_SWAP, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x40001840, XT_doLit, XT_isnotspace_3F, XT_xt_2Dskip, XT_branch, 0x40001848, XT_R_40, XT_skip_2Dtill, XT_R_3E, XT_DROP, XT_2DUP, XT_doLit, 1, XT_MIN, XT__2B, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x40001888: PARSE-NAME */ F_tokenDoList, XT_BL, XT_PARSE, XT_EXIT, 
/* 0x40001898: CHAR */ F_tokenDoList, XT_PARSE_2DNAME, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x400018ac: [CHAR] */ F_tokenDoList, XT_CHAR, XT_LITERAL, XT_EXIT, 
/* 0x400018bc: CTRL */ F_tokenDoList, XT_CHAR, XT_doLit, 0x1f, XT_AND, XT_EXIT, 
/* 0x400018d4: .( */ F_tokenDoList, XT_doLit, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x400018ec:  */ F_tokenDoList, XT_PARSE_2DNAME, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x4000191c: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x40001930: NAME>INTERPRET */ F_tokenDoList, XT_doLit, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x4000194c: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x54, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x54, XT_R_3E, XT_DROP, XT_EXIT, XT_next, XT_SAME_3F + 0x10, XT_FALSE, XT_EXIT, 
/* 0x400019b0: FIND-NAME */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_FIND_2DNAME + 0x20, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT__3ER, XT_R_40, XT__40, XT__3Fbranch, XT_FIND_2DNAME + 0x70, XT_2DUP, XT_R_40, XT__40, XT_FIND_2DNAME_2DIN, XT__3FDUP, XT__3Fbranch, XT_FIND_2DNAME + 0x24, XT_R_3E, XT_DROP, XT_NIP, XT_NIP, XT_EXIT, XT_R_3E, XT_DROP, XT_2DROP, XT_FALSE, XT_EXIT, 
/* 0x40001a34: NAME? */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x34, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_branch, XT_NAME_3F + 0x38, XT_FALSE, XT_EXIT, 
/* 0x40001a70: FIND */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_FIND + 0x58, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_immediate_3F, XT__3Fbranch, XT_FIND + 0x48, XT_doLit, 1, XT_branch, XT_FIND + 0x50, XT_doLit, 0xffffffff, XT_branch, XT_FIND + 0x60, XT_doLit, 0, XT_EXIT, 
/* 0x40001ad4: MARKER */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT_CONTEXT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CURRENT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CREATE, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT_DOES_3E, XT_DUP, XT__40, XT_CURRENT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CURRENT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CP, XT__21, XT_CELL_2B, XT__40, XT_NP, XT__21, XT_EXIT, 
/* 0x40001bac: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT_doLit, 0, XT_EXIT, 
/* 0x40001bf4: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x40, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40001c38: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x4c, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT_doLit, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40001c90: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x40001cb0: crlf? */ F_tokenDoList, XT_DUP, XT_doLit, 0xa, XT__3D, XT_SWAP, XT_doLit, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x40001cdc: skipCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipCRLF + 0x24, XT_OVER, XT_C_40, XT_crlf_3F, XT_branch, XT_skipCRLF + 0x28, XT_FALSE, XT__3Fbranch, XT_skipCRLF + 0x48, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipCRLF + 4, XT_EXIT, 
/* 0x40001d28: skipToCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipToCRLF + 0x28, XT_OVER, XT_C_40, XT_crlf_3F, XT_0_3D, XT_branch, XT_skipToCRLF + 0x2c, XT_FALSE, XT__3Fbranch, XT_skipToCRLF + 0x4c, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipToCRLF + 4, XT_EXIT, 
/* 0x40001d78: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x60, XT_DUP, XT_doLit, 8, XT__3D, XT_SWAP, XT_doLit, 0x7f, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x58, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x5c, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x40001de8: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40001e14: $," */ F_tokenDoList, XT_doLit, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x40001e3c: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x40001e48: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x40001e58: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x40001e68: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001e7c: C" */ F_tokenDoList, XT__24_22, XT_EXIT, 
/* 0x40001e88: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001e9c: S" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_22 + 0x28, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_branch, XT_S_22 + 0x40, XT_doLit, 0x22, XT_PARSE, XT_stringBuffer, XT_PACK_24, XT_COUNT, XT_EXIT, 
/* 0x40001ee0: bu+@ */ F_tokenDoList, XT_1_2D, XT__3ER, XT_COUNT, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x40001efc: c+! */ F_tokenDoList, XT_TUCK, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x40001f10: cmove\ */ F_tokenDoList, XT_SWAP, XT_DUP, XT__3ER, XT__3ER, XT__3FDUP, XT__3Fbranch, 0x400021e4, XT_bu_2B_40, XT_DUP, XT_doLit, 0x22, XT__3C_3E, XT__3Fbranch, 0x400021e0, XT_doLit, 0x5c, XT_of, 0x400021c4, XT_bu_2B_40, XT_doLit, 0x6d, XT_of, XT_cmove_5C + 0x8c, XT_doLit, 0xd, XT_R_3E, XT_c_2B_21, XT_doLit, 0xa, XT_SWAP, XT_c_2B_21, XT__3ER, XT_branch, 0x400021bc, XT_doLit, 0x78, XT_of, XT_cmove_5C + 0xf0, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_doLit, 0x10, XT__2A, XT__3ER, XT_bu_2B_40, XT_doLit, 0x10, XT_DIGIT_3F, XT_DROP, XT_R_3E, XT__2B, XT_R_3E, XT_c_2B_21, XT__3ER, XT_branch, 0x400021bc, XT_doLit, 0x61, XT_of, 0x40002020, XT_doLit, 7, XT_branch, 0x400021a8, XT_doLit, 0x62, XT_of, 0x40002040, XT_doLit, 8, XT_branch, 0x400021a8, XT_doLit, 0x65, XT_of, 0x40002060, XT_doLit, 0x1b, XT_branch, 0x400021a8, XT_doLit, 0x66, XT_of, 0x40002080, XT_doLit, 0xc, XT_branch, 0x400021a8, XT_doLit, 0x6c, XT_of, 0x400020a0, XT_doLit, 0xa, XT_branch, 0x400021a8, XT_doLit, 0x6e, XT_of, 0x400020c0, XT_doLit, 0xa, XT_branch, 0x400021a8, XT_doLit, 0x71, XT_of, 0x400020e0, XT_doLit, 0x22, XT_branch, 0x400021a8, XT_doLit, 0x72, XT_of, 0x40002100, XT_doLit, 0xd, XT_branch, 0x400021a8, XT_doLit, 0x74, XT_of, 0x40002120, XT_doLit, 9, XT_branch, 0x400021a8, XT_doLit, 0x76, XT_of, 0x40002140, XT_doLit, 0xb, XT_branch, 0x400021a8, XT_doLit, 0x7a, XT_of, 0x40002160, XT_doLit, 0, XT_branch, 0x400021a8, XT_doLit, 0x22, XT_of, 0x40002180, XT_doLit, 0x22, XT_branch, 0x400021a8, XT_doLit, 0x5c, XT_of, 0x400021a0, XT_doLit, 0x5c, XT_branch, 0x400021a8, XT_DUP, XT_DROP, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, 0x400021d8, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, XT_cmove_5C + 0x14, XT_2DROP, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x400021f4: pack\$ */ F_tokenDoList, XT_ALIGNED, XT__3ER, XT_R_40, XT_1_2B, XT_SWAP, XT_cmove_5C, XT_DUP, XT_R_40, XT_C_21, XT_DUP, XT_R_40, XT__2B, XT_1_2B, XT_SWAP, XT_doLit, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__3FDUP, XT__3Fbranch, XT_pack_5C_24 + 0x84, XT_SWAP, XT_doLit, 0, XT_OVER, XT_C_21, XT_1_2B, XT_SWAP, XT_1_2D, XT_branch, XT_pack_5C_24 + 0x50, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40002284: S\" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x28, XT_COMPILE, XT_S_22_7C, XT_HERE, XT_branch, XT_S_5C_22 + 0x2c, XT_stringBuffer, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_ROT, XT_pack_5C_24, XT_SWAP, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_COUNT, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x80, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x40002308: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x40002314: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x40002324: abort" */ F_tokenDoList, XT__3Fbranch, XT_abort_22 + 0x14, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x40002344: ABORT" */ F_tokenDoList, XT_COMPILE, XT_abort_22, XT__24_2C_22, XT_EXIT, 
/* 0x40002358: POSTPONE */ F_tokenDoList, XT_TOKEN, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT_0_3D, XT_abort_22, 0x746f4e09, 0x756f6620, 0x646e, XT_DUP, XT_immediate_3F, XT_0_3D, XT__3Fbranch, XT_POSTPONE + 0x44, XT_COMPILE, XT_COMPILE, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x400023a8:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x400023e8, XT_C_40, XT_doLit, 0x40, XT_AND, XT_abort_22, 0x6d6f630c, 0x656c6970, 0x4c4e4f20, 0x59, XT_EXECUTE, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x400023f8, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40002400: .OK */ F_tokenDoList, XT_STATE, XT__40, XT_0_3D, XT__3Fbranch, XT__2EOK + 0x20, XT__2E_22_7C, 0x6b6f2003, XT_CR, XT_EXIT, 
/* 0x40002428: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT_abort_22, 0x646e7509, 0x6c667265, 0x776f, XT_EXIT, 
/* 0x40002448:  */ F_tokenDoList, XT_FALSE, XT_STATE, XT__21, XT_EXIT, 
/* 0x4000245c: XIO */ F_tokenDoList, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x4000247c: FILE */ F_tokenDoList, XT_doLit, 0, XT_doLit, XT_DROP, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x400024a0: HAND */ F_tokenDoList, XT_doLit, XT__2EOK, XT_doLit, XT_EMIT, XT_doLit, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x400024c4: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x400024d4: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x400024f0:  */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, 0x40002508, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40002510: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x40002520: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x24, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x28, XT_ALLOT, XT_EXIT, 
/* 0x4000254c: BUFFER: */ F_tokenDoList, XT_CREATE, XT_vALLOT, XT_EXIT, 
/* 0x4000255c: '>BODY! */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT__27_3EBODY_21 + 0x28, XT__5B_27_5D, XT_COMPILE, XT__3EBODY_21, XT_branch, XT__27_3EBODY_21 + 0x30, XT__27, XT__3EBODY_21, XT_EXIT, 
/* 0x40002590: IS */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x4000259c: ACTION-OF */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_ACTION_2DOF + 0x28, XT__5B_27_5D, XT_COMPILE, XT_DEFER_40, XT_branch, XT_ACTION_2DOF + 0x30, XT__27, XT_DEFER_40, XT_EXIT, 
/* 0x400025d0: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x400025e8: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x28, XT__2E_22_7C, 0x65722007, 0x20666544, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x40002618:  */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, 0x40002638, XT__3FUNIQUE, XT__28_24_2Cn_29, XT_EXIT, XT__24_22_7C, 0x6d616e04, 0x65, XT_THROW, XT_EXIT, 
/* 0x4000264c:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x40002688, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, 0x40002680, XT_EXECUTE, XT_branch, 0x40002684, XT__2C, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x4000269c, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x400026a4: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x44, XT_STATE, XT__40, XT__3Fbranch, XT_EVAL + 0x34, XT__24COMPILE, XT_branch, XT_EVAL + 0x38, XT__24INTERPRET, XT__3FSTACK, XT_branch, XT_EVAL + 4, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x400026f8:  */ F_tokenDoList, XT_LAST, XT__40, XT_DUP, XT__40, XT__3Fbranch, 0x40002728, XT_CURRENT, XT__40, XT__21, XT_branch, 0x4000274c, XT_DROP, XT_NP, XT__40, XT_doLit, 3, XT_CELLS, XT__2B, XT_NP, XT__21, XT_EXIT, 
/* 0x40002750:  */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 3, XT_TRUE, XT_STATE, XT__21, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDefer, XT__2C, XT_doLit, 0, XT__2C, XT_OVERT, XT_EXIT, 
/* 0x400027c0: VALUE */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_HERE, XT_tokenValue, XT__2C, XT__5FUSER, XT__40, XT__2C, XT__5FUSER, XT__2B_2B, XT__3EBODY_21, XT_EXIT, 
/* 0x400027f8: TO */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x40002804: VARIABLE */ F_tokenDoList, XT_vCREATE, XT_doLit, 0, XT_v_2C, XT_EXIT, 
/* 0x4000281c: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x4000283c: leave-ptr */ F_tokenVar, 0, 0xc, 
/* 0x40002848: (?do) */ F_tokenDoList, XT_R_3E, XT__2DROT, XT_2DUP, XT_2_3ER, XT__3C_3E, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x4000286c: (loop) */ F_tokenDoList, XT_R_3E, XT_2R_3E, XT_1_2B, XT_2DUP, XT_2_3ER, XT__3D, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40002894: (+loop) */ F_tokenDoList, XT_R_3E, XT_SWAP, XT_2R_3E, XT_doLit, 2, XT_PICK, XT_OVER, XT__2B, XT_ROT, XT_DUP, XT__3ER, XT__2DROT, XT_DUP, XT__3ER, XT_doLit, 3, XT_PICK, XT_0_3C, XT__3Fbranch, XT__28_2Bloop_29 + 0x58, XT_SWAP, XT_1_2B, XT_SWAP, XT_1_2B, XT_SWAP, XT_WITHIN, XT_NIP, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40002910: leave, */ F_tokenDoList, XT_HERE, XT_leave_2Dptr, XT__40, XT__2C, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x40002930: LEAVE */ F_tokenDoList, XT_COMPILE, XT_branch, XT_leave_2C, XT_EXIT, 
/* 0x40002944: UNLOOP */ F_tokenDoList, XT_COMPILE, XT_2RDrop, XT_EXIT, 
/* 0x40002954: DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT_2_3ER, XT_HERE, XT_EXIT, 
/* 0x40002980: ?DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT_doLit, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT__28_3Fdo_29, XT_COMPILE, XT__3Fbranch, XT_leave_2C, XT_HERE, XT_EXIT, 
/* 0x400029b8: some-loop */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__2C, XT_leave_2Dptr, XT__40, XT__3FDUP, XT__3Fbranch, XT_some_2Dloop + 0x48, XT_DUP, XT__40, XT__3ER, XT_HERE, XT_SWAP, XT__21, XT_R_3E, XT_branch, XT_some_2Dloop + 0x18, XT_UNLOOP, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x40002a10: LOOP */ F_tokenDoList, XT_COMPILE, XT__28loop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x40002a24: +LOOP */ F_tokenDoList, XT_COMPILE, XT__28_2Bloop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x40002a38: I-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 2, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a58: J */ F_tokenDoList, XT_RP_40, XT_doLit, 3, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a78: J-MAX */ F_tokenDoList, XT_RP_40, XT_doLit, 4, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a98: accumulate */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_BASE, XT__40, XT_UM_2A, XT_DROP, XT_ROT, XT_BASE, XT__40, XT_UM_2A, XT_D_2B, XT_R_3E, XT_EXIT, 
/* 0x40002ad4: >NUMBER */ F_tokenDoList, XT_doLit, 0, XT_SWAP, XT_doLit, 0, XT__28_3Fdo_29, XT__3Fbranch, XT__3ENUMBER + 0x78, XT_DROP, XT_COUNT, XT_BASE, XT__40, XT_DIGIT_3F, XT_0_3D, XT__3Fbranch, XT__3ENUMBER + 0x60, XT_DROP, XT_1_2D, XT_I_2DMAX, XT_I, XT__2D, XT_branch, XT__3ENUMBER + 0x78, XT_accumulate, XT_doLit, 0, XT__28loop_29, XT__3Fbranch, XT__3ENUMBER + 0x24, XT_2RDrop, XT_EXIT, 
/* 0x40002b54: (charbase) */ F_tokenDoList, XT_DUP, XT_doLit, 0x23, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x28, XT_doLit, 0xa, XT_EXIT, XT_DUP, XT_doLit, 0x24, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x4c, XT_doLit, 0x10, XT_EXIT, XT_DUP, XT_doLit, 0x25, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x70, XT_doLit, 2, XT_EXIT, XT_doLit, 0, XT_EXIT, 3, XT_DUP, XT_BASE, XT__40, XT__3ER, XT_COUNT, XT_OVER, XT__3ER, XT__3ER, XT_COUNT, XT__28charbase_29, XT__3FDUP, XT__3Fbranch, XT__28charbase_29 + 0xc4, XT_BASE, XT__21, XT_DROP, XT_COUNT, XT_DUP, XT_doLit, 0x27, XT__3D, XT__3Fbranch, 0x40002c88, XT_DROP, XT_COUNT, XT_SWAP, XT_COUNT, XT_doLit, 0x27, XT__3C_3E, XT__3Fbranch, 0x40002c68, XT_2DROP, XT_2RDrop, XT_FALSE, XT_branch, 0x40002c78, XT_DROP, XT_NIP, XT_TRUE, XT_2RDrop, XT_R_3E, XT_BASE, XT__21, XT_EXIT, XT_doLit, 0x2d, XT__3D, XT_TUCK, XT_0_3D, XT__3Fbranch, 0x40002ca8, XT_1_2D, XT_doLit, 0, XT_doLit, 0, XT_ROT, XT_R_3E, XT_R_3E, XT__2B, XT_OVER, XT__2D, XT__3ENUMBER, XT__3Fbranch, 0x40002cf0, XT_2DROP, XT_2DROP, XT_FALSE, XT_branch, 0x40002d10, XT_DROP, XT_ROT, XT__3Fbranch, 0x40002d04, XT_DNEGATE, XT_DROP, XT_NIP, XT_TRUE, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x40002d20: ACCEPT */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_ACCEPT + 0x60, XT_KEY, XT_DUP, XT_BL, XT__2D, XT_doLit, 0x5f, XT_U_3C, XT__3Fbranch, XT_ACCEPT + 0x50, XT_TAP, XT_branch, XT_ACCEPT + 0x58, XT__27TAP, XT__40EXECUTE, XT_branch, XT_ACCEPT + 0x10, XT_DROP, XT_SWAP, XT__2D, XT_EXIT, 
/* 0x40002d90: stack */ F_tokenDoList, XT_CREATE, XT_HERE, XT_doLit, 0, XT__2C, XT_OVER, XT__2C, XT_vHERE, XT_SWAP, XT__21, XT_doLit, 0, XT_v_2C, XT_CELLS, XT_vALLOT, XT_EXIT, 
/* 0x40002dd4: spop */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_CELLS, XT_OVER, XT__2B, XT__40, XT_SWAP, XT__2D_2D, XT_EXIT, 
/* 0x40002e00: spush */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_1_2B, XT_2DUP, XT_SWAP, XT__21, XT_CELLS, XT__2B, XT__21, XT_EXIT, 
/* 0x40002e30: spushes */ F_tokenDoList, XT_OVER, XT__3ER, XT_SWAP, XT_doLit, 0, XT_2_3ER, XT_TUCK, XT_spush, XT__28loop_29, XT__3Fbranch, XT_spushes + 0x1c, XT_2RDrop, XT_R_3E, XT_SWAP, XT_spush, XT_EXIT, 
/* 0x40002e74: spops */ F_tokenDoList, XT_DUP, XT_spop, XT__3ER, XT_R_40, XT_doLit, 0, XT_2_3ER, XT_DUP, XT_spop, XT_SWAP, XT__28loop_29, XT__3Fbranch, XT_spops + 0x20, XT_2RDrop, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40002ebc: sempty */ F_tokenDoList, XT__40, XT_doLit, 0, XT_SWAP, XT__21, XT_EXIT, 
/* 0x40002ed8: SOURCE-ID */ F_tokenDoList, XT_source_2Did, XT__40, XT_EXIT, 
/* 0x40002ee8: sourceStack */ F_tokenCreate, 0, 0x10, 0x20, 
/* 0x40002ef8: 0> */ F_tokenDoList, XT_DUP, XT_0_3D, XT_SWAP, XT_0_3C, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x40002f18: unreadFile */ F_tokenDefer, 0, 
/* 0x40002f20: SAVE-INPUT */ F_tokenDoList, XT_SOURCE_2DID, XT_SOURCE, XT__3EIN, XT__40, XT_doLit, 4, XT_EXIT, 
/* 0x40002f40: sourcePush */ F_tokenDoList, XT_SAVE_2DINPUT, XT_sourceStack, XT_spushes, XT_EXIT, 
/* 0x40002f54: RESTORE-INPUT */ F_tokenDoList, XT_DROP, XT__3EIN, XT__21, XT__23TIB, XT__21, XT__23TIB, XT_CELL_2B, XT__21, XT_DUP, XT_source_2Did, XT__21, XT__3Fbranch, XT_RESTORE_2DINPUT + 0x44, XT_FILE, XT_branch, XT_RESTORE_2DINPUT + 0x48, XT_HAND, XT_doLit, 0, XT_EXIT, 
/* 0x40002fa8: sourcePop */ F_tokenDoList, XT_sourceStack, XT_spops, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x40002fc0: READ-LINE */ F_tokenDefer, 0, 
/* 0x40002fc8: REFILL */ F_tokenDoList, XT_SOURCE_2DID, XT__3FDUP, XT__3Fbranch, XT_REFILL + 0x34, XT_DROP, XT_FALSE, XT_doLit, 0, XT__3EIN, XT__21, XT_branch, XT_REFILL + 0x60, XT_TIB, XT_doLit, 0x50, XT_ACCEPT, XT__23TIB, XT__21, XT_doLit, 0, XT__3EIN, XT__21, XT_TRUE, XT_EXIT, 
/* 0x4000302c: QUERY */ F_tokenDoList, XT_REFILL, XT_0_3D, XT__3Fbranch, XT_QUERY + 0x18, XT_sourcePop, XT_EXIT, 3, XT_doLit, 0x29, XT_PARSE, XT__2B, XT_C_40, XT_doLit, 0x29, XT__3C_3E, XT__3Fbranch, XT_QUERY + 0x70, XT_REFILL, XT_0_3D, XT_abort_22, 0x746e7514, 0x696d7265, 0x6574616e, 0x6f632064, 0x6e656d6d, 0x74, XT_QUERY + 0x1c, XT_EXIT, 
/* 0x400030a0: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x400030b0: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_sourceStack, XT_sempty, XT_doLit, 0, XT_TIB0, XT_doLit, 0, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x400030f8: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x54, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT_doLit, 0x5e, XT_emits, XT_CR, XT__2E_24, XT__2E_22_7C, 0x203f2003, XT_PRESET, XT_EXIT, 
/* 0x40003154: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT_doLit, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x14, XT__27PROMPT, XT__40, XT__3ER, XT_CONSOLE, XT_quitError, XT_R_3E, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x58, XT__27PROMPT, XT__21, XT_branch, XT_QUIT + 0x10, XT_EXIT, 
/* 0x400031b8: quit1 */ F_tokenDoList, XT_doLit, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x24, XT_quitError, XT__5B, XT_EXIT, 
/* 0x400031e0: EVALUATE */ F_tokenDoList, XT_sourcePush, XT_doLit, 0xffffffff, XT__2DROT, XT_doLit, 0, XT_doLit, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_quit1, XT_EXIT, 
/* 0x40003214: dm+ */ F_tokenDoList, XT_OVER, XT_doLit, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x3c, XT_DUP, XT_C_40, XT_doLit, 3, XT_U_2ER, XT_1_2B, XT_next, XT_dm_2B + 0x24, XT_EXIT, 
/* 0x4000325c: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT_doLit, 0x10, XT__2F, XT__3ER, XT_CR, XT_doLit, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT_doLit, 2, XT_SPACES, XT_TYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x6c, XT_next, XT_DUMP + 0x24, XT_branch, XT_DUMP + 0x74, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x400032e4: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x24, XT_R_40, XT_PICK, XT__2E, XT_next, XT__2ES + 0x18, XT__2E_22_7C, 0x733c2005, 0x2070, XT_EXIT, 
/* 0x40003320: UNUSED */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT__2D, XT_EXIT, 
/* 0x4000333c: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x40003360: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x40003378: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x4000338c: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT_abort_22, 0x6174730b, 0x64206b63, 0x68747065, XT_EXIT, 
/* 0x400033b4: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x24, XT_COUNT, XT_BYTEMASK, XT_AND, XT_TYPE, XT_EXIT, XT__2E_22_7C, 0x6f6e7b08, 0x656d614e, 0x7d, XT_EXIT, 
/* 0x400033ec: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x40, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 0x10, XT_DROP, XT_EXIT, 
/* 0x40003430: >NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 0x6c, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT__3ENAME + 0x50, XT_2DUP, XT_NAME_3EINTERPRET, XT_XOR, XT__3Fbranch, XT__3ENAME + 0x50, XT_CELL_2D, XT_branch, XT__3ENAME + 0x20, XT_NIP, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 8, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_FALSE, XT_EXIT, 
/* 0x400034a8: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0xd0, XT__2E_22_7C, 0x203a02, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x54, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0xb0, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT_doLit, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT_doLit, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0xa8, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0xbc, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x38, XT_branch, XT_SEE + 0xec, XT__2E_22_7C, 0x746f4e14, 0x6c6f6320, 0x64206e6f, 0x6e696665, 0x6f697469, 0x6e, XT_DROP, XT_EXIT, 
/* 0x4000359c: VER */ F_tokenNextVal, 0x11, 
/* 0x400035a4: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x6265770a, 0x54524f46, 0x562048, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT_doLit, 0, XT__3C_23, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23, XT_doLit, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x4000361c: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x4000362c: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x4000364c: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x40003658: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 4, XT_EXIT, 
/* 0x40003688: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x400036a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400036e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400037a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400037e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400038a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400038e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400039a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400039e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400040a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400040e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400041a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400041e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400042a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400042e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400043a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400043e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400044a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400044e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400045a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400045e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400046a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400046e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400047a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400047e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400048a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400048e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400049a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400049e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400050a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400050e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400051a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400051e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400052a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400052e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400053a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400053e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400054a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400054e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400055a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400055e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400056a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400056e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400057a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400057e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400058a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400058e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400059a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400059e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400060a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400060e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400061a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400061e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400062a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400062e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400063a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400063e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400064a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400064e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400065a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400065e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400066a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400066e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400067a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400067e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400068a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400068e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400069a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400069e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400070a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400070e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400071a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400071e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400072a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400072e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400073a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400073e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400074a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400074e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400075a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400075e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400076a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400076e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400077a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400077e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400078a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400078e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400079a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400079e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400080a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400080e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400081a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400081e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400082a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400082e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400083a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400083e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400084a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400084e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400085a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400085e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400086a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400086e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400087a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400087e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400088a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400088e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400089a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400089e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400090a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400090e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400091a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400091e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400092a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400092e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400093a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400093e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400094a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400094e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400095a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400095e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400096a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400096e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400097a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400097e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009820: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009860: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400098a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400098e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009920: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009960: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400099a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400099e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009a20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009a60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009aa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ae0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009b20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009b60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ba0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009be0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009c20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009c60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ca0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ce0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009d20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009d60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009da0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009de0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009e20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009e60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ea0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ee0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009f20: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009f60: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009fa0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009fe0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a020: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a060: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a0a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a0e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a120: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a160: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a1a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a1e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a220: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a260: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a2a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a2e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a320: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a360: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a3a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a3e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a420: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a460: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a4a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a4e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a520: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a560: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a5a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a5e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a620: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a660: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a6a0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a6e0: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a720: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a760: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a7a0: */ 0x6573750c, 0x65724172, 0x76615361, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x4000a7b0 WARM */ XT_WARM, 0x4000a7c8, 0x52415704, 0x4d,
/* 0x4000a7c0 COLD */ XT_COLD, 0x4000a7d8, 0x4c4f4304, 0x44,
/* 0x4000a7d0 'BOOT */ XT__27BOOT, 0x4000a7e8, 0x4f422705, 0x544f,
/* 0x4000a7e0 EMPTY */ XT_EMPTY, 0x4000a7f8, 0x504d4505, 0x5954,
/* 0x4000a7f0 hi */ XT_hi, 0x4000a804, 0x696842,
/* 0x4000a7fc version */ XT_version, 0x4000a814, 0x72657607, 0x6e6f6973,
/* 0x4000a80c VER */ XT_VER, 0x4000a820, 0x52455603,
/* 0x4000a818 SEE */ XT_SEE, 0x4000a82c, 0x45455303,
/* 0x4000a824 >NAME */ XT__3ENAME, 0x4000a83c, 0x414e3e05, 0x454d,
/* 0x4000a834 WORDS */ XT_WORDS, 0x4000a84c, 0x524f5705, 0x5344,
/* 0x4000a844 .ID */ XT__2EID, 0x4000a858, 0x44492e03,
/* 0x4000a850 ?CSP */ XT__3FCSP, 0x4000a868, 0x53433f04, 0x50,
/* 0x4000a860 !CSP */ XT__21CSP, 0x4000a878, 0x53432104, 0x50,
/* 0x4000a870 .FREE */ XT__2EFREE, 0x4000a888, 0x52462e05, 0x4545,
/* 0x4000a880 .BASE */ XT__2EBASE, 0x4000a898, 0x41422e05, 0x4553,
/* 0x4000a890 UNUSED */ XT_UNUSED, 0x4000a8a8, 0x554e5506, 0x444553,
/* 0x4000a8a0 .S */ XT__2ES, 0x4000a8b4, 0x532e02,
/* 0x4000a8ac DUMP */ XT_DUMP, 0x4000a8c4, 0x4d554404, 0x50,
/* 0x4000a8bc dm+ */ XT_dm_2B, 0x4000a8d0, 0x2b6d6403,
/* 0x4000a8c8 EVALUATE */ XT_EVALUATE, 0x4000a8e4, 0x41564508, 0x5441554c, 0x45,
/* 0x4000a8dc quit1 */ XT_quit1, 0x4000a8f4, 0x69757105, 0x3174,
/* 0x4000a8ec QUIT */ XT_QUIT, 0x4000a904, 0x49555104, 0x54,
/* 0x4000a8fc quitError */ XT_quitError, 0x4000a918, 0x69757109, 0x72724574, 0x726f,
/* 0x4000a910 PRESET */ XT_PRESET, 0x4000a928, 0x45525006, 0x544553,
/* 0x4000a920 que */ XT_que, 0x4000a934, 0x65757103,
/* 0x4000a92c QUERY */ XT_QUERY, 0x4000a944, 0x45555105, 0x5952,
/* 0x4000a93c REFILL */ XT_REFILL, 0x4000a954, 0x46455206, 0x4c4c49,
/* 0x4000a94c READ-LINE */ XT_READ_2DLINE, 0x4000a968, 0x41455209, 0x494c2d44, 0x454e,
/* 0x4000a960 sourcePop */ XT_sourcePop, 0x4000a97c, 0x756f7309, 0x50656372, 0x706f,
/* 0x4000a974 RESTORE-INPUT */ XT_RESTORE_2DINPUT, 0x4000a994, 0x5345520d, 0x45524f54, 0x504e492d, 0x5455,
/* 0x4000a98c sourcePush */ XT_sourcePush, 0x4000a9a8, 0x756f730a, 0x50656372, 0x687375,
/* 0x4000a9a0 SAVE-INPUT */ XT_SAVE_2DINPUT, 0x4000a9bc, 0x5641530a, 0x4e492d45, 0x545550,
/* 0x4000a9b4 unreadFile */ XT_unreadFile, 0x4000a9d0, 0x726e750a, 0x46646165, 0x656c69,
/* 0x4000a9c8 0> */ XT_0_3E, 0x4000a9dc, 0x3e3002,
/* 0x4000a9d4 sourceStack */ XT_sourceStack, 0x4000a9f0, 0x756f730b, 0x53656372, 0x6b636174,
/* 0x4000a9e8 SOURCE-ID */ XT_SOURCE_2DID, 0x4000aa04, 0x554f5309, 0x2d454352, 0x4449,
/* 0x4000a9fc sempty */ XT_sempty, 0x4000aa14, 0x6d657306, 0x797470,
/* 0x4000aa0c spops */ XT_spops, 0x4000aa24, 0x6f707305, 0x7370,
/* 0x4000aa1c spushes */ XT_spushes, 0x4000aa34, 0x75707307, 0x73656873,
/* 0x4000aa2c spush */ XT_spush, 0x4000aa44, 0x75707305, 0x6873,
/* 0x4000aa3c spop */ XT_spop, 0x4000aa54, 0x6f707304, 0x70,
/* 0x4000aa4c stack */ XT_stack, 0x4000aa64, 0x61747305, 0x6b63,
/* 0x4000aa5c ACCEPT */ XT_ACCEPT, 0x4000aa74, 0x43434106, 0x545045,
/* 0x4000aa6c (charbase) */ XT__28charbase_29, 0x4000aa88, 0x6863280a, 0x61627261, 0x296573,
/* 0x4000aa80 >NUMBER */ XT__3ENUMBER, 0x4000aa98, 0x554e3e07, 0x5245424d,
/* 0x4000aa90 accumulate */ XT_accumulate, 0x4000aaac, 0x6363610a, 0x6c756d75, 0x657461,
/* 0x4000aaa4 J-MAX */ XT_J_2DMAX, 0x4000aabc, 0x4d2d4a05, 0x5841,
/* 0x4000aab4 J */ XT_J, 0x4000aac8, 0x4a01,
/* 0x4000aac0 I-MAX */ XT_I_2DMAX, 0x4000aad8, 0x4d2d4905, 0x5841,
/* 0x4000aad0 +LOOP */ XT__2BLOOP, 0x4000aae8, 0x4f4c2b85, 0x504f,
/* 0x4000aae0 LOOP */ XT_LOOP, 0x4000aaf8, 0x4f4f4c84, 0x50,
/* 0x4000aaf0 some-loop */ XT_some_2Dloop, 0x4000ab0c, 0x6d6f7309, 0x6f6c2d65, 0x706f,
/* 0x4000ab04 ?DO */ XT__3FDO, 0x4000ab18, 0x4f443f83,
/* 0x4000ab10 DO */ XT_DO, 0x4000ab24, 0x4f4482,
/* 0x4000ab1c UNLOOP */ XT_UNLOOP, 0x4000ab34, 0x4c4e5586, 0x504f4f,
/* 0x4000ab2c LEAVE */ XT_LEAVE, 0x4000ab44, 0x41454c85, 0x4556,
/* 0x4000ab3c leave, */ XT_leave_2C, 0x4000ab54, 0x61656c06, 0x2c6576,
/* 0x4000ab4c (+loop) */ XT__28_2Bloop_29, 0x4000ab64, 0x6c2b2807, 0x29706f6f,
/* 0x4000ab5c (loop) */ XT__28loop_29, 0x4000ab74, 0x6f6c2806, 0x29706f,
/* 0x4000ab6c (?do) */ XT__28_3Fdo_29, 0x4000ab84, 0x643f2805, 0x296f,
/* 0x4000ab7c leave-ptr */ XT_leave_2Dptr, 0x4000ab98, 0x61656c09, 0x702d6576, 0x7274,
/* 0x4000ab90 CONSTANT */ XT_CONSTANT, 0x4000abac, 0x4e4f4308, 0x4e415453, 0x54,
/* 0x4000aba4 VARIABLE */ XT_VARIABLE, 0x4000abc0, 0x52415608, 0x4c424149, 0x45,
/* 0x4000abb8 TO */ XT_TO, 0x4000abcc, 0x4f5482,
/* 0x4000abc4 VALUE */ XT_VALUE, 0x4000abdc, 0x4c415605, 0x4555,
/* 0x4000abd4  */ XT_, 0x4000abe8, 0xc0,
/* 0x4000abe0  */ XT_, 0x4000abf4, 0,
/* 0x4000abec EVAL */ XT_EVAL, 0x4000ac04, 0x41564504, 0x4c,
/* 0x4000abfc  */ XT_, 0x4000ac10, 0,
/* 0x4000ac08  */ XT_, 0x4000ac1c, 0,
/* 0x4000ac14 ?UNIQUE */ XT__3FUNIQUE, 0x4000ac2c, 0x4e553f07, 0x45555149,
/* 0x4000ac24 RECURSE */ XT_RECURSE, 0x4000ac3c, 0x43455287, 0x45535255,
/* 0x4000ac34 ACTION-OF */ XT_ACTION_2DOF, 0x4000ac50, 0x54434189, 0x2d4e4f49, 0x464f,
/* 0x4000ac48 IS */ XT_IS, 0x4000ac5c, 0x534982,
/* 0x4000ac54 '>BODY! */ XT__27_3EBODY_21, 0x4000ac6c, 0x423e2707, 0x2159444f,
/* 0x4000ac64 BUFFER: */ XT_BUFFER_3A, 0x4000ac7c, 0x46554207, 0x3a524546,
/* 0x4000ac74 vALLOT */ XT_vALLOT, 0x4000ac8c, 0x4c417606, 0x544f4c,
/* 0x4000ac84 ALLOT */ XT_ALLOT, 0x4000ac9c, 0x4c4c4105, 0x544f,
/* 0x4000ac94  */ XT_, 0x4000aca8, 0,
/* 0x4000aca0 CONSOLE */ XT_CONSOLE, 0x4000acb8, 0x4e4f4307, 0x454c4f53,
/* 0x4000acb0 I/O */ XT_I_2FO, 0x4000acc4, 0x4f2f4903,
/* 0x4000acbc HAND */ XT_HAND, 0x4000acd4, 0x4e414804, 0x44,
/* 0x4000accc FILE */ XT_FILE, 0x4000ace4, 0x4c494604, 0x45,
/* 0x4000acdc XIO */ XT_XIO, 0x4000acf0, 0x4f495803,
/* 0x4000ace8  */ XT_, 0x4000acfc, 0x80,
/* 0x4000acf4 ?STACK */ XT__3FSTACK, 0x4000ad0c, 0x54533f06, 0x4b4341,
/* 0x4000ad04 .OK */ XT__2EOK, 0x4000ad18, 0x4b4f2e03,
/* 0x4000ad10  */ XT_, 0x4000ad24, 0,
/* 0x4000ad1c POSTPONE */ XT_POSTPONE, 0x4000ad38, 0x534f5088, 0x4e4f5054, 0x45,
/* 0x4000ad30 ABORT" */ XT_ABORT_22, 0x4000ad48, 0x4f424186, 0x225452,
/* 0x4000ad40 abort" */ XT_abort_22, 0x4000ad58, 0x6f626146, 0x227472,
/* 0x4000ad50 ABORT */ XT_ABORT, 0x4000ad68, 0x4f424105, 0x5452,
/* 0x4000ad60 NULL$ */ XT_NULL_24, 0x4000ad78, 0x4c554e05, 0x244c,
/* 0x4000ad70 S\" */ XT_S_5C_22, 0x4000ad84, 0x225c5383,
/* 0x4000ad7c pack\$ */ XT_pack_5C_24, 0x4000ad94, 0x63617006, 0x245c6b,
/* 0x4000ad8c cmove\ */ XT_cmove_5C, 0x4000ada4, 0x6f6d6306, 0x5c6576,
/* 0x4000ad9c c+! */ XT_c_2B_21, 0x4000adb0, 0x212b6303,
/* 0x4000ada8 bu+@ */ XT_bu_2B_40, 0x4000adc0, 0x2b756204, 0x40,
/* 0x4000adb8 S" */ XT_S_22, 0x4000adcc, 0x225382,
/* 0x4000adc4 ." */ XT__2E_22, 0x4000add8, 0x222e82,
/* 0x4000add0 C" */ XT_C_22, 0x4000ade4, 0x224382,
/* 0x4000addc $" */ XT__24_22, 0x4000adf0, 0x222482,
/* 0x4000ade8 S"| */ XT_S_22_7C, 0x4000adfc, 0x7c225303,
/* 0x4000adf4 ."| */ XT__2E_22_7C, 0x4000ae08, 0x7c222e03,
/* 0x4000ae00 $"| */ XT__24_22_7C, 0x4000ae14, 0x7c222403,
/* 0x4000ae0c $," */ XT__24_2C_22, 0x4000ae20, 0x222c2403,
/* 0x4000ae18 do$ */ XT_do_24, 0x4000ae2c, 0x246f6403,
/* 0x4000ae24 kTAP */ XT_kTAP, 0x4000ae3c, 0x41546b04, 0x50,
/* 0x4000ae34 skipToCRLF */ XT_skipToCRLF, 0x4000ae50, 0x696b730a, 0x436f5470, 0x464c52,
/* 0x4000ae48 skipCRLF */ XT_skipCRLF, 0x4000ae64, 0x696b7308, 0x4c524370, 0x46,
/* 0x4000ae5c crlf? */ XT_crlf_3F, 0x4000ae74, 0x6c726305, 0x3f66,
/* 0x4000ae6c TAP */ XT_TAP, 0x4000ae80, 0x50415403,
/* 0x4000ae78 ^H */ XT__5EH, 0x4000ae8c, 0x485e02,
/* 0x4000ae84 THROW */ XT_THROW, 0x4000ae9c, 0x52485405, 0x574f,
/* 0x4000ae94 CATCH */ XT_CATCH, 0x4000aeac, 0x54414305, 0x4843,
/* 0x4000aea4 MARKER */ XT_MARKER, 0x4000aebc, 0x52414d06, 0x52454b,
/* 0x4000aeb4 FIND */ XT_FIND, 0x4000aecc, 0x4e494604, 0x44,
/* 0x4000aec4 NAME? */ XT_NAME_3F, 0x4000aedc, 0x4d414e05, 0x3f45,
/* 0x4000aed4 FIND-NAME */ XT_FIND_2DNAME, 0x4000aef0, 0x4e494609, 0x414e2d44, 0x454d,
/* 0x4000aee8 SAME? */ XT_SAME_3F, 0x4000af00, 0x4d415305, 0x3f45,
/* 0x4000aef8 NAME>INTERPRET */ XT_NAME_3EINTERPRET, 0x4000af18, 0x4d414e0e, 0x4e493e45, 0x50524554, 0x544552,
/* 0x4000af10 WORD */ XT_WORD, 0x4000af28, 0x524f5704, 0x44,
/* 0x4000af20  */ XT_, 0x4000af34, 0,
/* 0x4000af2c .( */ XT__2E_28, 0x4000af40, 0x282e82,
/* 0x4000af38 CTRL */ XT_CTRL, 0x4000af50, 0x52544304, 0x4c,
/* 0x4000af48 [CHAR] */ XT__5BCHAR_5D, 0x4000af60, 0x48435b86, 0x5d5241,
/* 0x4000af58 CHAR */ XT_CHAR, 0x4000af70, 0x41484304, 0x52,
/* 0x4000af68 PARSE-NAME */ XT_PARSE_2DNAME, 0x4000af84, 0x5241500a, 0x4e2d4553, 0x454d41,
/* 0x4000af7c  */ XT_, 0x4000af90, 0,
/* 0x4000af88 skip-till */ XT_skip_2Dtill, 0x4000afa4, 0x696b7309, 0x69742d70, 0x6c6c,
/* 0x4000af9c xt-skip */ XT_xt_2Dskip, 0x4000afb4, 0x2d747807, 0x70696b73,
/* 0x4000afac isnotspace? */ XT_isnotspace_3F, 0x4000afc8, 0x6e73690b, 0x7073746f, 0x3f656361,
/* 0x4000afc0 isspace? */ XT_isspace_3F, 0x4000afdc, 0x73736908, 0x65636170, 0x3f,
/* 0x4000afd4 /STRING */ XT__2FSTRING, 0x4000afec, 0x54532f07, 0x474e4952,
/* 0x4000afe4 SOURCE */ XT_SOURCE, 0x4000affc, 0x554f5306, 0x454352,
/* 0x4000aff4 ['] */ XT__5B_27_5D, 0x4000b008, 0x5d275b83,
/* 0x4000b000 CR */ XT_CR, 0x4000b014, 0x524302,
/* 0x4000b00c PACE */ XT_PACE, 0x4000b024, 0x43415004, 0x45,
/* 0x4000b01c NUF? */ XT_NUF_3F, 0x4000b034, 0x46554e04, 0x3f,
/* 0x4000b02c KEY */ XT_KEY, 0x4000b040, 0x59454b03,
/* 0x4000b038 ?KEY */ XT__3FKEY, 0x4000b050, 0x454b3f04, 0x59,
/* 0x4000b048 DIGIT? */ XT_DIGIT_3F, 0x4000b060, 0x47494406, 0x3f5449,
/* 0x4000b058 ? */ XT__3F, 0x4000b06c, 0x3f01,
/* 0x4000b064 . */ XT__2E, 0x4000b078, 0x2e01,
/* 0x4000b070 U. */ XT_U_2E, 0x4000b084, 0x2e5502,
/* 0x4000b07c U.R */ XT_U_2ER, 0x4000b090, 0x522e5503,
/* 0x4000b088 .R */ XT__2ER, 0x4000b09c, 0x522e02,
/* 0x4000b094 DECIMAL */ XT_DECIMAL, 0x4000b0ac, 0x43454407, 0x4c414d49,
/* 0x4000b0a4 HEX */ XT_HEX, 0x4000b0b8, 0x58454803,
/* 0x4000b0b0 str */ XT_str, 0x4000b0c4, 0x72747303,
/* 0x4000b0bc .$ */ XT__2E_24, 0x4000b0d0, 0x242e02,
/* 0x4000b0c8 SPACES */ XT_SPACES, 0x4000b0e0, 0x41505306, 0x534543,
/* 0x4000b0d8 emits */ XT_emits, 0x4000b0f0, 0x696d6505, 0x7374,
/* 0x4000b0e8 SPACE */ XT_SPACE, 0x4000b100, 0x41505305, 0x4543,
/* 0x4000b0f8 EMIT */ XT_EMIT, 0x4000b110, 0x494d4504, 0x54,
/* 0x4000b108 #> */ XT__23_3E, 0x4000b11c, 0x3e2302,
/* 0x4000b114 SIGN */ XT_SIGN, 0x4000b12c, 0x47495304, 0x4e,
/* 0x4000b124 #S */ XT__23S, 0x4000b138, 0x532302,
/* 0x4000b130 # */ XT__23, 0x4000b144, 0x2301,
/* 0x4000b13c HOLDS */ XT_HOLDS, 0x4000b154, 0x4c4f4805, 0x5344,
/* 0x4000b14c HOLD */ XT_HOLD, 0x4000b164, 0x4c4f4804, 0x44,
/* 0x4000b15c <# */ XT__3C_23, 0x4000b170, 0x233c02,
/* 0x4000b168 EXTRACT */ XT_EXTRACT, 0x4000b180, 0x54584507, 0x54434152,
/* 0x4000b178 DIGIT */ XT_DIGIT, 0x4000b190, 0x47494405, 0x5449,
/* 0x4000b188 PACK$ */ XT_PACK_24, 0x4000b1a0, 0x43415005, 0x244b,
/* 0x4000b198 -TRAILING */ XT__2DTRAILING, 0x4000b1b4, 0x52542d09, 0x494c4941, 0x474e,
/* 0x4000b1ac ERASE */ XT_ERASE, 0x4000b1c4, 0x41524505, 0x4553,
/* 0x4000b1bc FILL */ XT_FILL, 0x4000b1d4, 0x4c494604, 0x4c,
/* 0x4000b1cc MOVE */ XT_MOVE, 0x4000b1e4, 0x564f4d04, 0x45,
/* 0x4000b1dc CMOVE> */ XT_CMOVE_3E, 0x4000b1f4, 0x4f4d4306, 0x3e4556,
/* 0x4000b1ec CMOVE */ XT_CMOVE, 0x4000b204, 0x4f4d4305, 0x4556,
/* 0x4000b1fc COUNT */ XT_COUNT, 0x4000b214, 0x554f4305, 0x544e,
/* 0x4000b20c @EXECUTE */ XT__40EXECUTE, 0x4000b228, 0x58454008, 0x54554345, 0x45,
/* 0x4000b220 TIB */ XT_TIB, 0x4000b234, 0x42495403,
/* 0x4000b22c PAD */ XT_PAD, 0x4000b240, 0x44415003,
/* 0x4000b238 vCREATE */ XT_vCREATE, 0x4000b250, 0x52437607, 0x45544145,
/* 0x4000b248 vALIGN */ XT_vALIGN, 0x4000b260, 0x4c417606, 0x4e4749,
/* 0x4000b258 v, */ XT_v_2C, 0x4000b26c, 0x2c7602,
/* 0x4000b264 vHERE */ XT_vHERE, 0x4000b27c, 0x45487605, 0x4552,
/* 0x4000b274 2@ */ XT_2_40, 0x4000b288, 0x403202,
/* 0x4000b280 2! */ XT_2_21, 0x4000b294, 0x213202,
/* 0x4000b28c -- */ XT__2D_2D, 0x4000b2a0, 0x2d2d02,
/* 0x4000b298 ++ */ XT__2B_2B, 0x4000b2ac, 0x2b2b02,
/* 0x4000b2a4 +! */ XT__2B_21, 0x4000b2b8, 0x212b02,
/* 0x4000b2b0 PICK */ XT_PICK, 0x4000b2c8, 0x43495004, 0x4b,
/* 0x4000b2c0  */ XT_, 0x4000b2d4, 0,
/* 0x4000b2cc >CHAR */ XT__3ECHAR, 0x4000b2e4, 0x48433e05, 0x5241,
/* 0x4000b2dc DEFER! */ XT_DEFER_21, 0x4000b2f4, 0x46454406, 0x215245,
/* 0x4000b2ec >BODY! */ XT__3EBODY_21, 0x4000b304, 0x4f423e06, 0x215944,
/* 0x4000b2fc DEFER@ */ XT_DEFER_40, 0x4000b314, 0x46454406, 0x405245,
/* 0x4000b30c :NONAME */ XT__3ANONAME, 0x4000b324, 0x4f4e3a07, 0x454d414e,
/* 0x4000b31c ($,n) */ XT__28_24_2Cn_29, 0x4000b334, 0x2c242805, 0x296e,
/* 0x4000b32c 2* */ XT_2_2A, 0x4000b340, 0x2a3202,
/* 0x4000b338 CHARS */ XT_CHARS, 0x4000b350, 0x41484305, 0x5352,
/* 0x4000b348 CELLS */ XT_CELLS, 0x4000b360, 0x4c454305, 0x534c,
/* 0x4000b358 CELL- */ XT_CELL_2D, 0x4000b370, 0x4c454305, 0x2d4c,
/* 0x4000b368 SM/REM */ XT_SM_2FREM, 0x4000b380, 0x2f4d5306, 0x4d4552,
/* 0x4000b378 DABS */ XT_DABS, 0x4000b390, 0x42414404, 0x53,
/* 0x4000b388 D0< */ XT_D0_3C, 0x4000b39c, 0x3c304403,
/* 0x4000b394 * / */ XT__2A_2F, 0x4000b3a8, 0x2f2a02,
/* 0x4000b3a0 * /MOD */ XT__2A_2FMOD, 0x4000b3b8, 0x4d2f2a05, 0x444f,
/* 0x4000b3b0 M* */ XT_M_2A, 0x4000b3c4, 0x2a4d02,
/* 0x4000b3bc * */ XT__2A, 0x4000b3d0, 0x2a01,
/* 0x4000b3c8 UM* */ XT_UM_2A, 0x4000b3dc, 0x2a4d5503,
/* 0x4000b3d4 / */ XT__2F, 0x4000b3e8, 0x2f01,
/* 0x4000b3e0 MOD */ XT_MOD, 0x4000b3f4, 0x444f4d03,
/* 0x4000b3ec /MOD */ XT__2FMOD, 0x4000b404, 0x4f4d2f04, 0x44,
/* 0x4000b3fc FM/MOD */ XT_FM_2FMOD, 0x4000b414, 0x2f4d4606, 0x444f4d,
/* 0x4000b40c M/MOD */ XT_M_2FMOD, 0x4000b424, 0x4d2f4d05, 0x444f,
/* 0x4000b41c UM/MOD */ XT_UM_2FMOD, 0x4000b434, 0x2f4d5506, 0x444f4d,
/* 0x4000b42c S>D */ XT_S_3ED, 0x4000b440, 0x443e5303,
/* 0x4000b438 WITHIN */ XT_WITHIN, 0x4000b450, 0x54495706, 0x4e4948,
/* 0x4000b448 MIN */ XT_MIN, 0x4000b45c, 0x4e494d03,
/* 0x4000b454 MAX */ XT_MAX, 0x4000b468, 0x58414d03,
/* 0x4000b460 > */ XT__3E, 0x4000b474, 0x3e01,
/* 0x4000b46c < */ XT__3C, 0x4000b480, 0x3c01,
/* 0x4000b478 ud< */ XT_ud_3C, 0x4000b48c, 0x3c647503,
/* 0x4000b484 U> */ XT_U_3E, 0x4000b498, 0x3e5502,
/* 0x4000b490 U< */ XT_U_3C, 0x4000b4a4, 0x3c5502,
/* 0x4000b49c <> */ XT__3C_3E, 0x4000b4b0, 0x3e3c02,
/* 0x4000b4a8 = */ XT__3D, 0x4000b4bc, 0x3d01,
/* 0x4000b4b4 C, */ XT_C_2C, 0x4000b4c8, 0x2c4302,
/* 0x4000b4c0 CHAR+ */ XT_CHAR_2B, 0x4000b4d8, 0x41484305, 0x2b52,
/* 0x4000b4d0 ABS */ XT_ABS, 0x4000b4e4, 0x53424103,
/* 0x4000b4dc ?negate */ XT__3Fnegate, 0x4000b4f4, 0x656e3f07, 0x65746167,
/* 0x4000b4ec 1- */ XT_1_2D, 0x4000b500, 0x2d3102,
/* 0x4000b4f8 - */ XT__2D, 0x4000b50c, 0x2d01,
/* 0x4000b504 DNEGATE */ XT_DNEGATE, 0x4000b51c, 0x454e4407, 0x45544147,
/* 0x4000b514 NEGATE */ XT_NEGATE, 0x4000b52c, 0x47454e06, 0x455441,
/* 0x4000b524 1+ */ XT_1_2B, 0x4000b538, 0x2b3102,
/* 0x4000b530 INVERT */ XT_INVERT, 0x4000b548, 0x564e4906, 0x545245,
/* 0x4000b540 D+ */ XT_D_2B, 0x4000b554, 0x2b4402,
/* 0x4000b54c 2SWAP */ XT_2SWAP, 0x4000b564, 0x57533205, 0x5041,
/* 0x4000b55c 2OVER */ XT_2OVER, 0x4000b574, 0x564f3205, 0x5245,
/* 0x4000b56c 2DUP */ XT_2DUP, 0x4000b584, 0x55443204, 0x50,
/* 0x4000b57c -ROT */ XT__2DROT, 0x4000b594, 0x4f522d04, 0x54,
/* 0x4000b58c ?test\ */ XT__3Ftest_5C, 0x4000b5a4, 0x65743f86, 0x5c7473,
/* 0x4000b59c ?safe\ */ XT__3Fsafe_5C, 0x4000b5b4, 0x61733f86, 0x5c6566,
/* 0x4000b5ac ?\ */ XT__3F_5C, 0x4000b5c0, 0x5c3f82,
/* 0x4000b5b8 D0= */ XT_D0_3D, 0x4000b5cc, 0x3d304403,
/* 0x4000b5c4 0<> */ XT_0_3C_3E, 0x4000b5d8, 0x3e3c3003,
/* 0x4000b5d0 0= */ XT_0_3D, 0x4000b5e4, 0x3d3002,
/* 0x4000b5dc ENDCASE */ XT_ENDCASE, 0x4000b5f4, 0x444e4587, 0x45534143,
/* 0x4000b5ec ENDOF */ XT_ENDOF, 0x4000b604, 0x444e4585, 0x464f,
/* 0x4000b5fc OF */ XT_OF, 0x4000b610, 0x464f82,
/* 0x4000b608 CASE */ XT_CASE, 0x4000b620, 0x53414384, 0x45,
/* 0x4000b618 >RESOLVETHREAD */ XT__3ERESOLVETHREAD, 0x4000b638, 0x45523e0e, 0x564c4f53, 0x52485445, 0x444145,
/* 0x4000b630 >MARKTHREAD */ XT__3EMARKTHREAD, 0x4000b64c, 0x414d3e0b, 0x48544b52, 0x44414552,
/* 0x4000b644 >MARKSTART */ XT__3EMARKSTART, 0x4000b660, 0x414d3e0a, 0x54534b52, 0x545241,
/* 0x4000b658 >RESOLVES */ XT__3ERESOLVES, 0x4000b674, 0x45523e09, 0x564c4f53, 0x5345,
/* 0x4000b66c ?DUP */ XT__3FDUP, 0x4000b684, 0x55443f04, 0x50,
/* 0x4000b67c WHILE */ XT_WHILE, 0x4000b694, 0x49485785, 0x454c,
/* 0x4000b68c WHEN */ XT_WHEN, 0x4000b6a4, 0x45485784, 0x4e,
/* 0x4000b69c ELSE */ XT_ELSE, 0x4000b6b4, 0x534c4584, 0x45,
/* 0x4000b6ac AFT */ XT_AFT, 0x4000b6c0, 0x54464183,
/* 0x4000b6b8 THEN */ XT_THEN, 0x4000b6d0, 0x45485484, 0x4e,
/* 0x4000b6c8 REPEAT */ XT_REPEAT, 0x4000b6e0, 0x50455286, 0x544145,
/* 0x4000b6d8 AHEAD */ XT_AHEAD, 0x4000b6f0, 0x45484185, 0x4441,
/* 0x4000b6e8 IF */ XT_IF, 0x4000b6fc, 0x464982,
/* 0x4000b6f4 AGAIN */ XT_AGAIN, 0x4000b70c, 0x41474185, 0x4e49,
/* 0x4000b704 UNTIL */ XT_UNTIL, 0x4000b71c, 0x544e5585, 0x4c49,
/* 0x4000b714 NEXT */ XT_NEXT, 0x4000b72c, 0x58454e84, 0x54,
/* 0x4000b724 BEGIN */ XT_BEGIN, 0x4000b73c, 0x47454285, 0x4e49,
/* 0x4000b734 FOR */ XT_FOR, 0x4000b748, 0x524f4683,
/* 0x4000b740 >RESOLVE */ XT__3ERESOLVE, 0x4000b75c, 0x45523e08, 0x564c4f53, 0x45,
/* 0x4000b754 >MARK */ XT__3EMARK, 0x4000b76c, 0x414d3e05, 0x4b52,
/* 0x4000b764 <RESOLVE */ XT__3CRESOLVE, 0x4000b780, 0x45523c08, 0x564c4f53, 0x45,
/* 0x4000b778 <MARK */ XT__3CMARK, 0x4000b790, 0x414d3c05, 0x4b52,
/* 0x4000b788 CREATE */ XT_CREATE, 0x4000b7a0, 0x45524306, 0x455441,
/* 0x4000b798 create */ XT_create, 0x4000b7b0, 0x65726306, 0x657461,
/* 0x4000b7a8 LITERAL */ XT_LITERAL, 0x4000b7c0, 0x54494c87, 0x4c415245,
/* 0x4000b7b8 COMPILE */ XT_COMPILE, 0x4000b7d0, 0x4d4f4347, 0x454c4950,
/* 0x4000b7c8 [COMPILE] */ XT__5BCOMPILE_5D, 0x4000b7e4, 0x4f435b89, 0x4c49504d, 0x5d45,
/* 0x4000b7dc COMPILE, */ XT_COMPILE_2C, 0x4000b7f8, 0x4d4f4308, 0x454c4950, 0x2c,
/* 0x4000b7f0 , */ XT__2C, 0x4000b804, 0x2c01,
/* 0x4000b7fc CELL+ */ XT_CELL_2B, 0x4000b814, 0x4c454305, 0x2b4c,
/* 0x4000b80c + */ XT__2B, 0x4000b820, 0x2b01,
/* 0x4000b818 HERE */ XT_HERE, 0x4000b830, 0x52454804, 0x45,
/* 0x4000b828 TUCK */ XT_TUCK, 0x4000b840, 0x43555404, 0x4b,
/* 0x4000b838 NIP */ XT_NIP, 0x4000b84c, 0x50494e03,
/* 0x4000b844 \ */ XT__5C, 0x4000b858, 0x5c81,
/* 0x4000b850 IMMEDIATE */ XT_IMMEDIATE, 0x4000b86c, 0x4d4d4909, 0x41494445, 0x4554,
/* 0x4000b864 COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x4000b884, 0x4d4f430c, 0x454c4950, 0x4c4e4f2d, 0x59,
/* 0x4000b87c setHeaderBits */ XT_setHeaderBits, 0x4000b89c, 0x7465730d, 0x64616548, 0x69427265, 0x7374,
/* 0x4000b894 2DROP */ XT_2DROP, 0x4000b8ac, 0x52443205, 0x504f,
/* 0x4000b8a4 testDepth */ XT_testDepth, 0x4000b8c0, 0x73657409, 0x70654474, 0x6874,
/* 0x4000b8b8 testFlags */ XT_testFlags, 0x4000b8d4, 0x73657409, 0x616c4674, 0x7367,
/* 0x4000b8cc source-id */ XT_source_2Did, 0x4000b8e8, 0x756f7309, 0x2d656372, 0x6469,
/* 0x4000b8e0 VP */ XT_VP, 0x4000b8f4, 0x505602,
/* 0x4000b8ec LAST */ XT_LAST, 0x4000b904, 0x53414c04, 0x54,
/* 0x4000b8fc NP */ XT_NP, 0x4000b910, 0x504e02,
/* 0x4000b908 CP */ XT_CP, 0x4000b91c, 0x504302,
/* 0x4000b914 CURRENT */ XT_CURRENT, 0x4000b92c, 0x52554307, 0x544e4552,
/* 0x4000b924 CONTEXT */ XT_CONTEXT, 0x4000b93c, 0x4e4f4307, 0x54584554,
/* 0x4000b934 HANDLER */ XT_HANDLER, 0x4000b94c, 0x4e414807, 0x52454c44,
/* 0x4000b944 HLD */ XT_HLD, 0x4000b958, 0x444c4803,
/* 0x4000b950 SPARE2 */ XT_SPARE2, 0x4000b968, 0x41505306, 0x324552,
/* 0x4000b960 STATE */ XT_STATE, 0x4000b978, 0x41545305, 0x4554,
/* 0x4000b970 CSP */ XT_CSP, 0x4000b984, 0x50534303,
/* 0x4000b97c #TIB */ XT__23TIB, 0x4000b994, 0x49542304, 0x42,
/* 0x4000b98c >IN */ XT__3EIN, 0x4000b9a0, 0x4e493e03,
/* 0x4000b998 SPAN */ XT_SPAN, 0x4000b9b0, 0x41505304, 0x4e,
/* 0x4000b9a8 temp */ XT_temp, 0x4000b9c0, 0x6d657404, 0x70,
/* 0x4000b9b8 BASE */ XT_BASE, 0x4000b9d0, 0x53414204, 0x45,
/* 0x4000b9c8 'PROMPT */ XT__27PROMPT, 0x4000b9e0, 0x52502707, 0x54504d4f,
/* 0x4000b9d8 'ECHO */ XT__27ECHO, 0x4000b9f0, 0x43452705, 0x4f48,
/* 0x4000b9e8 'TAP */ XT__27TAP, 0x4000ba00, 0x41542704, 0x50,
/* 0x4000b9f8 SPARE */ XT_SPARE, 0x4000ba10, 0x41505305, 0x4552,
/* 0x4000ba08 'EMIT */ XT__27EMIT, 0x4000ba20, 0x4d452705, 0x5449,
/* 0x4000ba18 '?KEY */ XT__27_3FKEY, 0x4000ba30, 0x4b3f2705, 0x5945,
/* 0x4000ba28 RP0 */ XT_RP0, 0x4000ba3c, 0x30505203,
/* 0x4000ba34 SP0 */ XT_SP0, 0x4000ba48, 0x30505303,
/* 0x4000ba40 _USER */ XT__5FUSER, 0x4000ba58, 0x53555f05, 0x5245,
/* 0x4000ba50 -> */ XT__2D_3E, 0x4000ba64, 0x3e2d02,
/* 0x4000ba5c }T */ XT__7DT, 0x4000ba70, 0x547d02,
/* 0x4000ba68 DEPTH */ XT_DEPTH, 0x4000ba80, 0x50454405, 0x4854,
/* 0x4000ba78 T{ */ XT_T_7B, 0x4000ba8c, 0x7b5402,
/* 0x4000ba84 of */ XT_of, 0x4000ba98, 0x666f02,
/* 0x4000ba90 DEFER */ XT_DEFER, 0x4000baa8, 0x46454405, 0x5245,
/* 0x4000baa0 >BODY */ XT__3EBODY, 0x4000bab8, 0x4f423e05, 0x5944,
/* 0x4000bab0 ALIGN */ XT_ALIGN, 0x4000bac8, 0x494c4105, 0x4e47,
/* 0x4000bac0 immediate? */ XT_immediate_3F, 0x4000badc, 0x6d6d690a, 0x61696465, 0x3f6574,
/* 0x4000bad4 2RDrop */ XT_2RDrop, 0x4000baec, 0x44523206, 0x706f72,
/* 0x4000bae4 RDrop */ XT_RDrop, 0x4000bafc, 0x72445205, 0x706f,
/* 0x4000baf4 leave */ XT_leave, 0x4000bb0c, 0x61656c05, 0x6576,
/* 0x4000bb04 I */ XT_I, 0x4000bb18, 0x4901,
/* 0x4000bb10 loop */ XT_loop, 0x4000bb28, 0x6f6f6c04, 0x70,
/* 0x4000bb20 TYPE */ XT_TYPE, 0x4000bb38, 0x50595404, 0x45,
/* 0x4000bb30 stringBuffer */ XT_stringBuffer, 0x4000bb50, 0x7274730c, 0x42676e69, 0x65666675, 0x72,
/* 0x4000bb48 Fbreak */ XT_Fbreak, 0x4000bb60, 0x72624606, 0x6b6165,
/* 0x4000bb58 debugNA */ XT_debugNA, 0x4000bb70, 0x62656407, 0x414e6775,
/* 0x4000bb68 ' */ XT__27, 0x4000bb7c, 0x2701,
/* 0x4000bb74 ; */ XT__3B, 0x4000bb88, 0x3b81,
/* 0x4000bb80 : */ XT__3A, 0x4000bb94, 0x3a01,
/* 0x4000bb8c ] */ XT__5D, 0x4000bba0, 0x5d01,
/* 0x4000bb98 [ */ XT__5B, 0x4000bbac, 0x5b81,
/* 0x4000bba4 $INTERPRET */ XT__24INTERPRET, 0x4000bbc0, 0x4e49240a, 0x50524554, 0x544552,
/* 0x4000bbb8 $COMPILE */ XT__24COMPILE, 0x4000bbd4, 0x4f432408, 0x4c49504d, 0x45,
/* 0x4000bbcc NUMBER? */ XT_NUMBER_3F, 0x4000bbe4, 0x4d554e07, 0x3f524542,
/* 0x4000bbdc TOKEN */ XT_TOKEN, 0x4000bbf4, 0x4b4f5405, 0x4e45,
/* 0x4000bbec ( */ XT__28, 0x4000bc00, 0x2881,
/* 0x4000bbf8 PARSE */ XT_PARSE, 0x4000bc10, 0x52415005, 0x4553,
/* 0x4000bc08 userAreaSave */ XT_userAreaSave, 0x4000bc28, 0x6573750c, 0x65724172, 0x76615361, 0x65,
/* 0x4000bc20 userAreaInit */ XT_userAreaInit, 0x4000bc40, 0x6573750c, 0x65724172, 0x696e4961, 0x74,
/* 0x4000bc38 2/ */ XT_2_2F, 0x4000bc4c, 0x2f3202,
/* 0x4000bc44 LSHIFT */ XT_LSHIFT, 0x4000bc5c, 0x48534c06, 0x544649,
/* 0x4000bc54 RSHIFT */ XT_RSHIFT, 0x4000bc6c, 0x48535206, 0x544649,
/* 0x4000bc64 UM+ */ XT_UM_2B, 0x4000bc78, 0x2b4d5503,
/* 0x4000bc70 XOR */ XT_XOR, 0x4000bc84, 0x524f5803,
/* 0x4000bc7c OR */ XT_OR, 0x4000bc90, 0x524f02,
/* 0x4000bc88 AND */ XT_AND, 0x4000bc9c, 0x444e4103,
/* 0x4000bc94 0< */ XT_0_3C, 0x4000bca8, 0x3c3002,
/* 0x4000bca0 ROT */ XT_ROT, 0x4000bcb4, 0x544f5203,
/* 0x4000bcac ROLL */ XT_ROLL, 0x4000bcc4, 0x4c4f5204, 0x4c,
/* 0x4000bcbc OVER */ XT_OVER, 0x4000bcd4, 0x45564f04, 0x52,
/* 0x4000bccc SWAP */ XT_SWAP, 0x4000bce4, 0x41575304, 0x50,
/* 0x4000bcdc DUP */ XT_DUP, 0x4000bcf0, 0x50554403,
/* 0x4000bce8 DROP */ XT_DROP, 0x4000bd00, 0x4f524404, 0x50,
/* 0x4000bcf8 SP! */ XT_SP_21, 0x4000bd0c, 0x21505303,
/* 0x4000bd04 SP@ */ XT_SP_40, 0x4000bd18, 0x40505303,
/* 0x4000bd10 2>R */ XT_2_3ER, 0x4000bd24, 0x523e3203,
/* 0x4000bd1c 2R@ */ XT_2R_40, 0x4000bd30, 0x40523203,
/* 0x4000bd28 2R> */ XT_2R_3E, 0x4000bd3c, 0x3e523203,
/* 0x4000bd34 >R */ XT__3ER, 0x4000bd48, 0x523e02,
/* 0x4000bd40 R@ */ XT_R_40, 0x4000bd54, 0x405202,
/* 0x4000bd4c R> */ XT_R_3E, 0x4000bd60, 0x3e5202,
/* 0x4000bd58 RP! */ XT_RP_21, 0x4000bd6c, 0x21505203,
/* 0x4000bd64 RP@ */ XT_RP_40, 0x4000bd78, 0x40505203,
/* 0x4000bd70 C! */ XT_C_21, 0x4000bd84, 0x214302,
/* 0x4000bd7c C@ */ XT_C_40, 0x4000bd90, 0x404302,
/* 0x4000bd88 @ */ XT__40, 0x4000bd9c, 0x4001,
/* 0x4000bd94 ! */ XT__21, 0x4000bda8, 0x2101,
/* 0x4000bda0 branch */ XT_branch, 0x4000bdb8, 0x61726206, 0x68636e,
/* 0x4000bdb0 ?branch */ XT__3Fbranch, 0x4000bdc8, 0x72623f07, 0x68636e61,
/* 0x4000bdc0 next */ XT_next, 0x4000bdd8, 0x78656e04, 0x74,
/* 0x4000bdd0 DOES> */ XT_DOES_3E, 0x4000bde8, 0x454f4405, 0x3e53,
/* 0x4000bde0 doLit */ XT_doLit, 0x4000bdf8, 0x4c6f6405, 0x7469,
/* 0x4000bdf0 !IO */ XT__21IO, 0x4000be04, 0x4f492103,
/* 0x4000bdfc TX! */ XT_TX_21, 0x4000be10, 0x21585403,
/* 0x4000be08 ?RX */ XT__3FRX, 0x4000be1c, 0x58523f03,
/* 0x4000be14 EXECUTE */ XT_EXECUTE, 0x4000be2c, 0x45584507, 0x45545543,
/* 0x4000be24 EXIT */ XT_EXIT, 0x4000be3c, 0x49584504, 0x54,
/* 0x4000be34 BYE */ XT_BYE, 0x4000be48, 0x45594203,
/* 0x4000be40 ms */ XT_ms, 0x4000be54, 0x736d02,
/* 0x4000be4c $,n */ XT__24_2Cn, 0x4000be60, 0x6e2c2403,
/* 0x4000be58 OVERT */ XT_OVERT, 0x4000be70, 0x45564f05, 0x5452,
/* 0x4000be68 FIND-NAME-IN */ XT_FIND_2DNAME_2DIN, 0x4000be88, 0x4e49460c, 0x414e2d44, 0x492d454d, 0x4e,
/* 0x4000be80 ALIGNED */ XT_ALIGNED, 0x4000be98, 0x494c4107, 0x44454e47,
/* 0x4000be90 tokenValue */ XT_tokenValue, 0x4000beac, 0x6b6f740a, 0x61566e65, 0x65756c,
/* 0x4000bea4 tokenDefer */ XT_tokenDefer, 0x4000bec0, 0x6b6f740a, 0x65446e65, 0x726566,
/* 0x4000beb8 tokenCreate */ XT_tokenCreate, 0x4000bed4, 0x6b6f740b, 0x72436e65, 0x65746165,
/* 0x4000becc tokenVar */ XT_tokenVar, 0x4000bee8, 0x6b6f7408, 0x61566e65, 0x72,
/* 0x4000bee0 tokenUser */ XT_tokenUser, 0x4000befc, 0x6b6f7409, 0x73556e65, 0x7265,
/* 0x4000bef4 tokenDoList */ XT_tokenDoList, 0x4000bf10, 0x6b6f740b, 0x6f446e65, 0x7473694c,
/* 0x4000bf08 tokenNextVal */ XT_tokenNextVal, 0x4000bf28, 0x6b6f740c, 0x654e6e65, 0x61567478, 0x6c,
/* 0x4000bf20 tokenVocabulary */ XT_tokenVocabulary, 0x4000bf40, 0x6b6f740f, 0x6f566e65, 0x75626163, 0x7972616c,
/* 0x4000bf38 BL */ XT_BL, 0x4000bf4c, 0x4c4202,
/* 0x4000bf44 FALSE */ XT_FALSE, 0x4000bf5c, 0x4c414605, 0x4553,
/* 0x4000bf54 TRUE */ XT_TRUE, 0x4000bf6c, 0x55525404, 0x45,
/* 0x4000bf64 BYTEMASK */ XT_BYTEMASK, 0x4000bf80, 0x54594208, 0x53414d45, 0x4b,
/* 0x4000bf78 IMED */ XT_IMED, 0x4000bf90, 0x454d4904, 0x44,
/* 0x4000bf88 COMP */ XT_COMP, 0x4000bfa0, 0x4d4f4304, 0x50,
/* 0x4000bf98 rqFiles */ XT_rqFiles, 0x4000bfb0, 0x46717207, 0x73656c69,
/* 0x4000bfa8 TIB0 */ XT_TIB0, 0x4000bfc0, 0x42495404, 0x30,
/* 0x4000bfb8 CELLMASK */ XT_CELLMASK, 0x4000bfd4, 0x4c454308, 0x53414d4c, 0x4b,
/* 0x4000bfcc CELLbits */ XT_CELLbits, 0x4000bfe8, 0x4c454308, 0x7469624c, 0x73,
/* 0x4000bfe0 CELLL */ XT_CELLL, 0x4000bff8, 0x4c454305, 0x4c4c,
/* 0x4000bff0 FORTH */ XT_FORTH, 0, 0x524f4605, 0x4854,
};
// === End of Arduino source from dictionary === 
