#include "reg51.h"
sfr  IAP_CONTR=0xc7;
sfr  P6=0xE8;

void main()
{
	long unsigned int j;
	  P6=0x00;
	  for(j=0;j<999999;j++);
	  P6=0xFF;
	  for(j=0;j<999999;j++);
	  P6=0x00;
	  for(j=0;j<999999;j++);
	  IAP_CONTR=0x60;
}