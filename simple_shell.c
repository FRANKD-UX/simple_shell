#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

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
 * execute_command - Forks a child process to execute a command.
 * @command: The command to execute.
 *
 * Return: Void.
 */
void execute_command(char *command)
{
	pid_t pid;
	char *argv[] = {command, NULL};
	int status;

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

/**
 * list_directory_contents - Lists the contents of the current directory.
 *
 * Return: Void.
 */
void list_directory_contents(void)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
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

	while (1)
	{
		printf(PROMPT);
		read = getline(&line, &len, stdin);
		handle_getline_error(read);

		line[strcspn(line, "\n")] = '\0';
		command = line;

		if (strcmp(command, "ls") == 0)
		{
			list_directory_contents();
		}
		else
		{
			execute_command(command);
		}
	}

	free(line);
	return (0);
}
