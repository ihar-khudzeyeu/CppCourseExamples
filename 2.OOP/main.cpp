#include "Point.h"
#include "Rectangle.h"
#include "Distance.h"
#include "String.h"
#include "Student.h"

#include <iostream>

int main() {
    Point p(2, 3);
    p.PrintToConsole();

    Rectangle rect(2, 3, 5, 4);
    std::cout << "-------\n";
    rect.PrintToConsole();
    std::cout << "-------\n";
    rect.Move(2, 2);
    rect.PrintToConsole();
    std::cout << "-------\n";

    Rectangle rect2(2, 3, 4, 3);
    rect2.PrintToConsole();
    std::cout << "-------\n";

    Rectangle rect3 = rect.Intersection(rect2);
    rect3.PrintToConsole();
    std::cout << "Area is " << rect.GetArea() << std::endl;
    std::cout << "-------\n";

    String str("Hello");
    std::cout << str << std::endl;
    str[2] = 'w';
    std::cout << str << std::endl;

    Student st("Bob", 5);
    st.PrintToConsole();

    return 0;
}
