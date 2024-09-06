CC = gcc
CFLAGS = -Wall - Werror - Wextra - pedantic - std = gnu89
TARGET = simple_shell

all : $(TARGET)

$(TARGET) : simple_shell.o
	$(CC) $(CFLAGS) - o $(TARGET) simple_shell.o

clean :
	rm - f $(TARGET)  * .o

