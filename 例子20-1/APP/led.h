

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef __TASK_H__
#define __TASK_H__
 
////////////////////////////
//��ͷ�ļ�
#include "includes.h"

extern OS_STK  TASK_1_STK[MaxStkSize+1];
extern void Task1(void * ppdata) reentrant;

extern OS_STK  TASK_2_STK[MaxStkSize+1];
extern void Task2(void * ppdata) reentrant;

#endif

