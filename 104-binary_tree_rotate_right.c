#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	pivot = tree->left;

	/* Connect pivot's right child to tree's left */
	tree->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = tree;

	/* Connect pivot to tree's original parent */
	pivot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	/* Move tree to be pivot's right child */
	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}
