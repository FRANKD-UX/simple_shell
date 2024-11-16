#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function prototypes */
void run_interactive_mode(void);
void run_non_interactive_mode(const char *script_path);
void execute_command(const char *command);
char **tokenize(const char *line);
int handle_builtin(char **args);
void free_tokens(char **tokens);

#endif /* SHELL_H */
