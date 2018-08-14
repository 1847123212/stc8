Name main
seg_1 SEGMENT CODE 
	       RSEG seg_1
TABLE:     DB   3,2,5,0x0EE
seg_2 SEGMENT IDATA 
           RSEG seg_2
BUFFER:    DS   19
seg_3 SEGMENT XDATA
           RSEG seg_3
XBUFFER:   DS   100

myprog SEGMENT CODE 
	       RSEG myprog
		   USING 0
		   LJMP  main
		   ORG   0x100
main:      MOV   DPTR, #TABLE
           MOV   A,#3
		   MOVC  A,@A+DPTR
		   MOV   P1,#0
		   MOV   P1,A
		   
		   MOV   R0,#BUFFER
		   MOV   @R0,A
		   INC   A
		   INC   R0
		   MOV   @R0,A
		   
		   MOV   DPTR,#XBUFFER
		   INC   A
		   MOVX  @DPTR,A
		   INC   DPTR
		   CLR   A 
		   MOVX  @DPTR,A
END
		