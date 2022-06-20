#include "monty.h"
#include <stdio.h>

/**
 * op_add - adds the top two elements of the stack
 * @stack: The stack
 * @line_number: An integer
 *
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);

		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	free_stack_t(stack_pop(stack));
}
