# Makefile for simple shell project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Executable name
TARGET = hsh

# Source files
SRCS = simple_shell.c

# Header files
HEADERS = main.h

# Rule to build the executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Rule to clean build files
clean:
	rm -f $(TARGET)

# Rule to remove all generated files
fclean: clean
	rm -f $(TARGET)

# Rule to rebuild everything
re: fclean $(TARGET)

.PHONY: clean fclean re

