#include "shell.h"

/**
 * execute_command - Executes a command.
 * @args: The arguments for the command.
 */

void execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
	/*No command was entered*/
	return;
	}

	pid = fork();/*Fork a child process*/
	if (pid == 0)
	{
	/*Child process*/
	if (execvp(args[0], args) == -1)
	{
	perror("Error");
	}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	/*Error forking*/
	perror("Error");
	}
	else
	{
	/*Parent process waits for the child to finish*/
	do {
		waitpid(pid, &status, WUNTRACED);
	}
while (!WIFEXITED(status) && !WIFSIGNALED(status))
	}
}
