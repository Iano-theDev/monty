#include "main.h"
/**
 * free_stack - clear the stack and free all elements
 * @stack: the stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *freed = NULL;

	if (!stack)
		return;

	freed = *stack;

	while (*stack)
	{
		freed = *stack;
		*stack = (*stack)->next;
		free_stack_t(freed);
	}
}
