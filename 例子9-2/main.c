#include "reg51.h"
#include "intrins.h"

sfr P6=0xE8;
char control[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
void delay(long int m)
{
	long int n=0;
	for(n=0;n<m;n++)
   	_nop_();
}

void main()
{
	int i=0,j=0;
	while(1)
	{
	  for(i=0;i<10;i++)
   	{
	     P6=0xAA;
       delay(50000);
	     P6=0x55;
		   delay(50000);
	  }
		for(i=0;i<10;i++)
		{
			for(j=0;j<8;j++)
			  {
			   P6=control[j];
				 delay(50000);
				}
		}
		for(i=0;i<10;i++)
		{
			P6=0xFF;
		  delay(50000);
			P6=0x00;
		  delay(50000);
		} 
		for(i=0;i<1000;i++)
		{
			P6=0xFF;
		  delay(i);
			P6=0x00;
		  delay(1000-i);
		}
			for(i=0;i<1000;i++)
		{
			P6=0x00;
		  delay(i);
			P6=0xFF;
		  delay(1000-i);
		}
	}
			
}