#include "binary_trees.h"

/**
 * heap_t *heap_insert - insert new node in max heap b tree
 * @root: root of the b tree for the queue
 * @value: value for the new node
 *
 * Return: pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *actual_node = NULL, *tmp = *root;
	q_list *queue = NULL, *actual_queue NULL;
	c_list *control = NULL;

	
	if (root == NULL)
		return (NULL);

	if (tmp == NULL)
	{
		tmp = binary_tree_node(NULL, value);
		return (tmp);
	}

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	enqueue(&queue, tmp, &control);


	while (queue->size > 0)
	{
		actual_queue = link_dequeue(&queue);
	}
	/*if (tmp->left == NULL)
	{
		tmp->left = new;
		new->parent = tmp;
	}
	else if (tmp->right == NULL)
	{
		tmp->right = new;
		new->parent = tmp;
	}*/		
}


/**
 * link_enqueue - create queue (link list) or insert new element
 * @new: new node to insert
 * @c_queue: controller object for the queue list
 *
 * Return: None
 */
void link_enqueue(q_list **queue, heap_t *new, c_list **c_queue)
{
	q_list *tmp = NULL, *new_queue = NULL;

	tmp = *queue;
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(q_list));
		if (tmp == NULL)
			return;
		tmp->node = new;
		tmp->next = NULL;

		*c_queue = malloc(sizeof(c_list));
		if (*c_queue == NULL)
			return;
		(*c_queue)->head = tmp;
		(*c_queue)->last_in = tmp;
		(*c_queue)->size++;
		return;
	}
	new_queue = malloc(sizeof(q_list));
	if (new_queue == NULL)
		return;
	new_queue->node = new;
	new_queue->next = NULL;

	(*c_queue)->last_in->next = new_queue;
	(*c_queue)->size++;
	(*c_queue)->last_in = new_queue;
}

/**
 * q_list *link_dequeue - dequeue element from the linked list
 * @queue: the linked list head
 *
 * Return: dequeue node that nows is not in the linked list
 */
q_list *link_dequeue(q_list **queue)
{
	q_list *tmp = *queue;

	*queue = (*queue)->next;
	return (tmp);
}
