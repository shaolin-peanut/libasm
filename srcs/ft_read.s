%define read 0

section .text
    global ft_read

    extern __errno_location

ft_read:
    mov rax, read
    syscall
    test rax, rax
    js set_errno ; js = jump if sign (negative number)
    ret

set_errno:
    neg rax ; absolute value of write return value = errno code
    mov r10, rax
    call __errno_location wrt ..plt
    mov [rax], r10; errno pointer
    mov rax, -1
    ret