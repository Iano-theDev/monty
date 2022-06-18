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

	if (!opcode)
		return (NULL);

	if (strcasecmp("pall", opcode) == 0)
		return (op_pall);

	if (strcasecmp("pint", opcode) == 0)
		return (op_pint);

	if (strcasecmp("pop", opcode) == 0)
		return (op_pop);

	if (strcasecmp("swap", opcode) == 0)
		return (op_swap);

	if (strcasecmp("add", opcode) == 0)
		return (op_add);

	if (strcasecmp("nop", opcode) == 0)
		return (op_nop);
	return (NULL);
}
