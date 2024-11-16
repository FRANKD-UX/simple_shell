#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(const char *command);
char **tokenize(const char *input);
int handle_builtin(char **args);
void free_tokens(char **tokens);

#endif /* SHELL_H */

