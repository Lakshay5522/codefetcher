#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Add node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Forward traversal
    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Backward traversal
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Go to last node
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    dll.append(10);
    dll.append(20);
    dll.append(30);
    dll.append(40);

    dll.displayForward();   // Output: 10 20 30 40
    dll.displayBackward();  // Output: 40 30 20 10

    return 0;
}
