#include "monty.h"
#include <stddef.h>

/**
 * op_rotl - rotates the stack to the top
 * @stack: The stack
 * @line_number: An unsigned integer
 *
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line_number)
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

	*stack = (*stack)->next;
	tmp->next = (*stack)->prev;
	(*stack)->prev = NULL;
	tmp->next->next = NULL;
	tmp->next->prev = tmp;
}
