;*************	����˵��	**************

;����ʹ��P6����ʾ�ļ���ֵ

;******************************************
;******************************************
;����P6�˿ڵĵ�ַ
P6        DATA 0E8H
;******************************************
	
	my_prog  SEGMENT CODE
		     RSEG my_prog
		     LJMP main
			 ORG 0x0003
			 LJMP count_dec
			 ORG 0x0013
		     LJMP count_inc
             ORG 0x100		
Main:
	    USING   0
        MOV SP, #40H
	    SETB IT0
		SETB IT1
	    SETB EX0
		SETB EX1
	    SETB EA
		MOV  A,#0FFH
		MOV  P6,A
loop:   ljmp loop
;********************************

;//==============================
;// ����: count_dec
;// ����: �жϷ����ӳ���
;//==============================
count_dec:  
        PUSH DPH
	    PUSH 02H
    	DEC  A
		MOV  P6,A
	    POP  DPH
		POP  02H
	    RETI
		
;//==============================
;// ����: count_inc
;// ����: �жϷ����ӳ���
;//==============================		
count_inc:  
        PUSH DPH
	    PUSH 02H
    	INC  A
		MOV  P6,A
	    POP  DPH
		POP  02H
	    RETI
		
END


