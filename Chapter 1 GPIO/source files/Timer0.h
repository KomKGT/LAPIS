
extern unsigned char Msec,Sec,Min,Hour;

void Init_Timer0(void);
void Timer0_Interrupt(void);
void RealTimeClock(void);

void BuzzerControl(void);
extern unsigned int tm0Flag;
