/*
Q.3: Write a program to find out the cycle in a given singly linked list. 
[Note: First, you have to generate a linked list through consecutive insertion operations. 
You may use any data type for the elements of your linked list. 
Now, generate two examples, i.e., with a cycle case and without a cycle case, and show the output of your implementation.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class SLL {
    Node* head;
public:
    SLL() : head(nullptr) {}

    void insertEnd(int d) {
        Node* newNode = new Node(d);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void createCycle(int pos) {
        if (!head) return;
        Node* end = head, * cycleNode = nullptr;
        int count = 1;

        while (end->next) {
            if (count == pos) cycleNode = end;
            end = end->next;
            count++;
        }
        if (cycleNode) end->next = cycleNode;
    }

    bool hasCycle() {
        if (!head) return false;

        Node* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    void display(int limit = 20) {
        Node* temp = head;
        int count = 0;
        while (temp && count < limit) {
            cout << temp->data << "->";
            temp = temp->next;
            count++;
        }
        cout << (temp ? "..." : "NULL") << endl;
    }
};

int main() {
    SLL list1;
    for (int i = 1; i <= 10; i++) list1.insertEnd(i);

    cout << "List without cycle: ";
    list1.display();
    cout << "Has cycle: " << (list1.hasCycle() ? "Yes" : "No") << endl << endl;

    SLL list2;
    for (int i = 1; i <= 10; i++) list2.insertEnd(i);
    list2.createCycle(4);

    cout << "List with cycle: ";
    list2.display();
    cout << "Has cycle: " << (list2.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}