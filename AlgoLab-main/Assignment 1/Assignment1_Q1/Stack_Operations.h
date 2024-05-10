//
// Created by gr on 25/04/23.
//

#ifndef STACK_STACK_OPERATIONS_H
#define STACK_STACK_OPERATIONS_H

#include <stdlib.h>
#include <printf.h>

typedef struct stack {
    int *stack;
    int max_index;
    int current_index;
} stack,Stack;


stack *createStack(int size);

int peek(stack *stack1);

int push(stack *stack1, int val);

int pop(stack *stack1, int *popc);

void print(stack *stack1);

int isEmpty(stack *stack1);

#endif //STACK_STACK_OPERATIONS_H
