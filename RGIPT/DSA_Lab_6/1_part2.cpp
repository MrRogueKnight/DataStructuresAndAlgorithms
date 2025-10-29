// (II): Using a Hash Table

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findKthFromEndHash(Node* head, int k) {
    unordered_map<int, Node*> mp;
    Node* temp = head;
    int index = 0;

    // Store each node with index
    while (temp) {
        mp[index++] = temp;
        temp = temp->next;
    }

    int n = index; // total number of nodes
    if (k > n) return nullptr; // invalid k

    return mp[n - k];
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 3;
    Node* res = findKthFromEndHash(head, k);

    if (res)
        cout << "Kth node from end: " << res->data << endl;
    else
        cout << "K is greater than number of nodes" << endl;

    return 0;
}
