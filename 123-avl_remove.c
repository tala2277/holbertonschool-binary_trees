#include "binary_trees.h"

/**
 * avl_balance_node - Balances an AVL tree node
 * @root: Pointer to the node to balance
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_balance_node(avl_t *root)
{
	int balance;

	if (!root)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * bst_min_node - Finds the smallest node in a subtree
 * @root: Pointer to the root of the subtree
 * Return: Pointer to the min node
 */
avl_t *bst_min_node(avl_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node
 * @value: Value to remove
 * Return: Pointer to the new root node after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = bst_min_node(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	return (avl_balance_node(root));
}
