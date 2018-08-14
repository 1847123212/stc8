#include "reg51.h"
#define TIMS 3036
#define CLKDIV (*(unsigned char volatile xdata *)0xfe01) 
sfr AUXR  =0x8E;
sfr AUXR2 =0x8F;
sfr P6=0xE8;
sfr P_SW2= 0xba;
void timer_0() interrupt 1
{
	P6=~P6;
}
main()
{
	P_SW2=0x80;
	CLKDIV=0x10;
	P_SW2=0x00;
	TL0=TIMS;
	TH0=TIMS>>8;
	AUXR&=0x7F;
	AUXR2|=0x01;
	TMOD=0x00;
	P6=0;
	TR0=1;
	ET0=1;
	EA=1;
	while(1);
}