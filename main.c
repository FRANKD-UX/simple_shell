#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	(void)argc;

	if (isatty(STDIN_FILENO))
		run_interactive_mode();
	else
		run_non_interactive_mode(argv[1]);

	return (0);
}

/**
 * run_interactive_mode - Handles shell in interactive mode
 */
void run_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		execute_command(line);
	}
}

/**
 * run_non_interactive_mode - Handles shell in non-interactive mode
 * @script_path: Path to script file
 */
void run_non_interactive_mode(const char *script_path)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;

	if (!script_path)
	{
		fprintf(stderr, "Error: No script file provided.\n");
		return;
	}

	file = fopen(script_path, "r");
	if (!file)
	{
		perror("Error opening file");
		return;
	}

	while (getline(&line, &len, file) != -1)
		execute_command(line);

	free(line);
	fclose(file);
}

