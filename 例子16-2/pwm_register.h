#ifndef _PWM_REGISTER
#define _PWM_REGISTER

#include "reg51.h"
#include "intrins.h"


sfr	P_SW2	=	0xba;
sfr	PWMCFG	=	0xf1;
sfr	PWMIF	=	0xf6;
sfr	PWMFDCR	=	0xf7;
sfr	PWMCR	=	0xfe;

#define	PWMC		(*(unsigned int volatile xdata *)0xfff0)
#define	PWMCKS		(*(unsigned char volatile xdata *)0xfff2)
#define	TADCP		(*(unsigned int volatile xdata *)0xfff3)
#define	PWM0T1		(*(unsigned int volatile xdata *)0xff00)
#define	PWM0T2		(*(unsigned int volatile xdata *)0xff02)
#define	PWM0CR		(*(unsigned char volatile xdata *)0xff04)
#define	PWM0HLD		(*(unsigned char volatile xdata *)0xff05)
#define	PWM1T1		(*(unsigned int volatile xdata *)0xff10)
#define	PWM1T2		(*(unsigned int volatile xdata *)0xff12)
#define	PWM1CR		(*(unsigned char volatile xdata *)0xff14)
#define	PWM1HLD		(*(unsigned char volatile xdata *)0xff15)
#define	PWM2T1		(*(unsigned int volatile xdata *)0xff20)
#define	PWM2T2		(*(unsigned int volatile xdata *)0xff22)
#define	PWM2CR		(*(unsigned char volatile xdata *)0xff24)
#define	PWM2HLD		(*(unsigned char volatile xdata *)0xff25)
#define	PWM3T1		(*(unsigned int volatile xdata *)0xff30)
#define	PWM3T2		(*(unsigned int volatile xdata *)0xff32)
#define	PWM3CR		(*(unsigned char volatile xdata *)0xff34)
#define	PWM3HLD		(*(unsigned char volatile xdata *)0xff35)
#define	PWM4T1		(*(unsigned int volatile xdata *)0xff40)
#define	PWM4T2		(*(unsigned int volatile xdata *)0xff42)
#define	PWM4CR		(*(unsigned char volatile xdata *)0xff44)
#define	PWM4HLD		(*(unsigned char volatile xdata *)0xff45)
#define	PWM5T1		(*(unsigned int volatile xdata *)0xff50)
#define	PWM5T2		(*(unsigned int volatile xdata *)0xff52)
#define	PWM5CR		(*(unsigned char volatile xdata *)0xff54)
#define	PWM5HLD		(*(unsigned char volatile xdata *)0xff55)
#define	PWM6T1		(*(unsigned int volatile xdata *)0xff60)
#define	PWM6T2		(*(unsigned int volatile xdata *)0xff62)
#define	PWM6CR		(*(unsigned char volatile xdata *)0xff64)
#define	PWM6HLD		(*(unsigned char volatile xdata *)0xff65)
#define	PWM7T1		(*(unsigned int volatile xdata *)0xff70)
#define	PWM7T2		(*(unsigned int volatile xdata *)0xff72)
#define	PWM7CR		(*(unsigned char volatile xdata *)0xff74)
#define	PWM7HLD		(*(unsigned char volatile xdata *)0xff75)
	
void set_pwm0_T1_T2_point(unsigned int h,unsigned l);
void set_pwm1_T1_T2_point(unsigned int h,unsigned l);
void enable_xsfr(void);
void disable_xsfr(void);
void pwm_clock_speed(unsigned char a);
void set_pwm_period(unsigned int a);
void enable_pwm0(void);
void enable_pwm1(void);
void enable_pwm(void);
#endif 
