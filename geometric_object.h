#pragma once
#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include <vector>
#include <iostream>

class Point {
public:
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class GeometricObject {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual bool intersects(const GeometricObject& other) const = 0;
	virtual ~GeometricObject() = default;
};

class LineSegment : public GeometricObject {
public:
	Point start, end;
	LineSegment(const Point& start, const Point& end) : start(start), end(end) {}
	double getArea() const override { return 0; } // Линия не имеет площади
	double getPerimeter() const override { return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2)); }
	bool intersects(const GeometricObject& other) const override; // Реализация пересечения
};


class Circle : public GeometricObject {
public:
	Point center;
	double radius;
	Circle(const Point& center, double radius) : center(center), radius(radius) {}
	double getArea() const override { return 3.14159 * radius * radius; }
	double getPerimeter() const override { return 2 * 3.14159 * radius; }
	bool intersects(const GeometricObject& other) const override; // Реализация пересечения
};

// ...  Другие классы (Polygon и т.д.) ...

#endif