#ifndef BUILTINS_H
#define BUILTINS_H

#include "main.h"

void execute_cd(char **args);
void execute_exit(void);
void execute_pwd(void);
int execute_builtin(char **args);

#endif /* BUILTINS_H */

