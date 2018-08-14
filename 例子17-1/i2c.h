#ifndef __i2c_library
#define __i2c_library

#include "reg51.h"
#include "intrins.h"

sfr AUXR      = 0x8E;
sfr AUXR1     = 0xA2;
sfr P_SW2     = 0xba;

#define  TIMS  0

#define I2CCFG    (*(unsigned char volatile xdata *)0xfe80)
#define I2CMSCR   (*(unsigned char volatile xdata *)0xfe81)
#define I2CMSST   (*(unsigned char volatile xdata *)0xfe82)
#define I2CSLCR   (*(unsigned char volatile xdata *)0xfe83)
#define I2CSLST   (*(unsigned char volatile xdata *)0xfe84)
#define I2CSLADR  (*(unsigned char volatile xdata *)0xfe85)
#define I2CTXD    (*(unsigned char volatile xdata *)0xfe86)
#define I2CRXD    (*(unsigned char volatile xdata *)0xfe87)

void ini_timer0(void);
void ini_i2c(void);	
void Start(void);
void SendData(char dat);
void RecvACK(void);
char RecvData(void);
void SendACK(void);
void SendNAK(void);
void Stop(void);
void Delay(void);
void slv_addr(void);	
void slv_cmd(char cmd);
void slv_dat(char dat);
void config_port(char cmd,char dat1,char dat2); 
void write_port(char cmd,char dat1,char dat2);
#endif