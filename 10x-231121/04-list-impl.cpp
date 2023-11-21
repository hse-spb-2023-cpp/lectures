#include <cassert>
#include <vector>
#include <iostream>

struct Node {
    int data;
    int prev;
    int next;
};

std::vector<Node> NODES;
const int NOTHING = -1;

struct List {
    int first = NOTHING;
    int last = NOTHING;
};

void insert_front(List &v, int x) {
    int new_node = NODES.size();
    NODES.emplace_back();
    NODES[new_node].data = x;
    NODES[new_node].prev = NOTHING;
    NODES[new_node].next = v.first;
    if (v.last == NOTHING) {
        v.first = new_node;
        v.last = new_node;
    } else {
        NODES[v.first].prev = new_node;
        v.first = new_node;
    }
}

void insert_back(List &v, int x) {
    int new_node = NODES.size();
    NODES.emplace_back();
    NODES[new_node].data = x;
    NODES[new_node].next = NOTHING;
    NODES[new_node].prev = v.last;
    if (v.last != NOTHING) {
        NODES[v.last].next = new_node;
        v.last = new_node;
    } else {
        v.first = new_node;
        v.last = new_node;
    }
}

void erase_front(List &) {
    assert(false);  // TODO
}

void erase_back(List &) {
    assert(false);  // TODO
}

int find(List &v, int x) {
    for (int it = v.first; it != NOTHING; it = NODES[it].next) {
        if (NODES[it].data == x) {
            return it;
        }
    }
    assert(false);
}

void erase(List &, int it) {       // it = 0
    int beforeIt = NODES[it].prev;  // beforeIt = 1
    int afterIt = NODES[it].next;   // afterIt = 2
    std::cout << "it=" << it << "\n";
    std::cout << "beforeIt=" << beforeIt << "\n";
    std::cout << "afterIt=" << afterIt << "\n";
    NODES[afterIt].prev = beforeIt;
    NODES[beforeIt].next = afterIt;
    // TODO: it == v.first
    // TODO: it == v.last
    // TODO: v.first == v.last == it
}

/*
first = 1
last = 2
┌────0─────┐   ┌────1─────┐   ┌────2─────┐
│1  100   2│   │-  200   0│   │1  300   -│
└──────────┘   └──────────┘   └──────────┘
insert_front(v, 100);  // 0: {0: 100}
insert_front(v, 200);  // 1: {1: 200, 0: 100}
insert_back( v, 300);  // 2: {1: 200, 0: 100, 2: 300}
*/
void print_all(const List &v) {
    for (int it = v.first; it != NOTHING; it = NODES[it].next) {
       std::cout << " " << NODES[it].data;  // 200 100
    }
    std::cout << "\n";
}

int main() {
    List vec;
    insert_front(vec, 30);  // O(1)
    insert_front(vec, 20);  // O(1)
    insert_back(vec, 40);  // O(1)
    insert_front(vec, 10);  // O(1)
    insert_back(vec, 50);  // O(1)
    print_all(vec);  // 10 20 30 40 50

    auto x = find(vec, 20);  // O(n)
    erase(vec, x);  // O(n)
    print_all(vec);
}
