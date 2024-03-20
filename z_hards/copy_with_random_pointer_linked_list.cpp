#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node *random;
    Node(int x = 0) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    void insertattail(Node* &head,Node* &tail,int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        //step 1 create the linked list
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }


        //step 2
        unordered_map<Node* , Node*> mp;
        Node* originalnode = head;
        Node* clonenode =   clonehead;
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
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        if (head->random) {
            std::cout << head->random->val;
        } else {
            std::cout << "NULL";
        }
        std::cout << std::endl;
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Sample linked list (modify as needed for your testing)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next; // Set random pointer of head to the third Node

    // Create a deep copy of the linked list
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // Print the original and copied lists
    std::cout << "Original List:" << std::endl;
    printList(head);
    std::cout << "Copied List:" << std::endl;
    printList(copiedList);

    return 0;
}
