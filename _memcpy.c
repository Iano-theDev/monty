#include <stddef.h>

/**
 *_memcpy - copy bytes
 *@dest: A pointer
 *@src: A pointer
 *@n: Number of bytes
 *
 *Return: void
 */
void _memcpy(const void *dest, const void *src, const size_t n)
{
	size_t i = 0;
	char *csrc = (char *) src;
	char *cdest = (char *) dest;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
}
