#include <iostream>

using namespace std;

// c[i,j] = 1 +  max(c[i+1,j] , c[i,j+1]); but, check if they are smaller than the current number

class Arr {

public:

    int n = 0;
    int m = 0;
    int **arr{};


    Arr() {
        cout << "Enter the value of n: " << endl;
        cin >> this->n;
        this->arr = new int *[n];

    }

    Arr(int n) {
        this->n = n;
        arr = new int *[n];
    }

    void fillArray(int m) {
        this->m = m;
        cout << "Enter the matrix: " << endl;

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

class FindPath {
public:
    Arr dataMatrix;

    FindPath() {
        int m;
        cout << "Enter the value of m: ";
        cin >> m;
        dataMatrix.fillArray(m);
        dataMatrix.printArr();
    }

    int calculate(int i, int j) {
        if (i == dataMatrix.n - 1 || j == dataMatrix.m - 1)
            return 0;
        else {
            int down = calculate(i + 1, j);
            int right = calculate(i, j + 1);
            if (dataMatrix[i][j] > dataMatrix[i + 1][j]) {
                down++;
            }
            if (dataMatrix[i][j] > dataMatrix[i][j + 1]) {
                right++;
            }

            return max(down, right);

        }
    }

    void createTable() {
        Arr table(this->dataMatrix.n);
        table.fillArrayWithZeros(this->dataMatrix.m);

        for (int i = dataMatrix.n - 2; i >= 0; i--) {
            for (int j = dataMatrix.m - 2; j >= 0; j--) {
                int down = table[i + 1][j];
                int right = table[i][j + 1];
                if (dataMatrix[i][j] > dataMatrix[i + 1][j]) {
                    down++;
                } else down = 0;

                if (dataMatrix[i][j] > dataMatrix[i][j + 1]) {
                    right++;
                } else right = 0;
                table[i][j] = max(down, right);
            }
        }
        table.printArr();

        int max = INT32_MIN;
        int i_max = 0, j_max = 0;

        //to find the max element
        for (int i = dataMatrix.n - 2; i >= 0; i--) {
            for (int j = dataMatrix.m - 2; j >= 0; j--) {
                if (max < table[i][j]) {
                    max = table[i][j];
                    i_max = i;
                    j_max = j;
                }
            }
        }

        //get the shortest path;

        do {
            cout << dataMatrix[i_max][j_max] << " ";
            if (table[i_max][j_max] == table[i_max][j_max + 1] + 1 &&
                table[i_max][j_max] > table[i_max][j_max + 1]) {
                j_max++;
            } else i_max++;
        } while (table[i_max][j_max] != 0);

        cout << dataMatrix[i_max][j_max] << endl;


    }


};

int main() {
    FindPath fp;

    cout << "The max length is: " << fp.calculate(0, 0) << endl;


    fp.createTable();

    return 0;
}
