#include "monty.h"
#include <stddef.h>

/**
 * op_rotr - rotates the stack to the bottom
 * @stack: The stack
 * @line_number: An unsigned integer
 *
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;
	tmp = *stack;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}

	if (tmp == *stack)
		return;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
}
