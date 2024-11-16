#include "shell.h"
#include <stdio.h>

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		run_non_interactive_mode(argv[1]);
	}
	else if (argc == 1)
	{
		run_interactive_mode();
	}
	else
	{
		fprintf(stderr, "Usage: %s [script_path]\n", argv[0]);
		return (1);
	}

	return (0);
}

