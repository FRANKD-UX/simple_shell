#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _unsetenv - Remove an environment variable.
 * @name: The name of the environment variable to remove.
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	char **env;
	size_t len = strlen(name);
	int found = 0;

	if (name == NULL || *name == '\0')
	return (-1);

	for (env = environ; *env != NULL; env++)
	{
	if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
	{
		found = 1;
		break;
	}
	}

	if (found)
	{
	for (; *env != NULL; env++)
		*env = *(env + 1);
	return (0);
	}

	return (-1);
}

/**
 * main - Test the _unsetenv function.
 * Return: 0 on success.
 */
int main(void)
{
	const char *env_var = "TEST_VAR";
	char *test_value;

	/*Set an environment variable for testing*/
	setenv(env_var, "some_value", 1);

	/*Print the environment variable before removal*/
	test_value = getenv(env_var);
	printf("Before removal: %s=%s\n", env_var, test_value ? test_value : "NULL");

	/*Remove the environment variable*/
	if (_unsetenv(env_var) == 0)
	printf("Environment variable '%s' removed successfully.\n", env_var);
	else
	printf("Failed to remove environment variable '%s'.\n", env_var);

	/*Print the environment variable after removal*/
	test_value = getenv(env_var);
	printf("After removal: %s=%s\n", env_var, test_value ? test_value : "NULL");

	return (0);
}
