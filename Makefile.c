CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
TARGET = simple_shell

all: $(TARGET)

$(TARGET): simple_shell.c
    $(CC) $(CFLAGS) -o $(TARGET) simple_shell.c

clean:
    rm -f $(TARGET)

.PHONY: all clean


