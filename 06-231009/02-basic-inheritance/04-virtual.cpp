#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

// Library

struct MyStream {
    virtual void write(const std::string &) {
        assert(false);
    }
    virtual void write(int) {
        assert(false);
    }
};

struct MyCoutStream : MyStream {  // inheritance
    void write(const std::string &v) {
        std::cout << v;
    }
    void write(int v) {
        std::cout << v;
    }
};

struct MyStringStream : MyStream {
    std::ostringstream s;

    void write(const std::string &v) {
        s << v;
    }
    void write(int v) {
        s << v;
    }
};

// User code

struct Bigint {
    int x;
};

MyStream &operator<<(MyStream &s, Bigint &b) {  // `&` is important, otherwise creates new `MyStream`.
    s.write(b.x);  // "Virtual" call.
    return s;
}

int main() {
    MyCoutStream s1;
    MyStringStream s2;
    MyStream sBad;  // should not call.
    Bigint x{123};
    s1 << x;  // Binds `MyStream&` to `MyCoutStream`!
    s1.write("!\n");
    s2 << x;  // Binds `MyStream&` to `MyCoutStream`!
    std::cout << "|" << s2.s.str() << "|\n";
}
