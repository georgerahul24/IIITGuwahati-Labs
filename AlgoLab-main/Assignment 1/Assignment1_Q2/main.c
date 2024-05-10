#include <stdio.h>
#include <math.h>

int seq(int n) {
    int i = 1;
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }


    int a = 1, b = 2;
    int c;
    while ((c = a + b + 1) <= n) {
        a = b;
        b = c;
        i++;
    }


    return i;
}


int main() {

    while (1) {
        printf("Enter value for n: ");
        int n;
        scanf("%d", &n);
        printf("Min: %d & Max: %d\n", (int) log2(n), seq(n));
    }


    return 0;
}
