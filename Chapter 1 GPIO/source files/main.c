/*
 * main.c
 *
 *  Created on: Jan 5, 2020
 *      Author: USER
 */
#include <ml621367.h>

/*****************************************************************************
 main.c
 ******************************************************************************/

#include "wdt.h"
#include "SysDefine.h"
#include "SysFlag.h"

#include "VLS.h"
#include "Timer0.h"
#include "BlinkLED.h"
#include "time_delay.h"


/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/

/*############################################################################*/
/*#                                Variable                                  #*/
/*############################################################################*/

/*############################################################################*/
/*#                               Prototype                                  #*/
/*############################################################################*/
void InitSystemClock(void);
void Init_MCU(void);
void Init_Port(void);

// ---------------------------------------------------------------------

//----------------------------------------------------------------------

int main( void )
{
	unsigned long i;

	/*=== Init ===*/

	Init_MCU();
	Init_LED();


	/*=== End of program ===*/
	//---------------------------------------------------------------
	wdt_clear();
	while(1)
	{
		//while(Flag._ScanTime==0)
		//		;

		//Flag._ScanTime = 0;
		//wdt_clear();

		//RealTimeClock();
		//Display();
		LEDon();
		Delay();
		LEDoff();
		Delay();
	}
}
//-------------------------------------------------------------------
void InitSystemClock(void)
{
	unsigned int i;

	ENOSC = 0;		// Disable the high speed oscillation

	//---------------------------------------------------------------
	Set_VLS_Startup();

	//******************************* Initial System Clock *********************************
	//		HOSCM0 = 0 Choose PLL oscillation mode
	//		SYSC2=0 SYSC1=0 SYSC0=0 Choose a division ratio of the frequency of the high-speed
	//								SYSTEMCLK Frequency = HSCLK
	//		OUTC2=1 OUTC1=0 OUTC0=0 Choose a division ratio of the frequency of the high-speed output clock
	//								OUTHSCLK Frequency = 1/16 HSCLK
	//		FHUT0 = 0  Choose the wake-up time of the high-speed clock
	//				   Clock Start after 2.5 mS
	//**************************************************************************************
	HOSCM0 = 0;
	SYSC2=0;SYSC1=0;SYSC0=0;
	OUTC2=1;OUTC1=0;OUTC0=0;
	FHUT0=0;

	ENOSC = 1;	// Enable the high speed oscillation
	i = 200;	// Wait for OSC. is stable.
	while(--i)
		wdt_clear();

	SELSCLK = 1; 	// System Clock = HSCLK by the SYSC2 to SYSC0 bit
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
}
//-------------------------------------------------------------------
void Init_Port(void)
{
	//-------------------------------------------------------------
	//-------- Port 0 Init ---------------------------------------
	//-------------------------------------------------------------
	//P00DO=0;	// Output = 0
	P01DO=0;	// Output = 0
	P02DO=0;	// Output = 0
	P03DO=0;	// Output = 0
	P04DO=0;	// Output = 0
	P05DO=0;	// Output = 0
	P06DO=0;	// Output = 0
	P07DO=0;	// Output = 0

	//P00IE=0;P00OE=0;P00OD=0;P00PU=0;	// Disable input, Disable output, CMOS output, No pull
	P01IE=0;P01OE=0;P01OD=0;P01PU=0;	// Disable input, Disable output, CMOS output, No pull
	P02IE=0;P02OE=0;P02OD=0;P02PU=0;	// Disable input, Disable output, CMOS output, No pull
	P03IE=0;P03OE=0;P03OD=0;P03PU=0;	// Disable input, Disable output, CMOS output, No pull
	P04IE=0;P04OE=0;P04OD=0;P04PU=0;	// Disable input, Disable output, CMOS output, No pull
	P05IE=0;P05OE=0;P05OD=0;P05PU=0;	// Disable input, Disable output, CMOS output, No pull
	P06IE=0;P06OE=0;P06OD=0;P06PU=0;	// Disable input, Disable output, CMOS output, No pull
	P07IE=0;P07OE=0;P07OD=0;P07PU=0;	// Disable input, Disable output, CMOS output, No pull

	//P00MD3=0;P00MD2=0;P00MD1=0;P00MD0=0;	// Primary function
	P01MD3=0;P01MD2=0;P01MD1=0;P01MD0=0;	// Primary function
	P02MD3=0;P02MD2=0;P02MD1=0;P02MD0=0;	// Primary function
	P03MD3=0;P03MD2=0;P03MD1=0;P03MD0=0;	// Primary function
	P04MD3=0;P04MD2=0;P04MD1=0;P04MD0=0;	// Primary function
	P05MD3=0;P05MD2=0;P05MD1=0;P05MD0=0;	// Primary function
	P06MD3=0;P06MD2=0;P06MD1=0;P06MD0=0;	// Primary function
	P07MD3=0;P07MD2=0;P07MD1=0;P07MD0=0;	// Primary function
	//-------------------------------------------------------------
	//-------- Port 1 Init ---------------------------------------
	//-------------------------------------------------------------
	P10DO=0;	// Output = 0
	P11DO=0;	// Output = 0
	P12DO=0;	// Output = 0
	P13DO=0;	// Output = 0
	P14DO=0;	// Output = 0
	P15DO=0;	// Output = 0
	P16DO=0;	// Output = 0
	P17DO=0;	// Output = 0

	P10IE=0;P10OE=0;P10OD=0;P10PU=0;	// Disable input, Disable output, CMOS output, No pull
	P11IE=0;P11OE=0;P11OD=0;P11PU=0;	// Disable input, Disable output, CMOS output, No pull
	P12IE=0;P12OE=0;P12OD=0;P12PU=0;	// Disable input, Disable output, CMOS output, No pull
	P13IE=0;P13OE=0;P13OD=0;P13PU=0;	// Disable input, Disable output, CMOS output, No pull
	P14IE=0;P14OE=0;P14OD=0;P14PU=0;	// Disable input, Disable output, CMOS output, No pull
	P15IE=0;P15OE=0;P15OD=0;P15PU=0;	// Disable input, Disable output, CMOS output, No pull
	P16IE=0;P16OE=0;P16OD=0;P16PU=0;	// Disable input, Disable output, CMOS output, No pull
	P17IE=0;P17OE=0;P17OD=0;P17PU=0;	// Disable input, Disable output, CMOS output, No pull

	P10MD3=0;P10MD2=0;P10MD1=0;P10MD0=0;	// Primary function
	P11MD3=0;P11MD2=0;P11MD1=0;P11MD0=0;	// Primary function
	P12MD3=0;P12MD2=0;P12MD1=0;P12MD0=0;	// Primary function
	P13MD3=0;P13MD2=0;P13MD1=0;P13MD0=0;	// Primary function
	P14MD3=0;P14MD2=0;P14MD1=0;P14MD0=0;	// Primary function
	P15MD3=0;P15MD2=0;P15MD1=0;P15MD0=0;	// Primary function
	P16MD3=0;P16MD2=0;P16MD1=0;P16MD0=0;	// Primary function
	P17MD3=0;P17MD2=0;P17MD1=0;P17MD0=0;	// Primary function

	//-------------------------------------------------------------
	//-------- Port 2 Init ---------------------------------------
	//-------------------------------------------------------------
	P20DO=0;	// Output = 0
	P21DO=0;	// Output = 0
	P22DO=0;	// Output = 0
	P23DO=0;	// Output = 0
	P24DO=0;	// Output = 0
	P25DO=0;	// Output = 0
	P26DO=0;	// Output = 0
	P27DO=0;	// Output = 0

	P20IE=0;P20OE=0;P20OD=0;P20PU=0;	// Disable input, Disable output, CMOS output, No pull
	P21IE=0;P21OE=0;P21OD=0;P21PU=0;	// Disable input, Disable output, CMOS output, No pull
	P22IE=0;P22OE=0;P22OD=0;P22PU=0;	// Disable input, Disable output, CMOS output, No pull
	P23IE=0;P23OE=0;P23OD=0;P23PU=0;	// Disable input, Disable output, CMOS output, No pull

	P24IE=0;P24OE=0;P24OD=0;P24PU=0;	// Disable input, Disable output, CMOS output, No pull
	P25IE=0;P25OE=0;P25OD=0;P25PU=0;	// Disable input, Disable output, CMOS output, No pull
	P26IE=0;P26OE=0;P26OD=0;P26PU=0;	// Disable input, Disable output, CMOS output, No pull
	P27IE=0;P27OE=0;P27OD=0;P27PU=0;	// Disable input, Disable output, CMOS output, No pull

	P20MD3=0;P20MD2=0;P20MD1=0;P20MD0=0;	// Primary function
	P21MD3=0;P21MD2=0;P21MD1=0;P21MD0=0;	// Primary function
	P22MD3=0;P22MD2=0;P22MD1=0;P22MD0=0;	// Primary function
	P23MD3=0;P23MD2=0;P23MD1=0;P23MD0=0;	// Primary function
	P24MD3=0;P24MD2=0;P24MD1=0;P24MD0=0;	// Primary function
	P25MD3=0;P25MD2=0;P25MD1=0;P25MD0=0;	// Primary function
	P26MD3=0;P26MD2=0;P26MD1=0;P26MD0=0;	// Primary function
	P27MD3=0;P27MD2=0;P27MD1=0;P27MD0=0;	// Primary function

	//-------------------------------------------------------------
	//-------- Port 3 Init ---------------------------------------
	//-------------------------------------------------------------
	P30DO=0;	// Output = 0
	P31DO=0;	// Output = 0
	P32DO=0;	// Output = 0
	P33DO=0;	// Output = 0

	P30IE=0;P30OE=0;P30OD=0;P30PU=0;	// Disable input, Disable output, CMOS output, No pull
	P31IE=0;P31OE=0;P31OD=0;P31PU=0;	// Disable input, Disable output, CMOS output, No pull
	P32IE=0;P32OE=0;P32OD=0;P32PU=0;	// Disable input, Disable output, CMOS output, No pull
	P33IE=0;P33OE=0;P33OD=0;P33PU=0;	// Disable input, Disable output, CMOS output, No pull

	P30MD3=0;P30MD2=0;P30MD1=0;P30MD0=0;	// Primary function
	P31MD3=0;P31MD2=0;P31MD1=0;P31MD0=0;	// Primary function
	P32MD3=0;P32MD2=0;P32MD1=0;P32MD0=0;	// Primary function
	P33MD3=0;P33MD2=0;P33MD1=0;P33MD0=0;	// Primary function

	//-------------------------------------------------------------

}
//-------------------------------------------------------------------
void Init_MCU(void)
{
	__DI();
	/* WDT */
	wdt_init( WDT_WINDOW_100, WDT_500MS );

	Init_Port();
	InitSystemClock();

	Init_Timer0();

	__EI();
}
//-------------------------------------------------------------------


