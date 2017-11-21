#include "String.h"

#include <cstring>
#include <iostream>

String::String(char const* str) {
    if (str) {
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
}

String::String(String const& string) {
    _str = new char[string.size() + 1];
    strcpy(_str, string._str ? string._str : "");
}

String::String(String&& rhs) noexcept {
    _str = rhs._str;
    rhs._str = nullptr;
}

String& String::operator=(String const& rhs) {
    if (this != &rhs) {
        delete[] _str;
        if (rhs._str != nullptr) {
            _str = new char[rhs.size() + 1];
            strcpy(_str, rhs._str);
        }
        else {
            _str = nullptr;
        }
    }
    return *this;
}

String& String::operator=(String&& rhs) noexcept {
    if (this != &rhs) {
        delete[] _str;
        _str = rhs._str;
        rhs._str = nullptr;
    }
    return *this;
}

size_t String::size() const {
    return _str != nullptr ? strlen(_str) : 0;
}

bool String::empty() const {
    return _str == nullptr || strlen(_str) == 0;
}

char const* String::c_str() const {
    return _str;
}

String::operator char*() {
    return _str;
}

String::operator bool() const {
    return empty();
}

String String::operator+(String const& rhs) {
    size_t length1 = size();
    size_t length2 = rhs.size();
    size_t newLength = length1 + length2;
    String result;
    result._str = new char[newLength + 1];
    if (length1) {
        memcpy(result._str, _str, length1);
    }
    if (length2) {
        memcpy(result._str + length1, rhs._str, length2);
    }
    result._str[newLength] = '\0';
    return result;
}

bool String::operator==(String const& rhs) const {
    return strcmp(_str ? _str : "", rhs._str ? rhs._str : "") == 0;
}

bool String::operator!=(String const& rhs) const {
    return !(*this == rhs);
}

bool String::operator<(String const& rhs) const {
    return strcmp(_str ? _str : "", rhs._str ? rhs._str : "") < 0;
}

bool String::operator>(String const& rhs) const {
    return strcmp(_str ? _str : "", rhs._str ? rhs._str : "") > 0;
}

char& String::operator[](int idx) {
    if (idx < 0 || idx >= size()) {
        std::cout << "String: invalid index\n";
        exit(-1);
    }
    return _str[idx];
}

char String::operator[](int idx) const {
    return (*this)[idx];
}

std::ostream& operator<<(std::ostream& stream, String const& string) {
    stream << (string.empty() ? "" : string.c_str());
    return stream;
}

std::istream& operator>>(std::istream& stream, String& string) {
    char buffer[1024];
    stream >> buffer;
    String tmp(buffer);
    delete[] string._str;
    string._str = tmp._str;
    tmp._str = nullptr;
    return stream;
}
