;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : timer0.c

	type (ML621367) 
	model small, near
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$Init_Timer0$timer0 segment code 2h #0h
	$$RealTimeClock$timer0 segment code 2h #0h
	$$Timer0_Interrupt$timer0 segment code 2h #0h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "Init_Timer0" 08H 02H 07H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "Timer0_Interrupt" 08H 02H 08H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "RealTimeClock" 08H 02H 09H 00H 80H 00H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0001H 0002H 00000002H "flag"
CSTRUCTMEM 52H 00000001H 00000000H "_ScanTime" 02H 00H 01H
CSTRUCTMEM 52H 00000001H 00000001H "_TimerLED" 02H 00H 01H
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
CGLOBAL 01H 42H 0002H "CountmSec" 02H 00H 01H
CGLOBAL 01H 42H 0002H "counttest" 02H 00H 01H
CGLOBAL 00H 43H 0002H "Flag" 04H 00H 05H 01H 00H
CGLOBAL 01H 42H 0002H "BuzzCount" 02H 00H 01H
CGLOBAL 01H 42H 0001H "Hour" 02H 00H 00H
CGLOBAL 01H 42H 0002H "t_cnt" 02H 00H 01H
CGLOBAL 01H 42H 0001H "Msec" 02H 00H 00H
CGLOBAL 01H 42H 0001H "Min" 02H 00H 00H
CGLOBAL 01H 42H 0001H "Sec" 02H 00H 00H
CFILE 0001H 0000117DH "D:\\U8Dev\\Inc\\ml621367.h"
CFILE 0002H 0000005EH "..\\source files\\wdt.h"
CFILE 0003H 0000004BH "..\\source files\\rdwr_reg.h"
CFILE 0004H 00000009H "..\\source files\\SysDefine.h"
CFILE 0005H 00000012H "..\\source files\\BlinkLED.h"
CFILE 0006H 00000008H "..\\source files\\SysFlag.h"
CFILE 0007H 0000000EH "..\\source files\\time_delay.h"
CFILE 0000H 00000069H "..\\source files\\timer0.c"

	rseg $$Init_Timer0$timer0
CFUNCTION 7

_Init_Timer0	:
CBLOCK 7 1 22

;;{
CLINEA 0000H 0001H 0016H 0001H 0001H
CBLOCK 7 2 22

;;	TH0CS=1;
CLINEA 0000H 0001H 0029H 0002H 0009H
	sb	0f320h.0

;;	TH0EX=0;
CLINEA 0000H 0001H 002AH 0002H 0009H
	rb	0f320h.2

;;	TH0EXS=0;
CLINEA 0000H 0001H 002CH 0002H 000AH
	rb	0f320h.3

;;	TH0DIV2=0;TH0DIV1=0;TH0DIV0=0;
CLINEA 0000H 0001H 002DH 0002H 001FH
	rb	0f320h.6
	rb	0f320h.5
	rb	0f320h.4

;;	TH08BM = 0;
CLINEA 0000H 0001H 002FH 0002H 000CH
	rb	0f321h.0

;;	TH0OST = 0;
CLINEA 0000H 0001H 0030H 0002H 000CH
	rb	0f321h.1

;;	TH0NEG = 0;
CLINEA 0000H 0001H 0031H 0002H 000CH
	rb	0f321h.2

;;	TMH0D = 5999;
CLINEA 0000H 0001H 0033H 0002H 000EH
	mov	r0,	#06fh
	mov	r1,	#017h
	st	er0,	0f300h

;;	ETM0 = 1;      	// Timer 0 interrupt enable
CLINEA 0000H 0001H 0035H 0002H 002CH
	sb	0f023h.6

;;	TH0RUN = 1;		// Start Counting
CLINEA 0000H 0001H 0036H 0002H 001FH
	sb	0f350h.0
CBLOCKEND 7 2 55

;;}
CLINEA 0000H 0001H 0037H 0001H 0001H
	rt
CBLOCKEND 7 1 55
CFUNCTIONEND 7


	rseg $$Timer0_Interrupt$timer0
CFUNCTION 8

_Timer0_Interrupt	:
CBLOCK 8 1 60

;;{
CLINEA 0000H 0001H 003CH 0001H 0001H
CBLOCK 8 2 60
CSLOCAL 42H 0001H 0000H 0002H "tick_cnt" 02H 00H 00H
CSLOCAL 42H 0002H 0001H 0002H "t_base_cnt" 02H 00H 01H

;;	if(++tick_cnt >= 16)	// Count for 250Hz (4000Hz/250Hz = 16)
CLINEA 0000H 0001H 0044H 0002H 003CH
	l	r0,	NEAR _$ST0
	mov	r1,	#00h
	add	er0,	#1 
	st	r0,	NEAR _$ST0
	cmp	r0,	#010h
	blt	_$L2
CBLOCK 8 3 69

;;		tick_cnt = 0;
CLINEA 0000H 0001H 0046H 0003H 000FH
	mov	r0,	#00h
	st	r0,	NEAR _$ST0

;;		Flag._ScanTime=1;
CLINEA 0000H 0001H 0047H 0003H 0013H
	sb	NEAR _Flag.0
CBLOCKEND 8 3 72

;;	}
CLINEA 0000H 0000H 0048H 0002H 0002H
_$L2 :

