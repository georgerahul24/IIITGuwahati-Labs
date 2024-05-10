#include <iostream>

using namespace std;


class BinarySearch {
public:
    int *arr;
    int arr_size;
    int target;

    BinarySearch() {
        cout << "Enter the size of the array: ";
        cin >> arr_size;
        cout << "Enter the array: ";
        for (int i = 0; i < arr_size; i++) {
            cin >> arr[i];
        }

        printArray();


    }


    BinarySearch(int arr[], int arr_length, int target) {
        this->arr = arr;
        this->arr_size = arr_length;
        this->target = target;


    }


    int normalBinarySearch(int start, int end) {

        if (end < start) return -1;

        int middle = start + ((end - start) / 2);
        if (arr[middle] == target) {
            return middle;
        } else {

            if (arr[middle] > target) return normalBinarySearch(start, middle - 1);
            return normalBinarySearch(middle + 1, end);
        }


    }

    int alphaBinarySearch(int start, int end) {
        if (end < start) return -1;

        int middle = start + (2 * (end - start) / 3);
        if (arr[middle] == target) {
            return middle;
        } else {

            if (arr[middle] > target) return alphaBinarySearch(start, middle - 1);
            return alphaBinarySearch(middle + 1, end);
        }

    }



    int betaBinarySearch(int start, int end) {
        if (end < start) return -1;

        int middle = start + (1 * (end - start) / 4);
        if (arr[middle] == target) {
            return middle;
        } else {

            if (arr[middle] > target) return alphaBinarySearch(start, middle - 1);
            return alphaBinarySearch(middle + 1, end);
        }

    }


    void printArray() {
        for (int i = 0; i < arr_size; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

};

