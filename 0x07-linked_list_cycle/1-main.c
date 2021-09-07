#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *current;
    listint_t *temp;
    int i;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 5);
    add_nodeint(&head, 6);
    add_nodeint(&head, 7);
    add_nodeint(&head, 8);
    add_nodeint(&head, 9);
    add_nodeint(&head, 10);
    add_nodeint(&head, 11);
    add_nodeint(&head, 13);
    add_nodeint(&head, 15);
    add_nodeint(&head, 17);
    add_nodeint(&head, 19);
    add_nodeint(&head, 21);
    add_nodeint(&head, 23);
    add_nodeint(&head, 25);
    add_nodeint(&head, 27);
    add_nodeint(&head, 29);
    add_nodeint(&head, 31);
    add_nodeint(&head, 40);
    add_nodeint(&head, 43);
    add_nodeint(&head, 45);
    add_nodeint(&head, 47);
    add_nodeint(&head, 49);
    add_nodeint(&head, 51);
    add_nodeint(&head, 55);
    add_nodeint(&head, 62);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 8; i++)
        current = current->next;
    temp = current->next;
    current->next = head;

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    current->next = temp;

    free_listint(head);

    return (0);
}
