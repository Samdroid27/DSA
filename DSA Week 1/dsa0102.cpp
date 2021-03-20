#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define i32 int32_t
 
using namespace std;
 
class Node{
public:
	char data;
	Node* next=NULL;
	Node* prev=NULL;
};


Node* dll(Node* root,int t){

	for(int i=0;i<t;i++){
		char c;
		cin>>c;
		root->data =c;
		if(i<t-1){
			Node* pal=new Node();
			root->next=pal;
			pal->prev = root;
			root=root->next;
		}
		
	}
	return root;
	
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t;
	cin>>t;	
	Node* root=new Node();
	Node* end=dll(root,t);
	int flag=1;
	for(int i=0;i<t && flag;i++){
		if(root->data != end->data) flag=0;
		root=root->next;
		end=end->prev;
	}
	if(flag) cout<<"Palindrome"<<endl;
	else cout<<"Not Palindrome"<<endl;

	return 0;
}