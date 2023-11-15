#ifndef FOO_HPP_
#define FOO_HPP_

struct Foo {
    int x = 10;
    Foo();
};

extern Foo f;  // declaraion (not definition!) of global variable
Foo &get_foo();

#endif  // FOO_HPP_
