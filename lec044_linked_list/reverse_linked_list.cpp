#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node *insertNode(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to reverse the linked list (this is the function you need to implement)
Node *reverseList(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }

    Node* previous = NULL;
    Node* current = head;
    while(current != NULL){
        Node* forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    head = previous;

    return head;
}

int main()
{
    Node *head = nullptr; // Initially empty list

    // Create some nodes and insert them into the list
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head); // Call the function to reverse the list

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
