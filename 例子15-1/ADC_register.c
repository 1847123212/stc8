#include "ADC_register.h"
void set_P1_drive_mode(u8 a,u8 b)
{
  P1M0=a;
	P1M1=b;
}
void set_timer_2_ini_value(u16 a)
{
  T2L=a-OSC/4/BAUD;
	T2H=(a-OSC/4/BAUD)>>8;
}

void SendData(u8 dat)
{
	while(!TI);
	TI=0;
	SBUF=dat;
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
	u16 i;
	for(i=0;i<10000;i++)
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

void set_uart_mode(void)
{
	SCON=0x5A;
	AUXR=0x14;
	AUXR|=0x01;
}
float get_voltage_value(void)
{
	u16 tmp=0;
	float value;
	tmp=(ADC_RES*256+ADC_RESL);
	value=(tmp*2.5)/4096;
	return value;
}