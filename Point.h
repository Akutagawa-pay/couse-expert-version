﻿#include <cmath>
#include <iostream>

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {} // Конструктор

    double distanceTo(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    // Пример перегрузки оператора
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};