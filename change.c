#include "shell.h"
/**
 * change - executing command with entire path variables.
 * data - a pointer to the program's data
 * return - On success, return zero, else, return -1.
 */
int change(program_data *data)
{
	int z = 0, status;
	pid_t pidd;

	z = list(data); /* check program builtins */
	if (z != -1)/* if program was found in built ins */
		return (z);

	/* check for program file system */
	z = find(data);
	if (z)
	{
		return (z); /* if not found */
	}
	else /*alternatively*/
	{
		pidd = fork(); /* child process */
		if (pidd == -1)
		{
			perror(data->command_name); /* if fork call fails */
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			z = execve(data->tokens[0], data->tokens, data->env);
			if (z == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status); /*parent process*/
			if (WIFEXITED(stat))
				errno = WEXITSTATUS(stat);
			else if (WIFSIGNALED(stat))
				errno = 128 + WTERMSIG(stat);
		}
	}
	return (0);
}
/*Code by Frank Ndlovu and Nomcebo Mncina*/
