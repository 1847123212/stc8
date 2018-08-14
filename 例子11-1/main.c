#include "reg51.h"

#define CLKSEL  (*(unsigned char volatile xdata *)0xFE00)

sfr P_SW2=0xba;

void main()
{
	P_SW2=0x80;
	CLKSEL=0xE0;
	P_SW2=0x00;
	while(1);
}