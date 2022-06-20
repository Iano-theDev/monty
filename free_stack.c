#include "monty.h"
/**
 * free_stack - clear the stack and free all elements
 * @stack: the stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	while (*stack)
		free_stack_t(stack_pop(stack));
}
