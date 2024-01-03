// CS2211a 2023
// Assignment #4
// Salim Terzout Yettou
// 251214366
// sterzout
// November 15, 2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
Key key_construct(char *in_name, int in_num) {
    Key key;
    key.name = (char*)malloc(strlen(in_name+1));
    if (key.name != NULL){
        strcpy(key.name,in_name);
    }
    key.num = in_num;
    return key;
    // key constructor. Allocating memory and setting the variables needed
}
int key_comp(Key key1, Key key2) {
    if (key1.name != NULL && key2.name != NULL) {
        // if both keys are not null continue
        if (strcmp(key1.name, key2.name) < 0) {
            return -1;
        }
        //return -1 for smaller, 1 for larger and if 0 then re-compare with the values
        if (strcmp(key1.name, key2.name) > 0) {
            return 1;
        } else {
            if (strcmp(key1.name, key2.name) == 0) {
                if (key1.num > key2.num) {
                    return 1;
                }
                if (key1.num < key2.num) {
                    return -1;
                }
            }
        }
    }
    return 0;
}
void print_key(Key key) {
    if (key.num ==1){printf("%d %s\n",key.num, key.name);}
    //print the key num and name with new line after each if equal to 1
}
void print_node(Node node) {
    print_key(node.key);
    if (node.data ==1)printf("node: %d\n", node.data);
    //print the key node/node.data
}
