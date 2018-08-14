#ifndef _REGISTER_
#define _REGISTER_

#include "reg51.h"
#include "intrins.h"
#define FOSC  6000000L
#define BAUD 115200
#define u8 unsigned char
#define u16 unsigned int

sfr AUXR  =0x8E;
sfr AUXR1 =0xA2;
sfr INT_CLKO =0x8F;
sfr TH2   =0xD6;
sfr TL2   =0xD7;
sfr P3M1  =0xB1;
sfr P3M0  =0xB2;
sbit P36  =P3^6;

bit busy=0;
u8 irdata[4]={0,0,0,0};	
bit flag=0;
#endif