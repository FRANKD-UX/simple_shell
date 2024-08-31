#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/* Declare the global environment variable */
extern char **environ;

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len;

	if (name == NULL || *name == '\0')
	return (NULL);

	len = strlen(name);

    /* Iterate through the environment variables */
	for (env = environ; *env != NULL; env++)
	{
	/* Check if the current environment variable starts with `name=` */
	if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
		return (*env + len + 1); /* Return pointer to the value */
		}
	}

	return (NULL); /* Return NULL if variable is not found */
}

/**
 * main - Demonstrates the usage of _getenv function.
 * Test the _getenv function by attempting to retrieve
 * the values of the HOME and PATH environment variables. It prints
 * the values to the standard output.
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *value;

    /* Example environment variables to test */
	value = _getenv("HOME");
	if (value)
		printf("HOME: %s\n", value);
		else
		printf("HOME not found\n");

		value = _getenv("PATH");
	if (value)
		printf("PATH: %s\n", value);
	else
		printf("PATH not found\n");

	return (0);
}
