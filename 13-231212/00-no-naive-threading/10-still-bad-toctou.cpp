#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O2")

int main() {
    std::atomic<bool> finished = false;
    std::atomic<int> value = 0;

    std::thread t1([&]() {
        while (!finished) {
            value++;
        }
    });

    for (int i = 0; i < 10; ++i) {
        std::cout << "value=" << value << "\n";
    }
    // Order does not matter: incorrect in both cases.
    finished = true;
    value = 1'000'000;

    t1.join();
    std::cout << value << "\n";
}
