#include "reg51.h"
#define TIMS 3036
#define CLKDIV (*(unsigned char volatile xdata *)0xfe01) 
sfr AUXR  =0x8E;
sfr IE2 =0xAF;
sfr TH2 =0xD6;
sfr TL2 =0xD7;
sfr P6  =0xE8;
sfr P_SW2=0xba;
void timer_2() interrupt 12
{
	P6=~P6;
}
main()
{
	P_SW2=0x80;
	CLKDIV=0x10;
	P_SW2=0x00;
	TL2=TIMS;
	TH2=TIMS>>8;
	AUXR|=0x10;
	P6=0;
	IE2|=0x04;
	EA=1;
	while(1);
}