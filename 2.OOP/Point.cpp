#include "Rectangle.h"

#include <iostream>

Point::Point(int x, int y) :
        _x(x),
        _y(y) {
}

void Point::Set(int x, int y) {
    _x = x;
    _y = y;
}

int Point::GetX() const {
    return _x;
}

int Point::GetY() const {
    return _y;
}

void Point::InputFromConsole() {
    std::cout << "Enter point coordinates: x y" << std::endl;
    std::cin >> _x >> _y;
}

void Point::PrintToConsole() const {
    std::cout << "Point: " << _x << ", " << _y << std::endl;
}

void Point::Move(int xOffset, int yOffset) {
    _x += xOffset;
    _y += yOffset;
}
