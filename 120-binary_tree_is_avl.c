#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (tree == NULL)
		return (0);

	h_left = height(tree->left);
	h_right = height(tree->right);

	return ((h_left > h_right ? h_left : h_right) + 1);
}

/**
 * check_bst_avl - Validates BST and checks balance factor
 * @tree: Pointer to the root node
 * @min: Minimum allowable value
 * @max: Maximum allowable value
 * Return: 1 if valid AVL, 0 otherwise
 */
int check_bst_avl(const binary_tree_t *tree, int min, int max)
{
	size_t hl, hr, diff;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	hl = height(tree->left);
	hr = height(tree->right);
	diff = hl > hr ? hl - hr : hr - hl;

	if (diff > 1)
		return (0);

	return (check_bst_avl(tree->left, min, tree->n) &&
			check_bst_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if valid, 0 if NULL or invalid
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst_avl(tree, INT_MIN, INT_MAX));
}
