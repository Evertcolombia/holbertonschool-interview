#include "holberton.h"
/**
 * _isdigit - this function says if a character is a digit
 * @n: a pointer to a string.
 * Return: return 1 if c is a digit and 0 in other cases.
 */
static int _isdigit(char *n)
{
	int i = 0;

	while (*(n + i) != '\0')
	{
		if (*(n + i) < 48 || *(n + i++) > 57)
			return (0);
	}
	return (1);
}
/**
 * _strlen  - this functions returns the length of a string
 * @s: string
 * Return: return the length in int
 */
static int _strlen(char *s)
{
	return (*s != '\0' ? 1 + _strlen(++s) : 0);
}
/**
 * manual_mul - multiplies two strings arrays number by number
 * @total: int array which stores the final value
 * @argv: the arguments to be multiplicated
 * @d1_len: data 1 digit number
 * @d2_len: data 2 digit number
 * Return: return the length in int
 */
static void manual_mul(int *total, char *argv[], int d1_len, int d2_len)
{
	int product, result, i, j;

	for (i = (d2_len - 1); i >= 0; i--)
	{
		result = 0;
		for (j = (d1_len - 1); j >= 0; j--)
		{
			product = (argv[2][i] - '0') * (argv[1][j] - '0');
			result =  (product / 10);
			total[(i + j) + 1] += (product % 10);
			if (total[(i + j) + 1] > 9)
			{
				total[i + j] += total[(i + j) + 1] / 10;
				total[(i + j) + 1] = total[(i + j) + 1] % 10;
			}
			total[(i + j)] += result;
		}
	}

}

/**
 * main - the entry point
 * @argc:the number of argumentes
 * @argv: the arguments to be multiplicated
 * Return: return 0 in success 98 in error.
 */
int main(int argc, char *argv[])
{
	int d1_len, d2_len, i;
	int *total;

	if (argc != 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
	{
		puts("Error");
		exit(98);
	}
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (0);
	}
	d1_len = _strlen(argv[1]);
	d2_len = _strlen(argv[2]);
	total = calloc(d1_len + d2_len, sizeof(int));
	if (!total)
	{
		puts("Error");
		exit(98);
	}
	manual_mul(total, argv, d1_len, d2_len);
	i = *total == 0 ? 1 : 0;
	for (; i < (d1_len + d2_len); i++)
		printf("%d", total[i]);
	printf("\n");
	free(total);
	return (0);
}
