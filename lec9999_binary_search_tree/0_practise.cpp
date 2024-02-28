#include <iostream>
using namespace std;
struct node{
	int data;
    node* left;
    node* right;
	node(int val){
		data = val;
	    left  = NULL;
		right = NULL;
	}
};
void pre(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	pre(root->left);
	pre(root->right);

	
}
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	
}
void post(node* root){
	if(root==NULL){
		return;
	}
	post(root->left);
	post(root->right);
	cout<<root->data<<" ";
	
}
node* search(node* root,int key){
	//base case
	if(root==NULL){
		return NULL;
	}
	
	
	if(root->data == key){
		return root;
	}
	
	if(root->data > key){
		return search(root->left,key);
	}
	else if(root->data < key){
		return search(root->right,key);
	}

    return NULL;
}
node* insert(node* root,int val){
	
	if(root==NULL){
		return new node(val);
	}
	
	if(val<root->data){
		root->left = insert(root->left,val);
	}
	
	if(val>root->data){
		root->right = insert(root->right,val);
	}
	
	return root;
	
}
node* inordersucc(node* root){
	node* curr = root;
	while(curr && curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}
node* deletion(node* root,int key){
	
	if(key<root->data){
		root->left = deletion(root->left,key);
	}
	else if(key > root->data){
		root->right = deletion(root->right,key);
	}
	else{
		
		if(root->left == NULL){
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			node* temp = root->left;
			free(root);
			return temp;
		}
		//case 3
		node* temp = inordersucc(root);
		root->data = temp->data;
		root->right = deletion(root->right,temp->data);
	}
	
	return root;
}
int main(){
	node* root  = NULL;
	root = insert(root,1);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,2);
	
    if (search(root,4)==NULL)
    {
       cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }
    

	pre(root);
	cout<<endl;
	post(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	
	deletion(root,4);
	cout<<"After deletion"<<endl;
	
	pre(root);
	cout<<endl;
	post(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
    if (search(root,4)==NULL)
    {
       cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }
    
	
	return 0;
	
	
}