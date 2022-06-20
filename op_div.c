#include "monty.h"
#include <stdio.h>

/**
 * op_div - divides the second top element of the stack by the top element
 * @stack: The stack
 * @line_number: An integer
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		die(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		die(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	free_stack_t(stack_pop(stack));
}
