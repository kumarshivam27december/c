// #include <iostream>
// #include <unordered_map>

// class LRUCache {
// private:
//     class node {
//     public:
//         int key;
//         int val;
//         node* next;
//         node* prev;
//         node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
//     };

//     node* head;
//     node* tail;
//     int cap;
//     std::unordered_map<int, node*> m;

// public:
//     LRUCache(int capacity) : cap(capacity) {
//         head = new node(-1, -1);
//         tail = new node(-1, -1);
//         head->next = tail;
//         tail->prev = head;
//     }

//     void addnode(node* newnode) {
//         node* temp = head->next;
//         newnode->next = temp;
//         newnode->prev = head;
//         head->next = newnode;
//         temp->prev = newnode;
//     }

//     void deletenode(node* delnode) {
//         node* delprev = delnode->prev;
//         node* delnext = delnode->next;
//         delprev->next = delnext;
//         delnext->prev = delprev;
//         delete delnode;
//     }

//     int get(int key_) {
//         if (m.find(key_) != m.end()) {
//             node* resnode = m[key_];
//             int res = resnode->val;
//             m.erase(key_);
//             deletenode(resnode);
//             addnode(resnode);
//             m[key_] = head->next;
//             return res;
//         }
//         return -1;
//     }

//     void put(int key_, int value) {
//         if (m.find(key_) != m.end()) {
//             node* existingnode = m[key_];
//             m.erase(key_);
//             deletenode(existingnode);
//             existingnode->val = value;
//             m[key_] = existingnode;
//         } else if (m.size() == cap) {
//             m.erase(tail->prev->key);
//             deletenode(tail->prev);
//         }
//         addnode(new node(key_, value));
//         m[key_] = head->next;
//     }

//     void printCache() {
//         node* curr = head->next;
//         std::cout << "Cache: ";
//         while (curr != tail) {
//             std::cout << "(" << curr->key << ", " << curr->val << ") -> ";
//             curr = curr->next;
//         }
//         std::cout << "NULL" << std::endl;
//     }
// };

// int main() {
//     LRUCache cache(2);

//     cache.put(1, 1);
//     cache.printCache(); // Output: Cache: (1, 1) -> NULL

//     cache.put(2, 2);
//     cache.printCache(); // Output: Cache: (2, 2) -> (1, 1) -> NULL

//     int value = cache.get(1);
//     std::cout << "Value of key 1: " << value << std::endl; // Output: Value of key 1: 1

//     cache.put(3, 3);
//     cache.printCache(); // Output: Cache: (3, 3) -> (2, 2) -> NULL (Least recently used item (1) is evicted)

//     return 0;
// }






#include <iostream>  // Header file for input/output operations (cout, endl)
#include <unordered_map>  // Header file for the unordered_map container (used for efficient key-value lookup)

class LRUCache {
private:
    class node {  // Inner class to represent a node in the doubly linked list
    public:
        int key;        // Integer variable to store the key associated with the node
        int val;        // Integer variable to store the value associated with the node
        node* next;     // Pointer to the next node in the doubly linked list
        node* prev;     // Pointer to the previous node in the doubly linked list
        node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}  // Constructor for the node class with initialization list
    };

    node* head;  // Pointer to the head node of the doubly linked list (sentinel node)
    node* tail;  // Pointer to the tail node of the doubly linked list (sentinel node)
    int cap;     // Integer variable storing the maximum capacity of the cache
    std::unordered_map<int, node*> m;  // Unordered map to store key-value pair associations for quick lookups

public:
    LRUCache(int capacity) : cap(capacity) {  // Constructor for the LRUCache class
        head = new node(-1, -1);  // Allocate memory for the head node with default values
        tail = new node(-1, -1);  // Allocate memory for the tail node with default values
        head->next = tail;      // Initialize an empty doubly linked list (head -> tail)
        tail->prev = head;
    }

    void addnode(node* newnode) {  // Function to add a new node to the beginning of the list
        node* temp = head->next;  // Temporary pointer to the current head's next node
        newnode->next = temp;     // Set new node's next pointer to the current head's next node
        newnode->prev = head;     // Set new node's prev pointer to the head node
        head->next = newnode;     // Update head's next pointer to point to the new node
        temp->prev = newnode;     // Update the previous head's next node's prev pointer to point to the new node
    }

    void deletenode(node* delnode) {  // Function to delete a node from the list
        node* delprev = delnode->prev;  // Get the node before the one to be deleted
        node* delnext = delnode->next;  // Get the node after the one to be deleted
        delprev->next = delnext;      // Update the previous node's next pointer to skip the deleted node
        delnext->prev = delprev;      // Update the next node's prev pointer to point to the previous node
        delete delnode;               // Deallocate memory associated with the deleted node (important to prevent leaks)
    }

    int get(int key_) {  // Function to retrieve the value for a given key
        if (m.find(key_) != m.end()) {  // Check if the key exists in the map
            node* resnode = m[key_];    // Get the node associated with the key from the map
            int res = resnode->val;      // Store the value from the node
            m.erase(key_);             // Remove the key-node association from the map (for later update)
            deletenode(resnode);         // Remove the node from its current position (may not be head)
            addnode(resnode);            // Add the node back to the beginning (to mark it as most recently used)
            m[key_] = head->next;       // Update the map to point to the newly added node (now at the head)
            return res;                 // Return the retrieved value
        }
        return -1;  // Key not found, return -1
    }

    void put(int key_, int value) {  // Function to insert or update a key-value pair
        if (m.find(key_) != m.end()) {  // Check if the key already exists
            node* existingnode = m[key_];  // Get the existing node associated with the key
            m.erase(key_);                 // Remove the old key-node association from the map
            deletenode(existingnode);
            existingnode->val = value;  // Update the value of the existing node
            m[key_] = existingnode;       // Update the map to point to the existing node (with the new value)
        } else if (m.size() == cap) {  // Check if cache is full
            m.erase(tail->prev->key);  // Remove the least recently used node (at tail's previous) from the map
            deletenode(tail->prev);     // Remove the least recently used node from the list
        }
        addnode(new node(key_, value));  // Create and add a new node with the key-value pair to the beginning
        m[key_] = head->next;             // Update the map to point to the newly added node (now at the head)
    }

    void printCache() {  // Function to print the contents of the cache (for testing purposes)
        node* curr = head->next;
        std::cout << "Cache: ";
        while (curr != tail) {
            std::cout << "(" << curr->key << ", " << curr->val << ") -> ";
            curr = curr->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.printCache(); // Output: Cache: (1, 1) -> NULL

    cache.put(2, 2);
    cache.printCache(); // Output: Cache: (2, 2) -> (1, 1) -> NULL

    int value = cache.get(1);
    std::cout << "Value of key 1: " << value << std::endl; // Output: Value of key 1: 1

    cache.put(3, 3);
    cache.printCache(); // Output: Cache: (3, 3) -> (2, 2) -> NULL (Least recently used item (1) is evicted)

    return 0;
}
