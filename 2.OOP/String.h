#pragma once

#include <iosfwd>

class String
{
public:
    String() = default;
    String(char const* str);
    String(String const& string);
    String(String&& string) noexcept;

    String& operator=(String const& rhs);
    String& operator=(String&& rhs) noexcept;

    size_t size() const;
    char const* c_str() const;
    bool empty() const;

    explicit operator char*();
    explicit operator bool() const;

    String operator+(String const& rhs);
    bool operator==(String const& rhs) const;
    bool operator!=(String const& rhs) const;
    bool operator<(String const& rhs) const;
    bool operator>(String const& rhs) const;

    char& operator[](int idx);
    char operator[](int idx) const;

    friend std::ostream& operator<<(std::ostream& stream, String const& string);
    friend std::istream& operator>>(std::istream& stream, String& string);

private:
    char* _str = nullptr;
};
