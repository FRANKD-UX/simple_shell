#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
int main(int argc, char **argv);
void execute_command(char *cmd);
void prompt(void);

#endif /* MAIN_H */

