#include "monty.h"
#include <string.h>
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
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	ssize_t read = -1;
	stack_t *stack = NULL;
	void (*handler)(stack_t **, unsigned int);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line[read - 1] = '\0';
		line_number += 1;
		opcode = strtok(line, " ");

		if (!opcode || opcode[0] == '#')
			continue;

		handler = get_opcode_handler(opcode);

		if (!handler)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}

		handler(&stack, line_number);
	}

	free(line);
	free_stack(&stack);
}
