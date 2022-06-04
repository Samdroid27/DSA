// \
Query 1 : Replace i-th element in the array with integer x. \
Query 2 : Replace each element in the array with integer x. \
Output : calculate the sum of all elements in the array after performing each query.

#include<bits/stdc++.h>
#define int long long
 
const int N = 2e5+1;
int a[N],st[4*N],lazy[4*N];
 
using namespace std;
 
void build(int si,int ss,int se){
	if(ss==se){
		st[si]=a[ss];
		return;
	} 
	int mid = ss + (se-ss)/2;
	build((2*si),ss,mid);
	build((2*si)+1,mid+1,se);
	st[si]=st[2*si]+st[(2*si)+1];
}
 
int query(int si,int ss,int se,int ind,int val){
	if(lazy[si]){
		int dx = lazy[si];
		lazy[si]=0;
		st[si] = dx*(se-ss+1);
		if(ss!=se) lazy[2*si] = dx, lazy[(2*si)+1]=dx;
	}
	if(ind>se || ind<ss) return st[si];
	if(ind==ss && ind==se){
		return st[si]=val;
	}
	int mid = ss + (se-ss)/2;
	int leftq = query((2*si),ss,mid,ind,val);
	int rightq = query((2*si)+1,mid+1,se,ind,val);
	return st[si]=leftq+rightq;
}
 
signed main() {
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	memset(lazy,0,sizeof(lazy));
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int ind,val;
			cin>>ind>>val;
			cout<<query(1,1,n,ind,val)<<endl;
		}else{
			int x;
			cin>>x;
			lazy[1]=x;
			cout<<n*x<<endl;
		}
	}
}