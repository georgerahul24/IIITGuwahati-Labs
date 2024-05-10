#include <stdio.h>


void print(const int array[], const int size) {

    int index = 0;
    while (index < size) {
        printf("%d->", array[index++]);
    }


}


void merge_sort(int array[], int start, int end) {

    if (start == end) return;


    int middle = (end - start) / 2;
    merge_sort(array, start, middle);
    merge_sort(array, middle, end);





}


int main() {

    int size = 0;
    printf("Enter the size of the array: ");
    scanf(" %d", &size);
    int array[size];
    printf("Enter the array: ");
    int index = 0;

    while (index < size) {
        scanf(" %d", &array[index++]);
    }

    print(array, size);
}