#include <stdio.h>
#include "main.h"

/* Declare the global variable `environ` */
extern char **environ;

/**
 * main - Prints the addresses of `env` and `environ` to compare them.
 * @ac: The number of command-line arguments.
 * @av: The array of command-line arguments.
 * @env: The environment variable array passed to `main`.
 *
 * Return: Always 0.
 */
int main(int ac, char **env)
{
	(void)ac;
    /* Print the address of the `env` parameter */
	printf("Address of env (parameter): %p\n", (void *)env);

    /* Print the address of the `environ` global variable */
	printf("Address of environ (global): %p\n", (void *)environ);

	return (0);
}
