#include <stdio.h>
#include "main.h"

/**
 * main - prints the environment
 * @ac: The number of command-line arguments (not used).
 * @av: The array of command-line arguments (not used).
 * @env: The array of environment variables.
 * Return: Always 0.
 */
int main (int ac, char **env)
{
	unsigned int i;
	(void)ac;
	i = 0;
	while (env[i] != NULL)
	{
	printf("%s\n", env[i]);
	i++;
	}
	return (0);
}
