#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL)
		new->parent = NULL;

	else if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;
	new->parent = parent;
	return (new);

}
