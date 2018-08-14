#include "ccp.h"

unsigned char i=0;
void PCA_int() interrupt 7
{
	CF=0;
	CCAP0H=i;
	CCAP0L=i;
	if(i<255) i++;
  else i=0;		

}
void main()
{
	P_SW1=0x20;
	CCON=0;
	CL=0;
	CH=0;
	CMOD=0x03;
	PCA_PWM0=0x00;
	CCAP0L=0x10;
	CCAP0H=0x10;
	CCAPM0=0x42;
	CR=1;
	EA=1;
	while(1);
}