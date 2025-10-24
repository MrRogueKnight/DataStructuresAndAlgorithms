/*
Q.2: Write a program to reverse the singly linked list, and the input linked list would be 
the final output linked list after performing all operations in Q.1.
*/

// sol

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

    void reverse() {
        Node* prev = nullptr, * curr = head, * next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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

    // Build the final linked list from Q.1 operations
    for (char c = 'A'; c <= 'J'; c++) list.insertEnd(c);
    for (char c = 'K'; c <= 'T'; c++) list.insertBegin(c);

    char rem[] = { 'U','V','W','X','Y' };
    int pos[] = { 4,8,12,16,20 };
    for (int i = 0; i < 5; i++) list.insertBeforePos(rem[i], pos[i]);
    list.insertEnd('Z');

    list.deleteBegin();
    list.deleteEnd();

    int delPos[] = { 3,6,9,12 };
    for (int p : delPos) list.deletePos(p);

    cout << "Final list from Q.1: ";
    list.display();

    list.reverse();
    cout << "Reversed list: ";
    list.display();

    return 0;
}