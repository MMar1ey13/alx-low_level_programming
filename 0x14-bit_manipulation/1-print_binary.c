#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int print = 0;

	while (mask > 0)
	{
		if ((n & mask) == mask)
		{
			_putchar('1');
			print = 1;
		}
		else if (print)
		{
			_putchar('0');
		}

		mask >>= 1;
	}

	if (!print)
		_putchar('0');
}
