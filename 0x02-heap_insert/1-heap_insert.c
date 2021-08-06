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
	heap_t *new = NULL, *tmp = NULL;
	q_list *queue = NULL, *actual_queue = NULL;
	c_list *control = NULL;
	
	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	link_enqueue(&queue, *root, &control);

	while (control->size > 0)
	{
		actual_queue = link_dequeue(&queue, &control);
		new->parent = actual_queue->node;
		tmp =  actual_queue->node;
		free(actual_queue);
		if (tmp->left == NULL)
		{
			tmp->left = new;

			if (new->parent == NULL)
				*root = new;
			break;
		}
		else if (tmp->right == NULL)
		{
			tmp->right = new;

			if (new->parent == NULL)
				*root = new;
			break;
		}
		else
		{
			link_enqueue(&queue, tmp->left, &control);
			link_enqueue(&queue, tmp->right, &control);
		}
	}
	link_queue_free(queue, control);
	return (new);
}

/**
 * link_enqueue - create queue (link list) or insert new element
 * @new: new node to insert
 * @control: controller object for the queue list
 *
 * Return: None
 */
void link_enqueue(q_list **queue, heap_t *new, c_list **control)
{
	q_list *new_queue = NULL;

	if (*queue == NULL)
	{
		*queue = malloc(sizeof(q_list));
		if (*queue == NULL)
			return;
		(*queue)->node = new;
		(*queue)->next = NULL;

		if (*control == NULL)
		{
			*control = malloc(sizeof(c_list));
			if (*control == NULL)
				return;
		}
		(*control)->head = *queue;
		(*control)->last_in = *queue;
		(*control)->size = 1;
		return;
	}
	new_queue = malloc(sizeof(q_list));
	if (new_queue == NULL)
		return;
	new_queue->node = new;
	new_queue->next = NULL;

	(*control)->last_in->next = new_queue;
	(*control)->size++;
	(*control)->last_in = new_queue;
}

/**
 * q_list *link_dequeue - dequeue element from the linked list
 * @queue: the linked list head
 *
 * Return: dequeue node that nows is not in the linked list
 */
q_list *link_dequeue(q_list **queue, c_list **control)
{
	q_list *tmp = NULL;

	tmp = *queue;
	*queue = (*queue)->next;
	if (tmp->node == (*control)->head->node)
		(*control)->head = *queue;
	if (tmp->node == (*control)->last_in->node)
		(*control)->last_in = *queue;
	(*control)->size--;
	return (tmp);
}

/**
 * link_queue_free - free a queue and controlller
 * @queue: queue linked list
 * @control: controller for the queue list
 *
 * Return: None 
 */
void link_queue_free(q_list *queue, c_list *control)
{
	q_list *tmp = NULL;

	while (control->size > 0)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
		control->size--;
	}
	free(control);
}
