%define socket 41
%define bind 49
%define af_inet 2
%define sock_stream 1
%define listen 50
%define accept 43
%define connect 42
%define read 0
%define write 1
%define open 2
%define close 3
%define o_rdonly 00
%define o_wronly 01
%define o_rdwr 02
%define exit 60

; mov ax,[ip_addr+sin_family] or mov ax,[ip_addr+sin_port].

struc sockaddr_in
    sin_family resw 1 ; word (2 bytes), equivalent to short
    sin_port resw 1 ; word (2 bytes)t
    sin_addr resd 1 ; double word (8 bytes), equivalent to int
    sin_zero resb 8; 8 null bytes
endstruc

section .data
    address:
        istruc sockaddr_in
            at sin_family, dw af_inet
            at sin_port, dw 0x191f ; htons(8080). Basically it's in hex and you swap bytes, so 0x16D9 becomes 0xD916
            at sin_addr, dd 0x00000000
            at sin_zero, times 8 db 0
    buffer:
        times 256 db 0
    buffer2:
        times 256 db 0
    path:
        db "bonus/index.html", 0

section .text

global _start

; argument registers: rdi   rsi   rdx   r10   r8    r9 
_start:
    ; call socket
    mov rdi, af_inet ; AF_INET
    mov rsi, 1 ; SOCK_STREAM
    mov rdx, 0
    mov rax, socket
    syscall

    ; save socket fd
    mov r12, rax

    ; call bind
    mov rdi, r12
    lea rsi, [address] ; put pointer of sockaddr_in as second argument
    mov rdx, 16 ; len(sockaddr_in)
    mov rax, bind
    syscall

    ; call listen
    mov rdi, r12
    mov rsi, 10
    mov rax, listen
    syscall

    accept_loop:

    ; call accept
    mov rdi, r12
    mov rsi, 0
    mov rdx, 0
    mov rax, accept
    syscall

    ; store client socket in r13
    mov r13, rax

    ; call read from client
    mov rdi, r13
    mov rsi, buffer
    mov rdx, 256
    mov rax, read
    syscall

    ; open file
    mov rdi, path
    mov rsi, o_rdonly
    mov rax, open
    syscall

    mov r14, rax

    ; read into buffer2
    mov rdi, rax
    mov rsi, buffer2
    mov rdx, 256
    mov rax, read

    mov r15, rax

    ; write to client
    mov rdi, r13
    mov rsi, buffer2
    mov rdx, r15
    mov rax, write
    syscall

    ; end
    mov rdi, r13
    mov rax, close
    syscall

    mov rdi, r14
    mov rax, close
    syscall

    jmp accept_loop

    mov rdi, 0
    mov rax, exit
    syscall

; _exit:
;     ; close client socket
;     mov rdi, r13
;     mov rax, close
;     syscall

;     ; close server socket
;     mov rdi, r12
;     mov rax, close
;     syscall

;     ; exit program
;     xor edi, edi              ; exit code 0
;     mov rax, 60               ; sys_exit
;     syscall





