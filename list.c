#include "shell.h"
/**
* list - search for list match and execute the associate builtin
* @data: structure for the data in program
* return: if there is a match
* else return -1.
 **/
int list(program_data *data)
{
	int i;
	built_in options[] = {
		{"exit", exit_out},
		{"help", help},
		{"cd", cd_in},
		{"alias", more_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	for (x = 0; options[x].built_in != NULL; x++)
	{
		if (string_c(options[x].built_in, data->command_name, 0)) /*upon match, between the biultin and given command*/
		{
			return (options[x].function(data)); /*execute and return the return value of the function*/

		}
	}
	return (-1); /*when there is no match, return -1 */

}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/

