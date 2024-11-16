#include "shell.h"

/**
 * handle_exit - Exits the shell with the specified status.
 * @args: The arguments passed to the exit command.
 */
void handle_exit(char **args)
{
	if (args[1])
		exit(atoi(args[1])); /* Exit with specified status */
	else
		exit(0); /* Default exit status */
}

/**
 * handle_cd - Changes the current working directory.
 * @args: The arguments passed to the cd command.
 */
void handle_cd(char **args)
{
	if (!args[1])
	{
		fprintf(stderr, "cd: missing argument\n");
		return;
	}
	if (chdir(args[1]) != 0)
		perror("cd");
}

/**
 * handle_env - Prints the environment variables.
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
