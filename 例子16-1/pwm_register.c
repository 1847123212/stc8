#include "pwm_register.h"

void enable_xsfr(void)
{
	P_SW2 = 0x80;
}

void pwm_clock_speed(unsigned char a)
{
  PWMCKS |=a;	
}

void set_pwm_period(unsigned int a)
{
		PWMC = a;	
}

void set_pwm0_T1_T2_point(unsigned int h,unsigned l)
{
	PWM0T1=h;	
	PWM0T2=l;	
}

void enable_pwm0(void)
{
  PWM0CR= 0x80;	
}	

void enable_pwm(void)
{
  PWMCR= 0x80;	
}	

void disable_xsfr(void)
{
	P_SW2 = 0x00;
}


