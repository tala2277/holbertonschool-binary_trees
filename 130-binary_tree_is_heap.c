#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root
 * @index: Current node index
 * @size: Total number of nodes
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * check_max - Checks if parent nodes are greater than children
 * @tree: Pointer to the root
 * Return: 1 if max heap property holds, 0 otherwise
 */
int check_max(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (check_max(tree->left) && check_max(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node
 * Return: 1 if valid, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = tree_size(tree);

	if (!is_complete(tree, 0, size))
		return (0);

	return (check_max(tree));
}
