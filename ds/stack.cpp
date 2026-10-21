#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Push operation
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
    }

    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }

    // Peek operation
    void peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    // Display stack contents
    void display() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();    // Show current stack

    s.peek();       // Show top element

    s.pop();        // Remove top
    s.display();    // Show current stack

    s.peek();       // Show new top

    return 0;
}
