# CMPT 214 - Assignment 2
# Name, Student Number, NSID

# Make has variables, pretty similar to the shell.  Everywhere
# you see $(CC) it will be replaced with the "gcc" string.
# gcc is the GNU C Compiler.
CC= gcc

# The -Wall option displays additional warnings that make
# debugging easier.
CFLAGS= -Wall -Wextra

BINARY= a.out

# The binary we want to create, a.out, is dependant on
# the string_length.c file.

# The -o option to gcc specifies the name of the executable
# file being created.  

$(BINARY): string_length.c
	$(CC) -o $(BINARY) $(CFLAGS) string_length.c

# It's always a good idea to have a cleanup target.

clean:
	rm -f $(BINARY)
