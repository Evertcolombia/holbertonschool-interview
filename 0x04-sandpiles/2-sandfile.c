#include "sandpiles.h"

#include <stdio.h>


int grid_sum(int grid1[3][3], int grid2[3][3], int flag);
static void print_grid(int grid[3][3]);
void process_sandpile(int grid[3][3]);
int is_unstable(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;

	unstable = grid_sum(grid1, grid2, unstable);
	if (unstable != 0)
	{
		process_sandpile(grid1);
		printf("\n");
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
	return flag;

}

void process_sandpile(int grid[3][3])
{

	int i = 0, c = 0;
	int unstable = 0; 

	for (c = 0; i < 3; c++)
	{
		if (c == 3)
			i++, c =0;
		if (i == 3)
			break;
		
		if (grid[i][c] > 3)
		{
			(c < 2) ? grid[i][c + 1] += 1 : 0;
			(i < 2) ? grid[i + 1][c] += 1 : 0;
			(c > 0) ? grid[i][c - 1] += 1 : 0;
			(i > 0) ? grid[i - 1][c] += 1 : 0;
			grid[i][c] -= 4;
		}
	}
	unstable = is_unstable(grid);

	if (unstable)
	{
		print_grid(grid);
		printf("\n");
		process_sandpile(grid);
	}
}

int is_unstable(int grid[3][3])
{
	int i = 0, c = 0, f = 2, f2 = 2;

	for (c = 0, f2 = 2; i < 3; c++, f2--)
	{
		if (c == 3)
			i++, f--, c =0, f2 = 2;
		if (i == 3)
			break;
		if (grid[i][c] > 3) 
			return (1);
		if (grid[f][f2] > 3)
			return (1);
	}
	return (0);
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
