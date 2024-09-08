CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
OBJ = simple_shell.o history.o builtin.o execute1.o parse_command.o read_command.o main.o

all: simple_shell

simple_shell: $(OBJ)
	$(CC) $(CFLAGS) -o simple_shell $(OBJ)

simple_shell.o: simple_shell.c shell.h
	$(CC) $(CFLAGS) -c simple_shell.c

history.o: history.c shell.h
	$(CC) $(CFLAGS) -c history.c

builtin.o: builtin.c shell.h
	$(CC) $(CFLAGS) -c builtin.c

execute.o: execute1.c shell.h
	$(CC) $(CFLAGS) -c execute1.c

main.o: main.c shell.h
        $(CC) $(CFLAGS) -c main.c

read_command.o: read_command.c shell.h
        $(CC) $(CFLAGS) -c read_command.c

parse_command.o: parse_command.c shell.h
        $(CC) $(CFLAGS) -c parse_command.c



clean:
	rm -f *.o simple_shell

