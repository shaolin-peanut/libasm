%define ENOMEM 12

section .text
    global ft_strdup

    extern ft_strlen
    extern ft_strcpy
    extern malloc
    extern __errno_location

ft_strdup:
    mov r12, rsi ; save source
    call ft_strlen
    test rax, rax
    je ret_err

    mov rdi, rax ; put len in rdi, only param for malloc
    inc rdi ; add 1 for null temrinator
    call malloc wrt ..plt
    mov r14, rax ; save dest
    ; test rax, rax
    jmp set_errno

    mov rdi, r14 ; destination (malloc ptr)
    mov rsi, r12 ; source
    call ft_strcpy
    ret

ret_err:
    mov rax, 0
    ret

set_errno:
    mov rdi, ENOMEM
    call __errno_location wrt ..plt
    mov [rax], rdi; ENOMEM
    jmp ret_err