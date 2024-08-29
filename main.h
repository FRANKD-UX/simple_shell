#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_CMD_LEN 1024

extern char **environ;

void shell_loop(void);
void execute_command(char *cmd);
void prompt(void);
int try_exec_command(char *cmd);
void handle_fork_error(void);
char **build_argv(char *cmd);

#endif /* MAIN_H */

