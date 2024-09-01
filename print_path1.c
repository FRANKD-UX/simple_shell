#include <stdio.h>
#include <string.h>
#include "env.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: A pointer to the valu of the environmnt vrble, or NULL if not fund.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(name, *env, len) == 0 &&
		    (*env)[len] == '=')
		{
			return ((*env) + len + 1);
		}
	}

	return (NULL);
}

/**
 * main - Entry point of the program.
 *
 * This function demonstrates the usage of the _getenv function.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	const char *path = _getenv("PATH");

	if (path != NULL)
	{
		printf("PATH: %s\n", path);
	}
	else
	{
		printf("PATH not found\n");
	}

	return (0);
}

