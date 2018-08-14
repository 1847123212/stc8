
;*************	功能说明	**************

;程序使用P6 来显示0~15的计数值

;******************************************
;******************************************
;定义P6端口的地址
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
;// 函数: delay
;// 描述: 延时子程序。
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


