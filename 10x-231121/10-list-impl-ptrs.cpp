#include <cassert>
#include <vector>
#include <iostream>

struct Node;
using NodePtr = Node*;

struct Node {
    int data;
    NodePtr prev;
    NodePtr next;
};

const NodePtr NOTHING = nullptr;

struct List {
    NodePtr first = NOTHING;
    NodePtr last = NOTHING;
};

void insert_front(List &v, int x) {
    // int new_node = NODES.size();
    // NODES.emplace_back();
    NodePtr new_node = new Node{};

    // `NODES[new_node]` --> `(*new_node)`

    (*new_node).data = x;
    (*new_node).prev = NOTHING;
    (*new_node).next = v.first;
    if (v.last == NOTHING) {
        v.first = new_node;
        v.last = new_node;
    } else {
        (*v.first).prev = new_node;
        v.first = new_node;
    }
}

void insert_back(List &v, int x) {
    // int new_node = NODES.size();
    // NODES.emplace_back();
    NodePtr new_node = new Node{};

    (*new_node).data = x;
    (*new_node).next = NOTHING;
    (*new_node).prev = v.last;
    if (v.last != NOTHING) {
        (*v.last).next = new_node;
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

NodePtr find(List &v, int x) {
    for (NodePtr it = v.first; it != NOTHING; it = (*it).next) {
        if ((*it).data == x) {
            return it;
        }
    }
    assert(false);
}

void erase(List &, NodePtr it) {       // it = 0
    NodePtr beforeIt = (*it).prev;  // beforeIt = 1
    NodePtr afterIt = (*it).next;   // afterIt = 2
    std::cout << "it=" << it << "\n";
    std::cout << "beforeIt=" << beforeIt << "\n";
    std::cout << "afterIt=" << afterIt << "\n";
    (*afterIt).prev = beforeIt;
    (*beforeIt).next = afterIt;
    // TODO: it == v.first
    // TODO: it == v.last
    // TODO: v.first == v.last == it

    delete it;
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
    for (NodePtr it = v.first; it != NOTHING; it = (*it).next) {
       std::cout << " " << (*it).data;  // 200 100
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
