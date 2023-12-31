#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    [[maybe_unused]] int x;  // uninitialized! reading - UB.

    std::vector<int> v1, v2;  // empty dynamic arrays
    int n = 5;
    n += 5;
    std::vector<int> v3(n);        // 10 zeros
    std::vector<int> v4{1, 20, 3}; // 3 elements: 1, 20, 3
    std::vector<int> v5(n, 239);   // 10 of 239

    std::cout << "v1:";
    for (int i = 0; i < static_cast<int>(v1.size()); i++) {
        std::cout << " " << v1[i];
    }
    std::cout << "\n";

    std::cout << "v2:";
    for (std::size_t i = 0; i < v2.size(); i++) {
        std::cout << " " << v2[i];
    }
    std::cout << "\n";

    std::cout << "v3:";
    for (int value : v3) {  // range-based-for, C++11
        // for value in v3:  # Python

        std::cout << " " << value;
        // please do not change size of v3, it will be UB
    }
    std::cout << "\n";

    std::cout << "v4:";
    for (auto value : v4) {
        std::cout << " " << value;
    }
    std::cout << "\n";
}
