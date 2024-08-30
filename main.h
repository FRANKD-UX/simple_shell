#ifndef MAIN_H
#define MAIN_H

/* Standard Library Includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Macros and Constants */
#define BUFFER_SIZE 1024

/* Function Prototypes */

/* execute_command.c */
void execute_command(char *command);

/* shell.c */
int shell_main(void);

/* my_getline.c */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

/* set_env.c */
int _setenv(const char *name, const char *value, int overwrite);

/* print_args.c */
int print_args(int ac, char **av);

/* getenv_code3.c */
char *_getenv(const char *name);

/* env-main.c */
int env_main(int ac, char **av, char **env);

/* env_vs_environ.c */
int env_vs_environ(int ac, char **av, char **env);

/* Add additional function prototypes as needed */

/* Optional: External Variables */
/* extern char **environ; */  /* Uncomment if using the globl environ vrible */

#endif /* MAIN_H */

