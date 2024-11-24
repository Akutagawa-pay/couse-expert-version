#pragma once

#define CIRCLE_H

#include "geometric_object.h"
#include <cmath>
#include <iostream>
#include"linesegment.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "Point.h"
#include <stdexcept>
class Circle {
public:
    Point center;
    double radius;

    Circle(const Point& center, double radius) : center(center), radius(radius) {
        if (radius < 0) {
            throw std::invalid_argument("Radius cannot be negative");
        }
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * M_PI * radius;
    }

    bool intersects(const Circle& other) const {
        return center.distanceTo(other.center) < radius + other.radius;
    }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) {
        os << "Circle{center: " << c.center << ", radius: " << c.radius << "}";
        return os;
    }
};


