#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

namespace ns1 {
struct Foo {};
void do1(const Foo &) {}
}

namespace ns2 {
using Bar = ns1::Foo;
void do2(const Bar &) {}

Bar b;
}

int main() {
    ns2::Bar b;  // Really `ns1::Foo`
    do1(b);
    // do2(b);
    // do2(ns2::b);  // Compiler only looks at the _type_ of the argument.

    // Example:
    std::string str;
    getline(std::cin, str);
    // Better: std::getline

    std::vector<int> v{1, 2, 3};
    sort(v.begin(), v.end());  // v.begin() ~ std::vector<int>::iterator ~(?) int*
    // Better: std::sort
    // Probably not guaranteed at all: https://stackoverflow.com/questions/6803556/do-custom-container-iterators-guarantee-adl-to-consider-namespace-std
    // See https://quuxplusone.github.io/blog/2022/03/03/why-isnt-vector-iterator-just-t-star/
}
