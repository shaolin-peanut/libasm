SRCS = ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s
SRCBONUS = ft_exit.s ft_server.s

SRCDIR = ./src
BONUSDIR = ./bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -nostdlib -static

OBJS = $(SRCS:.s=.o)

constants:
	gcc -E -P bonus/constants.c > constants.txt