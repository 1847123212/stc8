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

void set_pwm1_T1_T2_point(unsigned int h,unsigned l)
{
	PWM1T1=h;	
	PWM1T2=l;	
}

void set_pwm3_T1_T2_point(unsigned int h,unsigned l)
{
	PWM3T1=h;	
	PWM3T2=l;	
}

void set_pwm5_T1_T2_point(unsigned int h,unsigned l)
{
	PWM5T1=h;	
	PWM5T2=l;	
}
void set_pwm7_T1_T2_point(unsigned int h,unsigned l)
{
	PWM7T1=h;	
	PWM7T2=l;	
}

void enable_pwm1(void)
{
  PWM1CR= 0x80;	
}	

void enable_pwm3(void)
{
  PWM3CR= 0x80;	
}	

void enable_pwm5(void)
{
  PWM5CR= 0x80;	
}	

void enable_pwm7(void)
{
  PWM7CR= 0x80;	
}	


void enable_pwm(void)
{
  PWMCR= 0x80;	
}	

void pwm_ini_voltage()
{
	
}
void disable_xsfr(void)
{
	P_SW2 = 0x00;
}


