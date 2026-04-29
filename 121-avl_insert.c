#include "binary_trees.h"

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: Double pointer to the current node
 * @parent: Parent of the current node
 * @new_node: Double pointer to store the newly created node
 * @value: Value to insert
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new_node, int value)
{
	int balance;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree, new_node, value);
		if (!*new_node)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&((*tree)->right), *tree, new_node, value);
		if (!*new_node)
			return (NULL);
	}
	else
		return (*tree);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node
 * @value: Value to store in the node
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	*tree = avl_insert_recursive(tree, NULL, &new_node, value);
	return (new_node);
}
