#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int n,m,k;
	cin>>n>>m>>k;
	string s,t;
	cin>>s>>t;
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++){
		if(i>=m){
			if(s.substr(i-m,m)==t) a[i]=a[i-1]+1;
			else a[i]=a[i-1];
		} 
		else a[i]=0;
	}
	while(k--){
		int x,y;
		cin>>x>>y;
		if(m>n || (y-x+1)<m){
			cout<<0<<endl;
			continue;
		}
		int ans = a[y]-a[x+m-2];
		cout<<ans<<endl;
	}
}