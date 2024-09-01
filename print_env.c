#include "main.h"

/**
 * print_env - Prints the current environment.
 *
 * Return: Always 0.
 */
int print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}

