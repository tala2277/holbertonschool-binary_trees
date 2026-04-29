#include "binary_trees.h"

/**
 * create_tree - Auxiliary function to build an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Start index of the subarray
 * @end: End index of the subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created subtree, or NULL
 */
avl_t *create_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	new_node->left = create_tree(array, start, mid - 1, new_node);
	new_node->right = create_tree(array, mid + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (create_tree(array, 0, (int)size - 1, NULL));
}
