//
// Created by gr on 10/05/23.
//


#include <stdio.h>
#include <stdlib.h>


typedef struct queue {
     int *queue;
    int max_size;
    int front;
    int back;
} queue;


queue *create_queue(int max_size);

int push(queue *q, int data);


int pop(queue *q);

int peek(queue *q);

void print_queue(queue *q);

queue *create_queue(int max_size) {
    queue *new = malloc(sizeof(queue));
    new->max_size = max_size;
    new->front = 0;
    new->back = -1;
    new->queue = malloc(sizeof(int) * max_size);
    return new;
}

int push(queue *q,  int data) {
    if (q->back == q->max_size) {
        return -1;
    } else {

        q->queue[++q->back] = data;
    }
}



int pop(queue *q) {
    if (q->front > q->back) {
        return -1;
    }
    return q->queue[q->front++];
}



int peek(queue *q) {
    if (q->front > q->back) {
        return -1;
    }
    return q->queue[q->front];
}





