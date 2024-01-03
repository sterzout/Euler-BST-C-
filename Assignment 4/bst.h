//
// Created by Salim Terzout on 2023-11-09.
//

#ifndef ASSIGNMENT_4_BST_H
#define ASSIGNMENT_4_BST_H

#endif //ASSIGNMENT_4_BST_H
#include "data.h"
typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);