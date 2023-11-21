struct Node {
    int data;
    Node *prev;
    Node *next;
};

int main() {
    Node a, b;
    // a.next = b;
    a.next = &b;  // take address

    // NODES[a].next = NODES[b];
    // NODES[a].next = b;
}
