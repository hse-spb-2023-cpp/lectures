#include <vector>

template<typename T>
struct BaseConstructorTag {};

template<typename T>
struct Base {
    Base() {}
    Base(BaseConstructorTag<T>) {}
};

struct ConvertibleToBase {
    operator Base<int>() {
        return {};
    }
    // Even more fun for compiler and you, see `return-type-resolver` exercise
    // template<typename T> operator T() { return {}; }
    // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Return_Type_Resolver
};

template<typename T>
void foo(const Base<T> &) {
}

int main() {
    BaseConstructorTag<int> t;
    [[maybe_unused]] const Base<int> &tref = t;  // Creates a temporary and binds to it.
    foo<int>(t);  // Works exactly as above.
    // foo(t);  // compilation error: cannot deduce T because compiler won't go through all possible constructors

    ConvertibleToBase x;
    [[maybe_unused]] const Base<int> &xref = x;  // Creates a temporary and binds to it.
    foo<int>(x);  // Works exactly as above.
    // foo(x);  // compilation error: cannot deduce T because compiler won't go through all possible conversions
}
