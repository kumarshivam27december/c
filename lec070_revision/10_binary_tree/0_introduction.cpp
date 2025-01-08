#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertNode(Node* &root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(root->data > key){
        root->left = insertNode(root->left,key);
    }else{
        root->right = insertNode(root->right,key);
    }
    return root;
}
void pre_order_print_recursive(Node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre_order_print_recursive(root->left);
    pre_order_print_recursive(root->right);
}
vector<int> pre_order_print_iterative(Node* &root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<Node*>stk;
    stk.push(root);
    while(!stk.empty()){
        Node* elem = stk.top();
        stk.pop();
        ans.push_back(elem->data);
        if(elem->right!=NULL){
            stk.push(elem->right);
        }
        if(elem->left!=NULL){
            stk.push(elem->left);
        }
    }
    
    return ans;
}
void post_order_print_recursive(Node* &root){
    if(root==NULL){
        return;
    }
    post_order_print_recursive(root->left);
    post_order_print_recursive(root->right);
    cout<<root->data<<" ";
}
vector<int> post_order_print_iterative(Node* &root){
  vector<int>ans;
  stack<Node*> stk1;
  stack<Node*> stk2;
  stk1.push(root);
  while(!stk1.empty()){
    Node* current = stk1.top();
    stk1.pop();
    stk2.push(current);
    if(current->left!=NULL) {stk1.push(current->left);}
    if(current->right!=NULL) {stk1.push(current->right);}
  }

  while(!stk2.empty()){
    ans.push_back(stk2.top()->data);
    stk2.pop();
  }
  return ans;
}
void in_order_print_recursive(Node* &root){
    if(root==NULL){
        return;
    }
    in_order_print_recursive(root->left);
    cout<<root->data<<" ";
    in_order_print_recursive(root->right);
}
vector<int> in_order_print_iterative(Node* &root){
    vector<int>ans;
    stack<Node*>stk;
    Node* current = root;
    while(current!=NULL or !stk.empty()){
        while(current!=NULL){
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        ans.push_back(current->data);
        current = current->right;
    }
    return ans;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    pre_order_print_recursive(root);
    cout<<endl;
    post_order_print_recursive(root);
    cout<<endl;
    in_order_print_recursive(root);
    cout<<endl;
    cout<<"Iterative pre order traversal"<<endl;
    vector<int>ans = pre_order_print_iterative(root);
    vector<int>:: iterator it;
    for(it = ans.begin();it!=ans.end();++it){
        cout<<(*it)<<" ";
    }cout<<endl;
    cout<<"Iterative In order traversal"<<endl;
    vector<int>ans1 = in_order_print_iterative(root);
    vector<int>:: iterator itt;
    for(itt = ans1.begin();itt!=ans1.end();++itt){
        cout<<(*itt)<<" ";
    }cout<<endl;
    cout<<"Iterative Post order traversal using two stack"<<endl;
    vector<int>ans3 = post_order_print_iterative(root);
    vector<int>::iterator ittt;
    for(ittt=ans3.begin();ittt!=ans3.end();++ittt){
        cout<<(*ittt)<<" ";
    }cout<<endl;
    return 0;
}