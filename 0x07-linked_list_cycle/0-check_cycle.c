#include "lists.h"

/**
 * check_cycle - check if a linked list is cycle
 * @list: head of the list
 *
 * Return: 1 on success, 0 on error
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise = NULL;
	listint_t *hare = NULL, *tmp = NULL;

	if (list == NULL)
		return (0);
	tortoise = hare = tmp = list;

	while (true)
	{
		if (hare->next == NULL || hare->next->next == NULL)
			return (0);
		hare = hare->next->next;

		if (tortoise->next == NULL)
			return (0);
		tortoise = tortoise->next;

		if (hare->n == tmp->n || tortoise->n == hare->n)
			return (1);
	}
	return (0);
}
