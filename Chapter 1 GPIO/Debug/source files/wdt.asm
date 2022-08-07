;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : wdt.c

	type (ML621367) 
	model small, near
	$$wdt_clear$wdt segment code 2h #0h
	$$wdt_init$wdt segment code 2h #0h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "wdt_clear" 08H 02H 01H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "wdt_init" 08H 02H 00H 00H 81H 04H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CFILE 0001H 0000117DH "D:\\U8Dev\\Inc\\ml621367.h"
CFILE 0002H 0000005EH "..\\source files\\wdt.h"
CFILE 0003H 0000004BH "..\\source files\\rdwr_reg.h"
CFILE 0000H 0000004FH "..\\source files\\wdt.c"

	rseg $$wdt_init$wdt
CFUNCTION 0

_wdt_init	:
CBLOCK 0 1 46

;;{
CLINEA 0000H 0001H 002EH 0001H 0001H
	push	lr
	push	er8
	mov	er8,	er0
CBLOCK 0 2 46
CRET 0002H
CARGUMENT 46H 0001H 001CH "window" 02H 00H 00H
CARGUMENT 46H 0001H 001DH "period" 02H 00H 00H

;;    wdt_clear();
CLINEA 0000H 0001H 002FH 0005H 0010H
	bl	_wdt_clear

;;    while(wdt_getWdtClr1() == 1) {};
CLINEA 0000H 0001H 0030H 0005H 0024H
_$L3 :
CBLOCK 0 3 48
CBLOCKEND 0 3 48
	tb	0f016h.1
	bne	_$L3

;;    while(wdt_getWdtClr2() == 1) {};
CLINEA 0000H 0001H 0031H 0005H 0024H
_$L7 :
CBLOCK 0 4 49
CBLOCKEND 0 4 49
	tb	0f016h.2
	bne	_$L7

;;    write_reg8( WDTMOD, (( window << 4 ) | period) );
CLINEA 0000H 0001H 0032H 0005H 0035H
	mov	r0,	r8
	sll	r0,	#04h
	mov	r2,	r9
	or	r2,	r0
	st	r2,	0f012h
CBLOCKEND 0 2 51

;;}
CLINEA 0000H 0001H 0033H 0001H 0001H
	pop	er8
	pop	pc
CBLOCKEND 0 1 51
CFUNCTIONEND 0


	rseg $$wdt_clear$wdt
CFUNCTION 1

_wdt_clear	:
CBLOCK 1 1 61

;;{
CLINEA 0000H 0001H 003DH 0001H 0001H
CBLOCK 1 2 61

;;    if(wdt_getWdtClr1() == 1) {
CLINEA 0000H 0001H 003EH 0005H 001FH
	tb	0f016h.1
	bne	_$L9
CBLOCK 1 3 62

;;        return;
CLINEA 0000H 0001H 003FH 0009H 000FH
CBLOCKEND 1 3 64

;;    if(wdt_getWdtClr2() == 1) {
CLINEA 0000H 0001H 0042H 0005H 001FH
	tb	0f016h.2
	bne	_$L9
CBLOCK 1 4 66

;;        return;
CLINEA 0000H 0001H 0043H 0009H 000FH
CBLOCKEND 1 4 68

;;	__DI();
CLINEA 0000H 0001H 0046H 0002H 0008H
	di

;;	do {
CLINEA 0000H 0001H 0047H 0002H 0005H
_$L16 :
CBLOCK 1 5 71

;;		write_reg8( WDTCON, 0x5A );
CLINEA 0000H 0001H 0048H 0003H 001DH
	mov	r0,	#05ah
	st	r0,	0f010h
CBLOCKEND 1 5 73

;;	} while ( get_bit( WDP ) != 1 ); 
CLINEA 0000H 0000H 0049H 0002H 0022H
	tb	0f010h.0
	beq	_$L16

;;	write_reg8( WDTCON, 0xA5 );
CLINEA 0000H 0001H 004AH 0002H 001CH
	mov	r0,	#0a5h
	st	r0,	0f010h

;;	__EI();
CLINEA 0000H 0001H 004BH 0002H 0008H
	ei
CBLOCKEND 1 2 76

;;}
CLINEA 0000H 0001H 004CH 0001H 0001H
_$L9 :
	rt
CBLOCKEND 1 1 76
CFUNCTIONEND 1

	public _wdt_clear
	public _wdt_init
	extrn code near : _main

	end