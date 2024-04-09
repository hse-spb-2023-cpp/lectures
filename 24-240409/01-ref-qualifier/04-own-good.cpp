#include <iostream>
#include <memory>
#include <optional>
#include <utility>

std::optional<std::unique_ptr<int>> create() {
    return std::make_unique<int>(10);
}

void just_print(const std::unique_ptr<int> &a) {
    if (a) {
        std::cout << "printed " << *a << std::endl;
    } else {
        std::cout << "printed nullptr" << std::endl;
    }
}

void consume_print(std::unique_ptr<int> a) {
    just_print(a);
}

struct MyOptionalUniquePtrInt {
    std::unique_ptr<int> p = std::make_unique<int>(30);

    // ref-qualifier: https://habr.com/ru/post/216783/
    std::unique_ptr<int> &value() & {
        return p;
    }

    const std::unique_ptr<int> &value() const & {
        return p;
    }

    std::unique_ptr<int> &&value() && {  // Return reference to avoid copy.
        return std::move(p);
    }
    
    // Not covered: const&&
};

MyOptionalUniquePtrInt my_create() {
    return {};
}

int main() {
    MyOptionalUniquePtrInt a;

     // a.value() is lvalue: method returns reference.
     just_print(a.value());
     // consume_print(a.value());  // CE
     consume_print(std::move(a.value()));

     // <rvalue-optional>.value() is rvalue: https://en.cppreference.com/w/cpp/utility/optional/value
     consume_print(create().value());
     consume_print(my_create().value());
     consume_print(std::move(a).value());
}
