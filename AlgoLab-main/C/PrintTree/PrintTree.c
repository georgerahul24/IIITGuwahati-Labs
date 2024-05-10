//
// Created by gr on 18/06/23.
//

#include "PrintTree.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}


void printSpaces(int len){
    while (len--){
        printf(" ");
    }
}

void printCurrentLevel(node *root, int height, int currentHeight, int max_height) {
    if (root != NULL) {
        printSpaces((max_height-currentHeight)/currentHeight);
        if (currentHeight == height) {
            printf("+--%d---+", root->data);
        } else {
            printCurrentLevel(root->left, height, currentHeight + 1, max_height);
            printCurrentLevel(root->right, height, currentHeight + 1, max_height);
        }
        printSpaces((max_height-currentHeight)/currentHeight);
    }
}


int printTree(node *root) {
    int height = getHeight(root);
    for (int i = 0; i < height; i++) {
        printCurrentLevel(root, i, 0, height);
        printf("\n");
    }
}