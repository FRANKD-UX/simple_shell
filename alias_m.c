#include "shell.h"

/**
 * print_alias - Add, remove or show aliases
 * @data: Structure for the program's data
 * @alias: Name of the alias to be printed
 * Return: Zero if sucess, or other number if its declared in the arguments
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

int print_alias(p_data *data, char *alias)
{
	int x, y, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (x = 0; data->alias_list[x]; x++)
		{
			if (!alias || (str_compare(data->alias_list[x], alias, alias_length)
				&&	data->alias_list[x][alias_length] == '='))
			{
				for (y = 0; data->alias_list[x][y]; y++)
				{
					buffer[y] = data->alias_list[x][y];
					if (data->alias_list[x][y] == '=')
						break;
				}
				buffer[y + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[x] + y + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */

char *get_alias(p_data *data, char *name)
{
	int x, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (x = 0; data->alias_list[x]; x++)
	{
		if (str_compare(name, data->alias_list[x], alias_length) &&
			data->alias_list[x][alias_length] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (data->alias_list[x] + alias_length + 1);
		}
	}
	return (NULL);

}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int set_alias(char *alias_string, p_data *data)
{
	int x, y;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (x = 0; alias_string[x]; x++)
		if (alias_string[x] != '=')
			buffer[x] = alias_string[x];
		else
		{
			temp = get_alias(data, alias_string + x + 1);
			break;
		}

	for (y = 0; data->alias_list[y]; y++)
		if (str_compare(buffer, data->alias_list[y], x) &&
			data->alias_list[y][x] == '=')
		{/* if the alias alredy exist */
			free(data->alias_list[y]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[y] = str_duplicate(buffer);
	}
	else
		data->alias_list[y] = str_duplicate(alias_string);
	return (0);
}
