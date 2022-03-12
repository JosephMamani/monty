#include "monty.h"
/**
 * delete_at_end - delete node at index position
 * @stack: pointer to the head of stack
 * Return: 1 if succes -1 if failed
 */
void delete_at_end(stack_p *stack, stack_p  **head)
{
	stack_p *pop = NULL;

	pop = stack;
	if (pop->next == NULL)
	{
		if(pop->prev == NULL)
		{
			stack = NULL;
			free(pop);
			*head = NULL;
			/*	free(stack);*/
		}
		else
		{
			pop->prev->next = NULL;
			free(pop);
		}
		return;
	}
	delete_at_end(pop->next, head);
}
