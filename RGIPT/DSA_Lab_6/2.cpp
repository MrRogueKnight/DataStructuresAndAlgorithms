// Q.2: Write a program to find the cycle in a singly linked list using hashing.

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect cycle using hashing
bool detectCycle(Node* head) {
    unordered_set<Node*> visited;
    Node* temp = head;

    while (temp) {
        // If current node already seen, cycle exists
        if (visited.find(temp) != visited.end()) {
            return true;
        }

        // Mark current node as visited
        visited.insert(temp);
        temp = temp->next;
    }

    return false; // no cycle
}

int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Create a cycle: 50 -> 30
    head->next->next->next->next->next = head->next->next;

    if (detectCycle(head))
        cout << "Cycle detected in the linked list!" << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
