#pragma once

class Point
{
public:
    Point() = default;
    Point(int x, int y);

    void Set(int x, int y);

    int GetX() const;
    int GetY() const;

    void InputFromConsole();
    void PrintToConsole() const;

    void Move(int xOffset, int yOffset);

private:
    int _x = 0;
    int _y = 0;
};
