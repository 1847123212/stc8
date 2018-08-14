

//////////////////////////////////
//ͷ�ļ�
#include "includes.h"

//////////////////////////////////
//��ջ
OS_STK  TASK_1_STK[MaxStkSize+1]; //�����ջ����
OS_STK  TASK_2_STK[MaxStkSize+1]; //�����ջ����

///////////////////////////////////////////////
//����1
void Task1(void * ppdata) reentrant
{
	ppdata = ppdata;
	for(;;)
	{          
		    SW1=1;
        if(SW1==0)
        {
            OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
            if(SW1==0)
            {
                LED=LED |0x0F;          //������Ч���� ��LED0~LED3��
                while(SW1==0)
                {
                    while(SW1==0)
                    {
                         OSTimeDlyHMSM(0,0,0,20); //�������� 20ms����
                    }
                    OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
                    OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
                }
								OSTaskSuspend(OS_PRIO_SELF);     //�����Լ�
                LED=LED &0xF0;
            }
        }  
        OSTimeDlyHMSM(0,0,0,20);        
    }
}


///////////////////////////////////////////////
//����2
void Task2(void * ppdata) reentrant
{
	ppdata = ppdata;
	for(;;)
	{          
		     SW2=1;
        if(SW2==0)
        {
            OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
            if(SW2==0)
            {
							  OSTaskResume(TASK_1_Prio);   //�ָ�����1
                LED=LED | 0xF0   ; //������Ч���� ���LED4~LED7��
                while(SW2==0)
                {
                    while(SW2==0)
                    {
                         OSTimeDlyHMSM(0,0,0,20); //�������� 20ms����
                    }
                    OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
                    OSTimeDlyHMSM(0,0,0,20);     //�������� 20ms����
                }
                LED=LED & 0x0F;
            }
        }  
        OSTimeDlyHMSM(0,0,0,30);        
    }
}


