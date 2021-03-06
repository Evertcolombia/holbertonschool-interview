#ifndef _HEAP_B_
#define _HEAP_B_

#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * struct Queue - queue linked list struct
 *
 * @node: node to point
 * @next: next queue element in the list
 */
typedef struct Queue {
	binary_tree_t *node;
	struct Queue *next;
} q_list;

/**
 * struct queue_control - controller for the queue list
 *
 * @size: size of the list
 * @head: head of the list
 * @last_in: last node pushed on the list
 */
typedef struct queue_control {
	int size;
	q_list *head;
	q_list *last_in;
} c_list;

/* binary tree Prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);

/** queue linked list Prototypes */
void link_enqueue(q_list **queue, heap_t *new, c_list **c_queue);
q_list *link_dequeue(q_list **queue, c_list **control);
void link_queue_free(q_list *queue, c_list *control);

#endif /* _HEAP_B_ */
