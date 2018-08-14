#include "reg51.h"

sfr P6=0xE8;
int i=0xFF;

servivce_int0() interrupt 0
{
	 i--;
	 P6=i;
}

servivce_int1() interrupt 2
{
	 i++;
	 P6=i;
}

void main()
{
	IT0=1;
	EX0=1;
	IT1=1;
	EX1=1;
	EA=1;
	P6=0xFF;
  while(1);
}