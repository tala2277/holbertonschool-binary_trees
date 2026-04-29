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

/* Helper */
void binary_tree_print(const binary_tree_t *);

/* Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_complete(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
