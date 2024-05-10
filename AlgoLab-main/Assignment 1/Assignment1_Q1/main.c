#include <stdio.h>
#include <string.h>
#include "Stack_Operations.h"


#define max_size 1000


int pow(int x, int y) {
    int sum = x;
    for (int i = 1; i < y; i++) {
        sum *= x;
    }
    return sum;

}


int isOperatorAndOperatorPrecedence(char s) {
    switch (s) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;

    }
}

int _evaluate(int x, int y, char o) {

    switch (o) {
        case '^':
            return pow(y, x);
        case '+':
            return x + y;
        case '-':
            return y-x;
        case '*':
            return x * y;
        case '/':
            return y / x;
        default:
            printf("There is an error in the expression");
            return 0;

    }


}

int evaluate(char *input, Stack *operators, Stack *operands) {

    char *ptr = strtok(input, " ");
    while (ptr != NULL) {

        if (isOperatorAndOperatorPrecedence(ptr[0])) {
            if (isOperatorAndOperatorPrecedence(ptr[0]) >= isOperatorAndOperatorPrecedence(peek(operators))) {

            } else {
                while (isOperatorAndOperatorPrecedence(ptr[0]) <= isOperatorAndOperatorPrecedence(peek(operators))) {
                    int x, y, o;
                    pop(operands, &x);
                    pop(operands, &y);
                    pop(operators, &o);
                    push(operands, _evaluate(x, y, o));
                }

            }
            push(operators, ptr[0]);


        } else push(operands, atoi(ptr));


        ptr = strtok(NULL, " ");
    }

    while (!isEmpty(operators)) {
        int x, y, o;
        pop(operands, &x);
        pop(operands, &y);
        pop(operators, &o);
        push(operands, _evaluate(x, y, o));
    }

    return peek(operands);
}


int main() {

    char input[max_size] = "1 + 22 * 5 * 2 - 100 / 10 - 4 / 2 + 10 - 48 / 6 + 11\n";
    printf("Enter the expression: ");
    //fgets(input, max_size, stdin);

    int length = strlen(input);
    input[length - 1] = '\0';

    Stack *operands = createStack(length);
    Stack *operators = createStack(length);
    printf("The ans is: %d", evaluate(input, operators, operands));


    return 0;

}
