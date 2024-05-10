#include <stdio.h>
#include <stdlib.h>


#ifndef LEVELORDER_QUEUE_OPERATIONS_H
#define LEVELORDER_QUEUE_OPERATIONS_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;


typedef struct queue {
    node **queue;
    int max_size;
    int front;
    int back;
} queue;


queue *create_queue(int max_size);

int push(queue *q, node *data);

node *createNewNode(int data);

node *pop(queue *q);

node *peek(queue *q);

void print_queue(queue *q);

void print_tree(node *root,int type);
#endif //LEVELORDER_QUEUE_OPERATIONS_H
