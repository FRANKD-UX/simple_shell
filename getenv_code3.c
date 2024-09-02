#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/* Function prototype for _getenv */
char *_getenv(const char *name);

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
#include "main.h"

char *_getenv(const char *name)
{
    /* Function implementation */
}
