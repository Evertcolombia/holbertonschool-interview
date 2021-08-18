#ifndef SANDPILES
#define SANDPILES

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void unstable_check(int grid[3][3], int unstable);
int grid_sum(int grid1[3][3], int grid2[3][3], int flag);
void process_sandpile(int grid[3][3]);
#endif /* SANDPILES */
