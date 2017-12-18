#include "Queue.h"

Queue::Queue(std::initializer_list<std::string> const& list) {
    for (auto& item : list) {
        PushBack(item);
    }
}

Queue::~Queue() {
    while (_head) {
        QueueItem* item = _head;
        _head = item->next;
        delete item;
    }
}

Queue::Queue(Queue const& queue) {
    QueueItem* item = queue._head;
    while (item) {
        PushBack(item->data);
        item = item->next;
    }
}

void Queue::PushBack(std::string const& data) {
    QueueItem *item = new QueueItem;
    item->data = data;
    item->next = nullptr;
    if (_tail) {
        _tail->next = item;
    }
    else {
        _head = item;
    }
    _tail = item;
}

std::string Queue::PopFront() {
    if (_head) {
        std::string data(std::move(_head->data));

        QueueItem *item = _head;
        _head = _head->next;

        delete item;
        return std::move(data);
    }
    return std::string();
}

std::size_t Queue::Count() const {
    std::size_t count = 0;
    QueueItem* item = _head;
    while (item) {
        item = item->next;
        count++;
    }
    return count;
}
