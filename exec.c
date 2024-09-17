#include "sshell.h"

/**
 * execute - Execute a command with its entire path variables.
 * @data: A pointer to the program's data
 * Return: If success returns zero, otherwise, return -1.
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

int execute(p_data *data)
{
	int ret_v = 0, status;
	pid_t pidd;

	ret_v = builtins_list(data);
	if (ret_v != -1)
		return (ret_v);

	ret_v = find_program(data);
	if (ret_v)
	{
		return (ret_v);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			ret_v = execve(data->tokens[0], data->tokens, data->env);
			if (ret_v == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}

