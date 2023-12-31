#include <iostream>

struct ratio {
    int num = 0;
    int denom = 1;
    std::vector<int> unused_vector;

    // Better to initialize correctly right away than to reassign.
    ratio() {}
    ratio(int value) : num(value), unused_vector{123, 456} {}
    ratio(int value, int value_denom) : num(value), denom(value_denom), unused_vector(2) {}
};

int main() {
    ratio r1;
    std::cout << r1.num << "\n";
    std::cout << r1.denom << "\n";

    ratio r2(10);
    std::cout << r2.num << "\n";
    std::cout << r2.denom << "\n";

    ratio r3(10, 11);
    std::cout << r3.num << "\n";
    std::cout << r3.denom << "\n";
}
