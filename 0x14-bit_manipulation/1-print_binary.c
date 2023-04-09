#include "main.h"

/**
 *print_binary - Prints the binary representation of a number.
 *@n: The number to be printed in binary.
 *
 *Description: This function prints the binary representation of a number,
 *             using recursion to repeatedly shift the number right and
 *             check its least significant bit until it reaches 0.
 *             It does not use arrays, malloc, or the % or / operators.
 */
void print_binary(unsigned long int n)
{
	/*Base case: the number is 0 or 1, so just print it */
	if (n <= 1)
	{
		_putchar(n + '0');
		return;
	}

	/*Recursively print the binary representation of the number */
	print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
