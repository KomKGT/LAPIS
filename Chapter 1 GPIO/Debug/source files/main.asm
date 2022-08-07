;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : main.c

	type (ML621367) 
	model small, near
	$$InitSystemClock$main segment code 2h #0h
	$$Init_MCU$main segment code 2h #0h
	$$Init_Port$main segment code 2h #0h
	$$main$main segment code 2h #0h
	STACKSEG 0400h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "main" 08H 02H 10H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "InitSystemClock" 08H 02H 0DH 00H 83H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "Init_MCU" 08H 02H 0EH 00H 81H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "Init_Port" 08H 02H 0FH 00H 80H 00H 00H 00H 07H
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
CGLOBAL 00H 43H 0002H "Flag" 04H 00H 05H 01H 00H
CFILE 0001H 0000117DH "D:\\U8Dev\\Inc\\ml621367.h"
CFILE 0002H 0000005EH "..\\source files\\wdt.h"
CFILE 0003H 0000004BH "..\\source files\\rdwr_reg.h"
CFILE 0004H 00000009H "..\\source files\\SysDefine.h"
CFILE 0005H 00000008H "..\\source files\\SysFlag.h"
CFILE 0006H 00000003H "..\\source files\\VLS.h"
CFILE 0007H 0000000AH "..\\source files\\Timer0.h"
CFILE 0008H 00000012H "..\\source files\\BlinkLED.h"
CFILE 0009H 0000000EH "..\\source files\\time_delay.h"
CFILE 0000H 000000EDH "..\\source files\\main.c"

	rseg $$main$main
CFUNCTION 16

_main	:
CBLOCK 16 1 43

;;{
CLINEA 0000H 0001H 002BH 0001H 0001H
CBLOCK 16 2 43
CLOCAL 4AH 0004H 0000H 0002H "i" 02H 00H 02H

;;	Init_MCU();
CLINEA 0000H 0001H 0030H 0002H 000CH
	bl	_Init_MCU

;;	Init_LED();
CLINEA 0000H 0001H 0031H 0002H 000CH
	bl	_Init_LED

;;	wdt_clear();
CLINEA 0000H 0001H 0036H 0002H 000DH
	bl	_wdt_clear

;;	while(1)
CLINEA 0000H 0001H 0037H 0002H 0009H
	bal	_$L1
_$L3 :
CBLOCK 16 3 56

;;		LEDon();
CLINEA 0000H 0001H 0041H 0003H 000AH
	bl	_LEDon

;;		Delay();
CLINEA 0000H 0001H 0042H 0003H 000AH
	bl	_Delay

;;		LEDoff();
CLINEA 0000H 0001H 0043H 0003H 000BH
	bl	_LEDoff

;;		Delay();
CLINEA 0000H 0001H 0044H 0003H 000AH
	bl	_Delay
CBLOCKEND 16 3 69

;;	}
CLINEA 0000H 0000H 0045H 0002H 0002H
_$L1 :

;;	while(1)
CLINEA 0000H 0000H 0037H 0000H 0000H
	mov	er0,	#0 
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L3

;;	}
CLINEA 0000H 0000H 0045H 0002H 0002H
CBLOCKEND 16 2 70

;;}
CLINEA 0000H 0001H 0046H 0001H 0001H
_$$end_of_main :
	bal	$
CBLOCKEND 16 1 70
CFUNCTIONEND 16


	rseg $$InitSystemClock$main
CFUNCTION 13

_InitSystemClock	:
CBLOCK 13 1 73

