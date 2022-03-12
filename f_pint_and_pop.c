#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @data: data of program
 */
void pint(data_of_program *data)
{
	stack_p *stack = NULL;

	stack = data->head;

	if (!data->head)
		error(data, 5);
/* loop to goes at the last element in stack */
	for (; stack->next != NULL; stack = stack->next)
	{}
	printf("%d\n", (stack->n));
}

/**
 * pop - removes the top element of the stack
 * @data: data of program
 */
void pop(data_of_program *data)
{
	if (!data->head)
		error(data, 6);
	delete_at_end(data->head, &(data->head));
/* Erase the first node */
/*	if(data->head->prev == NULL)
		free(data->head);*/
}
