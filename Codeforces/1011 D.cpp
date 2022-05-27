#include<bits/stdc++.h>
 
using namespace std;

int query(int a){
	cout<<a<<endl;
	fflush(stdout);
	int t;
	cin>>t;
	if(t==0 || t==-2) exit(0);
	return t;
}
 
signed main() {
	int m,n;
	cin>>m>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		int t = query(1);
		a[i] = (t==1);
	}
	int l = 2, r = m;
	for(int q = 0;; q++){
		int mid = l + (r-l)/2;
		int t = query(mid);
		if(!a[q%n]) t *= -1;
		if(t==1) l = mid+1;
		else r = mid-1; 
	}
	
}