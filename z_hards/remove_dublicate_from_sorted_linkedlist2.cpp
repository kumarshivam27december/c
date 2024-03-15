/*
//wrong approach
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }

    vector<int> v;
    ListNode* temp =head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->val == temp->next->val){
            temp = temp->next;
        }else{
            v.push_back(temp->val);
            // cout<<temp->val<<" ";
        }
        temp=temp->next;
    }

    ListNode* ans = NULL;
    ListNode* tail = NULL;

    while (!v.empty()) {
        if (ans == NULL) {
            ans = new ListNode(v[0]);
            tail = ans;
        } else {
            tail->next = new ListNode(v[0]);
            tail = tail->next;
        }
        v.erase(v.begin());
    }

    return ans;


}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Create a sample linked list with duplicates
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    // head->next->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next->next->next= new ListNode(6);
    // head->next->next->next->next->next->next->next->next->next  = new ListNode(9);
    // head->next->next->next->next->next->next->next->next->next->next  = new ListNode(10);


    cout << "Original list: ";
    printList(head);

    head = deleteDuplicates(head); // Remove duplicates

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}


*/