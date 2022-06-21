#include "monty.h"
#include <stdio.h>

/**
 * op_pstr - prints  the string starting at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor = *stack;

	(void) line_number;

	while (cursor)
	{
		if (cursor->n < 0 || cursor->n > 127 || cursor->n == 0)
			break;

		printf("%c", cursor->n);
		cursor = cursor->next;
	}

	printf("\n");
}
