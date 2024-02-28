#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        this->data=val;
        this->next=NULL;
    }
};
void print(node* &head){
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertathead(node* &head,int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;

}
void insertattail(node* &tail,int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;

}
void insertatposition(node* &head,node* &tail,int position,int data){
    
}
int main(){
    node* node1 = new node(10);
    // cout<<node1->data<<" ";
    node* head = node1;
    node* tail = node1; 
    insertathead(head,20);
    insertathead(head,40);
    insertathead(head,50);
    insertathead(head,60);
    insertathead(head,70);
    insertathead(head,80);
    print(head);
    cout<<"Now inserting at end\n";
    insertattail(tail,20);
    insertattail(tail,40);
    insertattail(tail,50);
    insertattail(tail,60);
    insertattail(tail,70);
    insertattail(tail,80);
    print(head);

    return 0;
}