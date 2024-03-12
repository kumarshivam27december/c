#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head=temp;
}
void insertAttail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtposition(Node* &head,int pos,int d){
    Node* temp = head;
    int cnt = 0;
    Node* traverse = head;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(100);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    Node* head = node1; 
    Node* tail = node1;
    insertAthead(head,10);
    insertAthead(head,20);
    print(head);
    insertAttail(tail,30);
    insertAttail(tail,40);
    print(head);
    insertAtposition(head,2,50);
    insertAtposition(head,3,60);
    insertAtposition(head,4,70);
    print(head);

    return 0;
}