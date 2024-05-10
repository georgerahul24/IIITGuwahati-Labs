#include <iostream>

using namespace std;
typedef struct interval {
    int start;
    int end;
    int weight;
} interval;


class WeightedIntervalScheduling {

public:
    interval *intervals = nullptr;
    int numberOfIntervals = 0;

    WeightedIntervalScheduling() {
        cout << "Enter the number of intervals: ";
        cin >> numberOfIntervals;
        intervals = new interval[numberOfIntervals];

        cout << "Enter the intervals: \n";

        for (int i = 0; i < numberOfIntervals; i++) {
            auto in = new interval;
            cin >> in->start >> in->end >> in->weight;
            intervals[i] = *in;
        }

    }

    interval *nextEvent(int i, interval current) {
        while (i++ < numberOfIntervals) {
            if (current.end < intervals[i].start) {
                return &intervals[i];
            }
        }
        return nullptr;
    }

    int calculate(int i) {
        //find the i-1 th element
        return 0;

    }

    void bubbleSort() {
        for (int i = 0; i < numberOfIntervals; i++) {
            for (int j = 0; j < numberOfIntervals - 1; j++) {
                if (intervals[j].end > intervals[j + 1].end) {
                    interval temp;
                    temp = intervals[j];
                    intervals[j] = intervals[j + 1];
                    intervals[j + 1] = temp;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < numberOfIntervals; i++) {
            cout << intervals[i].start << " " << intervals[i].end << " " << intervals[i].weight << endl;
        }
    }

};


int main() {
    WeightedIntervalScheduling w;
    w.bubbleSort();
    w.print();
    return 0;
}
