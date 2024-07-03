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
    map<int,Node*>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(q.size()>0){
        int sz = q.size();
        for(int  i = 0;i<sz;i++){
            Node* curr = q.front().first;
            int ind = q.front().second;
            q.pop();
            if(curr->left) q.push({curr->left,ind-1});
            if(curr->right) q.push({curr->right,ind+1});
            if(mp.find(ind)==mp.end()){
                mp[ind]= curr;
            }

        }
    }
    vector<int> ans;
    for(auto itr:mp){
        ans.push_back(itr.second->data);
    }


    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

}


void bottomview(Node* root){
    
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

