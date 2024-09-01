#include <stdio.h>
#include "main.h"

/**
 * print_env - Prints the environment variables.
 * @environ: Array of environment variables.
 *
 * Return: void.
 */
void print_env(char **environ)
{
	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
}

