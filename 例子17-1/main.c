#include "i2c.h"
xdata unsigned char  seg[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
xdata unsigned char  com[8]={0xef,0xdf,0xbf,0x7f,0xfe,0xfd,0xfb,0xf7};
bit busy=0;
char counter=0;
char m=0;
void timer_0() interrupt 1
{
	counter++;
	if(counter==5)
	{
	   m++;
		 counter=0;
	}
	if(m==16) m=0;
}
void I2C_ISR() interrupt 24 using 0
{
	_push_(P_SW2);
	P_SW2|=0x80;
	if(I2CMSST & 0x40)
	{
		I2CMSST &=0xBF;
		busy=0;
	}
	_pop_(P_SW2);
}

void main()
{
	long int i=0,j=0,k=0;
	ini_timer0();
	ini_i2c();
	
	config_port(0x06,0x00,0x00);
	Delay();
	while(1)
	{   
    	for(i=0;i<8;i++)
	   {
	     write_port(0x02,com[i],seg[(i+m)%16]);
	     Delay();
	   }
   }
	while(1);
}