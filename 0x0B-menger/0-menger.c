#include "menger.h"
/**
 * print_menger - if must it will print the data
 * @x: x position in the grid
 * @y: y position in the grid
 *
 * Return: int
 */
int print_menger(int c_x, int c_y)
{
	while (true)
	{
		if (c_x == 0 || c_y == 0)
			return (1);
		if (c_x % 3 == 1 && c_y % 3 == 1)
			return (0);
		c_x = c_x / 3;
		c_y = c_y / 3;
	}
}

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge
 *
 * Return: None
 */
void menger(int level)
{
	int n = 0, row = 0, column = 0;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (column = 0; column < n; column++)
		{
			if (print_menger(row, column))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
