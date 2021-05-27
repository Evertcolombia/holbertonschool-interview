#include "lists.h"
#include <stdlib.h>

int test_stack(listint_t **left, listint_t *right);

/**
 * is_palindrome - check if a link list is palindrome
 * @head: double pointer to head
 *
 * Return: 1 on success 0 on no palindrome
 *
 */
int is_palindrome(listint_t **head)
{
	int res = 0;

	if (*head == NULL)
		return (1);
	res = test_stack(head, *head);
	return (res);
}

/**
 * test_stack - recursive test nodes
 * @left: head node
 * @right: node to traverse the list
 *
 * Return: 1 on succes 0 on None
 */
int test_stack(listint_t **left, listint_t *right)
{
	int is_equal = 0;

	if (right == NULL)
		return (1);

	if (test_stack(left, right->next) == 0)
		return (0);

	(right->n == (*left)->n) ? is_equal = 1 : 0;
	*left = (*left)->next;

	return (is_equal);
}
