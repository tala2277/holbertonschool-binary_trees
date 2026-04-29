#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heapify_down - Restores the Max Heap property from root down
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root, *left = root->left, *right = root->right;
	int tmp;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Finds the last node in level-order
 * @root: Pointer to root
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root)
{
	size_t size = tree_size(root);
	size_t mask;
	heap_t *last = root;

	for (mask = 1; mask <= size; mask <<= 1)
		;
	mask >>= 2;

	while (mask > 0)
	{
		if (size & mask)
			last = last->right;
		else
			last = last->left;
		mask >>= 1;
	}
	return (last);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value stored in root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	last = get_last_node(*root);

	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last->n;
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
