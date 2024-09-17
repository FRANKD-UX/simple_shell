#include "shell.h"

/**
 * builtin_exit - Exit of the program with the status
 * @data: Structure for the program's data
 * Return: Zero if success, or other number if its declared in the arguments
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

int builtin_exit(p_data *data)
{
	int x;

	if (data->tokens[1] != NULL)
	{
		for (x = 0; data->tokens[1][x]; x++)
			if ((data->tokens[1][x] < '0' || data->tokens[1][x] > '9')
				&& data->tokens[1][x] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_data(data);
	exit(errno);
}

/**
 * builtin_cd - Change the current directory
 * @data: Structure for the program's data
 * Return: Zero if success, or other number if its declared in the arguments
 */

int builtin_cd(p_data  *data)
{
	char *dir_home = env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = set_work_directory(data, dir_old);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_work_directory(data, dir_home));
	}
	return (0);
}

/**
 * set_work_directory - Set the work directory
 * @data: Structure for the program's data
 * @new_dir: Path to be set as work directory
 * Return: Zero if success, or other number if its declared in the arguments
 */

int set_work_directory(p_data *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, data);
	}
	env_set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * builtin_help - Shows the environment where the shell runs
 * @data: Structure for the program's data
 * Return: Zero if success, or other number if its declared in the arguments
 */

int builtin_help(p_data *data)
{
	int x, length = 0;
	char *message[6] = {NULL};

	message[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(message[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	message[1] = HELP_EXIT_MSG;
	message[2] = HELP_ENV_MSG;
	message[3] = HELP_SETENV_MSG;
	message[4] = HELP_UNSETENV_MSG;
	message[5] = HELP_CD_MSG;

	for (x = 0; message[x]; x++)
	{
		length = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], message[x], length))
		{
			_print(message[x] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * builtin_alias - Add, remove or show aliases
 * @data: Structure for the program's data
 * Return: Zero if success, or other number if its declared in the arguments
 */

int builtin_alias(p_data *data)
{
	int x = 0;

	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++x])
	{
		if (count_characters(data->tokens[x], "="))
			set_alias(data->tokens[x], data);
		else
			print_alias(data, data->tokens[x]);
	}
	return (0);
}
