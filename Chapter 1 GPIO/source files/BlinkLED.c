/*
 * BlinkLED.c
 *
 *  Created on: 1 ¡.¾. 2563
 *      Author: pichet
 */

//----------------------------------------------------------------------
#include <ml621367.h>

#include "wdt.h"
#include "SysDefine.h"
#include "SysFlag.h"
#include "Timer0.h"
#include "time_delay.h"


//----------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
void Init_LED(void)
{
	P21DO=1;	// Output = 0
	P21IE=0;P21OE=1;P21OD=0;P21PU=0;	// Disable input, Enable output, CMOS output, No pull
	P21MD3=0;P21MD2=0;P21MD1=0;P21MD0=0;	// Primary function

	P20DO=1;	// Output = 0
	P20IE=0;P20OE=1;P20OD=0;P20PU=0;	// Disable input, Enable output, CMOS output, No pull
	P20MD3=0;P20MD2=0;P20MD1=0;P20MD0=0;	// Primary function
}
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------

void LEDon(void)
{
	LED_Out=0;
	P20DO=0;
}
void LEDoff(void)
{
	LED_Out=1;
	P20DO=1;
}


void Display(void)
{
	Delay();
	if(Flag._TimerLED==1)
	{
		 LEDon();
		 Flag._TimerLED=0;

	}
	else{LEDon();}
}

//---------------------------------------------------------------------------------------------






