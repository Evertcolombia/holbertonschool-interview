#include "slide_line.h"

/**
 * resolve_line - reorder the line array with the results
 * @line: pointer to line array
 * @slides: pointer to results array
 * @len: len of the slides
 * @size: len of the line
 * @direction: decides if left or right
 *
 * Return: None
 */
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

/**
 * slide_left - linear search for the left
 * @line: line to traverse
 * @size: size in bytes of the line
 *
 * Return: None
 */
void slide_left(int *line, size_t size)
{
	int slides[100], len = 0;
	int count =  (int) size, *head;
	bool con = false;

	head = line + (count - 1);
	for (; count > 0; count--)
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
		--head;
	}

	if (len > 0)
		resolve_line(line, slides, len, 0, 0);
}

/**
 * slide_right - linear search for the left
 * @line: line to traverse
 * @size: size of the line in bytes
 *
 * Return: None
 */
int *slide_right(int *line, size_t size)
{
	int slides[100], len = 0;
	int count = 0, *head;
	bool con = false;

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

	if (len > 0)
		resolve_line(line, slides, len, (int) size, 1);

	return (line);
}


/**
 * slide_line - slide a line in horizontal mode as 2048 game
 * @line: pointer to array
 * @size: size of the array in bytes
 * @direction: direction to slide
 *
 * Return: 0 on error, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{

	if (line == NULL)
		return (0);
	if (direction == 0)
		slide_left(line, size);
	else if (direction == 1)
		line = slide_right(line, size);
	else
	{
		printf("Direction must be left or right\n");
		return (0);
	}
	return (1);
}
