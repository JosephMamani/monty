#include "monty.h"
/**
 * main - entry point and general management
 * @argv: argument values
 * @argc: argument counter
 * Return: 0 if success, other value if error
 */
int main(int argc, char *argv[])
{
	data_of_program data_struct, *data = &data_struct;
	char *delim_line = "\n", *delim_spc = " ", *token = NULL;
	
	if(argc < 2)
	{
		error(data, 0);
	}

	inicialize_data(data, argc, argv);
	/* open and read the data from file return a buffer to file data */
	open_file(data, argv);

	/*tokenize */
	token =	strtok(data->file_content, delim_line);
	while (token != NULL)
	{
		data->line_number = data->line_number + 1;
		data->words = _strtok(token, delim_spc, data);
		if (data->words[0] == NULL)
		{}
		else
		{
			list(data);
		}
		if(data->words != NULL)
		{
			free((void *)data->words[0]);
			free(data->words);
		}
		token =	strtok(NULL, delim_line);
	}
	free_all(data);
	return (0);
}
