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
	public :int data;
	Node* next=NULL;
	Node* prev=NULL;
};

Node* pushNewNode(Node* head,Node* node,int n){
	Node* nnode= new Node();
	nnode->prev = node;
	node->next = nnode;
	nnode->data = n;
	nnode->next = head;
	head->prev=nnode;
	return nnode;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	string reg;
	cin>>reg;
	int n;
	cin>>n;
	Node* head=new Node();
	Node* end= head;
	for(int i=0;i<sz(reg);i++){
		if(i==0)	head->data= reg[i]-'0';
		else{
			Node* nxt=pushNewNode(head,end,reg[i]-'0');
			end=nxt;
		}	
	}
	while(n--){
		string tsk;
		cin>>tsk;
		if(tsk=="LS"){
			head->data = 0;
			head=head->next;
			end=end->next;
		}
		else if(tsk=="RS"){
			end->data = 0;
			end=end->prev;
			head=head->prev;
		}
		else if(tsk=="LR"){
			head=head->next;
			end=end->next;
		}
		else if(tsk=="RR"){
			head=head->prev;
			end=end->prev;
		}
		else if(tsk=="INC"){
			Node* pt= end;
			while(pt->data != 0 && pt != head) {
				pt->data = 0;
				pt= pt->prev;
			}
			pt->data = !pt->data;
		}
		else if(tsk == "DEC"){
			Node* pt = end;
			while(pt->data == 0 && pt!= head){
				pt->data = 1;
				pt=pt->prev;
			}
			pt->data = !pt->data; 
		}
	}
	for(int i=0;i<sz(reg);i++){
		cout<<head->data;
		head=head->next;
	}
	return 0;
}		