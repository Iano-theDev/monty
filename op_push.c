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

	if (!is_int(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (stack_push(stack, atoi(arg)) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
