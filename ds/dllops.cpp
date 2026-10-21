#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at specific position (0-based index)
    void insertAtPosition(int position, int value) {
        if (position == 0) {
            insertAtHead(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 0; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds.\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete head
    void deleteAtHead() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete tail
    void deleteAtTail() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at specific position (0-based index)
    void deleteAtPosition(int position) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (position == 0) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of bounds.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPosition(1, 15);  // Insert 15 at position 1
    list.insertAtPosition(2, 35);
    cout << "List after insertions:\n";
    list.display();

    list.deleteAtHead();
    list.deleteAtTail();

    list.deleteAtPosition(2);  // Delete node at position 2

    cout << "List after deletions:\n";
    list.display();

    return 0;
}
