#include "BigNumberMultiplicationN2.hpp"


class BigNumberMultiplicationN :
        public BigNumberMultiplicationN2 {

protected:


    static bigNumber *multiplyBigNumber(bigNumber *n1, bigNumber *n2) {
        bigNumber* ans= static_cast<bigNumber*>(malloc(sizeof(bigNumber) ));
        ans->n_size = n1->n_size + n2->n_size + 1;
        ans->n = static_cast<int *>( calloc(sizeof(int), ans->n_size));

        int carry = 0;
        int temp = 0;

        for (int i = 0; i < n2->n_size; i++) {

            for (int j = 0; j < n1->n_size; j++) {
                temp = ((ans->n[i + j] + n1->n[j] * n2->n[i]) + carry);
                ans->n[i + j] = temp % 10;
                carry = temp / 10;
            }
            ans->n[i + n1->n_size] = carry;
            carry = 0;


        }

        return ans;

    }

public:
    int main() override {
        bigNumber n1, n2;
        printf("Enter the number of digits: ");
        scanf("%d", &n1.n_size);
        n1.n = static_cast<int *>(malloc(n1.n_size * sizeof(int)));
        getBigNumber(&n1);
        printNumber(&n1, true);


        printf("Enter the number of digits: ");
        scanf("%d", &n2.n_size);
        n2.n = static_cast<int *>(malloc(n2.n_size * sizeof(int)));
        getBigNumber(&n2);
        printNumber(&n2, true);

        bigNumber *ans = multiplyBigNumber(&n1, &n2);
        printNumber(ans, true);
        return 0;

    }


};