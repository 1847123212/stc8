#include "led1602.h"

void delay(void)
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}	
void lcdwait()
{
	LCD1602_DB=0xFF;
	delay();
	LCD1602_RS=0;
	LCD1602_RW=1;
	LCD1602_E=1;
	while(LCD1602_DB & 0x80);
  LCD1602_E=0;
}

void lcdwritecmd(unsigned char cmd)
{
	lcdwait();
	delay();
	LCD1602_RS=0;
	LCD1602_RW=0;
	LCD1602_DB=cmd;
	LCD1602_E=1;
	delay();
	LCD1602_E=0;
}

void lcdwritedata(unsigned char dat)
{
	lcdwait();
  delay();
	LCD1602_RS=1;
	LCD1602_RW=0;
	LCD1602_DB=dat;
	LCD1602_E=1;
	delay();
	LCD1602_E=0;
}

void lcdinit()
{
	lcdwritecmd(0x38);
	lcdwritecmd(0x0c);
	lcdwritecmd(0x06);
	lcdwritecmd(0x01);
}

void lcdsetcursor(unsigned char x, unsigned char y)
{
	unsigned char address;
	if(y==0)
		address=0x00+x;
	else
		address=0x40+x;
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

void set_P0_mode(u8 a,u8 b)
{
	 P0M0=a;
	 P0M1=b;
}
void set_P2_mode(u8 a,u8 b)
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

float get_voltage_value(void)
{
	u16 tmp=0;
	float value;
	tmp=(ADC_RES*256+ADC_RESL);
	value=(tmp*2.5)/4096;
	return value;
}