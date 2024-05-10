#include "iostream"
#include "Point.hpp"
class ONSquare {
public:
    explicit ONSquare(PointArray *p) {
        int n = p->size;
        float dist = 0;
        float min_dist = INT_MAX;

        Point p1, p2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dist = Point::distance(p->points[i], p->points[j]);
                if (dist < min_dist) {
                    p1 = p->points[i];
                    p2 = p->points[j];
                    min_dist = dist;

                }
            }

        }

        cout << "The Closest Dist is " << min_dist << "\n The points are: \n";
        p1.print();
        p2.print();

    }
};