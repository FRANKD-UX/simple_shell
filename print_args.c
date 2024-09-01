#include <stdio.h>
#include "main.h"

/**
 * print_args - prints all command line arguments
 * @av: array of command line arguments
 */
void print_args(char **av)
{
	while (*av)
	{
		/* Print the current argument */
		printf("%s\n", *av);
		/* Move to the next argument */
		av++;
	}
}

