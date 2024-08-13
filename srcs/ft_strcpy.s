section .text
    global ft_strcpy

ft_strcpy:
    ; save pointers
    mov r10, rdi
loop_start:
    ;lodsb ; load next char in rsi (source) into al, and increment rsi
    mov al, [rsi]
    inc rsi
    ;stosb ; store al in rdi (destination) and increment rdi pointers
    mov [rdi], al ; *rsi = al
    inc rdi
    test al, al ; check if al (rsi/source) is zero
    jnz loop_start ; if test alal is not zero, jumpt to loop_start
loop_end:
    mov rax, r10
    ret


    
