#include "pwm_register.h"

void main()
{
	enable_xsfr();
	pwm_clock_speed(0xf);
  set_pwm_period(0xBFF);
	set_pwm1_T1_T2_point(0xB7F,0x8FF);
	set_pwm3_T1_T2_point(0x27F,0xBFF);
	set_pwm5_T1_T2_point(0x57F,0x2FF);
	set_pwm7_T1_T2_point(0x87F,0x5FF);
	enable_pwm1();
	enable_pwm3();
	enable_pwm5();
	enable_pwm7();
	disable_xsfr();
  enable_pwm();
	while (1);
}
