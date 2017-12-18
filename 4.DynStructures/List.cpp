#include "List.h"

List::List(std::initializer_list<std::string> const& list) {
    for (auto& item : list) {
        PushBack(item);
    }
}

List::~List() {
    while (_head) {
        ListItem* item = _head;
        _head = item->next;
        delete item;
    }
}

List::List(List const& list) {
    ListItem* item = list._head;
    while (item) {
        PushBack(item->data);
        item = item->next;
    }
}

void List::PushBack(std::string const& data) {
    ListItem *item = new ListItem;
    item->data = data;
    item->next = nullptr;
    item->previous = _tail;
    if (_tail) {
        _tail->next = item;
    }
    else {
        _head = item;
    }
    _tail = item;
}

void List::PushFront(std::string const& data) {
    ListItem *item = new ListItem;
    item->data = data;
    item->next = _head;
    item->previous = nullptr;
    if (_head) {
        _head->previous = item;
    }
    else {
        _tail = item;
    }
    _head = item;
}

std::string List::PopBack() {
    if (_tail) {
        std::string data(std::move(_tail->data));

        ListItem *item = _tail;
        _tail = _tail->previous;
        if (_tail) {
            _tail->next = nullptr;
        }
        else {
            _head = nullptr;
        }

        delete item;
        return std::move(data);
    }
    return std::string();
}

std::string List::PopFront() {
    if (_head) {
        std::string data(std::move(_head->data));

        ListItem *item = _head;
        _head = _head->next;
        if (_head) {
            _head->previous = nullptr;
        }
        else {
            _tail = nullptr;
        }

        delete item;
        return std::move(data);
    }
    return std::string();
}

std::size_t List::Count() const {
    std::size_t count = 0;
    ListItem* item = _head;
    while (item) {
        item = item->next;
        count++;
    }
    return count;
}
