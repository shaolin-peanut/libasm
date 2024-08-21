%define write 1

section .text
    global ft_write

    extern __errno_location

ft_write:
    mov rax, write
    syscall
    test rax, rax
    js set_errno
    ret ; returns rax

set_errno:
    neg rax ; absolute value of write return value = errno code
    mov r10, rax
    call __errno_location wrt ..plt
    mov [rax], r10; errno pointer
    mov rax, -1
    ret
