#include <bits/stdc++.h>
using namespace std;

// Struct for linked list nodes
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition_list(ListNode* head, int n) {
        vector<int> v1;
        vector<int> v2;
        ListNode* temp = head;
        while(temp){
           if(temp->val < n){
                if(temp->val==0){
                    v1.push_back(0);
                }else{
                v1.push_back(temp->val);
                }
            }else{
                v2.push_back(temp->val);
            }
            temp = temp->next;
        }


        
        //convert vector v1 to linked list
        
        ListNode* newhead = new ListNode(v1[0]);
        ListNode* curr = newhead;
        for(int i = 1;i<v1.size();i++){
            curr->next = new ListNode(v1[i]);
            curr= curr->next;
        }


        //convert vector v2 to linked list
        ListNode* newhead2 = new ListNode(v2[0]);
        ListNode* curr2 = newhead2;
        for(int i = 1;i<v2.size();i++){
            curr2->next = new ListNode(v2[i]);
            curr2= curr2->next;
        }

        curr->next = newhead2;

        

        

    return newhead;

       
        
    }
    

};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(2);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next = new ListNode(0);




    int n = 1; // Remove the node n times
    cout << "Original list: ";
    printList(head);
    cout<<endl;
    Solution sol;
    head = sol.partition_list(head, n);

    // Print the modified list
    cout << "Modified list: ";
    printList(head);
    cout<<endl;

    return 0;
}
