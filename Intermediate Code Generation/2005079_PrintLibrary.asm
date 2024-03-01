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