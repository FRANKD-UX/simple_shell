#include "shell.h"

/**
 * parse_command - Tokenizes a command string into arguments
 * @command: The command string
 *
 * Return: An array of arguments
 */
char **parse_command(char *command)
{
	char **argv;
	char *token;
	int i = 0;

	/* Allocate memory for arguments array */
	argv = malloc(10 * sizeof(char *)); /* Assume max of 10 arguments */
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the command string */
	token = strtok(command, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL; /* Null-terminate the array of arguments */

	return (argv);
}

