#include "reg51.h"
sfr  WDT_CONTR=0xc1;
sfr  P6=0xe8;

void main()
{
	long unsigned int j;
	char c=0x10;
	  P6=0x00;
	  for(j=0;j<99999;j++);
	  P6=0xFF;
	  while(1)
			WDT_CONTR|=c;
}