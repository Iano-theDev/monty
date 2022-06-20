#include "monty.h"

extern stack_t *stack;

/**
 * die - cleanup and exit
 * @msg: Message to printout
 * @status: status code
 *
 * Return: void
 */
void die(int status)
{
	free_stack(&stack);
	exit(status);
}
