#include "shell.h"
#include <stdlib.h>

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		/* Non-interactive mode */
		run_non_interactive_mode(argv[1]);
	}
	else
	{
		/* Interactive mode */
		run_interactive_mode();
	}
	return (0);
}

