#include "reg51.h"

sfr P6=0xE8;
sfr IPH=0xB7;
unsigned char i=0xFF;
bit busy=1;

servivce_int0() interrupt 0
{
	 busy=0;
}

servivce_int1() interrupt 2
{
	 IT1=0;
	 while(busy);
	 busy=1;
	 i--;
	 P6=i;
	 IT1=1;
}

void main()
{
	IP=0x01;
	IPH=0x01;
	IT0=1;
	EX0=1;
	IT1=1;
	EX1=1;
	EA=1;
	P6=0xFF;
  while(1);
}