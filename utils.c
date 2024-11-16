#include "shell.h"

/**
 * free_tokens - Frees memory allocated for tokens.
 * @tokens: The array of tokens to free.
 */
void free_tokens(char **tokens)
{
	int i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}

/**
 * print_error - Prints an error message to stderr.
 * @msg: The error message to print.
 */
void print_error(const char *msg)
{
	if (msg)
	{
		fprintf(stderr, "%s\n", msg);
	}
}
