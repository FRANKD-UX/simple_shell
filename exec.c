#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * run_ls - Executes the `ls -l /usr/` command using execve
 *
 * Return: Nothing
 */
void run_ls(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
}

