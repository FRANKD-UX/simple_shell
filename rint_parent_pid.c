#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints the PID of the parent process.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();/*Retrieve the parent process ID*/

	printf("Parent PID: %d\n", parent_pid);

	return (0);
}
