
;*************	����˵��	**************

;����ʹ��P6 ����ʾ0~15�ļ���ֵ

;******************************************
;******************************************
;����P6�˿ڵĵ�ַ
P6        DATA 0e8H
;******************************************
    CSEG AT  0x0000
	LJMP main
	my_prog  SEGMENT CODE
		     RSEG my_prog
             ORG 0x100		
main:
	USING   0
LOOP1:
	MOV     R0,#0FFH
LOOP2:
    MOV     P6,R0
dly:
	ACALL   delay
	ACALL   delay
	ACALL   delay
	ACALL   delay
	DEC     R0
    CJNE    R0,#0EFH,LOOP2
    JMP     lOOP1	
;********************************

;//==============================
;// ����: delay
;// ����: ��ʱ�ӳ���
;//==============================
delay:
    MOV		R3, #0FFH
delay_1:	
   MOV		R4, #0FFH
	 
delay_2:
	DEC		R4				;
	CJNE	R4,#0,delay_2	;
	DEC		R3
	CJNE    R3,#0,delay_1	;
	RET
	
	END


