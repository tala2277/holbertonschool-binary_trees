#include "binary_trees.h"

/**
 * count_nodes - Counts the nodes in a binary tree
 * @tree: Pointer to the root node
 * Return: Number of nodes
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_comp - Recursive helper to check completeness
 * @tree: Pointer to the root node
 * @index: Index of the current node
 * @n: Total number of nodes
 * Return: 1 if complete, 0 otherwise
 */
int is_comp(const binary_tree_t *tree, size_t index, size_t n)
{
	if (tree == NULL)
		return (1);

	if (index >= n)
		return (0);

	return (is_comp(tree->left, 2 * index + 1, n) &&
			is_comp(tree->right, 2 * index + 2, n));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 * Return: 1 if complete, 0 if NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);

	nodes = count_nodes(tree);
	return (is_comp(tree, 0, nodes));
}
