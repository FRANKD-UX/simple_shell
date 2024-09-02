#include "main.h"
#include <string.h>  /* Include this for strtok and strcmp functions */

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable if found, NULL otherwise
*/
extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;  /* Assuming 'environ' is declared globally */
	char *env_var;

	while (*env)
	{
		env_var = strtok(*env, "=");
		if (strcmp(env_var, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		env++;
	}

	return (NULL);
}

