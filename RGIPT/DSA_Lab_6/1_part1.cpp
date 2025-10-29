// Q.1: Given a singly linked list having n nodes, write a program to find out the kth node from the end of the linked list, considering the  following solution cases:
// (I) Without a hash table in a single pass/traversal of the linked list
// (II) Using a hash table

// (I): Without Hash Table — Single Pass Solution

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findKthFromEnd(Node* head, int k) {
    Node* first = head;
    Node* second = head;

    // Move first k steps ahead
    for (int i = 0; i < k; i++) {
        if (!first) return nullptr; // if k > n
        first = first->next;
    }

    // Move both until first reaches end
    while (first) {
        first = first->next;
        second = second->next;
    }

    return second; // kth node from end
}

int main() {
    // Example Linked List: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 2;
    Node* res = findKthFromEnd(head, k);

    if (res)
        cout << "Kth node from end: " << res->data << endl;
    else
        cout << "K is greater than number of nodes" << endl;

    return 0;
}
