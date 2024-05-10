//
// Created by gr on 18/06/23.
//

#ifndef PRINTTREE_PRINTTREE_H
#define PRINTTREE_PRINTTREE_H

#include "stdio.h"

int max(int a, int b);


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node,node;


int getHeight(Node *root);
int printTree(node *root);

#endif //PRINTTREE_PRINTTREE_H
