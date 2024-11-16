#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_builtin - Handles built-in commands like exit
 * @args: Parsed command arguments
 *
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free_tokens(args);
		exit(0);
	}

	return (0);
}
