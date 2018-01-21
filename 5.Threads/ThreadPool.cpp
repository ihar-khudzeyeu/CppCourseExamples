#include <thread>
#include <functional>
#include <vector>
#include <atomic>
#include <algorithm>
#include <queue>
#include <mutex>
#include <iostream>
#include <chrono>

class ThreadPool {
public:
    explicit ThreadPool(int n) :
            _stop(false),
            _count(0),
            _worker_flags(n),
            _workers(n) {
        std::fill_n(_worker_flags.begin(), n, false);
        _controller = std::thread([this]() {
            while (!_stop) {
                if (_count != 0) {
                    std::unique_lock<std::mutex> lock(_mutex);
                    auto it = std::find(_worker_flags.begin(), _worker_flags.end(), false);
                    if (it != _worker_flags.end()) {
                        size_t index = it - _worker_flags.begin();
                        if (_workers[index].joinable()) {
                            _workers[index].join();
                        }
                        *it = true;
                        _workers[index] = std::thread([this, index]() {
                            _tasks.front()();
                            _worker_flags[index] = false;
                        });
                        _tasks.pop();
                        _count--;
                    }
                }

                std::this_thread::yield();
            }
        });
    }


    ~ThreadPool() {
        _stop = true;
        _controller.join();
        Wait();
    }

    void Add(std::function<void()> task) {
        std::unique_lock<std::mutex> lock(_mutex);
        _count++;
        _tasks.push(task);
    }

    void Wait() {
        while (_count != 0) {
            std::this_thread::yield();
        }

        std::for_each(_workers.begin(), _workers.end(),
                      [](std::thread& e) {
                          if (e.joinable()) {
                              e.join();
                          }
                      });
    }
private:
    std::vector<std::thread> _workers;
    std::vector<std::atomic_bool> _worker_flags;
    std::atomic_uint _count;
    std::atomic_bool _stop;
    std::queue<std::function<void()>> _tasks;
    std::thread _controller;
    std::mutex _mutex;
};

int main() {
    ThreadPool s(2);

    s.Add([]() {
        std::cout << "Function 1 start!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Function 1 end!\n";
    });
    s.Add([]() {
        std::cout << "Function 2 start!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Function 2 end!\n";
    });
    s.Add([]() {
        std::cout << "Function 3 start!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Function 3 end!\n";
    });
    s.Add([]() {
        std::cout << "Function 4 start!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Function 4 end!\n";
    });
    s.Add([]() {
        std::cout << "Function 5 start!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Function 5 end!\n";
    });
    s.Wait();
    return 0;
}
