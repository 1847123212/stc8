#include "led1602.h"

bit flag=1;
float voltage=0;
unsigned char tstr[5];
void adc_int() interrupt 5
{
	ADC_CONTR &=~0x20;
	voltage=get_voltage_value();
	sprintf(tstr,"%1.4f",voltage);
	flag=1;
	adc_start();
}

void main()
{
  set_P0_mode(0x00,0x00);
	set_P2_mode(0x00,0x00);
  clear_adc_result();
	set_adc_result_format(1);
	set_adc_conv_speed(0xf);
	EN_ADC_INT;
	EN_GOL_INT;
	lcdwait();
	lcdinit();
	adc_power_on();
	delay();
	set_adc_channel(1);
	adc_start();
	lcdshowstr(0,0,"Measured Voltage is");
	lcdshowstr(6,1,"V");
	while(1)
		{ 
			if(flag==1)
			{
				flag=0;
	      lcdshowstr(0,1,tstr);
			}
		}
}
