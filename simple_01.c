#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char *command) {
	pid_t pid;
	int status;

	/*Fork a child process*/
	pid = fork();
	if (pid == 0) {
	perror("fork");
	exit(EXIT_FAILURE);
	}

	if (pid == 0) { /*Child process*/
        /*Execute the command*/
	execlp(command, command, (char *)NULL);
        /*If execlp returns, it must have failed*/
	perror("execlp");
	exit(EXIT_FAILURE);
	} else { /*Parent process*/
        /*Wait for the child process to finish*/
	do {
	wpid = waitpid(pid, &status, WNOHANG);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

int main() {
	char command[MAX_COMMAND_LENGTH];
    
	while (1) {
        /*Display the prompt*/
	printf("simple_shell> ");
	fflush(stdout);

        /*Read a command from the user*/
	if (fgets(command, sizeof(command), stdin) == NULL) {
	if (feof(stdin)) { /*End of file (Ctrl+D)*/
		printf("\n");
	break;
	} else {
		perror("fgets");
		continue;
	}
	}

        /*Remove the newline character at the end of the command*/
	command[strcspn(command, "\n")] = '\0';

        /*If the command is empty, continue to the next iteration*/
	if (strlen(command) == 0) {
		continue;
	}

        /*Execute the command*/
	execute_command(command);
	}

	return 0;
}
