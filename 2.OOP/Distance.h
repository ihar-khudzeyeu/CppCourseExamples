#pragma once

#include <iosfwd>

class Distance
{
private:
    int m_feet;
    double m_inches;
    
    double ToInches() const;
    
public:
    Distance();
    explicit Distance(int feet);
    Distance(int feet, double inches);
    
    int GetFeet() const;
    double GetInches() const;
    void SetData(int feet, double inches);
    void Read();
    void Print() const;

    void operator+=(Distance const& rhs);
    void operator-=(Distance const& rhs);
    
    Distance operator+(Distance const& rhs);
    Distance operator-(Distance const& rhs);
    
    bool operator==(Distance const& rhs) const;
    bool operator!=(Distance const& rhs) const;
    bool operator<=(Distance const& rhs) const;
    bool operator>(Distance const& rhs) const;
    
    Distance& operator++();
    Distance operator++(int);
    
    friend double operator/(Distance const& lhs, Distance const& rhs);
    friend double operator*(Distance const& lhs, Distance const& rhs);
    friend std::ostream& operator<<(std::ostream& stream, Distance const& d);
    friend std::istream& operator>>(std::istream& stream, Distance& d);
};

double operator/(Distance const& lhs, Distance const& rhs);
double operator*(Distance const& lhs, Distance const& rhs);
std::ostream& operator<<(std::ostream& stream, Distance const& d);
std::istream& operator>>(std::istream& stream, Distance& d);
