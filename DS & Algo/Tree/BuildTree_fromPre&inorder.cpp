#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define int long long
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
#define sep " "
 
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}


Node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx =0;
    if(start>end) return NULL;
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    int pos = search(inorder,start,end,curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);
    return node;
}

void inorderPrint(Node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->data<<sep;
    inorderPrint(root->right);
}

i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node* root =buildTree(preorder,inorder,0,4);
    inorderPrint(root);
	return 0;
}