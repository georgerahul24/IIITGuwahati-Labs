#include <iostream>

using namespace std;

class Fibonacci {
public:
    int n;
    int *DPArray = nullptr;
    int topDownDPCount = 0;
    int bruteForceCount = 0;

    Fibonacci(int n) {
        this->n = n;
        DPArray = new int[n + 1];
    }

    int bruteForce(int n) {
        bruteForceCount++;
        if (n == 0) return 0;
        if (n == 1) return 1;
        return bruteForce(n - 1) + bruteForce(n - 2);
    }

    int topDownDp(int n) {
        topDownDPCount++;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int n1, n2;
        if (DPArray[n - 1] == 0) {
            n1 = topDownDp(n - 1);
            DPArray[n - 1] = n1;
        } else n1 = DPArray[n - 1];
        if (DPArray[n - 2] == 0) {
            n2 = topDownDp(n - 2);
            DPArray[n - 2] = n2;
        } else n2 = DPArray[n - 2];
        return DPArray[n] = n1 + n2;

    }


};


int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Fibonacci fibonacci{n};
    cout << "Brute Force: " << fibonacci.bruteForce(n) << " Function Count: " << fibonacci.bruteForceCount << endl;
    cout << "Top Down DP: " << fibonacci.topDownDp(n) << " Function Count: " << fibonacci.topDownDPCount << endl;


    return 0;
}
