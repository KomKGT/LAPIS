;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : VLS.c

	type (ML621367) 
	model small, near
	$$Set_VLS_Monitoring$VLS segment code 2h #0h
	$$Set_VLS_Startup$VLS segment code 2h #0h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "Set_VLS_Startup" 08H 02H 00H 00H 83H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "Set_VLS_Monitoring" 08H 02H 02H 00H 80H 00H 00H 00H 07H
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
CFILE 0000H 00000038H "..\\source files\\VLS.c"

	rseg $$Set_VLS_Startup$VLS
CFUNCTION 0

_Set_VLS_Startup	:
CBLOCK 0 1 8

;;{
CLINEA 0000H 0001H 0008H 0001H 0001H
	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
CBLOCK 0 2 8
CRET 0004H
CLOCAL 42H 0002H 0002H 0002H "i" 02H 00H 01H

;;	VLS0EN = 0;		// Disable VLS(Voltage Level Supervisor)
CLINEA 0000H 0001H 000BH 0002H 0036H
	rb	0f850h.0

;;	VLS0AMD1=1;VLS0AMD0=0;	// Supervisor mode
CLINEA 0000H 0001H 000DH 0002H 002AH
	sb	0f852h.5
	rb	0f852h.4

;;	VLS0SEL1=0;VLS0SEL0=0;  // No reset, no interrupt
CLINEA 0000H 0001H 000EH 0002H 0032H
	rb	0f852h.1
	rb	0f852h.0

;;	VLS0SM1=0;VLS0SM0=0;	// Without sampling 
CLINEA 0000H 0001H 000FH 0002H 002AH
	rb	0f856h.3
	rb	0f856h.2

;;	VLS0DIV2=0;VLS0DIV1=0;VLS0DIV0=0;	// No clock division
CLINEA 0000H 0001H 0010H 0002H 0037H
	rb	0f856h.6
	rb	0f856h.5
	rb	0f856h.4

;;	VLS0LV3=1;VLS0LV2=0;VLS0LV1=1;VLS0LV0=1;	// Threshold = 1.85 V
CLINEA 0000H 0001H 0011H 0002H 003FH
	sb	0f854h.3
	rb	0f854h.2
	sb	0f854h.1
	sb	0f854h.0

;;	VLS0EN = 1;		// Enable VLS(Voltage Level Supervisor)		
CLINEA 0000H 0001H 0013H 0002H 0037H
	sb	0f850h.0

;;	__asm("nop");
CLINEA 0000H 0001H 0014H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0015H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0016H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0017H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0018H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0019H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 001AH 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 001BH 0002H 000EH
nop

;;	while(VLS0RF==0)
CLINEA 0000H 0001H 001DH 0002H 0011H
	bal	_$L1
_$L3 :

;;		wdt_clear();
CLINEA 0000H 0001H 001EH 0003H 000EH
	bl	_wdt_clear
_$L1 :

;;	while(VLS0RF==0)
CLINEA 0000H 0000H 001DH 000AH 000FH
	tb	0f850h.2
	beq	_$L3

;;	for(i=0;i<200;i++)
CLINEA 0000H 0001H 0020H 0006H 0009H
	mov	er0,	#0 
	st	er0,	-2[fp]

;;	for(i=0;i<200;i++)
CLINEA 0000H 0000H 0020H 000AH 000FH
	cmp	r0,	#0c8h
	cmpc	r1,	#00h
	bge	_$L11

;;	for(i=0;i<200;i++)
CLINEA 0000H 0000H 0020H 0010H 0012H
_$L7 :

;;	for(i=0;i<200;i++)
CLINEA 0000H 0000H 0020H 0010H 0012H
	l	er0,	-2[fp]
	add	er0,	#1 
	st	er0,	-2[fp]

;;	for(i=0;i<200;i++)
CLINEA 0000H 0000H 0020H 000AH 000FH
	l	er0,	-2[fp]
	cmp	r0,	#0c8h
	cmpc	r1,	#00h
	blt	_$L7

;;	while(VLS0F==1)
CLINEA 0000H 0001H 0022H 0002H 0010H
	bal	_$L11
_$L13 :

;;		wdt_clear();
CLINEA 0000H 0001H 0023H 0003H 000EH
	bl	_wdt_clear
_$L11 :

;;	while(VLS0F==1)
CLINEA 0000H 0000H 0022H 000AH 000FH
	tb	0f850h.1
	bne	_$L13

;;		wdt_clear();
CLINEA 0000H 0000H 0023H 0003H 000EH
CBLOCKEND 0 2 36

;;}
CLINEA 0000H 0001H 0024H 0001H 0001H
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 0 1 36
CFUNCTIONEND 0


	rseg $$Set_VLS_Monitoring$VLS
CFUNCTION 2

_Set_VLS_Monitoring	:
CBLOCK 2 1 39

;;{
CLINEA 0000H 0001H 0027H 0001H 0001H
CBLOCK 2 2 39
CLOCAL 4AH 0002H 0000H 0002H "i" 02H 00H 01H

;;	VLS0EN = 0;		// Disable VLS(Voltage Level Supervisor)
CLINEA 0000H 0001H 002AH 0002H 0036H
	rb	0f850h.0

;;	VLS0AMD1=1;VLS0AMD0=0;	// Supervisor mode
CLINEA 0000H 0001H 002CH 0002H 002AH
	sb	0f852h.5
	rb	0f852h.4

;;	VLS0SEL1=0;VLS0SEL0=0;  // No reset, no interrupt
CLINEA 0000H 0001H 002DH 0002H 0032H
	rb	0f852h.1
	rb	0f852h.0

;;	VLS0SM1=0;VLS0SM0=0;	// Without sampling 
CLINEA 0000H 0001H 002EH 0002H 002AH
	rb	0f856h.3
	rb	0f856h.2

;;	VLS0DIV2=0;VLS0DIV1=0;VLS0DIV0=0;	// No clock division
CLINEA 0000H 0001H 002FH 0002H 0037H
	rb	0f856h.6
	rb	0f856h.5
	rb	0f856h.4

;;	VLS0LV3=1;VLS0LV2=0;VLS0LV1=0;VLS0LV0=0;	// Threshold = 2.45 V
CLINEA 0000H 0001H 0030H 0002H 003FH
	sb	0f854h.3
	rb	0f854h.2
	rb	0f854h.1
	rb	0f854h.0

;;	VLS0EN = 1;		// Enable VLS(Voltage Level Supervisor)		
CLINEA 0000H 0001H 0032H 0002H 0037H
	sb	0f850h.0
CBLOCKEND 2 2 51

;;}
CLINEA 0000H 0001H 0033H 0001H 0001H
	rt
CBLOCKEND 2 1 51
CFUNCTIONEND 2

	extrn code near : _wdt_clear
	public _Set_VLS_Startup
	public _Set_VLS_Monitoring
	extrn code near : _main

	end
