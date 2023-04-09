#include "main.h"
#include <string.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0, i = 0, len;

	if (!b)
		return (0);

	len = strlen(b);

	while (i < len)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

		n <<= 1;
		n += b[i] - '0';
		i++;
	}

	return (n);
}

