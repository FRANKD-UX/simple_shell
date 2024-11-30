#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT "simple_shell$ "

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[] = { NULL, NULL };
	char *envp[] = { NULL };
	pid_t pid;
	int status;

	while (1)
	{
		printf(PROMPT);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break; /* Handle Ctrl+D (EOF) */
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character from getline() */
		line[read - 1] = '\0';

		argv[0] = line;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			if (execve(line, argv, envp) == -1)
			{
				perror(line);
			exit(EXIT_FAILURE);
			}
		} 
		else 
		{
			/* Parent process */
			wait(&status);
		}
	}

	free(line);
	return (0);
}
