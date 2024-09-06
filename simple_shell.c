#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;
    char *args[] = {NULL}; /* args is an array of pointers to command arguments */

    while (1)
    {
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
        nread = getline(&input, &len, stdin);

        if (nread == -1) /* Handle EOF */
        {
            if (feof(stdin))
            {
                free(input);
                write(STDOUT_FILENO, "\n", 1);
                exit(EXIT_SUCCESS);
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }

        /* Remove newline character from input */
        if (input[nread - 1] == '\n')
            input[nread - 1] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) /* Child process */
        {
            execve(input, args, NULL);
            perror(input);
            exit(EXIT_FAILURE);
        }
        else /* Parent process */
        {
            waitpid(pid, &status, 0);
        }
    }

    free(input);
    return (0);
}

