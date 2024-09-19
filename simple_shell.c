#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	char *args[2];
	int status;
	pid_t pid;

	while (1)
	{
		printf(PROMPT);
		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			continue;
		}

		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */

		if (strcmp(buffer, "exit") == 0)
			break;

		args[0] = buffer;
		args[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid == 0)
		{
			/* Child process */
			if (execve(args[0], args, environ) == -1)
			{
				perror(argv[0]);
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	return (0);
}

