#ifndef _HEAP_B_
#define _HEAP_B_

#include <stddef.h>
#include <stdlib.h>
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

typedef struct Queue {
	binary_tree_t *node;
	binary_tree_t *next;
} q_list;

typedef struct queue_control {
	int size;
	binary_tree_t *head;
	binary_tree_t *last_in;
} c_list;

/* Prototypes */
binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);void link_enqueue(q_list **queue, heap_t *new, c_list **c_queue);
q_list *link_dequeue(q_list **queue);

#endif /* _HEAP_B_ */
