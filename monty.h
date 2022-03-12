#ifndef MONTY_H
#define MONTY_H

#include <stdio.h> /* For printf */
#include <unistd.h> /* For fork, execve */
#include <stdlib.h> /* For exit failure or success */
#include <string.h> /* For strtok, strlen */
#include <errno.h> /* For errno and perror */
#include <sys/types.h> /* For type pid */
#include <sys/wait.h> /* For wait */
#include <sys/stat.h> /* For use of stat function */
#include <fcntl.h> /* For open files */
#include <ctype.h> /* For isdigit */

/************* MACROS **************/

/* Resume from the unused attibute */
#define UNUSED __attribute__((unused))

/* Buffer size for each read of file */
#define BUFFER_SIZE 4048

/************* STRUCTURES **************/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_p;

/**
 * struct info- struct for the program's data
 * @line_number: ...
 * @words: ...
 * @file_content: ...
 * @file_path: ...
 * @lines: ...
 * @head: ...
 * @stack: ...
 */
typedef struct info
{
	/*data who changes every line */
	unsigned int line_number;
	char **words;
	/* data who don't change */
	char file_content[BUFFER_SIZE];
	char *file_path;
	char **lines;
	stack_p *head;
	/* the double linked list to operate on */
	stack_p **stack;
} data_of_program;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @function: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*function)(data_of_program *data);
} instruction_t;

/************** MAIN FUNCTIONS **************/

/* print error message to stout and exit_failure to stderr */
void inicialize_data(data_of_program *data, int argc, char *argv[]);

void open_file(data_of_program *data, char *argv[]);

void error(data_of_program *data, int error);

void list(data_of_program *data);


/************** OPERATIONS ***************/
/* pushes an element to the stack */
void push(data_of_program *data);
/* prints all the values on the stack, starting from the top of the stack */
void pall(data_of_program *data);
/* prints the value at the top of the stack, followed by a new line */
void pint(data_of_program *data);
/* removes the top element of the stack */
void pop(data_of_program *data);
/* adds the top two elements of the stack */
void add(data_of_program *data);
/* swaps the top two elements of the stack */
void swap(data_of_program *data);
/* do nothing */
void nop(data_of_program *data);
void _sub(data_of_program *data);
void _mul(data_of_program *data);
void _div(data_of_program *data);




/************** LIST HELPERS ***************/

/* print all the nodes of the stack */
void print_stack(stack_p *stack);
/* return the number of elements in the stack */
size_t stack_len(stack_p **stack);
/* add node in stack */
stack_t *add_node(stack_p **stack, int n, data_of_program *data);
/* add node at end of a stack */
stack_t *add_node_end(stack_p **stack, int n, data_of_program *data);
/* free stack */
void free_stack(stack_p **stack);
/* delete node at index position */
int delete_at_index(stack_p **stack, unsigned int index);

/* fill a buff with a char */
char *_memset(char *s, char b, unsigned int n);
/* delete a node */
void delete_at_end(stack_p *stack, stack_p **head);

/* strtok */
/* char *_strdup(char *str, data_of_program *data); */
int countargs(char *copytext, char *delimiter);
char **_split(int args, char *text, char *delimiter, data_of_program *data);
char **_strtok(char *text, char *delimiter, data_of_program *data);

/* OTHERS  */
/* compare two strings */
int str_compare(char *string1, char *string2, int number);


/* FREE MEMORY */
/* frees each pointer of an array of pointers and the array too */
void free_array_of_pointers(char **array);
/* free the fields needed each readed line */
void free_recurrent_data(data_of_program *data);
/* Free all field of the data structure */
void free_all_data(data_of_program *data);
void free_all(data_of_program *data);
void free_til_end(stack_p *stack, stack_p  **head);


#endif /* MONTY_H */
