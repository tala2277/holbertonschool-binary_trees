#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to store in the node
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int tmp, size, bit, mask;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root) + 1;
	for (bit = 0, tmp = size; tmp > 1; tmp >>= 1, bit++)
		;
	for (parent = *root, mask = 1 << (bit - 1); mask > 1; mask >>= 1)
		parent = (size & mask) ? parent->right : parent->left;

	new_node = binary_tree_node(parent, value);
	if (size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	/* Bubble-up */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}
