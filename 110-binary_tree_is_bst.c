#include "binary_trees.h"

/**
 * check_bst - Validates a BST within a given range
 * @tree: Pointer to the root node
 * @min: Minimum allowable value
 * @max: Maximum allowable value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n) &&
			check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid, 0 if NULL or invalid
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
