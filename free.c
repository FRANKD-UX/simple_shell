#include "shell.h"
/**
* recurrent_data - frees the fields needed in each loop
* Frees allocated memory in the 'program_data'
* structure and resets pointers.This function
* cleans up resources associated with the 'program_data'
* structure by freeing dynamically allocated memory
* and setting pointers to NULL. It is used to prevent
* memory leaks and to ensure that the structure is
* properly cleaned up when it is no longer needed.
* @data: A pointer to a 'program_data' structure
* whose memory allocations are to be freed.
* returm: nothing
*/
void recurrent_data(program_data *data)
{
	if (data->tokens)
	/*Free memory allocated for tokens, if any*/
		free_pointers(data->tokens);
	/*Custom function to free array of pointers*/
	if (data->input_line)
	/*Free memory allocated for input line, if any*/
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);
	/*Standard library function to free memory*/

	data->input_line = NULL;
	/* Reset pointers to NULL to avoid dangling pointers*/
	data->command_name = NULL;
	data->tokens = NULL;
}
/**
* free_data - frees all field of the data
* Frees resources and memory associated with the
* 'program_data' structure. This function handles
* the cleanup of resources within the 'program_data'
* structure. It closes an open file descriptor, frees
* dynamically allocated memory for the environment
* variables and alias list, and resets internal data
* pointers to ensure no dangling references.
* @data: A pointer to a 'program_data' structure
* whose resources and memory need to be freed.
* return: nothing
**/
void free_data(program_data *data)
{
	if (data->file_descr != 0)
	/*Close the file descriptor if it is open*/
	{
		if (close(data->file_descr))
			perror(data->program_name);
		/*Print an error message if closing the file descriptor fails*/
	}
	/**
	 * Free memory and resources related to the input line, command
	 * name, tokens, environment variables, and alias list
	 **/
	recurrent_data(data);
	/*Free memory for input_line, command_name, and tokens*/
	free_pointers(data->env);
	/*Free memory for environment variables*/
	free_pointers(data->alias_list);
	/*Free memory for alias list*/
}
/**
 * free_pointers - frees each pointer of an array of pointers
 * and the array too
 * @array: array of pointers
 * return: nothing
 */
void free_pointers(char **array)
{
	int x;

	if (array != NULL)
	{
		for (x = 0; array[x]; x++)
			free(array[x]);

		free(array);/*Free the memory allocated for the array of pointers*/
		array = NULL; /*Set the array pointer to NULL to avoid dangling references*/
	}
}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/
