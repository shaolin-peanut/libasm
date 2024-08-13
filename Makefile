SRCDIR = srcs

OBJDIR = objects

LIBNAME = libasm.a

SOURCES = $(wildcard $(SRCDIR)/*.s)

OBJECTS = $(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	mkdir -p $(OBJDIR)
	nasm -f elf64 $< -o $@

$(LIBNAME): $(OBJECTS)
	ar rcs $@ $^

all: $(LIBNAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBNAME) main

re: fclean all

distclean: clean
	rm -f $(LIBNAME)

constants:
	gcc -E -P bonus/constants.c > constants.txt

test: all
	gcc -o main srcs/main.c $(LIBNAME)
	./main
