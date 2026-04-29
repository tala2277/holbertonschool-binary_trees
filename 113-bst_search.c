#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	while (node != NULL)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	return (NULL);
}
