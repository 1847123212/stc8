
/* Includes -----------------------------------------------------------------*/
#include "includes.h"

//////////////////////////////////////////////////////////
OS_STK  TASK_START_STK[MaxStkSize+1]; //�����ջ����

//////////////////////////////////////////////////////////
void TaskCreateOther(void) reentrant;             //�����������������������


//////////////////////////////////////////////////////////
//��ʼ���� ����������ٴ�����������
void TaskStart(void * ppdata) reentrant
{
	ppdata = ppdata;
	
    ET0=1;                              //ʹ��ʱ�ӽ����ж�
    
    //ʹ��ucos ��ͳ������
    #if (OS_TASK_STAT_EN > 0)
    OSStatInit();                       //ͳ�������ʼ������   
    #endif  
    
    bsp();                              //����Ӳ����ʼ��
    globalvariable();                   //�û�Ӧ�ó���ȫ�ֱ�����ʼ��
    TaskCreateOther();			            //��������������
	  OSStart();
    OSTaskSuspend(OS_PRIO_SELF);	    //suspend but not delete ��������	
}

/////////////////////////////////////////////////////////////////////////////
//���������������� �������ҽ����˸�LED��˸����������
void TaskCreateOther(void) reentrant
{  
    OSTaskCreate(Task1, (void * )0, (OS_STK *)&TASK_1_STK[0], TASK_1_Prio);                     //LED��ʾ����1
    OSTaskCreate(Task2, (void * )0, (OS_STK *)&TASK_2_STK[0], TASK_2_Prio);                     //LED��ʾ����2
}


      





