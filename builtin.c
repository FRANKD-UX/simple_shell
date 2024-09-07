#include "shell.h"

/**
 * handle_builtin_commands - Handles built-in commands.
 * @cmd: The command to handle.
 * @args: Arguments for the command.
 *
 * Return: 1 if the command was handled, 0 otherwise.
 */
int handle_builtin_commands(char *cmd, char **args)
{
	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "history") == 0)
	{
		print_history();
		return (1);
	}
	return (0);
}

