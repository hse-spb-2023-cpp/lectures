#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<std::pair<int, int>> v;

    v.emplace_back(20, 30);
    std::cout << "v:";
    for (auto [a, b] : v) {  // structured binding, C++17
        // for (a, b) in v:  # Python
        std::cout << " (" << a << " " << b << ")";
    }
    std::cout << "\n";

    // todo: distinct types are ok
    {
        auto [a, b] = v[0];
        std::cout << "v[0] = " << a << " " << b << "\n";
    }
    {
        auto &[a, b] = v[0];
        a++;
        std::cout << "v[0] = " << v[0].first << " " << v[0].second << "\n";
    }
}
