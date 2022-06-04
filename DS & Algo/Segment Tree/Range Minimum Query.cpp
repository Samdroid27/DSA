#include <bits/stdc++.h>
using namespace std;

int a[100001],st[400004];

void buildSegmentTree(int si,int ss,int se){
	if(ss==se){
		st[si]=a[ss];   //leaf node
		return; 
	} 
	int mid = ss + (se-ss)/2;

	buildSegmentTree(2*si,ss,mid);
	buildSegmentTree((2*si)+1,mid+1,se);

	st[si]=min(st[2*si],st[(2*si)+1]);
}

int query(int si,int ss,int se,int l,int r){
	if(l>se || r<ss) return INT_MAX;
	if(l<=ss && r>=se) return st[si];

	int mid = ss + (se-ss)/2;

	int leftq = query(2*si,ss,mid,l,r);
	int rightq = query((2*si)+1,mid+1,se,l,r);

	return min(leftq,rightq);

}

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	buildSegmentTree(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int ss,se;
		cin>>ss>>se;
		cout<<query(1,1,n,ss+1,se+1)<<endl;
	}
	return 0;
}