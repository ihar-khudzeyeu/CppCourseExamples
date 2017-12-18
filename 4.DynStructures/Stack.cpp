#include "Stack.h"

Stack::Stack(std::initializer_list<std::string> const& list) {
    for (auto& item : list) {
        PushBack(item);
    }
}

Stack::~Stack() {
    while (_tail) {
        StackItem* item = _tail;
        _tail = item->previous;
        delete item;
    }
}

Stack::Stack(Stack const& stack) {
    ReverseInsert(stack._tail);
}

void Stack::PushBack(std::string const& data) {
    StackItem *item = new StackItem;
    item->data = data;
    item->previous = _tail;
    _tail = item;
}

std::string Stack::PopBack() {
    if (_tail) {
        std::string data(std::move(_tail->data));

        StackItem *item = _tail;
        _tail = _tail->previous;

        delete item;
        return std::move(data);
    }
    return std::string();
}

std::size_t Stack::Count() const {
    std::size_t count = 0;
    StackItem* item = _tail;
    while (item) {
        item = item->previous;
        count++;
    }
    return count;
}

void Stack::ReverseInsert(StackItem* item) {
    if (item->previous != nullptr) {
        ReverseInsert(item->previous);
    }
    PushBack(item->data);
}
