#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle(Point const& origin, int height, int width) :
        _coordinates(origin),
        _height(height),
        _width(width) {
}

Rectangle::Rectangle(int x, int y, int height, int width) :
        Rectangle(Point(x, y), height, width) {
}

Rectangle::Rectangle(int height, int width) :
        _height(height),
        _width(width) {
}

Point Rectangle::GetTopLeftPoint() const {
    return _coordinates;
}

Point Rectangle::GetBottomRightPoint() const {
    Point point = _coordinates;
    // -height because Y starts from bottom unlike our starting point
    point.Move(_width, -_height);
    return point;
}

int Rectangle::GetArea() const {
    return _height * _width;
}

int Rectangle::GetX() const {
    return _coordinates.GetX();
}

int Rectangle::GetY() const {
    return _coordinates.GetY();
}

void Rectangle::SetTopLeftPoint(int x, int y) {
    _coordinates.Set(x, y);
}

void Rectangle::SetTopLeftPoint(Point const& point) {
    _coordinates = point;
}

void Rectangle::SetSize(int height, int width) {
    _height = height;
    _width = width;
}

void Rectangle::Move(int xOffset, int yOffset) {
    _coordinates.Move(xOffset, yOffset);
}

bool Rectangle::IsEmpty() const {
    return _height * _width == 0;
}

bool Rectangle::Contains(Point& p) const {
    return _coordinates.GetX() <= p.GetX() && p.GetX() <= GetBottomRightPoint().GetX() &&
            _coordinates.GetY() >= p.GetY() && p.GetY() >= GetBottomRightPoint().GetY();
}

Rectangle Rectangle::Intersection(Rectangle const& r) const {
    Rectangle result;
    int left = _coordinates.GetX();
    if (r.GetX() > left) {
        left = r.GetX();
    }

    int right = GetBottomRightPoint().GetX();
    if (r.GetBottomRightPoint().GetX() < right) {
        right = r.GetBottomRightPoint().GetX();
    }

    int bottom = GetBottomRightPoint().GetY();
    if (r.GetBottomRightPoint().GetY() > bottom) {
        bottom = r.GetBottomRightPoint().GetY();
    }

    int top = GetY();
    if (r.GetY() < top) {
        top = r.GetY();
    }

    if (right > left && top > bottom) {
        result.SetTopLeftPoint(left, top);
        result.SetSize(top - bottom, right - left);
    }
    return result;
}

void Rectangle::InputFromConsole() {
    _coordinates.InputFromConsole();
    std::cout << "Enter size: height width" << std::endl;
    std::cin >> _height >> _width;
}

void Rectangle::PrintToConsole() const {
    std::cout << "left x:  " << _coordinates.GetX() << ", top y:    " << _coordinates.GetY() << std::endl;
    std::cout << "right x: " << GetBottomRightPoint().GetX() << ", bottom y: " << GetBottomRightPoint().GetY() << std::endl;
    std::cout << "width: " << _width << ", height: " << _height << std::endl;
}
