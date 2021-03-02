#include "webforth_functions.h"
// === Arduino source built directly from dictionary - edit at your own risk ! === 
/* === Dumping Arduino source from names === */
#define XT_WARM 0x40003680 /* WARM*/
#define XT_COLD 0x40003650 /* COLD*/
#define XT__27BOOT 0x40003644 /* 'BOOT*/
#define XT_EMPTY 0x40003624 /* EMPTY*/
#define XT_hi 0x40003614 /* hi*/
#define XT_version 0x4000359c /* version*/
#define XT_VER 0x40003594 /* VER*/
#define XT_SEE 0x400034a0 /* SEE*/
#define XT__3ENAME 0x40003428 /* >NAME*/
#define XT_WORDS 0x400033e4 /* WORDS*/
#define XT__2EID 0x400033ac /* .ID*/
#define XT__3FCSP 0x40003384 /* ?CSP*/
#define XT__21CSP 0x40003370 /* !CSP*/
#define XT__2EFREE 0x40003358 /* .FREE*/
#define XT__2EBASE 0x40003334 /* .BASE*/
#define XT_UNUSED 0x40003318 /* UNUSED*/
#define XT__2ES 0x400032dc /* .S*/
#define XT_DUMP 0x40003254 /* DUMP*/
#define XT_dm_2B 0x4000320c /* dm+*/
#define XT_EVALUATE 0x400031d8 /* EVALUATE*/
#define XT_quit1 0x400031b0 /* quit1*/
#define XT_QUIT 0x4000314c /* QUIT*/
#define XT_quitError 0x400030f0 /* quitError*/
#define XT_PRESET 0x400030a8 /* PRESET*/
#define XT_que 0x40003098 /* que*/
#define XT_QUERY 0x40003024 /* QUERY*/
#define XT_REFILL 0x40002fc0 /* REFILL*/
#define XT_READ_2DLINE 0x40002fb8 /* READ-LINE*/
#define XT_sourcePop 0x40002fa0 /* sourcePop*/
#define XT_RESTORE_2DINPUT 0x40002f4c /* RESTORE-INPUT*/
#define XT_sourcePush 0x40002f38 /* sourcePush*/
#define XT_SAVE_2DINPUT 0x40002f18 /* SAVE-INPUT*/
#define XT_unreadFile 0x40002f10 /* unreadFile*/
#define XT_0_3E 0x40002ef0 /* 0>*/
#define XT_sourceStack 0x40002ee0 /* sourceStack*/
#define XT_SOURCE_2DID 0x40002ed0 /* SOURCE-ID*/
#define XT_sempty 0x40002eb4 /* sempty*/
#define XT_spops 0x40002e6c /* spops*/
#define XT_spushes 0x40002e28 /* spushes*/
#define XT_spush 0x40002df8 /* spush*/
#define XT_spop 0x40002dcc /* spop*/
#define XT_stack 0x40002d88 /* stack*/
#define XT_ACCEPT 0x40002d18 /* ACCEPT*/
#define XT__28charbase_29 0x40002b4c /* (charbase)*/
#define XT__3ENUMBER 0x40002acc /* >NUMBER*/
#define XT_accumulate 0x40002a90 /* accumulate*/
#define XT_J_2DMAX 0x40002a70 /* J-MAX*/
#define XT_J 0x40002a50 /* J*/
#define XT_I_2DMAX 0x40002a30 /* I-MAX*/
#define XT__2BLOOP 0x40002a1c /* +LOOP*/
#define XT_LOOP 0x40002a08 /* LOOP*/
#define XT_some_2Dloop 0x400029b0 /* some-loop*/
#define XT__3FDO 0x40002978 /* ?DO*/
#define XT_DO 0x4000294c /* DO*/
#define XT_UNLOOP 0x4000293c /* UNLOOP*/
#define XT_LEAVE 0x40002928 /* LEAVE*/
#define XT_leave_2C 0x40002908 /* leave,*/
#define XT__28_2Bloop_29 0x4000288c /* (+loop)*/
#define XT__28loop_29 0x40002864 /* (loop)*/
#define XT__28_3Fdo_29 0x40002840 /* (?do)*/
#define XT_leave_2Dptr 0x40002834 /* leave-ptr*/
#define XT_CONSTANT 0x40002814 /* CONSTANT*/
#define XT_VARIABLE 0x400027fc /* VARIABLE*/
#define XT_TO 0x400027f0 /* TO*/
#define XT_VALUE 0x400027b8 /* VALUE*/
#define XT_EVAL 0x4000269c /* EVAL*/
#define XT__3FUNIQUE 0x400025e0 /* ?UNIQUE*/
#define XT_RECURSE 0x400025c8 /* RECURSE*/
#define XT_ACTION_2DOF 0x40002594 /* ACTION-OF*/
#define XT_IS 0x40002588 /* IS*/
#define XT__27_3EBODY_21 0x40002554 /* '>BODY!*/
#define XT_BUFFER_3A 0x40002544 /* BUFFER:*/
#define XT_vALLOT 0x40002518 /* vALLOT*/
#define XT_ALLOT 0x40002508 /* ALLOT*/
#define XT_CONSOLE 0x400024cc /* CONSOLE*/
#define XT_I_2FO 0x400024bc /* I/O*/
#define XT_HAND 0x40002498 /* HAND*/
#define XT_FILE 0x40002474 /* FILE*/
#define XT_XIO 0x40002454 /* XIO*/
#define XT__3FSTACK 0x40002420 /* ?STACK*/
#define XT__2EOK 0x400023f8 /* .OK*/
#define XT_POSTPONE 0x40002350 /* POSTPONE*/
#define XT_ABORT_22 0x4000233c /* ABORT"*/
#define XT__28abort_22_29 0x4000231c /* (abort")*/
#define XT_ABORT 0x4000230c /* ABORT*/
#define XT_NULL_24 0x40002300 /* NULL$*/
#define XT_S_5C_22 0x4000227c /* S\"*/
#define XT_pack_5C_24 0x400021ec /* pack\$*/
#define XT_cmove_5C 0x40001f08 /* cmove\*/
#define XT_c_2B_21 0x40001ef4 /* c+!*/
#define XT_bu_2B_40 0x40001ed8 /* bu+@*/
#define XT_S_22 0x40001e94 /* S"*/
#define XT__2E_22 0x40001e80 /* ."*/
#define XT_C_22 0x40001e74 /* C"*/
#define XT__24_22 0x40001e60 /* $"*/
#define XT_S_22_7C 0x40001e50 /* S"|*/
#define XT__2E_22_7C 0x40001e40 /* ."|*/
#define XT__24_22_7C 0x40001e34 /* $"|*/
#define XT__24_2C_22 0x40001e0c /* $,"*/
#define XT_do_24 0x40001de0 /* do$*/
#define XT_kTAP 0x40001d70 /* kTAP*/
#define XT_skipToCRLF 0x40001d20 /* skipToCRLF*/
#define XT_skipCRLF 0x40001cd4 /* skipCRLF*/
#define XT_crlf_3F 0x40001ca8 /* crlf?*/
#define XT_TAP 0x40001c88 /* TAP*/
#define XT__5EH 0x40001c30 /* ^H*/
#define XT_THROW 0x40001bec /* THROW*/
#define XT_CATCH 0x40001ba4 /* CATCH*/
#define XT_MARKER 0x40001acc /* MARKER*/
#define XT_FIND 0x40001a68 /* FIND*/
#define XT_NAME_3F 0x40001a2c /* NAME?*/
#define XT_FIND_2DNAME 0x400019a8 /* FIND-NAME*/
#define XT_SAME_3F 0x40001944 /* SAME?*/
#define XT_NAME_3EINTERPRET 0x40001928 /* NAME>INTERPRET*/
#define XT_WORD 0x40001914 /* WORD*/
#define XT__2E_28 0x400018cc /* .(*/
#define XT_CTRL 0x400018b4 /* CTRL*/
#define XT__5BCHAR_5D 0x400018a4 /* [CHAR]*/
#define XT_CHAR 0x40001890 /* CHAR*/
#define XT_PARSE_2DNAME 0x40001880 /* PARSE-NAME*/
#define XT_skip_2Dtill 0x40001780 /* skip-till*/
#define XT_xt_2Dskip 0x40001734 /* xt-skip*/
#define XT_isnotspace_3F 0x40001724 /* isnotspace?*/
#define XT_isspace_3F 0x40001710 /* isspace?*/
#define XT__2FSTRING 0x400016f4 /* /STRING*/
#define XT_SOURCE 0x400016e0 /* SOURCE*/
#define XT__5B_27_5D 0x400016d0 /* [']*/
#define XT_CR 0x400016b0 /* CR*/
#define XT_PACE 0x4000169c /* PACE*/
#define XT_NUF_3F 0x40001670 /* NUF?*/
#define XT_KEY 0x40001644 /* KEY*/
#define XT__3FKEY 0x40001634 /* ?KEY*/
#define XT_DIGIT_3F 0x400015b4 /* DIGIT?*/
#define XT__3F 0x400015a4 /* ?*/
#define XT__2E 0x4000156c /* .*/
#define XT_U_2E 0x40001548 /* U.*/
#define XT_U_2ER 0x40001514 /* U.R*/
#define XT__2ER 0x400014f0 /* .R*/
#define XT_DECIMAL 0x400014d8 /* DECIMAL*/
#define XT_HEX 0x400014c0 /* HEX*/
#define XT_str 0x40001490 /* str*/
#define XT__2E_24 0x40001480 /* .$*/
#define XT_SPACES 0x40001470 /* SPACES*/
#define XT_emits 0x40001438 /* emits*/
#define XT_SPACE 0x40001428 /* SPACE*/
#define XT_EMIT 0x40001418 /* EMIT*/
#define XT__23_3E 0x400013f8 /* #>*/
#define XT_SIGN 0x400013d8 /* SIGN*/
#define XT__23S 0x400013b4 /* #S*/
#define XT__23 0x4000139c /* #*/
#define XT_HOLDS 0x40001368 /* HOLDS*/
#define XT_HOLD 0x40001344 /* HOLD*/
#define XT__3C_23 0x40001330 /* <#*/
#define XT_EXTRACT 0x400012f8 /* EXTRACT*/
#define XT_DIGIT 0x400012c4 /* DIGIT*/
#define XT_PACK_24 0x40001260 /* PACK$*/
#define XT__2DTRAILING 0x40001210 /* -TRAILING*/
#define XT_ERASE 0x400011fc /* ERASE*/
#define XT_FILL 0x400011c8 /* FILL*/
#define XT_MOVE 0x40001194 /* MOVE*/
#define XT_CMOVE_3E 0x4000112c /* CMOVE>*/
#define XT_CMOVE 0x400010ec /* CMOVE*/
#define XT_COUNT 0x400010d4 /* COUNT*/
#define XT__40EXECUTE 0x400010b8 /* @EXECUTE*/
#define XT_TIB 0x400010a4 /* TIB*/
#define XT_PAD 0x4000108c /* PAD*/
#define XT_vCREATE 0x40001054 /* vCREATE*/
#define XT_vALIGN 0x40001038 /* vALIGN*/
#define XT_v_2C 0x40000ff8 /* v,*/
#define XT_vHERE 0x40000fd4 /* vHERE*/
#define XT_2_40 0x40000fb8 /* 2@*/
#define XT_2_21 0x40000f9c /* 2!*/
#define XT__2D_2D 0x40000f84 /* --*/
#define XT__2B_2B 0x40000f6c /* ++*/
#define XT__2B_21 0x40000f4c /* +!*/
#define XT_PICK 0x40000f30 /* PICK*/
#define XT__3ECHAR 0x40000ed0 /* >CHAR*/
#define XT_DEFER_21 0x40000ec4 /* DEFER!*/
#define XT__3EBODY_21 0x40000eb4 /* >BODY!*/
#define XT_DEFER_40 0x40000ea4 /* DEFER@*/
#define XT__3ANONAME 0x40000e60 /* :NONAME*/
#define XT__28_24_2Cn_29 0x40000e08 /* ($,n)*/
#define XT_2_2A 0x40000df4 /* 2**/
#define XT_CHARS 0x40000dec /* CHARS*/
#define XT_CELLS 0x40000ddc /* CELLS*/
#define XT_CELL_2D 0x40000dcc /* CELL-*/
#define XT_SM_2FREM 0x40000d84 /* SM/REM*/
#define XT_DABS 0x40000d68 /* DABS*/
#define XT_D0_3C 0x40000d58 /* D0<*/
#define XT__2A_2F 0x40000d48 /* * /*/
#define XT__2A_2FMOD 0x40000d30 /* * /MOD*/
#define XT_M_2A 0x40000cf8 /* M**/
#define XT__2A 0x40000ce8 /* **/
#define XT_UM_2A 0x40000c74 /* UM**/
#define XT__2F 0x40000c64 /* /*/
#define XT_MOD 0x40000c54 /* MOD*/
#define XT__2FMOD 0x40000c3c /* /MOD*/
#define XT_FM_2FMOD 0x40000c30 /* FM/MOD*/
#define XT_M_2FMOD 0x40000bc4 /* M/MOD*/
#define XT_UM_2FMOD 0x40000b04 /* UM/MOD*/
#define XT_S_3ED 0x40000af4 /* S>D*/
#define XT_WITHIN 0x40000ad4 /* WITHIN*/
#define XT_MIN 0x40000ab0 /* MIN*/
#define XT_MAX 0x40000a90 /* MAX*/
#define XT__3E 0x40000a80 /* >*/
#define XT__3C 0x40000a50 /* <*/
#define XT_ud_3C 0x40000a20 /* ud<*/
#define XT_U_3E 0x40000a10 /* U>*/
#define XT_U_3C 0x400009e0 /* U<*/
#define XT__3C_3E 0x400009c0 /* <>*/
#define XT__3D 0x400009a0 /* =*/
#define XT_C_2C 0x40000980 /* C,*/
#define XT_CHAR_2B 0x40000974 /* CHAR+*/
#define XT_ABS 0x40000964 /* ABS*/
#define XT__3Fnegate 0x4000094c /* ?negate*/
#define XT_1_2D 0x40000938 /* 1-*/
#define XT__2D 0x40000928 /* -*/
#define XT_DNEGATE 0x40000900 /* DNEGATE*/
#define XT_NEGATE 0x400008f0 /* NEGATE*/
#define XT_1_2B 0x400008dc /* 1+*/
#define XT_INVERT 0x400008c8 /* INVERT*/
#define XT_D_2B 0x400008a0 /* D+*/
#define XT_2SWAP 0x40000888 /* 2SWAP*/
#define XT_2OVER 0x40000864 /* 2OVER*/
#define XT_2DUP 0x40000854 /* 2DUP*/
#define XT__2DROT 0x4000083c /* -ROT*/
#define XT__3Ftest_5C 0x4000081c /* ?test\*/
#define XT__3Fsafe_5C 0x400007fc /* ?safe\*/
#define XT__3F_5C 0x400007e4 /* ?\*/
#define XT_D0_3D 0x400007d4 /* D0=*/
#define XT_0_3C_3E 0x400007c4 /* 0<>*/
#define XT_0_3D 0x400007a4 /* 0=*/
#define XT_ENDCASE 0x40000790 /* ENDCASE*/
#define XT_ENDOF 0x40000770 /* ENDOF*/
#define XT_OF 0x4000075c /* OF*/
#define XT_CASE 0x40000750 /* CASE*/
#define XT__3ERESOLVETHREAD 0x40000724 /* >RESOLVETHREAD*/
#define XT__3EMARKTHREAD 0x40000710 /* >MARKTHREAD*/
#define XT__3EMARKSTART 0x40000700 /* >MARKSTART*/
#define XT__3ERESOLVES 0x400006e0 /* >RESOLVES*/
#define XT__3FDUP 0x400006c8 /* ?DUP*/
#define XT_WHILE 0x400006b8 /* WHILE*/
#define XT_WHEN 0x400006a8 /* WHEN*/
#define XT_ELSE 0x40000694 /* ELSE*/
#define XT_AFT 0x4000067c /* AFT*/
#define XT_THEN 0x40000670 /* THEN*/
#define XT_REPEAT 0x40000660 /* REPEAT*/
#define XT_AHEAD 0x4000064c /* AHEAD*/
#define XT_IF 0x40000638 /* IF*/
#define XT_AGAIN 0x40000624 /* AGAIN*/
#define XT_UNTIL 0x40000610 /* UNTIL*/
#define XT_NEXT 0x400005fc /* NEXT*/
#define XT_BEGIN 0x400005f0 /* BEGIN*/
#define XT_FOR 0x400005dc /* FOR*/
#define XT__3ERESOLVE 0x400005c8 /* >RESOLVE*/
#define XT__3EMARK 0x400005b0 /* >MARK*/
#define XT__3CRESOLVE 0x400005a4 /* <RESOLVE*/
#define XT__3CMARK 0x40000598 /* <MARK*/
#define XT_CREATE 0x40000588 /* CREATE*/
#define XT_create 0x40000564 /* create*/
#define XT_LITERAL 0x40000550 /* LITERAL*/
#define XT_COMPILE 0x40000530 /* COMPILE*/
#define XT__5BCOMPILE_5D 0x40000520 /* [COMPILE]*/
#define XT_COMPILE_2C 0x40000514 /* COMPILE,*/
#define XT__2C 0x400004f0 /* ,*/
#define XT_CELL_2B 0x400004e0 /* CELL+*/
#define XT__2B 0x400004d0 /* +*/
#define XT_HERE 0x400004c0 /* HERE*/
#define XT_TUCK 0x400004b0 /* TUCK*/
#define XT_NIP 0x400004a0 /* NIP*/
#define XT__5C 0x40000488 /* \*/
#define XT_IMMEDIATE 0x40000478 /* IMMEDIATE*/
#define XT_COMPILE_2DONLY 0x40000468 /* COMPILE-ONLY*/
#define XT_setHeaderBits 0x40000444 /* setHeaderBits*/
#define XT_2DROP 0x40000434 /* 2DROP*/
#define XT_testDepth 0x4000042c /* testDepth*/
#define XT_testFlags 0x40000424 /* testFlags*/
#define XT_source_2Did 0x4000041c /* source-id*/
#define XT_VP 0x40000414 /* VP*/
#define XT_LAST 0x4000040c /* LAST*/
#define XT_NP 0x40000404 /* NP*/
#define XT_CP 0x400003fc /* CP*/
#define XT_CURRENT 0x400003f4 /* CURRENT*/
#define XT_CONTEXT 0x400003ec /* CONTEXT*/
#define XT_HANDLER 0x400003e4 /* HANDLER*/
#define XT_HLD 0x400003dc /* HLD*/
#define XT_SPARE2 0x400003d4 /* SPARE2*/
#define XT_STATE 0x400003cc /* STATE*/
#define XT_CSP 0x400003c4 /* CSP*/
#define XT__23TIB 0x400003bc /* #TIB*/
#define XT__3EIN 0x400003b4 /* >IN*/
#define XT_SPAN 0x400003ac /* SPAN*/
#define XT_temp 0x400003a4 /* temp*/
#define XT_BASE 0x4000039c /* BASE*/
#define XT__27PROMPT 0x40000394 /* 'PROMPT*/
#define XT__27ECHO 0x4000038c /* 'ECHO*/
#define XT__27TAP 0x40000384 /* 'TAP*/
#define XT_SPARE 0x4000037c /* SPARE*/
#define XT__27EMIT 0x40000374 /* 'EMIT*/
#define XT__27_3FKEY 0x4000036c /* '?KEY*/
#define XT_RP0 0x40000364 /* RP0*/
#define XT_SP0 0x4000035c /* SP0*/
#define XT__5FUSER 0x40000354 /* _USER*/
#define XT__2D_3E 0x4000034c /* ->*/
#define XT__7DT 0x40000340 /* }T*/
#define XT_DEPTH 0x40000334 /* DEPTH*/
#define XT_T_7B 0x40000328 /* T{*/
#define XT__28of_29 0x40000320 /* (of)*/
#define XT_DEFER 0x40000318 /* DEFER*/
#define XT__3EBODY 0x40000310 /* >BODY*/
#define XT_ALIGN 0x4000030c /* ALIGN*/
#define XT_immediate_3F 0x40000308 /* immediate?*/
#define XT_2RDrop 0x40000304 /* 2RDrop*/
#define XT_RDrop 0x40000300 /* RDrop*/
#define XT_I 0x400002fc /* I*/
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
#define XT__28next_29 0x400001e4 /* (next)*/
#define XT_DOES_3E 0x400001e0 /* DOES>*/
#define XT__28literal_29 0x400001dc /* (literal)*/
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
void (* const f[FUNCTIONSLENGTH])() PROGMEM = {
0, tokenVocabulary, tokenNextVal, tokenDoList, 
tokenUser, tokenVar, tokenCreate, tokenDefer, 
tokenValue, ALIGNED, /* FIND-NAME-IN */ findNameIn, 0, 
0, ms, BYE, EXIT, 
EXECUTE, /* ?RX */ QRX, /* TX! */ TXstore, /* !IO */ storeIO, 
/* (literal) */ literal, /* DOES> */ DOES, /* (next) */ next, /* ?branch */ qBranch, 
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
stringBuffer, TYPE, I, RDrop, 
/* 2RDrop */ TwoRDrop, /* immediate? */ immediateQ, /* ALIGN */ vpAlign, /* >BODY */ toBODY, 
0, /* (of) */ of, 0, 0, 
0, 0,  0 };
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
/* 0x40000090 LAST */ 0x4000a7cc,
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
/* 0x400001ac: OVERT */ F_tokenDefer, 0x400026f0, 0xc, 
/* 0x400001b8: $,n */ F_tokenDefer, 0x40002610, 
/* 0x400001c0: ms */ F_ms, 
/* 0x400001c4: BYE */ F_BYE, 
/* 0x400001c8: EXIT */ F_EXIT, 
/* 0x400001cc: EXECUTE */ F_EXECUTE, 
/* 0x400001d0: ?RX */ F_QRX, 
/* 0x400001d4: TX! */ F_TXstore, 
/* 0x400001d8: !IO */ F_storeIO, 
/* 0x400001dc: (literal) */ F_literal, 
/* 0x400001e0: DOES> */ F_DOES, 
/* 0x400001e4: (next) */ F_next, 
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
/* 0x4000026c: PARSE */ F_tokenDefer, 0x400017d0, 0x38, 
/* 0x40000278: ( */ F_tokenDefer, 0x40003040, 0x39, 
/* 0x40000284: TOKEN */ F_tokenDefer, 0x400018e4, 0x3a, 
/* 0x40000290: NUMBER? */ F_tokenDefer, 0x40002bc8, 0x3b, 
/* 0x4000029c: $COMPILE */ F_tokenDefer, 0x40002644, 0x3c, 
/* 0x400002a8: $INTERPRET */ F_tokenDefer, 0x400023a0, 0x3d, 
/* 0x400002b4: [ */ F_tokenDefer, 0x40002440, 0x3e, 
/* 0x400002c0: ] */ F_tokenDefer, 0x40002760, 0x3f, 
/* 0x400002cc: : */ F_tokenDefer, 0x40002774, 0x40, 
/* 0x400002d8: ; */ F_tokenDefer, 0x40002748, 0x41, 
/* 0x400002e4: ' */ F_tokenDefer, 0x400024e8, 
/* 0x400002ec: debugNA */ F_debugNA, 
/* 0x400002f0: Fbreak */ F_Fbreak, 
/* 0x400002f4: stringBuffer */ F_stringBuffer, 
/* 0x400002f8: TYPE */ F_TYPE, 
/* 0x400002fc: I */ F_I, 
/* 0x40000300: RDrop */ F_RDrop, 
/* 0x40000304: 2RDrop */ F_TwoRDrop, 
/* 0x40000308: immediate? */ F_immediateQ, 
/* 0x4000030c: ALIGN */ F_vpAlign, 
/* 0x40000310: >BODY */ F_toBODY, 0x4c, 
/* 0x40000318: DEFER */ F_tokenDefer, 0x40002790, 
/* 0x40000320: (of) */ F_of, 0x4e, 
/* 0x40000328: T{ */ F_tokenDefer, 0x40000324, 0x4f, 
/* 0x40000334: DEPTH */ F_tokenDefer, 0x40000f0c, 0x50, 
/* 0x40000340: }T */ F_tokenDefer, 0x4000033c, 0x51, 
/* 0x4000034c: -> */ F_tokenDefer, 0x40000348, 
/* 0x40000354: _USER */ F_tokenUser, 0, 
/* 0x4000035c: SP0 */ F_tokenUser, 4, 
/* 0x40000364: RP0 */ F_tokenUser, 5, 
/* 0x4000036c: '?KEY */ F_tokenUser, 6, 
/* 0x40000374: 'EMIT */ F_tokenUser, 7, 
/* 0x4000037c: SPARE */ F_tokenUser, 8, 
/* 0x40000384: 'TAP */ F_tokenUser, 9, 
/* 0x4000038c: 'ECHO */ F_tokenUser, 0xa, 
/* 0x40000394: 'PROMPT */ F_tokenUser, 0xb, 
/* 0x4000039c: BASE */ F_tokenUser, 0xc, 
/* 0x400003a4: temp */ F_tokenUser, 0xd, 
/* 0x400003ac: SPAN */ F_tokenUser, 0xe, 
/* 0x400003b4: >IN */ F_tokenUser, 0xf, 
/* 0x400003bc: #TIB */ F_tokenUser, 0x10, 
/* 0x400003c4: CSP */ F_tokenUser, 0x12, 
/* 0x400003cc: STATE */ F_tokenUser, 0x13, 
/* 0x400003d4: SPARE2 */ F_tokenUser, 0x14, 
/* 0x400003dc: HLD */ F_tokenUser, 0x15, 
/* 0x400003e4: HANDLER */ F_tokenUser, 0x16, 
/* 0x400003ec: CONTEXT */ F_tokenUser, 0x17, 
/* 0x400003f4: CURRENT */ F_tokenUser, 0x20, 
/* 0x400003fc: CP */ F_tokenUser, 0x22, 
/* 0x40000404: NP */ F_tokenUser, 0x23, 
/* 0x4000040c: LAST */ F_tokenUser, 0x24, 
/* 0x40000414: VP */ F_tokenUser, 0x25, 
/* 0x4000041c: source-id */ F_tokenUser, 0x26, 
/* 0x40000424: testFlags */ F_tokenUser, 0x27, 
/* 0x4000042c: testDepth */ F_tokenUser, 0x28, 
/* 0x40000434: 2DROP */ F_tokenDoList, XT_DROP, XT_DROP, XT_EXIT, 
/* 0x40000444: setHeaderBits */ F_tokenDoList, XT_LAST, XT__40, XT_C_40, XT_OR, XT_LAST, XT__40, XT_C_21, XT_EXIT, 
/* 0x40000468: COMPILE-ONLY */ F_tokenDoList, XT_COMP, XT_setHeaderBits, XT_EXIT, 
/* 0x40000478: IMMEDIATE */ F_tokenDoList, XT_IMED, XT_setHeaderBits, XT_EXIT, 
/* 0x40000488: \ */ F_tokenDoList, XT__23TIB, XT__40, XT__3EIN, XT__21, XT_EXIT, 
/* 0x400004a0: NIP */ F_tokenDoList, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x400004b0: TUCK */ F_tokenDoList, XT_SWAP, XT_OVER, XT_EXIT, 
/* 0x400004c0: HERE */ F_tokenDoList, XT_CP, XT__40, XT_EXIT, 
/* 0x400004d0: + */ F_tokenDoList, XT_UM_2B, XT_DROP, XT_EXIT, 
/* 0x400004e0: CELL+ */ F_tokenDoList, XT_CELLL, XT__2B, XT_EXIT, 
/* 0x400004f0: , */ F_tokenDoList, XT_HERE, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_CP, XT__21, XT__21, XT_EXIT, 
/* 0x40000514: COMPILE, */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x40000520: [COMPILE] */ F_tokenDoList, XT__27, XT__2C, XT_EXIT, 
/* 0x40000530: COMPILE */ F_tokenDoList, XT_R_3E, XT_DUP, XT__40, XT__2C, XT_CELL_2B, XT__3ER, XT_EXIT, 
/* 0x40000550: LITERAL */ F_tokenDoList, XT_COMPILE, XT__28literal_29, XT__2C, XT_EXIT, 
/* 0x40000564: create */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT__2C, XT__28literal_29, 0, XT__2C, XT_EXIT, 
/* 0x40000588: CREATE */ F_tokenDoList, XT_tokenCreate, XT_create, XT_EXIT, 
/* 0x40000598: <MARK */ F_tokenDoList, XT_HERE, XT_EXIT, 
/* 0x400005a4: <RESOLVE */ F_tokenDoList, XT__2C, XT_EXIT, 
/* 0x400005b0: >MARK */ F_tokenDoList, XT_HERE, XT__28literal_29, 0, XT__2C, XT_EXIT, 
/* 0x400005c8: >RESOLVE */ F_tokenDoList, XT__3CMARK, XT_SWAP, XT__21, XT_EXIT, 
/* 0x400005dc: FOR */ F_tokenDoList, XT_COMPILE, XT__3ER, XT__3CMARK, XT_EXIT, 
/* 0x400005f0: BEGIN */ F_tokenDoList, XT__3CMARK, XT_EXIT, 
/* 0x400005fc: NEXT */ F_tokenDoList, XT_COMPILE, XT__28next_29, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000610: UNTIL */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000624: AGAIN */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3CRESOLVE, XT_EXIT, 
/* 0x40000638: IF */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__3EMARK, XT_EXIT, 
/* 0x4000064c: AHEAD */ F_tokenDoList, XT_COMPILE, XT_branch, XT__3EMARK, XT_EXIT, 
/* 0x40000660: REPEAT */ F_tokenDoList, XT_AGAIN, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000670: THEN */ F_tokenDoList, XT__3ERESOLVE, XT_EXIT, 
/* 0x4000067c: AFT */ F_tokenDoList, XT_DROP, XT_AHEAD, XT_BEGIN, XT_SWAP, XT_EXIT, 
/* 0x40000694: ELSE */ F_tokenDoList, XT_AHEAD, XT_SWAP, XT_THEN, XT_EXIT, 
/* 0x400006a8: WHEN */ F_tokenDoList, XT_IF, XT_OVER, XT_EXIT, 
/* 0x400006b8: WHILE */ F_tokenDoList, XT_IF, XT_SWAP, XT_EXIT, 
/* 0x400006c8: ?DUP */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT__3FDUP + 0x14, XT_DUP, XT_EXIT, 
/* 0x400006e0: >RESOLVES */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVES + 0x1c, XT__3ERESOLVE, XT_branch, XT__3ERESOLVES + 4, XT_EXIT, 
/* 0x40000700: >MARKSTART */ F_tokenDoList, XT__28literal_29, 0, XT_EXIT, 
/* 0x40000710: >MARKTHREAD */ F_tokenDoList, XT_HERE, XT_SWAP, XT__2C, XT_EXIT, 
/* 0x40000724: >RESOLVETHREAD */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__3ERESOLVETHREAD + 0x28, XT_DUP, XT__40, XT_SWAP, XT__3ERESOLVE, XT_branch, XT__3ERESOLVETHREAD + 4, XT_EXIT, 
/* 0x40000750: CASE */ F_tokenDoList, XT__3EMARKSTART, XT_EXIT, 
/* 0x4000075c: OF */ F_tokenDoList, XT_COMPILE, XT__28of_29, XT__3EMARK, XT_EXIT, 
/* 0x40000770: ENDOF */ F_tokenDoList, XT_COMPILE, XT_branch, XT_SWAP, XT__3EMARKTHREAD, XT_SWAP, XT__3ERESOLVE, XT_EXIT, 
/* 0x40000790: ENDCASE */ F_tokenDoList, XT_COMPILE, XT_DROP, XT__3ERESOLVETHREAD, XT_EXIT, 
/* 0x400007a4: 0= */ F_tokenDoList, XT__3Fbranch, XT_0_3D + 0x18, XT_FALSE, XT_branch, XT_0_3D + 0x1c, XT_TRUE, XT_EXIT, 
/* 0x400007c4: 0<> */ F_tokenDoList, XT_0_3D, XT_0_3D, XT_EXIT, 
/* 0x400007d4: D0= */ F_tokenDoList, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x400007e4: ?\ */ F_tokenDoList, XT_0_3D, XT__3Fbranch, XT__3F_5C + 0x14, XT__5C, XT_EXIT, 
/* 0x400007fc: ?safe\ */ F_tokenDoList, XT_testFlags, XT__40, XT__28literal_29, 4, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x4000081c: ?test\ */ F_tokenDoList, XT_testFlags, XT__40, XT__28literal_29, 8, XT_AND, XT__3F_5C, XT_EXIT, 
/* 0x4000083c: -ROT */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_R_3E, XT_EXIT, 
/* 0x40000854: 2DUP */ F_tokenDoList, XT_OVER, XT_OVER, XT_EXIT, 
/* 0x40000864: 2OVER */ F_tokenDoList, XT__3ER, XT__3ER, XT_2DUP, XT_R_3E, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x40000888: 2SWAP */ F_tokenDoList, XT__3ER, XT__2DROT, XT_R_3E, XT__2DROT, XT_EXIT, 
/* 0x400008a0: D+ */ F_tokenDoList, XT__3ER, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_R_3E, XT__2B, XT__2B, XT_EXIT, 
/* 0x400008c8: INVERT */ F_tokenDoList, XT__28literal_29, 0xffffffff, XT_XOR, XT_EXIT, 
/* 0x400008dc: 1+ */ F_tokenDoList, XT__28literal_29, 1, XT__2B, XT_EXIT, 
/* 0x400008f0: NEGATE */ F_tokenDoList, XT_INVERT, XT_1_2B, XT_EXIT, 
/* 0x40000900: DNEGATE */ F_tokenDoList, XT_INVERT, XT__3ER, XT_INVERT, XT__28literal_29, 1, XT_UM_2B, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40000928: - */ F_tokenDoList, XT_NEGATE, XT__2B, XT_EXIT, 
/* 0x40000938: 1- */ F_tokenDoList, XT__28literal_29, 1, XT__2D, XT_EXIT, 
/* 0x4000094c: ?negate */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT__3Fnegate + 0x14, XT_NEGATE, XT_EXIT, 
/* 0x40000964: ABS */ F_tokenDoList, XT_DUP, XT__3Fnegate, XT_EXIT, 
/* 0x40000974: CHAR+ */ F_tokenDoList, XT_1_2B, XT_EXIT, 
/* 0x40000980: C, */ F_tokenDoList, XT_HERE, XT_DUP, XT_CHAR_2B, XT_CP, XT__21, XT_C_21, XT_EXIT, 
/* 0x400009a0: = */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3D + 0x18, XT_FALSE, XT_EXIT, XT_TRUE, XT_EXIT, 
/* 0x400009c0: <> */ F_tokenDoList, XT_XOR, XT__3Fbranch, XT__3C_3E + 0x18, XT_TRUE, XT_EXIT, XT_FALSE, XT_EXIT, 
/* 0x400009e0: U< */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT_U_3C + 0x24, XT_NIP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x40000a10: U> */ F_tokenDoList, XT_SWAP, XT_U_3C, XT_EXIT, 
/* 0x40000a20: ud< */ F_tokenDoList, XT_ROT, XT_SWAP, XT_U_3C, XT__3Fbranch, XT_ud_3C + 0x28, XT_2DROP, XT_TRUE, XT_branch, XT_ud_3C + 0x2c, XT_U_3C, XT_EXIT, 
/* 0x40000a50: < */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3Fbranch, XT__3C + 0x24, XT_DROP, XT_0_3C, XT_EXIT, XT__2D, XT_0_3C, XT_EXIT, 
/* 0x40000a80: > */ F_tokenDoList, XT_SWAP, XT__3C, XT_EXIT, 
/* 0x40000a90: MAX */ F_tokenDoList, XT_2DUP, XT__3C, XT__3Fbranch, XT_MAX + 0x18, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x40000ab0: MIN */ F_tokenDoList, XT_2DUP, XT_SWAP, XT__3C, XT__3Fbranch, XT_MIN + 0x1c, XT_SWAP, XT_DROP, XT_EXIT, 
/* 0x40000ad4: WITHIN */ F_tokenDoList, XT_OVER, XT__2D, XT__3ER, XT__2D, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x40000af4: S>D */ F_tokenDoList, XT_DUP, XT_0_3C, XT_EXIT, 
/* 0x40000b04: UM/MOD */ F_tokenDoList, XT_2DUP, XT_U_3C, XT__3Fbranch, XT_UM_2FMOD + 0xa8, XT_NEGATE, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2FMOD + 0x94, XT__3ER, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_DUP, XT_R_3E, XT_R_40, XT_SWAP, XT__3ER, XT_UM_2B, XT_R_3E, XT_OR, XT__3Fbranch, XT_UM_2FMOD + 0x8c, XT__3ER, XT_DROP, XT_1_2B, XT_R_3E, XT_branch, XT_UM_2FMOD + 0x90, XT_DROP, XT_R_3E, XT__28next_29, XT_UM_2FMOD + 0x28, XT_DROP, XT_SWAP, XT_EXIT, XT_DROP, XT_2DROP, XT__28literal_29, 0xffffffff, XT_DUP, XT_EXIT, 
/* 0x40000bc4: M/MOD */ F_tokenDoList, XT_DUP, XT_0_3C, XT_DUP, XT__3ER, XT__3Fbranch, XT_M_2FMOD + 0x2c, XT_NEGATE, XT__3ER, XT_DNEGATE, XT_R_3E, XT__3ER, XT_DUP, XT_0_3C, XT__3Fbranch, XT_M_2FMOD + 0x48, XT_R_40, XT__2B, XT_R_3E, XT_UM_2FMOD, XT_R_3E, XT__3Fbranch, XT_M_2FMOD + 0x68, XT_SWAP, XT_NEGATE, XT_SWAP, XT_EXIT, 
/* 0x40000c30: FM/MOD */ F_tokenDoList, XT_M_2FMOD, XT_EXIT, 
/* 0x40000c3c: /MOD */ F_tokenDoList, XT__3ER, XT_S_3ED, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x40000c54: MOD */ F_tokenDoList, XT__2FMOD, XT_DROP, XT_EXIT, 
/* 0x40000c64: / */ F_tokenDoList, XT__2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000c74: UM* */ F_tokenDoList, XT__28literal_29, 0, XT_SWAP, XT_CELLbits, XT__3ER, XT_branch, XT_UM_2A + 0x60, XT_DUP, XT_UM_2B, XT__3ER, XT__3ER, XT_DUP, XT_UM_2B, XT_R_3E, XT__2B, XT_R_3E, XT__3Fbranch, XT_UM_2A + 0x60, XT__3ER, XT_OVER, XT_UM_2B, XT_R_3E, XT__2B, XT__28next_29, XT_UM_2A + 0x20, XT_ROT, XT_DROP, XT_EXIT, 
/* 0x40000ce8: * */ F_tokenDoList, XT_UM_2A, XT_DROP, XT_EXIT, 
/* 0x40000cf8: M* */ F_tokenDoList, XT_2DUP, XT_XOR, XT_0_3C, XT__3ER, XT_ABS, XT_SWAP, XT_ABS, XT_UM_2A, XT_R_3E, XT__3Fbranch, XT_M_2A + 0x34, XT_DNEGATE, XT_EXIT, 
/* 0x40000d30: * /MOD */ F_tokenDoList, XT__3ER, XT_M_2A, XT_R_3E, XT_M_2FMOD, XT_EXIT, 
/* 0x40000d48: * / */ F_tokenDoList, XT__2A_2FMOD, XT_NIP, XT_EXIT, 
/* 0x40000d58: D0< */ F_tokenDoList, XT_NIP, XT_0_3C, XT_EXIT, 
/* 0x40000d68: DABS */ F_tokenDoList, XT_2DUP, XT_D0_3C, XT__3Fbranch, XT_DABS + 0x18, XT_DNEGATE, XT_EXIT, 
/* 0x40000d84: SM/REM */ F_tokenDoList, XT_2DUP, XT_XOR, XT__3ER, XT_OVER, XT__3ER, XT_ABS, XT__3ER, XT_DABS, XT_R_3E, XT_UM_2FMOD, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_SWAP, XT_R_3E, XT__3Fnegate, XT_EXIT, 
/* 0x40000dcc: CELL- */ F_tokenDoList, XT_CELLL, XT__2D, XT_EXIT, 
/* 0x40000ddc: CELLS */ F_tokenDoList, XT_CELLL, XT__2A, XT_EXIT, 
/* 0x40000dec: CHARS */ F_tokenDoList, XT_EXIT, 
/* 0x40000df4: 2* */ F_tokenDoList, XT__28literal_29, 2, XT__2A, XT_EXIT, 
/* 0x40000e08: ($,n) */ F_tokenDoList, XT_DUP, XT_LAST, XT__21, XT_HERE, XT_ALIGNED, XT_DUP, XT_CP, XT__21, XT_SWAP, XT_CELL_2D, XT_CURRENT, XT__40, XT__40, XT_OVER, XT__21, XT_CELL_2D, XT_DUP, XT_NP, XT__21, XT__21, XT_EXIT, 
/* 0x40000e60: :NONAME */ F_tokenDoList, XT_NP, XT__40, XT_CELL_2D, XT__28literal_29, 0, XT_OVER, XT__21, XT_DUP, XT_NP, XT__21, XT__28_24_2Cn_29, XT_HERE, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 
/* 0x40000ea4: DEFER@ */ F_tokenDoList, XT__3EBODY, XT__40, XT_EXIT, 
/* 0x40000eb4: >BODY! */ F_tokenDoList, XT__3EBODY, XT__21, XT_EXIT, 
/* 0x40000ec4: DEFER! */ F_tokenDoList, XT__3EBODY_21, XT_EXIT, 
/* 0x40000ed0: >CHAR */ F_tokenDoList, XT__28literal_29, 0x7f, XT_AND, XT_DUP, XT__28literal_29, 0x7f, XT_BL, XT_WITHIN, XT__3Fbranch, XT__3ECHAR + 0x38, XT_DROP, XT__28literal_29, 0x5f, XT_EXIT, 
/* 0x40000f0c:  */ F_tokenDoList, XT_SP_40, XT_SP0, XT__40, XT_SWAP, XT__2D, XT_CELLL, XT__2F, XT_EXIT, 
/* 0x40000f30: PICK */ F_tokenDoList, XT_1_2B, XT_CELLS, XT_SP_40, XT__2B, XT__40, XT_EXIT, 
/* 0x40000f4c: +! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__40, XT__2B, XT_SWAP, XT__21, XT_EXIT, 
/* 0x40000f6c: ++ */ F_tokenDoList, XT__28literal_29, 1, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x40000f84: -- */ F_tokenDoList, XT__28literal_29, 0xffffffff, XT_SWAP, XT__2B_21, XT_EXIT, 
/* 0x40000f9c: 2! */ F_tokenDoList, XT_SWAP, XT_OVER, XT__21, XT_CELL_2B, XT__21, XT_EXIT, 
/* 0x40000fb8: 2@ */ F_tokenDoList, XT_DUP, XT_CELL_2B, XT__40, XT_SWAP, XT__40, XT_EXIT, 
/* 0x40000fd4: vHERE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vHERE + 0x1c, XT_EXIT, XT_HERE, XT_EXIT, 
/* 0x40000ff8: v, */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_v_2C + 0x38, XT_ALIGNED, XT_DUP, XT_CELL_2B, XT_VP, XT__21, XT__21, XT_branch, XT_v_2C + 0x3c, XT__2C, XT_EXIT, 
/* 0x40001038: vALIGN */ F_tokenDoList, XT_VP, XT__40, XT_ALIGNED, XT_VP, XT__21, XT_EXIT, 
/* 0x40001054: vCREATE */ F_tokenDoList, XT_VP, XT__40, XT__3FDUP, XT__3Fbranch, XT_vCREATE + 0x30, XT_tokenVar, XT_create, XT_vALIGN, XT__2C, XT_branch, XT_vCREATE + 0x34, XT_CREATE, XT_EXIT, 
/* 0x4000108c: PAD */ F_tokenDoList, XT_HERE, XT__28literal_29, 0x50, XT__2B, XT_EXIT, 
/* 0x400010a4: TIB */ F_tokenDoList, XT__23TIB, XT_CELL_2B, XT__40, XT_EXIT, 
/* 0x400010b8: @EXECUTE */ F_tokenDoList, XT__40, XT__3FDUP, XT__3Fbranch, XT__40EXECUTE + 0x18, XT_EXECUTE, XT_EXIT, 
/* 0x400010d4: COUNT */ F_tokenDoList, XT_DUP, XT_1_2B, XT_SWAP, XT_C_40, XT_EXIT, 
/* 0x400010ec: CMOVE */ F_tokenDoList, XT__3ER, XT_branch, XT_CMOVE + 0x30, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2B, XT_R_3E, XT_1_2B, XT__28next_29, XT_CMOVE + 0x10, XT_2DROP, XT_EXIT, 
/* 0x4000112c: CMOVE> */ F_tokenDoList, XT__3ER, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_SWAP, XT_R_40, XT_1_2D, XT__2B, XT_R_3E, XT__3ER, XT_branch, XT_CMOVE_3E + 0x58, XT__3ER, XT_DUP, XT_C_40, XT_R_40, XT_C_21, XT_1_2D, XT_R_3E, XT_1_2D, XT__28next_29, XT_CMOVE_3E + 0x38, XT_2DROP, XT_EXIT, 
/* 0x40001194: MOVE */ F_tokenDoList, XT__3ER, XT_2DUP, XT__3E, XT_R_3E, XT_SWAP, XT__3Fbranch, XT_MOVE + 0x2c, XT_CMOVE, XT_branch, XT_MOVE + 0x30, XT_CMOVE_3E, XT_EXIT, 
/* 0x400011c8: FILL */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_branch, XT_FILL + 0x24, XT_2DUP, XT_C_21, XT_1_2B, XT__28next_29, XT_FILL + 0x18, XT_2DROP, XT_EXIT, 
/* 0x400011fc: ERASE */ F_tokenDoList, XT__28literal_29, 0, XT_FILL, XT_EXIT, 
/* 0x40001210: -TRAILING */ F_tokenDoList, XT__3ER, XT_branch, XT__2DTRAILING + 0x3c, XT_BL, XT_OVER, XT_R_40, XT__2B, XT_C_40, XT__3C, XT__3Fbranch, XT__2DTRAILING + 0x3c, XT_R_3E, XT_1_2B, XT_EXIT, XT__28next_29, XT__2DTRAILING + 0x10, XT__28literal_29, 0, XT_EXIT, 
/* 0x40001260: PACK$ */ F_tokenDoList, XT_ALIGNED, XT_DUP, XT__3ER, XT_OVER, XT_DUP, XT__28literal_29, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__2D, XT_OVER, XT__2B, XT__28literal_29, 0, XT_SWAP, XT__21, XT_2DUP, XT_C_21, XT_1_2B, XT_SWAP, XT_CMOVE, XT_R_3E, XT_EXIT, 
/* 0x400012c4: DIGIT */ F_tokenDoList, XT__28literal_29, 9, XT_OVER, XT__3C, XT__28literal_29, 7, XT_AND, XT__2B, XT__28literal_29, 0x30, XT__2B, XT_EXIT, 
/* 0x400012f8: EXTRACT */ F_tokenDoList, XT__3ER, XT__28literal_29, 0, XT_R_40, XT_FM_2FMOD, XT_R_3E, XT_SWAP, XT__3ER, XT_FM_2FMOD, XT_R_3E, XT_ROT, XT_DIGIT, XT_EXIT, 
/* 0x40001330: <# */ F_tokenDoList, XT_PAD, XT_HLD, XT__21, XT_EXIT, 
/* 0x40001344: HOLD */ F_tokenDoList, XT_HLD, XT__40, XT_1_2D, XT_DUP, XT_HLD, XT__21, XT_C_21, XT_EXIT, 
/* 0x40001368: HOLDS */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_HOLDS + 0x2c, XT_1_2D, XT_2DUP, XT__2B, XT_C_40, XT_HOLD, XT_branch, XT_HOLDS + 4, XT_2DROP, XT_EXIT, 
/* 0x4000139c: # */ F_tokenDoList, XT_BASE, XT__40, XT_EXTRACT, XT_HOLD, XT_EXIT, 
/* 0x400013b4: #S */ F_tokenDoList, XT__23, XT_2DUP, XT_OR, XT__3Fbranch, XT__23S + 0x20, XT_branch, XT__23S + 4, XT_EXIT, 
/* 0x400013d8: SIGN */ F_tokenDoList, XT_0_3C, XT__3Fbranch, XT_SIGN + 0x1c, XT__28literal_29, 0x2d, XT_HOLD, XT_EXIT, 
/* 0x400013f8: #> */ F_tokenDoList, XT_2DROP, XT_HLD, XT__40, XT_PAD, XT_OVER, XT__2D, XT_EXIT, 
/* 0x40001418: EMIT */ F_tokenDoList, XT__27EMIT, XT__40EXECUTE, XT_EXIT, 
/* 0x40001428: SPACE */ F_tokenDoList, XT_BL, XT_EMIT, XT_EXIT, 
/* 0x40001438: emits */ F_tokenDoList, XT_SWAP, XT__28literal_29, 0, XT_MAX, XT__3ER, XT_branch, XT_emits + 0x28, XT_DUP, XT_EMIT, XT__28next_29, XT_emits + 0x20, XT_DROP, XT_EXIT, 
/* 0x40001470: SPACES */ F_tokenDoList, XT_BL, XT_emits, XT_EXIT, 
/* 0x40001480: .$ */ F_tokenDoList, XT_COUNT, XT_TYPE, XT_EXIT, 
/* 0x40001490: str */ F_tokenDoList, XT_DUP, XT__3ER, XT_ABS, XT__28literal_29, 0, XT__3C_23, XT__23S, XT_R_3E, XT_SIGN, XT__23_3E, XT_EXIT, 
/* 0x400014c0: HEX */ F_tokenDoList, XT__28literal_29, 0x10, XT_BASE, XT__21, XT_EXIT, 
/* 0x400014d8: DECIMAL */ F_tokenDoList, XT__28literal_29, 0xa, XT_BASE, XT__21, XT_EXIT, 
/* 0x400014f0: .R */ F_tokenDoList, XT__3ER, XT_str, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x40001514: U.R */ F_tokenDoList, XT__3ER, XT__28literal_29, 0, XT__3C_23, XT__23S, XT__23_3E, XT_R_3E, XT_OVER, XT__2D, XT_SPACES, XT_TYPE, XT_EXIT, 
/* 0x40001548: U. */ F_tokenDoList, XT__28literal_29, 0, XT__3C_23, XT__23S, XT__23_3E, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x4000156c: . */ F_tokenDoList, XT_BASE, XT__40, XT__28literal_29, 0xa, XT_XOR, XT__3Fbranch, XT__2E + 0x28, XT_U_2E, XT_EXIT, XT_str, XT_SPACE, XT_TYPE, XT_EXIT, 
/* 0x400015a4: ? */ F_tokenDoList, XT__40, XT__2E, XT_EXIT, 
/* 0x400015b4: DIGIT? */ F_tokenDoList, XT__3ER, XT__28literal_29, 0x30, XT__2D, XT__28literal_29, 0x2a, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x38, XT__28literal_29, 0x20, XT__2D, XT__28literal_29, 9, XT_OVER, XT__3C, XT__3Fbranch, XT_DIGIT_3F + 0x70, XT__28literal_29, 7, XT__2D, XT_DUP, XT__28literal_29, 0xa, XT__3C, XT_OR, XT_DUP, XT_R_3E, XT_U_3C, XT_EXIT, 
/* 0x40001634: ?KEY */ F_tokenDoList, XT__27_3FKEY, XT__40EXECUTE, XT_EXIT, 
/* 0x40001644: KEY */ F_tokenDoList, XT__28literal_29, 0, XT_ms, XT__28literal_29, 0xc8, XT__3FKEY, XT__3Fbranch, XT_KEY + 0xc, XT_NIP, XT_EXIT, 
/* 0x40001670: NUF? */ F_tokenDoList, XT__3FKEY, XT_DUP, XT__3Fbranch, XT_NUF_3F + 0x28, XT_2DROP, XT_KEY, XT__28literal_29, 0xd, XT__3D, XT_EXIT, 
/* 0x4000169c: PACE */ F_tokenDoList, XT__28literal_29, 0xb, XT_EMIT, XT_EXIT, 
/* 0x400016b0: CR */ F_tokenDoList, XT__28literal_29, 0xd, XT_EMIT, XT__28literal_29, 0xa, XT_EMIT, XT_EXIT, 
/* 0x400016d0: ['] */ F_tokenDoList, XT__27, XT_LITERAL, XT_EXIT, 
/* 0x400016e0: SOURCE */ F_tokenDoList, XT_TIB, XT__23TIB, XT__40, XT_EXIT, 
/* 0x400016f4: /STRING */ F_tokenDoList, XT_TUCK, XT__2D, XT__3ER, XT__2B, XT_R_3E, XT_EXIT, 
/* 0x40001710: isspace? */ F_tokenDoList, XT_BL, XT_1_2B, XT_U_3C, XT_EXIT, 
/* 0x40001724: isnotspace? */ F_tokenDoList, XT_isspace_3F, XT_0_3D, XT_EXIT, 
/* 0x40001734: xt-skip */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_xt_2Dskip + 0x40, XT_OVER, XT_C_40, XT_R_40, XT_EXECUTE, XT__3Fbranch, XT_xt_2Dskip + 0x40, XT__28literal_29, 1, XT__2FSTRING, XT_branch, XT_xt_2Dskip + 8, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x40001780: skip-till */ F_tokenDoList, XT__3ER, XT_DUP, XT__3Fbranch, XT_skip_2Dtill + 0x44, XT_OVER, XT_C_40, XT_R_40, XT__3D, XT_0_3D, XT__3Fbranch, XT_skip_2Dtill + 0x44, XT__28literal_29, 1, XT__2FSTRING, XT_branch, XT_skip_2Dtill + 8, XT_R_3E, XT_DROP, XT_EXIT, 
/* 0x400017d0:  */ F_tokenDoList, XT__3ER, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x40001808, XT__28literal_29, XT_isspace_3F, XT_xt_2Dskip, XT_OVER, XT_SWAP, XT_R_40, XT_BL, XT__3D, XT__3Fbranch, 0x40001838, XT__28literal_29, XT_isnotspace_3F, XT_xt_2Dskip, XT_branch, 0x40001840, XT_R_40, XT_skip_2Dtill, XT_R_3E, XT_DROP, XT_2DUP, XT__28literal_29, 1, XT_MIN, XT__2B, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_DROP, XT_OVER, XT__2D, XT_EXIT, 
/* 0x40001880: PARSE-NAME */ F_tokenDoList, XT_BL, XT_PARSE, XT_EXIT, 
/* 0x40001890: CHAR */ F_tokenDoList, XT_PARSE_2DNAME, XT_DROP, XT_C_40, XT_EXIT, 
/* 0x400018a4: [CHAR] */ F_tokenDoList, XT_CHAR, XT_LITERAL, XT_EXIT, 
/* 0x400018b4: CTRL */ F_tokenDoList, XT_CHAR, XT__28literal_29, 0x1f, XT_AND, XT_EXIT, 
/* 0x400018cc: .( */ F_tokenDoList, XT__28literal_29, 0x29, XT_PARSE, XT_TYPE, XT_EXIT, 
/* 0x400018e4:  */ F_tokenDoList, XT_PARSE_2DNAME, XT_BYTEMASK, XT_MIN, XT_NP, XT__40, XT_OVER, XT__2D, XT_CELLL, XT__2D, XT_PACK_24, XT_EXIT, 
/* 0x40001914: WORD */ F_tokenDoList, XT_PARSE, XT_HERE, XT_PACK_24, XT_EXIT, 
/* 0x40001928: NAME>INTERPRET */ F_tokenDoList, XT__28literal_29, 2, XT_CELLS, XT__2D, XT__40, XT_EXIT, 
/* 0x40001944: SAME? */ F_tokenDoList, XT__3ER, XT_branch, XT_SAME_3F + 0x54, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT_OVER, XT_R_40, XT_CELLS, XT__2B, XT__40, XT__2D, XT__3FDUP, XT__3Fbranch, XT_SAME_3F + 0x54, XT_R_3E, XT_DROP, XT_EXIT, XT__28next_29, XT_SAME_3F + 0x10, XT_FALSE, XT_EXIT, 
/* 0x400019a8: FIND-NAME */ F_tokenDoList, XT_CONTEXT, XT_DUP, XT_2_40, XT_XOR, XT__3Fbranch, XT_FIND_2DNAME + 0x20, XT_CELL_2D, XT__3ER, XT_R_3E, XT_CELL_2B, XT__3ER, XT_R_40, XT__40, XT__3Fbranch, XT_FIND_2DNAME + 0x70, XT_2DUP, XT_R_40, XT__40, XT_FIND_2DNAME_2DIN, XT__3FDUP, XT__3Fbranch, XT_FIND_2DNAME + 0x24, XT_R_3E, XT_DROP, XT_NIP, XT_NIP, XT_EXIT, XT_R_3E, XT_DROP, XT_2DROP, XT_FALSE, XT_EXIT, 
/* 0x40001a2c: NAME? */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_NAME_3F + 0x34, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_branch, XT_NAME_3F + 0x38, XT_FALSE, XT_EXIT, 
/* 0x40001a68: FIND */ F_tokenDoList, XT_DUP, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT__3Fbranch, XT_FIND + 0x58, XT_NIP, XT_DUP, XT_NAME_3EINTERPRET, XT_SWAP, XT_immediate_3F, XT__3Fbranch, XT_FIND + 0x48, XT__28literal_29, 1, XT_branch, XT_FIND + 0x50, XT__28literal_29, 0xffffffff, XT_branch, XT_FIND + 0x60, XT__28literal_29, 0, XT_EXIT, 
/* 0x40001acc: MARKER */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT_CONTEXT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CURRENT, XT__40, XT_DUP, XT__40, XT_SWAP, XT_CREATE, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT__2C, XT_DOES_3E, XT_DUP, XT__40, XT_CURRENT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CURRENT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CONTEXT, XT__40, XT__21, XT_CELL_2B, XT_DUP, XT__40, XT_CP, XT__21, XT_CELL_2B, XT__40, XT_NP, XT__21, XT_EXIT, 
/* 0x40001ba4: CATCH */ F_tokenDoList, XT_SP_40, XT__3ER, XT_HANDLER, XT__40, XT__3ER, XT_RP_40, XT_HANDLER, XT__21, XT_EXECUTE, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_DROP, XT__28literal_29, 0, XT_EXIT, 
/* 0x40001bec: THROW */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT_THROW + 0x40, XT_HANDLER, XT__40, XT_RP_21, XT_R_3E, XT_HANDLER, XT__21, XT_R_3E, XT_SWAP, XT__3ER, XT_SP_21, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40001c30: ^H */ F_tokenDoList, XT__3ER, XT_OVER, XT_R_40, XT__3C, XT_DUP, XT__3Fbranch, XT__5EH + 0x4c, XT__28literal_29, 8, XT__27ECHO, XT__40EXECUTE, XT_BL, XT__27ECHO, XT__40EXECUTE, XT__28literal_29, 8, XT__27ECHO, XT__40EXECUTE, XT_R_3E, XT__2B, XT_EXIT, 
/* 0x40001c88: TAP */ F_tokenDoList, XT_DUP, XT__27ECHO, XT__40EXECUTE, XT_OVER, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x40001ca8: crlf? */ F_tokenDoList, XT_DUP, XT__28literal_29, 0xa, XT__3D, XT_SWAP, XT__28literal_29, 0xd, XT__3D, XT_OR, XT_EXIT, 
/* 0x40001cd4: skipCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipCRLF + 0x24, XT_OVER, XT_C_40, XT_crlf_3F, XT_branch, XT_skipCRLF + 0x28, XT_FALSE, XT__3Fbranch, XT_skipCRLF + 0x48, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipCRLF + 4, XT_EXIT, 
/* 0x40001d20: skipToCRLF */ F_tokenDoList, XT_DUP, XT__3Fbranch, XT_skipToCRLF + 0x28, XT_OVER, XT_C_40, XT_crlf_3F, XT_0_3D, XT_branch, XT_skipToCRLF + 0x2c, XT_FALSE, XT__3Fbranch, XT_skipToCRLF + 0x4c, XT_1_2D, XT_SWAP, XT_1_2B, XT_SWAP, XT_branch, XT_skipToCRLF + 4, XT_EXIT, 
/* 0x40001d70: kTAP */ F_tokenDoList, XT_DUP, XT_crlf_3F, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x60, XT_DUP, XT__28literal_29, 8, XT__3D, XT_SWAP, XT__28literal_29, 0x7f, XT__3D, XT_OR, XT_0_3D, XT__3Fbranch, XT_kTAP + 0x58, XT_BL, XT_TAP, XT_branch, XT_kTAP + 0x5c, XT__5EH, XT_EXIT, XT_DROP, XT_NIP, XT_DUP, XT_EXIT, 
/* 0x40001de0: do$ */ F_tokenDoList, XT_R_3E, XT_R_40, XT_R_3E, XT_COUNT, XT__2B, XT_ALIGNED, XT__3ER, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40001e0c: $," */ F_tokenDoList, XT__28literal_29, 0x22, XT_WORD, XT_COUNT, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x40001e34: $"| */ F_tokenDoList, XT_do_24, XT_EXIT, 
/* 0x40001e40: ."| */ F_tokenDoList, XT_do_24, XT__2E_24, XT_EXIT, 
/* 0x40001e50: S"| */ F_tokenDoList, XT_do_24, XT_COUNT, XT_EXIT, 
/* 0x40001e60: $" */ F_tokenDoList, XT_COMPILE, XT__24_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001e74: C" */ F_tokenDoList, XT__24_22, XT_EXIT, 
/* 0x40001e80: ." */ F_tokenDoList, XT_COMPILE, XT__2E_22_7C, XT__24_2C_22, XT_EXIT, 
/* 0x40001e94: S" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_22 + 0x28, XT_COMPILE, XT_S_22_7C, XT__24_2C_22, XT_branch, XT_S_22 + 0x40, XT__28literal_29, 0x22, XT_PARSE, XT_stringBuffer, XT_PACK_24, XT_COUNT, XT_EXIT, 
/* 0x40001ed8: bu+@ */ F_tokenDoList, XT_1_2D, XT__3ER, XT_COUNT, XT_R_3E, XT_SWAP, XT_EXIT, 
/* 0x40001ef4: c+! */ F_tokenDoList, XT_TUCK, XT_C_21, XT_1_2B, XT_EXIT, 
/* 0x40001f08: cmove\ */ F_tokenDoList, XT_SWAP, XT_DUP, XT__3ER, XT__3ER, XT__3FDUP, XT__3Fbranch, 0x400021dc, XT_bu_2B_40, XT_DUP, XT__28literal_29, 0x22, XT__3C_3E, XT__3Fbranch, 0x400021d8, XT__28literal_29, 0x5c, XT__28of_29, 0x400021bc, XT_bu_2B_40, XT__28literal_29, 0x6d, XT__28of_29, XT_cmove_5C + 0x8c, XT__28literal_29, 0xd, XT_R_3E, XT_c_2B_21, XT__28literal_29, 0xa, XT_SWAP, XT_c_2B_21, XT__3ER, XT_branch, 0x400021b4, XT__28literal_29, 0x78, XT__28of_29, XT_cmove_5C + 0xf0, XT_bu_2B_40, XT__28literal_29, 0x10, XT_DIGIT_3F, XT_DROP, XT__28literal_29, 0x10, XT__2A, XT__3ER, XT_bu_2B_40, XT__28literal_29, 0x10, XT_DIGIT_3F, XT_DROP, XT_R_3E, XT__2B, XT_R_3E, XT_c_2B_21, XT__3ER, XT_branch, 0x400021b4, XT__28literal_29, 0x61, XT__28of_29, 0x40002018, XT__28literal_29, 7, XT_branch, 0x400021a0, XT__28literal_29, 0x62, XT__28of_29, 0x40002038, XT__28literal_29, 8, XT_branch, 0x400021a0, XT__28literal_29, 0x65, XT__28of_29, 0x40002058, XT__28literal_29, 0x1b, XT_branch, 0x400021a0, XT__28literal_29, 0x66, XT__28of_29, 0x40002078, XT__28literal_29, 0xc, XT_branch, 0x400021a0, XT__28literal_29, 0x6c, XT__28of_29, 0x40002098, XT__28literal_29, 0xa, XT_branch, 0x400021a0, XT__28literal_29, 0x6e, XT__28of_29, 0x400020b8, XT__28literal_29, 0xa, XT_branch, 0x400021a0, XT__28literal_29, 0x71, XT__28of_29, 0x400020d8, XT__28literal_29, 0x22, XT_branch, 0x400021a0, XT__28literal_29, 0x72, XT__28of_29, 0x400020f8, XT__28literal_29, 0xd, XT_branch, 0x400021a0, XT__28literal_29, 0x74, XT__28of_29, 0x40002118, XT__28literal_29, 9, XT_branch, 0x400021a0, XT__28literal_29, 0x76, XT__28of_29, 0x40002138, XT__28literal_29, 0xb, XT_branch, 0x400021a0, XT__28literal_29, 0x7a, XT__28of_29, 0x40002158, XT__28literal_29, 0, XT_branch, 0x400021a0, XT__28literal_29, 0x22, XT__28of_29, 0x40002178, XT__28literal_29, 0x22, XT_branch, 0x400021a0, XT__28literal_29, 0x5c, XT__28of_29, 0x40002198, XT__28literal_29, 0x5c, XT_branch, 0x400021a0, XT_DUP, XT_DROP, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, 0x400021d0, XT_DUP, XT_R_3E, XT_c_2B_21, XT__3ER, XT_DROP, XT_branch, XT_cmove_5C + 0x14, XT_2DROP, XT_R_3E, XT_R_3E, XT__2D, XT_EXIT, 
/* 0x400021ec: pack\$ */ F_tokenDoList, XT_ALIGNED, XT__3ER, XT_R_40, XT_1_2B, XT_SWAP, XT_cmove_5C, XT_DUP, XT_R_40, XT_C_21, XT_DUP, XT_R_40, XT__2B, XT_1_2B, XT_SWAP, XT__28literal_29, 0, XT_CELLL, XT_UM_2FMOD, XT_DROP, XT__3FDUP, XT__3Fbranch, XT_pack_5C_24 + 0x84, XT_SWAP, XT__28literal_29, 0, XT_OVER, XT_C_21, XT_1_2B, XT_SWAP, XT_1_2D, XT_branch, XT_pack_5C_24 + 0x50, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x4000227c: S\" */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x28, XT_COMPILE, XT_S_22_7C, XT_HERE, XT_branch, XT_S_5C_22 + 0x2c, XT_stringBuffer, XT_SOURCE, XT__3EIN, XT__40, XT__2FSTRING, XT_ROT, XT_pack_5C_24, XT_SWAP, XT_SOURCE, XT_DROP, XT__2D, XT__3EIN, XT__21, XT_COUNT, XT_STATE, XT__40, XT__3Fbranch, XT_S_5C_22 + 0x80, XT__2B, XT_ALIGNED, XT_CP, XT__21, XT_EXIT, 
/* 0x40002300: NULL$ */ F_tokenCreate, 0, 0, 
/* 0x4000230c: ABORT */ F_tokenDoList, XT_NULL_24, XT_THROW, XT_EXIT, 
/* 0x4000231c: (abort") */ F_tokenDoList, XT__3Fbranch, XT__28abort_22_29 + 0x14, XT_do_24, XT_THROW, XT_do_24, XT_DROP, XT_EXIT, 
/* 0x4000233c: ABORT" */ F_tokenDoList, XT_COMPILE, XT__28abort_22_29, XT__24_2C_22, XT_EXIT, 
/* 0x40002350: POSTPONE */ F_tokenDoList, XT_TOKEN, XT_COUNT, XT_FIND_2DNAME, XT__3FDUP, XT_0_3D, XT__28abort_22_29, 0x746f4e09, 0x756f6620, 0x646e, XT_DUP, XT_immediate_3F, XT_0_3D, XT__3Fbranch, XT_POSTPONE + 0x44, XT_COMPILE, XT_COMPILE, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x400023a0:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x400023e0, XT_C_40, XT__28literal_29, 0x40, XT_AND, XT__28abort_22_29, 0x6d6f630c, 0x656c6970, 0x4c4e4f20, 0x59, XT_EXECUTE, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x400023f0, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x400023f8: .OK */ F_tokenDoList, XT_STATE, XT__40, XT_0_3D, XT__3Fbranch, XT__2EOK + 0x20, XT__2E_22_7C, 0x6b6f2003, XT_CR, XT_EXIT, 
/* 0x40002420: ?STACK */ F_tokenDoList, XT_DEPTH, XT_0_3C, XT__28abort_22_29, 0x646e7509, 0x6c667265, 0x776f, XT_EXIT, 
/* 0x40002440:  */ F_tokenDoList, XT_FALSE, XT_STATE, XT__21, XT_EXIT, 
/* 0x40002454: XIO */ F_tokenDoList, XT__27TAP, XT__21, XT__27ECHO, XT__21, XT__27PROMPT, XT__21, XT_EXIT, 
/* 0x40002474: FILE */ F_tokenDoList, XT__28literal_29, 0, XT__28literal_29, XT_DROP, XT__28literal_29, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x40002498: HAND */ F_tokenDoList, XT__28literal_29, XT__2EOK, XT__28literal_29, XT_EMIT, XT__28literal_29, XT_kTAP, XT_XIO, XT_EXIT, 
/* 0x400024bc: I/O */ F_tokenCreate, 0, XT__3FRX, XT_TX_21, 
/* 0x400024cc: CONSOLE */ F_tokenDoList, XT_I_2FO, XT_2_40, XT__27_3FKEY, XT_2_21, XT_HAND, XT_EXIT, 
/* 0x400024e8:  */ F_tokenDoList, XT_TOKEN, XT_NAME_3F, XT__3Fbranch, 0x40002500, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x40002508: ALLOT */ F_tokenDoList, XT_CP, XT__2B_21, XT_EXIT, 
/* 0x40002518: vALLOT */ F_tokenDoList, XT_VP, XT__40, XT__3Fbranch, XT_vALLOT + 0x24, XT_VP, XT__2B_21, XT_branch, XT_vALLOT + 0x28, XT_ALLOT, XT_EXIT, 
/* 0x40002544: BUFFER: */ F_tokenDoList, XT_CREATE, XT_vALLOT, XT_EXIT, 
/* 0x40002554: '>BODY! */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT__27_3EBODY_21 + 0x28, XT__5B_27_5D, XT_COMPILE, XT__3EBODY_21, XT_branch, XT__27_3EBODY_21 + 0x30, XT__27, XT__3EBODY_21, XT_EXIT, 
/* 0x40002588: IS */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x40002594: ACTION-OF */ F_tokenDoList, XT_STATE, XT__40, XT__3Fbranch, XT_ACTION_2DOF + 0x28, XT__5B_27_5D, XT_COMPILE, XT_DEFER_40, XT_branch, XT_ACTION_2DOF + 0x30, XT__27, XT_DEFER_40, XT_EXIT, 
/* 0x400025c8: RECURSE */ F_tokenDoList, XT_LAST, XT__40, XT_NAME_3EINTERPRET, XT__2C, XT_EXIT, 
/* 0x400025e0: ?UNIQUE */ F_tokenDoList, XT_DUP, XT_NAME_3F, XT__3Fbranch, XT__3FUNIQUE + 0x28, XT__2E_22_7C, 0x65722007, 0x20666544, XT_OVER, XT__2E_24, XT_DROP, XT_EXIT, 
/* 0x40002610:  */ F_tokenDoList, XT_DUP, XT_C_40, XT__3Fbranch, 0x40002630, XT__3FUNIQUE, XT__28_24_2Cn_29, XT_EXIT, XT__24_22_7C, 0x6d616e04, 0x65, XT_THROW, XT_EXIT, 
/* 0x40002644:  */ F_tokenDoList, XT_NAME_3F, XT__3FDUP, XT__3Fbranch, 0x40002680, XT_C_40, XT_IMED, XT_AND, XT__3Fbranch, 0x40002678, XT_EXECUTE, XT_branch, 0x4000267c, XT__2C, XT_EXIT, XT_NUMBER_3F, XT__3Fbranch, 0x40002694, XT_LITERAL, XT_EXIT, XT_THROW, XT_EXIT, 
/* 0x4000269c: EVAL */ F_tokenDoList, XT_TOKEN, XT_DUP, XT_C_40, XT__3Fbranch, XT_EVAL + 0x44, XT_STATE, XT__40, XT__3Fbranch, XT_EVAL + 0x34, XT__24COMPILE, XT_branch, XT_EVAL + 0x38, XT__24INTERPRET, XT__3FSTACK, XT_branch, XT_EVAL + 4, XT_DROP, XT__27PROMPT, XT__40EXECUTE, XT_EXIT, 
/* 0x400026f0:  */ F_tokenDoList, XT_LAST, XT__40, XT_DUP, XT__40, XT__3Fbranch, 0x40002720, XT_CURRENT, XT__40, XT__21, XT_branch, 0x40002744, XT_DROP, XT_NP, XT__40, XT__28literal_29, 3, XT_CELLS, XT__2B, XT_NP, XT__21, XT_EXIT, 
/* 0x40002748:  */ F_tokenDoList, XT_COMPILE, XT_EXIT, XT__5B, XT_OVERT, XT_EXIT, 3, XT_TRUE, XT_STATE, XT__21, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDoList, XT__2C, XT__5D, XT_EXIT, 3, XT_TOKEN, XT__24_2Cn, XT_tokenDefer, XT__2C, XT__28literal_29, 0, XT__2C, XT_OVERT, XT_EXIT, 
/* 0x400027b8: VALUE */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_HERE, XT_tokenValue, XT__2C, XT__5FUSER, XT__40, XT__2C, XT__5FUSER, XT__2B_2B, XT__3EBODY_21, XT_EXIT, 
/* 0x400027f0: TO */ F_tokenDoList, XT__27_3EBODY_21, XT_EXIT, 
/* 0x400027fc: VARIABLE */ F_tokenDoList, XT_vCREATE, XT__28literal_29, 0, XT_v_2C, XT_EXIT, 
/* 0x40002814: CONSTANT */ F_tokenDoList, XT_TOKEN, XT__24_2Cn, XT_OVERT, XT_tokenNextVal, XT__2C, XT__2C, XT_EXIT, 
/* 0x40002834: leave-ptr */ F_tokenVar, 0, 0xc, 
/* 0x40002840: (?do) */ F_tokenDoList, XT_R_3E, XT__2DROT, XT_2DUP, XT_2_3ER, XT__3C_3E, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40002864: (loop) */ F_tokenDoList, XT_R_3E, XT_2R_3E, XT_1_2B, XT_2DUP, XT_2_3ER, XT__3D, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x4000288c: (+loop) */ F_tokenDoList, XT_R_3E, XT_SWAP, XT_2R_3E, XT__28literal_29, 2, XT_PICK, XT_OVER, XT__2B, XT_ROT, XT_DUP, XT__3ER, XT__2DROT, XT_DUP, XT__3ER, XT__28literal_29, 3, XT_PICK, XT_0_3C, XT__3Fbranch, XT__28_2Bloop_29 + 0x58, XT_SWAP, XT_1_2B, XT_SWAP, XT_1_2B, XT_SWAP, XT_WITHIN, XT_NIP, XT_SWAP, XT__3ER, XT_EXIT, 
/* 0x40002908: leave, */ F_tokenDoList, XT_HERE, XT_leave_2Dptr, XT__40, XT__2C, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x40002928: LEAVE */ F_tokenDoList, XT_COMPILE, XT_branch, XT_leave_2C, XT_EXIT, 
/* 0x4000293c: UNLOOP */ F_tokenDoList, XT_COMPILE, XT_2RDrop, XT_EXIT, 
/* 0x4000294c: DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT__28literal_29, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT_2_3ER, XT_HERE, XT_EXIT, 
/* 0x40002978: ?DO */ F_tokenDoList, XT_leave_2Dptr, XT__40, XT__28literal_29, 0, XT_leave_2Dptr, XT__21, XT_COMPILE, XT__28_3Fdo_29, XT_COMPILE, XT__3Fbranch, XT_leave_2C, XT_HERE, XT_EXIT, 
/* 0x400029b0: some-loop */ F_tokenDoList, XT_COMPILE, XT__3Fbranch, XT__2C, XT_leave_2Dptr, XT__40, XT__3FDUP, XT__3Fbranch, XT_some_2Dloop + 0x48, XT_DUP, XT__40, XT__3ER, XT_HERE, XT_SWAP, XT__21, XT_R_3E, XT_branch, XT_some_2Dloop + 0x18, XT_UNLOOP, XT_leave_2Dptr, XT__21, XT_EXIT, 
/* 0x40002a08: LOOP */ F_tokenDoList, XT_COMPILE, XT__28loop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x40002a1c: +LOOP */ F_tokenDoList, XT_COMPILE, XT__28_2Bloop_29, XT_some_2Dloop, XT_EXIT, 
/* 0x40002a30: I-MAX */ F_tokenDoList, XT_RP_40, XT__28literal_29, 2, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a50: J */ F_tokenDoList, XT_RP_40, XT__28literal_29, 3, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a70: J-MAX */ F_tokenDoList, XT_RP_40, XT__28literal_29, 4, XT_CELLS, XT__2B, XT__40, XT_EXIT, 
/* 0x40002a90: accumulate */ F_tokenDoList, XT_SWAP, XT__3ER, XT_SWAP, XT_BASE, XT__40, XT_UM_2A, XT_DROP, XT_ROT, XT_BASE, XT__40, XT_UM_2A, XT_D_2B, XT_R_3E, XT_EXIT, 
/* 0x40002acc: >NUMBER */ F_tokenDoList, XT__28literal_29, 0, XT_SWAP, XT__28literal_29, 0, XT__28_3Fdo_29, XT__3Fbranch, XT__3ENUMBER + 0x78, XT_DROP, XT_COUNT, XT_BASE, XT__40, XT_DIGIT_3F, XT_0_3D, XT__3Fbranch, XT__3ENUMBER + 0x60, XT_DROP, XT_1_2D, XT_I_2DMAX, XT_I, XT__2D, XT_branch, XT__3ENUMBER + 0x78, XT_accumulate, XT__28literal_29, 0, XT__28loop_29, XT__3Fbranch, XT__3ENUMBER + 0x24, XT_2RDrop, XT_EXIT, 
/* 0x40002b4c: (charbase) */ F_tokenDoList, XT_DUP, XT__28literal_29, 0x23, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x28, XT__28literal_29, 0xa, XT_EXIT, XT_DUP, XT__28literal_29, 0x24, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x4c, XT__28literal_29, 0x10, XT_EXIT, XT_DUP, XT__28literal_29, 0x25, XT__3D, XT__3Fbranch, XT__28charbase_29 + 0x70, XT__28literal_29, 2, XT_EXIT, XT__28literal_29, 0, XT_EXIT, 3, XT_DUP, XT_BASE, XT__40, XT__3ER, XT_COUNT, XT_OVER, XT__3ER, XT__3ER, XT_COUNT, XT__28charbase_29, XT__3FDUP, XT__3Fbranch, XT__28charbase_29 + 0xc4, XT_BASE, XT__21, XT_DROP, XT_COUNT, XT_DUP, XT__28literal_29, 0x27, XT__3D, XT__3Fbranch, 0x40002c80, XT_DROP, XT_COUNT, XT_SWAP, XT_COUNT, XT__28literal_29, 0x27, XT__3C_3E, XT__3Fbranch, 0x40002c60, XT_2DROP, XT_2RDrop, XT_FALSE, XT_branch, 0x40002c70, XT_DROP, XT_NIP, XT_TRUE, XT_2RDrop, XT_R_3E, XT_BASE, XT__21, XT_EXIT, XT__28literal_29, 0x2d, XT__3D, XT_TUCK, XT_0_3D, XT__3Fbranch, 0x40002ca0, XT_1_2D, XT__28literal_29, 0, XT__28literal_29, 0, XT_ROT, XT_R_3E, XT_R_3E, XT__2B, XT_OVER, XT__2D, XT__3ENUMBER, XT__3Fbranch, 0x40002ce8, XT_2DROP, XT_2DROP, XT_FALSE, XT_branch, 0x40002d08, XT_DROP, XT_ROT, XT__3Fbranch, 0x40002cfc, XT_DNEGATE, XT_DROP, XT_NIP, XT_TRUE, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x40002d18: ACCEPT */ F_tokenDoList, XT_OVER, XT__2B, XT_OVER, XT_2DUP, XT_XOR, XT__3Fbranch, XT_ACCEPT + 0x60, XT_KEY, XT_DUP, XT_BL, XT__2D, XT__28literal_29, 0x5f, XT_U_3C, XT__3Fbranch, XT_ACCEPT + 0x50, XT_TAP, XT_branch, XT_ACCEPT + 0x58, XT__27TAP, XT__40EXECUTE, XT_branch, XT_ACCEPT + 0x10, XT_DROP, XT_SWAP, XT__2D, XT_EXIT, 
/* 0x40002d88: stack */ F_tokenDoList, XT_CREATE, XT_HERE, XT__28literal_29, 0, XT__2C, XT_OVER, XT__2C, XT_vHERE, XT_SWAP, XT__21, XT__28literal_29, 0, XT_v_2C, XT_CELLS, XT_vALLOT, XT_EXIT, 
/* 0x40002dcc: spop */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_CELLS, XT_OVER, XT__2B, XT__40, XT_SWAP, XT__2D_2D, XT_EXIT, 
/* 0x40002df8: spush */ F_tokenDoList, XT__40, XT_DUP, XT__40, XT_1_2B, XT_2DUP, XT_SWAP, XT__21, XT_CELLS, XT__2B, XT__21, XT_EXIT, 
/* 0x40002e28: spushes */ F_tokenDoList, XT_OVER, XT__3ER, XT_SWAP, XT__28literal_29, 0, XT_2_3ER, XT_TUCK, XT_spush, XT__28loop_29, XT__3Fbranch, XT_spushes + 0x1c, XT_2RDrop, XT_R_3E, XT_SWAP, XT_spush, XT_EXIT, 
/* 0x40002e6c: spops */ F_tokenDoList, XT_DUP, XT_spop, XT__3ER, XT_R_40, XT__28literal_29, 0, XT_2_3ER, XT_DUP, XT_spop, XT_SWAP, XT__28loop_29, XT__3Fbranch, XT_spops + 0x20, XT_2RDrop, XT_DROP, XT_R_3E, XT_EXIT, 
/* 0x40002eb4: sempty */ F_tokenDoList, XT__40, XT__28literal_29, 0, XT_SWAP, XT__21, XT_EXIT, 
/* 0x40002ed0: SOURCE-ID */ F_tokenDoList, XT_source_2Did, XT__40, XT_EXIT, 
/* 0x40002ee0: sourceStack */ F_tokenCreate, 0, 0x10, 0x20, 
/* 0x40002ef0: 0> */ F_tokenDoList, XT_DUP, XT_0_3D, XT_SWAP, XT_0_3C, XT_OR, XT_0_3D, XT_EXIT, 
/* 0x40002f10: unreadFile */ F_tokenDefer, 0, 
/* 0x40002f18: SAVE-INPUT */ F_tokenDoList, XT_SOURCE_2DID, XT_SOURCE, XT__3EIN, XT__40, XT__28literal_29, 4, XT_EXIT, 
/* 0x40002f38: sourcePush */ F_tokenDoList, XT_SAVE_2DINPUT, XT_sourceStack, XT_spushes, XT_EXIT, 
/* 0x40002f4c: RESTORE-INPUT */ F_tokenDoList, XT_DROP, XT__3EIN, XT__21, XT__23TIB, XT__21, XT__23TIB, XT_CELL_2B, XT__21, XT_DUP, XT_source_2Did, XT__21, XT__3Fbranch, XT_RESTORE_2DINPUT + 0x44, XT_FILE, XT_branch, XT_RESTORE_2DINPUT + 0x48, XT_HAND, XT__28literal_29, 0, XT_EXIT, 
/* 0x40002fa0: sourcePop */ F_tokenDoList, XT_sourceStack, XT_spops, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x40002fb8: READ-LINE */ F_tokenDefer, 0, 
/* 0x40002fc0: REFILL */ F_tokenDoList, XT_SOURCE_2DID, XT__3FDUP, XT__3Fbranch, XT_REFILL + 0x34, XT_DROP, XT_FALSE, XT__28literal_29, 0, XT__3EIN, XT__21, XT_branch, XT_REFILL + 0x60, XT_TIB, XT__28literal_29, 0x50, XT_ACCEPT, XT__23TIB, XT__21, XT__28literal_29, 0, XT__3EIN, XT__21, XT_TRUE, XT_EXIT, 
/* 0x40003024: QUERY */ F_tokenDoList, XT_REFILL, XT_0_3D, XT__3Fbranch, XT_QUERY + 0x18, XT_sourcePop, XT_EXIT, 3, XT__28literal_29, 0x29, XT_PARSE, XT__2B, XT_C_40, XT__28literal_29, 0x29, XT__3C_3E, XT__3Fbranch, XT_QUERY + 0x70, XT_REFILL, XT_0_3D, XT__28abort_22_29, 0x746e7514, 0x696d7265, 0x6574616e, 0x6f632064, 0x6e656d6d, 0x74, XT_QUERY + 0x1c, XT_EXIT, 
/* 0x40003098: que */ F_tokenDoList, XT_QUERY, XT_EVAL, XT_EXIT, 
/* 0x400030a8: PRESET */ F_tokenDoList, XT_SP0, XT__40, XT_SP_21, XT_sourceStack, XT_sempty, XT__28literal_29, 0, XT_TIB0, XT__28literal_29, 0, XT__28literal_29, 0, XT__28literal_29, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_EXIT, 
/* 0x400030f0: quitError */ F_tokenDoList, XT_NULL_24, XT_OVER, XT_XOR, XT__3Fbranch, XT_quitError + 0x54, XT_CR, XT_TIB, XT__23TIB, XT__40, XT_TYPE, XT_CR, XT__3EIN, XT__40, XT__28literal_29, 0x5e, XT_emits, XT_CR, XT__2E_24, XT__2E_22_7C, 0x203f2003, XT_PRESET, XT_EXIT, 
/* 0x4000314c: QUIT */ F_tokenDoList, XT_RP0, XT__40, XT_RP_21, XT__5B, XT__28literal_29, XT_que, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x14, XT__27PROMPT, XT__40, XT__3ER, XT_CONSOLE, XT_quitError, XT_R_3E, XT__3FDUP, XT__3Fbranch, XT_QUIT + 0x58, XT__27PROMPT, XT__21, XT_branch, XT_QUIT + 0x10, XT_EXIT, 
/* 0x400031b0: quit1 */ F_tokenDoList, XT__28literal_29, XT_EVAL, XT_CATCH, XT__3FDUP, XT__3Fbranch, XT_quit1 + 0x24, XT_quitError, XT__5B, XT_EXIT, 
/* 0x400031d8: EVALUATE */ F_tokenDoList, XT_sourcePush, XT__28literal_29, 0xffffffff, XT__2DROT, XT__28literal_29, 0, XT__28literal_29, 4, XT_RESTORE_2DINPUT, XT_THROW, XT_quit1, XT_EXIT, 
/* 0x4000320c: dm+ */ F_tokenDoList, XT_OVER, XT__28literal_29, 4, XT_U_2ER, XT_SPACE, XT__3ER, XT_branch, XT_dm_2B + 0x3c, XT_DUP, XT_C_40, XT__28literal_29, 3, XT_U_2ER, XT_1_2B, XT__28next_29, XT_dm_2B + 0x24, XT_EXIT, 
/* 0x40003254: DUMP */ F_tokenDoList, XT_BASE, XT__40, XT__3ER, XT_HEX, XT__28literal_29, 0x10, XT__2F, XT__3ER, XT_CR, XT__28literal_29, 0x10, XT_2DUP, XT_dm_2B, XT__2DROT, XT__28literal_29, 2, XT_SPACES, XT_TYPE, XT_NUF_3F, XT_0_3D, XT__3Fbranch, XT_DUMP + 0x6c, XT__28next_29, XT_DUMP + 0x24, XT_branch, XT_DUMP + 0x74, XT_R_3E, XT_DROP, XT_DROP, XT_R_3E, XT_BASE, XT__21, XT_EXIT, 
/* 0x400032dc: .S */ F_tokenDoList, XT_CR, XT_DEPTH, XT__3ER, XT_branch, XT__2ES + 0x24, XT_R_40, XT_PICK, XT__2E, XT__28next_29, XT__2ES + 0x18, XT__2E_22_7C, 0x733c2005, 0x2070, XT_EXIT, 
/* 0x40003318: UNUSED */ F_tokenDoList, XT_NP, XT__40, XT_CP, XT__40, XT__2D, XT_EXIT, 
/* 0x40003334: .BASE */ F_tokenDoList, XT_BASE, XT__40, XT_DECIMAL, XT_DUP, XT__2E, XT_BASE, XT__21, XT_EXIT, 
/* 0x40003358: .FREE */ F_tokenDoList, XT_CP, XT_2_40, XT__2D, XT_U_2E, XT_EXIT, 
/* 0x40003370: !CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__21, XT_EXIT, 
/* 0x40003384: ?CSP */ F_tokenDoList, XT_SP_40, XT_CSP, XT__40, XT_XOR, XT__28abort_22_29, 0x6174730b, 0x64206b63, 0x68747065, XT_EXIT, 
/* 0x400033ac: .ID */ F_tokenDoList, XT__3FDUP, XT__3Fbranch, XT__2EID + 0x24, XT_COUNT, XT_BYTEMASK, XT_AND, XT_TYPE, XT_EXIT, XT__2E_22_7C, 0x6f6e7b08, 0x656d614e, 0x7d, XT_EXIT, 
/* 0x400033e4: WORDS */ F_tokenDoList, XT_CR, XT_CONTEXT, XT__40, XT__40, XT__3FDUP, XT__3Fbranch, XT_WORDS + 0x40, XT_DUP, XT_SPACE, XT__2EID, XT_CELL_2D, XT_NUF_3F, XT__3Fbranch, XT_WORDS + 0x10, XT_DROP, XT_EXIT, 
/* 0x40003428: >NAME */ F_tokenDoList, XT_CURRENT, XT_CELL_2B, XT__40, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 0x6c, XT_2DUP, XT__40, XT_DUP, XT__3Fbranch, XT__3ENAME + 0x50, XT_2DUP, XT_NAME_3EINTERPRET, XT_XOR, XT__3Fbranch, XT__3ENAME + 0x50, XT_CELL_2D, XT_branch, XT__3ENAME + 0x20, XT_NIP, XT__3FDUP, XT__3Fbranch, XT__3ENAME + 8, XT_NIP, XT_NIP, XT_EXIT, XT_DROP, XT_FALSE, XT_EXIT, 
/* 0x400034a0: SEE */ F_tokenDoList, XT__27, XT_CR, XT_DUP, XT__40, XT_tokenDoList, XT__3D, XT__3Fbranch, XT_SEE + 0xd0, XT__2E_22_7C, 0x203a02, XT_DUP, XT__3ENAME, XT__2EID, XT_CELL_2B, XT_DUP, XT__40, XT_DUP, XT__3Fbranch, XT_SEE + 0x54, XT__3ENAME, XT__3FDUP, XT__3Fbranch, XT_SEE + 0xb0, XT_SPACE, XT__2EID, XT_DUP, XT__40, XT__28literal_29, XT_EXIT, XT__3D, XT_OVER, XT_CELL_2B, XT__40, XT__28literal_29, 0x14, XT__3C, XT_AND, XT__3Fbranch, XT_SEE + 0xa8, XT_DROP, XT_EXIT, XT_branch, XT_SEE + 0xbc, XT_DUP, XT__40, XT_U_2E, XT_NUF_3F, XT__3Fbranch, XT_SEE + 0x38, XT_branch, XT_SEE + 0xec, XT__2E_22_7C, 0x746f4e14, 0x6c6f6320, 0x64206e6f, 0x6e696665, 0x6f697469, 0x6e, XT_DROP, XT_EXIT, 
/* 0x40003594: VER */ F_tokenNextVal, 0x11, 
/* 0x4000359c: version */ F_tokenDoList, XT_CR, XT__2E_22_7C, 0x6265770a, 0x54524f46, 0x562048, XT_BASE, XT__40, XT_DECIMAL, XT_VER, XT__28literal_29, 0, XT__3C_23, XT__23, XT__23, XT__28literal_29, 0x2e, XT_HOLD, XT__23, XT__23, XT__28literal_29, 0x2e, XT_HOLD, XT__23, XT__23_3E, XT_TYPE, XT_BASE, XT__21, XT_CR, XT_EXIT, 
/* 0x40003614: hi */ F_tokenDoList, XT__21IO, XT_version, XT_EXIT, 
/* 0x40003624: EMPTY */ F_tokenDoList, XT_FORTH, XT_CONTEXT, XT__40, XT_DUP, XT_CURRENT, XT_2_21, XT_EXIT, 
/* 0x40003644: 'BOOT */ F_tokenCreate, 0, XT_hi, 
/* 0x40003650: COLD */ F_tokenDoList, XT_userAreaInit, XT_PRESET, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_EMPTY, XT_OVERT, XT_QUIT, XT_branch, XT_COLD + 4, XT_EXIT, 
/* 0x40003680: WARM */ F_tokenDoList, XT_CONSOLE, XT__27BOOT, XT__40EXECUTE, XT_QUIT, XT_EXIT, 
/* ==== CURRENT TOP OF CODE DICTIONARY ==== */
/* 0x40003698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400036d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400037d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400038d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400039d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40003fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400040d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400041d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400042d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400043d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400044d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400045d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400046d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400047d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400048d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400049d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40004fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400050d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400051d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400052d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400053d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400054d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400055d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400056d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400057d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400058d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400059d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40005fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400060d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400061d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400062d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400063d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400064d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400065d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400066d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400067d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400068d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400069d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40006fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400070d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400071d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400072d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400073d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400074d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400075d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400076d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400077d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400078d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400079d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40007fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400080d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400081d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400082d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400083d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400084d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400085d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400086d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400087d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400088d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400089d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40008fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400090d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400091d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400092d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400093d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400094d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400095d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400096d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009798: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400097d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009818: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009858: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009898: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400098d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009918: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009958: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009998: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x400099d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009a18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009a58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009a98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ad8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009b18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009b58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009b98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009bd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009c18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009c58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009c98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009cd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009d18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009d58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009d98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009dd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009e18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009e58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009e98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009ed8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009f18: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009f58: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009f98: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x40009fd8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a018: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a058: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a098: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a0d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a118: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a158: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a198: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a1d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a218: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a258: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a298: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a2d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a318: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a358: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a398: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a3d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a418: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a458: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a498: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a4d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a518: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a558: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a598: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a5d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a618: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a658: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a698: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a6d8: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a718: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a758: */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
/* 0x4000a798: */ 0, 0, 0, 0, 0, 0, 0, 0x6573750c, 0x65724172, 0x76615361, 0x65, 
/* ==== CURRENT BOTTOM OF NAME DICTIONARY ==== */
/* 0x4000a7c4 WARM */ XT_WARM, 0x4000a7dc, 0x52415704, 0x4d,
/* 0x4000a7d4 COLD */ XT_COLD, 0x4000a7ec, 0x4c4f4304, 0x44,
/* 0x4000a7e4 'BOOT */ XT__27BOOT, 0x4000a7fc, 0x4f422705, 0x544f,
/* 0x4000a7f4 EMPTY */ XT_EMPTY, 0x4000a80c, 0x504d4505, 0x5954,
/* 0x4000a804 hi */ XT_hi, 0x4000a818, 0x696842,
/* 0x4000a810 version */ XT_version, 0x4000a828, 0x72657607, 0x6e6f6973,
/* 0x4000a820 VER */ XT_VER, 0x4000a834, 0x52455603,
/* 0x4000a82c SEE */ XT_SEE, 0x4000a840, 0x45455303,
/* 0x4000a838 >NAME */ XT__3ENAME, 0x4000a850, 0x414e3e05, 0x454d,
/* 0x4000a848 WORDS */ XT_WORDS, 0x4000a860, 0x524f5705, 0x5344,
/* 0x4000a858 .ID */ XT__2EID, 0x4000a86c, 0x44492e03,
/* 0x4000a864 ?CSP */ XT__3FCSP, 0x4000a87c, 0x53433f04, 0x50,
/* 0x4000a874 !CSP */ XT__21CSP, 0x4000a88c, 0x53432104, 0x50,
/* 0x4000a884 .FREE */ XT__2EFREE, 0x4000a89c, 0x52462e05, 0x4545,
/* 0x4000a894 .BASE */ XT__2EBASE, 0x4000a8ac, 0x41422e05, 0x4553,
/* 0x4000a8a4 UNUSED */ XT_UNUSED, 0x4000a8bc, 0x554e5506, 0x444553,
/* 0x4000a8b4 .S */ XT__2ES, 0x4000a8c8, 0x532e02,
/* 0x4000a8c0 DUMP */ XT_DUMP, 0x4000a8d8, 0x4d554404, 0x50,
/* 0x4000a8d0 dm+ */ XT_dm_2B, 0x4000a8e4, 0x2b6d6403,
/* 0x4000a8dc EVALUATE */ XT_EVALUATE, 0x4000a8f8, 0x41564508, 0x5441554c, 0x45,
/* 0x4000a8f0 quit1 */ XT_quit1, 0x4000a908, 0x69757105, 0x3174,
/* 0x4000a900 QUIT */ XT_QUIT, 0x4000a918, 0x49555104, 0x54,
/* 0x4000a910 quitError */ XT_quitError, 0x4000a92c, 0x69757109, 0x72724574, 0x726f,
/* 0x4000a924 PRESET */ XT_PRESET, 0x4000a93c, 0x45525006, 0x544553,
/* 0x4000a934 que */ XT_que, 0x4000a948, 0x65757103,
/* 0x4000a940 QUERY */ XT_QUERY, 0x4000a958, 0x45555105, 0x5952,
/* 0x4000a950 REFILL */ XT_REFILL, 0x4000a968, 0x46455206, 0x4c4c49,
/* 0x4000a960 READ-LINE */ XT_READ_2DLINE, 0x4000a97c, 0x41455209, 0x494c2d44, 0x454e,
/* 0x4000a974 sourcePop */ XT_sourcePop, 0x4000a990, 0x756f7309, 0x50656372, 0x706f,
/* 0x4000a988 RESTORE-INPUT */ XT_RESTORE_2DINPUT, 0x4000a9a8, 0x5345520d, 0x45524f54, 0x504e492d, 0x5455,
/* 0x4000a9a0 sourcePush */ XT_sourcePush, 0x4000a9bc, 0x756f730a, 0x50656372, 0x687375,
/* 0x4000a9b4 SAVE-INPUT */ XT_SAVE_2DINPUT, 0x4000a9d0, 0x5641530a, 0x4e492d45, 0x545550,
/* 0x4000a9c8 unreadFile */ XT_unreadFile, 0x4000a9e4, 0x726e750a, 0x46646165, 0x656c69,
/* 0x4000a9dc 0> */ XT_0_3E, 0x4000a9f0, 0x3e3002,
/* 0x4000a9e8 sourceStack */ XT_sourceStack, 0x4000aa04, 0x756f730b, 0x53656372, 0x6b636174,
/* 0x4000a9fc SOURCE-ID */ XT_SOURCE_2DID, 0x4000aa18, 0x554f5309, 0x2d454352, 0x4449,
/* 0x4000aa10 sempty */ XT_sempty, 0x4000aa28, 0x6d657306, 0x797470,
/* 0x4000aa20 spops */ XT_spops, 0x4000aa38, 0x6f707305, 0x7370,
/* 0x4000aa30 spushes */ XT_spushes, 0x4000aa48, 0x75707307, 0x73656873,
/* 0x4000aa40 spush */ XT_spush, 0x4000aa58, 0x75707305, 0x6873,
/* 0x4000aa50 spop */ XT_spop, 0x4000aa68, 0x6f707304, 0x70,
/* 0x4000aa60 stack */ XT_stack, 0x4000aa78, 0x61747305, 0x6b63,
/* 0x4000aa70 ACCEPT */ XT_ACCEPT, 0x4000aa88, 0x43434106, 0x545045,
/* 0x4000aa80 (charbase) */ XT__28charbase_29, 0x4000aa9c, 0x6863280a, 0x61627261, 0x296573,
/* 0x4000aa94 >NUMBER */ XT__3ENUMBER, 0x4000aaac, 0x554e3e07, 0x5245424d,
/* 0x4000aaa4 accumulate */ XT_accumulate, 0x4000aac0, 0x6363610a, 0x6c756d75, 0x657461,
/* 0x4000aab8 J-MAX */ XT_J_2DMAX, 0x4000aad0, 0x4d2d4a05, 0x5841,
/* 0x4000aac8 J */ XT_J, 0x4000aadc, 0x4a01,
/* 0x4000aad4 I-MAX */ XT_I_2DMAX, 0x4000aaec, 0x4d2d4905, 0x5841,
/* 0x4000aae4 +LOOP */ XT__2BLOOP, 0x4000aafc, 0x4f4c2b85, 0x504f,
/* 0x4000aaf4 LOOP */ XT_LOOP, 0x4000ab0c, 0x4f4f4c84, 0x50,
/* 0x4000ab04 some-loop */ XT_some_2Dloop, 0x4000ab20, 0x6d6f7309, 0x6f6c2d65, 0x706f,
/* 0x4000ab18 ?DO */ XT__3FDO, 0x4000ab2c, 0x4f443f83,
/* 0x4000ab24 DO */ XT_DO, 0x4000ab38, 0x4f4482,
/* 0x4000ab30 UNLOOP */ XT_UNLOOP, 0x4000ab48, 0x4c4e5586, 0x504f4f,
/* 0x4000ab40 LEAVE */ XT_LEAVE, 0x4000ab58, 0x41454c85, 0x4556,
/* 0x4000ab50 leave, */ XT_leave_2C, 0x4000ab68, 0x61656c06, 0x2c6576,
/* 0x4000ab60 (+loop) */ XT__28_2Bloop_29, 0x4000ab78, 0x6c2b2807, 0x29706f6f,
/* 0x4000ab70 (loop) */ XT__28loop_29, 0x4000ab88, 0x6f6c2806, 0x29706f,
/* 0x4000ab80 (?do) */ XT__28_3Fdo_29, 0x4000ab98, 0x643f2805, 0x296f,
/* 0x4000ab90 leave-ptr */ XT_leave_2Dptr, 0x4000abac, 0x61656c09, 0x702d6576, 0x7274,
/* 0x4000aba4 CONSTANT */ XT_CONSTANT, 0x4000abc0, 0x4e4f4308, 0x4e415453, 0x54,
/* 0x4000abb8 VARIABLE */ XT_VARIABLE, 0x4000abd4, 0x52415608, 0x4c424149, 0x45,
/* 0x4000abcc TO */ XT_TO, 0x4000abe0, 0x4f5482,
/* 0x4000abd8 VALUE */ XT_VALUE, 0x4000abf0, 0x4c415605, 0x4555,
/* 0x4000abe8  */ 0x40002748, 0x4000abfc, 0xc0,
/* 0x4000abf4  */ 0x400026f0, 0x4000ac08, 0,
/* 0x4000ac00 EVAL */ XT_EVAL, 0x4000ac18, 0x41564504, 0x4c,
/* 0x4000ac10  */ 0x40002644, 0x4000ac24, 0,
/* 0x4000ac1c  */ 0x40002610, 0x4000ac30, 0,
/* 0x4000ac28 ?UNIQUE */ XT__3FUNIQUE, 0x4000ac40, 0x4e553f07, 0x45555149,
/* 0x4000ac38 RECURSE */ XT_RECURSE, 0x4000ac50, 0x43455287, 0x45535255,
/* 0x4000ac48 ACTION-OF */ XT_ACTION_2DOF, 0x4000ac64, 0x54434189, 0x2d4e4f49, 0x464f,
/* 0x4000ac5c IS */ XT_IS, 0x4000ac70, 0x534982,
/* 0x4000ac68 '>BODY! */ XT__27_3EBODY_21, 0x4000ac80, 0x423e2707, 0x2159444f,
/* 0x4000ac78 BUFFER: */ XT_BUFFER_3A, 0x4000ac90, 0x46554207, 0x3a524546,
/* 0x4000ac88 vALLOT */ XT_vALLOT, 0x4000aca0, 0x4c417606, 0x544f4c,
/* 0x4000ac98 ALLOT */ XT_ALLOT, 0x4000acb0, 0x4c4c4105, 0x544f,
/* 0x4000aca8  */ 0x400024e8, 0x4000acbc, 0,
/* 0x4000acb4 CONSOLE */ XT_CONSOLE, 0x4000accc, 0x4e4f4307, 0x454c4f53,
/* 0x4000acc4 I/O */ XT_I_2FO, 0x4000acd8, 0x4f2f4903,
/* 0x4000acd0 HAND */ XT_HAND, 0x4000ace8, 0x4e414804, 0x44,
/* 0x4000ace0 FILE */ XT_FILE, 0x4000acf8, 0x4c494604, 0x45,
/* 0x4000acf0 XIO */ XT_XIO, 0x4000ad04, 0x4f495803,
/* 0x4000acfc  */ 0x40002440, 0x4000ad10, 0x80,
/* 0x4000ad08 ?STACK */ XT__3FSTACK, 0x4000ad20, 0x54533f06, 0x4b4341,
/* 0x4000ad18 .OK */ XT__2EOK, 0x4000ad2c, 0x4b4f2e03,
/* 0x4000ad24  */ 0x400023a0, 0x4000ad38, 0,
/* 0x4000ad30 POSTPONE */ XT_POSTPONE, 0x4000ad4c, 0x534f5088, 0x4e4f5054, 0x45,
/* 0x4000ad44 ABORT" */ XT_ABORT_22, 0x4000ad5c, 0x4f424186, 0x225452,
/* 0x4000ad54 (abort") */ XT__28abort_22_29, 0x4000ad70, 0x62612848, 0x2274726f, 0x29,
/* 0x4000ad68 ABORT */ XT_ABORT, 0x4000ad80, 0x4f424105, 0x5452,
/* 0x4000ad78 NULL$ */ XT_NULL_24, 0x4000ad90, 0x4c554e05, 0x244c,
/* 0x4000ad88 S\" */ XT_S_5C_22, 0x4000ad9c, 0x225c5383,
/* 0x4000ad94 pack\$ */ XT_pack_5C_24, 0x4000adac, 0x63617006, 0x245c6b,
/* 0x4000ada4 cmove\ */ XT_cmove_5C, 0x4000adbc, 0x6f6d6306, 0x5c6576,
/* 0x4000adb4 c+! */ XT_c_2B_21, 0x4000adc8, 0x212b6303,
/* 0x4000adc0 bu+@ */ XT_bu_2B_40, 0x4000add8, 0x2b756204, 0x40,
/* 0x4000add0 S" */ XT_S_22, 0x4000ade4, 0x225382,
/* 0x4000addc ." */ XT__2E_22, 0x4000adf0, 0x222e82,
/* 0x4000ade8 C" */ XT_C_22, 0x4000adfc, 0x224382,
/* 0x4000adf4 $" */ XT__24_22, 0x4000ae08, 0x222482,
/* 0x4000ae00 S"| */ XT_S_22_7C, 0x4000ae14, 0x7c225303,
/* 0x4000ae0c ."| */ XT__2E_22_7C, 0x4000ae20, 0x7c222e03,
/* 0x4000ae18 $"| */ XT__24_22_7C, 0x4000ae2c, 0x7c222403,
/* 0x4000ae24 $," */ XT__24_2C_22, 0x4000ae38, 0x222c2403,
/* 0x4000ae30 do$ */ XT_do_24, 0x4000ae44, 0x246f6403,
/* 0x4000ae3c kTAP */ XT_kTAP, 0x4000ae54, 0x41546b04, 0x50,
/* 0x4000ae4c skipToCRLF */ XT_skipToCRLF, 0x4000ae68, 0x696b730a, 0x436f5470, 0x464c52,
/* 0x4000ae60 skipCRLF */ XT_skipCRLF, 0x4000ae7c, 0x696b7308, 0x4c524370, 0x46,
/* 0x4000ae74 crlf? */ XT_crlf_3F, 0x4000ae8c, 0x6c726305, 0x3f66,
/* 0x4000ae84 TAP */ XT_TAP, 0x4000ae98, 0x50415403,
/* 0x4000ae90 ^H */ XT__5EH, 0x4000aea4, 0x485e02,
/* 0x4000ae9c THROW */ XT_THROW, 0x4000aeb4, 0x52485405, 0x574f,
/* 0x4000aeac CATCH */ XT_CATCH, 0x4000aec4, 0x54414305, 0x4843,
/* 0x4000aebc MARKER */ XT_MARKER, 0x4000aed4, 0x52414d06, 0x52454b,
/* 0x4000aecc FIND */ XT_FIND, 0x4000aee4, 0x4e494604, 0x44,
/* 0x4000aedc NAME? */ XT_NAME_3F, 0x4000aef4, 0x4d414e05, 0x3f45,
/* 0x4000aeec FIND-NAME */ XT_FIND_2DNAME, 0x4000af08, 0x4e494609, 0x414e2d44, 0x454d,
/* 0x4000af00 SAME? */ XT_SAME_3F, 0x4000af18, 0x4d415305, 0x3f45,
/* 0x4000af10 NAME>INTERPRET */ XT_NAME_3EINTERPRET, 0x4000af30, 0x4d414e0e, 0x4e493e45, 0x50524554, 0x544552,
/* 0x4000af28 WORD */ XT_WORD, 0x4000af40, 0x524f5704, 0x44,
/* 0x4000af38  */ 0x400018e4, 0x4000af4c, 0,
/* 0x4000af44 .( */ XT__2E_28, 0x4000af58, 0x282e82,
/* 0x4000af50 CTRL */ XT_CTRL, 0x4000af68, 0x52544304, 0x4c,
/* 0x4000af60 [CHAR] */ XT__5BCHAR_5D, 0x4000af78, 0x48435b86, 0x5d5241,
/* 0x4000af70 CHAR */ XT_CHAR, 0x4000af88, 0x41484304, 0x52,
/* 0x4000af80 PARSE-NAME */ XT_PARSE_2DNAME, 0x4000af9c, 0x5241500a, 0x4e2d4553, 0x454d41,
/* 0x4000af94  */ 0x400017d0, 0x4000afa8, 0,
/* 0x4000afa0 skip-till */ XT_skip_2Dtill, 0x4000afbc, 0x696b7309, 0x69742d70, 0x6c6c,
/* 0x4000afb4 xt-skip */ XT_xt_2Dskip, 0x4000afcc, 0x2d747807, 0x70696b73,
/* 0x4000afc4 isnotspace? */ XT_isnotspace_3F, 0x4000afe0, 0x6e73690b, 0x7073746f, 0x3f656361,
/* 0x4000afd8 isspace? */ XT_isspace_3F, 0x4000aff4, 0x73736908, 0x65636170, 0x3f,
/* 0x4000afec /STRING */ XT__2FSTRING, 0x4000b004, 0x54532f07, 0x474e4952,
/* 0x4000affc SOURCE */ XT_SOURCE, 0x4000b014, 0x554f5306, 0x454352,
/* 0x4000b00c ['] */ XT__5B_27_5D, 0x4000b020, 0x5d275b83,
/* 0x4000b018 CR */ XT_CR, 0x4000b02c, 0x524302,
/* 0x4000b024 PACE */ XT_PACE, 0x4000b03c, 0x43415004, 0x45,
/* 0x4000b034 NUF? */ XT_NUF_3F, 0x4000b04c, 0x46554e04, 0x3f,
/* 0x4000b044 KEY */ XT_KEY, 0x4000b058, 0x59454b03,
/* 0x4000b050 ?KEY */ XT__3FKEY, 0x4000b068, 0x454b3f04, 0x59,
/* 0x4000b060 DIGIT? */ XT_DIGIT_3F, 0x4000b078, 0x47494406, 0x3f5449,
/* 0x4000b070 ? */ XT__3F, 0x4000b084, 0x3f01,
/* 0x4000b07c . */ XT__2E, 0x4000b090, 0x2e01,
/* 0x4000b088 U. */ XT_U_2E, 0x4000b09c, 0x2e5502,
/* 0x4000b094 U.R */ XT_U_2ER, 0x4000b0a8, 0x522e5503,
/* 0x4000b0a0 .R */ XT__2ER, 0x4000b0b4, 0x522e02,
/* 0x4000b0ac DECIMAL */ XT_DECIMAL, 0x4000b0c4, 0x43454407, 0x4c414d49,
/* 0x4000b0bc HEX */ XT_HEX, 0x4000b0d0, 0x58454803,
/* 0x4000b0c8 str */ XT_str, 0x4000b0dc, 0x72747303,
/* 0x4000b0d4 .$ */ XT__2E_24, 0x4000b0e8, 0x242e02,
/* 0x4000b0e0 SPACES */ XT_SPACES, 0x4000b0f8, 0x41505306, 0x534543,
/* 0x4000b0f0 emits */ XT_emits, 0x4000b108, 0x696d6505, 0x7374,
/* 0x4000b100 SPACE */ XT_SPACE, 0x4000b118, 0x41505305, 0x4543,
/* 0x4000b110 EMIT */ XT_EMIT, 0x4000b128, 0x494d4504, 0x54,
/* 0x4000b120 #> */ XT__23_3E, 0x4000b134, 0x3e2302,
/* 0x4000b12c SIGN */ XT_SIGN, 0x4000b144, 0x47495304, 0x4e,
/* 0x4000b13c #S */ XT__23S, 0x4000b150, 0x532302,
/* 0x4000b148 # */ XT__23, 0x4000b15c, 0x2301,
/* 0x4000b154 HOLDS */ XT_HOLDS, 0x4000b16c, 0x4c4f4805, 0x5344,
/* 0x4000b164 HOLD */ XT_HOLD, 0x4000b17c, 0x4c4f4804, 0x44,
/* 0x4000b174 <# */ XT__3C_23, 0x4000b188, 0x233c02,
/* 0x4000b180 EXTRACT */ XT_EXTRACT, 0x4000b198, 0x54584507, 0x54434152,
/* 0x4000b190 DIGIT */ XT_DIGIT, 0x4000b1a8, 0x47494405, 0x5449,
/* 0x4000b1a0 PACK$ */ XT_PACK_24, 0x4000b1b8, 0x43415005, 0x244b,
/* 0x4000b1b0 -TRAILING */ XT__2DTRAILING, 0x4000b1cc, 0x52542d09, 0x494c4941, 0x474e,
/* 0x4000b1c4 ERASE */ XT_ERASE, 0x4000b1dc, 0x41524505, 0x4553,
/* 0x4000b1d4 FILL */ XT_FILL, 0x4000b1ec, 0x4c494604, 0x4c,
/* 0x4000b1e4 MOVE */ XT_MOVE, 0x4000b1fc, 0x564f4d04, 0x45,
/* 0x4000b1f4 CMOVE> */ XT_CMOVE_3E, 0x4000b20c, 0x4f4d4306, 0x3e4556,
/* 0x4000b204 CMOVE */ XT_CMOVE, 0x4000b21c, 0x4f4d4305, 0x4556,
/* 0x4000b214 COUNT */ XT_COUNT, 0x4000b22c, 0x554f4305, 0x544e,
/* 0x4000b224 @EXECUTE */ XT__40EXECUTE, 0x4000b240, 0x58454008, 0x54554345, 0x45,
/* 0x4000b238 TIB */ XT_TIB, 0x4000b24c, 0x42495403,
/* 0x4000b244 PAD */ XT_PAD, 0x4000b258, 0x44415003,
/* 0x4000b250 vCREATE */ XT_vCREATE, 0x4000b268, 0x52437607, 0x45544145,
/* 0x4000b260 vALIGN */ XT_vALIGN, 0x4000b278, 0x4c417606, 0x4e4749,
/* 0x4000b270 v, */ XT_v_2C, 0x4000b284, 0x2c7602,
/* 0x4000b27c vHERE */ XT_vHERE, 0x4000b294, 0x45487605, 0x4552,
/* 0x4000b28c 2@ */ XT_2_40, 0x4000b2a0, 0x403202,
/* 0x4000b298 2! */ XT_2_21, 0x4000b2ac, 0x213202,
/* 0x4000b2a4 -- */ XT__2D_2D, 0x4000b2b8, 0x2d2d02,
/* 0x4000b2b0 ++ */ XT__2B_2B, 0x4000b2c4, 0x2b2b02,
/* 0x4000b2bc +! */ XT__2B_21, 0x4000b2d0, 0x212b02,
/* 0x4000b2c8 PICK */ XT_PICK, 0x4000b2e0, 0x43495004, 0x4b,
/* 0x4000b2d8  */ 0x40000f0c, 0x4000b2ec, 0,
/* 0x4000b2e4 >CHAR */ XT__3ECHAR, 0x4000b2fc, 0x48433e05, 0x5241,
/* 0x4000b2f4 DEFER! */ XT_DEFER_21, 0x4000b30c, 0x46454406, 0x215245,
/* 0x4000b304 >BODY! */ XT__3EBODY_21, 0x4000b31c, 0x4f423e06, 0x215944,
/* 0x4000b314 DEFER@ */ XT_DEFER_40, 0x4000b32c, 0x46454406, 0x405245,
/* 0x4000b324 :NONAME */ XT__3ANONAME, 0x4000b33c, 0x4f4e3a07, 0x454d414e,
/* 0x4000b334 ($,n) */ XT__28_24_2Cn_29, 0x4000b34c, 0x2c242805, 0x296e,
/* 0x4000b344 2* */ XT_2_2A, 0x4000b358, 0x2a3202,
/* 0x4000b350 CHARS */ XT_CHARS, 0x4000b368, 0x41484305, 0x5352,
/* 0x4000b360 CELLS */ XT_CELLS, 0x4000b378, 0x4c454305, 0x534c,
/* 0x4000b370 CELL- */ XT_CELL_2D, 0x4000b388, 0x4c454305, 0x2d4c,
/* 0x4000b380 SM/REM */ XT_SM_2FREM, 0x4000b398, 0x2f4d5306, 0x4d4552,
/* 0x4000b390 DABS */ XT_DABS, 0x4000b3a8, 0x42414404, 0x53,
/* 0x4000b3a0 D0< */ XT_D0_3C, 0x4000b3b4, 0x3c304403,
/* 0x4000b3ac * / */ XT__2A_2F, 0x4000b3c0, 0x2f2a02,
/* 0x4000b3b8 * /MOD */ XT__2A_2FMOD, 0x4000b3d0, 0x4d2f2a05, 0x444f,
/* 0x4000b3c8 M* */ XT_M_2A, 0x4000b3dc, 0x2a4d02,
/* 0x4000b3d4 * */ XT__2A, 0x4000b3e8, 0x2a01,
/* 0x4000b3e0 UM* */ XT_UM_2A, 0x4000b3f4, 0x2a4d5503,
/* 0x4000b3ec / */ XT__2F, 0x4000b400, 0x2f01,
/* 0x4000b3f8 MOD */ XT_MOD, 0x4000b40c, 0x444f4d03,
/* 0x4000b404 /MOD */ XT__2FMOD, 0x4000b41c, 0x4f4d2f04, 0x44,
/* 0x4000b414 FM/MOD */ XT_FM_2FMOD, 0x4000b42c, 0x2f4d4606, 0x444f4d,
/* 0x4000b424 M/MOD */ XT_M_2FMOD, 0x4000b43c, 0x4d2f4d05, 0x444f,
/* 0x4000b434 UM/MOD */ XT_UM_2FMOD, 0x4000b44c, 0x2f4d5506, 0x444f4d,
/* 0x4000b444 S>D */ XT_S_3ED, 0x4000b458, 0x443e5303,
/* 0x4000b450 WITHIN */ XT_WITHIN, 0x4000b468, 0x54495706, 0x4e4948,
/* 0x4000b460 MIN */ XT_MIN, 0x4000b474, 0x4e494d03,
/* 0x4000b46c MAX */ XT_MAX, 0x4000b480, 0x58414d03,
/* 0x4000b478 > */ XT__3E, 0x4000b48c, 0x3e01,
/* 0x4000b484 < */ XT__3C, 0x4000b498, 0x3c01,
/* 0x4000b490 ud< */ XT_ud_3C, 0x4000b4a4, 0x3c647503,
/* 0x4000b49c U> */ XT_U_3E, 0x4000b4b0, 0x3e5502,
/* 0x4000b4a8 U< */ XT_U_3C, 0x4000b4bc, 0x3c5502,
/* 0x4000b4b4 <> */ XT__3C_3E, 0x4000b4c8, 0x3e3c02,
/* 0x4000b4c0 = */ XT__3D, 0x4000b4d4, 0x3d01,
/* 0x4000b4cc C, */ XT_C_2C, 0x4000b4e0, 0x2c4302,
/* 0x4000b4d8 CHAR+ */ XT_CHAR_2B, 0x4000b4f0, 0x41484305, 0x2b52,
/* 0x4000b4e8 ABS */ XT_ABS, 0x4000b4fc, 0x53424103,
/* 0x4000b4f4 ?negate */ XT__3Fnegate, 0x4000b50c, 0x656e3f07, 0x65746167,
/* 0x4000b504 1- */ XT_1_2D, 0x4000b518, 0x2d3102,
/* 0x4000b510 - */ XT__2D, 0x4000b524, 0x2d01,
/* 0x4000b51c DNEGATE */ XT_DNEGATE, 0x4000b534, 0x454e4407, 0x45544147,
/* 0x4000b52c NEGATE */ XT_NEGATE, 0x4000b544, 0x47454e06, 0x455441,
/* 0x4000b53c 1+ */ XT_1_2B, 0x4000b550, 0x2b3102,
/* 0x4000b548 INVERT */ XT_INVERT, 0x4000b560, 0x564e4906, 0x545245,
/* 0x4000b558 D+ */ XT_D_2B, 0x4000b56c, 0x2b4402,
/* 0x4000b564 2SWAP */ XT_2SWAP, 0x4000b57c, 0x57533205, 0x5041,
/* 0x4000b574 2OVER */ XT_2OVER, 0x4000b58c, 0x564f3205, 0x5245,
/* 0x4000b584 2DUP */ XT_2DUP, 0x4000b59c, 0x55443204, 0x50,
/* 0x4000b594 -ROT */ XT__2DROT, 0x4000b5ac, 0x4f522d04, 0x54,
/* 0x4000b5a4 ?test\ */ XT__3Ftest_5C, 0x4000b5bc, 0x65743f86, 0x5c7473,
/* 0x4000b5b4 ?safe\ */ XT__3Fsafe_5C, 0x4000b5cc, 0x61733f86, 0x5c6566,
/* 0x4000b5c4 ?\ */ XT__3F_5C, 0x4000b5d8, 0x5c3f82,
/* 0x4000b5d0 D0= */ XT_D0_3D, 0x4000b5e4, 0x3d304403,
/* 0x4000b5dc 0<> */ XT_0_3C_3E, 0x4000b5f0, 0x3e3c3003,
/* 0x4000b5e8 0= */ XT_0_3D, 0x4000b5fc, 0x3d3002,
/* 0x4000b5f4 ENDCASE */ XT_ENDCASE, 0x4000b60c, 0x444e4587, 0x45534143,
/* 0x4000b604 ENDOF */ XT_ENDOF, 0x4000b61c, 0x444e4585, 0x464f,
/* 0x4000b614 OF */ XT_OF, 0x4000b628, 0x464f82,
/* 0x4000b620 CASE */ XT_CASE, 0x4000b638, 0x53414384, 0x45,
/* 0x4000b630 >RESOLVETHREAD */ XT__3ERESOLVETHREAD, 0x4000b650, 0x45523e0e, 0x564c4f53, 0x52485445, 0x444145,
/* 0x4000b648 >MARKTHREAD */ XT__3EMARKTHREAD, 0x4000b664, 0x414d3e0b, 0x48544b52, 0x44414552,
/* 0x4000b65c >MARKSTART */ XT__3EMARKSTART, 0x4000b678, 0x414d3e0a, 0x54534b52, 0x545241,
/* 0x4000b670 >RESOLVES */ XT__3ERESOLVES, 0x4000b68c, 0x45523e09, 0x564c4f53, 0x5345,
/* 0x4000b684 ?DUP */ XT__3FDUP, 0x4000b69c, 0x55443f04, 0x50,
/* 0x4000b694 WHILE */ XT_WHILE, 0x4000b6ac, 0x49485785, 0x454c,
/* 0x4000b6a4 WHEN */ XT_WHEN, 0x4000b6bc, 0x45485784, 0x4e,
/* 0x4000b6b4 ELSE */ XT_ELSE, 0x4000b6cc, 0x534c4584, 0x45,
/* 0x4000b6c4 AFT */ XT_AFT, 0x4000b6d8, 0x54464183,
/* 0x4000b6d0 THEN */ XT_THEN, 0x4000b6e8, 0x45485484, 0x4e,
/* 0x4000b6e0 REPEAT */ XT_REPEAT, 0x4000b6f8, 0x50455286, 0x544145,
/* 0x4000b6f0 AHEAD */ XT_AHEAD, 0x4000b708, 0x45484185, 0x4441,
/* 0x4000b700 IF */ XT_IF, 0x4000b714, 0x464982,
/* 0x4000b70c AGAIN */ XT_AGAIN, 0x4000b724, 0x41474185, 0x4e49,
/* 0x4000b71c UNTIL */ XT_UNTIL, 0x4000b734, 0x544e5585, 0x4c49,
/* 0x4000b72c NEXT */ XT_NEXT, 0x4000b744, 0x58454e84, 0x54,
/* 0x4000b73c BEGIN */ XT_BEGIN, 0x4000b754, 0x47454285, 0x4e49,
/* 0x4000b74c FOR */ XT_FOR, 0x4000b760, 0x524f4683,
/* 0x4000b758 >RESOLVE */ XT__3ERESOLVE, 0x4000b774, 0x45523e08, 0x564c4f53, 0x45,
/* 0x4000b76c >MARK */ XT__3EMARK, 0x4000b784, 0x414d3e05, 0x4b52,
/* 0x4000b77c <RESOLVE */ XT__3CRESOLVE, 0x4000b798, 0x45523c08, 0x564c4f53, 0x45,
/* 0x4000b790 <MARK */ XT__3CMARK, 0x4000b7a8, 0x414d3c05, 0x4b52,
/* 0x4000b7a0 CREATE */ XT_CREATE, 0x4000b7b8, 0x45524306, 0x455441,
/* 0x4000b7b0 create */ XT_create, 0x4000b7c8, 0x65726306, 0x657461,
/* 0x4000b7c0 LITERAL */ XT_LITERAL, 0x4000b7d8, 0x54494c87, 0x4c415245,
/* 0x4000b7d0 COMPILE */ XT_COMPILE, 0x4000b7e8, 0x4d4f4347, 0x454c4950,
/* 0x4000b7e0 [COMPILE] */ XT__5BCOMPILE_5D, 0x4000b7fc, 0x4f435b89, 0x4c49504d, 0x5d45,
/* 0x4000b7f4 COMPILE, */ XT_COMPILE_2C, 0x4000b810, 0x4d4f4308, 0x454c4950, 0x2c,
/* 0x4000b808 , */ XT__2C, 0x4000b81c, 0x2c01,
/* 0x4000b814 CELL+ */ XT_CELL_2B, 0x4000b82c, 0x4c454305, 0x2b4c,
/* 0x4000b824 + */ XT__2B, 0x4000b838, 0x2b01,
/* 0x4000b830 HERE */ XT_HERE, 0x4000b848, 0x52454804, 0x45,
/* 0x4000b840 TUCK */ XT_TUCK, 0x4000b858, 0x43555404, 0x4b,
/* 0x4000b850 NIP */ XT_NIP, 0x4000b864, 0x50494e03,
/* 0x4000b85c \ */ XT__5C, 0x4000b870, 0x5c81,
/* 0x4000b868 IMMEDIATE */ XT_IMMEDIATE, 0x4000b884, 0x4d4d4909, 0x41494445, 0x4554,
/* 0x4000b87c COMPILE-ONLY */ XT_COMPILE_2DONLY, 0x4000b89c, 0x4d4f430c, 0x454c4950, 0x4c4e4f2d, 0x59,
/* 0x4000b894 setHeaderBits */ XT_setHeaderBits, 0x4000b8b4, 0x7465730d, 0x64616548, 0x69427265, 0x7374,
/* 0x4000b8ac 2DROP */ XT_2DROP, 0x4000b8c4, 0x52443205, 0x504f,
/* 0x4000b8bc testDepth */ XT_testDepth, 0x4000b8d8, 0x73657409, 0x70654474, 0x6874,
/* 0x4000b8d0 testFlags */ XT_testFlags, 0x4000b8ec, 0x73657409, 0x616c4674, 0x7367,
/* 0x4000b8e4 source-id */ XT_source_2Did, 0x4000b900, 0x756f7309, 0x2d656372, 0x6469,
/* 0x4000b8f8 VP */ XT_VP, 0x4000b90c, 0x505602,
/* 0x4000b904 LAST */ XT_LAST, 0x4000b91c, 0x53414c04, 0x54,
/* 0x4000b914 NP */ XT_NP, 0x4000b928, 0x504e02,
/* 0x4000b920 CP */ XT_CP, 0x4000b934, 0x504302,
/* 0x4000b92c CURRENT */ XT_CURRENT, 0x4000b944, 0x52554307, 0x544e4552,
/* 0x4000b93c CONTEXT */ XT_CONTEXT, 0x4000b954, 0x4e4f4307, 0x54584554,
/* 0x4000b94c HANDLER */ XT_HANDLER, 0x4000b964, 0x4e414807, 0x52454c44,
/* 0x4000b95c HLD */ XT_HLD, 0x4000b970, 0x444c4803,
/* 0x4000b968 SPARE2 */ XT_SPARE2, 0x4000b980, 0x41505306, 0x324552,
/* 0x4000b978 STATE */ XT_STATE, 0x4000b990, 0x41545305, 0x4554,
/* 0x4000b988 CSP */ XT_CSP, 0x4000b99c, 0x50534303,
/* 0x4000b994 #TIB */ XT__23TIB, 0x4000b9ac, 0x49542304, 0x42,
/* 0x4000b9a4 >IN */ XT__3EIN, 0x4000b9b8, 0x4e493e03,
/* 0x4000b9b0 SPAN */ XT_SPAN, 0x4000b9c8, 0x41505304, 0x4e,
/* 0x4000b9c0 temp */ XT_temp, 0x4000b9d8, 0x6d657404, 0x70,
/* 0x4000b9d0 BASE */ XT_BASE, 0x4000b9e8, 0x53414204, 0x45,
/* 0x4000b9e0 'PROMPT */ XT__27PROMPT, 0x4000b9f8, 0x52502707, 0x54504d4f,
/* 0x4000b9f0 'ECHO */ XT__27ECHO, 0x4000ba08, 0x43452705, 0x4f48,
/* 0x4000ba00 'TAP */ XT__27TAP, 0x4000ba18, 0x41542704, 0x50,
/* 0x4000ba10 SPARE */ XT_SPARE, 0x4000ba28, 0x41505305, 0x4552,
/* 0x4000ba20 'EMIT */ XT__27EMIT, 0x4000ba38, 0x4d452705, 0x5449,
/* 0x4000ba30 '?KEY */ XT__27_3FKEY, 0x4000ba48, 0x4b3f2705, 0x5945,
/* 0x4000ba40 RP0 */ XT_RP0, 0x4000ba54, 0x30505203,
/* 0x4000ba4c SP0 */ XT_SP0, 0x4000ba60, 0x30505303,
/* 0x4000ba58 _USER */ XT__5FUSER, 0x4000ba70, 0x53555f05, 0x5245,
/* 0x4000ba68 -> */ XT__2D_3E, 0x4000ba7c, 0x3e2d02,
/* 0x4000ba74 }T */ XT__7DT, 0x4000ba88, 0x547d02,
/* 0x4000ba80 DEPTH */ XT_DEPTH, 0x4000ba98, 0x50454405, 0x4854,
/* 0x4000ba90 T{ */ XT_T_7B, 0x4000baa4, 0x7b5402,
/* 0x4000ba9c (of) */ XT__28of_29, 0x4000bab4, 0x666f2804, 0x29,
/* 0x4000baac DEFER */ XT_DEFER, 0x4000bac4, 0x46454405, 0x5245,
/* 0x4000babc >BODY */ XT__3EBODY, 0x4000bad4, 0x4f423e05, 0x5944,
/* 0x4000bacc ALIGN */ XT_ALIGN, 0x4000bae4, 0x494c4105, 0x4e47,
/* 0x4000badc immediate? */ XT_immediate_3F, 0x4000baf8, 0x6d6d690a, 0x61696465, 0x3f6574,
/* 0x4000baf0 2RDrop */ XT_2RDrop, 0x4000bb08, 0x44523206, 0x706f72,
/* 0x4000bb00 RDrop */ XT_RDrop, 0x4000bb18, 0x72445205, 0x706f,
/* 0x4000bb10 I */ XT_I, 0x4000bb24, 0x4901,
/* 0x4000bb1c TYPE */ XT_TYPE, 0x4000bb34, 0x50595404, 0x45,
/* 0x4000bb2c stringBuffer */ XT_stringBuffer, 0x4000bb4c, 0x7274730c, 0x42676e69, 0x65666675, 0x72,
/* 0x4000bb44 Fbreak */ XT_Fbreak, 0x4000bb5c, 0x72624606, 0x6b6165,
/* 0x4000bb54 debugNA */ XT_debugNA, 0x4000bb6c, 0x62656407, 0x414e6775,
/* 0x4000bb64 ' */ XT__27, 0x4000bb78, 0x2701,
/* 0x4000bb70 ; */ XT__3B, 0x4000bb84, 0x3b81,
/* 0x4000bb7c : */ XT__3A, 0x4000bb90, 0x3a01,
/* 0x4000bb88 ] */ XT__5D, 0x4000bb9c, 0x5d01,
/* 0x4000bb94 [ */ XT__5B, 0x4000bba8, 0x5b81,
/* 0x4000bba0 $INTERPRET */ XT__24INTERPRET, 0x4000bbbc, 0x4e49240a, 0x50524554, 0x544552,
/* 0x4000bbb4 $COMPILE */ XT__24COMPILE, 0x4000bbd0, 0x4f432408, 0x4c49504d, 0x45,
/* 0x4000bbc8 NUMBER? */ XT_NUMBER_3F, 0x4000bbe0, 0x4d554e07, 0x3f524542,
/* 0x4000bbd8 TOKEN */ XT_TOKEN, 0x4000bbf0, 0x4b4f5405, 0x4e45,
/* 0x4000bbe8 ( */ XT__28, 0x4000bbfc, 0x2881,
/* 0x4000bbf4 PARSE */ XT_PARSE, 0x4000bc0c, 0x52415005, 0x4553,
/* 0x4000bc04 userAreaSave */ XT_userAreaSave, 0x4000bc24, 0x6573750c, 0x65724172, 0x76615361, 0x65,
/* 0x4000bc1c userAreaInit */ XT_userAreaInit, 0x4000bc3c, 0x6573750c, 0x65724172, 0x696e4961, 0x74,
/* 0x4000bc34 2/ */ XT_2_2F, 0x4000bc48, 0x2f3202,
/* 0x4000bc40 LSHIFT */ XT_LSHIFT, 0x4000bc58, 0x48534c06, 0x544649,
/* 0x4000bc50 RSHIFT */ XT_RSHIFT, 0x4000bc68, 0x48535206, 0x544649,
/* 0x4000bc60 UM+ */ XT_UM_2B, 0x4000bc74, 0x2b4d5503,
/* 0x4000bc6c XOR */ XT_XOR, 0x4000bc80, 0x524f5803,
/* 0x4000bc78 OR */ XT_OR, 0x4000bc8c, 0x524f02,
/* 0x4000bc84 AND */ XT_AND, 0x4000bc98, 0x444e4103,
/* 0x4000bc90 0< */ XT_0_3C, 0x4000bca4, 0x3c3002,
/* 0x4000bc9c ROT */ XT_ROT, 0x4000bcb0, 0x544f5203,
/* 0x4000bca8 ROLL */ XT_ROLL, 0x4000bcc0, 0x4c4f5204, 0x4c,
/* 0x4000bcb8 OVER */ XT_OVER, 0x4000bcd0, 0x45564f04, 0x52,
/* 0x4000bcc8 SWAP */ XT_SWAP, 0x4000bce0, 0x41575304, 0x50,
/* 0x4000bcd8 DUP */ XT_DUP, 0x4000bcec, 0x50554403,
/* 0x4000bce4 DROP */ XT_DROP, 0x4000bcfc, 0x4f524404, 0x50,
/* 0x4000bcf4 SP! */ XT_SP_21, 0x4000bd08, 0x21505303,
/* 0x4000bd00 SP@ */ XT_SP_40, 0x4000bd14, 0x40505303,
/* 0x4000bd0c 2>R */ XT_2_3ER, 0x4000bd20, 0x523e3203,
/* 0x4000bd18 2R@ */ XT_2R_40, 0x4000bd2c, 0x40523203,
/* 0x4000bd24 2R> */ XT_2R_3E, 0x4000bd38, 0x3e523203,
/* 0x4000bd30 >R */ XT__3ER, 0x4000bd44, 0x523e02,
/* 0x4000bd3c R@ */ XT_R_40, 0x4000bd50, 0x405202,
/* 0x4000bd48 R> */ XT_R_3E, 0x4000bd5c, 0x3e5202,
/* 0x4000bd54 RP! */ XT_RP_21, 0x4000bd68, 0x21505203,
/* 0x4000bd60 RP@ */ XT_RP_40, 0x4000bd74, 0x40505203,
/* 0x4000bd6c C! */ XT_C_21, 0x4000bd80, 0x214302,
/* 0x4000bd78 C@ */ XT_C_40, 0x4000bd8c, 0x404302,
/* 0x4000bd84 @ */ XT__40, 0x4000bd98, 0x4001,
/* 0x4000bd90 ! */ XT__21, 0x4000bda4, 0x2101,
/* 0x4000bd9c branch */ XT_branch, 0x4000bdb4, 0x61726206, 0x68636e,
/* 0x4000bdac ?branch */ XT__3Fbranch, 0x4000bdc4, 0x72623f07, 0x68636e61,
/* 0x4000bdbc (next) */ XT__28next_29, 0x4000bdd4, 0x656e2806, 0x297478,
/* 0x4000bdcc DOES> */ XT_DOES_3E, 0x4000bde4, 0x454f4405, 0x3e53,
/* 0x4000bddc (literal) */ XT__28literal_29, 0x4000bdf8, 0x696c2809, 0x61726574, 0x296c,
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
