#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono;

bool count(int m) {
    bool a;
    while (int i = m--) {
        while (int j = i--) {
            while (j--) {
                a != a;
            }
        }
    }
    return a;

}


int main() {
    auto start = high_resolution_clock::now();


    std::thread t(count, 3000);
    t.join();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;


    start = high_resolution_clock::now();
    std::thread t1(count, 750);
    std::thread t2(count, 750);
    std::thread t3(count, 750);
    std::thread t4(count, 750);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;


    return 0;
}
