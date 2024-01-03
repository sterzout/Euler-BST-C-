// CS2211a 2023
// Assignment #4
// Salim Terzout Yettou
// 251214366
// sterzout
// November 15, 2023

#include <stdio.h>
#include "bst.h"
int main(void) {
    BStree bst;
    bst = bstree_ini(600);
    bstree_insert(bst, key_construct("Oxford Street", 70), 2500);
    bstree_insert(bst, key_construct("3 Valleys Place", 8), 2000);
    bstree_insert(bst, key_construct("Western Road", 101), 2500);
    bstree_insert(bst, key_construct("3rd Street", 74), 3000);
    bstree_insert(bst, key_construct("4 Oaks Crescent", 4), 2100);
    bstree_insert(bst, key_construct("Abbott Street", 10), 2300);
    bstree_insert(bst, key_construct("1st Street", 100), 1000);
    bstree_insert(bst, key_construct("Beech Drive", 204), 1800);
    bstree_insert(bst, key_construct("Beechbank Crescent", 36), 2400);
    bstree_insert(bst, key_construct("Beechmount Crescent", 36), 2500);
    bstree_insert(bst, key_construct("Oxford Street", 46), 2600);
    bstree_traversal(bst);
    bstree_free(bst);
}