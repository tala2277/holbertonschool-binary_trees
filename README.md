# Binary Trees

## Overview
This project focuses on implementing binary trees in C as part of data structures fundamentals. It covers the creation and manipulation of tree nodes while following strict coding and compilation standards.

## Authors
- Tala Alhudaibi
- Reem Alanazi

## Project Description
In this project, we implemented a function to create a binary tree node. The function allocates memory for a new node, assigns the given value, links it to its parent, and initializes its children pointers to NULL.

## Files
- binary_trees.h
- 0-binary_tree_node.c

## Function Prototype
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

## Compilation
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-binary_tree_node.c 0-main.c binary_tree_print.c -o 0-node

## Requirements
- Ubuntu 20.04 LTS
- No global variables
- Max 5 functions per file
- Betty style
- All files end with new line

## Learning Objectives
- Understanding binary trees
- Working with pointers and memory allocation
- Building structured C programs
