SRCDIR = srcs

OBJDIR = objects

NAME = libasm.a

SOURCES = $(wildcard $(SRCDIR)/*.s)

OBJECTS = $(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	mkdir -p $(OBJDIR)
	nasm -f elf64 $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) main

re: fclean all

test: all
	gcc -o main srcs/main.c $(NAME)
	gcc -o main2 srcs/main2.c $(NAME)
	./main && ./main2