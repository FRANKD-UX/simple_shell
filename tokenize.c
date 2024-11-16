#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - Splits a string into tokens
 * @line: Input string
 *
 * Return: Array of tokens
 */
char **tokenize(const char *line)
{
	char **tokens = NULL;
	char *token, *line_copy;
	size_t count = 0;

	if (!line)
		return (NULL);

	line_copy = strdup(line);
	if (!line_copy)
		return (NULL);

	token = strtok(line_copy, " \t\n");
	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (count + 2));
		if (!tokens)
		{
			free(line_copy);
			return (NULL);
		}
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, " \t\n");
	}
	if (tokens)
		tokens[count] = NULL;

	free(line_copy);
	return (tokens);
}
