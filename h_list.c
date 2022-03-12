#include "monty.h"

/**
 * print_stack - print all the nodes of the stack
 * @stack: pointer to head of the stack
 * Return: number of fields printed
 */
void print_stack(stack_p *stack)
{
	if (!stack)
		return;
	print_stack(stack->next);
	printf("%d\n", stack->n);
}

/**
 * stack_len - return the number of elements in the stack
 * @stack: pointer to head of the stack
 * Return: number of nodes in the stack
 */
size_t stack_len(stack_p **stack)
{
	size_t i = 0;

	if (stack == NULL || *stack == NULL)
		return (0);
	for (i = 0; *stack != NULL; i++)
	{
		*stack = (*stack)->next;
	}
	return (i);
}

/**
 * add_node - add node in stack
 * @stack: pointer to head of the stack
 * @n: value to assign to the new node
 * @data : data of program
 * Return: new node's direction
 */
stack_t *add_node(stack_p **stack, int n, data_of_program *data)
{
	stack_p *new = NULL;

	if (!stack)
		return (NULL);

	new = malloc(sizeof(stack_p));
	if (new == NULL)
		error(data, 3);

	new->prev = NULL;
	new->n = n;

	if (!*stack)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;

	return ((void *)stack);
}

/**
 * add_node_end - add node at end of a stack
 * @stack: pointer to head of stack
 * @n: return the number of elements in the stack
 * @data: ...
 * Return: new node's direction
 */
stack_t *add_node_end(stack_p **stack, int n, data_of_program *data)
{
	stack_p *new = NULL, *prev = NULL;

	if (!stack)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error(data, 3);
	new->n = n;
	new->next = NULL;

	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		prev = *stack;
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		new->prev = prev;
		prev->next = new;
	}
	return ((void *)new);
}

/**
 * free_stack - free stack
 * @stack: pointer to head of the stack
 */
void free_stack(stack_p **stack)
{
	stack_p *prev = NULL;

	if (!*stack)
		return;

	do {
		prev = (*stack)->next;
		(*stack)->prev = NULL;
		free(*stack);
		(*stack) = prev;
	} while ((*stack)->next != NULL);

	free(stack);
}
