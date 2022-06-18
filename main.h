#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}

stack_t;

/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}

instruction_t;

stack_t *new_stack_t(int n);
stack_t *stack_push(stack_t **stack, int n);
stack_t *stack_pop(stack_t **stack);
void free_stack_t(stack_t *stack);
void free_stack(stack_t **stack);

void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);

void (*get_opcode_handler(const char *opcode))(stack_t **, unsigned int);

ssize_t _getline(char **line, size_t *line_len, FILE *fp);

void *_realloc(void *ptr, size_t n);

void _memcpy(const void *dest, const void *src, const size_t n);

void run(FILE *fp);

int is_numeric(const char *str);

#endif /*MAIN_H*/
