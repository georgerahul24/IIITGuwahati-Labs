#include <iostream>


typedef struct {
    int max;
    int min;
} Max_Min;

class Q1 {

public:
    int *arr;
    int arr_length;

    Q1(int *arr, int arr_length) {
        this->arr = arr;
        this->arr_length = arr_length;
    };


    int find_max(int start, int end) {
        if (start == end) return arr[start];
        else {
            int middle = start + (end - start) / 2;

            int max1 = find_max(start, middle);
            int max2 = find_max(middle + 1, end);

            return max(max1, max2);


        }
    }

    Max_Min *findMaxMin(int start, int end) {


        if (start == end) {
            return new Max_Min{.max=arr[start], .min=arr[start]};
        } else {
            int middle = start + (end - start) / 2;

            Max_Min *max1 = findMaxMin(start, middle);
            Max_Min *max2 = findMaxMin(middle + 1, end);

            return new Max_Min{.max=max(max1->max, max2->max), .min=min(max1->min, max2->min)};
        }


    }


    Max_Min *findMaxAndSecondMax(int start, int end) {


        if (start == end) {
            return new Max_Min{.max=arr[start], .min=arr[start]};
        } else {
            int middle = start + (end - start) / 2;

            Max_Min *max1 = findMaxMin(start, middle);
            Max_Min *max2 = findMaxMin(middle + 1, end);

            return new Max_Min{.max=max(max1->max, max2->max), .min=min(max1->max, max2->max)};//TODO: errorm in 2nd max
        }


    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }


};
