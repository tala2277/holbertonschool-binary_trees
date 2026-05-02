#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Helpers */
void binary_tree_print(const binary_tree_t *);
size_t binary_tree_size(const binary_tree_t *tree);

/* Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);

int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
