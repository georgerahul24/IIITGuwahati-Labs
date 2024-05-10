#include <stdio.h>

int ternarySearch(int *arr, int num, int l, int h) {
    if (l <= h) {
        int mid1 = (l + h) / 3;
        int mid2 = ((l + h) * 2) / 3;
        if (num == arr[mid1])
            return mid1;
        else if (num == arr[mid2])
            return mid2;
        else if (num < arr[mid1])
            return ternarySearch(arr, num, l, mid1 - 1);
        else if (num > arr[mid2])
            return ternarySearch(arr, num, mid2 + 1, h);
        else
            return ternarySearch(arr, num, mid1 + 1, mid2 - 1);
    } else
        return -1;
}

int main() {
    int n, num;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element whose position is to be found: ");
    scanf("%d", &num);
    printf("The index of the element is %d", ternarySearch(arr, num, 0, n - 1));
    return 0;
}
