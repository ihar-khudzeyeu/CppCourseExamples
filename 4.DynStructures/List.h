#pragma once

#include <cstddef>
#include <string>
#include <initializer_list>

class List {
    struct ListItem {
        std::string data;
        ListItem* next = nullptr;
        ListItem* previous = nullptr;
    };
public:
    List() = default;
    List(std::initializer_list<std::string> const& list);
    ~List();
    List(List const& list);
    void PushBack(std::string const& data);
    void PushFront(std::string const& data);
    std::string PopBack();
    std::string PopFront();

    std::size_t Count() const;

private:

    ListItem* _head = nullptr;
    ListItem* _tail = nullptr;
};
