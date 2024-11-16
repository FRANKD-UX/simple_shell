#include "shell.h"
#include <string.h>

void execute_command(const char *command)
{
    pid_t pid;
    int status;
    char **args;

    /* Tokenize command */
    args = tokenize(command);
    if (args == NULL)
    {
        perror("Failed to tokenize command");
        return;
    }

    /* Handle built-in commands */
    if (handle_builtin(args))
    {
        free_tokens(args);
        return;
    }

    /* Fork process */
    pid = fork();
    if (pid == -1)
    {
        perror("Error during fork");
        free_tokens(args);
        return;
    }

    if (pid == 0) /* Child process */
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        do {
            wait(&status);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free_tokens(args);
}

