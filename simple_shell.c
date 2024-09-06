#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * handle_command - Handles the execution of a command
 * @buffer: The command to be executed
 */
void handle_command(char *buffer)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execlp(buffer, buffer, (char *)NULL);
		perror(buffer);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * read_input - Displays the prompt and reads user input
 * @buffer: Pointer to buffer to store the input
 * @bufsize: Size of the buffer
 * Return: 0 on success, -1 on failure
 */
int read_input(char **buffer, size_t *bufsize)
{
	ssize_t bytes_read;

	write(STDOUT_FILENO, "#cisfun$ ", 9);

	bytes_read = getline(buffer, bufsize, stdin);

	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		perror("getline");
		return (-1);
	}

	if ((*buffer)[bytes_read - 1] == '\n')
		(*buffer)[bytes_read - 1] = '\0';

	return (0);
}

/**
 * main - Entry point of the shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	while (1)
	{
		if (read_input(&buffer, &bufsize) == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}

		handle_command(buffer);
	}

	free(buffer);
	return (0);
}

