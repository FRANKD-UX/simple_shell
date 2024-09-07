CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
OBJ = simple_shell.o history.o builtin.o execute.o

all: simple_shell

simple_shell: $(OBJ)
	$(CC) $(CFLAGS) -o simple_shell $(OBJ)

simple_shell.o: simple_shell.c shell.h
	$(CC) $(CFLAGS) -c simple_shell.c

history.o: history.c shell.h
	$(CC) $(CFLAGS) -c history.c

builtin.o: builtin.c shell.h
	$(CC) $(CFLAGS) -c builtin.c

execute.o: execute.c shell.h
	$(CC) $(CFLAGS) -c execute.c

clean:
	rm -f *.o simple_shell

