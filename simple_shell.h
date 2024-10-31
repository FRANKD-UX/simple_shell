#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function declarations */
void shell_loop(void);
void execute_command(char **args);
char **split_input(char *input);

#endif /* SIMPLE_SHELL_H */

