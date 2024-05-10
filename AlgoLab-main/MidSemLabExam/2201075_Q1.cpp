#include "iostream"

using namespace std;

class Arr {

public:

    int n = 0;
    int **arr{};


    Arr() {
        cout << "Enter the number of items(n): " << endl;
        cin >> this->n;
        this->arr = new int *[n];

    }

    Arr(int n) {
        this->n = n;
        arr = new int *[n];
    }

    void fillArray(int m) {
        cout << "Enter the Wt and Value: " << endl;

        for (int i = 0; i < n; i++) {
            int *_arr = new int[m];
            for (int j = 0; j < m; j++) {
                cin >> _arr[j];
            }
            this->arr[i] = _arr;
        }

    }

    void fillArrayWithZeros(int m) {
        for (int i = 0; i < n; i++) {
            int *_arr = new int[m];
            this->arr[i] = _arr;
        }

    }


    void printArr(int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int *&operator[](int index) const {

        return arr[index];
    }


};


class Q1 {
public:
    Arr arr;
    int x = -1, y = -1;

    Q1(Arr arr) {
        this->arr = arr;
    }

    bool findIndex(int lowR, int highR, int lowC, int highC, int target) {
        int medianOfMedian = (arr)[lowR + (highR - lowR) / 2][lowC + (highC - lowC) / 2];

        if (lowC == highC || lowR == highR) {
            if (lowR == highR) {
                for (int i = lowR; i <= highR; i++) {
                    if (target == arr[lowR][i]) {
                        x = lowR;
                        y = i;
                        break;
                    }
                }
            } else if (lowR == highR) {
                for (int i = lowC; i <= highC; i++) {
                    if (target == arr[i][highC]) {
                        x = lowC;
                        y = lowR;
                        break;
                    }
                }
            }

            return x != -1;
        }

        if(highR-lowR == 1 && highC-lowC == 1){
            if(arr[lowR][lowC]==target){
                x=lowR;y=lowC;
            }
            if(arr[lowR][highC]==target){
                x=lowR;y=highC;
            }
            if(arr[highR][lowC]==target){
                x=highR;y=lowC;
            }
            if(arr[highR][highC]==target){
                x=highR;y=highC;
            }

            return x!=-1;
        }



        if (medianOfMedian == target) {
            x = lowR + (highR - lowR) / 2;
            y = lowC + (highC - lowC) / 2;
            return true;
        } else {
            if (medianOfMedian > target) {
                findIndex(lowR, lowR + (highR - lowR) / 2, lowC, lowC + (highC - lowC) / 2, target);
            } else {


                return findIndex(lowR + (highR - lowR) / 2, highR, lowC, lowC + (highC - lowC) / 2, target) ||
                       findIndex(lowR + (highR - lowR) / 2, highR, lowC + (highC - lowC) / 2, highC, target) ||
                       findIndex(lowR, lowR + (highR - lowR) / 2, lowC + (highC - lowC) / 2, highC, target);


            }

        }

        return false;

    }


};




int main1() {
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    Arr arr(n);
    arr.fillArray(n);
    Q1 q1(arr);
//    cout << "Enter the variable to get the index: ";
//    int target;
//    cin >> target;
    q1.findIndex(0, n - 1, 0, n - 1, 18);

    cout << q1.x << " " << q1.y;

}