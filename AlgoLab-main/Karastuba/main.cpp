#include <iostream>

using namespace std;

int numberOfDigits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int multiply(int num1, int num2, int n) {

    if(n==1) return num1*num2;


    int x1, x2, y1, y2;
    int base = pow(10, n / 2);

    x1 = num1 / base;
    x2 = num1 % base;
    y1 = num2 / base;
    y2 = num2 % base;

    cout << "x1: " << x1 << " x2: " << x2 << " y1: " << y1 << " y2: " << y2 << endl;
    int x1y1 = multiply(x1, y1, n / 2);
    int x2y2 = multiply(x2, y2, n / 2);
    int x1y2 = multiply(x1 + x2, y1 + y2, n / 2) - x1y1 - x2y2;

    return x1y1 * base * base + x2y2 * base + x1y2;


}


int main() {
    int num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;

    cout << numberOfDigits(num1) << " " << numberOfDigits(num2) << endl;
    cout << "The ans is: \n"<<multiply(num1, num2, numberOfDigits(num2));


    return 0;
}
