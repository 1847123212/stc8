#ifndef _1602_
#define _1602_
#include "reg51.h"
#include "intrins.h"
#include "stdio.h"

#define u8  unsigned char
#define u16 unsigned int
#define  EN_ADC_INT  EADC=1
#define  EN_GOL_INT  EA=1

sbit LCD1602_RS=P2^5;
sbit LCD1602_RW=P2^6;
sbit LCD1602_E =P2^7;
sfr  LCD1602_DB=0x80;

sfr  P0M1=0x93;
sfr  P0M0=0x94;
sfr  P2M1=0x95;
sfr  P2M0=0x96;

sfr ADC_CONTR =0xBC;
sfr ADC_RES   =0xBD;
sfr ADC_RESL  =0xBE;
sfr ADCCFG    =0xDE;
sbit EADC     =IE^5;

void set_P0_mode(u8 a,u8 b);
void set_P2_mode(u8 a,u8 b);
void lcdwait();
void lcdwritecmd(unsigned char cmd);
void lcdwritedata(unsigned char dat);
void lcdinit();
void lcdsetcursor(unsigned char x, unsigned char y);
void lcdshowstr(unsigned char x, unsigned char y,
	              unsigned char *str);

void delay(void);
void clear_adc_result(void);
void adc_power_on(void);
void adc_start(void);
void set_adc_channel(u8 ch);
void set_adc_result_format(u8 a);
void set_adc_conv_speed(u8 a);
float get_voltage_value(void);

#endif