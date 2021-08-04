#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 * @parent: parent of the node
 * @value: value for the node
 *
 * Return: Node or Null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);

}
