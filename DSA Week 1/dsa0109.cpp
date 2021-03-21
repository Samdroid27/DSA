#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define vll vector<ll>
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
 
using namespace std;
 
class Node{
	public :int data=-1;
	Node* next=NULL;
};

Node* pushNewNode(Node* node,int n){
	Node* nnode= new Node();
	node->next = nnode;
	nnode->data = n;
	return nnode;
}

Node* reverse(Node* head){
	Node* current = head;
	Node *prev = NULL, *next= NULL;

	while(current != NULL){
		next= current->next;
		current->next = prev;
		prev = current; 
		current = next;
	}
	return prev; 
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	Node* head=new Node();
	Node* end= head;
	int k;
	cin>>k;
	while(k!=-1){
		if(end->data == -1) end->data = k;
		else end=pushNewNode(end,k);
		cin>>k;
	}
	head=reverse(head);
	while(head->data != -1){
		cout<<head->data;
		cout<<endl;
		head=head->next;
	}
	return 0;
}		