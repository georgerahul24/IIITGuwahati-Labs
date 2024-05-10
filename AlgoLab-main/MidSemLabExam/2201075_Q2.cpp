#include <iostream>

using namespace std;

class Arr {

public:

    int n = 0;
    int m = 0;
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
        this->m = m;
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
        this->m = m;
        for (int i = 0; i < n; i++) {
            int *_arr = new int[m];
            this->arr[i] = _arr;
        }

    }


    void printArr(int m) {
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printArr() {
        cout << endl;
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

class LCS {
public:
    int *X;
    int *Y;
    int n;


    LCS(int arr[], int n) {

        this->n = n;
        this->X = arr;
        this->Y = arr;


    }

    int getLCS(int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (X[i] - Y[j]) return 1 + getLCS(i - 1, j - 1);
        else {
            return max(getLCS(i - 1, j), getLCS(i, j - 1));
        }

    }


    void getLCSTable(int d) {
        int arr[n];

        for (int i = 0; i < n; i++) arr[i] = 0;
        int i = 1;
        arr[0] = 0;
        while (i < n) {
            int j = i;
            while (j>= 0 && X[i] - X[j] <= d) {
                j--;
            }
            if (i == j) arr[i] = arr[j - 1];
            else {
                arr[i] = 1 + arr[j];
            }
            i++;


        }

        int m = arr[0],in=0;
        for (int i = 0; i < n; i++) {
            cout << arr[i] <<" ";
            if (m < arr[i]) {
                m = arr[i];
                in=i;
            }
        }

        cout <<"Length is: " <<arr[in]+1;
    }

    void getLCSTable1(int d) {
        Arr arr(n);
        arr.fillArrayWithZeros(n);


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Y[j + 1] - X[j] >= -d) {
                    arr[i][j + 1] = arr[i][j] + 1;
                } else {
                    arr[i][j + 1] = arr[i][j];
                }
            }
        }
        arr.printArr(n + 1);

        int jmax = -1, jIndex = 0;
        for (int j = 0; j < n; j++) {
            if (arr[n - 1][j] > jmax) {
                jmax = arr[n - 1][j];
                jIndex = j;
            }
        }

        int prev_element = arr[jIndex][n - 1];
        int i = n - 1;
        while (i-- >= 0) {
            if (arr[jIndex][i] != prev_element) {
                cout << X[i] << " ";
                prev_element = arr[jIndex][i];
            }

        }
    }


    void printString() {
        cout << "X: " << X << endl;
        cout << "Y: " << Y << endl;
    }


};


int main() {
    int arr[] = {9,7,5,3,1};
    LCS lcs(arr, sizeof(arr) / sizeof(int));
//    cout << "Enter the value of d: ";
//    int d;
//    cin >> d;
    lcs.getLCSTable(2);

    return 0;
}