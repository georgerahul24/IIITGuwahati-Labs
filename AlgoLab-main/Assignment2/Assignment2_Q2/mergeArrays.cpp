#include <cstdlib>
#include "limits.h"

int sumOfArrays(int *arrSizes, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arrSizes[i];
    }
    return sum;
}

int findMin(int **array, int *arrayIndexes) {

}


int *mergeNArrays(int n, int **arrays, int *arrSizes) {
    const int finalArraySize = sumOfArrays(arrSizes, n);
    int *finalArray = new int(finalArraySize);
    int finalArrayIndex = 0;
    int *arrayIndexes = new int(finalArraySize);


}