#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *next;
    node *random;
    node(int x = 0) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    void insertattail(node* &head,node* &tail,int d){
        node* newNode = new node(d);
        if(head==NULL){
            head = newNode;
            tail = newNode; 
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    node* copyRandomList(node* head) {
        //step 1 create the linked list
        node* clonehead = NULL;
        node* clonetail = NULL;

        node* temp = head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }


        //step 2
        unordered_map<node* , node*> mp;// map original list with the copied list
        node* originalnode = head;
        node* clonenode =   clonehead;
        while(originalnode && clonenode){
            mp[originalnode] = clonenode;
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }



        originalnode = head;
        clonenode = clonehead;
        while(originalnode){
            clonenode->random = mp[originalnode->random];
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }

        return clonehead;


    }
};

// Function to print the linked list (for testing purposes)
void printList(node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "NULL";
        }
        cout << endl;
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Sample linked list (modify as needed for your testing)
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->random = head->next->next; // Set random pointer of head to the third node

    // Create a deep copy of the linked list
    Solution solution;
    node* copiedList = solution.copyRandomList(head);

    // Print the original and copied lists
    cout << "Original List:" << endl;
    printList(head);
    cout << "Copied List:" << endl;
    printList(copiedList);

    return 0;
}
