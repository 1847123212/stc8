#include "reg51.h"
sfr P4M0=0xB4;
sfr P4M1=0xB3;
sfr P4=0xC0;
sfr P6=0xe8;
void main()
{
	long int i=0;
	P4M0=1;
	P4M1=1;
 while(1)
 {
	P6=0x00;
	P4=0x00;
	for(i=0;i<32768;i++);
	P6=0xFF;
	P4=0xFF;
	 for(i=0;i<32768;i++);
 }
}
