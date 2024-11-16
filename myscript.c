#include "shell.h"

/**
 * main - Non-interactive script entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc > 1)
		run_non_interactive_mode(argv[1]);
	else
	{
		fprintf(stderr, "Usage: %s <script_file>\n", argv[0]);
		return (1);
	}

	return (0);
}
