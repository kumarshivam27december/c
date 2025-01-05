#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtTail(Node* &head, int val) {
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;

}
void insertAtHead(Node* &head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void deleteAtTail(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deleteAtHead(Node* &head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete temp;
}
void insertAtPosition(Node* &head, int position, int val) {
    if (position == 0) {
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    Node* newNode = new Node(val);
    position--;
    while (position-- && temp->next != NULL) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteAtPosition(Node* &head, int position) {
    if (position == 0) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    position--;
    while (position-- && temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    delete temp;
}
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* reverse(Node* &head) {
   Node* temp ;
   Node* curr = head;
   while(curr!=NULL){
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;  
   }
   return temp->prev;
}
Node* recursive_reverse(Node* &head) {
    if (!head || !head->next) return head;
    Node* rest = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    Node* head = NULL;
    insertAtTail(head, 10);
    printLL(head);
    insertAtTail(head, 20);
    printLL(head);
    insertAtTail(head, 30);
    printLL(head);
    insertAtTail(head, 40);
    printLL(head);
    insertAtTail(head, 50);
    printLL(head);
    insertAtHead(head, 5);
    printLL(head);
    deleteAtTail(head);
    printLL(head);
    deleteAtHead(head);
    printLL(head);
    insertAtPosition(head, 2, 25);
    printLL(head);
    deleteAtPosition(head, 2);
    printLL(head);
    cout << "Before reversing:" << endl;
    printLL(head);
    cout << "After reversing:" << endl;
    head = reverse(head);
    printLL(head);
    cout << "Middle Node: " << middleNode(head)->data << endl;
    return 0;
}
