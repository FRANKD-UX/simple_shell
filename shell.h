#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
char *read_command(void);
char **parse_command(char *line);
void prompt(void);
void add_to_history(char *cmd);
void print_history(void);
int handle_builtin_commands(char *cmd, char **args);
void parse_and_execute(char *cmd);
void execute_command(char **args);

#endif /* SHELL_H */

