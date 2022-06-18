#include "main.h"
#include <stdio.h>

/**
 * op_add - multiplies the second top element of the stack with the top element
 * of  the stack.
 * @stack: The stack
 * @line_number: An integer
 *
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
        if (!(*stack) || !(*stack)->next)
        {
                free_stack(stack);
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n *= (*stack)->n;
        free_stack_t(stack_pop(stack));
}
