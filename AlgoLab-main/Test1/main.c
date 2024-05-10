#include <stdio.h>

int main() {
    int original, num, rev = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }

    printf("The number is %d\n", rev);
    if (original == rev) {
        printf("It is a palindrome");
    } else {
        printf("It is not");
    }

    return 0;
}