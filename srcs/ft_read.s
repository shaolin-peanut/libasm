%define read 0

section .text
    global ft_read

ft_read:
    mov rax, read
    syscall
    ret