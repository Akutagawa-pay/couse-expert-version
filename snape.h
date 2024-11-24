#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;

    // Чисто виртуальные методы для вычислений, таких как площадь, периметр и т.д.
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Проверка на пересечение с другим объектом
    virtual bool intersects(const Shape& other) const = 0;

    virtual void draw() const = 0;  // Функция для "отрисовки" примитива (например, на экране)
};

#endif // SHAPE_H
