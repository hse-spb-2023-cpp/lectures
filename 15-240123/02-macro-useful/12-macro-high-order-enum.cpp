#include <iostream>

// X macros: https://en.wikipedia.org/wiki/X_macro

#define LIST_E(f) f(Option1) f(Option2) f(Option3)
enum E {
   #define OPTION(e) e,
   LIST_E(OPTION)
   // OPTION(Option1) OPTION(Option2) OPTION(Option3)
   // Option1, Option2, Option3,
   #undef OPTION
};

int main() {
    E e = Option2;
    switch (e) {
    case Option1: std::cout << "Option1\n"; break;
    case Option2: std::cout << "Option2\n"; break;
    case Option3: std::cout << "Option3\n"; break;
    }

    switch (e) {
    #define PRINT_OPTION(e) case e: std::cout << #e "\n"; break;
    LIST_E(PRINT_OPTION)
    #undef PRINT_OPTION  // undefine, remove macro
    }
}
