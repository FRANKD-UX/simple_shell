#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/* Declare the global environment variable */
extern char **environ;

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to search for.
 *
 * Return: The value of the environment variable if found, otherwise NULL.
 */
char *_getenv(const char *name)
int main(void);
{
	(void)char *name;
	char **env;
	size_t len;

	if (name == NULL || *name == '\0')
	return (NULL);

	len = strlen(name);

    /*Iterate through the environment variables*/
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

/**
 * print_path_dirs - Prints each directory in the PATH environment variable.
 *
 * This function retrieves the PATH environment variable, splits it by
 * colons, and prints each directory on a new line.
 */
void print_path_dirs(void)
{
	char *path;
	char *token;
	char *path_copy;

    /*Retrieve the PATH environment variable*/
	path = _getenv("PATH");
	if (path == NULL)
	{
	printf("PATH environment variable not found\n");
	return;
	}

    /* Make a copy of the PATH variable to avoid modifying the original */
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror("strdup");
	return;
	}

    /* Tokenize the PATH variable by colon */
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
	printf("%s\n", token); /* Print each directory */
	token = strtok(NULL, ":"); /* Get the next token */
	}

    /* Free the allocated memory for path_copy */
	free(path_copy);
}

/**
 * main - Entry point of the program.
 *
 * This function calls print_path_dirs to print each directory in the
 * PATH environment variable.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	print_path_dirs();
	return (0);
}
