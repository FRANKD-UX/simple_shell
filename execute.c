#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a command
 * @command: Command to execute
 */
void execute_command(const char *command)
{
	char **args;
	pid_t pid;

	args = tokenize(command);
	if (!args)
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
		else if (pid > 0)
			wait(NULL);
		else
			perror("Error forking process");
	}
	free_tokens(args);
}

