#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val; // Using 'val' for consistency with common practice
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode *revList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = revList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
        return head;
    ListNode *prev = NULL;
    int l = 1;
    ListNode *temp = head;
    while (l < left)
    {
        prev = temp;
        temp = temp->next;
        l++;
    }
    int r = 1;
    ListNode *temp2 = head;
    while (r < right)
    {
        temp2 = temp2->next;
        r++;
    }
    ListNode *last = NULL;
    if (temp2->next)
    {
        last = temp2->next;
        temp2->next = NULL;
    }
    if (prev)
    {
        prev->next = revList(temp);
    }
    else
    {
        head = revList(temp);
    }
    temp->next = last;
    return head;
}
ListNode* createList(vector<int>& data) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : data) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    vector<int> data = {1, 2, 3, 4, 5}; // Sample data for the linked list
    ListNode* head = createList(data);  // Create the linked list

    cout << "Original list: ";
    printList(head);                   // Print the original list

    int left = 2;                       // Starting position for reversal
    int right = 4;                       // Ending position for reversal

    cout << "Reversing sublist between " << left << " and " << right << ":" << endl;

    // Call the 'reverseBetween' function to reverse the specified sublist
    head = reverseBetween(head, left, right);

    cout << "Reversed list: ";
    printList(head);                   // Print the reversed list with the sublist reversed

    return 0;
}
