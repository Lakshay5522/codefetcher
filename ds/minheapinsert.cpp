#include <iostream>
using namespace std;

int heap[100];
int n = 0;

// Insert into Min Heap
void insert(int value) {
    int i = n;
    heap[n] = value;
    n++;

    // Move upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        // If parent is already smaller, stop
        if (heap[parent] <= heap[i])
            break;

        // Swap parent and child
        swap(heap[parent], heap[i]);

        i = parent;
    }
}

// Display heap
void display() {
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);
    insert(40);

    cout << "Min Heap: ";
    display();

    return 0;
}
