#include <iostream>

// ## and #, bad stuff happens with nested macros
// Non-standard, but supported by (Apple) GCC, Clang, MSVC (not Intel C++): __COUNTER__, use __LINE__ instead
#define not_really_random (__COUNTER__ * 100)

// It can be made to work! Maybe: https://stackoverflow.com/a/1295338 and (in Russian): https://habr.com/ru/articles/787442/
#define new_var int var_ ## __COUNTER__

int main() {
    std::cout << not_really_random << "\n";
    std::cout << not_really_random << "\n";
    std::cout << not_really_random << "\n";

    new_var = 500;
    std::cout << var___COUNTER__ << "\n";
}
