#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono;

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


class KnapSack {
public:
    Arr arr{};
    int W{};
    int count = 0;

    KnapSack() {
        arr.fillArray(2);
        cout << "Enter the max weight(W):";
        cin >> this->W;
    }


    int calculateTopDown(int i, int W) {
        count++;
        if (i < 0) return 0;
        if (W < arr[i][0]) {
            return calculateTopDown(i - 1, W);

        } else {
            return max(calculateTopDown(i - 1, W), arr[i][1] + calculateTopDown(i - 1, W - arr[i][0]));
        }
    }

    void calculateTopDownMultiThreaded(int i, int W, promise<int> &&p) {
        if (i < 0) {
            p.set_value(0);
            return;
        }
        if (W < arr[i][0]) {

            std::promise<int> p1;
            auto f = p1.get_future();
            std::thread t(&KnapSack::calculateTopDownMultiThreaded, this, i - 1, W, std::move(p1));
            t.join();
            int i1 = f.get();
            p.set_value(i1);
            return;

        } else {

            std::promise<int> p1;
            auto f1 = p1.get_future();
            std::thread t1(&KnapSack::calculateTopDownMultiThreaded, this, i - 1, W, std::move(p1));


            std::promise<int> p2;
            auto f2 = p2.get_future();
            std::thread t2(&KnapSack::calculateTopDownMultiThreaded, this, i - 1, W - arr[i][0], std::move(p2));

            t1.join();
            t2.join();

            int i1 = f1.get();
            int i2 = f2.get();

            p.set_value(max(i1, arr[i][1] + i2));
            return;
        }
    }

    int calculateBottomUp() {
        Arr table(arr.n);
        table.fillArrayWithZeros(arr.n);
        table.printArr(arr.n);

    }


};


int main() {
    KnapSack k;
    auto start = high_resolution_clock::now();
    cout << endl << "The max that can be added is " << k.calculateTopDown(k.arr.n - 1, k.W) << endl;
    auto stop = high_resolution_clock::now();
    cout << "The number of function calls is " << k.count << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    cout << endl << endl << endl;


    std::promise<int> p;
    auto f = p.get_future();
        start = high_resolution_clock::now();

    k.calculateTopDownMultiThreaded(k.arr.n - 1, k.W, std::move(p));

    cout << "The max that can be added is " << f.get() << endl;
    stop = high_resolution_clock::now();
    cout << "The number of function calls is " << k.count << endl;
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    return 0;
}
