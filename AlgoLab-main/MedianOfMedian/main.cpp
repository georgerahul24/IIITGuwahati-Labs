#include <iostream>

using namespace std;

class KthSmallest {
public:
    void merge(int array[], int const left, int const mid,
               int const right) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        // Create temp arrays
        auto *leftArray = new int[subArrayOne],
                *rightArray = new int[subArrayTwo];

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne
               && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne]
                <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray]
                        = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray]
                        = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

    void mergeSort(int array[], int const begin, int const end) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }

    void printArray(const int A[], int size) {
        for (int i = 0; i < size; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    int Select(const int arr[], int start, int end) {

    }

    int LinearSearch(const int arr[], int low, int high, int median) {
        for (int i = low; i <= high; i++) {
            if (arr[i] == median) return i;
        }
        return -1;
    }

    int Search_Linear(int arr[], int low, int high, int k) {
        int n = high - low + 1;
        if (k > 0 & k <= n) {
            if (n <= 5) {
                mergeSort(arr, low, high);
                return arr[k+low];
            } else {
                int numberOfGroups = n / 5 + (n % 5 != 0); //Ceil Func
                int medians[numberOfGroups];
                int startIndex = low;
                for (int i = 0; i < numberOfGroups - 1; i++) {
                    medians[i] = Median(arr, startIndex, startIndex + 4);
                    startIndex += 5;
                }
                medians[numberOfGroups - 1] = Median(arr, startIndex, high); // Last need not have 5 elements

                int medianOfMedians = Search_Linear(medians, 0, numberOfGroups-1, numberOfGroups / 2);
                int i;
                for (i = low; i < high; i++) {
                    if (arr[i] == medianOfMedians) {
                        break;
                    }
                }
                int positionOfMedianOfMedians = i;
                swap(&arr[high], &arr[positionOfMedianOfMedians]);
                positionOfMedianOfMedians = Partition(arr, low,
                                                      high); //Update position of median of median after using it as a pivot
                int rank = positionOfMedianOfMedians - low + 1;

                if (rank == k) {
                    return arr[rank];
                } else if (k < rank) {
                    return Search_Linear(arr, low, positionOfMedianOfMedians - 1, k);
                } else return Search_Linear(arr, positionOfMedianOfMedians + 1, high, k - rank);


            }
        }
    }

    void swap(int *x, int *y) {
        int temp = *y;
        *y = *x;
        *x = temp;
    }

    int Median(int arr[], int start, int end) {
        mergeSort(arr, start, end);
        int pos = start + (end - start) / 2;
        return arr[pos];
    }

    int Partition(int arr[], int low, int high) {
        int x = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= x) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return i + 1;

    }
};

int main() {
    KthSmallest k;
    int arr[] = {10, 150, 40, 230, 100, 20, 1, 3, 4, 2, 5, 8};
    for(int i = (sizeof(arr)/sizeof(int))-1; i>=0;i--){
        std::cout << k.Search_Linear(arr, 0, (sizeof(arr) / sizeof(int))-1, i) << std::endl; //I guess not working

    }
    //std::cout << k.Search_Linear(arr, 0, (sizeof(arr) / sizeof(int))-1, (sizeof(arr) / sizeof(int))-1) << std::endl; //I guess not working
     return 0;
}
