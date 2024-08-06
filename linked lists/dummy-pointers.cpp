struct LinkedListNode {
    int val;
    LinkedListNode *next;
    LinkedListNode *prev;
    LinkedListNode(int val): val (val), next(nullptr), prev(nullptr) {}
};

int main() {
    // Write your code here
    // Try creating 1 <-> 2 <-> 3
    // Test with cout
    LinkedListNode* node1 = new LinkedListNode(1);
    LinkedListNode* node2 = new LinkedListNode(2);
    LinkedListNode* node3 = new LinkedListNode(3);
    // Link nodes in forward direction
    node1->next = node2;
    node2->next = node3;

    // Link nodes in backward direction
    node2->prev = node1;
    node3->prev = node2;
}
