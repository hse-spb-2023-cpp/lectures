#ifndef FOO_H_
#define FOO_H_

#include <vector>
// #include "bar.hpp"
struct Bar;  // `struct`, or `class`? or `typedef int Bar;`? or `using Bar = int;`

struct Foo {
    std::vector<Bar> bs;

    void doit();
    friend void foo_friend();
};

#endif  // FOO_H_
