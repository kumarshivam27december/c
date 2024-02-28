#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* current = head;
    while (current != NULL) {
        Node* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
    return head;
}

int main() {
    Node* head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);

    cout << "Original Doubly Linked List: ";
    printList(head);

    cout << "Reversed Doubly Linked List: ";
    head = reverseList(head);
    printList(head);

    return 0;
}
