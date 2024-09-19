#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

extern char **environ;

void execute_command(char *command, char *argv[]);

#endif /* SIMPLE_SHELL_H */

