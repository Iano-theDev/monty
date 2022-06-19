#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_swap - swaps the top tow elements of the stack
 * @stack: The stack
 * @line_number: An integer
 *
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;

	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;

	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}
