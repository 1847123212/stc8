#include "ccp.h"

void PCA_int() interrupt 7 using 1
{
	CCF0=0;
	P6=~P6;
}

void main()
{
	P6=0x00;
  P_SW1=0x20;
  CCON=0;
  CL=0;
	CH=0;
	CMOD=0x08;
	CCAPM0=0x11;
	CR=1;
	EA=1;
	while(1);
} 
