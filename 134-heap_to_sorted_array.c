#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to root node
 *
 * Return: size of tree
 */
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_to_sorted_array - converts a max heap to a sorted array
 * @heap: pointer to root node
 * @size: address to store array size
 *
 * Return: sorted array in descending order, or NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i;

	if (heap == NULL)
	{
		*size = 0;
		return (NULL);
	}

	*size = tree_size(heap);
	array = malloc(sizeof(int) * (*size));
	if (array == NULL)
		return (NULL);

	i = 0;
	while (heap != NULL)
		array[i++] = heap_extract(&heap);

	return (array);
}
