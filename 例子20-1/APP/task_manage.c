
/* Includes -----------------------------------------------------------------*/
#include "includes.h"

//////////////////////////////////////////////////////////
OS_STK  TASK_START_STK[MaxStkSize+1]; //任务堆栈声明

//////////////////////////////////////////////////////////
void TaskCreateOther(void) reentrant;             //用这个函数来创建其他任务


//////////////////////////////////////////////////////////
//起始任务 又这个任务再创建其他任务
void TaskStart(void * ppdata) reentrant
{
	ppdata = ppdata;
	
    ET0=1;                              //使能时钟节拍中断
    
    //使能ucos 的统计任务
    #if (OS_TASK_STAT_EN > 0)
    OSStatInit();                       //统计任务初始化函数   
    #endif  
    
    bsp();                              //板载硬件初始化
    globalvariable();                   //用户应用程序全局变量初始化
    TaskCreateOther();			            //建立其他的任务
	  OSStart();
    OSTaskSuspend(OS_PRIO_SELF);	    //suspend but not delete 挂起任务	
}

/////////////////////////////////////////////////////////////////////////////
//创建其他所有任务 在这里我建立了个LED闪烁的任务当例子
void TaskCreateOther(void) reentrant
{  
    OSTaskCreate(Task1, (void * )0, (OS_STK *)&TASK_1_STK[0], TASK_1_Prio);                     //LED显示任务1
    OSTaskCreate(Task2, (void * )0, (OS_STK *)&TASK_2_STK[0], TASK_2_Prio);                     //LED显示任务2
}


      





