#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/**
 * execute_cd - Changes the current directory.
 *
 * @args: An array of arguments.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
			return (0);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (0);
		}
	}
	return (1);
}

/**
 * execute_exit - Exits the shell.
 *
 * Return: Always returns 1.
 */
int execute_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * execute_pwd - Prints the current working directory.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int execute_pwd(void)
{
	char cwd[MAX_CMD_LEN];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (1);
	}
	else
	{
		perror("pwd");
		return (0);
	}
}

/**
 * execute_builtin - Executes a built-in command.
 *
 * @args: An array of arguments.
 *
 * Return: 1 if the command was executed, 0 otherwise.
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		return (execute_cd(args));
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		execute_exit();
	}
	else if (strcmp(args[0], "pwd") == 0)
	{
		return (execute_pwd());
	}

	return (0);
}

