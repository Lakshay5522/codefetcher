#include <iostream>
using namespace std;

// Define structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node in the BST
Node* insertBST(Node* root, int value) {
    if (root == nullptr) {
        // Create new node if tree is empty or at correct position
        return new Node(value);
    }

    // Go to left subtree if value is smaller
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    // Go to right subtree if value is greater
    else {
        root->right = insertBST(root->right, value);
    }

    return root;
}

// In-order traversal to print BST in sorted order
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Example dataset
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = nullptr;

    // Insert each element into the BST
    for (int i = 0; i < size; ++i) {
        root = insertBST(root, data[i]);
    }

    // Print in-order traversal (should be sorted)
    cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
