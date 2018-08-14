#include "12864.h"

bit flag=1;
unsigned char max_tstr[10],min_tstr[10],avg_tstr[10];
unsigned int tmp=0;
xdata unsigned char value[128];
unsigned int max_value=0 ,min_value=1024,avg_value=10;
unsigned char inc=0;
void adc_int() interrupt 5
{
	ADC_CONTR &=~0x20;
	tmp=(ADC_RES*256+ADC_RESL);
  if(inc!=128 && flag==0)
	{
	  	value[inc]=tmp/64;
	  	if(tmp>max_value)
			      max_value=tmp;
		  if(tmp<min_value)
			     min_value=tmp;
		   inc++;
	}
	else
	{
		    inc=0;
		    flag=1;
	}
	   adc_start();
}

void main()
{
	long unsigned int i;
	set_P0_drive_mode(0x00,0x00);
	set_P2_drive_mode(0x00,0x00);
	LCD12864_RST=1;
	clear_adc_result();
	set_adc_result_format(1);
	set_adc_conv_speed(0xf);
	EN_ADC_INT;
	EN_GOL_INT;
	adc_power_on();
	delay();
	set_adc_channel(1);
	adc_start();
  lcdinit();
	lcdshowstr(0,0,"测量交流信号");
	for(i=0;i<600000;i++);
	lcdwritecmd(0x01);
		while(1)
		{ 
		if(flag==1)
			{
				  lcdinit();
				  sprintf(max_tstr,"%+1.4f",(max_value*2.5)/4096);
		      sprintf(min_tstr,"%+1.4f",(min_value*2.5)/4096);
				  sprintf(avg_tstr,"%+1.4f",((max_value-min_value)*2.5)/4096);
				  max_value=0;
		      min_value=4096;
				  lcdshowstr(0,1,"MAX: ");
	        lcdshowstr(2,1,max_tstr);
				  lcdshowstr(5,1," V");
				  lcdshowstr(0,2,"MIN: ");
	        lcdshowstr(2,2,min_tstr);
				  lcdshowstr(5,2," V");
				  lcdshowstr(0,3,"PTP: ");
				  lcdshowstr(2,3,avg_tstr);
				  lcdshowstr(5,3," V");
				  for(i=0;i<300000;i++);
        	lcdwritecmd(0x01);
          drawpoint(value); 
				flag=0;	
			}  
		} 
}
