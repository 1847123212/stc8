#include "reg51.h"
#define TIMS 3036
#define CLKDIV (*(unsigned char volatile xdata *)0xfe01) 
sfr IE2 =0xAF;
sfr TH3 =0xD4;
sfr TL3 =0xD5;
sfr T4T3M =0xD1;
sfr P6=0xE8;
sfr P_SW2=0xba;
void timer_3() interrupt 19
{
	P6=~P6;
}
main()
{
	P_SW2=0x80;
	CLKDIV=0x10;
	P_SW2=0x00;
	TL3=TIMS;
	TH3=TIMS>>8;
	T4T3M=0x08;
	P6=0;
	IE2|=0x20;
	EA=1;
	while(1);
}