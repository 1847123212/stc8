#include "i2c.h"

extern bit busy;
void ini_timer0(void)
{
	TL0=TIMS;
	TH0=TIMS>>8;
	AUXR&=0x3F;
	TMOD=0x00;
	TR0=1;
	ET0=1;
}

void ini_i2c(void)
{
	P_SW2=0x80;
	I2CCFG=0xc8;
	I2CMSST=0x00;
	I2CMSCR=0x80;
	EA=1;
}

void Start(void)
{
	busy=1;
	I2CMSCR=0x81;
	while(busy);
	
}

void SendData(char dat)
{
	I2CTXD=dat;
	busy=1;
	I2CMSCR=0x82;
	while(busy);
}

void RecvACK(void)
{
	busy=1;
	I2CMSCR=0x83;
	while(busy);
}

/* char RecvData(void)
{
	busy=1;
	I2CMSCR=0x84;
	while(busy);
	return I2CRXD;
}

void SendACK(void)
{
	I2CMSST=0x00;
	busy=1;
	I2CMSCR=0x85;
	while(busy);
}

void SendNAK(void)
{
	I2CMSST=0x01;
	busy=1;
	I2CMSCR=0x85;
	while(busy);
} 
*/
 void Delay(void)
{
	long int i;
	for(i=0;i<300;i++)
	{
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}

void Stop(void)
{
	busy=1;
	I2CMSCR=0x86;
	while(busy);
}

void slv_addr(void)
{
	Start();
	SendData(0x40);
	RecvACK();
}

void slv_cmd(char cmd)
{
  SendData(cmd);
	RecvACK();
}
void slv_dat(char dat)
{
	SendData(dat);
	RecvACK();
}

void config_port(char cmd,char dat1,char dat2)
{

	slv_addr();
	slv_cmd(cmd);
	slv_dat(dat1);
	slv_dat(dat2);
	Stop();
}
void write_port(char cmd,char dat1,char dat2)
{

	slv_addr();
	slv_cmd(cmd);
	slv_dat(dat1);
	slv_dat(dat2);
	Stop();
}
