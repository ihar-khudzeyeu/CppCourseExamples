#pragma once

#include <cstddef>
#include <string>
#include <initializer_list>

class Queue {
    struct QueueItem {
        std::string data;
        QueueItem* next = nullptr;
    };
public:
    Queue() = default;
    Queue(std::initializer_list<std::string> const& list);
    ~Queue();
    Queue(Queue const& queue);
    void PushBack(std::string const& data);
    std::string PopFront();

    std::size_t Count() const;

private:

    QueueItem* _head = nullptr;
    QueueItem* _tail = nullptr;
};
