#include "reg51.h"
#define FOSC  18432000L
#define BAUD 115200
sfr AUXR  =0x8E;
sfr TH2   =0xD6;
sfr TL2   =0xD7;
sfr P6    =0xE8;
sbit P60   =P6^0;
sbit P61   =P6^1;
sbit P62   =P6^2;
sbit P63   =P6^3;
sbit P64   =P6^4;
sbit P65   =P6^5;
sbit P66   =P6^6;
sbit P67   =P6^7;

bit busy=0;
xdata char menu[]={"\r\n------main menu---------------"
	                 "\r\n     input 0:  Control LED0 "
                   "\r\n     input 1:  Control LED1 "
                   "\r\n     input 2:  Control LED2 "
                   "\r\n     input 3:  Control LED3 "
	                 "\r\n     input 4:  Control LED4 "
	                 "\r\n     input 5:  Control LED5 "
	                 "\r\n     input 6:  Control LED6 "
	                 "\r\n     input 7:  Control LED7 "
	                 "\r\n     other  :  Exit Program"
	                 "\r\n------end menu----------------"
            };
	
void SendData(unsigned char dat)
{
	while(busy);
	SBUF=dat;
	busy=1;
}
void SendString(char *s)
{
	while(*s!='\0')
		SendData(*s++);
}
void uart1() interrupt 4
{
	if(RI)
		RI=0;
	if(TI)
		TI=0;
	  busy=0;
}
		
void main()
{
	unsigned char c;
	P6=0;
	SCON=0x50;
	AUXR=0x14;
	AUXR|=0x01;
	TL2=(65536-((FOSC/4)/BAUD));
	TH2=(65536-((FOSC/4)/BAUD))>>8;
	ES=1;
	EA=1;
	 SendString(&menu);
	 while(1){
		 if(RI==1)
		 {
			 c=SBUF;
			 if(c==0x30)
				   P60=!P60;
			 else if(c==0x31)
				   P61=!P61;
			 else if(c==0x32)
				   P62=!P62;
			 else if(c==0x33)
				   P63=!P63;
			 else if(c==0x34)
				   P64=!P64;
			 else if(c==0x35)
				   P65=!P65;
			 else if(c==0x36)
				   P66=!P66;
			 else if(c==0x37)
				   P67=!P67;
			 else 
			 {
				   SendString("\r\n Exit Program");
			 }
		 }    
	 }
}
	