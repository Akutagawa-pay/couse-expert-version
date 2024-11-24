#pragma once
#ifndef POLYGON_H
#define POLYGON_H
#include "geometric_object.h"
#include "Point.h"
#include <vector>
#include <stdexcept>
#include <numeric>
#include <cmath>


class Polygon {
public:
    std::vector<Point> vertices;

    Polygon(const std::vector<Point>& vertices) : vertices(vertices) {
        if (vertices.size() < 3) {
            throw std::invalid_argument("Polygon must have at least 3 vertices");
        }
    }

    double getArea() const {
        double area = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            area += (vertices[i].x * vertices[(i + 1) % n].y -
                vertices[(i + 1) % n].x * vertices[i].y);
        }
        return std::abs(area) / 2.0;
    }

    double getPerimeter() const {
        double perimeter = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            perimeter += vertices[i].distanceTo(vertices[(i + 1) % n]);
        }
        return perimeter;
    }

    // Простая проверка на пересечение с отрезком (неполная и неэффективная!)
    bool intersects(const LineSegment& segment) const {
        for (size_t i = 0; i < vertices.size(); ++i) {
            LineSegment edge(vertices[i], vertices[(i + 1) % vertices.size()]);
            if (edge.intersects(segment)) return true;
        }
        return false;
    }

};

#endif