#include <iostream>

struct ratio {
    int num = 0;
    int denom = 1;
    // no default constructor is autogenerated
    ratio(int value) : num(value) {}
};

int main() {
    ratio r;
}
