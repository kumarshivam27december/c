#include  <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};
void pre(node* root){
    if (root==NULL)
    {
        return;
    }
    
    pre(root->left);
    cout<<root->data<<" ";
    pre(root->right);
}

node* search(node* root,int key){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
       return root;
    }
    if (root->data < key)
    {
     return search(root->right,key);
    }
    if (root->data > key)
    {
       return  search(root->left,key);
    }
    return NULL; 
}
node*  insertion(node* root,int key){
    if (root==NULL)
    {
       return new node(key);
    }

    if (root->data > key )
    {
       root->left = insertion(root->left,key);
    }

    if (root->data < key)
    {
        root->right = insertion(root->right,key);
    }
    
   return root; 
       
}
node* inordersucc(node* root){
    node* curr = root;
    while (curr && curr->left !=NULL)
    {
       curr = curr->left;
    }

    return curr;
    
}

node* deletion(node* root,int key){
    if (root->data > key)
    {
        root->left = deletion(root->left,key);
    }
    else if (root->data < key)
    {
        root->right = deletion(root->right,key);
    }
    else{
        if (root->left==NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inordersucc(root);
        root->data = temp->data;
        root->right = deletion(root->right,temp->data);
        
    }

    return root;
    
}
int main(){
	node* root  = NULL;
	root = insertion(root,1);
	insertion(root,3);
	insertion(root,4);
	insertion(root,5);
	insertion(root,2);
	
    if (search(root,4)==NULL)
    {
       cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }
    

	pre(root);
	
	cout<<endl;
	cout<<"After deletion"<<endl;
	deletion(root,4);
	
	
	pre(root);

	cout<<endl;
    if (search(root,4)==NULL)
    {
       cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }
    
	
	return 0;
	
	
}