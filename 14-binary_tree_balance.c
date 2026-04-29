#include "binary_trees.h"

/**
 * height_helper - measures height for balance factor
 * @tree: pointer to root node
 *
 * Return: height of tree
 */
static int height_helper(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = height_helper(tree->left);
	right_height = height_helper(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to root node
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height_helper(tree->left) - height_helper(tree->right));
}
