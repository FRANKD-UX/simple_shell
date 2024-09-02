#ifndef MAIN_H
#define MAIN_H

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to find.
 *
 * Return: A pointer to the value of the envirnment varible,
 * or NULL if not found.
 */
char *_getenv(const char *name)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
	if (_strncmp(name, *env, _strlen(name)) == 0)
		{
		return (*env + _strlen(name) + 1);
		}
	}
	return (NULL);
}

