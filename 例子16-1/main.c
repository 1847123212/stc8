#include "pwm_register.h"

void main()
{
	enable_xsfr();
	pwm_clock_speed(0);
  set_pwm_period(0x1000);
	set_pwm0_T1_T2_point(0x200,0x700);
	enable_pwm0();
	disable_xsfr();
  enable_pwm();
	while (1);
}
