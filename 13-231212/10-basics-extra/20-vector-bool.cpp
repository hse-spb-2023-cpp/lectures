#include <iostream>
#include <vector>

int main() {
    // Extra reading: https://isocpp.org/blog/2012/11/on-vectorbool
    // TODO: add from https://alenacpp.blogspot.com/2005/06/vector.html , example with `bool&`

    std::vector<bool> v{false, true, false};
    std::cout << v[0] << v[1] << v[2] << "\n";  // 010
    v[1] = true;

    for ([[maybe_unused]] bool x : v) {  // copy as expected
        x = true;
    }
    std::cout << v[0] << v[1] << v[2] << "\n";  // 010

    // for (bool &x : v) { x = true; }  // does not compile :(

    for (auto x : v) {  // copy?
        x = true;
    }
    std::cout << v[0] << v[1] << v[2] << "\n";  // 111 ?!
}
