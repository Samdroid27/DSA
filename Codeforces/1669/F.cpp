#include <bits/stdc++.h>
using namespace std;
 
int mp[31];
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int pre=a[0],suf=a[n-1];
		int l=0,r=n-1;
		int ans = 0;
		while(l<r){
			while(l<r-1 && pre<suf)	pre+=a[++l];
			while(r>l+1 && suf<pre)	suf+=a[--r];
			if(pre==suf) ans=max(ans,l+n-r+1);
			if(l==r-1) break;
			else{
				pre+=a[++l];
			}
		}
		cout<<ans<<endl;
	}
}