/*
Q.1: Given a series of 26 Alphabets- 'A', 'B', 'C', 'D', ......, 'Y', 'Z', then write a program to perform the following operation in a Singly Linked List (SLL).

Insertion:

(I) Perform the insertion of the first ten (10) alphabets into the SLL, considering the insertion at the end of the list.
(II) Perform the insertion of the next ten (10) alphabets into the SLL, considering the insertion at the beginning of the list.
(III) Perform the insertion of the remaining five (5) alphabets before the 4th, 8th, 12th, 16th, and 20th node of the linked list, and then insert the last alphabet 'Z' at the end of the linked list.

Deletion:

(I) Perform the deletion of an alphabet from the beginning and another from the end of the list.
(II) Delete the 3rd, 6th, 9th, and 12th alphabets/nodes from the linked list

*/

// Solution 

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

class SLL {
    Node* head;
public:
    SLL() : head(nullptr) {}

    void insertEnd(char d) {
        Node* newNode = new Node(d);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void insertBegin(char d) {
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }

    void insertBeforePos(char d, int pos) {
        if (pos <= 1) insertBegin(d);
        else {
            Node* newNode = new Node(d);
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp->next; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteBegin() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deletePos(int pos) {
        if (!head || pos < 1) return;
        if (pos == 1) deleteBegin();
        else {
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp->next; i++) temp = temp->next;
            if (temp->next) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SLL list;

    // I: First 10 at end
    for (char c = 'A'; c <= 'J'; c++) list.insertEnd(c);

    // II: Next 10 at beginning
    for (char c = 'K'; c <= 'T'; c++) list.insertBegin(c);

    // III: Remaining 5 before positions
    char rem[] = { 'U','V','W','X','Y' };
    int pos[] = { 4,8,12,16,20 };
    for (int i = 0; i < 5; i++) list.insertBeforePos(rem[i], pos[i]);
    list.insertEnd('Z');

    cout << "After insertion: ";
    list.display();

    // I: Beginning and end
    list.deleteBegin();
    list.deleteEnd();

    // II: Specific positions
    int delPos[] = { 3,6,9,12 };
    for (int pos : delPos) list.deletePos(pos);

    cout << "After deletion: ";
    list.display();

    return 0;
}