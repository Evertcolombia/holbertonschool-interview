#include "lists.h"

/**
 * check_cycle - check if a linked list is cycle
 * @list: node to the list
 *
 * Return: 1 on success 0 on none
 */
int check_cycle(listint_t *list)
{
	listint_t *t = NULL, *h = NULL;

	if (list == NULL)
		return (0);

	t = h = list;
	while (t != NULL && h != NULL)
	{
		h = h->next->next;
		if (h == NULL)
			return (0);
		if (h == t)
			return (1);
		t = t->next;
	}
	return (0);
}
