#include "lists.h"
#include <stdio.h>
listint_t *recursive_iter(listint_t **curr, listint_t  *new, int n);
/**
 * listint_t *insert_node - insert node in sorted list
 * @head: double pointer to lis head
 * @number: number to sort
 *
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *curr = NULL;

	curr = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->next = NULL;
	new->n = number;

	if (curr == NULL || number < curr->n)
	{
		*head = new;
		new->next = *head;
		return (new);
	}

	return (recursive_iter(&curr->next, new, number));
}

/**
 * listint_t *recursive_iter - recursive iteration
 * @curr: current node place
 * @new: node to set in the list
 * @n: number to compare
 *
 * Return: Node on success
 */
listint_t *recursive_iter(listint_t **curr, listint_t  *new, int n)
{
	if (*curr && (*curr)->next)
	{
		if (n >= (*curr)->n && n <= (*curr)->next->n)
		{
			new->next = (*curr)->next;
			(*curr)->next = new;
			return (new);
		}
		else
			recursive_iter(&(*curr)->next, new, n);
	}
	return (NULL);
}
