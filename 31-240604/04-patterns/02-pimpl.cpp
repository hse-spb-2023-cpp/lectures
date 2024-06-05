// pimpl ~ pointer to implementation

// Before 
// a.hpp
class very_complex_class {
private:
    int a, b, c, d, e, f;

public:
    void make_everyone_happy();
    void make_everyone_sad();
};
// a.cpp
void very_complex_class::make_everyone_happy() {
    // ....
}

// After
// a.hpp
struct very_complex_class_impl;
class very_complex_class {
private:
    std::unique_ptr<very_complex_class_impl> pImpl;

public:
    very_complex_class_impl();
    ~very_complex_class_impl();  // important!
    void make_everyone_happy();
    void make_everyone_sad();
};
// a.cpp
struct very_complex_class_impl {
    int a, b, c, d, e, f;
    void make_everyone_happy();
    void make_everyone_sad();
};

very_complex_class::very_complex_class()
    : pImpl(new very_complex_class_impl()) {}

very_complex_class::~very_complex_class() {}

void very_complex_class::make_everyone_happy() {
    return pImpl->make_everyone_happy();
}
void very_complex_class::make_everyone_sad() {
    return pImpl->make_everyone_happy();
}

void very_complex_class_impl::make_everyone_happy() {
    // ....
}
void very_complex_class_impl::make_everyone_happy() {
    // ....
}
