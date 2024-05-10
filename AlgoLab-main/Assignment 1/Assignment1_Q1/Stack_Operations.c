//
// Created by gr on 25/04/23.
//

#include "Stack_Operations.h"

stack *createStack(int size) {
    stack *stack1 = malloc(sizeof(stack));
    stack1->stack = malloc(sizeof(int) * size);
    stack1->current_index = 0;
    stack1->max_index = size - 1;
    return stack1;
}

int peek(stack *stack1) {
    if (stack1->current_index >= 0) {
        return stack1->stack[stack1->current_index - 1];
    }

    return -1;
}

int push(stack *stack1, int val) {
    if (stack1->current_index > stack1->max_index) {
        return -1;
    }

    stack1->stack[stack1->current_index++] = val;
    return stack1->current_index - 1;//return at which index it was inserted;
}

int pop(stack *stack1, int *popc) {
    if (stack1->current_index > 0) {
        *popc = stack1->stack[--stack1->current_index];
        return stack1->current_index + 1;//return the index that was removed
    }

    return -1;
}

void print(stack *stack1) {
    for (int i = stack1->current_index - 1; i >= 0; i--) {
        printf("%c ", stack1->stack[i]);
    }
    printf("\n");
}

int isEmpty(stack *stack1) {
    if (stack1->current_index > 0) {
        return 0;
    }
    return 1;
}
