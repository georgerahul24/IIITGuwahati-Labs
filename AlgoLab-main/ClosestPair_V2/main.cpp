#include <iostream>
#include "Point.hpp"
#include "MergeSort.hpp"

class CP {
public:


    Point *pointArray = nullptr;
    Point *xSorted = nullptr;
    Point *ySorted = nullptr;
    int size;

    CP() {
        cout << "Enter the number of points: ";

        cin >> size;

        pointArray = new Point[size];
        cout << "Enter the points: " << endl;
        for (int i = 0; i < size; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            pointArray[i] = Point(x, y);

        }

        mergeSortOnX(pointArray, 0, size - 1);
        xSorted = new Point[size];
        for (int i = 0; i < size; i++) {
            xSorted[i] = pointArray[i];
        }
        mergeSortOnY(pointArray, 0, size - 1);

        ySorted = new Point[size];
        for (int i = 0; i < size; i++) {
            ySorted[i] = pointArray[i];
        }
        printPointArray(xSorted, size);
        printPointArray(ySorted, size);


    }

    float ClosestPairSplit(Point px[], Point py[], Point midpoint, float d, int n) {
        Point S[n];
        int iS = 0;
        for (int i = 0; i < n; i++) {
            if (-d < py[i].x - midpoint.x < d) {
                S[iS++] = py[i];
            }
        }

        float dSplit = INT32_MAX;

        for (int i = 0; i < iS; i++) {
            Point p = S[i];
            for (int j = i + 1; j < min(iS, i + 7); j++) {
                Point q = S[j];
                float _d = Point::distance(p, q);
                if (_d < dSplit) {
                    dSplit = _d;
                }
            }
        }
        return dSplit;

    }

    float closestPair(Point px[], Point py[], int n) {
        if (n == 1) return INT32_MAX;
        if (n == 2) return Point::distance(px[0], px[1]);
        else {
            int mid = n / 2;
            Point midpoint = px[mid];

            Point lx[n / 2], ly[n / 2], rx[n / 2], ry[n / 2];
            int ilx = 0, ily = 0, irx = 0, iry = 0;

            for (int i = 0; i < n; i++) {
                if (px[i].x <= midpoint.x) {
                    lx[ilx++] = px[i];
                } else {
                    rx[irx++] = px[i];
                }
            }


            for (int i = 0; i < n; i++) {
                if (py[i].x <= midpoint.x) {
                    ly[ily++] = py[i];
                } else {
                    ry[iry++] = py[i];
                }
            }

            float d1 = closestPair(lx, ly, n / 2);
            float d2 = closestPair(rx, ry, n / 2);
            float d = min(d1, d2);
            float dSplit = ClosestPairSplit(px, py, midpoint, d, n);

            float dMin = min(d, dSplit);
            return dMin;

        }


    }


    void printPointArray(Point *array, int n) {
        for (int i = 0; i < n; i++) {
            cout << "(" << array[i].x << " , " << array[i].y << ") ";
        }
        cout << endl;
    }


};


int main() {
    CP cp;

    cout << cp.closestPair(cp.xSorted,cp.ySorted,cp.size);

    return 0;
}
