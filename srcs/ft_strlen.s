
section .text
    global ft_strlen

ft_strlen:
    mov rsi, rdi
    mov rcx, 0 ; iterator
loop_start:
    mov al, [rsi] ; load first byte of rsi into al
    inc rsi ; increment rsi pointer
    test al, al ; check if al is zero
    jz loop_end ; if it is zero, jump to loop_end
    inc rcx ; else, increment rcx by 1
    jmp loop_start ; and jump back to loop_start
loop_end:
    mov rax, rcx ; move rcx into rax
    ret