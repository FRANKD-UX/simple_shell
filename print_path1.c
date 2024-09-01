#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Pointer to the valu of the envirnmnt varible, or NLL if nt found.
 */
char *_getenv(const char *name)
{
	char **env;
	char *env_var;

	for (env = environ; *env != NULL; env++)
	{
		env_var = strtok(*env, "=");
		if (strcmp(env_var, name) == 0)
		{
			return (strtok(NULL, "="));
		}
	}

	return (NULL);
}

