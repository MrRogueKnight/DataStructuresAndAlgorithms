#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

int nextKey = 1;

Node* generateMinAVL(int h) {
    if (h < 0) return nullptr;
    Node* left = generateMinAVL(h - 1);
    Node* root = new Node(nextKey++);
    root->left = left;
    root->right = generateMinAVL(h - 2);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    int h;
    cin >> h;
    Node* root = generateMinAVL(h);
    inorder(root);
    cout << endl;
    return 0;
}
