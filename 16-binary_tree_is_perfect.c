#include "binary_trees.h"

/**
 * height - calculates tree height
 * @tree: pointer to root node
 *
 * Return: height of tree
 */
static int height(const binary_tree_t *tree)
{
	int l;
	int r;

	if (tree == NULL)
		return (0);

	l = height(tree->left);
	r = height(tree->right);

	if (l > r)
		return (l + 1);

	return (r + 1);
}

/**
 * size - calculates tree size
 * @tree: pointer to root node
 *
 * Return: size of tree
 */
static int size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + size(tree->left) + size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h;
	int s;
	int expected;

	if (tree == NULL)
		return (0);

	h = height(tree);
	s = size(tree);
	expected = (1 << h) - 1;

	return (s == expected);
}
