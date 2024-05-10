#include <stdio.h>
#include <stdlib.h>
#include "Queue_Operations.h"

#define max_size 300


void _insert(node **root, int value, queue *q) {
    if (*root == NULL) {
        *root = createNewNode(value);
        push(q, *root);

    } else {

        node *ele = pop(q);
        if (ele->left == NULL) {

            ele->left = createNewNode(value);
            return;

        } else if (ele->right == NULL) {
            ele->right = createNewNode(value);
            return;

        } else {
            push(q, ele->left);
            push(q, ele->right);
            _insert(root, value, q);
        }

    }


}

void insert(node **root, int value) {
    queue *q = create_queue(max_size);
    if (root != NULL) {
        push(q, *root);
    }
    _insert(root, value, q);
}

int main() {
    node *root = NULL;

    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);


    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);


    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 10);
    insert(&root, 11);
    insert(&root, 12);
    insert(&root, 13);
    insert(&root, 14);
    insert(&root, 15);

    insert(&root, 16);
    insert(&root, 17);
    insert(&root, 18);
    insert(&root, 19);





    print_tree(root,2);

    return 0;
}
