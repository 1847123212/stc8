$NOMOD51

$INCLUDE (reg51.inc)
	
NAME CONTROL_GPIO
P6        DATA 0E8H                
segcode segment code
	public CONTROL_GPIO
	rseg segcode
CONTROL_GPIO:
        MOV  A,#0FEH                
LOOP:   MOV  P6,A
		RL   A
		JMP  LOOP
		RET
END 