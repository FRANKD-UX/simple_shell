
#include "shell.h"

/**
 * builtin_exit - exit of the program with the status
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int exit_out(program_data *data)
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
		errno = string_to_num(data->tokens[1]);
	}
	free_data(data);
	exit(errno);
}

/**
 * cd_in - change the current directory
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int cd_in(program_data *data)
{
	char *dir_home = get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (string_c(data->tokens[1], "-", 0))
		{
			dir_old = get_key("OLDPWD", data);
			if (dir_old)
				error_code = work_directory(data, dir_old);
			print1(get_key("PWD", data));
			print1("\n");

			return (error_code);
		}
		else
		{
			return (work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (work_directory(data, dir_home));
	}
	return (0);
}

/**
 * set_work_directory - set the work directory
 * @data: struct for the program's data
 * @new_dir: path to be set as work directory
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int work_directory(program_data *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!string_c(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		set_key("PWD", new_dir, data);
	}
	set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * builtin_help - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int help(program_data *data)
{
	int x, l = 0;
	char *ms[6] = {NULL};

	ms[0] = MSG_HELP;

	/* validate args */
	if (data->tokens[1] == NULL)
	{
		print1(ms[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	ms[1] = HELP_EXIT_OUT_MSG;
	ms[2] = HELP_ENV_MSG;
	ms[3] = HELP_SET_ENV_MSG;
	ms[4] = HELP_UNSET_ENV_MSG;
	ms[5] = HELP_CD_IN_MSG;

	for (x = 0; ms[x]; x++)
	{
		/*print the length of string */
		l = string_l(data->tokens[1]);
		if (string_c(data->tokens[1], ms[x], l))
		{
			print1(ms[x] + l + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * more_alias - add, remove or show aliases
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int more_alias(program_data *data)
{
	int x = 0;

	/* if there are no arguments, print all environment */
	if (data->tokens[1] == NULL)
		return (print_a(data, NULL));

	while (data->tokens[++x])
	{/* if there are arguments, set or print each env variable*/
		if (count_(data->tokens[x], "="))
			set_a(data->tokens[x], data);
		else
			print_a(data, data->tokens[x]);
	}

	return (0);
}
/*This is cide by Frank Dlamini and Nomcebo Mncina*/
