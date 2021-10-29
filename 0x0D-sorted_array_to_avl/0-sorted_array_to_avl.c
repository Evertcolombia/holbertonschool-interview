#include "binary_trees.h"

avl_t *create_new_node(int val, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = val;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

avl_t *create_avl(int *array, size_t lo, size_t hi, avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (hi == ULONG_MAX || lo > hi)
		return (NULL);
	mid = lo + (hi - lo) / 2;
	root = create_new_node(array[mid], parent);
	if (!root)
		return (NULL);

	root->left = create_avl(array, lo, mid - 1, root);
	root->right = create_avl(array, mid + 1, hi, root);
	return (root);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (create_avl(array, 0, size - 1, NULL));
}
