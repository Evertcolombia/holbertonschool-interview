#include "slide_line.h"

/*static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}*/

void resolve_line(int *line, int *slides, int len, int size, int direction)
{
	int i = 0, *head;


	if (direction == 0)	/* Left style */
	{
		head = line;
		slides = slides + (len - 1);

		for (i = 0; i < len; i++)
		{
			*head = *slides;
			head++, --slides;
		}
	}
	else	/* Right style */
	{
		head = line + (size - 1);

		for (; len > 0; len--)
		{
			*head = *slides;
			--head, slides++;
		}
	}
}


void slide_left(int *line, size_t size)
{
	int slides [100], len = 0;
	int count =  (int) size, *head;
	bool con = false;

	if (line != NULL)
		head = line + (count - 1);

	for (; count > 0; count--)
	{

		/*printf("%d\n", *head);*/
		if (*head > 0)
		{
			if (len > 0 && slides[len - 1] == *head && !con)
			{
				slides[len - 1] *= 2;
				con = true;
			}
			else
			{
				slides[len++] = *head;
				con = false;
			}
			*head = 0;
		}
		--head;
	}

	/*print_array(slides, size);
	print_array(line, size);*/
	
	if (len > 0)
		resolve_line(line, slides, len, 0, 0);
}

int *slide_right(int *line, size_t size)
{
	int slides [100], len = 0;
	int count = 0, *head;
	bool con = false;

	if (line != NULL)
		head = line;

	for (; count < (int) size; count++)
	{
		if (*head > 0)
		{
			if (len > 0 && slides[len - 1] == *head && !con)
			{
				slides[len - 1] *= 2;
				con = true;
			}
			else
			{
				slides[len++] = *head;
				con = false;
			}
			*head = 0;
		}
		head++;
	}

	/*print_array(slides, size);
	print_array(line, size);*/
	if (len > 0)
		resolve_line(line, slides, len, (int) size, 1);

	return(line);
}

int slide_line(int *line, size_t size, int direction)
{

	if (direction == 0)
		slide_left(line, size);
	else if (direction == 1)
		line = slide_right(line, size);
	else
	{
		printf("Direction must be left or right\n");
		return(0);
	}
	return(1);
}
