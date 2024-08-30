#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ; /* Global environment variable array */

/**
 * _setenv - Changes or adds an environment variable.
 * @name: The name of the environment variable to set.
 * @value: The value of the environment variable.
 * @overwrite: If non-zero, existing variables with the same name will be overwritten.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    char **env;
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    char *new_var;
    int found = 0;

    /* Validate input */
    if (name == NULL || *name == '\0' || value == NULL)
        return -1;

    /* Construct the new environment variable string */
    new_var = malloc(name_len + value_len + 2); /* +2 for '=' and '\0' */
    if (new_var == NULL)
        return -1;

    sprintf(new_var, "%s=%s", name, value);

    /* Iterate through the environment variables */
    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            /* Variable found */
            if (overwrite)
            {
                /* Replace the existing variable */
                *env = new_var;
                return 0;
            }
            else
            {
                /* Do not overwrite, free the new variable */
                free(new_var);
                return 0;
            }
        }
    }

    /* Variable not found, need to add it */
    /* Find the size of the current environment */
    int size;
    for (size = 0; environ[size] != NULL; size++)
        ;

    /* Reallocate the environment array to add the new variable */
    char **new_environ = realloc(environ, sizeof(char *) * (size + 2)); /* +2 for the new variable and NULL */
    if (new_environ == NULL)
    {
        free(new_var);
        return -1;
    }
    environ = new_environ;
    environ[size] = new_var;
    environ[size + 1] = NULL;

    return 0;
}

/**
 * main - Entry point to test the _setenv function
 *
 * Return: Always 0.
 */
int main(void)
{
    const char *name = "MY_VAR";
    const char *value = "my_value";

    /* Set environment variable */
    if (_setenv(name, value, 1) == 0)
    {
        /* Print the environment variable to verify it was set */
        printf("Environment variable '%s' set to '%s'.\n", name, getenv(name));
    }
    else
    {
        printf("Failed to set environment variable '%s'.\n", name);
    }

    return 0;
}
