#include "register.h"


void SendData(u8 dat)
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

u16 high_level_time()
{
	TL0=0;
	TH0=0;
	TR0=1;
	while(P36==1)
	{
		if(TH0>=0xEE)
			 break;
	}
	TR0=0;
	return(TH0*256+TL0);
}
u16 low_level_time()
{
	TL0=0;
	TH0=0;
	TR0=1;
	while(P36==0)
	{
		if(TH0>=0xEE)
			 break;
	}
	TR0=0;
	return(TH0*256+TL0);
}
void int2() interrupt 10
{
	u8 i,j;
	u16 count=0;
	u8 dat=0;
	
	INT_CLKO&=0x00;
	count=low_level_time();
	
	if(count<4000 || count>5000)
	{
	   return;
	}
	count=high_level_time();
	if(count<2000 || count>2500)
	{
     return;
	}
	
	for(i=0;i<4;i++)
	{ 
   P36=1;
		dat=0;
	   for(j=0;j<8;j++)
		  {
		     count=low_level_time();
				 if(count<250 || count>300) 
            return;
			   count=high_level_time(); 
				 if(count>250 && count<300)
					  dat>>=1;
				 else if(count>800 && count<1000)
				 {
					 dat>>=1;
					 dat|=0x80;
				 }
				 else return;
				
				 
			 }
			 irdata[i]=dat; 	
	 }
	  flag=1;   
	 INT_CLKO|=0x10;
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
	u8 k;
	P36=1;
	P3M1=0x00;
	P3M0=0x00;
	TMOD=0x00;
	SCON=0x50;
	AUXR=0x14;
	AUXR|=0x01;
	INT_CLKO|=0x10;
	TL2=(65536-((FOSC/4)/BAUD));
	TH2=(65536-((FOSC/4)/BAUD))>>8;
  ES=1;
	EA=1;
	SendString("\r\n--begin-----\r\n");
	 while(1)
		{
		 if(flag==1)
		 {
			   flag=0;
			    SendString("\r\n--Received IR data is-----\r\n");
			 for(k=0;k<4;k++)
			   SendData(irdata[k]);
			   SendString("\r\n");
			   INT_CLKO|=0x10;
      }
	 }
 }	