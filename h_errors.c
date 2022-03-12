#include "monty.h"
/**
 * error - print error message to stout and exit_failure to stderr
 * @data: data of program
 * @error: number of the error
 */
void error(data_of_program *data, int error)
{
	if (error == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (error == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", data->file_path);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", data->line_number,
						data->words[0]);
	if (error == 3)
		fprintf(stderr, "Error: malloc failed\n");
	if (error == 4)
		fprintf(stderr, "L%d: usage: push integer\n", (data->line_number));
	if (error == 5)
		fprintf(stderr, "L%d: can't pint, stack empty\n", data->line_number);
	if (error == 6)
		fprintf(stderr, "L%d: can't pop an empty stack\n", data->line_number);
	if (error == 7)
		fprintf(stderr, "L%d: can't swap, stack too short\n", data->line_number);
	if (error == 8)
		fprintf(stderr, "L%d: can't add, stack too short\n", data->line_number);
	if (error == 9)
		fprintf(stderr, "L%d: can't sub, stack too short\n", data->line_number);
	if (error == 10)
		fprintf(stderr, "L%d: can't mul, stack too short\n", data->line_number);
	if (error == 11)
		fprintf(stderr, "L%d: can't div, stack too short\n", data->line_number);
	if(data->head != NULL)
		free_all(data);
  free((void *)data->words[0]);
	free(data->words);
	exit(EXIT_FAILURE);
}
