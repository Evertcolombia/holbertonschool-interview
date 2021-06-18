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
	unsigned long reverse = 0, res = 0;

	if (n != 0)
		reverse = test(n, reverse);

	res = (n == reverse) ? 1 : 0;
	return (res);
}

/**
 * test - check palindrome number using recursion
 * @n: number to traverse
 * @reverse: encapsulate the  reverse stack
 *
 * Return: reverse
 */
unsigned long test(unsigned long n, unsigned long reverse)
{
	unsigned long remainder = 0;

	remainder = n % 10;
	reverse = reverse * 10 + remainder;
	n /= 10;

	if (n != 0)
		reverse = test(n, reverse);
	return (reverse);
}
