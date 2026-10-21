#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int SIZE = 5; // Small size to force collisions
    list<int> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at bucket " << index << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (auto &x : table[index]) {
            if (x == key) {
                cout << "Found " << key << " in bucket " << index << endl;
                return true;
            }
        }
        cout << key << " not found!" << endl;
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
        cout << "Removed " << key << " from bucket " << index << endl;
    }

    void display() {
        cout << "\nHash Table State:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto &x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL\n";
        }
        cout << endl;
    }
};

int main() {
    HashTable ht;

    // Insertion with collisions
    ht.insert(10); // bucket 0
    ht.insert(15); // bucket 0 (collision with 10)
    ht.insert(7);  // bucket 2
    ht.insert(12); // bucket 2 (collision with 7)

    ht.display();

    // Searching
    ht.search(15); // Found
    ht.search(5);  // Not found

    // Deletion
    ht.remove(15);
    ht.display();

    return 0;
}
