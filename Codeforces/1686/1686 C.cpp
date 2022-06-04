#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int test;
	cin>>test;
	while(test--){
		map<int,int> mp;
		priority_queue<int> pq;
		int n;
		cin>>n;
		int a[n];
		int mx=0;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			pq.push(k);
			mp[k]++;
			mx = max(mx,mp[k]);
		}
		if(mx*2 > n || n&1){
			cout<<"NO"<<endl;
			continue;
		}
		
		for(int i=0;i<n;i+=2){
			a[i]=pq.top();
			pq.pop();
		}
		bool flag = false;
		for(int i=1;i<n;i+=2){
			a[i]=pq.top();
			if(i+1<n && a[i+1]==a[i]) {
				flag = true;
				break;
			}
			pq.pop();
		}
		if(flag){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}