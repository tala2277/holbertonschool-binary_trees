#include "binary_trees.h"

/**
 * tree_h - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree
 */
size_t tree_h(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (tree == NULL)
		return (0);
	hl = tree_h(tree->left);
	hr = tree_h(tree->right);
	if (hl > hr)
		return (hl + 1);
	return (hr + 1);
}

/**
 * post_lvl - Prints nodes at a specific level
 * @tree: Pointer to the root node
 * @level: Level to print
 * @func: Function to call for each node
 */
void post_lvl(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		post_lvl(tree->left, level - 1, func);
		post_lvl(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Level-order traversal
 * @tree: Root node
 * @func: Function pointer
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;
	h = tree_h(tree);
	for (i = 1; i <= h; i++)
		post_lvl(tree, i, func);
}
