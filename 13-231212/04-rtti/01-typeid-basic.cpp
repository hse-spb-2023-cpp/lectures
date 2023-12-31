#include <boost/core/demangle.hpp>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

namespace ns {
// RTTI (run-time type information) is for polymorphic classes only.
struct Base {
    virtual ~Base() {
    }
};

struct Derived : Base {};
}

using ns::Base;
using ns::Derived;

int foo() {
    std::cout << "foo() called\n";
    return 10;
}

Base &bar() {
    std::cout << "bar() called\n";
    static Derived x;
    return x;
}

int main() {
    // RTTI: Run-Time Type Information.
    // https://en.cppreference.com/w/cpp/language/typeid
    std::cout << "===== 1 (type) =====\n";
    const std::type_info &info_base = typeid(Base);
    const std::type_info &info_derived = typeid(Derived);
    const std::type_info &info_int = typeid(int);

    std::cout << (info_base == info_derived) << "\n";  // 0
    std::cout << (info_base == typeid(Base)) << "\n";  // 1

    std::cout << typeid(int).name() << "\n";  // 'i' (msys2) or 'int' (VS)
    std::cout << info_base.name() << "\n";  // 'N2ns4BaseE' or 'struct ns::Base' (VS)
    std::cout << typeid(std::vector<int>).name()
              << "\n";  // 'St6vectorIiSaIiEE' or something else in VS

    std::cout << boost::core::demangle(info_int.name()) << "\n";
    std::cout << boost::core::demangle(info_base.name()) << "\n";
    std::cout << boost::core::demangle(info_derived.name()) << "\n";
    std::cout << boost::core::demangle(typeid(std::vector<int>).name()) << "\n";

    std::cout << "===== 2a (non-polymorphic) =====\n";
    Base b;
    Derived d;
    const std::type_info &info_int_expr =
        typeid(2 + 2 + foo());  // foo() is not called
    std::cout << boost::core::demangle(info_int_expr.name()) << "\n";
    std::cout << boost::core::demangle(typeid(b).name()) << "\n";
    std::cout << boost::core::demangle(typeid(d).name()) << "\n";
    std::cout << boost::core::demangle(typeid(static_cast<Base>(bar())).name())
              << "\n";  // bar() is not called

    std::cout << "===== 2b (polymorphic) =====\n";
    std::cout << boost::core::demangle(typeid(bar()).name())
              << "\n";  // bar() is called

    Base &bd = d;
    std::cout << boost::core::demangle(typeid(bd).name()) << "\n";
    if (typeid(bd) == typeid(Derived)) {
        [[maybe_unused]] Derived &d2 = static_cast<Derived&>(bd);  // always ok
    }

    std::unique_ptr<Base> dptr(new Derived);
    std::cout << boost::core::demangle(typeid(dptr).name()) << "\n";
    std::cout << boost::core::demangle(typeid(*dptr).name()) << "\n";
}
