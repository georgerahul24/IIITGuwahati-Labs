//
// Created by gr on 29/04/23.
//
#include <string.h>
#include "Stack_Operations.h"

#ifndef STACK_INFIX_TO_POSTFIX_H
#define STACK_INFIX_TO_POSTFIX_H


typedef struct node {
    char s[5];
    int precedence;
    struct node *next;
} node;


void add_at_beginning(const char *s, int precedence, node **head);

node *load_symbols_data();

int convert_infix_to_postfix(const char *input, int maxsize);

int is_symbol(const char *s, node *head);

#endif //STACK_INFIX_TO_POSTFIX_H
