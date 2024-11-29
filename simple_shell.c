#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

/**
 * handle_getline_error - Handles potential errors from getline.
 * @read: The return value from getline.
 *
 * Return: Void.
 */
void handle_getline_error(ssize_t read)
{
	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
}

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
	pid_t pid;

	while (1)
	{
		printf(PROMPT);
		read = getline(&line, &len, stdin);
		handle_getline_error(read);  /* Call the error handling function */

		line[strcspn(line, "\n")] = '\0';
		command = line;
		argv[0] = command;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(command, argv, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
