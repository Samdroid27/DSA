#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		int sum = 0;
		for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
		int flag = 0;
		for(int i=0;i<n;i++){
			if((sum-a[i]) == (n-1)*a[i]){
				flag = 1;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}