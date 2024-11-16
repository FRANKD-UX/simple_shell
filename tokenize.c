#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * tokenize - Splits a command string into tokens
 * @command: Command string
 *
 * Return: Array of tokens
 */
char **tokenize(const char *command)
{
	char **tokens = NULL;
	char *token, *command_copy;
	size_t count = 0;

	command_copy = strdup(command);
	if (!command_copy)
		return (NULL);

	token = strtok(command_copy, " \t\n");
	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (count + 2));
		if (!tokens)
		{
			free(command_copy);
			return (NULL);
		}
		tokens[count++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[count] = NULL;
	free(command_copy);
	return (tokens);
}

/**
 * free_tokens - Frees a tokenized array
 * @tokens: Array of tokens to free
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}

