//
// Created by gr on 10/05/23.
//

#include "Queue_Operations.h"

node *createNewNode(int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}


queue *create_queue(int max_size) {
    queue *new = malloc(sizeof(queue));
    new->max_size = max_size;
    new->front = 0;
    new->back = -1;
    new->queue = malloc(sizeof(node *) * max_size);
    return new;
}

int push(queue *q, node *data) {
    if (q->back == q->max_size) {
        return -1;
    } else {

        q->queue[++q->back] = data;
    }
}

node *pop(queue *q) {
    if (q->front > q->back) {
        return NULL;
    }
    return q->queue[q->front++];
}

node *peek(queue *q) {
    if (q->front > q->back) {
        return NULL;
    }
    return q->queue[q->front];
}

void print_queue(queue *q) {
    for (int i = q->front; i < q->back + 1; i++) {
        printf("%d->", q->queue[i]->data);
    }
    printf("\n");
}


void print_tree_inorder(node *root, int depth) {
    if (root == NULL) return;
    else {
        if (root->left == NULL);
        else {
            print_tree_inorder(root->left, depth + 1);
        }

        for (int i = 0; i < depth * 2; i++) {
            printf("   ");
        }
        for (int i = 0; i < depth * 2; i++) {
            printf("   ");
        }


        printf("%d\n", root->data);

        if (root->right == NULL);
        else {
            print_tree_inorder(root->right, depth + 1);
        }


    }
}

void get_left_max_depth(node *root, int *depth) {
    if (root->left != NULL) {
        get_left_max_depth(root->left, depth);
        *depth = *depth + 1;
    } else return;

}


void _print_tree_level_order(node *root, int depth, queue *q) {

}

void print_tree_level_order(node *root, int depth) {
    queue *q = create_queue(1000);
    _print_tree_level_order(root, depth, q);

}


void print_tree(node *root, int type) {
    int depth = 0;
    switch (type) {
        case 1:
            print_tree_inorder(root, 0);
            break;
        case 2:

            get_left_max_depth(root, &depth);
            printf("Max Depth: %d", depth);


    }


}
