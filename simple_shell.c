#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *command;
	char *argv[] = {NULL, NULL};
	int status;

	while (1)
	{
		printf(PROMPT);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		line[strcspn(line, "\n")] = '\0'; /* Remove trailing newline */
		command = line;
		argv[0] = command;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			if (execve(command, argv, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	free(line);
	return (0);
}
