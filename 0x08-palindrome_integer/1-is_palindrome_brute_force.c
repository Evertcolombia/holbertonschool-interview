#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - check if a number is palindrome
 * @n: unsigned long number to test
 *
 * Return: 1 on palindrome - 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, remainder = 0, or = 0;

	or = n;
	while (n != 0)
	{
		remainder = n % 10;
		printf("remainder: %d\n", (int) remainder);
		reverse = reverse * 10 + remainder;
		printf("reverse: %d\n", (int)reverse);
		n /= 10;
		printf("n: %d\n", (int)n);
	}

	if (or == reverse)
		return (1);
	else
		return (0);
}
