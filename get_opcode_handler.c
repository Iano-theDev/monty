#include "main.h"
#include <strings.h>

/**
 * get_opcode_handler - search an return the opcode handler
 * @opcode: A string
 *
 * Return: A function pointer
 */
void (*get_opcode_handler(const char *opcode))(stack_t **, unsigned int)
{

	size_t len = 0, i = 0;
	instruction_t ops[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
	};

	len = sizeof(ops) / sizeof(instruction_t);

	while (i < len && strcasecmp(ops[i].opcode, opcode) != 0)
		i++;

	if (i < len)
		return (ops[i].f);
	return (NULL);
}
