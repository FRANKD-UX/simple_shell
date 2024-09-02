#include <stdio.h>
#include "main.h"

/**
 * print_env - prints the environment variables
 * @environ: array of environment variables
 */
void print_env(char **environ)
{
	int i;

	/* Print each environment variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

