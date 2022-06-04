#include <bits/stdc++.h>
using namespace std;
 
int mp[31];
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
			for(int j=0;j<=30;j++){
				if(a[i]&(1<<j)) mp[j]++;
			}
		}
		for(int i=30;i>=0;i--){
			if(k && mp[i]<n && (n-mp[i])<=k){
				k-= n-mp[i];
				mp[i]=n;
			}
			if(mp[i]<n) mp[i]=0;
		}
		int ans = 0;
		for(int i=0;i<=30;i++) if(mp[i]==n) ans+=(1<<i);
		cout<<ans<<endl;
	}
}