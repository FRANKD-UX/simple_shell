#ifndef MAIN_H
#define MAIN_H

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

/* Function prototypes */
char *_getenv(const char *name);

/**
 * print_env - Prints the current environment variables.
 *
 * Return: 0 on success, or another integer if an error occurs.
 */
int print_env(void);

extern char **environ; /* Declare the extern variable */

#endif /* MAIN_H */

