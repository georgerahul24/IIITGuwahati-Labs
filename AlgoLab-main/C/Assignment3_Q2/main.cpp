#include <iostream>


int check(int *arr, int arr_size,int start, int end) {

    if (start>=end) return arr[start]-1;
    else {

        int middle = start + (end - start) / 2;


        if (middle + 1 < arr[middle]) {
            return check(arr, arr_size,start, middle - 1);
        } else
        {
            return check(arr, arr_size,middle + 1, end);
        }


    }
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int arr_size = sizeof(arr) / sizeof(int);

    std::cout << check(arr, arr_size,0, arr_size - 1);
    return 0;
}
