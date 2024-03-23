#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle empty lists
        if (list1 == nullptr || list2 == nullptr) {
            return list1 ? list1 : list2; // Return the non-empty list
        }

        // Create a dummy node to store the head of the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Merge lists iteratively
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining elements of the non-empty list
        tail->next = list1 ? list1 : list2;

        // Return the head of the merged list (skipping the dummy node)
        return dummy->next;
    }
};

// Function to print the linked list (optional)
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create sample linked lists (modify as needed)
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Create a Solution object
    Solution sol;

    // Merge the linked lists
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    // Print the merged list (optional)
    cout << "Merged list:" << endl;
    printList(mergedList);

    return 0;
}
