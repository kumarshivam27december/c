/*

linked list is a dynamic data structute
it can be changed at run time size->  grow/shrink
less memory wastage
no shifting needed in insertion or deletion unlike array
it is collection of various nodes
each nodes constituetes of a data and next data address



singly linked list
doubly linked list
circular linked list
circular  doubly linked list

*/

#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(node* &head,int data)
{
    //create a new node
    node* temp = new node(data);
    temp->next= head;
    head=temp;  
}
void insertatend(node* &tail,int data)
{
    //create a new node
    node* temp = new node(data);
    
    tail->next=temp;
    tail=temp;//or you can do tail = tail->next;

}
void insertatposition(node* &head,int position,int data)
{

    node* temp = head;
    int cnt = 1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    node* nodetoinsert = new node(data);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

}
void print(node* &head){
    node* temp1 = head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }cout<<endl;
}
int main()
{
    node* node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    node* head = node1;

    node* tail = node1;
    insertathead(head,20);


    insertathead(head,20);
    insertathead(head,30);
    print(head);
    cout<<"inserting at end now"<<endl;
    insertatend(tail,40);
    insertatend(tail,50);
    insertatend(tail,60);
    print(head);
    insertatposition(head,5,100);cout<<endl;
    print(head);


    return 0;
}