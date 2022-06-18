#include "main.h"
#include <stdlib.h>

/**
 * stack_pop - remove the top of the stack
 * @stack: the stack
 *
 * Return: The removed top element
 */
stack_t *stack_pop(stack_t **stack)
{
	stack_t *popped = NULL;

	if (!stack || !(*stack))
		return (NULL);

	/* 1->(X) */
	popped = *stack;
	*stack = popped->next;
	popped->next = NULL;

	if (*stack)
		(*stack)->prev = NULL;

	return (popped);
}
