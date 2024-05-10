//
// Created by gr on 25/04/23.
//

#include "arithmetic_expression.h"

int arithmetic_stack(const char *string, int max_size) {
    int flag = 0;
    stack *s1 = createStack(max_size);
    int index = 0;

    while (index < strlen(string)) {

        if (string[index] == '{' || string[index] == '(' || string[index] == '[') {
            push(s1, string[index]);
            flag++;
        } else if (string[index] == '}' || string[index] == ')' || string[index] == ']') {
            char top = peek(s1);
            if (top == -1) {
                printf("Mismatched %c in the expression at index %d", string[index], index);
                return -1;
            } else if ((string[index] == '}' && top != '{') || (string[index] == ']' && top != '[') ||
                       (string[index] == ')' && top != '(')) {
                printf("Mismatched %c in the expression at index %d", string[index], index);
                return -1;
            } else {
                pop(s1);
            }


        }


        index++;
    }

    return 0;

}
