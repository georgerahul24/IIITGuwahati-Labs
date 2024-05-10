#include <iostream>
#include "MergeSort.hpp"
#include "ONLogN.hpp"

using namespace std;

int main() {
    PointArray *pa = new PointArray();
    pa->getPoints();
    pa->print();


    ONLogN o(pa);
    o.CP(0, pa->size - 1);


    return 0;
};
