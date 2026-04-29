#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Helper */
void binary_tree_print(const binary_tree_t *);

/* Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* AVL specific */
avl_t *avl_insert(avl_t **tree, int value);

#endif /* BINARY_TREES_H */
