#include <iostream>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }

};

node* insertion(node* root,int key){
    if(root==NULL){
        return new node(key);
    }
    
    if(root->val > key){
        root->left =  insertion(root->left,key);
    }else{
        root->right =  insertion(root->right,key);
    }

    return root;
}
node* inordersucc(node* root){
    node* curr = root;
    while(curr && curr->left !=NULL){
        curr = curr->left;
    }

    return curr;
    
}
node* deletion(node* root,int key){
    if(root->val < key){
        root->right = deletion(root->right,key);
    }else if (root->val > key)
    {
        root->left = deletion(root->left,key);
    }else{
        if (root->left == NULL)
        {
           node* temp = root->right;
           free(root);
           return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = inordersucc(root->right);
        root->val = temp->val;
        root->right = deletion(root->right,temp->val);
        
    }
    return root;
    
}

node* searching(node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->val==key){
        return root;
    }
    else if(root->val>key){
        return searching(root->left,key);
    }else{
        return searching(root->right,key);
    }
    return NULL;
}



void pre(node* root){
    if(root==NULL){
        return ;
    }

    
    cout<<root->val<<" ";
    pre(root->left);
    pre(root->right);
}

void post(node* root){
    if(root==NULL){
        return ;
    }

    
    
    post(root->left);
    post(root->right);
    cout<<root->val<<" ";
}
void in(node* root){
    if(root==NULL){
        return ;
    }

    
    in(root->left);
    cout<<root->val<<" ";

    in(root->right);
}
int main(){
    node* root = NULL;
    int a;cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }

    root = insertion(root,arr[0]);
    for(int i=1;i<a;i++){
        insertion(root,arr[i]);
    }

    
    pre(root);cout<<endl;post(root);cout<<endl;in(root);cout<<endl;
    int pos;cin>>pos;
    if(searching(root,pos)){
        cout<<"yes";
    }else{
        cout<<"no";
    }

    


    cout<<endl;
    int b;cin>>b;
    deletion(root,b);
    
    if(searching(root,b)){
        cout<<"yes";
    }else{
        cout<<"no";
    }

    return 0;
}