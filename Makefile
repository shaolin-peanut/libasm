SRCDIR = srcs

OBJDIR = objects

NAME = libasm.a
TESTNAME = runtest

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
	rm -f $(NAME) $(TESTNAME) 

re: fclean all

test: all
	gcc -o runtest srcs/main.c $(NAME)
	./$(TESTNAME)
