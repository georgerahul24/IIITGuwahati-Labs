#include <stdio.h>

int main() {

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int j;
    printf("Enter the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &j);
        arr[i] = j;
    }
    int max, min;
    max = arr[0] > arr[n - 1] ? arr[0] : arr[n - 1];
    min = arr[0] < arr[n - 1] ? arr[0] : arr[n - 1];


    printf("The max element is: %d && The min element is: %d\n", max, min);


    return 0;
}