;;{
CLINEA 0000H 0001H 0049H 0001H 0001H
	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
CBLOCK 13 2 73
CRET 0004H
CLOCAL 42H 0002H 0002H 0002H "i" 02H 00H 01H

;;	ENOSC = 0;		// Disable the high speed oscillation
CLINEA 0000H 0001H 004CH 0002H 0032H
	rb	0f006h.1

;;	Set_VLS_Startup();
CLINEA 0000H 0001H 004FH 0002H 0013H
	bl	_Set_VLS_Startup

;;	HOSCM0 = 0;
CLINEA 0000H 0001H 005AH 0002H 000CH
	rb	0f002h.0

;;	SYSC2=0;SYSC1=0;SYSC0=0;
CLINEA 0000H 0001H 005BH 0002H 0019H
	rb	0f003h.2
	rb	0f003h.1
	rb	0f003h.0

;;	OUTC2=1;OUTC1=0;OUTC0=0;
CLINEA 0000H 0001H 005CH 0002H 0019H
	sb	0f003h.6
	rb	0f003h.5
	rb	0f003h.4

;;	FHUT0=0;
CLINEA 0000H 0001H 005DH 0002H 0009H
	rb	0f008h.0

;;	ENOSC = 1;	// Enable the high speed oscillation
CLINEA 0000H 0001H 005FH 0002H 0030H
	sb	0f006h.1

;;	i = 200;	// Wait for OSC. is stable.
CLINEA 0000H 0001H 0060H 0002H 0025H
	mov	r0,	#0c8h
	mov	r1,	#00h

;;	while(--i)
CLINEA 0000H 0001H 0061H 0002H 000BH
	add	er0,	#-1
	st	er0,	-2[fp]
	mov	er0,	er0
	beq	_$L7
_$L8 :

;;		wdt_clear();
CLINEA 0000H 0001H 0062H 0003H 000EH
	bl	_wdt_clear

;;	while(--i)
CLINEA 0000H 0000H 0061H 0000H 0000H
	l	er0,	-2[fp]
	add	er0,	#-1
	st	er0,	-2[fp]
	mov	er0,	er0
	bne	_$L8

;;		wdt_clear();
CLINEA 0000H 0000H 0062H 0003H 000EH
_$L7 :

;;	SELSCLK = 1; 	// System Clock = HSCLK by the SYSC2 to SYSC0 bit
CLINEA 0000H 0001H 0064H 0002H 0040H
	sb	0f006h.0

;;	__asm("nop");
CLINEA 0000H 0001H 0065H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0066H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0067H 0002H 000EH
nop

;;	__asm("nop");
CLINEA 0000H 0001H 0068H 0002H 000EH
nop
CBLOCKEND 13 2 105

;;}
CLINEA 0000H 0001H 0069H 0001H 0001H
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 13 1 105
CFUNCTIONEND 13


	rseg $$Init_Port$main
CFUNCTION 15

_Init_Port	:
CBLOCK 15 1 108

