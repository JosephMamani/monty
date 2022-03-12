#include "monty.h"
/**
 * inicialize_data - inicialize the struct with the info of the program
 * @data: pointer to the structure of data
 * @UNUSED: array of arguments pased to the program execution
 * @argv: number of values received from the command line
 */
void inicialize_data(data_of_program *data, int argc UNUSED, char *argv[])
{
	 stack_p **stack = NULL;
	 stack_p *head = NULL;
  /* just 'monty' on the command line or more than two arguments */
	data->file_path = argv[1];
	data->line_number = 0;
	data->lines = NULL;
	data->words = NULL;
	data->stack = stack;
	data->head = head;
}
