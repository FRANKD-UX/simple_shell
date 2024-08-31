#include <stdio.h>
#include "main.h"

/**
 * main - prints all command line arguments
 * @av: array of command line arguments
 * @ac: number of command line arguments (not used)
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	(void)ac;
	/* Loop through the array of arguments */
	while (*av)
	{
	/* Print the current argument */
	printf("%s\n", *av);
	/* Move to the next argument */
	av++;
	}

	return (0);
}
