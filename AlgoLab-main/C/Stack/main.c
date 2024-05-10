#include "Stack_Operations.h"
#include "Arithmethic_Expression_Checker/arithmetic_expression.h"
#include "Infix_to_Postfix.h"

#define max_size 1000


int main() {

    FILE *f = fopen("/Users/gr/Desktop/C/Stack/input.txt", "r");

    char input[max_size];
    fgets(input, max_size, f);

    int status = arithmetic_stack(input, max_size);
    if (status) {
        printf("\nArithmetically invalid expression");
    } else printf("Arithmetically Valid expression");

    //convert_infix_to_postfix(input, max_size);


    return 0;
}
