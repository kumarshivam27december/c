#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    //constructor
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    } 
    //destructor
    ~node()
    {
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free of the data "<<value<<endl;
    }
};
void print(node* &head){
    node* temp= head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}
int getlength(node* &head){
    node* temp = head;
    int len  = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(node* &head,node* &tail,int data){
    if(head == NULL){
        node* temp = head;
        head = temp;
    }
    else{
    node* temp = new node(data);
    temp->next =  head;
    head->prev = temp;
    head = temp;
    }
}
void insertattail(node* &head,node* &tail,int data){
    if(tail==NULL)
    {
        node* temp = tail;
        tail = temp;
    }else{
    node* temp = new node(data);
    tail->next=temp;
    temp->prev = tail;
    tail = temp;
    }
}
void insertatpos(node* &head,node* &tail,int position,int data){
    //starting case
    if (position==1)
    {
        insertathead(head,tail,data);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    
    node* nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev=temp;
    //inserting at last position
    if(temp-> next ==NULL){
        insertattail(head,tail,data);
        return;
    }
}
void deletionathead(node* &head){
    node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

// void deletionattail(node* &head,node* &tail){
//     node* temp = head;
   
//     node* curr = head;
//     node* prev = NULL;
//      /*int cnt = 1;
//     while(temp->next != NULL){
//         cnt++;
//         temp = temp->next;
//     }
//     temp->prev->next = NULL;
//     tail=temp;*/

//     delete temp;
// }

void deletionatposition(node* head,int position){
    node* curr = head;
    node* prev = NULL;
    int cnt = 1;
    while(cnt<position){
        prev= curr;
        curr = curr->next;
        cnt++;
        
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next=NULL;
    delete curr;
}
int main()
{
    node* node1 = new node(10);
    node* head  = node1;
    node* tail  = node1;

    insertathead(head,tail,11);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    insertathead(head,tail,21);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    insertattail(head,tail,2);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    insertattail(head,tail,69);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    insertatpos(head,tail,1,100);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    insertatpos(head,tail,6,111);
    print(head);
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;


    cout<<"length of the linked list is -> "<<getlength(head)<<endl;
    
    
    cout<<"after deletion"<<endl;
    deletionathead(head);
    print(head);
    
    cout<<"after deletion at end"<<endl;
    deletionatposition(head,4);
    print(head);
    cout<<"tail of this is -> "<<tail->data<<endl;
    
    cout<<"length of the linked list is -> "<<getlength(head)<<endl;

    return 0;
}

