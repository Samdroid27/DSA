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
		for(int i=0;i<n;i++) cin>>a[i];
		int i=0,j=1;
		int count = 0;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		while(i<n && j<n){
			if(a[i]>a[j]){
				count++;
				i=j+1;
				j = i+1;
			}else{
				i=j;
				j++;
			}
		}
		cout<<count<<endl;
	}
}