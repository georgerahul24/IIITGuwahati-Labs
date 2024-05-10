#include <iostream>


int countFrequency(int arr[], int start, int end, int val) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) {
            count++;
        }
    }
    return count;
}

int findHighestFrequency(int arr[], int start, int end) {
    if (start == end) return arr[start];

    int middle = start + (end - start) / 2;

    int leftHighest = findHighestFrequency(arr, start, middle); //TODO: Ask why middle-1 cannot be used
    int rightHighest = findHighestFrequency(arr, middle + 1 , end);

    if (leftHighest == rightHighest) return rightHighest; // since both the elements are the same

    int leftFreq = countFrequency(arr, start, end, leftHighest);
    int rightFreq = countFrequency(arr, start, end, rightHighest);

    if (leftFreq > ((end - start + 1) / 2)) return leftHighest; // "+1" since we need more than half

    if (rightFreq > ((end - start + 1) / 2)) return rightHighest;
    return -1;


}




int main() {




    return 0;
}
