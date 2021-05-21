#include "sandpiles.h"

#include <stdio.h>


int grid_sum(int grid1[3][3], int grid2[3][3], int flag);
static void print_grid(int grid[3][3]);
void process_sandpile(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;

	unstable = grid_sum(grid1, grid2, unstable);
	if (unstable != 0)
	{
		process_sandpile(grid1);
		print_grid(grid1);
	}

}

int grid_sum(int grid1[3][3], int grid2[3][3], int flag)
{
	int i = 0, c = 0, f = 2, f2 = 2;

	for (c = 0; i < 3; c++)
	{
		if (c == 3)
			i++, c = 0, f--, f2 = 2;
		if (i == 3)
			break;
		if (i == f && c == f2)
		{
			if (grid1[i][c] + grid2[i][c] > 3)
				flag = 1;
			grid1[i][c] += grid2[i][c];
			break;
		}

		if (grid1[i][c] + grid2[i][c] > 3)
			flag = 1;
		if (grid1[f][f2] + grid2[f][f2] > 3)
			flag = 1;
		grid1[i][c] += grid2[i][c];
		grid1[f][f2] += grid2[f][f2];
		f2--;
	}
	return flag;
}
void process_sandpile(int grid[3][3])
{

	int i = 0, c = 0, f = 2, f2 = 2;

	for (c = 0, f2 = 2; i < 3; c++, f2--)
	{
		if (c == 3)
			i++, f--, c =0, f2 = 2;
		if (i == 3)
			break;

		(c < 2) ? grid[i][c + 1] += 1 : 0;
		(i < 2) ? grid[i + 1][c] += 1 : 0;
		(c > 0) ? grid[i][c - 1] += 1 : 0;
		(i > 0) ? grid[i - 1][c] += 1 : 0;
		grid[i][c] -= 4;
		if (i == f && c == f2)
			break;

		(f2 < 2) ? grid[f][f2 + 1] += 1 : 0;
		(f < 2) ? grid[f + 1][f2] += 1 : 0;
		(f2 > 0) ? grid[f][f2 - 1] += 1 : 0;
		(f > 0) ? grid[f - 1][f2] += 1 : 0;
		grid[f][f2] -= 4;
	}
}
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
