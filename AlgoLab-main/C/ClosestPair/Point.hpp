#include "iostream"

#pragma once
using namespace std;


class Point {
public:
    float x, y;

    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Point() {
        x = 0;
        y = 0;
    }

    Point operator+(Point const &p) const {
        Point newPoint;
        newPoint.x = this->x + p.x;
        newPoint.y = this->y + p.y;
        return newPoint;
    }

    Point operator-(Point const &p) const {
        Point newPoint;
        newPoint.x = this->x - p.x;
        newPoint.y = this->y - p.y;
        return newPoint;
    }

    Point operator*(Point const &p) {
        Point newPoint;
        newPoint.x = this->x * p.x;
        newPoint.y = this->y * p.y;
        return newPoint;
    }

    Point operator^(float p) const {
        Point newPoint;
        newPoint.x = pow(this->x, p);
        newPoint.y = pow(this->y, p);
        return newPoint;
    }

    void operator=(const Point &p) {
        x = p.x;
        y = p.y;
    }


    void print() const {
        std::cout << "X: " << this->x << " Y: " << this->y << "\n";
    }

    float static distance(Point &p1, Point &p2) {
        Point p;
        p = (p1 - p2) ^ 2;


        return sqrt(p.x + p.y);
    }

};


class PointArray {
public:
    Point *points;
    int size;

    void getPoints() {
        cout << "Enter the number of points: ";

        cin >> size;

        points = new Point[size];
        cout << "Enter the points: " << endl;
        for (int i = 0; i < size; i++) {
            float x, y;
            scanf("%f,%f", &x, &y);

            points[i] = Point(x, y);

        }

    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "(" << points[i].x << " , " << points[i].y << "), ";

        }
        cout << endl;

    };


};