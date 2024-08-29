#ifndef EXECUTE_H
#define EXECUTE_H

#include "main.h"

void execute_command(char *cmd);
int try_exec_command(char *cmd);
char **build_argv(char *cmd);

#endif /* EXECUTE_H */

