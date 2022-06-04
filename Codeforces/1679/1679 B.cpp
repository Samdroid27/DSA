#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	int n,q;
	cin>>n>>q;
	int a[n+1],sum=0;
	map<int,int> mp;
	for(int i=1;i<=n;i++) cin>>a[i],mp[i]=a[i],sum+=a[i];
	int curr = 0;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int i,x;
			cin>>i>>x;
			if(mp.find(i)!=mp.end()){
				sum+=x-mp[i];
			}else{
				sum+=x-curr;
			}
			mp[i]=x;
		}else{
			int x;
			cin>>x;
			sum = x*n;
			curr = x;
			mp.clear();
		}
		cout<<sum<<endl;
	}
}