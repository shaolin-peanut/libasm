%define write 1

section .text
    global ft_write

    extern __errno_location

ft_write:
    mov rax, write
    syscall ; runs system call in rax, puts return value in rax
    ; test if rax is negative
    test rax, rax
    je set_errno
    ret ; returns rax

set_errno:
    neg rax
    mov r10, rax
    call __errno_location wrt ..plt
    mov [rax], r10; ENOMEM
    mov rax, 0
    ret
