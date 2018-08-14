#ifndef _ADC_REGISTER
#define _ADC_REGISTER

#include "stdio.h"
#include "reg51.h"
#include "intrins.h"
#define  u8   unsigned char
#define  u16  unsigned int
#define  EN_ADC_INT  EADC=1
#define  EN_GOL_INT  EA=1

#define OSC           18432000L
#define BAUD          9600
#define URMD          0


sfr P1M0      =0x92;
sfr P1M1      =0x91;
sfr T2H       =0xD6;
sfr T2L       =0xD7;
sfr AUXR      =0x8E;
sfr ADC_CONTR =0xBC;
sfr ADC_RES   =0xBD;
sfr ADC_RESL  =0xBE;
sfr ADCCFG    =0xDE;
sbit EADC     =IE^5;

void set_P1_drive_mode(u8 a,u8 b);
void set_timer_2_ini_value(u16 a);
void SendData(u8 dat);
void clear_adc_result(void);
void adc_power_on(void);
void adc_start(void);
void delay(void);
void set_adc_channel(u8 ch);
void set_adc_result_format(u8 a);
void set_adc_conv_speed(u8 a);
void set_uart_mode(void);
float get_voltage_value(void);
#endif