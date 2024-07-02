#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

struct QueueObj{
	Node* node;
	int hd;
	QueueObj(Node *node, int hd){
		this->node = node;
		this->hd = hd;
	}
};

void topView(Node* root){
    
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->left->right->right = new Node(5);
	root->left->right->right->right = new Node(6);
	cout<<"Following are nodes in top view of Binary Tree"<<endl;
	topView(root);
	return 0;
}

