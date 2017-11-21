#pragma once

#include "Point.h"

class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(Point const& origin, int height, int width);
    Rectangle(int x, int y, int height, int width);
    Rectangle(int width, int height);

    Point GetTopLeftPoint() const;
    Point GetBottomRightPoint() const;
    int GetArea() const;
    int GetX() const;
    int GetY() const;

    void SetTopLeftPoint(int x, int y);
    void SetTopLeftPoint(Point const& point);
    void SetSize(int height, int width);
    void Move(int xOffset, int yOffset);

    bool IsEmpty() const;
    bool Contains(Point& p) const;

    Rectangle Intersection(Rectangle const& r) const;

    void InputFromConsole();
    void PrintToConsole() const;

private:

    Point _coordinates;
    int _height = 0;
    int _width = 0;
};
