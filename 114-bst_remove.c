#include "binary_trees.h"

/**
 * bst_min - Finds the smallest node in a BST
 * @root: Pointer to the root of the tree
 * Return: Pointer to the minimum node
 */
bst_t *bst_min(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Case 1 & 2: No child or only one child */
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* Case 3: Two children */
		successor = bst_min(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
