#include "reg51.h"
sfr P2M0=0x96;
sfr P2M1=0x95;

unsigned char Step_table[]={0x80,0x20,0x08,0x02};
void delay(unsigned int a)
{
 while(a--);
}
void main()
{
	 unsigned char i;
	 P2M0=0;
	 P2M1=0;
   while(1)
   {
   for(i=0;i<4;i++)
      {
        P2=Step_table[i];
        delay(2000);
      }
   }
}
