#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 5; // Small to force collisions
    int table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // Empty
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1 && table[index] != -2) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash Table is full!\n";
                return;
            }
        }
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "Found " << key << " at index " << index << endl;
                return true;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        cout << key << " not found!\n";
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -2; // Deleted marker
                cout << "Removed " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        cout << key << " not found!\n";
    }

    void display() {
        cout << "\nHash Table State:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    HashTable ht;

    // Insertion with collisions
    ht.insert(10); // index 0
    ht.insert(15); // collision -> index 1
    ht.insert(7);  // index 2
    ht.insert(12); // collision -> index 3

    ht.display();

    // Searching
    ht.search(15); // Found
    ht.search(5);  // Not found

    // Deletion
    ht.remove(15);
    ht.display();

    return 0;
}
