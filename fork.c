#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * fork_example - fork example function
 *
 * Return: Always 0.
 */
void fork_example(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
}

