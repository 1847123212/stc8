#include "reg51.h"                                     
#define CKSEL     (*(unsigned char volatile xdata *)0xFE00)  
#define IRC32KCR  (*(unsigned char volatile xdata *)0xFE04) 
sfr P_SW2=0xba;

void main()
{
P_SW2=0x80; 
IRC32KCR=0x80;
while(!(IRC32KCR & 1));
CKSEL=0x13;    
P_SW2=0x00;    
while(1);         
}