;;{
CLINEA 0000H 0001H 006CH 0001H 0001H
CBLOCK 15 2 108

;;	P01DO=0;	// Output = 0
CLINEA 0000H 0001H 0071H 0002H 0017H
	rb	0f201h.1

;;	P02DO=0;	// Output = 0
CLINEA 0000H 0001H 0072H 0002H 0017H
	rb	0f201h.2

;;	P03DO=0;	// Output = 0
CLINEA 0000H 0001H 0073H 0002H 0017H
	rb	0f201h.3

;;	P04DO=0;	// Output = 0
CLINEA 0000H 0001H 0074H 0002H 0017H
	rb	0f201h.4

;;	P05DO=0;	// Output = 0
CLINEA 0000H 0001H 0075H 0002H 0017H
	rb	0f201h.5

;;	P06DO=0;	// Output = 0
CLINEA 0000H 0001H 0076H 0002H 0017H
	rb	0f201h.6

;;	P07DO=0;	// Output = 0
CLINEA 0000H 0001H 0077H 0002H 0017H
	rb	0f201h.7

;;	P01IE=0;P01OE=0;P01OD=0;P01PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007AH 0002H 0058H
	rb	0f203h.0
	rb	0f203h.1
	rb	0f203h.3
	rb	0f203h.2

;;	P02IE=0;P02OE=0;P02OD=0;P02PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007BH 0002H 0058H
	rb	0f204h.0
	rb	0f204h.1
	rb	0f204h.3
	rb	0f204h.2

;;	P03IE=0;P03OE=0;P03OD=0;P03PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007CH 0002H 0058H
	rb	0f205h.0
	rb	0f205h.1
	rb	0f205h.3
	rb	0f205h.2

;;	P04IE=0;P04OE=0;P04OD=0;P04PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007DH 0002H 0058H
	rb	0f206h.0
	rb	0f206h.1
	rb	0f206h.3
	rb	0f206h.2

;;	P05IE=0;P05OE=0;P05OD=0;P05PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007EH 0002H 0058H
	rb	0f207h.0
	rb	0f207h.1
	rb	0f207h.3
	rb	0f207h.2

;;	P06IE=0;P06OE=0;P06OD=0;P06PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 007FH 0002H 0058H
	rb	0f208h.0
	rb	0f208h.1
	rb	0f208h.3
	rb	0f208h.2

;;	P07IE=0;P07OE=0;P07OD=0;P07PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 0080H 0002H 0058H
	rb	0f209h.0
	rb	0f209h.1
	rb	0f209h.3
	rb	0f209h.2

;;	P01MD3=0;P01MD2=0;P01MD1=0;P01MD0=0;	// Primary function
CLINEA 0000H 0001H 0083H 0002H 0039H
	rb	0f203h.7
	rb	0f203h.6
	rb	0f203h.5
	rb	0f203h.4

;;	P02MD3=0;P02MD2=0;P02MD1=0;P02MD0=0;	// Primary function
CLINEA 0000H 0001H 0084H 0002H 0039H
	rb	0f204h.7
	rb	0f204h.6
	rb	0f204h.5
	rb	0f204h.4

;;	P03MD3=0;P03MD2=0;P03MD1=0;P03MD0=0;	// Primary function
CLINEA 0000H 0001H 0085H 0002H 0039H
	rb	0f205h.7
	rb	0f205h.6
	rb	0f205h.5
	rb	0f205h.4

;;	P04MD3=0;P04MD2=0;P04MD1=0;P04MD0=0;	// Primary function
CLINEA 0000H 0001H 0086H 0002H 0039H
	rb	0f206h.7
	rb	0f206h.6
	rb	0f206h.5
	rb	0f206h.4

;;	P05MD3=0;P05MD2=0;P05MD1=0;P05MD0=0;	// Primary function
CLINEA 0000H 0001H 0087H 0002H 0039H
	rb	0f207h.7
	rb	0f207h.6
	rb	0f207h.5
	rb	0f207h.4

;;	P06MD3=0;P06MD2=0;P06MD1=0;P06MD0=0;	// Primary function
CLINEA 0000H 0001H 0088H 0002H 0039H
	rb	0f208h.7
	rb	0f208h.6
	rb	0f208h.5
	rb	0f208h.4

;;	P07MD3=0;P07MD2=0;P07MD1=0;P07MD0=0;	// Primary function
CLINEA 0000H 0001H 0089H 0002H 0039H
	rb	0f209h.7
	rb	0f209h.6
	rb	0f209h.5
	rb	0f209h.4

;;	P10DO=0;	// Output = 0
CLINEA 0000H 0001H 008DH 0002H 0017H
	rb	0f211h.0

;;	P11DO=0;	// Output = 0
CLINEA 0000H 0001H 008EH 0002H 0017H
	rb	0f211h.1

;;	P12DO=0;	// Output = 0
CLINEA 0000H 0001H 008FH 0002H 0017H
	rb	0f211h.2

;;	P13DO=0;	// Output = 0
CLINEA 0000H 0001H 0090H 0002H 0017H
	rb	0f211h.3

;;	P14DO=0;	// Output = 0
CLINEA 0000H 0001H 0091H 0002H 0017H
	rb	0f211h.4

;;	P15DO=0;	// Output = 0
CLINEA 0000H 0001H 0092H 0002H 0017H
	rb	0f211h.5

;;	P16DO=0;	// Output = 0
CLINEA 0000H 0001H 0093H 0002H 0017H
	rb	0f211h.6

;;	P17DO=0;	// Output = 0
CLINEA 0000H 0001H 0094H 0002H 0017H
	rb	0f211h.7

;;	P10IE=0;P10OE=0;P10OD=0;P10PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 0096H 0002H 0058H
	rb	0f212h.0
	rb	0f212h.1
	rb	0f212h.3
	rb	0f212h.2

;;	P11IE=0;P11OE=0;P11OD=0;P11PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 0097H 0002H 0058H
	rb	0f213h.0
	rb	0f213h.1
	rb	0f213h.3
	rb	0f213h.2

;;	P12IE=0;P12OE=0;P12OD=0;P12PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 0098H 0002H 0058H
	rb	0f214h.0
	rb	0f214h.1
	rb	0f214h.3
	rb	0f214h.2

;;	P13IE=0;P13OE=0;P13OD=0;P13PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 0099H 0002H 0058H
	rb	0f215h.0
	rb	0f215h.1
	rb	0f215h.3
	rb	0f215h.2

;;	P14IE=0;P14OE=0;P14OD=0;P14PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 009AH 0002H 0058H
	rb	0f216h.0
	rb	0f216h.1
	rb	0f216h.3
	rb	0f216h.2

;;	P15IE=0;P15OE=0;P15OD=0;P15PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 009BH 0002H 0058H
	rb	0f217h.0
	rb	0f217h.1
	rb	0f217h.3
	rb	0f217h.2

;;	P16IE=0;P16OE=0;P16OD=0;P16PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 009CH 0002H 0058H
	rb	0f218h.0
	rb	0f218h.1
	rb	0f218h.3
	rb	0f218h.2

;;	P17IE=0;P17OE=0;P17OD=0;P17PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 009DH 0002H 0058H
	rb	0f219h.0
	rb	0f219h.1
	rb	0f219h.3
	rb	0f219h.2

;;	P10MD3=0;P10MD2=0;P10MD1=0;P10MD0=0;	// Primary function
CLINEA 0000H 0001H 009FH 0002H 0039H
	rb	0f212h.7
	rb	0f212h.6
	rb	0f212h.5
	rb	0f212h.4

;;	P11MD3=0;P11MD2=0;P11MD1=0;P11MD0=0;	// Primary function
CLINEA 0000H 0001H 00A0H 0002H 0039H
	rb	0f213h.7
	rb	0f213h.6
	rb	0f213h.5
	rb	0f213h.4

;;	P12MD3=0;P12MD2=0;P12MD1=0;P12MD0=0;	// Primary function
CLINEA 0000H 0001H 00A1H 0002H 0039H
	rb	0f214h.7
	rb	0f214h.6
	rb	0f214h.5
	rb	0f214h.4

;;	P13MD3=0;P13MD2=0;P13MD1=0;P13MD0=0;	// Primary function
CLINEA 0000H 0001H 00A2H 0002H 0039H
	rb	0f215h.7
	rb	0f215h.6
	rb	0f215h.5
	rb	0f215h.4

;;	P14MD3=0;P14MD2=0;P14MD1=0;P14MD0=0;	// Primary function
CLINEA 0000H 0001H 00A3H 0002H 0039H
	rb	0f216h.7
	rb	0f216h.6
	rb	0f216h.5
	rb	0f216h.4

;;	P15MD3=0;P15MD2=0;P15MD1=0;P15MD0=0;	// Primary function
CLINEA 0000H 0001H 00A4H 0002H 0039H
	rb	0f217h.7
	rb	0f217h.6
	rb	0f217h.5
	rb	0f217h.4

;;	P16MD3=0;P16MD2=0;P16MD1=0;P16MD0=0;	// Primary function
CLINEA 0000H 0001H 00A5H 0002H 0039H
	rb	0f218h.7
	rb	0f218h.6
	rb	0f218h.5
	rb	0f218h.4

;;	P17MD3=0;P17MD2=0;P17MD1=0;P17MD0=0;	// Primary function
CLINEA 0000H 0001H 00A6H 0002H 0039H
	rb	0f219h.7
	rb	0f219h.6
	rb	0f219h.5
	rb	0f219h.4

;;	P20DO=0;	// Output = 0
CLINEA 0000H 0001H 00ABH 0002H 0017H
	rb	0f221h.0

;;	P21DO=0;	// Output = 0
CLINEA 0000H 0001H 00ACH 0002H 0017H
	rb	0f221h.1

;;	P22DO=0;	// Output = 0
CLINEA 0000H 0001H 00ADH 0002H 0017H
	rb	0f221h.2

;;	P23DO=0;	// Output = 0
CLINEA 0000H 0001H 00AEH 0002H 0017H
	rb	0f221h.3

;;	P24DO=0;	// Output = 0
CLINEA 0000H 0001H 00AFH 0002H 0017H
	rb	0f221h.4

;;	P25DO=0;	// Output = 0
CLINEA 0000H 0001H 00B0H 0002H 0017H
	rb	0f221h.5

;;	P26DO=0;	// Output = 0
CLINEA 0000H 0001H 00B1H 0002H 0017H
	rb	0f221h.6

;;	P27DO=0;	// Output = 0
CLINEA 0000H 0001H 00B2H 0002H 0017H
	rb	0f221h.7

;;	P20IE=0;P20OE=0;P20OD=0;P20PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00B4H 0002H 0058H
	rb	0f222h.0
	rb	0f222h.1
	rb	0f222h.3
	rb	0f222h.2

;;	P21IE=0;P21OE=0;P21OD=0;P21PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00B5H 0002H 0058H
	rb	0f223h.0
	rb	0f223h.1
	rb	0f223h.3
	rb	0f223h.2

;;	P22IE=0;P22OE=0;P22OD=0;P22PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00B6H 0002H 0058H
	rb	0f224h.0
	rb	0f224h.1
	rb	0f224h.3
	rb	0f224h.2

;;	P23IE=0;P23OE=0;P23OD=0;P23PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00B7H 0002H 0058H
	rb	0f225h.0
	rb	0f225h.1
	rb	0f225h.3
	rb	0f225h.2

;;	P24IE=0;P24OE=0;P24OD=0;P24PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00B9H 0002H 0058H
	rb	0f226h.0
	rb	0f226h.1
	rb	0f226h.3
	rb	0f226h.2

;;	P25IE=0;P25OE=0;P25OD=0;P25PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00BAH 0002H 0058H
	rb	0f227h.0
	rb	0f227h.1
	rb	0f227h.3
	rb	0f227h.2

;;	P26IE=0;P26OE=0;P26OD=0;P26PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00BBH 0002H 0058H
	rb	0f228h.0
	rb	0f228h.1
	rb	0f228h.3
	rb	0f228h.2

;;	P27IE=0;P27OE=0;P27OD=0;P27PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00BCH 0002H 0058H
	rb	0f229h.0
	rb	0f229h.1
	rb	0f229h.3
	rb	0f229h.2

;;	P20MD3=0;P20MD2=0;P20MD1=0;P20MD0=0;	// Primary function
CLINEA 0000H 0001H 00BEH 0002H 0039H
	rb	0f222h.7
	rb	0f222h.6
	rb	0f222h.5
	rb	0f222h.4

;;	P21MD3=0;P21MD2=0;P21MD1=0;P21MD0=0;	// Primary function
CLINEA 0000H 0001H 00BFH 0002H 0039H
	rb	0f223h.7
	rb	0f223h.6
	rb	0f223h.5
	rb	0f223h.4

;;	P22MD3=0;P22MD2=0;P22MD1=0;P22MD0=0;	// Primary function
CLINEA 0000H 0001H 00C0H 0002H 0039H
	rb	0f224h.7
	rb	0f224h.6
	rb	0f224h.5
	rb	0f224h.4

;;	P23MD3=0;P23MD2=0;P23MD1=0;P23MD0=0;	// Primary function
CLINEA 0000H 0001H 00C1H 0002H 0039H
	rb	0f225h.7
	rb	0f225h.6
	rb	0f225h.5
	rb	0f225h.4

;;	P24MD3=0;P24MD2=0;P24MD1=0;P24MD0=0;	// Primary function
CLINEA 0000H 0001H 00C2H 0002H 0039H
	rb	0f226h.7
	rb	0f226h.6
	rb	0f226h.5
	rb	0f226h.4

;;	P25MD3=0;P25MD2=0;P25MD1=0;P25MD0=0;	// Primary function
CLINEA 0000H 0001H 00C3H 0002H 0039H
	rb	0f227h.7
	rb	0f227h.6
	rb	0f227h.5
	rb	0f227h.4

;;	P26MD3=0;P26MD2=0;P26MD1=0;P26MD0=0;	// Primary function
CLINEA 0000H 0001H 00C4H 0002H 0039H
	rb	0f228h.7
	rb	0f228h.6
	rb	0f228h.5
	rb	0f228h.4

;;	P27MD3=0;P27MD2=0;P27MD1=0;P27MD0=0;	// Primary function
CLINEA 0000H 0001H 00C5H 0002H 0039H
	rb	0f229h.7
	rb	0f229h.6
	rb	0f229h.5
	rb	0f229h.4

;;	P30DO=0;	// Output = 0
CLINEA 0000H 0001H 00CAH 0002H 0017H
	rb	0f231h.0

;;	P31DO=0;	// Output = 0
CLINEA 0000H 0001H 00CBH 0002H 0017H
	rb	0f231h.1

;;	P32DO=0;	// Output = 0
CLINEA 0000H 0001H 00CCH 0002H 0017H
	rb	0f231h.2

;;	P33DO=0;	// Output = 0
CLINEA 0000H 0001H 00CDH 0002H 0017H
	rb	0f231h.3

;;	P30IE=0;P30OE=0;P30OD=0;P30PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00CFH 0002H 0058H
	rb	0f232h.0
	rb	0f232h.1
	rb	0f232h.3
	rb	0f232h.2

;;	P31IE=0;P31OE=0;P31OD=0;P31PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00D0H 0002H 0058H
	rb	0f233h.0
	rb	0f233h.1
	rb	0f233h.3
	rb	0f233h.2

;;	P32IE=0;P32OE=0;P32OD=0;P32PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00D1H 0002H 0058H
	rb	0f234h.0
	rb	0f234h.1
	rb	0f234h.3
	rb	0f234h.2

;;	P33IE=0;P33OE=0;P33OD=0;P33PU=0;	// Disable input, Disable output, CMOS output, No pull
CLINEA 0000H 0001H 00D2H 0002H 0058H
	rb	0f235h.0
	rb	0f235h.1
	rb	0f235h.3
	rb	0f235h.2

;;	P30MD3=0;P30MD2=0;P30MD1=0;P30MD0=0;	// Primary function
CLINEA 0000H 0001H 00D4H 0002H 0039H
	rb	0f232h.7
	rb	0f232h.6
	rb	0f232h.5
	rb	0f232h.4

;;	P31MD3=0;P31MD2=0;P31MD1=0;P31MD0=0;	// Primary function
CLINEA 0000H 0001H 00D5H 0002H 0039H
	rb	0f233h.7
	rb	0f233h.6
	rb	0f233h.5
	rb	0f233h.4

;;	P32MD3=0;P32MD2=0;P32MD1=0;P32MD0=0;	// Primary function
CLINEA 0000H 0001H 00D6H 0002H 0039H
	rb	0f234h.7
	rb	0f234h.6
	rb	0f234h.5
	rb	0f234h.4

;;	P33MD3=0;P33MD2=0;P33MD1=0;P33MD0=0;	// Primary function
CLINEA 0000H 0001H 00D7H 0002H 0039H
	rb	0f235h.7
	rb	0f235h.6
	rb	0f235h.5
	rb	0f235h.4
CBLOCKEND 15 2 219

;;}
CLINEA 0000H 0001H 00DBH 0001H 0001H
	rt
