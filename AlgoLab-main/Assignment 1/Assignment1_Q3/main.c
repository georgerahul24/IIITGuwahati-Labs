#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n_size;
    int *n;
} bigNumber;


void getBigNumber(bigNumber *n) {

    printf("Enter the number: ");
    int i = 1;
    char c;
    while (i <= n->n_size) {
        scanf(" %c", &c);
        c -= '0'; //converting from char to int value of the number
        n->n[n->n_size - i++] = c;
    }
}

void printNumber(bigNumber *n) {
    printf("The number is: ");
    int i = 0;

    while (i < n->n_size) {
        printf("%d", n->n[i++]);
    }


    printf("\n");
}

bigNumber *addMultOfBigNumbers(int **arr, bigNumber *n1, bigNumber *n2) {

    bigNumber *bn = malloc(sizeof(bigNumber));
    bn->n_size = n1->n_size + n2->n_size + 1;
    bn->n = calloc(sizeof(int), bn->n_size);

    int carry = 0;
    for (int i = 0; i < n1->n_size + n2->n_size + 1; i++) {

        int sumcol = 0;
        for (int j = 0; j < n2->n_size; j++) {

            sumcol += arr[j][i];

        }

        bn->n[i] = (sumcol + carry) % 10;
        carry = (sumcol + carry) / 10;


    }
    bn->n[bn->n_size - 1] = carry;

    printNumber(bn);
    for (int i = 0; i < n2->n_size; i++) {
        free(arr[i]);
    }
    free(arr);
    return bn;
}


bigNumber *multiplyBigNumber(bigNumber *n1, bigNumber *n2) {


    int **arr = calloc(n2->n_size, sizeof(int *));
    for (int i = 0; i < n2->n_size; i++) {
        arr[i] = calloc(n1->n_size + n2->n_size + 1, sizeof(int));
    }


    for (int i = 0; i < n2->n_size; i++) {
        int j = i, z = i;
        int carry = 0;
        int k = 0;
        for (; k < n1->n_size; k++) {
            int mult = n1->n[k] * n2->n[i];

            int mult1 = mult % 10;

            arr[j][z + k] =( mult1 + carry)%10;
            carry = (mult + carry) / 10;

        }
        arr[j][z + k] = carry;


    }

    for (int i = 0; i < n2->n_size; i++) {
        for (int j = n1->n_size + n2->n_size + 1; j >= 0; --j) {

            printf("%d", arr[i][j]);
        }
        printf("\n");
    }


    return
            addMultOfBigNumbers(arr, n1, n2);
}


int main() {

    bigNumber n1, n2;
    printf("Enter the number of digits: ");
    scanf("%d", &n1.n_size);
    n1.n = malloc(n1.n_size * sizeof(int));
    getBigNumber(&n1);
    printNumber(&n1);


    printf("Enter the number of digits: ");
    scanf("%d", &n2.n_size);
    n2.n = malloc(n2.n_size * sizeof(int));
    getBigNumber(&n2);
    printNumber(&n2);


    bigNumber *ans = multiplyBigNumber(&n1, &n2);
    printNumber(ans);

    printf("\nThe ans is: ");

    for (int i = ans->n_size - 1; i >= 0; i--) {
        printf("%d", ans->n[i]);
    }

    return 0;


}