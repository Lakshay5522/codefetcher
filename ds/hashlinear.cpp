#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    int table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // -1 means empty
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index; // To detect full loop

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash Table is full!\n";
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -2; // -2 means deleted
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    ht.display();

    cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    ht.remove(15);
    cout << "After removing 15:\n";
    ht.display();

    return 0;
}
