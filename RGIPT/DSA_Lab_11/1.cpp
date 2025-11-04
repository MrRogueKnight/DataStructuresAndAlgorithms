#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << (isBST(root) ? "Given tree is a BST" : "Given tree is not a BST");
    return 0;
}
