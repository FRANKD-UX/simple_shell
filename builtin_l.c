#include "sshell.h"

/**
 * builtins_list - Search for match and execute the builtin
 * @data: Structure for the program's data
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 * Authors: Frank Ndlovu and Nomcebo Mncina
 **/

int builtins_list(p_data *data)
{
	int i;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	for (i = 0; options[i].builtin != NULL; i++)
	{
		if (str_compare(options[i].builtin, data->command_name, 0))
		{
			return (options[i].function(data));
		}
	}
	return (-1);
}
