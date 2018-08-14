

//////////////////////////////////
//头文件
#include "includes.h"

//////////////////////////////////
//堆栈
OS_STK  TASK_1_STK[MaxStkSize+1]; //任务堆栈声明
OS_STK  TASK_2_STK[MaxStkSize+1]; //任务堆栈声明

///////////////////////////////////////////////
//任务1
void Task1(void * ppdata) reentrant
{
	ppdata = ppdata;
	for(;;)
	{          
		    SW1=1;
        if(SW1==0)
        {
            OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
            if(SW1==0)
            {
                LED=LED |0x0F;          //按键有效按下 则LED0~LED3亮
                while(SW1==0)
                {
                    while(SW1==0)
                    {
                         OSTimeDlyHMSM(0,0,0,20); //按键按下 20ms消抖
                    }
                    OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
                    OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
                }
								OSTaskSuspend(OS_PRIO_SELF);     //挂起自己
                LED=LED &0xF0;
            }
        }  
        OSTimeDlyHMSM(0,0,0,20);        
    }
}


///////////////////////////////////////////////
//任务2
void Task2(void * ppdata) reentrant
{
	ppdata = ppdata;
	for(;;)
	{          
		     SW2=1;
        if(SW2==0)
        {
            OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
            if(SW2==0)
            {
							  OSTaskResume(TASK_1_Prio);   //恢复任务1
                LED=LED | 0xF0   ; //按键有效按下 则灯LED4~LED7亮
                while(SW2==0)
                {
                    while(SW2==0)
                    {
                         OSTimeDlyHMSM(0,0,0,20); //按键按下 20ms消抖
                    }
                    OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
                    OSTimeDlyHMSM(0,0,0,20);     //按键按下 20ms消抖
                }
                LED=LED & 0x0F;
            }
        }  
        OSTimeDlyHMSM(0,0,0,30);        
    }
}


