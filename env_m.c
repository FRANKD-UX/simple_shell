#include "sshell.h"

/**
 * env_get_key - Gets the value of an environment variable
 * @key: The environment variable of interest
 * @data: Structure of the program's data
 * Return: A pointer to the value of the variable or NULL if it doesn't exist
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

char *env_get_key(char *key, p_data *data)
{
	int x, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_length) &&
		 data->env[x][key_length] == '=')
		{
			return (data->env[x] + key_length + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - Overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: Name of the variable to set
 * @value: New value
 * @data: Structure of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, p_data *data)
{
	int x, key_length = 0, newkey = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_length) &&
		 data->env[x][key_length] == '=')
		{
			newkey = 0;
			free(data->env[x]);
			break;
		}
	}
	data->env[x] = str_concat(str_duplicate(key), "=");
	data->env[x] = str_concat(data->env[x], value);

	if (newkey)
	{
		data->env[x + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - Remove a key from the environment
 * @key: The key to remove
 * @data: The sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */

int env_remove_key(char *key, p_data *data)
{
	int x, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_length) &&
		 data->env[x][key_length] == '=')
		{
			free(data->env[x]);

			x++;
			for (; data->env[x]; x++)
			{
				data->env[x - 1] = data->env[x];
			}
				data->env[x - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */

void print_environ(p_data *data)
{
	int y;

	for (y = 0; data->env[y]; y++)
	{
		_print(data->env[y]);
		_print("\n");
	}
}
