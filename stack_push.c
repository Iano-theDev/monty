#include "main.h"
#include <stddef.h>


/**
 * stack_push - add on the stack
 * @stack: the stack
 * @n: An integer
 *
 * Return: The new created stack element
 */
stack_t *stack_push(stack_t **stack, int n)
{
	stack_t *e = NULL;

	if (stack == NULL)
		return (NULL);

	e = new_stack_t(n);

	if (e == NULL)
		return (NULL);

	e->next = *stack;

	if (*stack)
		(*stack)->prev = e;

	*stack = e;

	return (e);
}
