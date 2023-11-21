int main() {
    int x = 0;
    &x;  // 0x12345678
    &(&x);  // &0x12345678

    // Foo(Foo&&)
}
