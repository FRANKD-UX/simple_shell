#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 * @argv: Argument vector
 */
void execute_command(char *argv[])
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid = fork();

	if (pid == -1)
	{
		/* Error handling */
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process: Execute the command */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: Wait for the child to finish */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

