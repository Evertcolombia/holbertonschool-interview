#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - check if a link list is palindrome
 * @head: double pointer to head
 *
 * Return: 1 on success 0 on no palindrome
 *
 */
int is_palindrome(listint_t **head)
{
	listint_t *curr = NULL, *init = NULL, *last = NULL;

	if (*head == NULL)
		return (1);

	curr = *head;
	init = curr;

	while (curr != NULL)
	{
		if (curr->next == NULL || curr->next == last)
		{
			if (init->n == curr->n)
			{
				init = init->next;
				last = curr;
				curr = init;
			}
			else
				return (0);

			if (init == last)
				return (1);
		}
		else
			curr = curr->next;
	}
	return (0);
}
