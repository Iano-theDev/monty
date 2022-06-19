#include "monty.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

/**
 * run - run bytecode from file
 * @fp: A file pointer
 *
 * Return: void
 */
void run(FILE *fp)
{
	char *line = NULL, *opcode = NULL, *arg = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	ssize_t read = -1;
	int int_arg = 0;
	stack_t *stack = NULL;

	void (*handler)(stack_t **, unsigned int);

	while ((read = _getline(&line, &len, fp)) != -1)
	{
		line[read - 1] = '\0';
		line_number += 1;
		opcode = strtok(line, " ");
		arg = strtok(NULL, " ");
		if (!opcode && !arg || opcode[0] == '#')
			continue;
		if (strcasecmp("push", opcode) == 0)
		{
			if (!arg || !is_numeric(arg))
			{
				free_stack(&stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			int_arg = atoi(arg);
			stack_push(&stack, int_arg);
			continue;
		}
		handler = get_opcode_handler(opcode);
		if (handler)
			handler(&stack, line_number);
		else
		{
			free_stack(&stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&stack);
}
