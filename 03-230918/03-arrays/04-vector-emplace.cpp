#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<std::pair<int, int>> v;

    // Extra reading: emplace_back() works as well, but involves implicit conversions
    // https://abseil.io/tips/112

    v.push_back(std::pair<int, int>(10, 20));
    v.push_back(std::make_pair(10, 20));
    v.push_back(std::pair(10, 20));  // C++17
    v.push_back({10, 20});  // Not always

    v.emplace_back(20, 30);
    std::cout << "v:";
    for (auto x : v) {
        std::cout << " (" << x.first << " " << x.second << ")";
    }
    std::cout << "\n";
}
