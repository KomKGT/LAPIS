/*
 * time_delay.c
 *
 *  Created on: 20 ¡.¾. 2563
 *      Author: pichet
 */
#include "SysFlag.h"
#include "time_delay.h"


void Delay(void)
{
	static unsigned int Time_Count=0;

	Time_Count++;
		if(Time_Count >= 400) //400*4 mS = 1.6 S  //40*4 mS = 160 mS
		{
			Time_Count = 0;
			Flag._TimerLED=1;
		}

}
