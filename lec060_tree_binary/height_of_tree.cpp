#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    int height(struct Node* node){
        if(node==NULL) return 0;
        
        int lh = height(node->left);
        int rh = height(node->right);
        
        return max(lh,rh)+1;
    }
};
int main(){
    return 0;
}

