struct my_vector {
    my_vector() {}
    // explicit constructors do not participate in copy initialization.
    // direct initialization ~ explicit + implicit
    // copy initialization ~ implicit
    explicit my_vector(int) {}
};

void print_vector([[maybe_unused]] const my_vector &vec) {
}

int main() {
    [[maybe_unused]] my_vector v1a(10);
    [[maybe_unused]] my_vector v1b{10};
    [[maybe_unused]] my_vector v1c = my_vector(10);
    [[maybe_unused]] my_vector v1d = my_vector(10);

    // [[maybe_unused]] my_vector v2 = 10;
    // print_vector(10);

    // cast is explicit + copy initialization from vector
    [[maybe_unused]] my_vector v3 = static_cast<my_vector>(10);
    // cast is explicit + copy initialization
    print_vector(static_cast<my_vector>(10));
    // direct initialization of temporary
    print_vector(my_vector(10));
}
