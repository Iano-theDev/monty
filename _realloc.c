#include <stdlib.h>
#include "monty.h"

/**
 *_realloc - realloc new memory space
 *@ptr: A pointer
 *@n: New memory size
 *
 *Return: A pointer on success else NULL
 */
void *_realloc(void *ptr, size_t n)
{
	void *new_ptr = NULL;

	new_ptr = malloc(n);
	if (!new_ptr)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}

	_memcpy(new_ptr, ptr, n);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}
