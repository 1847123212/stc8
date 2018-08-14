#include "12864.h"

void set_P0_drive_mode(u8 a,u8 b)
{
  P0M0=a;
	P0M1=b;
}

void set_P2_drive_mode(u8 a,u8 b)
{
  P2M0=a;
	P2M1=b;
}

void clear_adc_result(void)
{
	ADC_RES=0x00;
	ADC_RESL=0x00;
}

void adc_power_on(void)
{
   ADC_CONTR=0x80;
}

void adc_start(void)
{
	ADC_CONTR|=0x40;
}

void delay(void)
{
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
}

void set_adc_channel(u8 ch)
{
		ADC_CONTR|=(ch & 0x0f);
}

void set_adc_result_format(u8 a)
{
	 if(a==0)
		  ADCCFG &=0xDF;
	 else
		  ADCCFG |=0x20;
}
void set_adc_conv_speed(u8 a)
{
	 ADCCFG |=(a &0xf);
}


void lcdwait()
{
	LCD12864_DB=0xFF;
  delay();
	LCD12864_RS=0;
	LCD12864_RW=1;
	LCD12864_E=1;
	while(LCD12864_DB & 0x80);
  LCD12864_E=0;
	delay();
}

void lcdwritecmd(unsigned char cmd)
{
	lcdwait();
	delay();
	LCD12864_RS=0;
	LCD12864_RW=0;
	LCD12864_DB=cmd;
	LCD12864_E=1;
	delay();
	LCD12864_E=0;
}

void lcdwritedata(unsigned char dat)
{
	lcdwait();
  delay();
	LCD12864_RS=1;
	LCD12864_RW=0;
	LCD12864_DB=dat;
	LCD12864_E=1;
	delay();
	LCD12864_E=0;
}

void lcdinit()
{
	lcdwritecmd(0x38);
	lcdwritecmd(0x06);
	lcdwritecmd(0x01);
	lcdwritecmd(0x0c);	
}

void lcdsetcursor(unsigned char x, unsigned char y)
{
	unsigned char address;
	if(y==0)
		address=0x80+x;
	else if(y==1)
		address=0x90+x;
	else if(y==2)
		address=0x88+x;
	else
		address=0x98+x;
	lcdwritecmd(address|0x80);
}

void lcdshowstr(unsigned char x, unsigned char y,
	              unsigned char *str)
{
	lcdsetcursor(x,y);
	while((*str)!='\0') 
	{
		 lcdwritedata(*str);
		 str++;
	}
}					
void drawpoint(unsigned char y[])
{
	unsigned char i,j,k;
	unsigned long int l;
	unsigned char x;
	xdata unsigned char pix[16][64];
	for(i=0;i<16;i++)
	  for(j=0;j<64;j++)
	         pix[i][j]=0;
			for(i=0;i<128;i++)
          pix[i/8][y[i]]=(0x80>>(i%8));	
	
			for(i=0,j=0;i<9;i+=8,j+=32)
	       {	
	        for(x=0;x<32;x++)
					  {			
		           lcdwritecmd(0x34);
		           lcdwritecmd(0x80+x);
		           lcdwritecmd(0x80+i);	
               lcdwritecmd(0x30);		
		          for(k=0;k<16;k++)	
		          	lcdwritedata(pix[k][x+j]);
	          }
	      }
       lcdwritecmd(0x36);	
			for(l=0;l<500000;l++);
}

	