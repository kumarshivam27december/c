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
void printLL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* reverse(Node* &head){
    Node* previous = NULL;
    Node* current = head;
    Node* nextnode;
    while(current!=NULL){
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    return previous;
}
Node* recursive_reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* nextnode = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return nextnode;
}
bool detect_cycle(Node* &head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
    
}
bool detect_cycle_2(Node* &head){
    unordered_set<Node*> st;
        while(head){
            if(st.find(head)!=st.end()){
                return true;
            }
            st.insert(head);
            head= head->next;
        }
        return false;
    
}
Node* detect_cycle3(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node* detectFirstNode(Node* &head){
    Node* meet = detect_cycle3(head);
    Node* start = head;
    while(start!=meet){
        start = start->next;
        meet = meet->next;
    }
    return start;
}
Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next){
            slow  = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    cout<<"Before reversing"<<endl;
    printLL(head);
    cout<<endl;
    cout<<"After reversing"<<endl;
    head = reverse(head);
    printLL(head);
    cout<<endl;
    cout<<"Reverse Recursion"<<endl;
    head = recursive_reverse(head);
    printLL(head);
    cout<<endl;
}