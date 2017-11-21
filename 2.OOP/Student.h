#pragma once

#include "String.h"

class Student
{
public:
    Student() = default;
    Student(String const& name, int rating);
    Student(Student const& student) = default;
    Student(Student&& student) noexcept;
    ~Student() = default;

    String const& GetName() const;
    int GetRating() const;

    void SetName(String const& name);
    void SetRating(int rating);

    void InputFromConsole();
    void PrintToConsole() const;

    Student& operator=(Student const& student);
    Student& operator=(Student&& student) noexcept;

private:
    String _name;
    int _rating = 0;
};
