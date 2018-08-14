#include "pwm_register.h"

void main()
{
	enable_xsfr();
	pwm_clock_speed(0);
  set_pwm_period(0x800);
	set_pwm0_T1_T2_point(0x100,0x700);
	set_pwm1_T1_T2_point(0x780,0x80);
	enable_pwm0();
	enable_pwm1();
	disable_xsfr();
  enable_pwm();
	while (1);
}
