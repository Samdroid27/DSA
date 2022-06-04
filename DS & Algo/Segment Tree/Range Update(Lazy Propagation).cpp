//\
Query 1 : Output the sum int the range [l,r] \
Query 2 : Increase the value of each element in the range [l,r]

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

int query(int si,int ss,int se,int qs,int qe){
	if(lazy[si]){
		int dx = lazy[si];
		lazy[si]=0;
		st[si] += dx*(se-ss+1);

		if(ss!=se) lazy[2*si] = dx, lazy[(2*si)+1]=dx;
	}
	if(qs>se || qe<ss) return 0;
	if(qs<=ss && qe>=se){
		return st[si];
	}
	int mid = ss + (se-ss)/2;
	int leftq = query((2*si),ss,mid,qs,qe);
	int rightq = query((2*si)+1,mid+1,se,qs,qe);
	return leftq+rightq;
}

void update(int si,int ss,int se,int qs,int qe,int val){
	if(lazy[si]){
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx*(se-ss+1);
		if(ss!=se) lazy[2*si] = dx, lazy[(2*si)+1]=dx;
	}
	if(qs>se || qe<ss) return ;
	if(qs<=ss && qe>=se){
		int dx = (se-ss+1)*val;
		st[si] += val;
		if(ss!=se) lazy[2*si] = val, lazy[(2*si)+1]=val;
		return;
	}
	int mid = ss + (se-ss)/2;
	update(2*si,ss,mid,qs,qe,val);
	update((2*si)+1,mid+1,se,qs,qe,val);
	st[si] = st[2*si]+st[(2*si)+1];
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
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}else{
			int l,r,val;
			cin>>l>>r>>val;
			update(1,1,n,l,r,val);
		}
	}
}