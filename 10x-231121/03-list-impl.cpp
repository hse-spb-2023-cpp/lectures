/*
front = A
last = C
┌────A─────┐  ┌────B─────┐  ┌────C─────┐
│-  100   B│  │A  200   C│  │B  300   -│
└──────────┘  └──────────┘  └──────────┘
*/

struct Node {
    int data;
    int prev;
    int next;
};

int main() {
    std::vector<Node> nodes(10'000);
    const int NOTHING = -1;
    const int A = 123;
    const int B = 456;
    const int C = 300;
    int front = A;
    int last = C;
    nodes[A].data = 100; nodes[A].prev = NOTHING; nodes[A].next = B;
    nodes[B].data = 200; nodes[B].prev = A;       nodes[B].next = C;
    nodes[C].data = 300; nodes[C].prev = B;       nodes[C].next = NOTHING;

    nodes[B].next = NOTHING;
    last = B;
/*
front = A
last = B
┌────A─────┐  ┌────B─────┐  ┌ ─ ─C─ ─ ─┐
│-  100   B│  │A  200   -│   B  300   - 
└──────────┘  └──────────┘  └ ─ ─ ─ ─ ─┘
*/
}
