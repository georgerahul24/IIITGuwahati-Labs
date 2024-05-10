#include <stdio.h>

void swap(int *a, int *b) {
    int c;
    c = *a;
    *a=*b;
    *b=c;


}


int main() {

    int a = 20, b = 10;
    swap(&a, &b);

    printf("%d %d", a, b);

    return 0;
}
