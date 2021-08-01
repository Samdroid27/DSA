#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define int long long
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

int search(vector<int> &inorder,int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

Node* buildTree(vector<int> &preorder,vector<int> &inorder,int start,int end){
    if(start>end) return NULL;
    static int idx =0;
    int curr = preorder[idx++];
    Node* node = new Node(curr);
    int pos = search(inorder,start,end,curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);
    return node;
}

void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<sep;
}

i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
    int n;
    cin>>n;
    vi preorder(n),inorder(n);
    for(int i=0;i<n;i++) cin>>inorder[i];
    for(int i=0;i<n;i++) cin>>preorder[i];
    Node* root = buildTree(preorder,inorder,0,n-1);
    postOrder(root);
	return 0;
}