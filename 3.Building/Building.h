#pragma once
#include <string>
#include <vector>

class Flat;
class Building;

class Citizen {
public:
    Citizen(std::string const& name, int born);
    bool operator == (Citizen const& c);
    std::string GetDescription() const;
    void Assign(Flat* flat);

private:
    std::string _name;
    int _born;
    std::vector<int> _flats;
};

class Building {
public:
    Building(int number);
    Building(int number, std::initializer_list<Flat> const& flats);

    void Add(int flat_number);
    void PutCitizen(int flat_number, Citizen* citizen);
    void List();

private:
    int _number;
    std::vector<Flat> _flats;
};

class Flat {
public:
    Flat(int number);

    void Assign(Citizen* c);
    void List();
    int GetNumber() const;
    std::string GetDescription() const;

private:
    int _number;
    std::vector<Citizen*> _citizens;
};
