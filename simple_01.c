#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  /* Include this for EXIT_FAILURE */

/**
 * execute_command - Executes a command using fork and execvp
 * @cmd: The command to execute
 * @args: The arguments for the command
 *
 * This function forks the process and then uses execvp to
 * execute the specified command. It waits for the child
 * process to finish before returning.
 */
void execute_command(char *cmd, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(cmd, args) == -1)
		{
			perror("execvp failed");
		}
		_exit(EXIT_FAILURE);  /* Use EXIT_FAILURE */
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("fork failed");
	}
	else
	{
		/* Parent process */
		do {
			if (waitpid(pid, &status, WNOHANG) == -1)
			{
				perror("waitpid failed");
				break;
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - Entry point of the program
 *
 * This function sets up a command and its arguments, and
 * then calls execute_command to run the command.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command = "ls";
	char *args[] = {"ls", "-l", NULL};

	execute_command(command, args);

	return (0);
}

