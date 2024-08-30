#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;

	/* Fork a new process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		/* Child process */
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		/* Parent process */
		wait(&status);
		printf("Oh, it's all better now\n");
	}

	return (0);
}

