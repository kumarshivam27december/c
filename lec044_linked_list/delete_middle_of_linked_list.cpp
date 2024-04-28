#include <bits/stdc++.h>
using namespace std;

// Structure for a node in the linked list
struct Node {
  int data;
  Node* next;
};

// Function to create a new node
Node* newNode(int data) {
  Node* new_node = new Node;
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to print the contents of the linked list
void printList(Node* head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Function to find the middle node (already provided)
int getmid(Node* head) {
  int count = 0;
  while (head != NULL) {
    head = head->next;
    count++;
  }
  return floor((count) / 2.0);
}

// Function to delete the middle node (already provided)
Node* deleteMid(Node* head) {
  if (head == NULL || head->next == NULL) {
    // Handle empty or single-node list (avoid accessing head->next)
    return NULL;
  }
  int k = getmid(head) - 1;
  Node* temp = head;
  while (k--) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  return head;
}

// Main function to create a sample linked list, delete the middle node, and print the modified list
int main() {
  // Create sample linked list
  Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  cout << "Original list: ";
  printList(head);

  // Delete middle node
  head = deleteMid(head);

  cout << "List after deleting middle node: ";
  printList(head);

  return 0;
}
