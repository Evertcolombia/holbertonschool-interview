#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - sum two sandpile
 * @grid1: sandpile
 * @grid2: sandpile
 *
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;

	unstable = grid_sum(grid1, grid2, unstable);

	if (unstable > 0)
		unstable_check(grid1, unstable);
}

/**
 * unstable_check - re run if sandpile is unstable
 * @grid: sandpile
 * @unstable: flag
 *
 * Return: None
 */
void unstable_check(int grid[3][3], int unstable)
{
	if (unstable > 0)
	{
		printf("=\n");
		print_grid(grid);
		process_sandpile(grid);
	}
}

/**
 * grid_sum - sum grid
 * @grid1: sandpile
 * @grid2: sandpile
 * @flag: flag
 *
 * Return: 1 or 0
 */
int grid_sum(int grid1[3][3], int grid2[3][3], int flag)
{
	int i = 0, c = 0, f = 2, f2 = 2;

	for (c = 0; i < 3; c++)
	{
		if (c == 3)
			i++, c = 0, f--, f2 = 2;
		if (i == 3)
			break;

		if (grid1[i][c] + grid2[i][c] > 3)
			flag = 1;

		grid1[i][c] += grid2[i][c];

		if (i == f && c == f2)
			break;

		if (grid1[f][f2] + grid2[f][f2] > 3)
			flag = 1;
		grid1[f][f2] += grid2[f][f2];
		f2--;
	}
	return (flag);

}

/**
 * process_sandpile - process sandpile
 * @grid: sandpile
 * Return: None
 */
void process_sandpile(int grid[3][3])
{
	int i = 0, j = 0, num = 0, uns = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			num = grid[i][j];
			if (num >= 4)
			{
				grid[i][j] = num - 4;

				if (i > 0)
				{
					num = ++grid[i - 1][j];
					uns += (num >= 4) ? 1 : 0;
				}
				if (i < 2)
				{
					num = ++grid[i + 1][j];
					uns += (num >= 4) ? 1 : 0;
				}
				if (j > 0)
				{
					num = ++grid[i][j - 1];
					uns += (num >= 4) ? 1 : 0;
				}
				if (j < 2)
				{
					num = ++grid[i][j + 1];
					uns += (num >= 4) ? 1 : 0;
				}
			}
		}
	}

	if (uns > 0)
		unstable_check(grid, uns);
}

/**
 * print_grid - prind sandpile
 * @grid: sandpile
 *
 * Retrun: None
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
