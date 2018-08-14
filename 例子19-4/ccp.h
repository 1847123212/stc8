#ifndef _CCP_
#define _CCP_

#include "reg51.h"
#define value 3906
sfr P_SW1    =0xA2;
sfr CCON     =0xD8;
sfr CMOD     =0xD9;
sfr CL       =0xE9;
sfr CH       =0xF9;
sfr CCAPM0   =0xDA;
sfr CCAP0L   =0xEA;
sfr CCAP0H   =0xFA;
sfr PCA_PWM0 =0xf2;
sbit CCF0    =CCON^0;
sbit CCF1    =CCON^1;
sbit CR      =CCON^6;
sbit CF      =CCON^7;

#endif