#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

extern char **environ;

void execute_command(char *command, char *argv[]);
int execute_program(char *const argv[], char *const envp[]);

#endif /* SIMPLE_SHELL_H */