CBLOCKEND 15 1 219
CFUNCTIONEND 15


	rseg $$Init_MCU$main
CFUNCTION 14

_Init_MCU	:
CBLOCK 14 1 222

;;{
CLINEA 0000H 0001H 00DEH 0001H 0001H
	push	lr
CBLOCK 14 2 222
CRET 0000H

;;	__DI();
CLINEA 0000H 0001H 00DFH 0002H 0008H
	di

;;	wdt_init( WDT_WINDOW_100, WDT_500MS );
CLINEA 0000H 0001H 00E1H 0002H 0027H
	mov	r1,	#05h
	mov	r0,	#00h
	bl	_wdt_init

;;	Init_Port();
CLINEA 0000H 0001H 00E3H 0002H 000DH
	bl	_Init_Port

;;	InitSystemClock();
CLINEA 0000H 0001H 00E4H 0002H 0013H
	bl	_InitSystemClock

;;	Init_Timer0();
CLINEA 0000H 0001H 00E6H 0002H 000FH
	bl	_Init_Timer0

;;	__EI();
CLINEA 0000H 0001H 00E8H 0002H 0008H
	ei
CBLOCKEND 14 2 233

;;}
CLINEA 0000H 0001H 00E9H 0001H 0001H
	pop	pc
CBLOCKEND 14 1 233
CFUNCTIONEND 14

	public _main
	public _InitSystemClock
	public _Init_MCU
	public _Init_Port
	_Flag comm data 02h #00h
	extrn code near : _Init_Timer0
	extrn code near : _LEDon
	extrn code near : _wdt_clear
	extrn code near : _Init_LED
	extrn code near : _wdt_init
	extrn code near : _Set_VLS_Startup
	extrn code near : _Delay
	extrn code near : _LEDoff
	extrn code : $$start_up

	cseg #00h at 02h
	dw	$$start_up

	end
