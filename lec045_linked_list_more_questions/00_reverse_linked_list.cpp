#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next = NULL;
    }
};
void insertathead(node* &head,int data){
    node* temp = new node(data);
    temp->next=head;
    head = temp;
}
// // node* reverse(node* &head){
// //     //when it is empty or have just one element
// //     if (head==NULL || head->next==NULL)
// //     {
// //         return head;
// //     }

// //     node* prev = NULL;
// //     node* curr = head;
// //     node* forward = NULL;

// //     while (curr!=NULL)
// //     {
// //         forward = curr->next;
// //         curr->next = prev;
// //         prev = curr;
// //         curr = forward;

// //     }
    
// //     head = prev;
// //     return head;
// // }


/*
//reversing linked List alter


node* reverse(node* &head){
    //when it is empty or have just one element
    if (head==NULL || head->next==NULL)
    {
        return head;
    }

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr; 
    }

    head = prevptr;
    return head;
}
*/



node* recursivereverse(node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* newhead = recursivereverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


void print(node* &head){
    node* temp = head;
    int cnt = 1;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
    
}
int main(){
    node* node1 = new node(10);
    node* head  = node1;
    node* tail = node1;
    insertathead(head,9);
    insertathead(head,8);
    insertathead(head,7);
    insertathead(head,6);
    insertathead(head,5);
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    cout<<"Before reversal "<<endl;
    print(head);
    cout<<"after reversal "<<endl;
    head = recursivereverse(head);
    print(head);
    return 0;
}


