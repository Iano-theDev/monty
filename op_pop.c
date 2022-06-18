#include "main.h"
#include <stdio.h>

/**
 * op_pop - removes the top element of the stack
 * @stack: A stack
 * @line_number: An integer
 *
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popped = stack_pop(stack);

	if (!popped)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	free_stack_t(popped);
}
