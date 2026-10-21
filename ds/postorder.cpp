#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insertBST(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

// Post-order traversal (Left, Right, Root)
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = nullptr;
    for (int i = 0; i < size; ++i)
        root = insertBST(root, data[i]);

    cout << "Post-order Traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}
