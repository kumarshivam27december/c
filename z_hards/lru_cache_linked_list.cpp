#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
  class node {
  public:
    int key;
    int val;
    node *next;
    node *prev;
    node(int _key, int _val) {
      key = _key;
      val = _val;
    }
  };

  node *head = new node(-1, -1);
  node *tail = new node(-1, -1);

  int cap;
  unordered_map<int, node*> m;

  LRUCache(int capacity) {
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }

  void addnode(node* newnode) {
    node* temp = head->next;
    newnode->next = temp;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;
  }

  void deletenode(node* delnode) {
    node* delprev = delnode->prev;
    node* delnext = delnode->next;
    delprev->next = delnext;
    delnext->prev = delprev;
    delete delnode; // Added deletion of the node object
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node* resnode = m[key_];
      int res = resnode->val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head->next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node* existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
      existingnode->val = value; // Update value for existing node
    } else if (m.size() == cap) {
      m.erase(tail->prev->key);
      deletenode(tail->prev);
    }

    addnode(new node(key_, value));
    m[key_] = head->next;
  }

  // Function to print the contents of the cache (for testing purposes)
  void printCache() {
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