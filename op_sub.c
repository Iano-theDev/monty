#include "monty.h"
#include <stdio.h>
/**
 * op_sub - subtructs the top two elements of the stack
 * @stack: the stack
 * @line_number: an integer
 *
 * Return: nothing
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	free_stack_t(stack_pop(stack));
}
