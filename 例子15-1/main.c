#include "ADC_register.h"

float voltage=0;
unsigned char tstr[5];
float old_voltage=0;

void adc_int() interrupt 5
{
	unsigned char i=0;
	ADC_CONTR &=~0x20;
  voltage=get_voltage_value();
	sprintf(tstr,"%1.4f",voltage);
	if(voltage!=old_voltage)
	{
	  old_voltage=voltage;
		SendData('\r');
	  SendData('\n');
	   for(i=0;i<5;i++)
	     SendData(tstr[i]);
	}
	adc_start();
}

void main()
{
  set_P1_drive_mode(0x00,0x01);
  set_timer_2_ini_value(65536);
	clear_adc_result();
	set_uart_mode();
	set_adc_result_format(1);
	set_adc_conv_speed(0xf);
	EN_ADC_INT;
	EN_GOL_INT;
	adc_power_on();
	delay();
	set_adc_channel(1);
	adc_start();
	while(1);
}
