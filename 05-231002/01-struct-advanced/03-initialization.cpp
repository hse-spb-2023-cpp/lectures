#include <iostream>

// Lots of ways: https://habr.com/ru/companies/jugru/articles/469465/
// We care about syntax.

struct Point {
    int x;  // default initialization
    int y{};  // value initialization
};

int main() {
    // https://en.cppreference.com/w/cpp/language/default_initialization
    std::vector<int> v_default;  // empty vector
    int x_default;  // uninitialized value
    Point p_default;  // x = uninitialized, y = 0
    double d_default;  // uninitialized

    // https://en.cppreference.com/w/cpp/language/value_initialization
    std::vector<int> v_value{};  // empty vector
    int x_value{};  // 0
    Point p_value{};  // x = 0, y = 0
    double d_default{};  // 0

    // https://en.cppreference.com/w/cpp/language/direct_initialization
    std::vector<int> v_direct(10);  // vector of 10 elements

    // https://en.cppreference.com/w/cpp/language/list_initialization
    // aggregate initialization, or something special (`vector`)
    Point p_list{2, 3};
    std::vector<int> v_list1{1, 2, 3};
    std::vector<int> v_list2 = {1, 2, 3};

    // Temporary values
    auto val1 = int(10);
    auto val2 = int{10};
    auto val3 = static_cast<int>(10);
    auto val4 = std::vector<int>();  // value initialization + copy
    auto val5 = std::vector<int>{};  // list initialization (->value) + copy
    auto val6 = std::vector<int>{1, 2};  // list initialization + copy
}
