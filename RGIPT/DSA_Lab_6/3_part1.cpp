// Q.3: Given a singly linked list having integer values, write a program to remove the duplicate values from the linked list, considering the following solution cases:
// (I) Without using a hash table (not sorting)
// (II) Using a hash table
// e.g., input values of the nodes in a linked list: 5 6 3 3 8 5 6 9 7 2 3, output: 5 6 3 8 9 7 2


// (I) Without using a hash table (not sorting)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates without hash table
void removeDuplicates_NoHash(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                // Duplicate found — remove it
                Node* dup = runner->next;
                runner->next = runner->next->next;
                delete dup;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Utility function to print the linked list
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

    removeDuplicates_NoHash(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
