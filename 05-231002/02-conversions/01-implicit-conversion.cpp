#include <cassert>
#include <iostream>

struct ratio {
    int num = 0;
    int denom = 1;
    ratio() {
        std::cout << "Default constructor\n";
    }
    ratio(int value) : num(value) {
        std::cout << "ratio(int)\n";
    }
    ratio(int num_, int denom_) : num(num_), denom(denom_) {
        assert(denom != 0);
        std::cout << "ratio(int, int)\n";
    }
};

void println(const ratio &r) {
    std::cout << r.num << " " << r.denom << "\n";
}

ratio generate_ratio() {
    return 123;  // 3. copy initialization: a new 'ratio' is created
    // return {123};  // copy list initialization
    // return {};  // copy initialization
}

int main() {
    ratio r(10);  // direct initialization
    ratio r1 = 10;  // 1(a). copy initialization, it has '='
    ratio r2 = {10};  // 1(b). list copy initialization, it has '='.
    ratio r2 = {};  // 1(c). copy initialization, it has '='.

    println(r);  // no new objects
    println(ratio(10));  // direct initialization of temporary
    println(ratio{10});  // direct list initialization of temporary
    println(10);  // 2(a). copy initialization: a temporary is created
    println({10});  // 2(b). list copy initialization
    println({10, 3});  // 2(c). list copy initialization

    println(generate_ratio());

    int x = 20;
    ratio r3 = x;  // copy initialization
    println(x);  // copy initialization
    r3 = 40;
    println(r3);
}
