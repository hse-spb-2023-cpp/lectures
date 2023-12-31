#include <iostream>

int main() {
    std::cout
        << "bool: " << sizeof(bool)
        << "\n";  // Typically 1 byte, but can only hold false (0) and true (1)

    // https://notes.algoprog.ru/cpp/syntax.html#id10
    bool b = false;
    std::cout << b << "\n";
    b = true;
    std::cout << b << "\n";
    // b = "true";  // compilation error
    b = 55;  // not UB, changed to 1
             // Extra reading:
             // https://stackoverflow.com/questions/54120862/does-the-c-standard-allow-for-an-uninitialized-bool-to-crash-a-program
    std::cout << b << "\n";       // 1
    std::cout << b + 10 << "\n";  // bool + int, int, 1 + 10
}
