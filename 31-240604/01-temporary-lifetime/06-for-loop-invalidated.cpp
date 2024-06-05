#include <iostream>
#include <vector>

std::vector<int> foo() {
    return {1, 2, 3};
}

struct VectorWrapper {
    std::vector<int> data;
    const std::vector<int> &get() const {
        return data;
    }
};

VectorWrapper bar() {
    return {{1, 2, 3}};
}

int main() {
    for (auto x : foo()) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";

    const VectorWrapper &vw = bar();
    for (auto x : vw.get()) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";

    // May be fixed in C++20/C++23/C++26, maybe not.
    for (auto x : bar().get()) {
        std::cout << x << "\n";
    }
}
