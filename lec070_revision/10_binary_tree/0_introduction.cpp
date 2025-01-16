#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* insertTreeNode(TreeNode* &root,int key){
    if(root==NULL){
        return new TreeNode(key);
    }
    if(root->data > key){
        root->left = insertTreeNode(root->left,key);
    }else{
        root->right = insertTreeNode(root->right,key);
    }
    return root;
}
void pre_order_print_recursive(TreeNode* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre_order_print_recursive(root->left);
    pre_order_print_recursive(root->right);
}
vector<int> pre_order_print_iterative(TreeNode* &root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<TreeNode*>stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* elem = stk.top();
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
void post_order_print_recursive(TreeNode* &root){
    if(root==NULL){
        return;
    }
    post_order_print_recursive(root->left);
    post_order_print_recursive(root->right);
    cout<<root->data<<" ";
}
vector<int> post_order_print_iterative(TreeNode* &root){
  vector<int>ans;
  stack<TreeNode*> stk1;
  stack<TreeNode*> stk2;
  stk1.push(root);
  while(!stk1.empty()){
    TreeNode* current = stk1.top();
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
vector<int> post_order_single_stack_iterative(TreeNode* &root){
    vector<int>ans;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    while(current!=NULL or !stk.empty()){
        if(current!=NULL){
            stk.push(current);
            current = current->left;
        }else{
            TreeNode* temp = stk.top()->right;
            if(temp==NULL){
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->data);
                while(!stk.empty() && temp==stk.top()->right){
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->data);
                }
            }else{
                current = temp;
            }
        }
    }
    return ans;
}
void in_order_print_recursive(TreeNode* &root){
    if(root==NULL){
        return;
    }
    in_order_print_recursive(root->left);
    cout<<root->data<<" ";
    in_order_print_recursive(root->right);
}
vector<int> in_order_print_iterative(TreeNode* &root){
    vector<int>ans;
    stack<TreeNode*>stk;
    TreeNode* current = root;
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
vector<vector<int>> level_order_traversal(TreeNode* &root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>qu;
    qu.push(root);
    while(!qu.empty()){
       vector<int>level;
       int k = qu.size();
       for(int i = 0;i<k;i++){
           TreeNode* elem = qu.front();
           qu.pop();
           level.push_back(elem->data);
           if(elem->left!=NULL){
            qu.push(elem->left);
           }
           if(elem->right!=NULL){
            qu.push(elem->right);
           }
       }
       ans.push_back(level);
    }
    return ans;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
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
    cout<<"Iterative Post order traversal using one stack"<<endl;
    vector<int>ans4 = post_order_single_stack_iterative(root);
    vector<int>::iterator itttt;
    for(itttt=ans4.begin();itttt!=ans4.end();++itttt){
        cout<<(*itttt)<<" ";
    }cout<<endl;
    cout<<"The level order traversal is "<<endl;
    vector<vector<int>> ans5 = level_order_traversal(root);
    for(auto arr: ans5){
        for(auto i : arr){
            cout<<i<<" ";
        }cout<<endl;
    }
    cout<<endl;
    return 0;
}