#include <iostream>
#include "limits.h"

typedef struct {
    int start;
    int end;
    int sum;
} SubArrayDetails;


SubArrayDetails *cross(const int arr[], int start, int middle, int end) {
    SubArrayDetails *subArrayDetails = new SubArrayDetails();
    int leftMax = INT32_MIN, leftIndex = middle;
    int rightMax = INT32_MIN, rightIndex = middle+1;

    int leftSum = 0;
    while (leftIndex >= start) {
        leftSum += arr[leftIndex];
        if (leftSum > leftMax) {
            leftMax = leftSum;
            subArrayDetails->start = leftIndex;
        }
        leftIndex--;


    }

    int rightSum=0;
    while (rightIndex <= end) {
        rightSum += arr[rightIndex];
        if (rightSum > rightMax) {
            rightMax = rightSum;
            subArrayDetails->end = rightIndex;
        }
        rightIndex++;
    }

    subArrayDetails->sum = leftMax + rightMax;



    return subArrayDetails;
}

SubArrayDetails *max(SubArrayDetails *s1, SubArrayDetails *s2, SubArrayDetails *s3) {
    return (s1->sum > s2->sum) ? s1 : ((s1->sum > s3->sum) ? s1 : s3);
}

SubArrayDetails *findMaxSubArray(const int arr[], int start, int end) {
    SubArrayDetails *subArrayDetails = new SubArrayDetails();
    if (start == end) {
        subArrayDetails->start = start;
        subArrayDetails->end = end;

        subArrayDetails->sum = arr[start];
        return subArrayDetails;
    }
    int middle = (start + end) / 2;
    SubArrayDetails *left = findMaxSubArray(arr, start, middle);
    SubArrayDetails *right = findMaxSubArray(arr, middle + 1, end);
    SubArrayDetails *leftAndRight = cross(arr, start, middle, end);

    return max(left, right, leftAndRight);


}


int main() {
    int arr[] = {-1,80,-90,100,-4,-9,11,1,121,-40};
    int arr_size = sizeof(arr) / sizeof(int);
    std::cout << findMaxSubArray(arr, 0, arr_size - 1)->sum;
    return 0;
}
