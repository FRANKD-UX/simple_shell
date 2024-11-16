#include "shell.h"
#include <stdlib.h>

/**
 * free_tokens - Frees an array of tokens
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
