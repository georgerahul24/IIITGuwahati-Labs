
#include <cstdio>
#include <cstdlib>

typedef struct {
    int n_size;
    int *n;
} bigNumber;

class BigNumberMultiplicationN2 {
protected:

    void static getBigNumber(bigNumber *n) {

        printf("Enter the number: ");
        int i = 1;
        char c;
        while (i <= n->n_size) {
            scanf(" %c", &c);
            c -= '0'; //converting from char to int value of the number
            n->n[n->n_size - i++] = c;
        }
    }

    static void printNumber(bigNumber *n) {
        printf("The number is: ");
        int i = 0;

        while (i < n->n_size) {
            printf("%d", n->n[i++]);
        }


        printf("\n");
    }

    static void printNumber(bigNumber *n, bool rev) {
        printf("The number is: ");
        int i = n->n_size;


        while (i--) {
            printf("%d", n->n[i]);
        }


        printf("\n");
    }


    static bigNumber *addMultOfBigNumbers(int **arr, bigNumber *n1, bigNumber *n2) {

        auto *bn = static_cast<bigNumber *>(malloc(sizeof(bigNumber)));
        bn->n_size = n1->n_size + n2->n_size + 1;
        bn->n = static_cast<int *>(calloc(sizeof(int), bn->n_size));

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


    static bigNumber *multiplyBigNumber(bigNumber *n1, bigNumber *n2) {


        int **arr = static_cast<int **>  (calloc(n2->n_size, sizeof(int *)));
        for (int i = 0; i < n2->n_size; i++) {
            arr[i] = static_cast<int *>(calloc(n1->n_size + n2->n_size + 1, sizeof(int)));
        }


        for (int i = 0; i < n2->n_size; i++) {
            int j = i, z = i;
            int carry = 0;
            int k = 0;
            for (; k < n1->n_size; k++) {
                int mult = n1->n[k] * n2->n[i];

                int mult1 = mult % 10;

                arr[j][z + k] = (mult1 + carry) % 10;
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


public:
    virtual int main() {

        bigNumber n1, n2;
        printf("Enter the number of digits: ");
        scanf("%d", &n1.n_size);
        n1.n = static_cast<int *>(malloc(n1.n_size * sizeof(int)));
        getBigNumber(&n1);
        printNumber(&n1);


        printf("Enter the number of digits: ");
        scanf("%d", &n2.n_size);
        n2.n = static_cast<int *>(malloc(n2.n_size * sizeof(int)));
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


};