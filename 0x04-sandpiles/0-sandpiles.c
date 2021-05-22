#include "sandpiles.h"

#include <stdio.h>


int grid_sum(int grid1[3][3], int grid2[3][3], int flag);
static void print_grid(int grid[3][3]);
void process_sandpile(int grid[3][3]);
int is_unstable(int grid[3][3]);

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

	if (unstable != 0)
	{
		printf("=\n");
		print_grid(grid1);
		process_sandpile(grid1);
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
	int unstable = 0, c = 0;

	(grid[0][0] > 3) ? grid[0][1]++, grid[1][0]++, grid[0][0] -= 4 : 0;
	(grid[0][2] > 3) ? grid[0][1]++, grid[1][2]++, grid[0][2] -= 4 : 0;
	(grid[2][0] > 3) ? grid[1][0]++, grid[2][1]++, grid[2][0] -= 4 : 0;
	(grid[2][2] > 3) ? grid[2][1]++, grid[1][2]++, grid[2][2] -= 4 : 0;

	(grid[0][1] > 3) ? grid[0][0]++, grid[0][2]++, c++, grid[0][1] -= 4 : 0;
	(grid[1][0] > 3) ? grid[0][0]++, grid[2][0]++, c++, grid[1][0] -= 4 : 0;
	(grid[1][2] > 3) ? grid[0][2]++, grid[2][2]++, c++, grid[1][2] -= 4 : 0;
	(grid[2][1] > 3) ? grid[2][0]++, grid[2][2]++, c++, grid[2][1] -= 4 : 0;
	(c > 0) ? grid[1][1] += c : 0;

	if (grid[1][1] > 3)
	{
		grid[0][1] += 1, grid[1][0] += 1;
		grid[1][2] += 1, grid[2][1] += 1;
		grid[1][1] -= 4;
	}

	unstable = is_unstable(grid);

	if (unstable)
	{
		printf("=\n");
		print_grid(grid);
		process_sandpile(grid);
	}
}

/**
 * is_unstable -  look if sandpile is stable
 * @grid: sandpile
 *
 * Return: 1 or 0
 */
int is_unstable(int grid[3][3])
{
	int i = 0, c = 0, f = 2, f2 = 2;

	for (c = 0, f2 = 2; i < 3; c++, f2--)
	{
		if (c == 3)
			i++, f--, c = 0, f2 = 2;
		if (i == 3)
			break;
		if (grid[i][c] > 3)
			return (1);
		if (grid[f][f2] > 3)
			return (1);
	}
	return (0);
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
