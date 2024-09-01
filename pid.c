#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * print_pid - Prints the process ID and parent process ID.
 *
 * Return: void
 */
void print_pid(void)
{
	pid_t pid;
	pid_t ppid;

	pid = getpid();
	ppid = getppid();

	printf("Process ID: %d\n", pid);
	printf("Parent Process ID: %d\n", ppid);
}

/**
 * fork_and_print_pid - Forks a process and prints process IDs.
 *
 * Return: void
 */
void fork_and_print_pid(void)
{
	pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	printf("After fork\n");
	print_pid();
}

