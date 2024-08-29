#ifndef MAIN_H
#define MAIN_H

#include <stddef.h> /* For size_t */
#include <stdlib.h> /* For malloc and free */

/* Declare extern variable */
extern char **environ;

/* Function prototypes */
void handle_input(char **line, size_t *len);
void execute_command(char *cmd);
int main(void);

#endif /* MAIN_H */

