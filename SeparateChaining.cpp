#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    // Define a list vector for each entry
    vector<list<int>> table;
    int size; // table size

    // Simple hash function: Takes the modulus of elements by table size
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor for creating a hash table
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Insertion operation
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Removal operation
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Search operation to check for the existence of an element
    bool search(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Creating a hash table and specifying the size
    HashTable hashTable(10);

    // Inserting elements
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);

    // Checking for the existence of elements
    cout << "20 exists: " << (hashTable.search(20) ? "Yes" : "No") << endl;
    cout << "40 exists: " << (hashTable.search(40) ? "Yes" : "No") << endl;

    // Removing an element
    hashTable.remove(20);

    // Displaying the hash table
    hashTable.display();

    return 0;
}

