#include "ccp.h"

void PCA_int() interrupt 7 using 1
{
	CCF0=0;
	CL=0;
	CH=0;
	P6=~P6;
}

void main()
{
	P_SW2=0x80;                
  CLKDIV=255;              
  P_SW2=0x00;               
	P6=0;
	P_SW1=0x20;
	CCON=0;
	CL=0;
	CH=0;
	CMOD=0x00;
	CCAP0L=value;
	CCAP0H=value>>8;
	CCAPM0=0x4d;
	CR=1;
	EA=1;
	while(1);
}