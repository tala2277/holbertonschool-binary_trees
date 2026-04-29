git init
git remote add origin https://github.com/tala2277/holbertonschool-binary_trees.git
git branch -m main
cat <<EOF > binary_trees.h
#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

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

/* Prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

#endif /* BINARY_TREES_H */
EOF

cat <<EOF > 0-binary_tree_node.c
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
EOF

git add binary_trees.h 0-binary_tree_node.c
git commit -m "Initial commit: Add header and task 0"
git push -u origin main
git add binary_trees.h 0-binary_tree_node.c
git commit -m "Initial commit: Add header and task 0"
git push -u origin main
git pull origin main --allow-unrelated-histories
git push -u origin main
git config pull.rebase false
git pull origin main --allow-unrelated-histories
git push -u origin main
rm -rf .git
git init
