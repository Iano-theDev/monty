#include "main.h"
#include <stdlib.h>

/**
 * free_stack_t - free a stack_t type
 * @stack: The stack
 *
 * Return: void
 */
void free_stack_t(stack_t *stack)
{
	stack->prev = NULL;
	stack->next = NULL;
	free(stack);
}
