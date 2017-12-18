#include "Stack.h"
#include "Queue.h"
#include "List.h"

#include <iostream>

template<typename T>
void FancyPopFront(T& t) {
    std::cout << t.PopFront() << " popped from front, " << t.Count() << " left" << std::endl;
}

template<typename T>
void FancyPopBack(T& t) {
    std::cout << t.PopBack() << " popped from back, " << t.Count() << " left" << std::endl;
}

void TestStack() {
    Stack stack = { "1", "2", "3" };
    Stack stack2(stack);

    std::size_t size = stack.Count();
    std::cout << "Stack1 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopBack(stack);
    }

    size = stack2.Count();
    std::cout << "Stack2 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopBack(stack2);
    }
}

void TestQueue() {
    Queue queue = { "1", "2", "3" };
    Queue queue2(queue);

    std::size_t size = queue.Count();
    std::cout << "Queue1 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopFront(queue);
    }

    size = queue2.Count();
    std::cout << "Queue2 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopFront(queue2);
    }
}

void TestListAsQueue() {
    List list = { "1", "2", "3" };
    List list2(list);

    std::size_t size = list.Count();
    std::cout << "List1 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopFront(list);
    }

    size = list2.Count();
    std::cout << "List2 size " << size << ':' << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        FancyPopFront(list2);
    }
}

void TestListCombined() {
    List list = { "2" };
    list.PushBack("Tail");
    list.PushFront("x");

    list.PopFront();
    list.PushFront("Head");

    std::size_t size = list.Count();
    std::cout << "List size is " << size << std::endl;
    std::cout << "Head is " << list.PopFront() << std::endl;
    std::cout << "Tail is " << list.PopBack() << std::endl;

    list.PushFront("1");
    list.PushBack("3");
    for (std::size_t i = 0; i < size; i++) {
        FancyPopBack(list);
    }
}

int main() {
    std::cout << "----------------------------------------\nTest Stack: PushBack, PopBack, Count, copy constructor\n";
    TestStack();
    std::cout << "----------------------------------------\nTest Queue: PushBack, PopFront, Count, copy constructor\n";
    TestQueue();
    std::cout << "----------------------------------------\nTest List: PushBack, PopFront, Count, copy constructor (left to right)\n";
    TestListAsQueue();
    std::cout << "----------------------------------------\nTest List: all Pushes, all Pops, Count\n";
    TestListCombined();
    std::cout << "----------------------------------------\n";

    return 0;
}