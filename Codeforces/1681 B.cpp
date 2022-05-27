#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int m;
		cin>>m;
		vector<int> b(m);
		for(int i=0;i<m;i++) cin>>b[i];
		int st=0;
		for(int i:b){
			st+=i;
			st %=n;
		}
		cout<<a[st]<<endl;

	}
}