#include "shell.h"

/**
 * tokenize_input - Tokenizes a string into an array of arguments
 * @input: The input string
 *
 * Return: Array of tokens or NULL on failure
 */
char **tokenize_input(const char *input)
{
	char **tokens = NULL;
	char *token, *input_copy;
	size_t i = 0, num_tokens = 0;

	if (input == NULL)
		return (NULL);

	input_copy = strdup(input);
	if (input_copy == NULL)
		return (NULL);

	/* Count tokens */
	token = strtok(input_copy, " \t\n");
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, " \t\n");
	}

	free(input_copy);

	/* Allocate memory for tokens */
	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	/* Tokenize the input */
	token = strtok(strdup(input), " \t\n");
	while (token)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
