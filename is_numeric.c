#include <stddef.h>
#include <stdio.h>

/**
 * is_numeric - check if string is numeric
 * @str: A string
 *
 * Return: 1 if numeric else 0
 */
int is_numeric(const char *str)
{
	size_t i = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	if (str[i] == '\0')
		return (0);

	if (str[i] >= '0' && str[i] <= '9')
		i++;

	if (str[i] != '\0')
		return (0);

	return (1);
}
