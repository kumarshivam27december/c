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
void insertAtTail(Node* &head,int val){
    Node* temp = new Node(val);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* dummy = head;
    while(dummy->next!=NULL){
        dummy = dummy->next;
    }
    dummy->next = temp;
}
void insertAtHead(Node* &head,int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}
void deleteAtTail(Node* &head){
    if(head==NULL) return;
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
void deleteAtHead(Node* &head){
   if(head==NULL){
    return;
   }
   head = head->next;
}
void insertAtPosition(Node* &head,int position,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    Node* temp = head;
    Node* n = new Node(val);
    position-=1;
    while(position--){
        temp = temp->next;
    }
    Node* newvar = temp->next;
    temp->next = n;
    n->next = newvar;
    
}
void deleteAtPosition(Node* &head,int position){
    if(position==0){
        head = head->next;
        return;
    }
    Node* temp = head;
    position-=1;
    while(position--){
        temp = temp->next;
    }

    temp->next = temp->next->next;
}
void deleteByNumber(){

}
void printLL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void reverse(){

}
void detect_cycle(){

}
int main(){
    Node* head = NULL;
    insertAtTail(head,10);
    printLL(head);
    cout<<endl;
    insertAtTail(head,20);
    printLL(head);
    cout<<endl;
    insertAtTail(head,30);
    printLL(head);
    cout<<endl;
    insertAtTail(head,60);
    printLL(head);
    cout<<endl;
    insertAtTail(head,70);
    printLL(head);
    cout<<endl;
    insertAtTail(head,80);
    printLL(head);
    cout<<endl;
    insertAtHead(head,40);
    printLL(head);
    cout<<endl;
    insertAtHead(head,50);
    printLL(head);
    cout<<endl;
    deleteAtTail(head);
    printLL(head);
    cout<<endl;
    deleteAtHead(head);
    printLL(head);
    cout<<endl;
    insertAtPosition(head,2,100);
    printLL(head);
    cout<<endl;
    deleteAtPosition(head,2);
    printLL(head);
    cout<<endl;
    deleteAtPosition(head,0);
    printLL(head);
    cout<<endl;
}