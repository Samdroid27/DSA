#include<bits/stdc++.h> 
using namespace std;

const int N = 1e9+7;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node* root,vector<int> &A){
	if(!root) return ans;
	A.push_back(A->data);
	preorder(root->left,A);
	preorder(root->right,A);
}

void postorder(Node* root,vector<int> &A){
	if(!root) return ans;
	preorder(root->left,A);
	preorder(root->right,A);
	A.push_back(A->data);
}

void inorder(Node* root,vector<int> &A){
	if(!root) return ans;
	preorder(root->left,A);
	A.push_back(A->data);
	preorder(root->right,A);
}

int solve(vector<int> &A,vector<int> &B,vector<int> &C){
	int ans=0;
	for(int i=0;i<A.size();i++){
		int k = A[i]-B[i];
		k *= C[i];
		ans += k%mod;
		ans = ans%mod;
	}
	return ans;
}





