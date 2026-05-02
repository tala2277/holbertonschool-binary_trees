#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts heap to sorted array (descending)
 * @heap: pointer to root
 * @size: address to store size
 *
 * Return: pointer to array or NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;

	if (!heap)
	{
		*size = 0;
		return (NULL);
	}

	*size = binary_tree_size(heap);

	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	while (heap)
	{
		array[i++] = heap_extract(&heap);
	}

	return (array);
}
