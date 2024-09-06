# Define the compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Target executable
TARGET = shell

# Source files
SRC = simple_shell.c exec.c prompt.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean

