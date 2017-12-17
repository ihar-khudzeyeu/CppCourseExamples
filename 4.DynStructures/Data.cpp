#include "Data.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

Data* CreateData(char const* name, int salary)
{
    Data* result = (Data*)malloc(sizeof(Data));
    strncpy(result->Name, name, 20);
    result->Salary = salary;
    return result;
}

Data* ReadData()
{
    Data* result = (Data*)malloc(sizeof(Data));
    std::cout << "Enter name and salary" << std::endl;
    std::cin >> result->Name >> result->Salary;
    return result;
}

Data* MakeRandomData()
{
    Data* result = (Data*)malloc(sizeof(Data));
    strcpy(result->Name, "Some Guy");
    result->Salary = rand() % 100000;
    return result;
}

void PrintData(Data* data)
{
    std::cout << "Name: " << data->Name << ", Salary: " << data->Salary << std::endl;
}

int CompareByName(const Data* d1, const Data* d2)
{
    return strcmp(d1->Name, d2->Name);
}
