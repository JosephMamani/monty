#include "monty.h"
/**
 * list - search for match and execute the associate builtin
 * @data: struct for the program's data
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
void list(data_of_program *data)
{
	int iterator = 0;
	int found = 0;
	instruction_t options[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"swap", swap},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{NULL, NULL}
	};

	/*walk through the structure*/
	for (iterator = 0; options[iterator].opcode != NULL; iterator++)
	{
		/*if there is a match between the given command and a builtin,*/
		if (str_compare(options[iterator].opcode, data->words[0], 0) == 1)
		{
			options[iterator].function(data);
			found = 1;
		}
	}
	if (found == 0)
		error(data, 2);

}
