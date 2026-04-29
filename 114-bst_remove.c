#include "binary_trees.h"

/**
 * bst_min_val - Finds the smallest node in a subtree
 * @root: Pointer to the root of the subtree
 * Return: Pointer to the node with the minimum value
 */
bst_t *bst_min_val(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_delete_node - Handles the actual removal of a node
 * @node: Pointer to the node to delete
 * Return: Pointer to the new child that replaces the deleted node
 */
bst_t *bst_delete_node(bst_t *node)
{
	bst_t *parent = node->parent, *successor, *replacement = NULL;

	if (node->left && node->right)
	{
		successor = bst_min_val(node->right);
		node->n = successor->n;
		return (bst_remove(node->right, successor->n));
	}
	if (node->left)
		replacement = node->left;
	else if (node->right)
		replacement = node->right;
	if (replacement)
		replacement->parent = parent;
	free(node);
	return (replacement);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		return (bst_delete_node(root));
	}
	return (root);
}
