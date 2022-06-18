#include "main.h"
#include <stdio.h>

/**
 * op_pint - prints the value at the top of the stack
 * @stack: The stack
 * @line_number: the linter number
 *
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't point, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
