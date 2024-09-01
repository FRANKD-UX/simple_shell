#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

extern char **environ;

/**
 * _unsetenv - Remove an environment variable.
 * @name: The name of the environment variable to remove.
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	char **env;
	size_t len = strlen(name);
	int found = 0;

	if (name == NULL || *name == '\0')
	return (-1);

	for (env = environ; *env != NULL; env++)
	{
	if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
	{
		found = 1;
		break;
	}
	}

	if (found)
	{
	for (; *env != NULL; env++)
		*env = *(env + 1);
	return (0);
	}

	return (-1);
}
