#ifndef MAIN_H
#define MAIN_H


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

