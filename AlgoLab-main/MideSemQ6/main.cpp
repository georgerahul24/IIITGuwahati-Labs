#include <iostream>

using namespace std;


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    printArray(arr, n);
    int low = 0;
    int high = n - 1;
    int max;
    while (true) {
        if (low == high) {
            max = low;
            break;
        } else {

            int middle = low + (high - low) / 2;


            if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1]) {
                max = arr[middle];
                break;
            } else {
                if (arr[middle] < arr[low] > 0) {
                    high = middle;
                } else {
                    low = middle;
                }
            }


        }
    }


    cout << "The max element is: " << max << endl;

}