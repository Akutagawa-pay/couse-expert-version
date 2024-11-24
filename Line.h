#ifndef LINE_H
#define LINE_H

#include "snape.h"
#include <cmath>

class Line : public Shape {
public:
    Line(double x1, double y1, double x2, double y2)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
    }

    double area() const override {
        return 0.0;  // Отрезок не имеет площади
    }

    double perimeter() const override {
        return length();
    }

    bool intersects(const Shape& other) const override {
        // Для простоты: проверка пересечения с другим отрезком или примитивом
        return false;
    }

    void draw() const override {
        std::cout << "Drawing line from (" << x1_ << ", " << y1_ << ") to (" << x2_ << ", " << y2_ << ")\n";
    }

private:
    double length() const {
        return std::sqrt(std::pow(x2_ - x1_, 2) + std::pow(y2_ - y1_, 2));
    }

    double x1_, y1_, x2_, y2_;
};

#endif // LINE_H
