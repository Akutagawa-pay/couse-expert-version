#pragma once
#include "point.h"
#include "linesegment.h"
#include "circle.h"
#include "polygon.h" // Assuming you have a Polygon class
#include <vector>
#include <iostream>
#include <algorithm> // for std::remove_if


// Упрощенные операции над множествами (более сложная версия)


template <typename T>
std::vector<T> setUnion(const std::vector<T>& set1, const std::vector<T>& set2) {
    std::vector<T> result = set1;
    result.insert(result.end(), set2.begin(), set2.end());
    //This is a simplification, a proper union would require checking for duplicates and merging overlapping shapes.
    return result;
}


template <typename T>
std::vector<T> setIntersection(const std::vector<T>& set1, const std::vector<T>& set2) {
    std::vector<T> result;
    for (const auto& item1 : set1) {
        for (const auto& item2 : set2) {
            if (item1.intersects(item2)) { //Requires implementing intersects() for all shapes
                result.push_back(item1); //Simplified:  We add one intersecting shape. A true intersection might need a more complex result.
                break; //Avoid duplicates (simplified)
            }
        }
    }
    return result;
}
