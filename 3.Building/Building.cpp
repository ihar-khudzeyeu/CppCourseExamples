#include "Building.h"
#include <iostream>

Citizen::Citizen(std::string const& name, int born) :
        _name(name),
        _born(born) {
}

std::string Citizen::GetDescription() const {
    std::string str = "Name: " + _name + ", born " + std::to_string(_born) + ". Lives in ";
    for (auto flat : _flats) {
        str += "flat " + std::to_string(flat) + ", ";
    }
    return str;
}

bool Citizen::operator == (Citizen const& c) {
    return _name == c._name && _born == c._born;
}

void Citizen::Assign(Flat* flat) {
    _flats.push_back(flat->GetNumber());
}


Flat::Flat(int number) :
        _number(number) {
}

int Flat::GetNumber() const {
    return _number;
}


void Flat::Assign(Citizen* c) {
    // Поиск с помощью std::find, используя итераторы
    auto itr = std::find(_citizens.begin(), _citizens.end(), c);
    if (itr == _citizens.end()) {
        c->Assign(this);
        _citizens.push_back(c);
    }

    // Простейшая рализация поиска, как мы использовали в С
    /*
    bool found = false;
    for (int i = 0; i < _citizens.size(); i++) {
        if (_citizens[i] == c) {
            found = true;
        }
    }

    if (!found) {
        _citizens.push_back(c);
    }
    */
}

void Flat::List() {
    std::cout << "Number: " << _number << std::endl;
    for (auto& citizen : _citizens) {
        std::cout << "    " << citizen->GetDescription() << std::endl;
    }
}

std::string Flat::GetDescription() const {
    return "flat " + std::to_string(_number);
}


Building::Building(int number) :
        _number(number) {
}

Building::Building(int number, std::initializer_list<Flat> const& flats) :
        _number(number),
        _flats(flats) {
}

void Building::Add(int flat_number) {
    bool found = false;
    for (int i = 0; i < _flats.size(); i++) {
        if (_flats[i].GetNumber() == flat_number) {
            found = true;
            break;
        }
    }
    if (!found) {
        _flats.push_back(Flat(flat_number));
    }
}

void Building::PutCitizen(int flat_number, Citizen* citizen) {
    for (int i = 0; i < _flats.size(); i++) {
        if (_flats[i].GetNumber() == flat_number) {
            _flats[i].Assign(citizen);
            return;
        }
    }
}

void Building::List() {
    std::cout << "Building: " << _number << std::endl;
    for (Flat& flat : _flats) {
        flat.List();
    }
}
