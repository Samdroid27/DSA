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

Node* find(Node* root,int val){
	if(!root) return NULL;
	if(root->data == val) return root;
	Node* left = find(root->left,val);
	Node* right = find(root->right,val);
	return left?left:right;
}

void insertNewNode(vector<int> &a, int p,int child, char pos,Node* root){
	Node* node = new Node(a[child]);
	Node* parent = find(root,a[p]);
	if(pos=='L') parent->left = node;
	else parent->right = node;
}

void preorder(Node* root,vector<int> &A){
	if(!root) return ;
	A.push_back(root->data);
	preorder(root->left,A);
	preorder(root->right,A);
}

i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	Node* root = new Node(a[0]);
	for(int i=0;i<n-1;i++){
		int p,c;
		char pos;
		cin>>p>>c;
		cin>>pos;
		insertNewNode(a,p,c,pos,root);
	}
	vector<int> ans;
	preorder(root,ans);
	for(int i:ans) cout<<i<<sep;
	cout<<endl;
	return 0;
}
