#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

extern char **environ; /* Global environment variable array */

/**
 * _setenv - Changes or adds an environment variable.
 * @name: The name of the environment variable to set.
 * @value: The value of the environment variable.
 * @overwrite: If non-zero, existing variables with the same name
 * will be overwritten.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
char **env;
int size;
char **new_environ;
size_t name_len = strlen(name);
size_t value_len = strlen(value);
char *new_var;

	if (name == NULL || *name == '\0' || value == NULL)
	return (-1);

	new_var = malloc(name_len + value_len + 2); /* +2 for '=' and '\0' */
	if (new_var == NULL)
	return (-1);

	sprintf(new_var, "%s=%s", name, value);

	for (env = environ; *env != NULL; env++)
	{
	if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
	{
		if (overwrite)
		{
		*env = new_var;
		return (0);
		}
		else
		{
		free(new_var);
		return (0);
		}
	}
	}

	size = 0;

	for (size = 0; environ[size] != NULL; size++)
	;

	new_environ = realloc(environ, sizeof(char *) * (size + 2));

	if (new_environ == NULL)
	{
	free(new_var);
	return (-1);
	}
	environ = new_environ;
	environ[size] = new_var;
	environ[size + 1] = NULL;

	return (0);
}
