#include <vector>
int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    [[maybe_unused]] int *a = &v[0];  // &a = 100;   a = 0
    [[maybe_unused]] int *b = &v[2];  // &b = 200;   b = 2
    [[maybe_unused]] int **aa = &a;   // &aa = 1000; aa = 100
    [[maybe_unused]] int **bb = &b;   // &bb = 2000; bb = 200
    [[maybe_unused]] int **cc = aa;   // &cc = 3000; cc = 100
    **aa = 10;  // *(*aa) = 10;  // *a = 10;  // v[0] = 10;
    *aa = b;  // *aa = b;  // a = b;  // a = &v[2]
    *b = 5;
    *aa = &v[3];
    cc = &a;
    *a = 7;
}
