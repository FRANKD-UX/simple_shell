#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char buffer[1024];
	char *argv[2];
	pid_t pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (fgets(buffer, 1024, stdin) == NULL) /* Handle Ctrl+D */
			break;
		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline */

		argv[0] = buffer;
		argv[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("./shell");
			return (1);
		}
		else if (pid > 0)
			wait(&status);
		else
			perror("Error forking process");
	}
	return (0);
}

