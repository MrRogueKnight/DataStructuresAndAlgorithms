// (II) Using a hash table
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates using hash table
void removeDuplicates_Hash(Node* head) {
    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            // Duplicate found — remove node
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

// Utility function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Input: 5 6 3 3 8 5 6 9 7 2 3
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    removeDuplicates_Hash(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
