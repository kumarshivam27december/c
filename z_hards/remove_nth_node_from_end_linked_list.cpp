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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sizeoflist = len(head); // Calculate list size for now (could be optimized)
        int nodetodelete = sizeoflist - n;
        int k = nodetodelete;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        if (k == 0) {
            return dummy->next->next;
        }
        while (k--) {
            temp = temp->next;
        }
        if (temp->next) {
            temp->next = temp->next->next;
        }

        return dummy->next;
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
    head = sol.removeNthFromEnd(head, n);

    // Print the modified list
    cout << "Modified list: ";
    printList(head);
    cout<<endl;

    return 0;
}
