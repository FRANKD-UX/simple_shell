#include <stdio.h>
#include <string.h> /* Include for strlen() and strncmp() */
#include <unistd.h> /* Include for environ */

/* Declare the extern variable */
extern char **environ;

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: The name of the environment variable to retrieve
 *
 * Return: A pointer to the value of the environment variable, or NULL
 * if the environment variable is not found.
 */
<<<<<<< HEAD
char *_getenv(const char *name);
int main(void);
{
(void)char *name;
char **env;
size_t len;
	
	if (name == NULL || *name == '\0')
	return (NULL);
=======
char *_getenv(const char *name)
{
	char **env;
	size_t len;
>>>>>>> c066c786ef941e9ca89ebf78fb01e87518a828ec

	len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}

<<<<<<< HEAD
	return (NULL); /* Return NULL if variable is not found */

=======
	return (NULL);
>>>>>>> c066c786ef941e9ca89ebf78fb01e87518a828ec
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

