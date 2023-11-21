#include <cassert>
#include <list>
#include <iostream>

void insert_front(std::list<int> &v, int x) {
    v.insert(v.begin(), x);
}

void insert_back(std::list<int> &v, int x) {
    v.insert(v.end(), x);
    // v.push_back(x);
}

void erase_front(std::list<int> &v) {
    v.erase(v.begin());
}

void erase_back(std::list<int> &v) {
    // v.erase(v.end() - 1);
    v.erase(--v.end());
}

std::list<int>::iterator find(std::list<int> &v, int x) {
    /*for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        if (v[i] == x) {
            return v.begin() + i;
        }
    }*/
    for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (*it == x) {
            return it;
        }
    }
    assert(false);
}

void erase(std::list<int> &v, std::list<int>::iterator it) {
    v.erase(it);
}

void print_all(const std::list<int> &v) {
    for (const auto &x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";
}

int main() {
    std::list<int> vec;
    insert_front(vec, 30);  // O(1)
    insert_front(vec, 20);  // O(1)
    insert_back(vec, 40);  // O(1)
    insert_front(vec, 10);  // O(1)
    insert_back(vec, 50);  // O(1)
    print_all(vec);  // 10 20 30 40 50

    auto x = find(vec, 20);  // O(n)
    erase(vec, x);  // O(1)
    print_all(vec);
}
