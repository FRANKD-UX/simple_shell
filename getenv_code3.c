#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Retrieve the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable or NULL if not found
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len;

	if (name == NULL || *name == '\0')
	{
		return (NULL);
	}

	name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}

