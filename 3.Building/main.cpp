#include "Building.h"

int main() {
    Citizen c("Bob", 1970);
    Citizen c2("Frank", 1990);

    Building b(54);

    b.Add(5);
    b.Add(5);
    b.PutCitizen(5, &c);
    b.PutCitizen(5, &c2);
    b.Add(6);
    b.PutCitizen(6, &c);
    b.PutCitizen(5, &c);

    b.List();

    return 0;
}
