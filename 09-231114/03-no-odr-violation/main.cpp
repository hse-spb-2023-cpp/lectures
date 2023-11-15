// These are two independent overloads.
void foo(int, int);
void foo() {
}

int main() {
    foo();
    foo(10, 20);
}
