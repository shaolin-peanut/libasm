%define write 1

section .text
    global ft_write

ft_write:
    mov rax, write
    syscall ; runs system call in rax, puts return value in rax
    ret ; returns rax
