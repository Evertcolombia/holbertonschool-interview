#include "lists.h"

/**
 * insert_node - inset node in sorted linked list
 * @head: double pointer to head node
 * @number: number to save
 *
 * Return: new node or Null
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *currNext;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	currNext = current->next;
	while (current->next != NULL)
	{
		if (number > current->n && number <= currNext->n)
		{
			current->next = new, new->next = currNext;
			break;
		}
		current = current->next, currNext = currNext->next;
	}
	return (new);
}