;;	t_base_cnt++;
CLINEA 0000H 0000H 004CH 0002H 000EH
	l	er0,	NEAR _$ST1
	add	er0,	#1 
	st	er0,	NEAR _$ST1

;;	if(t_base_cnt >= (4000))
CLINEA 0000H 0001H 004DH 0002H 0019H
	cmp	r0,	#0a0h
	cmpc	r1,	#0fh
	blt	_$L4

;;		t_base_cnt = 0;
CLINEA 0000H 0001H 004FH 0003H 0011H
	mov	er0,	#0 
	st	er0,	NEAR _$ST1
_$L4 :
CBLOCKEND 8 2 82

;;}
CLINEA 0000H 0001H 0052H 0001H 0001H
	rt
CBLOCKEND 8 1 82
CFUNCTIONEND 8


	rseg $$RealTimeClock$timer0
CFUNCTION 9

_RealTimeClock	:
CBLOCK 9 1 85

;;{
CLINEA 0000H 0001H 0055H 0001H 0001H
CBLOCK 9 2 85

;;	if(++Msec >= SecCountValue) //SecCountValue = 250
CLINEA 0000H 0001H 0056H 0002H 0032H
	l	r0,	NEAR _Msec
	mov	r1,	#00h
	add	er0,	#1 
	st	r0,	NEAR _Msec
	cmp	r0,	#0fah
	blt	_$L7
CBLOCK 9 3 87

;;		Msec=0;
CLINEA 0000H 0001H 0058H 0003H 0009H
	mov	r0,	#00h
	st	r0,	NEAR _Msec

;;		if(++Sec >= 60)
CLINEA 0000H 0001H 0059H 0003H 0011H
	l	r0,	NEAR _Sec
	mov	r1,	#00h
	add	er0,	#1 
	st	r0,	NEAR _Sec
	cmp	r0,	#03ch
	blt	_$L9
CBLOCK 9 4 90

;;			Sec=0;
CLINEA 0000H 0001H 005BH 0004H 0009H
	mov	r0,	#00h
	st	r0,	NEAR _Sec

;;			if(++Min >= 60)
CLINEA 0000H 0001H 005CH 0004H 0012H
	l	r0,	NEAR _Min
	mov	r1,	#00h
	add	er0,	#1 
	st	r0,	NEAR _Min
	cmp	r0,	#03ch
	blt	_$L11
CBLOCK 9 5 93

;;				Min=0;
CLINEA 0000H 0001H 005EH 0005H 000AH
	mov	r0,	#00h
	st	r0,	NEAR _Min

;;				Hour = ++Hour%24;
CLINEA 0000H 0000H 005FH 0005H 0015H
	l	r0,	NEAR _Hour
	mov	r1,	#00h
	add	er0,	#1 
	mov	r2,	r0
	mov	r3,	#00h
	mov	r0,	#018h
	div	er2,	r0
	st	r0,	NEAR _Hour
CBLOCKEND 9 5 96

;;			}
CLINEA 0000H 0000H 0060H 0004H 0004H
_$L11 :
CBLOCKEND 9 4 97

;;		}
CLINEA 0000H 0000H 0061H 0003H 0003H
_$L9 :
CBLOCKEND 9 3 98

;;	} 
CLINEA 0000H 0000H 0062H 0002H 0003H
_$L7 :
CBLOCKEND 9 2 99

;;}
CLINEA 0000H 0001H 0063H 0001H 0001H
	rt
CBLOCKEND 9 1 99
CFUNCTIONEND 9

	public _CountmSec
	public _Init_Timer0
	public _counttest
	public _BuzzCount
	public _Hour
	public _t_cnt
	public _Timer0_Interrupt
	public _Msec
	public _RealTimeClock
	public _Min
	public _Sec
	_Flag comm data 02h #00h
	extrn code near : _main

	rseg $$NINITTAB
	db	00h
	db	00h
	db	00h
	db	00h
	dw	00h
	dw	00h
	dw	00h
	dw	00h
	db	00h
	align
	dw	00h

	rseg $$NINITVAR
_Msec :
	ds	01h
_Sec :
	ds	01h
_Min :
	ds	01h
_Hour :
	ds	01h
_counttest :
	ds	02h
_t_cnt :
	ds	02h
_CountmSec :
	ds	02h
_BuzzCount :
	ds	02h
_$ST0 :
	ds	01h
	align
_$ST1 :
	ds	02h

	end
