#include <iostream>

struct ratio {
    int num;
    int denom;

    explicit operator double() {
        std::cout << "operator double()\n";
        return num * 1.0 / denom;
    }
};

int main() {
    ratio r{3, 4};
    std::cout << r.num << "\n";
    // double x0 = r;  // compilation error
    double x = static_cast<double>(r);
    [[maybe_unused]] double x2(r);
    [[maybe_unused]] double x3 = double(r);
    std::cout << x << "\n";
    std::cout << static_cast<double>(r) << "\n";
}
