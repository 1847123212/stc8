#ifndef __CPU_BSP_H__
#define __CPU_BSP_H__

////////////////////////////
//总头文件
#include "..\APP\includes.h"


/////////////////////////////////
//LED管脚预定义
#define     LED1    P60
#define     LED2    P61
#define     LED3    P62
#define     LED4    P63
#define     LED5    P64
#define     LED6    P65
#define     LED7    P66
#define     LED8    P67
#define     LED     P6
#define     SW1     P32  
#define     SW2     P33   

extern void bsp(void) reentrant;

#endif
