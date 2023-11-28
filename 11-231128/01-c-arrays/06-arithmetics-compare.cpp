#include <iostream>

int main() {
    int a[]{1, 2, 3, 4};
    int b[]{10, 20, 30, 40};

    int *p1 = a + 1;  // &a[1]
    int *p2 = a + 4;  // one-past-end
    int *p3 = b;      // &b[0]
    int *p4 = b + 2;  // &b[2]

    // Valid operations.
    std::cout << (p1 == p2) << "\n";  // false
    std::cout << (p1 < p2) << "\n";  // true
    std::cout << (p1 > p2) << "\n";  // false

    std::cout << (p3 == p4) << "\n";  // false
    std::cout << (p3 < p4) << "\n";  // true

    std::cout << (p1 == nullptr) << "\n";  // false
    std::cout << (p3 == nullptr) << "\n";  // false

    // Valid operations.
    std::cout << (p1 == p3) << "\n";  // false
    std::cout << (p2 == p4) << "\n";  // false

    // Not UB, but weird.  Maybe unspecified behavior?
    std::cout << p2 << "\n";
    std::cout << p3 << "\n";
    std::cout << (p2 == p3) << "\n";  // ?????
    std::cout << (p2 != p3) << "\n";  // ?????

    // Not UB, but unspecified.
    std::cout << (p2 < p3) << "\n";  // ?????
    std::cout << (p2 > p3) << "\n";  // ?????

    // Well-defined.
    std::cout << std::less{}(p2, p3) << "\n";  // ?????
    std::cout << std::less{}(p3, p2) << "\n";  // ?????
}
