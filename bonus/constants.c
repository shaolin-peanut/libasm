#include <sys/syscall.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

%define socket SYS_socket
%define bind SYS_bind
%define af_inet AF_INET
%define sock_stream SOCK_STREAM
%define listen SYS_listen
%define accept SYS_accept
%define connect SYS_connect
%define read SYS_read
%define write SYS_write
%define open SYS_open
%define close SYS_close
%define o_rdonly O_RDONLY
%define o_wronly O_WRONLY
%define o_rdwr O_RDWR