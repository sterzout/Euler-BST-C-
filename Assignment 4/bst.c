// CS2211a 2023
// Assignment #4
// Salim Terzout Yettou
// 251214366
// sterzout
// November 15, 2023
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
BStree bstree_ini(int size) {
    BStree tree;
    tree.size = size;
    tree.tree_nodes = (Node*) malloc((size+1)*sizeof(Node));
    tree.is_free = (unsigned char*) malloc((size+1)*sizeof(unsigned char));
    int i = 0;
    while(i < size+1){
        tree.is_free[i] = 1;
        i++;
    }
    return tree;
    // initialize variables, allocate memory for our free tree and node tree and then initialize the tree to all 1's
    // as an indication that it is free if 1
}
void place(BStree bst, Key key, int data, int position) {
    if (position >= bst.size || position <0){printf("Position is out of bounds"); return;}
    // if valid index return print statement and exit with return
    // if already in the tree do nothing
    if (key_comp(bst.tree_nodes[position].key, key) == 0){
        return;
    }
    // if larger than key check if left child is free then insert there if not call it recursively on left child
    if (key_comp(bst.tree_nodes[position].key,key) ==1) {
        if (bst.is_free[2*position] == 1) {
            bst.tree_nodes[2*position].key = key, bst.tree_nodes[2*position].data = data;
            bst.is_free[2*position] = 0;
            return;
        } else {
            place(bst, key, data, 2 * position);
        }
    }
    // if smaller than key check if right child is free then insert there if not call it recursively on right child
    if (key_comp(bst.tree_nodes[position].key,key) ==-1) {
        if (bst.is_free[2*position+1] == 1) {
            bst.tree_nodes[2*position+1].key = key, bst.tree_nodes[2*position+1].data = data;
            bst.is_free[2*position+1] = 0;
            return;
        } else {
            place(bst, key, data, 2 * position);
        }
    }
}
int inTree(BStree bst, Key key) {
    for (int i = 0; i < bst.size; i++) {
        if (key_comp(bst.tree_nodes[i].key, key) == 0) {
            return 1;
        }
        //iterate entire tree with key comparison to see if it is in the tree already if so return 1 else return 0
    }
    return 0;
}
void bstree_insert(BStree bst, Key key, int data) {
    if (inTree(bst,key)==0){
        place(bst, key, data, 0);
    }
    // if inTree returns 0 it means it is not in the tree and we can call the place method to put it in the tree
}
void inOrderTraversal(BStree bst, int position) {
    if (position >= bst.size || position<0) {
        return;
        // if position is invalid return and stop
    } else {
        inOrderTraversal(bst, 2 * position);
        print_node(bst.tree_nodes[position]);
        inOrderTraversal(bst, 2 * position + 1);
        // else we traverse inorder through left then right as needed
    }
}
void bstree_traversal(BStree bst) {
    inOrderTraversal(bst,0);
    //traversal inorder through our helper method
}
void bstree_free(BStree bst) {
    free(bst.tree_nodes);
    free(bst.is_free);
    // free both trees with free method
}