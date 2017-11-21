#include "Student.h"

#include <cstring>
#include <iostream>


Student::Student(String const& name, int rating) :
        _name(name),
        _rating(rating) {
}

Student::Student(Student&& student) noexcept :
        _name(std::move(student._name)),
        _rating(student._rating) {
}

String const& Student::GetName() const {
    return _name;
}

int Student::GetRating() const {
    return _rating;
}

void Student::SetName(String const& name) {
    _name = name;
}

void Student::SetRating(int rating) {
    _rating = rating;
}

void Student::InputFromConsole() {
    // Ensure that we have no garbage in stream buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter name: ";
    char buffer[51];
    std::cin.getline(buffer, 50);
    _name = buffer;
    std::cout << "Enter rating: ";
    std::cin >> _rating;
}

void Student::PrintToConsole() const {
    std::cout << _name << ": " << _rating << std::endl;
}

Student& Student::operator=(Student const& student) {
    if (this != &student) {
        _rating = student._rating;
        _name = student._name;
    }
    return *this;
}

Student& Student::operator=(Student&& student) noexcept {
    if (this != &student) {
        _name = std::move(student._name);
        _rating = student._rating;
    }
    return *this;
}
