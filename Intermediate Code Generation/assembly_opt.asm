.MODEL SMALL
.STACK 1000H
.DATA
	NUMBER DB "00000$"
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
L1:
	SUB SP, 2			; Line 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L2:
	MOV AX, 0			; Line 3
	MOV [BP - 4], AX
L3:
	MOV AX, 1			; Line 4
	MOV [BP - 6], AX
L4:
	MOV AX, 0			; Line 5
	MOV [BP - 8], AX
L5:
	MOV AX, [BP - 8]			; Line 5
	PUSH AX
	MOV AX, 4			; Line 5
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L6
	JMP L7
L6:
	MOV AX, 1
	JMP L8
L7:
	MOV AX, 0
L8:
	CMP AX, 0
	JE LL1
L9:
L10:
	MOV AX, 3			; Line 6
	MOV [BP - 2], AX
L11:
	MOV AX, [BP - 2]			; Line 7
	PUSH AX
	DEC AX
	MOV [BP - 2], AX
	POP AX
	CMP AX, 0
	JE LL2
L12:
L13:
	MOV AX, [BP - 4]			; Line 8
	PUSH AX
	INC AX
	MOV [BP - 4], AX
	POP AX
	JMP L11
LL2:
	MOV AX, [BP - 8]			; Line 5
	PUSH AX
	INC AX
	MOV [BP - 8], AX
	POP AX
	JMP L5
LL1:
	MOV AX, [BP - 2]			; Line 11
	CALL print_output
	CALL new_line
	MOV AX, [BP - 4]			; Line 12
	CALL print_output
	CALL new_line
	MOV AX, [BP - 6]			; Line 13
	CALL print_output
	CALL new_line
exit_main:
	ADD SP, 8
	POP BP
	MOV AX, 4CH
	INT 21H
main ENDP


; ---------------------------------------------------------
;                      PRINT LIBRARY
; ---------------------------------------------------------
new_line PROC
    PUSH AX
    PUSH DX
    MOV  AH, 2
    MOV  DL, 0DH
    INT  21H
    MOV  AH, 2
    MOV  DL,0AH
    INT  21H
    POP  DX
    POP  AX
    RET
new_line endp
print_output proc                     ; print what is in AX
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSH SI
    LEA  SI, number
    MOV  BX, 10
    ADD  SI, 4
    CMP  AX, 0
    JNGE negate
print:       
    XOR  DX, DX
    DIV  BX
    MOV  [SI], DL
    ADD  [SI], '0'
    DEC  SI
    CMP  AX, 0
    JNE  print
    INC  SI
    LEA  DX, [SI]
    MOV  AH, 9
    INT  21H
    POP  SI
    POP  DX
    POP  CX
    POP  BX
    POP  AX
    RET
negate:      
    PUSH AX
    MOV  AH, 2
    MOV  DL, '-'
    INT  21H
    POP  AX
    NEG  AX
    JMP  print
print_output endp

END main
