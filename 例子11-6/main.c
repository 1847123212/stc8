#include "reg51.h"
#include "intrins.h"
sfr WKTCL=0xAA;
sfr WKTCH=0xAB;
sfr P6=0xE8;

void main()
{
  WKTCL=255;
  WKTCH=0x80;
  P6=0x00;
  while(1)
	{		
    P6=~P6;
    PCON|=0x02; 
		 _nop_();
		 _nop_();

	}		
}
