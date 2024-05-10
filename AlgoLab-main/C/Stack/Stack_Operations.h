//
// Created by gr on 25/04/23.
//

#ifndef STACK_STACK_OPERATIONS_H
#define STACK_STACK_OPERATIONS_H

#include <stdlib.h>
#include <printf.h>

typedef struct stack {
    char *stack;
    int max_index;
    int current_index;
} stack;


stack *createStack(int size);

char peek(stack *stack1);

int push(stack *stack1, char val);

int pop(stack *stack1);

void print(stack *stack1);


#endif //STACK_STACK_OPERATIONS_H
