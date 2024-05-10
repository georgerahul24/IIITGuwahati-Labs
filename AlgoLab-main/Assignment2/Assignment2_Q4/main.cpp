#include <iostream>

using namespace std;

#include <cstdlib>
#include "limits.h"

#define SIZE_OF_ARRAY(n) ((sizeof(n)/sizeof(int) ) - 1)

void printArray(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
}


int min(int a, int b, bool *changed) {
    if (a > b) {
        *changed = true;
        return b;
    } else {
        *changed = false;
        return a;
    }
}


int sumOfArrays(int *arrSizes, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arrSizes[i];
    }
    return sum;
}


int findMin(int **array, int *arrayIndexes, int n) {
    int current_min = INT16_MAX; //initialise to the minimum
    int current_array = 0;
    bool changed = false;
    for (int i = 0; i < n; i++) {
        current_min = min(current_min, array[i][arrayIndexes[i]], &changed);
        if (changed) current_array = i;
        changed = false;
    }
    arrayIndexes[current_array]++; //update the index of the array that was changed
    return current_min;

}


int *mergeNArrays(int n, int **arrays, int *arrSizes) {
    const int finalArraySize = sumOfArrays(arrSizes, n);
    int *finalArray = new int[finalArraySize];
    int finalArrayIndex = 0;
    int *arrayIndexes{new int[n]{0, 0}}; //Initialing with zero
    int current_min = INT16_MIN;

    current_min = findMin(arrays, arrayIndexes, n);
    while (current_min != INT16_MAX) {
        finalArray[finalArrayIndex++] = current_min;
        current_min = findMin(arrays, arrayIndexes, n);
    }

    return finalArray;


}




int main() {
    const int NUMBER_OF_ARRAYS = 4;
    int arr0[] = {8, 100, 230, INT16_MAX};
    int arr1[] = {1, 4, 7, 9, 10, INT16_MAX};
    int arr2[] = {3, 5, 7, 120, 140, INT16_MAX};
    int arr3[] = {-100, -4, 5, 9, 11, INT16_MAX};


    int **arrs = new int *[NUMBER_OF_ARRAYS];
    arrs[0] = arr0;
    arrs[1] = arr1;
    arrs[2] = arr2;
    arrs[3] = arr3;

    int *arr_size = new int[NUMBER_OF_ARRAYS];
    arr_size[0] = SIZE_OF_ARRAY(arr0);
    arr_size[1] = SIZE_OF_ARRAY(arr1);
    arr_size[2] = SIZE_OF_ARRAY(arr2);
    arr_size[3] = SIZE_OF_ARRAY(arr3);


    int *ans = mergeNArrays(NUMBER_OF_ARRAYS, arrs, arr_size);

    printArray(ans, sumOfArrays(arr_size, NUMBER_OF_ARRAYS));

}
