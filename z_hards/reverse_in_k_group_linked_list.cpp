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

    ListNode* reversal(ListNode* head, int n) {
       
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the second node from the end (node with value 4)
    cout << "Original list: ";
    printList(head);
    cout<<endl;
    Solution sol;
    head = sol.reversal(head, n);

    // Print the modified list
    cout << "Modified list: ";
    printList(head);
    cout<<endl;

    return 0;
}


/*

//this method will reverse every node in k group even if it is less than k then still it will reverse which  should not happen so that is not correct solution  
 if(!head) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        int cnt = 0;
        while(curr!=NULL && cnt<n){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }


        if(next!=NULL){
            head->next = reversal(next,n);
        }

        return prev;
*/