#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i for Min Heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;          // Assume current node is smallest
    int left = 2 * i + 1;      // Index of left child
    int right = 2 * i + 2;     // Index of right child

    // If left child is smaller than current smallest
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root, swap and continue heapifying
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);  // Recursively heapify the affected subtree
    }
}

// Function to build a Min Heap from an array
void buildMinHeap(int arr[], int n) {
    // Start from last non-leaf node and go up to root
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {40, 20, 30, 10, 50, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    buildMinHeap(arr, n);

    cout << "Min Heap:\n";
    printArray(arr, n);

    return 0;
}
