
//-------------------------------------------------------------------------

#include <ml621367.h>

//-------------------------------------------------------------------------
void Set_VLS_Startup(void)
{
	unsigned int i;

	VLS0EN = 0;		// Disable VLS(Voltage Level Supervisor)
	
	VLS0AMD1=1;VLS0AMD0=0;	// Supervisor mode
	VLS0SEL1=0;VLS0SEL0=0;  // No reset, no interrupt
	VLS0SM1=0;VLS0SM0=0;	// Without sampling 
	VLS0DIV2=0;VLS0DIV1=0;VLS0DIV0=0;	// No clock division
	VLS0LV3=1;VLS0LV2=0;VLS0LV1=1;VLS0LV0=1;	// Threshold = 1.85 V

	VLS0EN = 1;		// Enable VLS(Voltage Level Supervisor)		
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	
	while(VLS0RF==0)
		wdt_clear();

	for(i=0;i<200;i++)
		;
	while(VLS0F==1)
		wdt_clear();
}
//-------------------------------------------------------------------------
void Set_VLS_Monitoring(void)
{
	unsigned int i;

	VLS0EN = 0;		// Disable VLS(Voltage Level Supervisor)

	VLS0AMD1=1;VLS0AMD0=0;	// Supervisor mode
	VLS0SEL1=0;VLS0SEL0=0;  // No reset, no interrupt
	VLS0SM1=0;VLS0SM0=0;	// Without sampling 
	VLS0DIV2=0;VLS0DIV1=0;VLS0DIV0=0;	// No clock division
	VLS0LV3=1;VLS0LV2=0;VLS0LV1=0;VLS0LV0=0;	// Threshold = 2.45 V

	VLS0EN = 1;		// Enable VLS(Voltage Level Supervisor)		
}
//------------------------------------------------------------------------



