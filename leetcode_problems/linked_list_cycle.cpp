#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast !=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    // Create a sample linked list with a cycle
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Create the cycle

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "The linked list has a cycle!" << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
