#include "reg51.h"
sfr P6=0xE8;

void wakeup() interrupt 0
{
}
void main()
{
  long int j;
	IT0=1;                        
	EX0=1;                        
	EA=1;  
  while(1)
	{		
    P6=0x00;
    for(j=0;j<222222;j++);
    PCON|=0x01;
    P6=0xFF;
    for(j=0;j<222222;j++);  
	}		
}
