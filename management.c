#include "shell.h"

/**
 * print_a - Prints aliases from the alias list, or a specific alias if provided.
 * @data: A pointer to the `program_data` structure containing the alias list.
 * @alias: A pointer to a null-terminated string representing the alias name to print.
 *         If NULL, all aliases are printed.
 * Return: 0 on success.
 */
int print_a(program_data *data, char *alias)
{
	int x, y, alias_length;
	char buffer[250] = {'\0'};

	/* Check if the alias list exists */
	if (data->alias_list)
	{
		alias_length = string_l(alias);
		for (x = 0; data->alias_list[x]; x++)
		{
			/* Print the alias if no specific alias is provided */
			if (!alias || (string_c(data->alias_list[x], alias, alias_length) &&
				data->alias_list[x][alias_length] == '='))
			{
				/* Copy the alias name into the buffer up to the '=' character */
				for (y = 0; data->alias_list[x][y]; y++)
				{
					buffer[y] = data->alias_list[x][y];
					if (data->alias_list[x][y] == '=')
						break;
				}
				buffer[y + 1] = '\0';
				buffer_p(buffer, "'");
				buffer_p(buffer, data->alias_list[x] + y + 1);
				/* Append the alias value */
				buffer_p(buffer, "'\n");
				print1(buffer);
			}
		}
	}
	return (0);
}

/**
 * get_a - Retrieves the value associated with a given alias name.
 * @data: A pointer to the `program_data` structure containing the alias list.
 * @name: A pointer to a null-terminated string representing the alias name.
 * Return: A pointer to the value associated with the alias if found, otherwise NULL.
 */
char *get_a(program_data *data, char *name)
{
	int x, alias_length;

	/* Validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = string_l(name);

	/* Iterate through the alias list to find a match */
	for (x = 0; data->alias_list[x]; x++)
	{
		if (string_c(name, data->alias_list[x], alias_length) &&
			data->alias_list[x][alias_length] == '=')
		{
			return (data->alias_list[x] + alias_length + 1);
		}
	}
	/* Return NULL if the alias is not found */
	return (NULL);
}

/**
 * set_a - Sets or updates an alias in the program data.
 * @alias_str: A pointer to a null-terminated string representing the alias.
 *             The string should be in the format "alias=value".
 * @data: A pointer to the `program_data` structure containing the alias list.
 * Return: 0 on success, 1 if the alias string or alias list is invalid.
 */
int set_a(char *alias_str, program_data *data)
{
	int x, y;
	char buffer[250] = {'\0'}, *temp = NULL;

	if (alias_str == NULL || data->alias_list == NULL)
		return (1);

	/* Extract the alias name and check if the value is another alias */
	for (x = 0; alias_str[x]; x++)
	{
		if (alias_str[x] != '=')
			buffer[x] = alias_str[x];
		else
		{
			/* Check if the value of the alias is another alias */
			temp = get_a(data, alias_str + x + 1);
			break;
		}
	}

	for (y = 0; data->alias_list[y]; y++)
	{
		if (string_c(buffer, data->alias_list[y], x) &&
			data->alias_list[y][x] == '=')
		{
			free(data->alias_list[y]);
			break;
		}
	}

	if (temp)
	{
		buffer_p(buffer, "=");
		buffer_p(buffer, temp);
		data->alias_list[y] = string_d(buffer);
	}
	else
	{
		data->alias_list[y] = string_d(alias_str);
	}
	return (0);
}

