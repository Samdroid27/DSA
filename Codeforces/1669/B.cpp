#include <bits/stdc++.h>
using namespace std;
 
map<int,int> mp;
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			mp[k]++;
		}
		int ans = -1;
		for(auto i:mp){
			if(i.second>=3){
				ans = i.first;
				break;
			}
		}
		cout<<ans<<endl;
		mp.clear();
	}
}