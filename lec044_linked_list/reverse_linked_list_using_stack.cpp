#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
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
Node *reverseList(Node *head)
{
    if(head==NULL ||head->next==NULL){
        return head;
    }

    stack<int> stk;
    Node* temp = head;
    while(temp!=NULL){
        stk.push(temp->data);
        temp=temp->next;
    }

    Node* reverelist = createNode(stk.top());
    Node* ptr = reverelist;
    while(!stk.empty()){
        ptr->next = createNode(stk.top());
        stk.pop();
        ptr=ptr->next;
    }

    return reverelist->next;
}

int main()
{
    Node *head = nullptr;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    cout << "Original list: ";
    printList(head);
    head = reverseList(head); 
    cout << "Reversed list: ";
    printList(head);
    return 0;
}
