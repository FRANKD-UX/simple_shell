#include <stdio.h>
#include <stdlib.h>

/**
 * builtin_printenv - Prints the environment variables
 *
 * Return: Always 0 on success, or 1 on error.
 */
int builtin_printenv(void)
{
    extern char **environ;
    char **env = environ;

    /* Iterate through the environment variables and print each one */
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    return (0);
}

