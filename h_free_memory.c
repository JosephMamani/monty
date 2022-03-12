#include "monty.h"

/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array too
 * @array: array of pointers
 * Return: nothing
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (*array != NULL)
	{
		for (i = 0; array[i]; i++)
		{
			free(array[i]);
		}
		free(array);
		array = NULL;
	}
}

/**
 * free_all_data - free all field of the data structure
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_all_data(data_of_program *data)
{
	if (data->lines)
		free_array_of_pointers(data->lines);
	if (data->head)
		free(data->head);
	if (data->stack)
		free_stack(data->stack);
	if (data->words)
		free_array_of_pointers(data->words);
}
