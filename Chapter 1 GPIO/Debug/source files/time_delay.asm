;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : time_delay.c

	type (ML621367) 
	model small, near
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$Delay$time_delay segment code 2h #0h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "Delay" 08H 02H 00H 00H 80H 00H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0002H 00000002H "flag"
CSTRUCTMEM 52H 00000001H 00000000H "_ScanTime" 02H 00H 01H
CSTRUCTMEM 52H 00000001H 00000001H "_TimerLED" 02H 00H 01H
CGLOBAL 00H 43H 0002H "Flag" 04H 00H 05H 00H 00H
CFILE 0001H 00000008H "..\\source files\\SysFlag.h"
CFILE 0002H 0000000EH "..\\source files\\time_delay.h"
CFILE 0000H 00000017H "..\\source files\\time_delay.c"

	rseg $$Delay$time_delay
CFUNCTION 0

_Delay	:
CBLOCK 0 1 12

;;{
CLINEA 0000H 0001H 000CH 0001H 0001H
CBLOCK 0 2 12
CSLOCAL 42H 0002H 0000H 0002H "Time_Count" 02H 00H 01H

;;	Time_Count++;
CLINEA 0000H 0000H 000FH 0002H 000EH
	l	er0,	NEAR _$ST0
	add	er0,	#1 
	st	er0,	NEAR _$ST0

;;		if(Time_Count >= 400) //400*4 mS = 1.6 S  //40*4 mS = 160 mS
CLINEA 0000H 0001H 0010H 0003H 003EH
	cmp	r0,	#090h
	cmpc	r1,	#01h
	blt	_$L1
CBLOCK 0 3 17

;;			Time_Count = 0;
CLINEA 0000H 0001H 0012H 0004H 0012H
	mov	er0,	#0 
	st	er0,	NEAR _$ST0

;;			Flag._TimerLED=1;
CLINEA 0000H 0001H 0013H 0004H 0014H
	sb	NEAR _Flag.1
CBLOCKEND 0 3 20

;;		}
CLINEA 0000H 0000H 0014H 0003H 0003H
_$L1 :
CBLOCKEND 0 2 22

;;}
CLINEA 0000H 0001H 0016H 0001H 0001H
	rt
CBLOCKEND 0 1 22
CFUNCTIONEND 0

	public _Delay
	_Flag comm data 02h #00h
	extrn code near : _main

	rseg $$NINITTAB
	dw	00h

	rseg $$NINITVAR
_$ST0 :
	ds	02h

	end
