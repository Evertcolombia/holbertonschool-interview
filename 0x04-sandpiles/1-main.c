#include <stdio.h>

int main(void)
{
	int arr[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int i = 0, c = 0;

	for (c = 0; i <= 2; c++)
	{
		if (c == 3)
		{
			i++;
			c = 0;
		}
		if (i == 3)
			break;
		if (arr[i][c - 1])
		{

			printf("%d - %d \n",c , arr[i][c]);
		}
	}
	return (0);
}
