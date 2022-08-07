//-----------------------------------------------------
#include <ml621367.h>

#include "wdt.h"
#include "SysDefine.h"
#include "BlinkLED.h"
#include "SysFlag.h"
#include "time_delay.h"

//-----------------------------------------------------
unsigned char Msec=0,Sec=0,Min=0,Hour=0;
unsigned int counttest=0;
unsigned int t_cnt=0;
unsigned int CountmSec=0;

unsigned int BuzzCount=0;

//*******************************************************************************//
//                                    Timer 0                                    //
//*******************************************************************************//
void Init_Timer0(void)
{
	//******************************* Initial Timer0 *********************************
	//		TH0CS = 1  Choose the timer clock of the 16-bit timer n
	//				   Choose HSCLK
	//		TH0EX = 0  The timer is counted by the clock chosen by the THnCS bit and
	//				   divided by the ratio chosen by the THnDIV2 to 0 bit
	//		TH0EXS = 0 Choose EXTRG0 For external trigger supplied as Count Clock in External Interrupt Function
	//		TH0DIV2=0 TH0DIV1=0 TH0DIV0=0 No dividing ratio for the count clock in the 16-bit timer
	//									  Count clock = HSCLK = 24 MHz
	//		TH08BM = 0 Choose 16-bit timer mode
	//		TH0OST = 0 Operation mode of the 16-bit timer -> Repeat timer mode
	//		TH0NEG = 0 Choose Positive Logic for output polarity of timer out (TMHnOUT)
	//		TMH0D = 5999 Comparison value with the 16-bit timer
	//					 TMH0D count to 5999
	//		timer interrupt request cycle = TMH0D + 1/HSCLK
	//		timer interrupt request Frequency = HSCLK/TMH0D + 1 = 24MHz/5999 + 1 = 4,000 Hz
	//		***16-bit timer n interrupt request  Frequency = 4 kHz
	//********************************************************************************

	TH0CS=1;
	TH0EX=0;

	TH0EXS=0;
	TH0DIV2=0;TH0DIV1=0;TH0DIV0=0;

	TH08BM = 0;
	TH0OST = 0;
	TH0NEG = 0;

	TMH0D = 5999;

	ETM0 = 1;      	// Timer 0 interrupt enable
	TH0RUN = 1;		// Start Counting
}
//*******************************************************************************//
//                                Timer Service                                  //
//*******************************************************************************//
void Timer0_Interrupt(void)
{

	static unsigned char tick_cnt=0;
	static unsigned int t_base_cnt=0;
	//-------------------------------------
	//4000 kHz -> 0.25 mS
	//count to 16 -> (4000 Hz/16) = 250 Hz
	//250 Hz -> 4 mS
	if(++tick_cnt >= 16)	// Count for 250Hz (4000Hz/250Hz = 16)
	{
		tick_cnt = 0;
		Flag._ScanTime=1;
	}

	//------ only test ----------------
	//
	t_base_cnt++;
	if(t_base_cnt >= (4000))
	//if(t_base_cnt >= 4000)		
		t_base_cnt = 0;

	//Delay();
}
//--------------------------------------------------------------
void RealTimeClock(void)
{
	if(++Msec >= SecCountValue) //SecCountValue = 250
	{
		Msec=0;
		if(++Sec >= 60)
		{
			Sec=0;
			if(++Min >= 60)
			{
				Min=0;
				Hour = ++Hour%24;
			}
		}
	} 
}
//--------------------------------------------------------------




