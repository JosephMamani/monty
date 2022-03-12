#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @data: data of program
 */
void free_all(data_of_program *data)
{
	while(data->head != NULL)
	{
        free_til_end(data->head, &(data->head));
	}
	return;
}
/**
 * delete_at_end - delete node at index position
 * @stack: pointer to the head of stack
 * Return: 1 if succes -1 if failed
 */
void free_til_end(stack_p *stack, stack_p  **head)
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
