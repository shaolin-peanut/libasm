section .text
    global ft_strcmp

ft_strcmp:
loop_start: ; load chars from s1 and s2
    mov al , [rdi]
    mov bl , [rsi]
    ;check if (strings are empty, chars are equal?)
    test al, al
    jz loop_end
    test bl, bl
    jz loop_end
    cmp al, bl ; compare characters, set to 0 if equal, or 1 if not equal
    jne loop_end ; jump if condition is met => jump to loop_startjmp while
    ; if none are triggered, keep looping
    inc rdi
    inc rsi
    jmp loop_start

loop_end:
    ; s1 = 0, s2 = 'a' => return -1
    ; s1 = 'a', s2 = 0 => return 1
    sub al, bl
    movzx rax, al 
    ret
    
