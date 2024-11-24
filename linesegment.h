#pragma once
#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "geometric_object.h"
#include "Point.h"
#include <limits>
#include <iostream> //added for printing


class LineSegment {
public:
    Point start, end;

    LineSegment(const Point& start, const Point& end) : start(start), end(end) {}

    double getLength() const {
        return start.distanceTo(end);
    }

    // Simple intersection check (not robust for all cases)
    bool intersects(const LineSegment& other) const {
        double det = (end.x - start.x) * (other.end.y - other.start.y) -
            (end.y - start.y) * (other.end.x - other.start.x);
        if (std::abs(det) < std::numeric_limits<double>::epsilon()) return false; // Parallel lines

        double t = ((other.start.x - start.x) * (other.end.y - other.start.y) -
            (other.start.y - start.y) * (other.end.x - other.start.x)) /
            det;
        double u = -((start.x - other.start.x) * (end.y - start.y) -
            (start.y - other.start.y) * (end.x - start.x)) /
            det;

        return (t > 0 && t < 1) && (u > 0 && u < 1);
    }

    friend std::ostream& operator<<(std::ostream& os, const LineSegment& ls) {
        os << "[" << ls.start << ", " << ls.end << "]";
        return os;
    }
};

#endif
