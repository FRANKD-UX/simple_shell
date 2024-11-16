#include "shell.h"
#include <stdlib.h>

/**
 * execute_command - Executes a shell command
 * @command: Command to execute
 */
void execute_command(const char *command)
{
	char **args;
	pid_t pid;

	args = tokenize(command);
	if (args == NULL)
		return;

	if (!handle_builtin(args))
	{
		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
				perror("Error executing command");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Error forking");
		}
		else
		{
			wait(NULL);
		}
	}

	free_tokens(args);
}
