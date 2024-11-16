#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

/* Function prototypes */
void run_interactive_mode(void);
void run_non_interactive_mode(const char *script_path);
void execute_command(const char *command);
char **tokenize(const char *command);
void free_tokens(char **tokens);
int handle_builtin(char **args);

#endif /* SHELL_H */

