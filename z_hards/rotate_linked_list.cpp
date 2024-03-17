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
    int len(ListNode* head) {
        if (head == nullptr) {
            return 0;
        }
        ListNode* temp = head;
        if (temp->next == nullptr) {
            return 1;
        }
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotate_list(ListNode* head, int n) {
        int sizeoflist = len(head); // Calculate list size for now (could be optimized)
        int m = n%sizeoflist;


        //breaking point

        int breakingpoint = sizeoflist-m-1;

        //find the tail pointer
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail=tail->next;
        }


        //create a temp node to break the node
       
        ListNode* temp = head;
        for(int i =0;i<breakingpoint;i++){
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;

        tail->next = head;
        return ans;
        
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
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    int n = 4; // Remove the node n times
    cout << "Original list: ";
    printList(head);
    cout<<endl;
    Solution sol;
    head = sol.rotate_list(head, n);

    // Print the modified list
    cout << "Modified list: ";
    printList(head);
    cout<<endl;

    return 0;
}
