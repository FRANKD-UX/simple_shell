#include <stdio.h>

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: The name of the environment variable to retrieve
 *
 * Return: A pointer to the value of the environment variable, or NULL
 * if the environment variable is not found.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len;

	/* Avoid unused parameter warning (if applicable) */
	(void)name;

	len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}

	return (NULL);
}

/**
 * main - Entry point of the program
 *
 * This function demonstrates the usage of the _getenv function
 *
 * Return: Always 0 (Success)
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

