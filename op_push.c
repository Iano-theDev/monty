#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * op_push - push on the stack
 * @stack: The stack
 * @line_number: the line number
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " ");

	if (!is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_push(stack, atoi(arg));
}
