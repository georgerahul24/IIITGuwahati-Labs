#include "Point.hpp"
#include "MergeSort.hpp"

typedef struct {
    Point p1, p2;
    float dist;
} ClosestPairDetails;


class ONLog2N {
public:
    PointArray *pa;

    ONLog2N(PointArray *pa) {
        this->pa = pa;

    }

    ClosestPairDetails *CP(int start, int end) {
        ClosestPairDetails *cpd = new ClosestPairDetails();
        int n = end - start + 1;
        if (n == 1) {
            //Error Case
            cpd->p1 = pa->points[start];
            cpd->p2 = pa->points[end];
            cpd->dist = INFINITY;

        } else if (n == 2) {
            cpd->p1 = pa->points[start];
            cpd->p2 = pa->points[end];
            cpd->dist = Point::distance(pa->points[start], pa->points[end]);

        } else {
            mergeSortOnX(pa->points, start, end);
            int middle = start + ((end - start) / 2);
            Point median = pa->points[middle];
            Point *L = new Point[middle - start];
            Point *R = new Point[middle - start];
            int LIndex = 0, RIndex = 0;
            for (int i = 0; i < n; i++) {
                if (pa->points[i].x <= median.x) {
                    L[LIndex++] = pa->points[i];
                } else {
                    R[RIndex++] = pa->points[i];
                }
            }

            ClosestPairDetails *deltaL = CP(start, middle);
            ClosestPairDetails *deltaR = CP(middle + 1, end);
            ClosestPairDetails *deltaSplit = CP_Split(start, end);


            return deltaL;


        }
        return cpd;
    }

    ClosestPairDetails *CP_Split(int start, int end) {
        int n = end - start + 1;
        mergeSortOnY(pa->points, start, end);
        


    }


};