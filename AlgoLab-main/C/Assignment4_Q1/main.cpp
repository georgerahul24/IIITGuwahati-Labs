#include <iostream>


int findPeak(int *arr, int arr_size, int low, int high) {
    int middle = low + (high - low) / 2;
    if ((middle == 0 ||
         arr[middle - 1] <= arr[middle]) // Checking if either index is 0 or if the left element is smaller
        &&
        (middle == arr_size - 1 || arr[middle + 1] <= arr[middle])) // Checking for the right condition
    {
        return middle;
    } else if (middle > 0 && arr[middle - 1] > arr[middle]) {
        return findPeak(arr, arr_size, low, middle - 1);//If left element is greater go to the left side
    } else {
        return findPeak(arr, arr_size, middle + 1, high);//If right element is greater, go to the right side
    }
}


int main() {
    int arr[] = {1,2,3};
    int arr_size = sizeof(arr) / sizeof(int);
    std::cout << "The Peak Element is: " << arr[findPeak(arr, arr_size, 0, arr_size - 1)];
    return 0;
}
