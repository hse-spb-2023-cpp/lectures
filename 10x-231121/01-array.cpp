#include <cassert>
#include <vector>
#include <iostream>

void insert_front(std::vector<int> &v, int x) {
    v.insert(v.begin(), x);
}

void insert_back(std::vector<int> &v, int x) {
    v.insert(v.end(), x);
    // v.push_back(x);
}

void erase_front(std::vector<int> &v) {
    v.erase(v.begin());
}

void erase_back(std::vector<int> &v) {
    v.erase(v.end() - 1);
}

std::vector<int>::iterator find(std::vector<int> &v, int x) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        if (v[i] == x) {
            return v.begin() + i;
        }
    }
    assert(false);
}

void erase(std::vector<int> &v, std::vector<int>::iterator it) {
    v.erase(it);
}

void print_all(const std::vector<int> &v) {
    for (const auto &x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> vec;
    insert_front(vec, 30);  // O(n)
    insert_front(vec, 20);  // O(n)
    insert_back(vec, 40);  // O(1)
    insert_front(vec, 10);  // O(n)
    insert_back(vec, 50);  // O(1)
    print_all(vec);  // 10 20 30 40 50

    auto x = find(vec, 20);  // O(n)
    erase(vec, x);  // O(n)
    print_all(vec);
}
