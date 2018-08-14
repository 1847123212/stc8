
//////////////////////////////////////
//头文件
#include "includes.h"


////////////////////////////////////////////////////////////////////////
//功能说明
//P6.0 LED1
//P6.1 LED2
//P6.2 LED3
//P6.3 LED4
//P6.4 LED5
//P6.5 LED6
//P6.6 LED7
//P6.7 LED8

//P3.3 SW1
//P3.2 SW2
//LED1~LED8 根据2个按键动作来亮灭


//uCOSII 系统入口
void main(void)
{
	OSInit();               //OS系统初始化
	SystickInitOfTmer0();   //系统滴答计数器初始化 采用TIMER0 
   
	OSTaskCreate(TaskStart,
                (void*)0,
                &TASK_START_STK[0],
                START_TASK_Prio
                );          //起始任务 又这个任务再创建其他任务
	OSStart();              //启动OS系统 并且打开总中断开关  即EA=1
}



