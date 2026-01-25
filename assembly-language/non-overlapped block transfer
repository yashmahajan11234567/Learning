section .data
    nline db 10, 10
    nline_len equ $ - nline
    space db ' '  ; Changed from -- to space
    ano db 10, "Assignment no: 6", 
        db 10, "------------------------------------------------------------------------",
        db 10, "Block transfer - non-overlapped without string instruction,", 
        db 10, "------------------------------------------------------------------------", 10
    ano_len equ $ - ano
    bmsg db 10, "Before transfer::"
    bmsg_len equ $ - bmsg

    amsg db 10, "After transfer::"
    amsg_len equ $ - amsg

    smsg db 10, " source block"
    smsg_len equ $ - smsg

    dmsg db 10, " destination block"
    dmsg_len equ $ - dmsg

    sblock db 11h, 22h, 33h, 44h, 55h
    dblock times 5 db 0
;-------------------------------------------------------------------------
section .bss
    char_ans resb 2
;-------------------------------------------------------------------------
%macro Print 2
    mov RAX, 1
    mov RDI, 1
    mov RSI, %1
    mov RDX, %2
    syscall
%endmacro

%macro Read 2
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro Exit 0
    ; Print nline, nline_len
    mov rax, 60
    xor rdi, rdi
    syscall
%endmacro
;-------------------------------------------------------------------------------

section .text
    global _start

_start:
    Print ano, ano_len
    Print bmsg, bmsg_len

    Print smsg, smsg_len
    mov rsi, sblock
    call disp_block

    Print bmsg, bmsg_len

    Print smsg, smsg_len
    mov rsi, sblock
    call disp_block

    Print dmsg, dmsg_len
    mov rsi, dblock
    call disp_block

    call BT_NO

    Print amsg, amsg_len

    Print smsg, smsg_len
    mov rsi, sblock
    call disp_block

    Print dmsg, dmsg_len
    mov rsi, dblock
    call disp_block

    Exit
;----------------------------------------------------------------------
BT_NO:
    mov rsi, sblock
    mov rdi, dblock
    mov rcx, 5

back:
    mov al, [rsi]
    mov [rdi], al

    inc rsi
    inc rdi

    dec rcx
    jnz back
    ret
;-------------------------------------------------------------------------
disp_block:
    mov rbp, 5

next_num:
    mov al, [rsi]
    push rsi

    call Disp_8
    Print space, 1

    pop rsi
    inc rsi

    dec rbp
    jnz next_num
    ret
;-----------------------------------------------------------------------------
Disp_8:
    mov RSI, char_ans + 1
    mov RCX, 2
    mov RBX, 16

next_digit:
    xor RDX, RDX
    div RBX
    cmp DL, 9
    jbe add30
    add DL, 7

add30:
    add DL, 30h
    mov [RSI], DL

    dec RSI
    dec RCX
    jnz next_digit

    Print char_ans, 2
    ret
;-----------------------------------------------------------------------------

