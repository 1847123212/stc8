
//////////////////////////////////////
//ͷ�ļ�
#include "includes.h"


////////////////////////////////////////////////////////////////////////
//����˵��
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
//LED1~LED8 ����2����������������


//uCOSII ϵͳ���
void main(void)
{
	OSInit();               //OSϵͳ��ʼ��
	SystickInitOfTmer0();   //ϵͳ�δ��������ʼ�� ����TIMER0 
   
	OSTaskCreate(TaskStart,
                (void*)0,
                &TASK_START_STK[0],
                START_TASK_Prio
                );          //��ʼ���� ����������ٴ�����������
	OSStart();              //����OSϵͳ ���Ҵ����жϿ���  ��EA=1
}



