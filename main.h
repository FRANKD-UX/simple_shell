#ifndef MAIN_H
#define MAIN_H
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
void prompt(void);
void add_to_history(char *cmd);
void print_history(void);
int handle_builtin_commands(char *cmd, char **args);
void parse_and_execute(char *cmd);
void execute_command(char **args);

void execute_command(char *command);

#endif /* MAIN_H */

