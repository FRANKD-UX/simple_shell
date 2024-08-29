#include "main.h"

/**
 * parse_command - Parses the input command.
 *
 * @input: The input string.
 *
 * Return: An array of arguments.
 */
char **parse_command(char *input)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * MAX_ARGS);
	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}


