#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/* Declare the global variable `environ` */
extern char **environ;

/**
 * main - Prints the environment variables using the global variable `environ`.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **env = environ;/*Initialize pointer to the global environment array*/
    /*Print each environment variable*/
	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}

	return (0);
}
