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
    string X;
    string Y;
    int n;


    LCS() {
        cout << "Enter X: ";
        cin >> X;

        cout << "Enter Y: ";
        cin >> Y;

        this->n = max(X.length(), Y.length());


    }

    int getLCS(int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (X[i] == Y[j]) return 1 + getLCS(i - 1, j - 1);
        else {
            return max(getLCS(i - 1, j), getLCS(i, j - 1));
        }

    }


    void getLCSTable() {
        Arr arr(X.length() + 1);
        arr.fillArrayWithZeros(Y.length() + 1);


        for (int i = 0; i < X.length(); i++) {
            for (int j = 0; j < Y.length(); j++) {
                if (X[i] == Y[j])
                    arr[i + 1][j + 1] = arr[i][j] + 1;
                else {
                    arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
                }
            }
        }
        arr.printArr(Y.length() + 1);
    }


    void printString() {
        cout << "X: " << X << endl;
        cout << "Y: " << Y << endl;
    }


};


int main() {
    LCS lcs;
    lcs.printString();
    cout << "The length of the max substring is: " << lcs.getLCS(lcs.X.length() - 1, lcs.Y.length() - 1);
    lcs.getLCSTable();
    return 0;
}
