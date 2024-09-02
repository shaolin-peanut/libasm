section .text
    global ft_strcpy

ft_strcpy:
    ; save pointers
    mov r10, rdi
loop_start:
    ;lodsb ; load next char from rsi (source) into al, and increment rsi
    mov al, [rsi]
    inc rsi
    ;stosb ; store al in rdi (destination) and increment rdi pointers
    mov [rdi], al ; *rsi = al
    inc rdi
    test al, al ; check if al (rsi/source) is zero
    jnz loop_start ; jnz = jump if zero flag is not set
loop_end:
    mov rax, r10
    ret


    
