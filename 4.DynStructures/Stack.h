#pragma once

#include <cstddef>
#include <string>
#include <initializer_list>

class Stack {
    struct StackItem {
        std::string data;
        StackItem* previous = nullptr;
    };
public:
    Stack() = default;
    Stack(std::initializer_list<std::string> const& list);
    ~Stack();
    Stack(Stack const& stack);
    void PushBack(std::string const& data);
    std::string PopBack();

    std::size_t Count() const;

private:
    void ReverseInsert(StackItem* item);

    StackItem* _tail = nullptr;
};
