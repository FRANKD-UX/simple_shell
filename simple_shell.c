#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* Function Prototypes */
void execute_command(char **args);
char *resolve_path(char *command);
void free_args(char **args);
char **parse_input(char *input);

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		/* Display prompt */
		printf("#cisfun$ ");
		fflush(stdout);

		/* Read user input */
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}

		/* Remove newline character */
		line[strcspn(line, "\n")] = '\0';

		/* Parse input into arguments */
		args = parse_input(line);
		if (!args)
			continue;

		/* Exit shell */
		if (strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			break;
		}

		/* Execute command */
		execute_command(args);
		free_args(args);
	}

	return (0);
}

/**
 * parse_input - Parses the input string into arguments.
 * @input: The input string.
 *
 * Return: Array of arguments or NULL if input is empty.
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token;
	size_t idx = 0, bufsize = BUFFER_SIZE;

	if (!input || strlen(input) == 0)
		return (NULL);

	args = malloc(sizeof(char *) * bufsize);
	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " ");
	while (token)
	{
		args[idx++] = strdup(token);
		if (idx >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = realloc(args, sizeof(char *) * bufsize);
			if (!args)
			{
				perror("realloc");
				return (NULL);
			}
		}
		token = strtok(NULL, " ");
	}
	args[idx] = NULL;

	return (args);
}

/**
 * execute_command - Forks a child process to execute a command.
 * @args: The command and its arguments.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *command;
	struct stat st;

	/* Resolve command using PATH if not an absolute/relative path */
	command = args[0];
	if (stat(command, &st) != 0)
	{
		command = resolve_path(args[0]);
		if (!command)
		{
			fprintf(stderr, "%s: Command not found\n", args[0]);
			return;
		}
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command, args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/* Parent process waits */
		wait(&status);
	}
	else
	{
		perror("Fork failed");
	}

	/* Free the resolved command if allocated */
	if (command != args[0])
		free(command);
}

/**
 * resolve_path - Searches for a command in the PATH environment variable.
 * @command: The command to search for.
 *
 * Return: Full path to the command, or NULL if not found.
 */
char *resolve_path(char *command)
{
	char *path = getenv("PATH");
	char *path_dup = strdup(path);
	char *dir, *full_path = NULL;
	struct stat st;

	if (!path_dup)
		return (NULL);

	dir = strtok(path_dup, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_dup);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_dup);
			return (full_path); /* Found the command */
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL); /* Not found */
}

/**
 * free_args - Frees an array of arguments.
 * @args: The array of arguments.
 */
void free_args(char **args)
{
	size_t i = 0;

	if (!args)
		return;

	while (args[i])
		free(args[i++]);

	free(args);
}

