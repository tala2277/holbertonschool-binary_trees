#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/* Data Structure */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;

/* Prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);

#endif /* BINARY_TREES_H */
